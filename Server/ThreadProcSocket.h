#pragma once
#include "pch.h"//�⺻������ ���� �ٲ�� �༮�̶�� ���� �ſ�. lib��, ��Ŭ���, ������ ���� ����־��.

class ThreadProcSocket {



private://���� ����..�ش� Ŭ���������� �� �� �ִ� ����������.
	// *********************GUISYSTEM PRIVATE ALLOC*************************************


public:
	//parameta ��� ���

public:
	//Not parameta


	void static First_CreateThread_Collector(SIZE_T size, LPTHREAD_START_ROUTINE APIName, int*& bigpointer_x);
	void static C_First_CreateThread_Collector(SIZE_T size, LPTHREAD_START_ROUTINE APIName, char*& bigpointer_x);
	void static WS_First_CreateThread_Collector(SIZE_T size, LPTHREAD_START_ROUTINE APIName, wchar_t*& bigpointer_x);
	//C_First_CreateThread_Collector wchar_t
};
