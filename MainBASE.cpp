// MainBASE.cpp
#include "pch.h"
#include "MainBASE.h"
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
cSocket* MainBASE::clientSock; // Ŭ���̾�Ʈ ������ ���� cSocket Ŭ���� ��ü. �� ���� �ν��Ͻ�ȭ�� ���� ����.
cHandler* MainBASE::handler; // Ŭ���̾�Ʈ ��û�� ó���� cHandler Ŭ���� ��ü. ����� ���� �ݺ� ����.

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



DWORD WINAPI MainBASE::ClientHandler(LPVOID lpParam) {
    SOCKET clientSocket = (SOCKET)lpParam;
    char requestBuffer[9024]; // Ŭ���̾�Ʈ�κ����� ��û�� �����ϴ� ����
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

    // HTTP GET ��û ó�� ����
    if (strstr(requestBuffer, "GET / HTTP/")) {
        if (!isClientHandlerUsed) {
            clientSock = new cSocket(clientSocket); // cSocket ��ü�� �������� �Ҵ�. ���� �߰� �̺�Ʈ �߻� ����.
            handler = new cHandler(clientSock);     // cHandler ��ü�� �������� �Ҵ�. ���� cHandler::cHandler�� �̺�Ʈ �߻� ����. cHandler �����ڿ��� �ڵ� ó�� ����.
        //    isClientHandlerUsed = true; // Ŭ���̾�Ʈ �ڵ鷯 ��� ���¸� Ȱ��ȭ. �ʱ�ȭ �� ù ��� �ÿ��� ����.
        }
        handler->sendPage();
        //   handler = new cHandler(clientSock);
    }

    closesocket(clientSocket);
    return 0;
}



DWORD WINAPI MainBASE::MainStart(LPVOID lpParam) {
    // �ܼ� �ʱ�ȭ
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

    listen(serverSocket, SOMAXCONN); // ���� ��� ����

    // Ŭ���̾�Ʈ ���� ó��
    SOCKET clientSocket;
    while ((clientSocket = accept(serverSocket, NULL, NULL)) != INVALID_SOCKET) {
        DWORD threadId;



        HANDLE clientThread = CreateThread(NULL, 0, ClientHandler, (LPVOID)clientSocket, 0, &threadId);

        if (clientThread == NULL) {
            std::cerr << "Failed to create thread for client connection." << std::endl;
            closesocket(clientSocket);
        }
        else {
            CloseHandle(clientThread); // ������ �ڵ� �ݱ�
        }
    }

    // ���� ���� ����
    closesocket(serverSocket);
    WSACleanup();
    return 0; // ���� ����
}

unsigned long __stdcall _closesocket(LPVOID lpParam) {
    Sleep(100); //�ð�Ÿ�̹� �Լ�
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

