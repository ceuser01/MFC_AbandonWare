#pragma once

#include "pch.h"//�⺻������ ���� �ٲ�� �༮�̶�� ���� �ſ�. lib��, ��Ŭ���, ������ ���� ����־��.






class synSocketServer {
private:

public:


    // public ��� �Լ�
    static bool FileExists(const char* fileName);
    static void SaveReceivedMessageToFile(const char* receivedMessage, size_t messageLength);
    static unsigned long __stdcall beginServer(LPVOID x_po);
    static unsigned long __stdcall ProcessClient(LPVOID x_po);
    static unsigned long __stdcall CreateFile_X(LPVOID x_po);
    static unsigned long __stdcall Timer(LPVOID x_po);
    //Timer
};

//STACK_T ServerProject::beginServer(LPVOID x_po) {