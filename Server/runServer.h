#pragma once

#include "pch.h"//�⺻������ ���� �ٲ�� �༮�̶�� ���� �ſ�. lib��, ��Ŭ���, ������ ���� ����־��.






class runServer {
private:

public:

    static void SaveReceivedMessageToFile(const char* receivedMessage, size_t messageLength);
    // public ��� �Լ�
    static unsigned long __stdcall beginServer(LPVOID x_po);
    static unsigned long __stdcall ProcessClient(LPVOID x_po);
    static unsigned long __stdcall CreateFile_X(LPVOID x_po);
    static unsigned long __stdcall Timer(LPVOID x_po);
    //Timer
};

//STACK_T ServerProject::beginServer(LPVOID x_po) {