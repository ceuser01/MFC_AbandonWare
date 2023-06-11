#pragma once
#include "pch.h"//기본적으로 자주 바뀌는 녀석이라고 보면 돼요. lib나, 인클루드, 디파인 등이 들어있어요.

class ThreadProcSocket {



private://접근 제어..해당 클래스에서만 쓸 수 있는 공간생성자.
	// *********************GUISYSTEM PRIVATE ALLOC*************************************


public:
	//parameta 운반 헤더

public:
	//Not parameta


	void static First_CreateThread_Collector(SIZE_T size, LPTHREAD_START_ROUTINE APIName, int*& bigpointer_x);
	void static C_First_CreateThread_Collector(SIZE_T size, LPTHREAD_START_ROUTINE APIName, char*& bigpointer_x);
	void static WS_First_CreateThread_Collector(SIZE_T size, LPTHREAD_START_ROUTINE APIName, wchar_t*& bigpointer_x);
	//C_First_CreateThread_Collector wchar_t
};
