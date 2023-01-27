#pragma once
#pragma once
#include "pch.h"//기본적으로 자주 바뀌는 녀석이라고 보면 돼요. lib나, 인클루드, 디파인 등이 들어있어요.
#pragma warning(disable:4996)
#include <iostream>
#pragma warning(disable:C2786)



using namespace std;


class ConversionLib : public CDialogEx {



private://접근 제어..해당 클래스에서만 쓸 수 있는 공간생성자.
	// *********************GUISYSTEM PRIVATE ALLOC*************************************


public:
	//parameta 운반 헤더

public:
	//Not parameta


	//void static First_CreateThread_Collector(SIZE_T size, LPTHREAD_START_ROUTINE APIName, int*& bigpointer_x);
		//Not parameta
	afx_msg void static Test_x();
	void static UniCodeConversion(char*& Ch, CString str);
	void static UniCodeConversion_mem_delete(char*& Ch, CString str);
	//
	void static MultiCodeConversion_mem_delete(wchar_t*& p_m_Unicode, char c_m_multi[]);
};
