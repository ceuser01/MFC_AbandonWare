#pragma once

#include <windows.h>//지워도 작동은 하는데 일단 냅둠.
#include <atlstr.h>//지워도 작동은 하는데 일단 냅둠.
#include <iostream>//지워도 작동 하는데 일단 냅둠.
#include <string>//getline함수에서 사용
#include <map>
#include <fstream>
#include <mutex>
#include <vector>
#pragma comment(lib, "Ws2_32.lib")

typedef std::map<std::string, std::string> string_map;

#define ASCII_XON 0x11  // XON character, used for Xon/Xoff flow control
#define ASCII_XOFF 0x13 // XOFF character, used for Xon/Xoff flow control
class cSocket {
private:
    SOCKET sock_;  // The socket associated with this object

public:
    cSocket(SOCKET s) : sock_(s) {}

    // 기존 메소드들...
    void txLine(const std::string& line);
    static unsigned long __stdcall _closesocket(LPVOID lpParam);
    unsigned long __stdcall updateSocketHandle(LPVOID lpParam);
    void txData(const char* data, int size);
    void _txData(const char* data, int size);
    void txLineEn(const std::string& line);
    std::string rxLine();

    // 소켓 핸들을 반환하는 메소드
    SOCKET getSocketHandle() const {
        return sock_;
    }
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
    void sendPngImage();  // Send the constructed PNG page
    void sendRootPage();  // Send the constructed HTTP page
    void sendJQueryScript();  // Send the constructed QueryS page
    void sendMenuScript();  // Send the constructed MenuScrip page
    void sendCSSFile();  // Send the constructed CSS page
    void checkAndSetGoogleDrivePath(); 


    static unsigned long __stdcall updateStartStatus(LPVOID lpParam);

    static unsigned long __stdcall UpdateHtmlAndJavaScriptState(LPVOID lpParam);

    static unsigned long __stdcall UpdateWebContentState(LPVOID lpParam);
    //UpdateWebContentState




    static unsigned long __stdcall checkFilePresenceMonitorThread(LPVOID lpParam);


    static unsigned long __stdcall checkHtmlPresenceMonitorThread(LPVOID lpParam);
    static unsigned long __stdcall ExitThreadSafely(LPVOID lpParam);
    //cHandler::ExitThreadSafely(LPVOID lpParam)
    //Start_Debug_sendPage
    //plugin_Debug_sendPage
    //sendMenuScript
    //sendRootPage
public:
    static LPVOID handlerContextPtr;
    static int isClientDebugCountFrist; // 클라이언트 핸들러 사용 여부를 추적하는 플래그. 초기 상태는 사용되지 않음을 나타냄.
    static int isClientDebugCountSecond; // 클라이언트 핸들러 사용 여부를 추적하는 플래그. 초기 상태는 사용되지 않음을 나타냄.


    static int CheckReuseHtml;
    static int isScriptReused;
    //isScriptReused

    static std::string webServiceImagePath;

    static std::string contentLengthStr;
    static std::string contentLengthStr_;
    // 버퍼
    static char* webServiceBuffer;
    // 파일 크기
    static DWORD webServiceFileSize;

    static char* scriptBuffer;
    static DWORD scriptFileSize;



    // 컨텐츠 길이 문자열
    static std::string webServiceContentLengthStr;

    static int isMenuScriptLoaded; // 변경된 변수 이름
    static char* menuScriptBuffer; // 변경된 변수 이름
    static DWORD menuScriptSize;   // 변경된 변수 이름


};
// MainBASE 클래스 정의
class MainBASE {
public:
    int isClientDebug; // 클라이언트 디버그 플래그를 인스턴스 멤버로 선언

    MainBASE() : isClientDebug(0) {} // 생성자에서 초기화
    std::mutex debugMutex; // 동기화를 위한 뮤텍스
  //  MainBASE();
   // ~MainBASE();
    static DWORD WINAPI ClientHandler(LPVOID lpParam);
    static DWORD WINAPI MainStart(LPVOID lpParam);
    unsigned long __stdcall updateSocketDebug(LPVOID lpParam);
    static void startWSA();
    cSocket* Accept();
    void StartTCPServer(int port);
    void StopTCPServer();
public:
    static LPVOID mainBaseStatePtr;

    static string_map myMap, statuscodes, statuspages;
    static short port;
    static bool isClientHandlerUsed; // 클라이언트 핸들러 사용 여부를 추적하는 플래그. 초기 상태는 사용되지 않음을 나타냄.
  
    static cSocket* clientSock; // 클라이언트 소켓을 위한 cSocket 클래스 객체. 한 번의 인스턴스화로 재사용 가능.
    static cHandler* handler; // 클라이언트 요청을 처리할 cHandler 클래스 객체. 재생성 없이 반복 사용됨.
 
   // SOCKET sock_;  // Server socket
//private:
private:
    SOCKET sock_;  // The socket associated with this object
private:
    int debug_Count;  // The socket associated with this object
};


