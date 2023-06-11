#include  "InTerrupt.h"
#include "pch.h"





void InTerrupt::StruectureCheckSumFirst(int*& switch_on_off, wchar_t* str_p_Unicode, char* c_p_ReadData) {
	if (switch_on_off == (int*)TRUE) {

		delete[] str_p_Unicode;
		str_p_Unicode = NULL;
		delete[] c_p_ReadData;
		c_p_ReadData = NULL;
		InTerrupt::intFalse(*&switch_on_off);
	}
}


void InTerrupt::HandleCheckSum_p(HANDLE* h) {
	if (*h == NULL || *h == (HANDLE*)-1) {
		cout << "InTerrupt::HandleCheckSumError_p" << endl;
		Sleep(SOMAXCONN);
	}
}

void InTerrupt::HandleCheckSum_x(HANDLE h) {
	if (h == NULL || h == (HANDLE)-1) {
		cout << "InTerrupt::HandleCheckSumError" << endl;


		Sleep(SOMAXCONN);
	}
}


void InTerrupt::HandleCheckSum_Close(HANDLE h) {
	if (h == NULL || h == (HANDLE)-1) {
		cout << "InTerrupt::HandleCheckSumError" << endl;
		Sleep(SOMAXCONN);
	}
	CloseHandle(h);
}

void InTerrupt::intTrue(int*& inte) {
	inte = (int*)TRUE;
}


void InTerrupt::intFalse(int*& inte) {
	inte = (int*)FALSE;
}



