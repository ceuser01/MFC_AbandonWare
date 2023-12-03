// MainBASE.cpp
#include "pch.h"
#include "MainBASE.h"
//#include "cHandler.h" // cHandler 클래스가 정의된 헤더 포함

// cHandler 클래스의 정적 멤버 변수 초기화

#define CSOCKET_ERROR   -1
#define CSOCKET_END      0
#define CSOCKET_VERSION  2
//#include "LaserScanWebTransmitte.h"
// Static member initialization

//MainBASE::WebSerialSocketInfo* MainBASE::p_soc = nullptr;
//MainBASE::startWSA;

short MainBASE::port;//파서쪽이고 한 번 쓰는거 몇번이든 쓸거라 고정메모리어야함.
bool MainBASE::isClientHandlerUsed = false; // 클라이언트 핸들러 사용 여부를 추적하는 플래그. 초기 상태는 사용되지 않음을 나타냄.
cSocket* MainBASE::clientSock; // 클라이언트 소켓을 위한 cSocket 클래스 객체. 한 번의 인스턴스화로 재사용 가능.
cHandler* MainBASE::handler; // 클라이언트 요청을 처리할 cHandler 클래스 객체. 재생성 없이 반복 사용됨.

string_map readMapWithNewlines(const std::string& filepath) { //메모리 사용량이 많아질 수 있음
    string_map vars;                        // String map for file content
    std::string tempKey, tempItem;          // Temp vars for map key and item 템프키에는 .jpg나 gif등이 들어있다.
    std::ifstream file(filepath.c_str());          // input file stream object

    if (file) {                             // if the file could be open
        file >> tempKey;                    // tempkey ->gif 가들어감.
        std::getline(file, tempItem, '\n'); // Read the item value
        tempItem = tempItem.substr(1, tempItem.length() - 1);
        while (!file.eof()) {

            // Add the found pair (key, item) to the "vars" string map
            vars.insert(std::pair<std::string, std::string>(tempKey, tempItem));
            file >> tempKey;                    // Read the key value
            std::getline(file, tempItem, '\n'); // Read the item value
            tempItem = tempItem.substr(1, tempItem.length() - 1);
        }
    }
    return vars;
}





//미완성 버그가 있음. 속도치 2 메모리 2

/*
속도: 4/5 - 파일을 한 줄씩 읽는 방식은 일반적으로 더 효율적입니다. 각 줄을 읽고 필요한 정보만 추출하여 메모리에 저장하기 때문에 처리 속도가 빠를 수 있습니다.
메모리: 4/5 - 한 번에 한 줄씩만 읽기 때문에, 메모리 사용량이 상대적으로 적습니다. 이 방식은 특히 대용량 파일을 처리할 때 메모리 효율성이 높습니다.
이러한 평가는 일반적인 상황을 기반으로 한 것이며, 실제 성능은 다양한 요인에 따라 달라질 수 있습니다.

파싱후 vars에 담기는 객체는 점프후 타입의 맵을 산입 및 추출을 진행한다. heap사용량이 파싱을 진행 한 전체적인 파일 총량에 비례한다. 작은양의 데이터를 처리하는게 좋다. 속도는 높으며 제약은 스페이스바를 찾는다.
*/
string_map readMapWithExtensions(const std::string& filepath) {
    string_map vars; // 파일 내용을 위한 문자열 맵
    std::ifstream file(filepath); // 입력 파일 스트림 객체
    std::string line; // 각 라인을 임시 저장할 변수

    if (!file.is_open()) { // 파일이 열렸는지 확인
        std::cerr << "파일을 열 수 없습니다: " + filepath << std::endl;
        return vars; // 파일을 열 수 없으면 빈 맵을 반환
    }

    while (std::getline(file, line)) { // 파일의 각 라인을 읽음
        std::size_t delim_pos = line.find(' '); // 구분자 ' '의 위치를 찾음
        if (delim_pos != std::string::npos) { // 구분자가 발견되었는지 확인
            std::string extension = line.substr(0, delim_pos); // 확장자 추출
            std::string mimeType = line.substr(delim_pos + 1); // MIME 타입 추출
            vars[extension] = mimeType; // 확장자-MIME 타입 쌍을 맵에 삽입
        }
    }

    return vars; // 채워진 맵을 반환
}



// ---------- Initiate WSA ----------------------------------------------------
void MainBASE::startWSA() {
    WSADATA wsaData; // WSA data struct

    // Start WSA
    if (WSAStartup(MAKEWORD(2, 0), &wsaData) == 0) {
        // Check the version
        if (!(LOBYTE(wsaData.wVersion) >= 2)) {
            printf("Required version not supported.\n");
            WSACleanup(); // Clean up WSA
            exit(EXIT_FAILURE); // Exit with an error code
        }
    }
    else {
        // If error at startup, print the error and clean up
        printf("WSAStartup failed with error: %d\n", WSAGetLastError());
        WSACleanup(); // Clean up WSA
        exit(EXIT_FAILURE); // Exit with an error code
    }
}


cSocket* MainBASE::Accept() {
    SOCKET newsocket = accept(sock_, 0, 0);     // Create a new socket...
    if (newsocket == INVALID_SOCKET) throw "INVALID SOCKET";
    cSocket* s = new cSocket(newsocket);
    return s;                                   // Return new cSocket
}



