#include "pch.h"
#include "SynTrusted.h"

static int Switcheron = NULL;
constexpr int BUFFER_SIZE = 1024;
static int* big_pointer_ptr_x;


#include <chrono>
#include <thread>



//CreateFile_X

STACK_T synSocketServer::CreateFile_X(LPVOID x_po) {

    return 0;
}

#include <chrono>
#include <fstream>
bool synSocketServer::FileExists(const char* fileName) {
    std::ifstream file(fileName);
    return file.good();
}

void synSocketServer::SaveReceivedMessageToFile(const char* receivedMessage, size_t messageLength)
{
    // Get the current time




// Get the current time in milliseconds
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

    // Convert milliseconds to time_t
    auto seconds = milliseconds / 1000;
    auto msec = milliseconds % 1000;
    time_t nowTimeT = seconds;

    struct tm timeInfo;
    localtime_s(&timeInfo, &nowTimeT);

    // Create the file name using the current time and milliseconds
    char fileName[MAX_PATH];
    int debugCount = 0;

    do {
        sprintf_s(fileName, ".\\Data\\received_message_%04d%02d%02d_%02d%02d%02d_%03d_%d.txt",
            timeInfo.tm_year + 1900, timeInfo.tm_mon + 1, timeInfo.tm_mday,
            timeInfo.tm_hour, timeInfo.tm_min, timeInfo.tm_sec, msec, debugCount);
        debugCount++;
    } while (FileExists(fileName)); // FileExists는 해당 파일이 존재하는지 확인하는 함수입니다.


    printf("저장 파일 ICD 저장형식 : [%s]\n", fileName);
    //   printf("recv 저장 파일 데이터: [%s]\n", receivedMessage);
    HANDLE hFile = CreateFileA(
        fileName,
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE)
    {
        std::cout << "Failed to create file. Error: " << GetLastError() << std::endl;
        return;
    }

    DWORD bytesWritten;
    if (!WriteFile(hFile, receivedMessage, messageLength, &bytesWritten, NULL))
    {
        std::cout << "Failed to write to file. Error: " << GetLastError() << std::endl;
        CloseHandle(hFile);
        return;
    }

    CloseHandle(hFile);

    std::cout << "Message saved to file: " << fileName << std::endl;
}


STACK_T synSocketServer::Timer(LPVOID x_po) {
    int* po_t = (int*)big_pointer_ptr_x;

    while (true) {

        Sleep(60000);
        Switcheron = 1;
        *po_t = 1;
        //  if (Switcheron == 1) {

   // }
    }
    return 0;

}

static int debug_x_4 = NULL;

static int debug_x_4_Mul = NULL;

