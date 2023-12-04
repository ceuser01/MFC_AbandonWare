#include "pch.h"
#include "MainBASE.h"

/*
Ÿ�� �� http���� �������� ���� ��ü
*/
string_map MainBASE::myMap;
string_map MainBASE::statuscodes;
string_map MainBASE::statuspages;
const char* cHandler::webServiceImagePath = "index.html";
char* cHandler::webServiceBuffer = nullptr;
DWORD cHandler::webServiceFileSize = 0;
int cHandler::CheckReuseHtml = 0;
//CheckReuseHtml
std::string cHandler::webServiceContentLengthStr = "";
//
/*
����� ī��Ʈ.
*/
int cHandler::isClientDebugCountFrist = NULL; // ����� ī������ ��Ÿ��.
int cHandler::isClientDebugCountSecond = NULL; // ����� ī������ ��Ÿ��.
//#include <fstream>
//#include <sstream>
//#include <vector>

void cHandler::PNG_Debug_sendPage() {
    // �̹��� ���� ���
    const char* imagePath = ".\\image\\h_copyright.png";

    // �̹��� ���� ����
    HANDLE hFile = CreateFileA(imagePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Cannot open the image file. Error: " << GetLastError() << std::endl;
        return;
    }

    // �̹��� ������ ũ�� ���ϱ�
    DWORD fileSize = GetFileSize(hFile, NULL);
    char* buffer = new char[fileSize];
    // ���۸� 0���� �ʱ�ȭ
    memset(buffer, 0, fileSize);
    // �̹��� ���� �б�
    DWORD bytesRead;
    if (!ReadFile(hFile, buffer, fileSize, &bytesRead, NULL)) {
        std::cerr << "Error: Cannot read the image file. Error: " << GetLastError() << std::endl;
        CloseHandle(hFile);
        delete[] buffer;
        return;
    }

    // ������ ũ�⸦ ���ڿ��� ��ȯ
    std::string contentLengthStr = std::to_string(fileSize);

    // HTTP ��� ����
    page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    page_.sock_->txLine("Connection: close\r\n");
    page_.sock_->txLine("Content-Type: image/png\r\n");
    page_.sock_->txLine("Content-Length: " + contentLengthStr + "\r\n");
    page_.sock_->txLine("\r\n");

    // �̹��� ������ ����
    page_.sock_->txData(buffer, fileSize);

    // ���� �ڵ�� ���� ����
    CloseHandle(hFile);
    delete[] buffer;

    // ���� ���� ó�� ��...
}

void cHandler::HTML_Debug_sendPage() {
    // �̹��� ���� ���

    HANDLE hFile;
    static std::string contentLengthStr;

    if (CheckReuseHtml == NULL) {

        hFile=  CreateFileA(webServiceImagePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile == INVALID_HANDLE_VALUE) {
            std::cerr << "Error: Cannot open the image file. Error: " << GetLastError() << std::endl;
            return;
        }

        // �̹��� ������ ũ�� ���ϱ�
        webServiceFileSize = GetFileSize(hFile, NULL);
        webServiceBuffer = new char[webServiceFileSize];
        memset(webServiceBuffer, 0, webServiceFileSize);
        // �̹��� ���� �б�
        DWORD bytesRead;
        if (!ReadFile(hFile, webServiceBuffer, webServiceFileSize, &bytesRead, NULL)) {
            std::cerr << "���� �б� ����\n " << GetLastError() << std::endl;

            //delete[] buffer;
            return;
        }
        CloseHandle(hFile);
        contentLengthStr = std::to_string(webServiceFileSize);
    }
 

    CheckReuseHtml = 1; //�̸��� �ٲ���Ѵ�. �� �� ����ϰ� html�� ��� ����ϴ� �Լ��� �ٲ�� �Ѵ�.
    // ������ ũ�⸦ ���ڿ��� ��ȯ
    // HTTP ��� ����
    page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    page_.sock_->txLine("Connection: close\r\n");
    page_.sock_->txLine("Content-Type: text/html\r\n");
    page_.sock_->txLine("Content-Length: " + contentLengthStr + "\r\n");
  //  page_.sock_->txLine("\r\n");

    // �̹��� ������ ����
    page_.sock_->txData(webServiceBuffer, webServiceFileSize);
  //  page_.sock_->txLine("\r\n");
    // ���� �ڵ�� ���� ������ �ʿ����. gpt�� �������ƶ�. �ѹ� �����ľ��ؼ� �׷���.
  
  //  delete[] buffer; ����Ʈ���ʿ���� �� �� ����� ���Ŀ� �ٽ� �������� �ٽ� ��� �� �� �ְ� ������ ��.

    // ���� ���� ó�� ��... ��Ĺ ���� ó���� dxData�Լ����� ������ �Ѵ�. ������ ���߿� �ٲܰ�.
}