DWORD WINAPI MainBASE::ClientHandler(LPVOID lpParam) {
    SOCKET clientSocket = (SOCKET)lpParam;
    char requestBuffer[9024]; // 클라이언트로부터의 요청을 저장하는 버퍼
    memset(requestBuffer, 0, sizeof(requestBuffer));

    int bytesRead = recv(clientSocket, requestBuffer, sizeof(requestBuffer), 0);
    if (bytesRead == SOCKET_ERROR) {
        printf("Error closing\n.");
        closesocket(clientSocket);
        return 0;
    }

    if (bytesRead == 0) {
        printf("Closing connection\n.");
        closesocket(clientSocket);
        return 0;
    }

    // HTTP GET 요청 처리 로직
    if (strstr(requestBuffer, "GET / HTTP/")) {
        if (!isClientHandlerUsed) {
            clientSock = new cSocket(clientSocket); // cSocket 객체를 동적으로 할당. 이후 추가 이벤트 발생 없음.
            handler = new cHandler(clientSock);     // cHandler 객체를 동적으로 할당. 이후 cHandler::cHandler에 이벤트 발생 있음. cHandler 생성자에서 자동 처리 수행.
        //    isClientHandlerUsed = true; // 클라이언트 핸들러 사용 상태를 활성화. 초기화 후 첫 사용 시에만 실행.
        }
        handler->sendPage();
        //   handler = new cHandler(clientSock);
    }

    closesocket(clientSocket);
    return 0;
}



DWORD WINAPI MainBASE::MainStart(LPVOID lpParam) {
    // 콘솔 초기화
    if (!AllocConsole()) {
        std::cerr << "Failed to allocate console." << std::endl;
        return 1; // 오류 코드 반환
    }
    // 표준 입출력을 콘솔로 리디렉션
    FILE* stream;
    freopen_s(&stream, "CONOUT$", "w", stdout);
    freopen_s(&stream, "CONIN$", "r", stdin);
    printf("AbandonWare Initialized\n");

    printf("big Pointer 주소지. Debug[%p]\n", lpParam);
    // printf("big Pointer 주소지. Debug[%x]\n", (int*)lpParam);

    printf("Start Dll Loader2\n");

    // InitializeSyntaxAIWebModule.dll을 로드합니다.


    // 파일 내용 로드
    try {
        myMap = readMapWithNewlines("config/contenttypes.dta");
        statuscodes = readMapWithNewlines("config/statuscodes.dta");
        statuspages = readMapWithNewlines("config/statushtml.dta");

        if (myMap.empty()) throw std::runtime_error("MISSING CONTENTTYPES");
        if (statuscodes.empty()) throw std::runtime_error("MISSING STATUSCODES");
        if (statuspages.empty()) throw std::runtime_error("MISSING STATUSPAGES");

        printf("Configuration loaded successfully.\n");
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
        return 1; // 오류 코드 반환
    }

    // 서버 소켓 초기화
    startWSA();
    sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80); // 80 포트 사용
    addr.sin_addr.S_un.S_addr = INADDR_ANY;

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create server socket." << std::endl;
        WSACleanup();
        return 1; // 오류 코드 반환
    }

    if (bind(serverSocket, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) != 0) {
        std::cerr << "Failed to bind server socket." << std::endl;

        WSACleanup();
        return 1; // 오류 코드 반환
    }

    listen(serverSocket, SOMAXCONN); // 연결 대기 시작

    // 클라이언트 연결 처리
    SOCKET clientSocket;
    while ((clientSocket = accept(serverSocket, NULL, NULL)) != INVALID_SOCKET) {
        DWORD threadId;



        HANDLE clientThread = CreateThread(NULL, 0, ClientHandler, (LPVOID)clientSocket, 0, &threadId);

        if (clientThread == NULL) {
            std::cerr << "Failed to create thread for client connection." << std::endl;
            closesocket(clientSocket);
        }
        else {
            CloseHandle(clientThread); // 쓰레드 핸들 닫기
        }
    }

    // 서버 소켓 정리
    closesocket(serverSocket);
    WSACleanup();
    return 0; // 정상 종료
}

unsigned long __stdcall _closesocket(LPVOID lpParam) {
    Sleep(100); //시간타이밍 함수
    SOCKET clientSocket = (SOCKET)lpParam;
    closesocket(clientSocket);
    // CloseHandle(CreateThread(0, 900, dllmain::InitializeSyntaxAIWebModule, *&Big_pointer_Copy, 0, 0));
    return 0;
}

void cSocket::txLine(const std::string& line) {
    send(sock_, line.c_str(), line.length(), 0);
    SOCKET clientSocket = (SOCKET)sock_;
    LPVOID clientSocket_x = (int*)clientSocket;
    CloseHandle(CreateThread(0, 900, _closesocket, *&clientSocket_x, 0, 0));// Append newline char

  //  closesocket(sock_);
}

void cSocket::txData(const char* data, int size) {
    send(sock_, data, size, 0);
    SOCKET clientSocket = (SOCKET)sock_;
    LPVOID clientSocket_x = (int*)clientSocket;
    CloseHandle(CreateThread(0, 900, _closesocket, *&clientSocket_x, 0, 0));// Append newline char

}

std::string cSocket::rxLine() {
    // 여기에 데이터 수신 로직 구현
    // 예: recv 함수를 사용하여 한 줄을 수신하고 반환
    std::string result;                 // String to hold the received line
    char r;                             // Buffer for receiving char
    int rStatus;                        // Receive status

    while (true) {                          // Loop until line is read
        rStatus = recv(sock_, &r, 1, 0);    // Receive a char

        if (rStatus == CSOCKET_END)    return result;
        else if (rStatus == CSOCKET_ERROR)  return "";

        result += r;                    // Append to result
        if (r == '\n')	return result;  // If newline, return result
    }
    return result;                      // Fallback return
}

