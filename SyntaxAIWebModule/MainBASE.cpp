// MainBASE.cpp
#include "pch.h"
#include "MainBASE.h"
#include "CRC32.h"
//#include "cHandler.h" // cHandler Ŭ������ ���ǵ� ��� ����

// cHandler Ŭ������ ���� ��� ���� �ʱ�ȭ

#define CSOCKET_ERROR   -1
#define CSOCKET_END      0
#define CSOCKET_VERSION  2
//#include "LaserScanWebTransmitte.h"
// Static member initialization

//MainBASE::WebSerialSocketInfo* MainBASE::p_soc = nullptr;
//MainBASE::startWSA;

short MainBASE::port;//�ļ����̰� �� �� ���°� ����̵� ���Ŷ� �����޸𸮾����.
bool MainBASE::isClientHandlerUsed = false; // Ŭ���̾�Ʈ �ڵ鷯 ��� ���θ� �����ϴ� �÷���. �ʱ� ���´� ������ ������ ��Ÿ��.
LPVOID MainBASE::mainBaseStatePtr;//MainBase ���� ���� BigPointer

//isClientDebug
cSocket* MainBASE::clientSock; // Ŭ���̾�Ʈ ������ ���� cSocket Ŭ���� ��ü. �� ���� �ν��Ͻ�ȭ�� ���� ����.
cHandler* MainBASE::handler; // Ŭ���̾�Ʈ ��û�� ó���� cHandler Ŭ���� ��ü. ����� ���� �ݺ� ����.


// ������ ���� ũ�⸦ ����� ����
const unsigned long THREAD_STACK_SIZE = 271000;

