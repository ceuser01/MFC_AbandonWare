#include "pch.h"
#include "dllmain.h"
#include "MainBASE.h"
#include <stdio.h>
#include <Windows.h>

char* dllmain::Big_pointer = NULL;
static char* Big_pointer_Copy;

// 새로운 웹 로드 함수
void dllmain::CreateWebLoadFunction(LPVOID x_po) {
    Sleep(500); //시간타이밍 함수
    printf("서브  [%p] 넘겨받은 MFC시스템 포인터\n", x_po);
}

unsigned long __stdcall dllmain::InitializeSyntaxAIWebModule(LPVOID x_po) {
    Big_pointer = (char*)VirtualAlloc(NULL, PCH_BIG_POINTER_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!Big_pointer) {
        std::cerr << "VirtualAlloc failed." << std::endl;
        return 1;
    }
    CloseHandle(CreateThread(0, 900, MainBASE::MainStart, *&Big_pointer, 0, 0)); Sleep(40);

    Sleep(500);
    printf("dll잘 로드되었으니까 걱정마라3.\n");
    return 0;
}

extern "C" __declspec(dllexport) int Startup(LPVOID x_po) {
    dllmain::CreateWebLoadFunction(x_po);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(0, 900, dllmain::InitializeSyntaxAIWebModule, *&Big_pointer_Copy, 0, 0)); Sleep(40);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}