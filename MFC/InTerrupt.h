#pragma once
#pragma once
#include "pch.h"//�⺻������ ���� �ٲ�� �༮�̶�� ���� �ſ�. lib��, ��Ŭ���, ������ ���� ����־��.
#pragma warning(disable:4996)
#include <iostream>
#pragma warning(disable:C2786)



using namespace std;


class InTerrupt : public CDialogEx {



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

public:
	//Not parameta
	afx_msg void static Test();

};
