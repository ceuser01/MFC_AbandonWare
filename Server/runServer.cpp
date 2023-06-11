#include "pch.h"
#include "Trusted.h"


constexpr int BUFFER_SIZE = 1024;

static int Switcheron;
static int* big_pointer_ptr_x;
#include <chrono>
#include <thread>



//CreateFile_X

STACK_T runServer::CreateFile_X(LPVOID x_po) {

    return 0;
}

#include <chrono>
#include <fstream>
bool FileExists(const char* fileName) {
    std::ifstream file(fileName);
    return file.good();
}

void runServer::SaveReceivedMessageToFile(const char* receivedMessage, size_t messageLength)
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
    } while (FileExists(fileName)); // FileExists�� �ش� ������ �����ϴ��� Ȯ���ϴ� �Լ��Դϴ�.


    printf("���� ���� ICD �������� : [%s]\n", fileName);
    printf("recv ���� ���� ������: [%s]\n", receivedMessage);
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

STACK_T runServer::ProcessClient(LPVOID x_po) {
    int Debug_Count = NULL;
    int m_Mul = 1;
    size_t totalBytesReceived = 0;
    printf("ProcessClient �� ������.%p\n", x_po);

    SOCKET clientSocket = (SOCKET)x_po;

    char buffer[BUFFER_SIZE];
    int bytesRead;

    WSABUF wsaBuf;
    wsaBuf.buf = buffer;
    wsaBuf.len = BUFFER_SIZE;


    DWORD flags = 0;
    DWORD bytesReceived;

    bool shouldWaitForData = true;

    // wsaBuf �ʱ�ȭ
    memset(wsaBuf.buf, 0, wsaBuf.len);

    char* receivedMessage = new char[BIG_BUFFER_SIZE]; // ���� �Ҵ�
    memset(receivedMessage, 0, BIG_BUFFER_SIZE); // �ʱ�ȭ



    while (true) {

        if (shouldWaitForData) {

            if (BOOL Abandon = WSARecv(clientSocket, &wsaBuf, 1, &bytesReceived, &flags, nullptr, nullptr) != 0) {

                if (bytesReceived == NULL) {

                    if (Switcheron == 1) {

                        Switcheron = NULL;

                        if(totalBytesReceived ==NULL){
                            printf("Debug Error NULL totalBytesReceived\n");
                            continue;
                        }

                        printf("���� ���� �޾ƿ� ������ ������ �Դϴ�.[%d]\n", totalBytesReceived);

                        printf("���ν��� ��.\n");



                        runServer::SaveReceivedMessageToFile(receivedMessage, totalBytesReceived);
                        // printf("Received full message: %s\n", receivedMessage);
                      //  printf("Received full message: %s\n", receivedMessage.c_str());
                        memset(receivedMessage, 0, totalBytesReceived); // �ʱ�ȭ
                        Switcheron = NULL;
                        totalBytesReceived = NULL;
                        m_Mul = NULL;
                        delete[] receivedMessage;
                        char* newReceivedMessage = new char[BIG_BUFFER_SIZE];
                        // char* newReceivedMessage = (char*)realloc(receivedMessage, BIG_BUFFER_SIZE * m_Mul);
                        memset(newReceivedMessage, 0, BIG_BUFFER_SIZE); // �ʱ�ȭ

                        receivedMessage = newReceivedMessage;
                        Debug_Count = NULL;
                        //   memset()
                        //  memcpy(newReceivedMessage, receivedMessage, totalBytesReceived);
                          //    Sleep(2100);
                              //free(receivedMessage);

                        continue;
                        // const char* receivedMessage = "This is a received message";
                        // size_t messageLength = strlen(receivedMessage);


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


                    printf("���� ���� �޾ƿ� ������ ������ �Դϴ�.[%d]\n", totalBytesReceived);

                    Switcheron = NULL;
                    printf("���ν��� ��.\n");



                    runServer::SaveReceivedMessageToFile(receivedMessage, totalBytesReceived);
                    // printf("Received full message: %s\n", receivedMessage);
                  //  printf("Received full message: %s\n", receivedMessage.c_str());
                    memset(receivedMessage, 0, totalBytesReceived); // �ʱ�ȭ
                    Switcheron = NULL;
                    totalBytesReceived = NULL;
                    m_Mul = NULL;
                    delete[] receivedMessage;
                    char* newReceivedMessage = new char[BIG_BUFFER_SIZE];
                    // char* newReceivedMessage = (char*)realloc(receivedMessage, BIG_BUFFER_SIZE * m_Mul);
                    memset(newReceivedMessage, 0, BIG_BUFFER_SIZE); // �ʱ�ȭ

                    receivedMessage = newReceivedMessage;
                    Debug_Count = NULL;
                    continue;


                }


                if (bytesReceived > 0) {
                    Debug_Count++;
                    // ���ڿ��� ���
       //             printf("Received full message1: %s\n", bytesReceived);
                    printf("DebugCount[%d]\n", Debug_Count);
              
                    //     strncat(receivedMessage, buffer, bytesReceived);


                         /*
                           char* newReceivedMessage = (char*)realloc(receivedMessage, BIG_BUFFER_SIZE*2);
                             delete[] receivedMessage;
                         */


                    totalBytesReceived += bytesReceived;

                    if (totalBytesReceived >= BIG_BUFFER_SIZE * m_Mul)
                    {
                        m_Mul++;

                        size_t t_size = BIG_BUFFER_SIZE * m_Mul;
                        char* newReceivedMessage = new char[t_size + 2000];

                        // char* newReceivedMessage = (char*)realloc(receivedMessage, BIG_BUFFER_SIZE * m_Mul);
                       //  memset(newReceivedMessage, 0, BIG_BUFFER_SIZE * m_Mul); // �ʱ�ȭ
                      //   memset()
                        memcpy(newReceivedMessage, receivedMessage, totalBytesReceived);
                        //    Sleep(2100);
                            //free(receivedMessage);
                        delete[] receivedMessage;
                        receivedMessage = newReceivedMessage;
                        printf("[%p]��\n", newReceivedMessage);


                    }


                    strncat_s(receivedMessage, totalBytesReceived + 10, buffer, bytesReceived);
                    bytesReceived = NULL;
                    continue;
                }
                if (bytesReceived == 0) {
                    //  std::cout << "Client disconnected." << std::endl;
                    break;
                }


                // ������ ������ ó�� ������ �ۼ��մϴ�.
                // ...

                // Ŭ���̾�Ʈ���� ������ �����մϴ�.
                // ...

                // ��Ŷ�� ���� �Ŀ��� ���� �����͸� ��ٸ��� �ʰ� �ٷ� ������ ������ �����մϴ�.
                shouldWaitForData = false;
            }
        }
        else {


            // ��Ŷ�� ���� ������ ���� �̺�Ʈ�� ��ٸ��ϴ�.

            //DWORD waitResult = WaitForSingleObject(acceptEvent, INFINITE);
            //if (waitResult != WAIT_OBJECT_0) {
            //    std::cout << "Failed to wait for accept event." << std::endl;
            //    break;
           // }

            // ��Ŷ�� ���� �Ŀ� �ٽ� ������ ������ ���� �����մϴ�.
            shouldWaitForData = true;
        }
    }

    closesocket(clientSocket);
    delete[] receivedMessage;
    return 0;
}






//���� ��ŸƮ Ÿ��


STACK_T runServer::Timer(LPVOID x_po) {
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

STACK_T runServer::beginServer(LPVOID x_po) {


    CloseHandle(CreateThread(0, 19000, runServer::Timer, x_po, 0, 0));
    int* allocated_memory = (int*)x_po;
    big_pointer_ptr_x = allocated_memory;
    printf("���� �� ������.%p\n", x_po);
    int result = WSAStartup(MAKEWORD(2, 2), &wsa_data);
    if (result != 0) {
        printf("����. failed: %d\n", result);
        Sleep(INFINITE);
        return 1;
    }

    m_hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (m_hSocket == INVALID_SOCKET) {
        printf("m_hSocket Failed to create socket: %d\n", result);
        WSACleanup();
        Sleep(INFINITE);
        return 1;
    }


    int* port_ptr = reinterpret_cast<int*>(allocated_memory) + PORT_OFFSET;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(*port_ptr); //��Ʈ

    if (bind(m_hSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cout << "Failed to bind socket." << std::endl;
        closesocket(m_hSocket);
        WSACleanup();
        return 0;
    }



    if (listen(m_hSocket, MY_MAX_CONNECTIONS) == SOCKET_ERROR) {
        std::cout << "Failed to listen on socket." << std::endl;
        closesocket(m_hSocket);
        WSACleanup();
        return 0;
    }

    HANDLE acceptEvent = WSACreateEvent();
    if (acceptEvent == WSA_INVALID_EVENT) {
        std::cout << "Failed to create accept event." << std::endl;
        closesocket(m_hSocket);
        WSACleanup();
        return 1;
    }

    if (WSAEventSelect(m_hSocket, acceptEvent, FD_ACCEPT) == SOCKET_ERROR) {
        std::cout << "Failed to associate event with socket." << std::endl;
        closesocket(m_hSocket);
        WSACleanup();
        return 1;
    }

    u_long mode = 1;
    if (ioctlsocket(m_hSocket, FIONBIO, &mode) == SOCKET_ERROR) {
        std::cout << "Failed to set server socket to non-blocking mode." << std::endl;
        closesocket(m_hSocket);
        WSACleanup();
        return 1;
    }

    bool opt_reuseaddr = true;
    if (setsockopt(m_hSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&opt_reuseaddr, sizeof(opt_reuseaddr)) == SOCKET_ERROR) {
        std::cout << "ERROR: CSockTcp::OpenServer(): setsockopt(): " << std::endl;
        closesocket(m_hSocket);
        return false;
    }

    int* m_hSocket_ptr = reinterpret_cast<int*>(allocated_memory) + RUN_SOCKET_OFFSET;
   * m_hSocket_ptr = m_hSocket;

    while (true) {
        Sleep(1);
        DWORD waitResult = WaitForSingleObject(acceptEvent, INFINITE);
        if (waitResult != WAIT_OBJECT_0) {
            //     std::cout << "Failed to wait for accept event." << std::endl;
            break;
        }

        while (true) {
            SOCKET clientSocket = accept(m_hSocket, NULL, NULL);
            if (clientSocket == INVALID_SOCKET) {

                break;
            }

            HANDLE threadHandle = CreateThread(NULL, SMALL_T, ProcessClient, (LPVOID)clientSocket, 0, NULL);
            if (threadHandle == NULL) {
                std::cout << "Failed to create thread for client connection." << std::endl;

                continue;
            }

            CloseHandle(threadHandle);
        }
    }



    printf("Ŭ����.\n");
    Sleep(INFINITE);
}