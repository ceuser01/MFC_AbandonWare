// 헤더 파일
#pragma once
//#include "pch.h"
#include <windows.h>
#include <iostream>
#include <stdio.h>

#define DLL_FUNC static unsigned long __stdcall

class dllmain {
public:
    static char* Big_pointer;
    static unsigned long __stdcall InitializeSyntaxAIWebModule(LPVOID x_po);
    static void CreateWebLoadFunction(LPVOID x_po);
    //static extern "C" __declspec(dllexport) int Startup(LPVOID x_po);

};