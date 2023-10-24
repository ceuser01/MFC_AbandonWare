#pragma once
#pragma once
#pragma once
#include "pch.h"//기본적으로 자주 바뀌는 녀석이라고 보면 돼요. lib나, 인클루드, 디파인 등이 들어있어요.
#pragma warning(disable:4996)
#include <iostream>




using namespace std;


class Main {



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

	void static TestDLL(LPVOID x_po);
	static void parseFrist(LPVOID x_po);
	static void parseFileSecond(LPVOID x_po);
	static void HIDDeviceFinderStart(LPVOID x_po);
	//HIDDeviceFinderStart
	//TrustMasterWheelParser.
	static void TrustMasterWheelParserStart(LPVOID x_po);
public:
	 void static __stdcall Start_Joy(LPVOID x_po);
	 void static __stdcall Start_Hid(LPVOID x_po);



};
