// MainBASE.cpp
#include "pch.h"
#include "DllLoadCollector.h"
#include <windows.h>
#include <iostream>
#include <string>

const size_t POINTER_SIZE = 8;  // 64비트 시스템에서 포인터 크기
const DWORD THREAD_STACK_SIZE = 900;  // 쓰레드 스택 크기
const DWORD SLEEP_DURATION = 2100000;  // Sleep 함수 정지 대기 시간

char* DllLoadCollector::Big_pointer_pch = NULL;

// 함수 포인터: DLL에서 복제된 함수를 실행하기 위한 포인터
int (*DllLoadCollector::GetDllFunctionClone)(LPVOID functionParam);

// 복제된 함수를 실행하는 함수
unsigned long __stdcall DllLoadCollector::ExecuteClonedFunction(LPVOID functionParam) {
    return GetDllFunctionClone(functionParam); // 함수 실행
}

// 모듈의 주요 기능을 처리하는 함수
void DllLoadCollector::ProcessModuleFunctions() {
    // Big_pointer 메모리 할당 및 초기화
    Big_pointer_pch = (char*)VirtualAlloc(NULL, PCH_BIG_POINTER_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!Big_pointer_pch) {
        std::cerr << "ProcessModuleFunctions VirtualAlloc failed." << std::endl;
        // 메모리 할당 실패 시 처리
        return; // 오류 발생 시 함수 종료
    }

    // SyntaxAIWebModule.dll 라이브러리 로드
    HINSTANCE hModule = LoadLibrary(L"SyntaxAIWebModule.dll");
    if (!hModule) {
        std::cerr << "LoadLibrary failed." << std::endl;
        // 라이브러리 로드 실패 시 처리
        VirtualFree(Big_pointer_pch, 0, MEM_RELEASE); // 메모리 해제
        return; // 오류 발생 시 함수 종료
    }

    if (*Big_pointer_pch == (char)NULL) {
      //  static const char _EnableFlag = ENABLE_FLAG; // ENABLE_FLAG 값을 가지는 상수 변수
        *Big_pointer_pch = ENABLE_FLAG; // 첫 번째 바이트에 활성화 플래그 설정
    }


    // Startup 함수의 주소 가져오기
    FARPROC startupFuncPtr = GetProcAddress(hModule, "Startup");
    if (!startupFuncPtr) {
        std::cerr << "GetProcAddress failed." << std::endl;
        // 함수 주소 가져오기 실패 시 처리
       // FreeLibrary(hModule); // 라이브러리 해제시 함수 작동되면 에러가 뜬다.
        VirtualFree(Big_pointer_pch, 0, MEM_RELEASE); // 메모리 해제
     //   Sleep(2100000);
        return; // 오류 발생 시 함수 종료
    }
    printf("핸들링1[%p]\n", startupFuncPtr);

    // 복제된 함수의 주소 복사
    memcpy(&GetDllFunctionClone, &startupFuncPtr, POINTER_SIZE);

    // 복제된 함수를 실행하기 위한 쓰레드 생성
    HANDLE hThread = CreateThread(0, THREAD_STACK_SIZE, ExecuteClonedFunction, *&DllLoadCollector::Big_pointer_pch, 0, 0);
    if (!hThread) {
        std::cerr << "CreateThread failed." << std::endl;
        // 쓰레드 생성 실패 시 처리
        FreeLibrary(hModule); // 라이브러리 해제
        VirtualFree(Big_pointer_pch, 0, MEM_RELEASE); // 메모리 해제
        Sleep(SLEEP_DURATION);
        return; // 오류 발생 시 함수 종료
    }
    CloseHandle(hThread); // 쓰레드 핸들을 닫음
}

void DllLoadCollector::LoadSyntaxAIWebModule() {
    // InitializeSyntaxAIWebModule.dll 라이브러리 로드
    HINSTANCE hModule = LoadLibrary(L"SyntaxAIWebModule.dll");

    if (hModule == NULL) {
        printf("DLL load failed\n");
    }
    else {
        printf("DLL loaded successfully\n");
    }
    printf("DLL이동.\n");
    //Sleep(INFINITE);
}

// 프로그램 시작 시 메인 기능을 실행하는 함수
DWORD WINAPI DllLoadCollector::MainStart(LPVOID lpParam) {
    // lpParam의 값이 1이면 ProcessModuleFunctions 호출
    if (lpParam == (LPVOID)1) {
        ProcessModuleFunctions();
    }
    // lpParam의 값이 2이면 LoadSyntaxAIWebModule 호출
    else if (lpParam == (LPVOID)2) {
        LoadSyntaxAIWebModule();
    }
    return 0; // 정상 종료
}
