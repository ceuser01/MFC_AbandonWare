#pragma once

//---------------------------- ��� ���� --------------------------//
#define BUFFER_CAPACITY   8192
#define WM_READ_MESSAGE   (WM_USER+1)     
#define ASCII_LINE_FEED   0x0a
#define ASCII_CARR_RETURN 0x0d
#define ASCII_FLOW_ON     0x11
#define ASCII_FLOW_OFF    0x13

// ������ ť Ŭ���� ���� //
class DataQueue {
public:
    BYTE buffer[BUFFER_CAPACITY];
    int  headIndex, tailIndex;

    void ResetQueueData(); // ť ������ �ʱ�ȭ
    int  QueueDataSize();  // ť ������ ũ�� ���

    BOOL ExtractByte(BYTE* pb); // 1 ����Ʈ ����
    BOOL InsertByteData(BYTE b); // 1 ����Ʈ ����
    DataQueue();
};

// ������ ��ĵ �� ���� Ŭ����: CLaserWebTransmitter
class CLaserWebTransmitter {
public:
    //--------- ȯ�� ���� -----------------------------------------//
    HANDLE      commHandle;              // ��� ��Ʈ �ڵ�
    CString     portName;                // ��Ʈ �̸� (COM1, etc.)
    BOOL        isPortOpen;              // ��Ʈ ���� ����
    OVERLAPPED  readOverlap, writeOverlap; // ������ ����ü
    HANDLE      watchCommThread;         // ���� ������ �ڵ�
    BYTE        portId;                  // ��Ʈ �ĺ���

    //--------- ��� ���� -----------------------------------------//
    DataQueue readQueue; // �б� ť

    //--------- �ܺ� ��� �Լ� ------------------------------------//
    BOOL InitializePort(CString name, DWORD baudRate, BYTE id); // ��Ʈ �ʱ�ȭ
    void TerminatePort(); // ��Ʈ ����
    DWORD SendCommData(BYTE* buffer, DWORD length); // ������ ����

    //--------- ���� ��� �Լ� ------------------------------------//
    DWORD ReceiveCommData(BYTE* buffer, DWORD length); // ������ ����
};

// ��Ʈ ���� ������ �Լ�
DWORD WatchCommThread(CLaserWebTransmitter* transmitter); // ������ ����
