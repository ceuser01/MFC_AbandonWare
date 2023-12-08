#include "pch.h"
#include "MainBASE.h"
/*

이해했습니다. 제공된 소스 코드의 변수들을 기능과 관련성에 따라 분류하고 정리하겠습니다. 이를 통해 코드의 구조가 더 명확해지고 가독성이 향상됩니다.

웹 서비스 관련 변수
*/

// 웹 서비스 관련 변수
LPVOID cHandler::handlerContextPtr; // MainBase 경유 관련 BigPointer

std::string cHandler::webServiceImagePath; // 웹 서비스 이미지 경로
std::string cHandler::crc32ValidationFilePath; // CRC32 기본 베이스 경로
std::string cHandler::calculatedCrc32Checksum; // CRC32 기본 베이스 경로
//calculatedCrc32Checksum


char* cHandler::webServiceBuffer = nullptr; // 웹 서비스 이미지 버퍼
DWORD cHandler::webServiceFileSize = 0; // 웹 서비스 이미지 파일 크기
int cHandler::CheckReuseHtml = 0; // HTML 재사용 여부 체크

std::string cHandler::webServiceContentLengthStr = ""; // 웹 서비스 컨텐츠 길이 문자열

std::string cHandler::rootPageContentLength = ""; // rootPageContentLength 서비스 컨텐츠 길이 문자열
std::string cHandler::jQueryScriptContentLength = ""; // jQueryScriptContentLength 웹 서비스 컨텐츠 길이 문자열

const DWORD THREAD_STACK_SIZE = 32900;  // 쓰레드 스택 크기
// 스레드 스택 크기를 상수로 정의

/*
스크립트 관련 변수
스크립트 관련 변수들은 웹 서비스에서 사용되는 JavaScript 및 CSS 파일의 로딩 상태, 버퍼, 파일 크기 등을 저장합니다.


*/

// 스크립트 관련 변수
int cHandler::isScriptReused = 0; // 일반 스크립트 재사용 여부
char* cHandler::scriptBuffer = nullptr; // 일반 스크립트 버퍼
DWORD cHandler::scriptFileSize = 0; // 일반 스크립트 파일 크기

int cHandler::isMenuScriptLoaded = 0; // 메뉴 스크립트 로드 여부
char* cHandler::menuScriptBuffer = nullptr; // 메뉴 스크립트 버퍼
DWORD cHandler::menuScriptSize = 0; // 메뉴 스크립트 크기


/*
서버 및 클라이언트 디버깅 관련 변수
서버 및 클라이언트 디버깅과 관련된 변수들은 클라이언트 요청 처리 및 디버깅 상태를 추적하는 데 사용됩니다.
*/
// 서버 및 클라이언트 디버깅 관련 변수
int cHandler::isClientDebugCountFrist = NULL; // 클라이언트 요청 처리 디버그 카운트
int cHandler::isClientDebugCountSecond = NULL; // 추가 클라이언트 요청 처리 디버그 카운트