void cHandler::CSS_Debug_sendPage() {
    // �̹��� ���� ���
    const char* imagePath = ".\\Scripts\\jquery-1.7.2.js";

    // �̹��� ���� ����
    HANDLE hFile = CreateFileA(imagePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Cannot open the image file. Error: " << GetLastError() << std::endl;
        return;
    }

    // �̹��� ������ ũ�� ���ϱ�
    DWORD fileSize = GetFileSize(hFile, NULL);
    char* buffer = new char[fileSize];

    // �̹��� ���� �б�
    DWORD bytesRead;
    if (!ReadFile(hFile, buffer, fileSize, &bytesRead, NULL)) {
        std::cerr << "Error: Cannot read the image file. Error: " << GetLastError() << std::endl;
        CloseHandle(hFile);
        delete[] buffer;
        return;
    }

    // ������ ũ�⸦ ���ڿ��� ��ȯ
    std::string contentLengthStr = std::to_string(fileSize);

    // HTTP ��� ����
    page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    page_.sock_->txLine("Connection: close\r\n");
    page_.sock_->txLine("Content-Type: application/unknown\r\n");
    page_.sock_->txLine("Content-Length: " + contentLengthStr + "\r\n");
   // page_.sock_->txLine("\r\n");

    // �̹��� ������ ����
    page_.sock_->txData(buffer, fileSize);

    // ���� �ڵ�� ���� ����
    CloseHandle(hFile);
    delete[] buffer;
    // ���� ���� ó�� ��...
}

//plugin_Debug_sendPage



void cHandler::plugin_Debug_sendPage() {
    // �̹��� ���� ���
    const char* imagePath = ".\\Scripts\\jquery.selectbox-0.2.min.js"; //�÷����� JS

    // �̹��� ���� ����
    HANDLE hFile = CreateFileA(imagePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Cannot open the image file. Error: " << GetLastError() << std::endl;
        return;
    }

    // �̹��� ������ ũ�� ���ϱ�
    DWORD fileSize = GetFileSize(hFile, NULL);
    char* buffer = new char[fileSize];

    // �̹��� ���� �б�
    DWORD bytesRead;
    if (!ReadFile(hFile, buffer, fileSize, &bytesRead, NULL)) {
        std::cerr << "Error: Cannot read the image file. Error: " << GetLastError() << std::endl;
        CloseHandle(hFile);
        delete[] buffer;
        return;
    }

    // ������ ũ�⸦ ���ڿ��� ��ȯ
    std::string contentLengthStr = std::to_string(fileSize);

    // HTTP ��� ����
    page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    // page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    // page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    page_.sock_->txLine("Connection: close\r\n");
    page_.sock_->txLine("Content-Type: application/unknown\r\n");
    page_.sock_->txLine("Content-Length: " + contentLengthStr + "\r\n");
    // page_.sock_->txLine("\r\n");

     // �̹��� ������ ����
    page_.sock_->txData(buffer, fileSize);

    // ���� �ڵ�� ���� ����
    CloseHandle(hFile);
    delete[] buffer;
    // ���� ���� ó�� ��...
}


