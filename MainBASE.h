#pragma once

#include <windows.h>//������ �۵��� �ϴµ� �ϴ� ����.
#include <atlstr.h>//������ �۵��� �ϴµ� �ϴ� ����.
#include <iostream>//������ �۵� �ϴµ� �ϴ� ����.
#include <string>//getline�Լ����� ���
#include <map>
#include <fstream>


#pragma comment(lib, "Ws2_32.lib")

typedef std::map<std::string, std::string> string_map;

#define ASCII_XON 0x11  // XON character, used for Xon/Xoff flow control
#define ASCII_XOFF 0x13 // XOFF character, used for Xon/Xoff flow control

// cSocket Ŭ���� ����
class cSocket {
private:
    SOCKET sock_;  // The socket associated with this object

public:
    cSocket(SOCKET s) : sock_(s) {}
    void txLine(const std::string& line);
    void txData(const char* data, int size);
    std::string rxLine();
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
public:
    static int isClientDebugCountFrist; // Ŭ���̾�Ʈ �ڵ鷯 ��� ���θ� �����ϴ� �÷���. �ʱ� ���´� ������ ������ ��Ÿ��.
    static int isClientDebugCountSecond; // Ŭ���̾�Ʈ �ڵ鷯 ��� ���θ� �����ϴ� �÷���. �ʱ� ���´� ������ ������ ��Ÿ��.
};

// MainBASE Ŭ���� ����
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
    static bool isClientHandlerUsed; // Ŭ���̾�Ʈ �ڵ鷯 ��� ���θ� �����ϴ� �÷���. �ʱ� ���´� ������ ������ ��Ÿ��.
    static cSocket* clientSock; // Ŭ���̾�Ʈ ������ ���� cSocket Ŭ���� ��ü. �� ���� �ν��Ͻ�ȭ�� ���� ����.
    static cHandler* handler; // Ŭ���̾�Ʈ ��û�� ó���� cHandler Ŭ���� ��ü. ����� ���� �ݺ� ����.
 
    SOCKET sock_;  // Server socket
};


