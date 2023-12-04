#include "pch.h"
#include "MainBASE.h"

/*
타입 및 http매핑 스프레더 저장 객체
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
디버그 카운트.
*/
int cHandler::isClientDebugCountFrist = NULL; // 디버그 카운팅을 나타냄.
int cHandler::isClientDebugCountSecond = NULL; // 디버그 카운팅을 나타냄.
//#include <fstream>
//#include <sstream>
//#include <vector>

void cHandler::PNG_Debug_sendPage() {
    // 이미지 파일 경로
    const char* imagePath = ".\\image\\h_copyright.png";

    // 이미지 파일 열기
    HANDLE hFile = CreateFileA(imagePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Cannot open the image file. Error: " << GetLastError() << std::endl;
        return;
    }

    // 이미지 파일의 크기 구하기
    DWORD fileSize = GetFileSize(hFile, NULL);
    char* buffer = new char[fileSize];
    // 버퍼를 0으로 초기화
    memset(buffer, 0, fileSize);
    // 이미지 파일 읽기
    DWORD bytesRead;
    if (!ReadFile(hFile, buffer, fileSize, &bytesRead, NULL)) {
        std::cerr << "Error: Cannot read the image file. Error: " << GetLastError() << std::endl;
        CloseHandle(hFile);
        delete[] buffer;
        return;
    }

    // 데이터 크기를 문자열로 변환
    std::string contentLengthStr = std::to_string(fileSize);

    // HTTP 헤더 전송
    page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    page_.sock_->txLine("Connection: close\r\n");
    page_.sock_->txLine("Content-Type: image/png\r\n");
    page_.sock_->txLine("Content-Length: " + contentLengthStr + "\r\n");
    page_.sock_->txLine("\r\n");

    // 이미지 데이터 전송
    page_.sock_->txData(buffer, fileSize);

    // 파일 핸들과 버퍼 정리
    CloseHandle(hFile);
    delete[] buffer;

    // 소켓 종료 처리 등...
}

void cHandler::HTML_Debug_sendPage() {
    // 이미지 파일 경로

    HANDLE hFile;
    static std::string contentLengthStr;

    if (CheckReuseHtml == NULL) {

        hFile=  CreateFileA(webServiceImagePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile == INVALID_HANDLE_VALUE) {
            std::cerr << "Error: Cannot open the image file. Error: " << GetLastError() << std::endl;
            return;
        }

        // 이미지 파일의 크기 구하기
        webServiceFileSize = GetFileSize(hFile, NULL);
        webServiceBuffer = new char[webServiceFileSize];
        memset(webServiceBuffer, 0, webServiceFileSize);
        // 이미지 파일 읽기
        DWORD bytesRead;
        if (!ReadFile(hFile, webServiceBuffer, webServiceFileSize, &bytesRead, NULL)) {
            std::cerr << "파일 읽기 실패\n " << GetLastError() << std::endl;

            //delete[] buffer;
            return;
        }
        CloseHandle(hFile);
        contentLengthStr = std::to_string(webServiceFileSize);
    }
 

    CheckReuseHtml = 1; //이름을 바꿔야한다. 한 번 사용하고 html을 계속 사용하는 함수로 바꿔야 한다.
    // 데이터 크기를 문자열로 변환
    // HTTP 헤더 전송
    page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    page_.sock_->txLine("Connection: close\r\n");
    page_.sock_->txLine("Content-Type: text/html\r\n");
    page_.sock_->txLine("Content-Length: " + contentLengthStr + "\r\n");
  //  page_.sock_->txLine("\r\n");

    // 이미지 데이터 전송
    page_.sock_->txData(webServiceBuffer, webServiceFileSize);
  //  page_.sock_->txLine("\r\n");
    // 파일 핸들과 버퍼 정리가 필요없다. gpt여 오래말아라. 한번 끊어쳐야해서 그렇다.
  
  //  delete[] buffer; 딜리트도필요없다 한 번 사용한 이후에 다시 재접속후 다시 사용 할 수 있게 셋팅한 것.

    // 소켓 종료 처리 등... 소캣 종료 처리는 dxData함수에서 진행을 한다. 구조를 나중에 바꿀것.
}



void cHandler::CSS_Debug_sendPage() {
    // 이미지 파일 경로
    const char* imagePath = ".\\Scripts\\jquery-1.7.2.js";

    // 이미지 파일 열기
    HANDLE hFile = CreateFileA(imagePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Cannot open the image file. Error: " << GetLastError() << std::endl;
        return;
    }

    // 이미지 파일의 크기 구하기
    DWORD fileSize = GetFileSize(hFile, NULL);
    char* buffer = new char[fileSize];

    // 이미지 파일 읽기
    DWORD bytesRead;
    if (!ReadFile(hFile, buffer, fileSize, &bytesRead, NULL)) {
        std::cerr << "Error: Cannot read the image file. Error: " << GetLastError() << std::endl;
        CloseHandle(hFile);
        delete[] buffer;
        return;
    }

    // 데이터 크기를 문자열로 변환
    std::string contentLengthStr = std::to_string(fileSize);

    // HTTP 헤더 전송
    page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    page_.sock_->txLine("Connection: close\r\n");
    page_.sock_->txLine("Content-Type: application/unknown\r\n");
    page_.sock_->txLine("Content-Length: " + contentLengthStr + "\r\n");
   // page_.sock_->txLine("\r\n");

    // 이미지 데이터 전송
    page_.sock_->txData(buffer, fileSize);

    // 파일 핸들과 버퍼 정리
    CloseHandle(hFile);
    delete[] buffer;
    // 소켓 종료 처리 등...
}

