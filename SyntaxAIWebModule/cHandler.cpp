#include "pch.h"
#include "MainBASE.h"
/*

�����߽��ϴ�. ������ �ҽ� �ڵ��� �������� ��ɰ� ���ü��� ���� �з��ϰ� �����ϰڽ��ϴ�. �̸� ���� �ڵ��� ������ �� ��Ȯ������ �������� ���˴ϴ�.

�� ���� ���� ����
*/

// �� ���� ���� ����
LPVOID cHandler::handlerContextPtr; // MainBase ���� ���� BigPointer

std::string cHandler::webServiceImagePath; // �� ���� �̹��� ���
std::string cHandler::crc32ValidationFilePath; // CRC32 �⺻ ���̽� ���
std::string cHandler::calculatedCrc32Checksum; // CRC32 �⺻ ���̽� ���
//calculatedCrc32Checksum


char* cHandler::webServiceBuffer = nullptr; // �� ���� �̹��� ����
DWORD cHandler::webServiceFileSize = 0; // �� ���� �̹��� ���� ũ��
int cHandler::CheckReuseHtml = 0; // HTML ���� ���� üũ

std::string cHandler::webServiceContentLengthStr = ""; // �� ���� ������ ���� ���ڿ�

std::string cHandler::rootPageContentLength = ""; // rootPageContentLength ���� ������ ���� ���ڿ�
std::string cHandler::jQueryScriptContentLength = ""; // jQueryScriptContentLength �� ���� ������ ���� ���ڿ�

const DWORD THREAD_STACK_SIZE = 32900;  // ������ ���� ũ��
// ������ ���� ũ�⸦ ����� ����

/*
��ũ��Ʈ ���� ����
��ũ��Ʈ ���� �������� �� ���񽺿��� ���Ǵ� JavaScript �� CSS ������ �ε� ����, ����, ���� ũ�� ���� �����մϴ�.


*/

// ��ũ��Ʈ ���� ����
int cHandler::isScriptReused = 0; // �Ϲ� ��ũ��Ʈ ���� ����
char* cHandler::scriptBuffer = nullptr; // �Ϲ� ��ũ��Ʈ ����
DWORD cHandler::scriptFileSize = 0; // �Ϲ� ��ũ��Ʈ ���� ũ��

int cHandler::isMenuScriptLoaded = 0; // �޴� ��ũ��Ʈ �ε� ����
char* cHandler::menuScriptBuffer = nullptr; // �޴� ��ũ��Ʈ ����
DWORD cHandler::menuScriptSize = 0; // �޴� ��ũ��Ʈ ũ��


/*
���� �� Ŭ���̾�Ʈ ����� ���� ����
���� �� Ŭ���̾�Ʈ ������ ���õ� �������� Ŭ���̾�Ʈ ��û ó�� �� ����� ���¸� �����ϴ� �� ���˴ϴ�.
*/
// ���� �� Ŭ���̾�Ʈ ����� ���� ����
int cHandler::isClientDebugCountFrist = NULL; // Ŭ���̾�Ʈ ��û ó�� ����� ī��Ʈ
int cHandler::isClientDebugCountSecond = NULL; // �߰� Ŭ���̾�Ʈ ��û ó�� ����� ī��Ʈ

/*
HTTP ���� �� ������ ���� ���� ����
HTTP ���� �ڵ�, ������ ���� ��� ���õ� �������� HTTP ����� ���õ� �����͸� �����մϴ�.
*/
// HTTP ���� �� ������ ���� ���� ����
string_map MainBASE::myMap; // HTTP ��û ����
string_map MainBASE::statuscodes; // HTTP ���� �ڵ� ����
string_map MainBASE::statuspages; // HTTP ���� ������ ����
void cHandler::sendPngImage() {
    // �̹��� ���� ���
    const char* imagePath = ".\\image\\h_copyright.png";

    //isScriptReused

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
    memset(buffer, 0, fileSize+5);
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

void cHandler::checkAndSetGoogleDrivePath() {
    const std::string googleDriveFolder = "\\�� ����̺�";
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
                std::cout << "��� ����: " << webServiceImagePath << std::endl;
                return;
            }
        }
    }

    std::cout << "���� ����̺� ��θ� ã�� �� �����ϴ�." << std::endl;
}

