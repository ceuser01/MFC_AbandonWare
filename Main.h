#pragma once
#pragma once
#pragma once
#include "pch.h"//�⺻������ ���� �ٲ�� �༮�̶�� ���� �ſ�. lib��, ��Ŭ���, ������ ���� ����־��.
#pragma warning(disable:4996)
#include <iostream>




using namespace std;


class Main {



private://���� ����..�ش� Ŭ���������� �� �� �ִ� ����������.
	// *********************GUISYSTEM PRIVATE ALLOC*************************************


public:
	//parameta ��� ���
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