/*
HTTP 상태 및 페이지 매핑 관련 변수
HTTP 상태 코드, 페이지 매핑 등과 관련된 변수들은 HTTP 응답과 관련된 데이터를 저장합니다.
*/
// HTTP 상태 및 페이지 매핑 관련 변수
string_map MainBASE::myMap; // HTTP 요청 매핑
string_map MainBASE::statuscodes; // HTTP 상태 코드 매핑
string_map MainBASE::statuspages; // HTTP 상태 페이지 매핑
void cHandler::sendPngImage() {
    // 이미지 파일 경로
    const char* imagePath = ".\\image\\h_copyright.png";

    //isScriptReused

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
    memset(buffer, 0, fileSize+5);
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

void cHandler::checkAndSetGoogleDrivePath() {
    const std::string googleDriveFolder = "\\내 드라이브";
    const std::string indexPath = "\\index.html";
    const std::string indexPathCRC = "\\ConfigCRC32.ini";
    const std::string indexPathCRCSum = "\\FileChecksums.ini";
    DWORD drives = GetLogicalDrives();

    for (char drive = 'C'; drive <= 'Z'; ++drive) {
        if (drives & (1 << (drive - 'A'))) {
            std::string drivePath = std::string(1, drive) + ":\\" + googleDriveFolder;
            if (GetFileAttributesA(drivePath.c_str()) != INVALID_FILE_ATTRIBUTES) {
                webServiceImagePath = drivePath + indexPath;
                crc32ValidationFilePath = drivePath + indexPathCRC;
                calculatedCrc32Checksum = drivePath + indexPathCRCSum;
                std::cout << "경로 설정: " << webServiceImagePath << std::endl;
                return;
            }
        }
    }

    std::cout << "구글 드라이브 경로를 찾을 수 없습니다." << std::endl;
}

void cHandler::sendRootPage() {
    // 이미지 파일 경로


  

    
    rootPageContentLength = std::to_string(webServiceFileSize);

    SOCKET socketHandle = page_.sock_->getSocketHandle(); // cSocket 인스턴스로부터 소켓 핸들을 가져옵니다.

   // HTTP 헤더 전송
    std::string htmlContent = "AbandonWare";
    send(socketHandle, "HTTP/1.1 200 OK\r\n", strlen("HTTP/1.1 200 OK\r\n"), 0);
    send(socketHandle, "Connection: close\r\n", strlen("Connection: close\r\n"), 0);
    send(socketHandle, "Content-Type: text/html\r\n", strlen("Content-Type: text/html\r\n"), 0);
    send(socketHandle, ("Content-Length: " + rootPageContentLength + htmlContent+ "\r\n").c_str(), strlen(("Content-Length: " + rootPageContentLength + htmlContent + "\r\n").c_str()), 0);
    send(socketHandle, "\r\n", strlen("\r\n"), 0);


   // std::string contentLengthStr = std::to_string(htmlContent.length());

    // 콘텐츠 길이 전송
 //   send(clientSocket, ("Content-Length: " + contentLengthStr + "\r\n").c_str(), strlen(("Content-Length: " + contentLengthStr + "\r\n").c_str()), 0);



    // 웹 서비스 버퍼 데이터 전송
    const int MAX_RETRY_COUNT = 5;  // 최대 재시도 횟수
    const int RETRY_INTERVAL_MS = 100;  // 재시도 간격 (밀리초)

    int bytesSent = 0;  // 전송된 바이트 수
    int retryCount = 0;  // 현재 재시도 횟수

    while (bytesSent < webServiceFileSize && retryCount < MAX_RETRY_COUNT) {
        int result = send(socketHandle, webServiceBuffer + bytesSent, webServiceFileSize - bytesSent, 0);

        if (result > 0) {
            bytesSent += result;  // 성공적으로 전송된 바이트 수 업데이트
        }
        else if (result == SOCKET_ERROR) {
            if (WSAGetLastError() == WSAEWOULDBLOCK) {
                // 네트워크가 바쁘다는 신호, 잠시 대기 후 재시도
                Sleep(RETRY_INTERVAL_MS);
                retryCount++;
            }
            else {
                // 기타 네트워크 오류
                break;
            }
        }
    }

    if (bytesSent < webServiceFileSize) {
        // 전체 데이터가 전송되지 않았음을 처리
        printf("AbandonWareError");
    }

   // send(socketHandle, htmlContent.c_str(), htmlContent.length(), 0);

}



void cHandler::sendJQueryScript() {

    // 스크립트 파일 경로
    HANDLE hFile;
    static std::string contentLengthStr;


    if (isScriptReused == NULL) {

        // HTML이 아닌 JavaScript 파일을 재사용하는 경우
        if (isScriptReused == NULL) {
            hFile = CreateFileA(".\\Scripts\\jquery-1.7.2.js", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            if (hFile == INVALID_HANDLE_VALUE) {
                std::cerr << "Error: Cannot open the JavaScript file. Error: " << GetLastError() << std::endl;
                return;
            }

            // 스크립트 파일의 크기 구하기
            scriptFileSize = GetFileSize(hFile, NULL);
            scriptBuffer = new char[scriptFileSize+5];
            memset(scriptBuffer, 0, scriptFileSize+5);

            // 스크립트 파일 읽기
            DWORD bytesRead;
            if (!ReadFile(hFile, scriptBuffer, scriptFileSize, &bytesRead, NULL)) {
                std::cerr << "Error: Cannot read the JavaScript file. Error: " << GetLastError() << std::endl;
                CloseHandle(hFile);
                delete[] scriptBuffer;
                return;
            }
            CloseHandle(hFile);
            contentLengthStr = std::to_string(scriptFileSize);
        }

        // JavaScript 파일을 계속 사용하도록 설정
    }
    isScriptReused = 1;




    // HTTP 헤더 전송
   /* page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    page_.sock_->txLine("Connection: close\r\n");
    page_.sock_->txLine("Content-Type: application/javascript\r\n");
    page_.sock_->txLine("Content-Length: " + contentLengthStr + "\r\n");
    page_.sock_->txLine("\r\n");

    // 스크립트 데이터 전송
    page_.sock_->_txData(scriptBuffer, scriptFileSize);
    */
    cSocket* socketPtr = (cSocket*)page_.sock_; // cSocket 객체의 포인터를 얻습니다.
   // cSocket* socketPtr = (cSocket*)page_.sock_;
    SOCKET socketHandle = socketPtr->getSocketHandle(); // SOCKET 핸들 얻기
  //  char* scriptBuffer; // 스크립트 데이터가 저장된 버퍼
  //  int scriptFileSize=NULL;       // 스크립트 파일의 크기

    // HTTP 헤더 전송
    send(socketHandle, "HTTP/1.1 200 OK\r\n", strlen("HTTP/1.1 200 OK\r\n"), 0);
    send(socketHandle, "Connection: close\r\n", strlen("Connection: close\r\n"), 0);
    send(socketHandle, "Content-Type: application/javascript\r\n", strlen("Content-Type: application/javascript\r\n"), 0);
    send(socketHandle, ("Content-Length: " + contentLengthStr + "\r\n").c_str(), strlen(("Content-Length: " + contentLengthStr + "\r\n").c_str()), 0);
    send(socketHandle, "\r\n", strlen("\r\n"), 0);

    // 스크립트 데이터 전송
    send(socketHandle, scriptBuffer, scriptFileSize, 0);


}

//plugin_Debug_sendPage


void cHandler::sendMenuScript() {


        cSocket* socketPtr = (cSocket*)page_.sock_; // cSocket 객체의 포인터를 얻습니다.
         // cSocket* socketPtr = (cSocket*)page_.sock_;
        SOCKET socketHandle = socketPtr->getSocketHandle(); // SOCKET 핸들 얻기
      //  char* scriptBuffer; // 스크립트 데이터가 저장된 버퍼
      //  int scriptFileSize=NULL;       // 스크립트 파일의 크기

      //  Sleep(500);

        // HTTP 헤더 전송
        send(socketHandle, "HTTP/1.1 200 OK\r\n", strlen("HTTP/1.1 200 OK\r\n"), 0);
        send(socketHandle, "Connection: close\r\n", strlen("Connection: close\r\n"), 0);
        send(socketHandle, "Content-Type: application/javascript\r\n", strlen("Content-Type: application/javascript\r\n"), 0);
        send(socketHandle, ("Content-Length: " + jQueryScriptContentLength + "\r\n").c_str(), strlen(("Content-Length: " + jQueryScriptContentLength + "\r\n").c_str()), 0);
        send(socketHandle, "\r\n", strlen("\r\n"), 0);

        // 메뉴 스크립트 데이터 전송
        send(socketHandle, menuScriptBuffer, menuScriptSize, 0);
        closesocket(socketHandle);
        printf("menu Stat\n");

    
}

void cHandler::sendPage() {


}

typedef void(NTAPI* PFN_RtlExitUserThread)(ULONG ExitStatus);

unsigned long __stdcall cHandler::ExitThreadSafely(LPVOID lpParam)
{
    HMODULE ntdllModule = GetModuleHandleW(L"ntdll.dll");
    if (ntdllModule == NULL)
    {
        std::cout << "Failed to load ntdll.dll" << std::endl;
        return 0;
    }

    PFN_RtlExitUserThread pfnRtlExitUserThread = reinterpret_cast<PFN_RtlExitUserThread>(GetProcAddress(ntdllModule, "RtlExitUserThread"));
    if (pfnRtlExitUserThread == NULL)
    {
        std::cout << "Failed to get address of RtlExitUserThread" << std::endl;
        return 0;
    }

    // 종료 상태 코드를 0으로 설정하여 스레드 종료
    pfnRtlExitUserThread(0);
    return 0;
}


//checkHtmlPresenceMonitorThread

unsigned long __stdcall cHandler::checkHtmlPresenceMonitorThread(LPVOID lpParam) {
    DWORD prevSize = webServiceFileSize; // 이전에 계산된 HTML 파일 크기

    while (true) {
        Sleep(500); // 0.5초 대기

        // HTML 파일의 크기 확인
        std::ifstream htmlFile(webServiceImagePath, std::ios::binary | std::ios::ate);
        if (!htmlFile.is_open()) {
            std::cerr << "Monitor Thread Error: Cannot open HTML file. Error: " << std::endl;
            continue;
        }

        DWORD currentSize = static_cast<DWORD>(htmlFile.tellg());

        // HTML 파일 크기가 변경되었는지 확인
        if (currentSize != prevSize) {
            printf("Detected change in HTML file. Total size: %lu bytes\n", currentSize);

            // 기존 버퍼 메모리 해제
            delete[] webServiceBuffer;
            webServiceBuffer = nullptr;
            webServiceFileSize = 0;
            isMenuScriptLoaded = 0;
            CloseHandle(CreateThread(0, THREAD_STACK_SIZE, UpdateWebContentState, lpParam, 0, 0));
            ExitThreadSafely(lpParam);//종료

            // 새로운 HTML 파일 읽기
            htmlFile.seekg(0, std::ios::beg);
            webServiceBuffer = new char[currentSize + 1]; // +1 for null-terminator
            if (htmlFile.read(webServiceBuffer, currentSize)) {
                webServiceBuffer[currentSize] = '\0'; // null-terminate the buffer
                webServiceFileSize = currentSize; // 파일 크기 업데이트
            }
            else {
                std::cerr << "Error: Cannot read HTML file: " << webServiceImagePath << std::endl;
                delete[] webServiceBuffer;
                webServiceBuffer = nullptr;

            }

            prevSize = currentSize; // 새로운 사이즈로 업데이트
        }
    }

    return 0;

}

unsigned long __stdcall cHandler::checkFilePresenceMonitorThread(LPVOID lpParam) {
    DWORD prevSize = menuScriptSize; // 이전에 계산된 스크립트 크기

    while (true) {
        Sleep(500); // 0.5초 대기

        WIN32_FIND_DATAA findFileData;
        HANDLE hFind = FindFirstFileA(".\\jsScripts\\*.js", &findFileData);

        if (hFind == INVALID_HANDLE_VALUE) {
            std::cerr << "Monitor Thread Error: Cannot find JavaScript files. Error: " << GetLastError() << std::endl;
            continue;
        }

        DWORD totalSize = 0; // 현재 계산된 총 스크립트 크기
        do {
            std::string scriptPath = ".\\jsScripts\\" + std::string(findFileData.cFileName);
            std::ifstream scriptFile(scriptPath, std::ios::binary | std::ios::ate);

            if (scriptFile) {
                totalSize += static_cast<DWORD>(scriptFile.tellg());
            }
        } while (FindNextFileA(hFind, &findFileData) != 0);

        FindClose(hFind);

        if (totalSize != prevSize) {
            printf("Detected change in script files. Total size: %lu bytes\n", totalSize);

            // 메뉴 스크립트 버퍼 삭제
            delete[] menuScriptBuffer;
            menuScriptBuffer = nullptr;
            menuScriptSize = 0;

            // updateStartStatus 스레드 생성
            CloseHandle(CreateThread(0, THREAD_STACK_SIZE, UpdateHtmlAndJavaScriptState, lpParam, 0, 0));
            isMenuScriptLoaded = 0;
            ExitThreadSafely(lpParam);
            return 0;

          //  prevSize = totalSize; // 새로운 사이즈로 업데이트
        }
    }

    return 0;
}

//UpdateHtmlAndJavaScriptState

unsigned long __stdcall cHandler::UpdateHtmlAndJavaScriptState(LPVOID lpParam) {

    printf("StartWebService[%p]updateStartStatus 스타트업 빅 포인터.\n", lpParam);

    // JavaScript 파일들을 찾기 위한 경로와 핸들
    WIN32_FIND_DATAA findFileData; // ASCII 버전의 구조체
    HANDLE hFind = FindFirstFileA(".\\jsScripts\\*.js", &findFileData); // ASCII 버전의 함수

    if (hFind == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Cannot find JavaScript files in the directory. Error: " << GetLastError() << std::endl;
        return 0;
    }

    std::vector<std::string> scriptContents;

    do {
        // 스크립트 파일 경로 생성
        std::string scriptPath = ".\\jsScripts\\" + std::string(findFileData.cFileName);

        // 각 스크립트 파일을 읽음
        std::ifstream scriptFile(scriptPath, std::ios::binary);
        if (scriptFile) {
            std::string content((std::istreambuf_iterator<char>(scriptFile)), std::istreambuf_iterator<char>());
            scriptContents.push_back(content);
        }
        else {
            std::cerr << "Error: Cannot open JavaScript file: " << scriptPath << std::endl;
        }
    } while (FindNextFileA(hFind, &findFileData) != 0); // ASCII 버전의 함수

    FindClose(hFind);

    // 모든 스크립트 파일의 내용을 합침
    std::string combinedScripts;
    for (const auto& script : scriptContents) {
        combinedScripts += script;
    }

    // 최종 합친 스크립트를 menuScriptBuffer에 저장
    menuScriptSize = combinedScripts.size();
    menuScriptBuffer = new char[menuScriptSize + 1];
    strcpy_s(menuScriptBuffer, menuScriptSize + 1, combinedScripts.c_str());

    isMenuScriptLoaded = 1;

    CloseHandle(CreateThread(0, THREAD_STACK_SIZE, checkFilePresenceMonitorThread, *&lpParam, 0, 0));

    return 0;
}

unsigned long __stdcall cHandler::UpdateWebContentState(LPVOID lpParam) {
    printf("WebStartUP\n.");

    // 기존 이미지 파일 처리 로직을 유지
    HANDLE hFile = CreateFileA(webServiceImagePath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Cannot open the file at path: " << webServiceImagePath << ". Error: " << GetLastError() << std::endl;
        return 0;
    }

    // 파일의 크기 구하기
    webServiceFileSize = GetFileSize(hFile, NULL);
    webServiceBuffer = new char[webServiceFileSize];
    memset(webServiceBuffer, 0, webServiceFileSize);

    // 파일 읽기
    DWORD bytesRead;
    if (!ReadFile(hFile, webServiceBuffer, webServiceFileSize, &bytesRead, NULL)) {
        std::cerr << "파일 읽기 실패\n " << GetLastError() << std::endl;
        delete[] webServiceBuffer;
        return 0;
    }
    CloseHandle(hFile);

    //checkHtmlPresenceMonitorThread
        CloseHandle(CreateThread(0, THREAD_STACK_SIZE, checkHtmlPresenceMonitorThread, *&lpParam, 0, 0));

    return 0;
}



unsigned long __stdcall cHandler::updateStartStatus(LPVOID lpParam) {
    CloseHandle(CreateThread(0, THREAD_STACK_SIZE, UpdateHtmlAndJavaScriptState, *&lpParam, 0, 0));
    CloseHandle(CreateThread(0, THREAD_STACK_SIZE, UpdateWebContentState, *&lpParam, 0, 0));
    return 0;
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