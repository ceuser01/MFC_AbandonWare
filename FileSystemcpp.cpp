#pragma once
#pragma once
#include "pch.h"//�⺻������ ���� �ٲ�� �༮�̶�� ���� �ſ�. lib��, ��Ŭ���, ������ ���� ����־��.
#pragma warning(disable:4996)
#include <iostream>
#pragma warning(disable:C2786)



using namespace std;


class FileProcFun {



private://���� ����..�ش� Ŭ���������� �� �� �ִ� ����������.
	// *********************GUISYSTEM PRIVATE ALLOC*************************************


public:
	//parameta ��� ���
	BOOL static Fun_IsFileExist(CString sPathName, HANDLE* h);
	BOOL static Fun_Find_Dir_size(CString sPathName_x, WIN32_FIND_DATA* data);
	void static Fun_Read_Dir(char*& Read, WIN32_FIND_DATA data, HANDLE* h, wchar_t*& strUnicode2);
	void static Fun_Save_Dir(CString sPathName, CString getdata);
public:
	//Not parameta


};