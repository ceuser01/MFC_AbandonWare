#pragma once
#pragma once
#include "pch.h"//기본적으로 자주 바뀌는 녀석이라고 보면 돼요. lib나, 인클루드, 디파인 등이 들어있어요.
#pragma warning(disable:4996)
#include <iostream>
#pragma warning(disable:C2786)



using namespace std;


class FileProcFun {



private://접근 제어..해당 클래스에서만 쓸 수 있는 공간생성자.
	// *********************GUISYSTEM PRIVATE ALLOC*************************************


public:
	//parameta 운반 헤더
	BOOL static Fun_IsFileExist(CString sPathName, HANDLE* h);
	BOOL static Fun_Find_Dir_size(CString sPathName_x, WIN32_FIND_DATA* data);
	void static Fun_Read_Dir(char*& Read, WIN32_FIND_DATA data, HANDLE* h, wchar_t*& strUnicode2);
	void static Fun_Save_Dir(CString sPathName, CString getdata);
public:
	//Not parameta


};