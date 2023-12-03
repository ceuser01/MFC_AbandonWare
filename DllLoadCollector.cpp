// MainBASE.cpp
#include "pch.h"
#include "DllLoadCollector.h"
#include <windows.h>
#include <iostream>
#include <string>

const size_t POINTER_SIZE = 8;  // 64��Ʈ �ý��ۿ��� ������ ũ��
const DWORD THREAD_STACK_SIZE = 900;  // ������ ���� ũ��
const DWORD SLEEP_DURATION = 2100000;  // Sleep �Լ� ���� ��� �ð�

char* DllLoadCollector::Big_pointer_pch = NULL;

// �Լ� ������: DLL���� ������ �Լ��� �����ϱ� ���� ������
int (*DllLoadCollector::GetDllFunctionClone)(LPVOID functionParam);

// ������ �Լ��� �����ϴ� �Լ�
unsigned long __stdcall DllLoadCollector::ExecuteClonedFunction(LPVOID functionParam) {
    return GetDllFunctionClone(functionParam); // �Լ� ����
}

// ����� �ֿ� ����� ó���ϴ� �Լ�
void DllLoadCollector::ProcessModuleFunctions() {
    // Big_pointer �޸� �Ҵ� �� �ʱ�ȭ
    Big_pointer_pch = (char*)VirtualAlloc(NULL, PCH_BIG_POINTER_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!Big_pointer_pch) {
        std::cerr << "ProcessModuleFunctions VirtualAlloc failed." << std::endl;
        // �޸� �Ҵ� ���� �� ó��
        return; // ���� �߻� �� �Լ� ����
    }

    // SyntaxAIWebModule.dll ���̺귯�� �ε�
    HINSTANCE hModule = LoadLibrary(L"SyntaxAIWebModule.dll");
    if (!hModule) {
        std::cerr << "LoadLibrary failed." << std::endl;
        // ���̺귯�� �ε� ���� �� ó��
        VirtualFree(Big_pointer_pch, 0, MEM_RELEASE); // �޸� ����
        return; // ���� �߻� �� �Լ� ����
    }

    if (*Big_pointer_pch == (char)NULL) {
      //  static const char _EnableFlag = ENABLE_FLAG; // ENABLE_FLAG ���� ������ ��� ����
        *Big_pointer_pch = ENABLE_FLAG; // ù ��° ����Ʈ�� Ȱ��ȭ �÷��� ����
    }


    // Startup �Լ��� �ּ� ��������
    FARPROC startupFuncPtr = GetProcAddress(hModule, "Startup");
    if (!startupFuncPtr) {
        std::cerr << "GetProcAddress failed." << std::endl;
        // �Լ� �ּ� �������� ���� �� ó��
       // FreeLibrary(hModule); // ���̺귯�� ������ �Լ� �۵��Ǹ� ������ ���.
        VirtualFree(Big_pointer_pch, 0, MEM_RELEASE); // �޸� ����
     //   Sleep(2100000);
        return; // ���� �߻� �� �Լ� ����
    }
    printf("�ڵ鸵1[%p]\n", startupFuncPtr);

    // ������ �Լ��� �ּ� ����
    memcpy(&GetDllFunctionClone, &startupFuncPtr, POINTER_SIZE);

    // ������ �Լ��� �����ϱ� ���� ������ ����
    HANDLE hThread = CreateThread(0, THREAD_STACK_SIZE, ExecuteClonedFunction, *&DllLoadCollector::Big_pointer_pch, 0, 0);
    if (!hThread) {
        std::cerr << "CreateThread failed." << std::endl;
        // ������ ���� ���� �� ó��
        FreeLibrary(hModule); // ���̺귯�� ����
        VirtualFree(Big_pointer_pch, 0, MEM_RELEASE); // �޸� ����
        Sleep(SLEEP_DURATION);
        return; // ���� �߻� �� �Լ� ����
    }
    CloseHandle(hThread); // ������ �ڵ��� ����
}

void DllLoadCollector::LoadSyntaxAIWebModule() {
    // InitializeSyntaxAIWebModule.dll ���̺귯�� �ε�
    HINSTANCE hModule = LoadLibrary(L"SyntaxAIWebModule.dll");

    if (hModule == NULL) {
        printf("DLL load failed\n");
    }
    else {
        printf("DLL loaded successfully\n");
    }
    printf("DLL�̵�.\n");
    //Sleep(INFINITE);
}

// ���α׷� ���� �� ���� ����� �����ϴ� �Լ�
DWORD WINAPI DllLoadCollector::MainStart(LPVOID lpParam) {
    // lpParam�� ���� 1�̸� ProcessModuleFunctions ȣ��
    if (lpParam == (LPVOID)1) {
        ProcessModuleFunctions();
    }
    // lpParam�� ���� 2�̸� LoadSyntaxAIWebModule ȣ��
    else if (lpParam == (LPVOID)2) {
        LoadSyntaxAIWebModule();
    }
    return 0; // ���� ����
}
