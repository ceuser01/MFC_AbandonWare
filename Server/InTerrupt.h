#pragma once
#pragma once
#pragma once
#include "pch.h"//기본적으로 자주 바뀌는 녀석이라고 보면 돼요. lib나, 인클루드, 디파인 등이 들어있어요.
#pragma warning(disable:4996)
#include <iostream>
#pragma warning(disable:C2786)



using namespace std;


class InTerrupt   {



private://접근 제어..해당 클래스에서만 쓸 수 있는 공간생성자.
	// *********************GUISYSTEM PRIVATE ALLOC*************************************


public:
	//parameta 운반 헤더
	void static StruectureCheckSumFirst(int*& switch_on_off, wchar_t* str_p_Unicode, char* c_p_ReadData);
	void static HandleCheckSum_p(HANDLE* h);
	void static HandleCheckSum_x(HANDLE h);
	void static HandleCheckSum_Close(HANDLE h);
	//HandleCheckSum_Close

	void static intTrue(int*& inte);
	//intFalse
	void static intFalse(int*& inte);

public:
	//Not parameta
	afx_msg size_t scalar_utf8_length(LPVOID x_po, const char* c, size_t len);

};
