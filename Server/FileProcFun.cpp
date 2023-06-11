#include  "FileProcFun.h"
#include "pch.h"

void FileProcFun::ExitKey() {
	cout << "�ܼ� â�� Ű�� �Է� �Ͻÿ�. Q�� �Է� �ϸ� ���α׷��� ���� �մϴ�." << endl;
	char msg;
	//ShellExecuteA(0, 0,"1.exe", 0, 0, 5);
	for (;;) {
		msg = _getch();

		cout << "���� ����: " << msg << endl;
		if (msg == 'Q') {
			cout << "���α׷��� ���� �մϴ�." << endl;
			Sleep(500);
			exit(0);
		}
	}
}


BOOL FileProcFun::Fun_IsFileExist(CString sPathName_x, HANDLE* h) //���� Ž�� �Լ�
{
	*h = CreateFile(sPathName_x, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
	if (*h == INVALID_HANDLE_VALUE) {
		printf("BOOL DlgFileOpenTutorialFirst::IsFileExist(CString sPathName_x , HANDLE h) Error\n");
		//FIleOpenOutPut.SetWindowTextW(L"Setting���� ���� �����ϴ�. DlgFileOpenTutorialFirst::IsFileExist Error");//����� �޼���End
		printf("etting���� ���� �����ϴ�. DlgFileOpenTutorialFirst::IsFileExist Error");
		return FALSE;
	}
	return TRUE;
}

//fun_Find_Dir_size

BOOL FileProcFun::Fun_Find_Dir_size(CString sPathName_x, WIN32_FIND_DATA* data) //���� Ž�� �Լ�
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

void FileProcFun::Fun_Read_Dir(char*& Read, WIN32_FIND_DATA data, HANDLE* h, wchar_t*& strUnicode2) //���� Ž�� �Լ�
{
	LPDWORD static checksum = 0;
	size_t size_x = data.nFileSizeLow + SAFETY; //������Ƽ�� ������ �� ����� ������ +1000���� �ؼ� ������ ���� �����
	Read = new char[size_x];
	memset(Read, NULL, (size_x) * sizeof(char));
	strUnicode2 = new wchar_t[size_x * 2 + SAFETY];
	memset(strUnicode2, 0, size_x * 2);
	while (true != ReadFile(*h, Read, size_x, checksum, 0)); //���� �Ҷ����� �Լ� ����ȣ��
	InTerrupt::HandleCheckSum_Close(*h);//�ڵ�Ŭ����
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
		printf("����\n");
		return;
	}
	printf("���� ���� ����\n");
	InTerrupt::HandleCheckSum_Close(fd); //CloseHandle(fd);
}





BOOL FileProcFun::IsNetworkAvailable()
{
	DWORD flags = 0;
	DWORD bufferSize = 0;

	if (!InternetGetConnectedState(&flags, 0))
		return false;

	// üũ�� ��Ʈ��ũ ���� ����
	DWORD networkFlags = INTERNET_CONNECTION_LAN | INTERNET_CONNECTION_MODEM | INTERNET_CONNECTION_PROXY;

	if ((flags & networkFlags) != 0)
		return true;

	return false;
}