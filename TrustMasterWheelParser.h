#pragma once
//TrustMasterWheelParser
#pragma once
#pragma once
#include "pch.h"//기본적으로 자주 바뀌는 녀석이라고 보면 돼요. lib나, 인클루드, 디파인 등이 들어있어요.
#pragma warning(disable:4996)
#include <iostream>
#pragma warning(disable:C2786)



using namespace std;

#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

class TrustMasterWheelParser {
private:

public:


    // public 멤버 함수
    static BOOL Fun_IsFileExist2(CString sPathName, HANDLE* h);
    static BOOL Fun_Find_Dir_size2(CString sPathName_x, WIN32_FIND_DATA* data);
    static void Fun_Read_Dir2(char*& Read, WIN32_FIND_DATA data, HANDLE* h, wchar_t*& strUnicode2);
    static void Fun_Save_Dir2(CString sPathName, CString getdata);
    static void FileOn2(LPVOID x_po);

    static BOOL x_FindFilePath2(CString& path);
    static BOOL x_FindFiles2(LPCTSTR path);
    static int  x_Fun_Read_Dir2(int*& p_ptr, void*& p, char*& my_c_p_ReadData, int mode, int* p_dll_ptr);
    static void parseInfo2(char* input, int* arr, size_t length);
};