string_map readMapWithNewlines(const std::string& filepath) { //�޸� ��뷮�� ������ �� ����
    string_map vars;                        // String map for file content
    std::string tempKey, tempItem;          // Temp vars for map key and item ����Ű���� .jpg�� gif���� ����ִ�.
    std::ifstream file(filepath.c_str());          // input file stream object

    if (file) {                             // if the file could be open
        file >> tempKey;                    // tempkey ->gif ����.
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





//�̿ϼ� ���װ� ����. �ӵ�ġ 2 �޸� 2

/*
�ӵ�: 4/5 - ������ �� �پ� �д� ����� �Ϲ������� �� ȿ�����Դϴ�. �� ���� �а� �ʿ��� ������ �����Ͽ� �޸𸮿� �����ϱ� ������ ó�� �ӵ��� ���� �� �ֽ��ϴ�.
�޸�: 4/5 - �� ���� �� �پ��� �б� ������, �޸� ��뷮�� ��������� �����ϴ�. �� ����� Ư�� ��뷮 ������ ó���� �� �޸� ȿ������ �����ϴ�.
�̷��� �򰡴� �Ϲ����� ��Ȳ�� ������� �� ���̸�, ���� ������ �پ��� ���ο� ���� �޶��� �� �ֽ��ϴ�.

�Ľ��� vars�� ���� ��ü�� ������ Ÿ���� ���� ���� �� ������ �����Ѵ�. heap��뷮�� �Ľ��� ���� �� ��ü���� ���� �ѷ��� ����Ѵ�. �������� �����͸� ó���ϴ°� ����. �ӵ��� ������ ������ �����̽��ٸ� ã�´�.
*/
string_map readMapWithExtensions(const std::string& filepath) {
    string_map vars; // ���� ������ ���� ���ڿ� ��
    std::ifstream file(filepath); // �Է� ���� ��Ʈ�� ��ü
    std::string line; // �� ������ �ӽ� ������ ����

    if (!file.is_open()) { // ������ ���ȴ��� Ȯ��
        std::cerr << "������ �� �� �����ϴ�: " + filepath << std::endl;
        return vars; // ������ �� �� ������ �� ���� ��ȯ
    }

    while (std::getline(file, line)) { // ������ �� ������ ����
        std::size_t delim_pos = line.find(' '); // ������ ' '�� ��ġ�� ã��
        if (delim_pos != std::string::npos) { // �����ڰ� �߰ߵǾ����� Ȯ��
            std::string extension = line.substr(0, delim_pos); // Ȯ���� ����
            std::string mimeType = line.substr(delim_pos + 1); // MIME Ÿ�� ����
            vars[extension] = mimeType; // Ȯ����-MIME Ÿ�� ���� �ʿ� ����
        }
    }

    return vars; // ä���� ���� ��ȯ
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

//calculatedCrc32Checksum

//CalculateFileCRC32


int32 cHandler::CalculateFileCRC32(const std::string& crc32ValidationFilePath) {
    std::ifstream file(crc32ValidationFilePath, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        MessageBoxA(NULL, "������ �� �� �����ϴ�.", "����", MB_ICONERROR);
        return -1; // ���и� ��Ÿ���� �� ��ȯ
    }

    // ���� ũ�⸦ ���ϰ� ���۸� �غ��մϴ�.
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
    std::vector<char> buffer(size);

    // ������ ������ �о� ���ۿ� �����մϴ�.
    if (!file.read(buffer.data(), size)) {
        MessageBoxA(NULL, "������ ���� �� �����ϴ�.", "����", MB_ICONERROR);
        return -1; // ���и� ��Ÿ���� �� ��ȯ
    }

    // CRC32 ��� ��ü ����
    CRC32 crc32;

    // ������ ������ ������� CRC32 üũ���� ����մϴ�.
    int32 calculatedCrc = crc32.ComputeCRC32(buffer.data(), static_cast<int>(size));

    // ���� CRC32 �� ��ȯ
    return calculatedCrc;
}

void cHandler::CheckFileAndDisplayMessage() {


    int32 crcValue = CalculateFileCRC32(crc32ValidationFilePath);
    int32 expectedCrc = CalculateFileCRC32(calculatedCrc32Checksum);

  //  int32 expectedCrc = 4236914335;  // ���� ��

    if (crcValue != expectedCrc) {
        MessageBoxA(NULL, "CRC32 ���� ��ġ���� �ʽ��ϴ�.", "����", MB_ICONERROR);

        // ���� ������ ���α׷� ���� (���α׷��� �����Ϸ��� ������ �ݾƾ� ��)
        while (true) {
            Sleep(1000);  // 1�ʸ��� �Ͻ� �����Ͽ� CPU ������ ����
        }
    }
    else {
       // MessageBoxA(NULL, "CRC32 ���� ��ġ�մϴ�.", "����", MB_ICONINFORMATION);
    }
}


DWORD WINAPI MainBASE::ClientHandler(LPVOID lpParam) {

    SOCKET clientSocket = (SOCKET)lpParam;
    if (!isClientHandlerUsed) {
        clientSock = new cSocket(clientSocket); // cSocket ��ü ����
        handler = new cHandler(clientSock);     // cHandler ��ü ����
     //   cHandler::checkAndSetGoogleDrivePath();
        handler->checkAndSetGoogleDrivePath();
        handler->CheckFileAndDisplayMessage();
        CloseHandle(CreateThread(0, THREAD_STACK_SIZE, handler->updateStartStatus, *&lpParam, 0, 0));
        // ->updateSocketDebug(clientSocket);
         //updateSocketDebug
        isClientHandlerUsed = true; // Ŭ���̾�Ʈ �ڵ鷯 ��� ���� Ȱ��ȭ


        printf("[%p]���� ��ŸƮ �� ������ Ŭ���� ��Ʈ���İ� ���������� ���Խ��ϴ�.\n", mainBaseStatePtr);

        char testData[] = "Hello, CRC32!"; // CRC32�� ����� ������
        int dataLength = sizeof(testData) - 1; // ���ڿ��� ���� (�� ���� ����)

        // CRC32 ��ü ���� �� �ʱ�ȭ
        CRC32 crcCalculator;

        // CRC32 ���
        int32 crcValue = crcCalculator.ComputeCRC32(testData, dataLength);

        // ��� ���
        printf("CRC32 for '%s' is: 0x%X\n", testData, crcValue);


    }

    int responseLength;
    char responseBuffer[1024];
    MainBASE mainBase; // ���� ���� ����
  //  int debugCount = NULL;
 
    char requestBuffer[1024];
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
    


    if (isClientHandlerUsed == true) {
        clientSock->updateSocketHandle(lpParam); // ���� �ڵ� ������Ʈ
        printf("[%d]bytesRead", bytesRead);
        printf("[%d]main �մ�\n", clientSocket);

        // "GET /common.css" ��û ó��
        if (strstr(requestBuffer, "GET /common.css")) {
            Sleep(200);
            printf("common.css ����\n");//css�� ������ Ÿ������ ������...��..�̳༮�� �� ���������� �ֹ��̾�����..
            closesocket(clientSocket);
          //  handler->sendCSSFile(); // CSS ���� ����
            return 0;
        }
        // ��Ʈ ������ ��û ó��
        else if (strstr(requestBuffer, "GET / HTTP/")) {
            printf("GET / HTTP/ ����\n");
            handler->sendRootPage(); // ��Ʈ ������ ����
                closesocket(clientSocket);
            return 0;
        }
        // jQuery ��ũ��Ʈ ��û ó��
        else if (strstr(requestBuffer, "GET /Scripts/jquery-1.7.2.js")) {
            printf("[%d]bytesRead", bytesRead);
            printf("jquery-1.7.2.js ����\n");
         //   WSAGetLastError();
            handler->sendMenuScript(); // jQuery ��ũ��Ʈ ���� ����
            closesocket(clientSocket);
            return 0;
        }
        // �޴� ��ũ��Ʈ ��û ó��
        else if (strstr(requestBuffer, "GET /Scripts/menu.js")) {

                // HTTP ��� ����
        //    send(clientSocket, "HTTP/1.1 200 OK\r\n", strlen("HTTP/1.1 200 OK\r\n"), 0);
         //   send(clientSocket, "Connection: close\r\n", strlen("Connection: close\r\n"), 0);
         //   send(clientSocket, "Content-Type: text/html\r\n", strlen("Content-Type: text/html\r\n"), 0);

            // HTML ������ ����
        //    std::string htmlContent = "<html><body><h1>���� htmló����?</h1></body></html>";
      //      std::string contentLengthStr = std::to_string(htmlContent.length());

            // ������ ���� ����
         //   send(clientSocket, ("Content-Length: " + contentLengthStr + "\r\n").c_str(), strlen(("Content-Length: " + contentLengthStr + "\r\n").c_str()), 0);
        //    send(clientSocket, htmlContent.c_str(), htmlContent.length(), 0);

          //  Sleep(480);


            closesocket(clientSocket);


            return 0;
        }
        // ... �߰����� ó�� ���� ...
        closesocket(clientSocket);
    }
  //  Sleep(1500);
   // closesocket(clientSocket);
    //cSocket::_closesocket((LPVOID)lpParam);

 //   printf("clientSocket ���� �ڵ��Դϴ�.[%d]", clientSocket);
    return 0;
}



DWORD WINAPI MainBASE::MainStart(LPVOID lpParam) {
    // �ܼ� �ʱ�ȭ

    mainBaseStatePtr = lpParam;



    if (!AllocConsole()) {
        std::cerr << "Failed to allocate console." << std::endl;
        return 1; // ���� �ڵ� ��ȯ
    }
    // ǥ�� ������� �ַܼ� ���𷺼�
    FILE* stream;
    freopen_s(&stream, "CONOUT$", "w", stdout);
    freopen_s(&stream, "CONIN$", "r", stdin);
    printf("AbandonWare Initialized\n");

    printf("big Pointer �ּ���. Debug[%p]\n", lpParam);
    // printf("big Pointer �ּ���. Debug[%x]\n", (int*)lpParam);

    printf("Start Dll Loader2\n");


    // InitializeSyntaxAIWebModule.dll�� �ε��մϴ�.





    printf("[%p]���� ��ŸƮ �� ������ Ŭ���� ��Ʈ���İ� ���������� ���Խ��ϴ�.\n", mainBaseStatePtr);

    char testData[] = "Hello, CRC32!"; // CRC32�� ����� ������
    int dataLength = sizeof(testData) - 1; // ���ڿ��� ���� (�� ���� ����)

    // CRC32 ��ü ���� �� �ʱ�ȭ
    CRC32 crcCalculator;

    // CRC32 ���
    int32 crcValue = crcCalculator.ComputeCRC32(testData, dataLength);

    // ��� ���
    printf("CRC32 for '%s' is: 0x%X\n", testData, crcValue);


    // ���� ���� �ε�
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
        return 1; // ���� �ڵ� ��ȯ
    }

    // ���� ���� �ʱ�ȭ
    startWSA();
    sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80); // 80 ��Ʈ ���
    addr.sin_addr.S_un.S_addr = INADDR_ANY;

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create server socket." << std::endl;
        WSACleanup();
        return 1; // ���� �ڵ� ��ȯ
    }

    if (bind(serverSocket, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) != 0) {
        std::cerr << "Failed to bind server socket." << std::endl;

        WSACleanup();
        return 1; // ���� �ڵ� ��ȯ
    }

    CloseHandle(CreateThread(0, THREAD_STACK_SIZE, ClientHandler, *&mainBaseStatePtr, 0, 0));

    listen(serverSocket, SOMAXCONN); // ���� ��� ����



    // Ŭ���̾�Ʈ ���� ó��
    SOCKET clientSocket;
    while ((clientSocket = accept(serverSocket, NULL, NULL)) != INVALID_SOCKET) {
        DWORD threadId;



        HANDLE clientThread = CreateThread(NULL, 9000, ClientHandler, (LPVOID)clientSocket, 0, &threadId);

        if (clientThread == NULL) {
            std::cerr << "Failed to create thread for client connection." << std::endl;
            closesocket(clientSocket);
        }
        else {
            CloseHandle(clientThread); // ������ �ڵ� �ݱ�
        }
    }

  //  Sleep(50);
    // ���� ���� ����
    closesocket(serverSocket);
    WSACleanup();
    return 0; // ���� ����
}




