#pragma once

//---------------------------- 상수 정의 --------------------------//
#define BUFFER_CAPACITY   8192
#define WM_READ_MESSAGE   (WM_USER+1)     
#define ASCII_LINE_FEED   0x0a
#define ASCII_CARR_RETURN 0x0d
#define ASCII_FLOW_ON     0x11
#define ASCII_FLOW_OFF    0x13

// 데이터 큐 클래스 정의 //
class DataQueue {
public:
    BYTE buffer[BUFFER_CAPACITY];
    int  headIndex, tailIndex;

    void ResetQueueData(); // 큐 데이터 초기화
    int  QueueDataSize();  // 큐 데이터 크기 계산

    BOOL ExtractByte(BYTE* pb); // 1 바이트 추출
    BOOL InsertByteData(BYTE b); // 1 바이트 삽입
    DataQueue();
};

// 레이저 스캔 웹 전송 클래스: CLaserWebTransmitter
class CLaserWebTransmitter {
public:
    //--------- 환경 변수 -----------------------------------------//
    HANDLE      commHandle;              // 통신 포트 핸들
    CString     portName;                // 포트 이름 (COM1, etc.)
    BOOL        isPortOpen;              // 포트 열림 상태
    OVERLAPPED  readOverlap, writeOverlap; // 오버랩 구조체
    HANDLE      watchCommThread;         // 감시 스레드 핸들
    BYTE        portId;                  // 포트 식별자

    //--------- 통신 버퍼 -----------------------------------------//
    DataQueue readQueue; // 읽기 큐

    //--------- 외부 사용 함수 ------------------------------------//
    BOOL InitializePort(CString name, DWORD baudRate, BYTE id); // 포트 초기화
    void TerminatePort(); // 포트 종료
    DWORD SendCommData(BYTE* buffer, DWORD length); // 데이터 전송

    //--------- 내부 사용 함수 ------------------------------------//
    DWORD ReceiveCommData(BYTE* buffer, DWORD length); // 데이터 수신
};

// 포트 감시 스레드 함수
DWORD WatchCommThread(CLaserWebTransmitter* transmitter); // 스레드 감시
