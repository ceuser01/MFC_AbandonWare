#include  "ConversionLib.h"
#include "pch.h"

STACK_X Disturb(LPVOID x_po) {
	printf("2���� ������ �ּҴ�[%p] �Դϴ�.\n �ش� �ּ��� ������ [%d]����ũ�� ������ �� ���ͺ� �ش� �ּ��� �޸� ������ ���ͺ� �ð��� �ٲٽ÷��� Define����� THOUSAND�� ����� �ٲټ���.\n", x_po, THOUSAND);
	Sleep(THOUSAND);
	delete[] x_po;
	x_po = NULL;
	printf("new ������ ���� ���ͺ� Ŭ����.\n");
	return 0;
}



void ConversionLib::UniCodeConversion(char*& Ch, CString str) {
	int n_len = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL); //�����ڵ� �����Ϳ��� ��Ƽ ����Ʈ�� L_len�� ��.
	Ch = new char[n_len];
	memset(Ch, NULL, (n_len) * sizeof(char));
	WideCharToMultiByte(CP_ACP, 0, str, -1, Ch, n_len, NULL, NULL);
}

void ConversionLib::UniCodeConversion_mem_delete(char*& Ch, CString str) {
	int n_len = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL); //�����ڵ� �����Ϳ��� ��Ƽ ����Ʈ�� L_len�� ��.
	Ch = new char[n_len];
	memset(Ch, 0x00, (n_len) * sizeof(char));
	WideCharToMultiByte(CP_ACP, 0, str, -1, Ch, n_len, NULL, NULL);
	ThreadProcSocket::C_First_CreateThread_Collector(SMALL_X, Disturb, *&Ch); //900 Size
}



void ConversionLib::MultiCodeConversion_mem_delete(wchar_t*& p_m_Unicode, char c_m_multi[]) {

	p_m_Unicode = new wchar_t[strlen(c_m_multi) * 2 + SAFETY];
	memset(p_m_Unicode, NULL, (strlen(c_m_multi)) * 2 + SAFETY + sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, 0, c_m_multi, strlen(c_m_multi), p_m_Unicode, strlen(c_m_multi) * 2 + SAFETY);
	printf("[%ws]\n", p_m_Unicode);
	ThreadProcSocket::WS_First_CreateThread_Collector(SMALL_X, Disturb, *&p_m_Unicode); //900 Size
}