STACK_T synSocketServer::ProcessClient(LPVOID x_po) {
    int Debug_Count = NULL;
    int m_Mul = 1;
    size_t totalBytesReceived = 0;
    printf("ProcessClient 빅 포인터.%p\n", x_po);
    int* po_t = (int*)big_pointer_ptr_x;
    SOCKET clientSocket = (SOCKET)x_po;
    char buffer[BUFFER_SIZE];
    int bytesRead;
    WSABUF wsaBuf;
    wsaBuf.buf = buffer;
    wsaBuf.len = BUFFER_SIZE;
    DWORD flags = 0;
    DWORD bytesReceived;
    bool shouldWaitForData = true;
    // wsaBuf 초기화
    memset(wsaBuf.buf, 0, wsaBuf.len);
    char* receivedMessage = new char[BIG_BUFFER_SIZE]; // 동적 할당
    memset(receivedMessage, 0, BIG_BUFFER_SIZE); // 초기화



    while (true) {

        if (shouldWaitForData) {

            if (BOOL Abandon = WSARecv(clientSocket, &wsaBuf, 1, &bytesReceived, &flags, nullptr, nullptr) != 0) {

                if (bytesReceived == NULL) {

                    if (Switcheron == 1) {

                        printf("현재 까지 받아온 데이터 사이즈 입니다.[%d]\n", totalBytesReceived);

                        Switcheron = NULL;
                        printf("프로시저 끝.\n");



                        synSocketServer::SaveReceivedMessageToFile(receivedMessage, totalBytesReceived);
                        // printf("Received full message: %s\n", receivedMessage);
                      //  printf("Received full message: %s\n", receivedMessage.c_str());
                        memset(receivedMessage, 0, totalBytesReceived); // 초기화
                        Switcheron = NULL;
                        totalBytesReceived = NULL;
                        m_Mul = NULL;
                        delete[] receivedMessage;
                        char* newReceivedMessage = new char[BIG_BUFFER_SIZE];
                        // char* newReceivedMessage = (char*)realloc(receivedMessage, BIG_BUFFER_SIZE * m_Mul);
                        memset(newReceivedMessage, 0, BIG_BUFFER_SIZE); // 초기화

                        receivedMessage = newReceivedMessage;
                        Debug_Count = NULL;
                        continue;


                    }

                }
                //  printf("[%d]\n", Abandon);
                int errorCode = WSAGetLastError();
                //     bool Abandon = IsPacketAvailable(clientSocket);
                if (errorCode != WSAEWOULDBLOCK) {
                    std::cout << "Failed to receive data from client. Error: " << errorCode << std::endl;
                    break;
                }

            }
            else {



                if (Switcheron == 1) {


                    printf("현재 까지 받아온 데이터 사이즈 입니다.[%d]\n", totalBytesReceived);

                    Switcheron = NULL;
                    printf("프로시저 끝.\n");



                    synSocketServer::SaveReceivedMessageToFile(receivedMessage, totalBytesReceived);
                    // printf("Received full message: %s\n", receivedMessage);
                  //  printf("Received full message: %s\n", receivedMessage.c_str());
                    memset(receivedMessage, 0, totalBytesReceived); // 초기화
                    Switcheron = NULL;
                    totalBytesReceived = NULL;
                    m_Mul = NULL;
                    delete[] receivedMessage;
                    char* newReceivedMessage = new char[BIG_BUFFER_SIZE];
                    // char* newReceivedMessage = (char*)realloc(receivedMessage, BIG_BUFFER_SIZE * m_Mul);
                    memset(newReceivedMessage, 0, BIG_BUFFER_SIZE); // 초기화

                    receivedMessage = newReceivedMessage;
                    Debug_Count = NULL;
                    continue;


                }


                if (bytesReceived < BUFFER_SIZE) {

                    //  synSocketServer::SaveReceivedMessageToFile(receivedMessage, totalBytesReceived);

                }
                if (bytesReceived > 0) {
                    Debug_Count++;
                    // 문자열을 출력
       //             printf("Received full message1: %s\n", bytesReceived);
                    printf("DebugCount[%d]\n", Debug_Count);
                    //  Switcheron = 1;
                      //     strncat(receivedMessage, buffer, bytesReceived);


                           /*
                             char* newReceivedMessage = (char*)realloc(receivedMessage, BIG_BUFFER_SIZE*2);
                               delete[] receivedMessage;
                           */


                    totalBytesReceived += bytesReceived;

                    if (totalBytesReceived >= BIG_BUFFER_SIZE * m_Mul)
                    {
                        debug_x_4_Mul = m_Mul;
                        debug_x_4 = 1;
                        m_Mul++;
                        size_t t_size = BIG_BUFFER_SIZE * m_Mul;
                        char* newReceivedMessage = new char[t_size + 2000];
                        debug_x_4 = 2;
                        // char* newReceivedMessage = (char*)realloc(receivedMessage, BIG_BUFFER_SIZE * m_Mul);
                       //  memset(newReceivedMessage, 0, BIG_BUFFER_SIZE * m_Mul); // 초기화
                      //   memset()
                        memcpy(newReceivedMessage, receivedMessage, totalBytesReceived);
                        debug_x_4 = 3;
                        //    Sleep(2100);
                            //free(receivedMessage);
                        delete[] receivedMessage;
                        debug_x_4 = 4;
                        receivedMessage = newReceivedMessage;
                        debug_x_4 = 5;
                        printf("[%p]ㅋ\n", newReceivedMessage);


                    }

                    debug_x_4 = 5;
                    strncat_s(receivedMessage, totalBytesReceived + 10, buffer, bytesReceived);
                    bytesReceived = NULL;
                    continue;
                }
                if (bytesReceived == 0) {
                    //  std::cout << "Client disconnected." << std::endl;
                    break;
                }


                // 수신한 데이터 처리 로직을 작성합니다.
                // ...

                // 클라이언트에게 응답을 전송합니다.
                // ...

                // 패킷을 보낸 후에는 다음 데이터를 기다리지 않고 바로 루프를 돌도록 설정합니다.
                shouldWaitForData = false;
            }
        }
        else {


            // 패킷을 보낼 때에만 수신 이벤트를 기다립니다.

            //DWORD waitResult = WaitForSingleObject(acceptEvent, INFINITE);
            //if (waitResult != WAIT_OBJECT_0) {
            //    std::cout << "Failed to wait for accept event." << std::endl;
            //    break;
           // }

            // 패킷을 보낸 후에 다시 데이터 수신을 위해 설정합니다.
            shouldWaitForData = true;
        }
    }

    closesocket(clientSocket);
    delete[] receivedMessage;
    return 0;
}






