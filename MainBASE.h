#pragma once

#include <windows.h>//지워도 작동은 하는데 일단 냅둠.
#include <atlstr.h>//지워도 작동은 하는데 일단 냅둠.
#include <iostream>//지워도 작동 하는데 일단 냅둠.
#include <string>//getline함수에서 사용
#include <map>
#include <fstream>


#pragma comment(lib, "Ws2_32.lib")

typedef std::map<std::string, std::string> string_map;

#define ASCII_XON 0x11  // XON character, used for Xon/Xoff flow control
#define ASCII_XOFF 0x13 // XOFF character, used for Xon/Xoff flow control

// cSocket 클래스 정의
class cSocket {
private:
    SOCKET sock_;  // The socket associated with this object

public:
    cSocket(SOCKET s) : sock_(s) {}
    void txLine(const std::string& line);
    void txData(const char* data, int size);
    std::string rxLine();
};

// cHandler 클래스 정의
class cHandler {
private:
    struct Page {
        cSocket* sock_;  // Socket associated with the page
        std::string path_;  // Requested path
        std::string status_;  // HTTP status code
        std::string contentType_;  // Content type of the response
        struct Data {
            int size;  // Size of the content
            char* content;  // Actual content
        } data_;

        Page(cSocket* s) : sock_(s), data_({ 0, nullptr }) {}
        ~Page();
        void createPage(const std::string& requestLine);
    };

    Page page_;

public:
    cHandler(cSocket* sock);
    ~cHandler();
    void handleRequest();
    void sendPage();  // Send the constructed HTTP page
public:
    static int isClientDebugCountFrist; // 클라이언트 핸들러 사용 여부를 추적하는 플래그. 초기 상태는 사용되지 않음을 나타냄.
    static int isClientDebugCountSecond; // 클라이언트 핸들러 사용 여부를 추적하는 플래그. 초기 상태는 사용되지 않음을 나타냄.
};

// MainBASE 클래스 정의
class MainBASE {
public:


    MainBASE();
    ~MainBASE();
    static DWORD WINAPI ClientHandler(LPVOID lpParam);
    static DWORD WINAPI MainStart(LPVOID lpParam);
    static void startWSA();
    cSocket* Accept();
    void StartTCPServer(int port);
    void StopTCPServer();
public:
    static string_map myMap, statuscodes, statuspages;
    static short port;
    static bool isClientHandlerUsed; // 클라이언트 핸들러 사용 여부를 추적하는 플래그. 초기 상태는 사용되지 않음을 나타냄.
    static cSocket* clientSock; // 클라이언트 소켓을 위한 cSocket 클래스 객체. 한 번의 인스턴스화로 재사용 가능.
    static cHandler* handler; // 클라이언트 요청을 처리할 cHandler 클래스 객체. 재생성 없이 반복 사용됨.
 
    SOCKET sock_;  // Server socket
};


