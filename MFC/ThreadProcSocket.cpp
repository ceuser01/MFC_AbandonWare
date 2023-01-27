#include  "ThreadProcSocket.h"
#include "pch.h"

void Text() {
	printf("ThreadProcSocketSystem.\n");
}

//CreateThread(0, sizes, apiname, *&bigpointers, NULL, 0)


void ThreadProcSocket::First_CreateThread_Collector(SIZE_T size, LPTHREAD_START_ROUTINE APIName, int*& para) {
	HANDLE h = CreateThread(0, size, APIName, *&para, NULL, 0);
	InTerrupt::HandleCheckSum_x(h);
}

void ThreadProcSocket::C_First_CreateThread_Collector(SIZE_T size, LPTHREAD_START_ROUTINE APIName, char*& para) {
	HANDLE h = CreateThread(0, size, APIName, *&para, NULL, 0);
	InTerrupt::HandleCheckSum_x(h);
}

//WS_First_CreateThread_Collector
void ThreadProcSocket::WS_First_CreateThread_Collector(SIZE_T size, LPTHREAD_START_ROUTINE APIName, wchar_t*& para) {
	HANDLE h = CreateThread(0, size, APIName, *&para, NULL, 0);
	InTerrupt::HandleCheckSum_x(h);
}