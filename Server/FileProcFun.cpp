#include  "FileProcFun.h"
#include "pch.h"

void FileProcFun::ExitKey() {
	cout << "콘솔 창에 키를 입력 하시오. Q를 입력 하면 프로그램은 종료 합니다." << endl;
	char msg;
	//ShellExecuteA(0, 0,"1.exe", 0, 0, 5);
	for (;;) {
		msg = _getch();

		cout << "종료 값은: " << msg << endl;
		if (msg == 'Q') {
			cout << "프로그램을 종료 합니다." << endl;
			Sleep(500);
			exit(0);
		}
	}
}


BOOL FileProcFun::Fun_IsFileExist(CString sPathName_x, HANDLE* h) //파일 탐색 함수
{
	*h = CreateFile(sPathName_x, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
	if (*h == INVALID_HANDLE_VALUE) {
		printf("BOOL DlgFileOpenTutorialFirst::IsFileExist(CString sPathName_x , HANDLE h) Error\n");
		//FIleOpenOutPut.SetWindowTextW(L"Setting파일 명이 없습니다. DlgFileOpenTutorialFirst::IsFileExist Error");//디버깅 메세지End
		printf("etting파일 명이 없습니다. DlgFileOpenTutorialFirst::IsFileExist Error");
		return FALSE;
	}
	return TRUE;
}

//fun_Find_Dir_size

BOOL FileProcFun::Fun_Find_Dir_size(CString sPathName_x, WIN32_FIND_DATA* data) //파일 탐색 함수
{
	HANDLE hFind = FindFirstFile(sPathName_x, data);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		cout << "Error\n" << endl;
		return FALSE;
	}
	FindClose(hFind);
	return TRUE;
}

void FileProcFun::Fun_Read_Dir(char*& Read, WIN32_FIND_DATA data, HANDLE* h, wchar_t*& strUnicode2) //파일 탐색 함수
{
	LPDWORD static checksum = 0;
	size_t size_x = data.nFileSizeLow + SAFETY; //세이프티로 디파인 된 사이즈에 여분을 +1000정도 해서 안전성 높은 사이즈를
	Read = new char[size_x];
	memset(Read, NULL, (size_x) * sizeof(char));
	strUnicode2 = new wchar_t[size_x * 2 + SAFETY];
	memset(strUnicode2, 0, size_x * 2);
	while (true != ReadFile(*h, Read, size_x, checksum, 0)); //성공 할때까지 함수 연사호출
	InTerrupt::HandleCheckSum_Close(*h);//핸들클로즈
	MultiByteToWideChar(CP_ACP, 0, Read, strlen(Read), (LPWSTR)strUnicode2, size_x * 2);
	return;
}



void FileProcFun::Fun_Save_Dir(CString hFilePath, CString str) {
	cout << "FileSave" << endl;
	HANDLE fd = CreateFile((LPCTSTR)hFilePath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	InTerrupt::HandleCheckSum_x(fd);
	char* pMultibyte;
	ConversionLib::UniCodeConversion_mem_delete(pMultibyte, str);

	//UniCodeConversion_mem_delete
	if (!WriteFile(fd, pMultibyte, strlen(pMultibyte), NULL, NULL))
	{
		printf("실패\n");
		return;
	}
	printf("파일 쓰기 성공\n");
	InTerrupt::HandleCheckSum_Close(fd); //CloseHandle(fd);
}





BOOL FileProcFun::IsNetworkAvailable()
{
	DWORD flags = 0;
	DWORD bufferSize = 0;

	if (!InternetGetConnectedState(&flags, 0))
		return false;

	// 체크할 네트워크 연결 상태
	DWORD networkFlags = INTERNET_CONNECTION_LAN | INTERNET_CONNECTION_MODEM | INTERNET_CONNECTION_PROXY;

	if ((flags & networkFlags) != 0)
		return true;

	return false;
}