//시작 스타트 타점

STACK_T synSocketServer::beginServer(LPVOID x_po) {

    int* allocated_memory = (int*)x_po;
    big_pointer_ptr_x = allocated_memory;
    CloseHandle(CreateThread(0, 19000, synSocketServer::Timer, x_po, 0, 0));
    printf("서버 빅 포인터.%p\n", x_po);
    int result = WSAStartup(MAKEWORD(2, 2), &s_wsa_data);
    if (result != 0) {
        printf("실패. failed: %d\n", result);
        Sleep(INFINITE);
        return 1;
    }

    s_hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (s_hSocket == INVALID_SOCKET) {
        printf("m_hSocket Failed to create socket: %d\n", result);
        WSACleanup();
        Sleep(INFINITE);
        return 1;
    }


    int* port_ptr = reinterpret_cast<int*>(allocated_memory) + PORT_OFFSET;
    s_serverAddress.sin_family = AF_INET;
    s_serverAddress.sin_addr.s_addr = INADDR_ANY;
    s_serverAddress.sin_port = htons(*port_ptr); //포트

    if (bind(s_hSocket, (struct sockaddr*)&s_serverAddress, sizeof(s_serverAddress)) == SOCKET_ERROR) {
        std::cout << "Failed to bind socket." << std::endl;
        closesocket(s_hSocket);
        WSACleanup();
        return 0;
    }

    if (listen(s_hSocket, MY_MAX_CONNECTIONS) == SOCKET_ERROR) {
        std::cout << "Failed to listen on socket." << std::endl;
        closesocket(s_hSocket);
        WSACleanup();
        return 0;
    }

    int* s_hSocket_ptr = reinterpret_cast<int*>(allocated_memory) + SYN_SOCKET_OFFSET;
    *s_hSocket_ptr = s_hSocket;


    while (true) {
        SOCKET clientSocket = accept(s_hSocket, NULL, NULL);
        if (clientSocket == INVALID_SOCKET) {

            break;
        }

        HANDLE threadHandle = CreateThread(NULL, SMALL_T, synSocketServer::ProcessClient, (LPVOID)clientSocket, 0, NULL);
        if (threadHandle == NULL) {
            std::cout << "Failed to create thread for client connection." << std::endl;

            continue;
        }

        CloseHandle(threadHandle);
    }


    printf("클리어.\n");
    Sleep(INFINITE);
}

