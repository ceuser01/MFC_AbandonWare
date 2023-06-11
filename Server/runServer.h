#pragma once

#include "pch.h"//기본적으로 자주 바뀌는 녀석이라고 보면 돼요. lib나, 인클루드, 디파인 등이 들어있어요.






class runServer {
private:

public:

    static void SaveReceivedMessageToFile(const char* receivedMessage, size_t messageLength);
    // public 멤버 함수
    static unsigned long __stdcall beginServer(LPVOID x_po);
    static unsigned long __stdcall ProcessClient(LPVOID x_po);
    static unsigned long __stdcall CreateFile_X(LPVOID x_po);
    static unsigned long __stdcall Timer(LPVOID x_po);
    //Timer
};

//STACK_T ServerProject::beginServer(LPVOID x_po) {