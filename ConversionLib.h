#pragma once
#pragma once
#include "pch.h"//�⺻������ ���� �ٲ�� �༮�̶�� ���� �ſ�. lib��, ��Ŭ���, ������ ���� ����־��.
#pragma warning(disable:4996)
#include <iostream>
#pragma warning(disable:C2786)



using namespace std;


class ConversionLib   {



private://���� ����..�ش� Ŭ���������� �� �� �ִ� ����������.
	// *********************GUISYSTEM PRIVATE ALLOC*************************************


public:
	//parameta ��� ���

public:
	//Not parameta


	//void static First_CreateThread_Collector(SIZE_T size, LPTHREAD_START_ROUTINE APIName, int*& bigpointer_x);
		//Not parameta

	void static UniCodeConversion(char*& Ch, CString str);
	void static UniCodeConversion_mem_delete(char*& Ch, CString str);
	//
	void static MultiCodeConversion_mem_delete(wchar_t*& p_m_Unicode, char c_m_multi[]);
};
