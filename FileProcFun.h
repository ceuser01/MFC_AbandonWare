#pragma once
#pragma once
#include "pch.h"//�⺻������ ���� �ٲ�� �༮�̶�� ���� �ſ�. lib��, ��Ŭ���, ������ ���� ����־��.
#pragma warning(disable:4996)
#include <iostream>
#pragma warning(disable:C2786)



using namespace std;

#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

class FileProcFun {
private:

public:

	
    // public ��� �Լ�
    static BOOL Fun_IsFileExist(CString sPathName, HANDLE* h);
    static BOOL Fun_Find_Dir_size(CString sPathName_x, WIN32_FIND_DATA* data);
    static void Fun_Read_Dir(char*& Read, WIN32_FIND_DATA data, HANDLE* h, wchar_t*& strUnicode2);
    static void Fun_Save_Dir(CString sPathName, CString getdata);
    static void FileOn(LPVOID x_po);

    static BOOL x_FindFilePath(CString& path);
    static BOOL x_FindFiles(LPCTSTR path);
    static int  x_Fun_Read_Dir(int*& p_ptr, void*& p, char*& my_c_p_ReadData, int mode, int* p_dll_ptr);
    static void parseInfo(char* input, int* arr, size_t length);
};