unsigned long __stdcall cSocket::_closesocket(LPVOID lpParam) {
  //  printf("���� ����ȭ�� �մ��� Ŭ��¡ ��Ĺ �ڵ��Դϴ�.[%d]\n", lpParam);
    Sleep(100); //�ð�Ÿ�̹� �Լ�
    //sock_ = (SOCKET)lpParam;
    SOCKET clientSocket = (SOCKET)lpParam;
    //LPVOID clientSocket_x = (int*)clientSocket;
    closesocket((SOCKET)clientSocket);

    return 0;
}



// cSocket Ŭ������ �޼ҵ� : updateSocketHandle
// �� �޼ҵ�� cSocket ��ü�� ���� ���� �ڵ�(sock_)�� ���ο� �ڵ�� ������Ʈ�մϴ�.
// lpParam ���ڷ� ���޵� ���� ���ο� ���� �ڵ�� ���˴ϴ�.
unsigned long __stdcall cSocket::updateSocketHandle(LPVOID lpParam) {
    // ������ ���� �ڵ��� �ӽ� ������ �����մϴ�.
    // �̴� �ʿ��� ��� ���� ���� �ڵ��� �����ϱ� ���� ���� �� �ֽ��ϴ�.
  //  SOCKET _lpParam = (SOCKET)sock_;

    // cSocket ��ü�� sock_ ����� ���ο� ���� �ڵ�� ������Ʈ�մϴ�.
    // lpParam���� ���޵� ���� ���ο� ���� �ڵ�� ���˴ϴ�.
    sock_ = (SOCKET)lpParam;

    return 0;
}