void cHandler::sendRootPage() {
    // �̹��� ���� ���


  

    
    rootPageContentLength = std::to_string(webServiceFileSize);

    SOCKET socketHandle = page_.sock_->getSocketHandle(); // cSocket �ν��Ͻ��κ��� ���� �ڵ��� �����ɴϴ�.

   // HTTP ��� ����
    std::string htmlContent = "AbandonWare";
    send(socketHandle, "HTTP/1.1 200 OK\r\n", strlen("HTTP/1.1 200 OK\r\n"), 0);
    send(socketHandle, "Connection: close\r\n", strlen("Connection: close\r\n"), 0);
    send(socketHandle, "Content-Type: text/html\r\n", strlen("Content-Type: text/html\r\n"), 0);
    send(socketHandle, ("Content-Length: " + rootPageContentLength + htmlContent+ "\r\n").c_str(), strlen(("Content-Length: " + rootPageContentLength + htmlContent + "\r\n").c_str()), 0);
    send(socketHandle, "\r\n", strlen("\r\n"), 0);


   // std::string contentLengthStr = std::to_string(htmlContent.length());

    // ������ ���� ����
 //   send(clientSocket, ("Content-Length: " + contentLengthStr + "\r\n").c_str(), strlen(("Content-Length: " + contentLengthStr + "\r\n").c_str()), 0);



    // �� ���� ���� ������ ����
    const int MAX_RETRY_COUNT = 5;  // �ִ� ��õ� Ƚ��
    const int RETRY_INTERVAL_MS = 100;  // ��õ� ���� (�и���)

    int bytesSent = 0;  // ���۵� ����Ʈ ��
    int retryCount = 0;  // ���� ��õ� Ƚ��

    while (bytesSent < webServiceFileSize && retryCount < MAX_RETRY_COUNT) {
        int result = send(socketHandle, webServiceBuffer + bytesSent, webServiceFileSize - bytesSent, 0);

        if (result > 0) {
            bytesSent += result;  // ���������� ���۵� ����Ʈ �� ������Ʈ
        }
        else if (result == SOCKET_ERROR) {
            if (WSAGetLastError() == WSAEWOULDBLOCK) {
                // ��Ʈ��ũ�� �ٻڴٴ� ��ȣ, ��� ��� �� ��õ�
                Sleep(RETRY_INTERVAL_MS);
                retryCount++;
            }
            else {
                // ��Ÿ ��Ʈ��ũ ����
                break;
            }
        }
    }

    if (bytesSent < webServiceFileSize) {
        // ��ü �����Ͱ� ���۵��� �ʾ����� ó��
        printf("AbandonWareError");
    }

   // send(socketHandle, htmlContent.c_str(), htmlContent.length(), 0);

}



