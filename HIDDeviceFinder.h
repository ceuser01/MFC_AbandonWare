#pragma once
#pragma once
#pragma once
#include "pch.h"//�⺻������ ���� �ٲ�� �༮�̶�� ���� �ſ�. lib��, ��Ŭ���, ������ ���� ����־��.
#pragma warning(disable:4996)
#include <iostream>




using namespace std;


class HIDDeviceFinder {



public:
	//parameta ��� ���
	void static HIDDeviceFinderStartUp(LPVOID x_po);
	static unsigned long __stdcall Mov_left_Ac(LPVOID x_po);
	static unsigned long __stdcall Start_JoyLogicStartUP(LPVOID x_po);
	static unsigned long __stdcall mini_ptr_Key_B_API(LPVOID x_po);
	static unsigned long __stdcall mini_ptr_Key_E_API(LPVOID x_po);
	static unsigned long __stdcall mini_ptr_Key_C_API(LPVOID x_po);
	static unsigned long __stdcall mini_ptr_Key_4_API(LPVOID x_po);
	//mini_ptr_Key_4_API
	//mini_ptr_Key_B
	//Start_JoyLogicStartUP
public:
	//Not parameta

	//static void JoyLogicStartUp(LPVOID x_po);

};
