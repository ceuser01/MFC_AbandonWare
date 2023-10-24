// dllmain.cpp : DLL 애플리케이션의 진입점을 정의합니다.
#include "pch.h"



int static* pointer;

static unsigned long __stdcall Start_JoyLogicStartUP(LPVOID x_po) {

    //    ConsoleController::InitializeConsole();

    ConsoleController::InitializeConsole();
    LPVOID BIGPOINTER = VirtualAlloc(NULL, 00401000, MEM_COMMIT, PAGE_READWRITE);//dll로드할 대상의  alloc항당.
    int* x_po_copy = (int*)BIGPOINTER;
   
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Main::parseFrist, *&x_po_copy); //900 Size //타점3
    Sleep(150);
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Main::parseFileSecond, *&x_po_copy); //900 Size //타점3
    Sleep(150);
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Main::TrustMasterWheelParserStart, *&x_po_copy); //900 Size //타점3
    Sleep(150);

    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Main::Start_Joy, *&x_po_copy); //900 Size //타점1
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Main::Start_Hid, *&x_po_copy); //900 Size //타점2

    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Main::HIDDeviceFinderStart, *&x_po_copy); //900 Size //HidFinder StartUP

    while (true) {
        //   printf("TestStruct[%d]\n", (int*)x_po);
        printf("TestStructAddress End While 500 Acc[%p]\n", (int*)x_po_copy);
        //   printf("zzzzz\n");
        Sleep(500);
    }
    return 0;
}
 


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
      //  CloseHandle(CreateThread(0, 900, Start_JoyLogicStartUP, *&pointer, 0, 0)); Sleep(40);
        printf("FristDll.\n");
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