void cHandler::sendJQueryScript() {

    // ��ũ��Ʈ ���� ���
    HANDLE hFile;
    static std::string contentLengthStr;


    if (isScriptReused == NULL) {

        // HTML�� �ƴ� JavaScript ������ �����ϴ� ���
        if (isScriptReused == NULL) {
            hFile = CreateFileA(".\\Scripts\\jquery-1.7.2.js", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            if (hFile == INVALID_HANDLE_VALUE) {
                std::cerr << "Error: Cannot open the JavaScript file. Error: " << GetLastError() << std::endl;
                return;
            }

            // ��ũ��Ʈ ������ ũ�� ���ϱ�
            scriptFileSize = GetFileSize(hFile, NULL);
            scriptBuffer = new char[scriptFileSize+5];
            memset(scriptBuffer, 0, scriptFileSize+5);

            // ��ũ��Ʈ ���� �б�
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

        // JavaScript ������ ��� ����ϵ��� ����
    }
    isScriptReused = 1;




    // HTTP ��� ����
   /* page_.sock_->txLine("HTTP/1.1 200 OK\r\n");
    page_.sock_->txLine("Connection: close\r\n");
    page_.sock_->txLine("Content-Type: application/javascript\r\n");
    page_.sock_->txLine("Content-Length: " + contentLengthStr + "\r\n");
    page_.sock_->txLine("\r\n");

    // ��ũ��Ʈ ������ ����
    page_.sock_->_txData(scriptBuffer, scriptFileSize);
    */
    cSocket* socketPtr = (cSocket*)page_.sock_; // cSocket ��ü�� �����͸� ����ϴ�.
   // cSocket* socketPtr = (cSocket*)page_.sock_;
    SOCKET socketHandle = socketPtr->getSocketHandle(); // SOCKET �ڵ� ���
  //  char* scriptBuffer; // ��ũ��Ʈ �����Ͱ� ����� ����
  //  int scriptFileSize=NULL;       // ��ũ��Ʈ ������ ũ��

    // HTTP ��� ����
    send(socketHandle, "HTTP/1.1 200 OK\r\n", strlen("HTTP/1.1 200 OK\r\n"), 0);
    send(socketHandle, "Connection: close\r\n", strlen("Connection: close\r\n"), 0);
    send(socketHandle, "Content-Type: application/javascript\r\n", strlen("Content-Type: application/javascript\r\n"), 0);
    send(socketHandle, ("Content-Length: " + contentLengthStr + "\r\n").c_str(), strlen(("Content-Length: " + contentLengthStr + "\r\n").c_str()), 0);
    send(socketHandle, "\r\n", strlen("\r\n"), 0);

    // ��ũ��Ʈ ������ ����
    send(socketHandle, scriptBuffer, scriptFileSize, 0);


}

//plugin_Debug_sendPage


void cHandler::sendMenuScript() {


        cSocket* socketPtr = (cSocket*)page_.sock_; // cSocket ��ü�� �����͸� ����ϴ�.
         // cSocket* socketPtr = (cSocket*)page_.sock_;
        SOCKET socketHandle = socketPtr->getSocketHandle(); // SOCKET �ڵ� ���
      //  char* scriptBuffer; // ��ũ��Ʈ �����Ͱ� ����� ����
      //  int scriptFileSize=NULL;       // ��ũ��Ʈ ������ ũ��

      //  Sleep(500);

        // HTTP ��� ����
        send(socketHandle, "HTTP/1.1 200 OK\r\n", strlen("HTTP/1.1 200 OK\r\n"), 0);
        send(socketHandle, "Connection: close\r\n", strlen("Connection: close\r\n"), 0);
        send(socketHandle, "Content-Type: application/javascript\r\n", strlen("Content-Type: application/javascript\r\n"), 0);
        send(socketHandle, ("Content-Length: " + jQueryScriptContentLength + "\r\n").c_str(), strlen(("Content-Length: " + jQueryScriptContentLength + "\r\n").c_str()), 0);
        send(socketHandle, "\r\n", strlen("\r\n"), 0);

        // �޴� ��ũ��Ʈ ������ ����
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

    // ���� ���� �ڵ带 0���� �����Ͽ� ������ ����
    pfnRtlExitUserThread(0);
    return 0;
}


//checkHtmlPresenceMonitorThread

unsigned long __stdcall cHandler::checkHtmlPresenceMonitorThread(LPVOID lpParam) {
    DWORD prevSize = webServiceFileSize; // ������ ���� HTML ���� ũ��

    while (true) {
        Sleep(500); // 0.5�� ���

        // HTML ������ ũ�� Ȯ��
        std::ifstream htmlFile(webServiceImagePath, std::ios::binary | std::ios::ate);
        if (!htmlFile.is_open()) {
            std::cerr << "Monitor Thread Error: Cannot open HTML file. Error: " << std::endl;
            continue;
        }

        DWORD currentSize = static_cast<DWORD>(htmlFile.tellg());

        // HTML ���� ũ�Ⱑ ����Ǿ����� Ȯ��
        if (currentSize != prevSize) {
            printf("Detected change in HTML file. Total size: %lu bytes\n", currentSize);

            // ���� ���� �޸� ����
            delete[] webServiceBuffer;
            webServiceBuffer = nullptr;
            webServiceFileSize = 0;
            isMenuScriptLoaded = 0;
            CloseHandle(CreateThread(0, THREAD_STACK_SIZE, UpdateWebContentState, lpParam, 0, 0));
            ExitThreadSafely(lpParam);//����

            // ���ο� HTML ���� �б�
            htmlFile.seekg(0, std::ios::beg);
            webServiceBuffer = new char[currentSize + 1]; // +1 for null-terminator
            if (htmlFile.read(webServiceBuffer, currentSize)) {
                webServiceBuffer[currentSize] = '\0'; // null-terminate the buffer
                webServiceFileSize = currentSize; // ���� ũ�� ������Ʈ
            }
            else {
                std::cerr << "Error: Cannot read HTML file: " << webServiceImagePath << std::endl;
                delete[] webServiceBuffer;
                webServiceBuffer = nullptr;

            }

            prevSize = currentSize; // ���ο� ������� ������Ʈ
        }
    }

    return 0;

}

unsigned long __stdcall cHandler::checkFilePresenceMonitorThread(LPVOID lpParam) {
    DWORD prevSize = menuScriptSize; // ������ ���� ��ũ��Ʈ ũ��

    while (true) {
        Sleep(500); // 0.5�� ���

        WIN32_FIND_DATAA findFileData;
        HANDLE hFind = FindFirstFileA(".\\jsScripts\\*.js", &findFileData);

        if (hFind == INVALID_HANDLE_VALUE) {
            std::cerr << "Monitor Thread Error: Cannot find JavaScript files. Error: " << GetLastError() << std::endl;
            continue;
        }

        DWORD totalSize = 0; // ���� ���� �� ��ũ��Ʈ ũ��
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

            // �޴� ��ũ��Ʈ ���� ����
            delete[] menuScriptBuffer;
            menuScriptBuffer = nullptr;
            menuScriptSize = 0;

            // updateStartStatus ������ ����
            CloseHandle(CreateThread(0, THREAD_STACK_SIZE, UpdateHtmlAndJavaScriptState, lpParam, 0, 0));
            isMenuScriptLoaded = 0;
            ExitThreadSafely(lpParam);
            return 0;

          //  prevSize = totalSize; // ���ο� ������� ������Ʈ
        }
    }

    return 0;
}

//UpdateHtmlAndJavaScriptState

unsigned long __stdcall cHandler::UpdateHtmlAndJavaScriptState(LPVOID lpParam) {

    printf("StartWebService[%p]updateStartStatus ��ŸƮ�� �� ������.\n", lpParam);

    // JavaScript ���ϵ��� ã�� ���� ��ο� �ڵ�
    WIN32_FIND_DATAA findFileData; // ASCII ������ ����ü
    HANDLE hFind = FindFirstFileA(".\\jsScripts\\*.js", &findFileData); // ASCII ������ �Լ�

    if (hFind == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Cannot find JavaScript files in the directory. Error: " << GetLastError() << std::endl;
        return 0;
    }

    std::vector<std::string> scriptContents;

    do {
        // ��ũ��Ʈ ���� ��� ����
        std::string scriptPath = ".\\jsScripts\\" + std::string(findFileData.cFileName);

        // �� ��ũ��Ʈ ������ ����
        std::ifstream scriptFile(scriptPath, std::ios::binary);
        if (scriptFile) {
            std::string content((std::istreambuf_iterator<char>(scriptFile)), std::istreambuf_iterator<char>());
            scriptContents.push_back(content);
        }
        else {
            std::cerr << "Error: Cannot open JavaScript file: " << scriptPath << std::endl;
        }
    } while (FindNextFileA(hFind, &findFileData) != 0); // ASCII ������ �Լ�

    FindClose(hFind);

    // ��� ��ũ��Ʈ ������ ������ ��ħ
    std::string combinedScripts;
    for (const auto& script : scriptContents) {
        combinedScripts += script;
    }

    // ���� ��ģ ��ũ��Ʈ�� menuScriptBuffer�� ����
    menuScriptSize = combinedScripts.size();
    menuScriptBuffer = new char[menuScriptSize + 1];
    strcpy_s(menuScriptBuffer, menuScriptSize + 1, combinedScripts.c_str());

    isMenuScriptLoaded = 1;

    CloseHandle(CreateThread(0, THREAD_STACK_SIZE, checkFilePresenceMonitorThread, *&lpParam, 0, 0));

    return 0;
}

unsigned long __stdcall cHandler::UpdateWebContentState(LPVOID lpParam) {
    printf("WebStartUP\n.");

    // ���� �̹��� ���� ó�� ������ ����
    HANDLE hFile = CreateFileA(webServiceImagePath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Cannot open the file at path: " << webServiceImagePath << ". Error: " << GetLastError() << std::endl;
        return 0;
    }

    // ������ ũ�� ���ϱ�
    webServiceFileSize = GetFileSize(hFile, NULL);
    webServiceBuffer = new char[webServiceFileSize];
    memset(webServiceBuffer, 0, webServiceFileSize);

    // ���� �б�
    DWORD bytesRead;
    if (!ReadFile(hFile, webServiceBuffer, webServiceFileSize, &bytesRead, NULL)) {
        std::cerr << "���� �б� ����\n " << GetLastError() << std::endl;
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



//���� ���ο��� �ߵ� �� ���� �ִ°���.
cHandler::cHandler(cSocket* sock) : page_(sock) {

    isClientDebugCountFrist++;
    printf("����� ī����1(�ѹ��� ������ �߻���.)[%d]\n", isClientDebugCountFrist);
    printf("���� ��Ĺ �ڵ鷯�� [%d]\n", sock);
    // cHandler::sendPage();
   // sendPage();
   //  printf("�ȳ�?\n");

}