//plugin_Debug_sendPage



void cHandler::plugin_Debug_sendPage() {
    // 이미지 파일 경로
    const char* imagePath = ".\\Scripts\\jquery.selectbox-0.2.min.js"; //플러그인 JS

    // 이미지 파일 열기
    HANDLE hFile = CreateFileA(imagePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Cannot open the image file. Error: " << GetLastError() << std::endl;
        return;
    }

    // 이미지 파일의 크기 구하기
    DWORD fileSize = GetFileSize(hFile, NULL);
    char* buffer = new char[fileSize];

    // 이미지 파일 읽기
    DWORD bytesRead;
    if (!ReadFile(hFile, buffer, fileSize, &bytesRead, NULL)) {
        std::cerr << "Error: Cannot read the image file. Error: " << GetLastError() << std::endl;
        CloseHandle(hFile);
        delete[] buffer;
        return;
    }

    // 데이터 크기를 문자열로 변환
    std::string contentLengthStr = std::to_string(fileSize);

    // HTTP 헤더 전송
    page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    // page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    // page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    page_.sock_->txLine("Connection: close\r\n");
    page_.sock_->txLine("Content-Type: application/unknown\r\n");
    page_.sock_->txLine("Content-Length: " + contentLengthStr + "\r\n");
    // page_.sock_->txLine("\r\n");

     // 이미지 데이터 전송
    page_.sock_->txData(buffer, fileSize);

    // 파일 핸들과 버퍼 정리
    CloseHandle(hFile);
    delete[] buffer;
    // 소켓 종료 처리 등...
}


void cHandler::Menu_Debug_sendPage() {
    // 이미지 파일 경로
    const char* imagePath = ".\\Scripts\\menu.js";

    // 이미지 파일 열기
    HANDLE hFile = CreateFileA(imagePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Cannot open the image file. Error: " << GetLastError() << std::endl;
        return;
    }

    // 이미지 파일의 크기 구하기
    DWORD fileSize = GetFileSize(hFile, NULL);
    char* buffer = new char[fileSize];

    // 이미지 파일 읽기
    DWORD bytesRead;
    if (!ReadFile(hFile, buffer, fileSize, &bytesRead, NULL)) {
        std::cerr << "Error: Cannot read the image file. Error: " << GetLastError() << std::endl;
        CloseHandle(hFile);
        delete[] buffer;
        return;
    }

    // 데이터 크기를 문자열로 변환
    std::string contentLengthStr = std::to_string(fileSize);

    // HTTP 헤더 전송
    page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    page_.sock_->txLine("Connection: close\r\n");
    page_.sock_->txLine("Content-Type: application/unknown\r\n");
    page_.sock_->txLine("Content-Length: " + contentLengthStr + "\r\n");
    // page_.sock_->txLine("\r\n");

     // 이미지 데이터 전송
    page_.sock_->txData(buffer, fileSize);



    // 파일 핸들과 버퍼 정리
    CloseHandle(hFile);
    delete[] buffer;
    // 소켓 종료 처리 등...
}



void cHandler::Start_Debug_sendPage() {
    // 이미지 파일 경로
    const char* imagePath = ".\\Scripts\\gamestart.js"; //플러그인 JS

    // 이미지 파일 열기
    HANDLE hFile = CreateFileA(imagePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Cannot open the image file. Error: " << GetLastError() << std::endl;
        return;
    }

    // 이미지 파일의 크기 구하기
    DWORD fileSize = GetFileSize(hFile, NULL);
    char* buffer = new char[fileSize];

    // 이미지 파일 읽기
    DWORD bytesRead;
    if (!ReadFile(hFile, buffer, fileSize, &bytesRead, NULL)) {
        std::cerr << "Error: Cannot read the image file. Error: " << GetLastError() << std::endl;
        CloseHandle(hFile);
        delete[] buffer;
        return;
    }

    // 데이터 크기를 문자열로 변환
    std::string contentLengthStr = std::to_string(fileSize);

    // HTTP 헤더 전송
    page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    page_.sock_->txLine("Connection: close\r\n");
    page_.sock_->txLine("Content-Type: application/unknown\r\n");
    page_.sock_->txLine("Content-Length: " + contentLengthStr + "\r\n");
    // page_.sock_->txLine("\r\n");

     // 이미지 데이터 전송
    page_.sock_->txData(buffer, fileSize);

    // 파일 핸들과 버퍼 정리
    CloseHandle(hFile);
    delete[] buffer;
    // 소켓 종료 처리 등...
}


void cHandler::sendPage() {

    HTML_Debug_sendPage();//HTML 1


    Menu_Debug_sendPage(); //착탄 타점 제이슨 라이브러리4
    //Sleep(10);
    CSS_Debug_sendPage();//CSS 2



}






//내부 메인에서 발동 할 수도 있는것임.
cHandler::cHandler(cSocket* sock) : page_(sock) {

    isClientDebugCountFrist++;
    printf("디버그 카운팅1(한번은 무조건 발생함.)[%d]\n", isClientDebugCountFrist);
    printf("현재 소캣 핸들러는 [%d]\n", sock);
    // cHandler::sendPage();
   // sendPage();
   //  printf("안녕?\n");

}