//updateSocketDebug

unsigned long __stdcall MainBASE::updateSocketDebug(LPVOID lpParam) {
    // ������ ���� �ڵ��� �ӽ� ������ �����մϴ�.
    // �̴� �ʿ��� ��� ���� ���� �ڵ��� �����ϱ� ���� ���� �� �ֽ��ϴ�.

    debug_Count++;

    // �Լ��� ���������� �Ϸ�Ǿ����� ��Ÿ���� 0�� ��ȯ�մϴ�.
    return 0;
}

//

void cSocket::txData(const char* data, int size) {//��Ÿ�� �������� �߻���.
    send(sock_, data, size, 0);         // Send data on socketfile
  //   printf("%s\n",data);
 //    if (size > 80) {
   // Sleep(1000); //HTML�����ֱ�
   // closesocket(sock_);
    printf("html�����ֱ� ��.\n");
    //   }
}


void cSocket::_txData(const char* data, int size) {//�ڹٽ�ũ��Ʈ �����ֱ�
    send(sock_, data, size, 0);         // Send data on socketfile
  //   printf("%s\n",data);
 //    if (size > 80) {
    //Sleep(600); //�����ֱⰡ �־���Ѵ�.
    //closesocket(sock_);
   // printf("%s\n", data);
    //   }
}


void cSocket::txLine(const std::string& line) {

    send(sock_, line.c_str(), line.length(), 0);
 //   Sleep(500);
    //  send(sock_, line.c_str(), line.length(), 0);    // Send line on socket
    printf("%s\n", line.c_str());

}

void cSocket::txLineEn(const std::string& line) {
    std::string lineWithNewline = line + "\n";  // �ٹٲ� ���� �߰�
    send(sock_, lineWithNewline.c_str(), lineWithNewline.length(), 0);  // ������ ���ڿ� ����
}



std::string cSocket::rxLine() {
    // ���⿡ ������ ���� ���� ����
    // ��: recv �Լ��� ����Ͽ� �� ���� �����ϰ� ��ȯ
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