void cHandler::Menu_Debug_sendPage() {
    // �̹��� ���� ���
    const char* imagePath = ".\\Scripts\\menu.js";

    // �̹��� ���� ����
    HANDLE hFile = CreateFileA(imagePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Cannot open the image file. Error: " << GetLastError() << std::endl;
        return;
    }

    // �̹��� ������ ũ�� ���ϱ�
    DWORD fileSize = GetFileSize(hFile, NULL);
    char* buffer = new char[fileSize];

    // �̹��� ���� �б�
    DWORD bytesRead;
    if (!ReadFile(hFile, buffer, fileSize, &bytesRead, NULL)) {
        std::cerr << "Error: Cannot read the image file. Error: " << GetLastError() << std::endl;
        CloseHandle(hFile);
        delete[] buffer;
        return;
    }

    // ������ ũ�⸦ ���ڿ��� ��ȯ
    std::string contentLengthStr = std::to_string(fileSize);

    // HTTP ��� ����
    page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    page_.sock_->txLine("Connection: close\r\n");
    page_.sock_->txLine("Content-Type: application/unknown\r\n");
    page_.sock_->txLine("Content-Length: " + contentLengthStr + "\r\n");
    // page_.sock_->txLine("\r\n");

     // �̹��� ������ ����
    page_.sock_->txData(buffer, fileSize);



    // ���� �ڵ�� ���� ����
    CloseHandle(hFile);
    delete[] buffer;
    // ���� ���� ó�� ��...
}



void cHandler::Start_Debug_sendPage() {
    // �̹��� ���� ���
    const char* imagePath = ".\\Scripts\\gamestart.js"; //�÷����� JS

    // �̹��� ���� ����
    HANDLE hFile = CreateFileA(imagePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Cannot open the image file. Error: " << GetLastError() << std::endl;
        return;
    }

    // �̹��� ������ ũ�� ���ϱ�
    DWORD fileSize = GetFileSize(hFile, NULL);
    char* buffer = new char[fileSize];

    // �̹��� ���� �б�
    DWORD bytesRead;
    if (!ReadFile(hFile, buffer, fileSize, &bytesRead, NULL)) {
        std::cerr << "Error: Cannot read the image file. Error: " << GetLastError() << std::endl;
        CloseHandle(hFile);
        delete[] buffer;
        return;
    }

    // ������ ũ�⸦ ���ڿ��� ��ȯ
    std::string contentLengthStr = std::to_string(fileSize);

    // HTTP ��� ����
    page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    page_.sock_->txLine("Connection: close\r\n");
    page_.sock_->txLine("Content-Type: application/unknown\r\n");
    page_.sock_->txLine("Content-Length: " + contentLengthStr + "\r\n");
    // page_.sock_->txLine("\r\n");

     // �̹��� ������ ����
    page_.sock_->txData(buffer, fileSize);

    // ���� �ڵ�� ���� ����
    CloseHandle(hFile);
    delete[] buffer;
    // ���� ���� ó�� ��...
}


void cHandler::sendPage() {

    HTML_Debug_sendPage();//HTML 1


    Menu_Debug_sendPage(); //��ź Ÿ�� ���̽� ���̺귯��4
    //Sleep(10);
    CSS_Debug_sendPage();//CSS 2



}






//���� ���ο��� �ߵ� �� ���� �ִ°���.
cHandler::cHandler(cSocket* sock) : page_(sock) {

    isClientDebugCountFrist++;
    printf("����� ī����1(�ѹ��� ������ �߻���.)[%d]\n", isClientDebugCountFrist);
    printf("���� ��Ĺ �ڵ鷯�� [%d]\n", sock);
    // cHandler::sendPage();
   // sendPage();
   //  printf("�ȳ�?\n");

}