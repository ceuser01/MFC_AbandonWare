#pragma once

#include <windows.h>//������ �۵��� �ϴµ� �ϴ� ����.
#include <atlstr.h>//������ �۵��� �ϴµ� �ϴ� ����.
#include <iostream>//������ �۵� �ϴµ� �ϴ� ����.
#include <string>//getline�Լ����� ���
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

    // ���� �޼ҵ��...
    void txLine(const std::string& line);
    static unsigned long __stdcall _closesocket(LPVOID lpParam);
    unsigned long __stdcall updateSocketHandle(LPVOID lpParam);
    void txData(const char* data, int size);
    void _txData(const char* data, int size);
    void txLineEn(const std::string& line);
    std::string rxLine();

    // ���� �ڵ��� ��ȯ�ϴ� �޼ҵ�
    SOCKET getSocketHandle() const {
        return sock_;
    }
};
// cHandler Ŭ���� ����
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
    static int isClientDebugCountFrist; // Ŭ���̾�Ʈ �ڵ鷯 ��� ���θ� �����ϴ� �÷���. �ʱ� ���´� ������ ������ ��Ÿ��.
    static int isClientDebugCountSecond; // Ŭ���̾�Ʈ �ڵ鷯 ��� ���θ� �����ϴ� �÷���. �ʱ� ���´� ������ ������ ��Ÿ��.


    static int CheckReuseHtml;
    static int isScriptReused;
    //isScriptReused

    static std::string webServiceImagePath;

    static std::string contentLengthStr;
    static std::string contentLengthStr_;
    // ����
    static char* webServiceBuffer;
    // ���� ũ��
    static DWORD webServiceFileSize;

    static char* scriptBuffer;
    static DWORD scriptFileSize;



    // ������ ���� ���ڿ�
    static std::string webServiceContentLengthStr;

    static int isMenuScriptLoaded; // ����� ���� �̸�
    static char* menuScriptBuffer; // ����� ���� �̸�
    static DWORD menuScriptSize;   // ����� ���� �̸�


};
// MainBASE Ŭ���� ����
class MainBASE {
public:
    int isClientDebug; // Ŭ���̾�Ʈ ����� �÷��׸� �ν��Ͻ� ����� ����

    MainBASE() : isClientDebug(0) {} // �����ڿ��� �ʱ�ȭ
    std::mutex debugMutex; // ����ȭ�� ���� ���ؽ�
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
    static bool isClientHandlerUsed; // Ŭ���̾�Ʈ �ڵ鷯 ��� ���θ� �����ϴ� �÷���. �ʱ� ���´� ������ ������ ��Ÿ��.
  
    static cSocket* clientSock; // Ŭ���̾�Ʈ ������ ���� cSocket Ŭ���� ��ü. �� ���� �ν��Ͻ�ȭ�� ���� ����.
    static cHandler* handler; // Ŭ���̾�Ʈ ��û�� ó���� cHandler Ŭ���� ��ü. ����� ���� �ݺ� ����.
 
   // SOCKET sock_;  // Server socket
//private:
private:
    SOCKET sock_;  // The socket associated with this object
private:
    int debug_Count;  // The socket associated with this object
};


