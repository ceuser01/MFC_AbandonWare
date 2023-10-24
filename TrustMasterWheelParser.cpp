#include  "TrustMasterWheelParser.h"
#include "pch.h"

BOOL TrustMasterWheelParser::Fun_IsFileExist2(CString sPathName_x, HANDLE* h) //파일 탐색 함수
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

BOOL TrustMasterWheelParser::Fun_Find_Dir_size2(CString sPathName_x, WIN32_FIND_DATA* datas) //파일 탐색 함수
{
	HANDLE hFind = FindFirstFile(sPathName_x, datas);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		cout << "Error\n" << endl;
		return FALSE;
	}
	FindClose(hFind);
	return TRUE;
}

void TrustMasterWheelParser::Fun_Read_Dir2(char*& Read, WIN32_FIND_DATA datas, HANDLE* h, wchar_t*& strUnicode2) //파일 탐색 함수
{
	LPDWORD checksum = 0;
	size_t size_x = datas.nFileSizeLow + SAFETY; //세이프티로 디파인 된 사이즈에 여분을 +1000정도 해서 안전성 높은 사이즈를
	Read = new char[size_x];
	memset(Read, NULL, (size_x) * sizeof(char));
	strUnicode2 = new wchar_t[size_x * 2 + SAFETY];
	memset(strUnicode2, 0, size_x * 2);
	while (true != ReadFile(*h, Read, size_x, checksum, 0)); //성공 할때까지 함수 연사호출
	InTerrupt::HandleCheckSum_Close(*h);//핸들클로즈
	MultiByteToWideChar(CP_ACP, 0, Read, strlen(Read), (LPWSTR)strUnicode2, size_x * 2);
	return;
}



void TrustMasterWheelParser::Fun_Save_Dir2(CString hFilePath, CString str) {
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

BOOL TrustMasterWheelParser::x_FindFiles2(LPCTSTR path)
{
	DWORD dwAttrib = GetFileAttributes(path);

	return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
		!(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

BOOL TrustMasterWheelParser::x_FindFilePath2(CString& path)
{
	// 파일이 이미 존재하는 경우, 해당 경로를 반환
	if (TrustMasterWheelParser::x_FindFiles2(path)) {
		return TRUE;
	}

	// 상대 경로인 경우, 현재 디렉토리와 현재 디렉토리의 상위 디렉토리에서 파일을 찾음
	CString relativePath = path;
	if (relativePath.Find(_T(':')) < 0 && relativePath.Find('\\') < 0 && relativePath.Find('/') < 0) {
		TCHAR buffer[MAX_PATH];
		GetCurrentDirectory(MAX_PATH, buffer);
		if (TrustMasterWheelParser::x_FindFiles2(CString(buffer) + _T('\\') + relativePath)) {
			path = CString(buffer) + _T('\\') + relativePath;
			return TRUE;
		}
		if (PathRemoveFileSpec(buffer)) {
			if (TrustMasterWheelParser::x_FindFiles2(CString(buffer) + _T('\\') + relativePath)) {
				path = CString(buffer) + _T('\\') + relativePath;
				return TRUE;
			}
		}
	}

	return FALSE;
}

#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <codecvt>
#pragma execution_character_set("utf-8")
#include <sstream>
#include <vector>


int TrustMasterWheelParser::x_Fun_Read_Dir2(int*& p_ptr, void*& p, char*& my_c_p_ReadData, int mode, int* p_dll_ptr) {
	std::string unknown_str2[50];// = "";
	int* P_dump_m;
	char** str_ptr;
	int* P_dump_m_2;// = p_dll_ptr;
	int result = -1;
	switch (mode) {
	case WHEEL_MODE_POINTER:
		if (std::string(my_c_p_ReadData).find("erSize}=") != std::string::npos) {
			result = WHEEL_MODE_POINTER;
		}
		break;
	case WHEEL_MODE_TEXT:
		if (std::string(my_c_p_ReadData).find("ext}=") == std::string::npos || std::string(my_c_p_ReadData).size() < 5 || std::string(my_c_p_ReadData).substr(std::string(my_c_p_ReadData).size() - 2) != "XT") {
			result = WHEEL_MODE_TEXT;
		}
		break;
	case WHEEL_MODE_KEY_FRIST:
		if (std::string(my_c_p_ReadData).find("y:") == std::string::npos || std::string(my_c_p_ReadData).size() < 4 || std::string(my_c_p_ReadData).substr(std::string(my_c_p_ReadData).size() - 2) != "ey") {
			result = WHEEL_MODE_KEY_FRIST;
		}
		break;
	case WHEEL_MODE_KEY_SECOND:
		if (std::string(my_c_p_ReadData).find("y:") == std::string::npos || std::string(my_c_p_ReadData).size() < 4 || std::string(my_c_p_ReadData).substr(std::string(my_c_p_ReadData).size() - 2) != "ey") {
			result = WHEEL_MODE_KEY_SECOND;
		}
		break;
	case WHEEL_MODE_KEY_THIRD:
		if (std::string(my_c_p_ReadData).find("y:") == std::string::npos || std::string(my_c_p_ReadData).size() < 3 || std::string(my_c_p_ReadData).substr(std::string(my_c_p_ReadData).size() - 2) != "ze") {
			result = WHEEL_MODE_KEY_THIRD;
		}
		break;

	case WHEEL_MODE_KEY_FOURTH:
		if (std::string(my_c_p_ReadData).find("y:") == std::string::npos || std::string(my_c_p_ReadData).size() < 3 || std::string(my_c_p_ReadData).substr(std::string(my_c_p_ReadData).size() - 2) != "ze") {
			result = WHEEL_MODE_KEY_FOURTH;
		}
		break;
	case WHEEL_MODE_KEY_FIVE:
		if (std::string(my_c_p_ReadData).find("y:") == std::string::npos || std::string(my_c_p_ReadData).size() < 3 || std::string(my_c_p_ReadData).substr(std::string(my_c_p_ReadData).size() - 2) != "ze") {
			result = WHEEL_MODE_KEY_FIVE;
		}
		break;
	default:
		result = -1;
		break;
	}

	if (result == -1) {
		return result;
	}
	switch (result) {
	case WHEEL_MODE_POINTER: {
		size_t pos = std::string(my_c_p_ReadData).find("=");
		if (pos == std::string::npos)
			return -1;
		std::string substring = std::string(my_c_p_ReadData).substr(pos + 1);
		pos = substring.find(';');
		if (pos == std::string::npos)
			return -1;
		substring = substring.substr(0, pos);
		int pointer_size = std::stoi(substring, nullptr, 16);
		//p_dll_ptr = new int[pointer_size / sizeof(int)];
		//memset(p_dll_ptr, 0, pointer_size);
		//*p_dll_ptr = pointer_size;
		return mode;
	}
	case WHEEL_MODE_TEXT: {
		P_dump_m = p_dll_ptr;
		std::string str = std::string(my_c_p_ReadData);
		size_t pos = str.find("{loadText}=");
		if (pos != std::string::npos) {
			str = str.substr(pos + strlen("{loadText}="));
		}


		size_t start_pos = str.find("{");
		size_t end_pos = str.find("}");
		int debug = 0;
		while (start_pos != std::string::npos && end_pos != std::string::npos && start_pos < end_pos && debug < 50) {
			unknown_str2[debug] = str.substr(start_pos + 1, end_pos - start_pos - 1);
			std::cout << unknown_str2[debug] << std::endl;
			start_pos = str.find("{", end_pos + 1);
			end_pos = str.find("}", end_pos + 1);
			debug++;
			std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
			std::wstring wstr = conv.from_bytes(unknown_str2[debug]);
			std::wcout << wstr << std::endl;
		}
		str_ptr = new char* [debug];

		for (int i = 0; i < debug; i++) {
			str_ptr[i] = new char[unknown_str2[i].size() + 1];
			strcpy_s(str_ptr[i], unknown_str2[i].size() + 1, unknown_str2[i].c_str());
			char* char_ptr = str_ptr[i];

			memcpy(P_dump_m, char_ptr, 80);
			//	*P_dump_m = reinterpret_cast<int>(char_ptr); //배열 포인터 주소 넣기
			printf("[%p]debug1\n", P_dump_m);
			P_dump_m = P_dump_m + 80 / 4;// 포인터 오프셋 증가
		}

		P_dump_m = p_dll_ptr; //복제 포인터로 포인터 원래 주소 복원.
		return mode;
	}
	case WHEEL_MODE_KEY_FRIST: {
		P_dump_m = p_dll_ptr + KEY_OFFSET_FRIST;
		std::string str2 = std::string(my_c_p_ReadData);
		size_t pos = str2.find("{Key1dwButtons}=");
		if (pos != std::string::npos) {
			str2 = str2.substr(pos + strlen("{Key1dwButtons}="));
		}
		size_t start_pos = str2.find("{");
		size_t end_pos = str2.find("}");
		int debug = 0;
		while (start_pos != std::string::npos && end_pos != std::string::npos && start_pos < end_pos && debug < 50) {
			unknown_str2[debug] = str2.substr(start_pos + 1, end_pos - start_pos - 1);
			std::cout << unknown_str2[debug] << std::endl;
			start_pos = str2.find("{", end_pos + 1);
			end_pos = str2.find("}", end_pos + 1);
			debug++;
			std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
			std::wstring wstr = conv.from_bytes(unknown_str2[debug]);
			std::wcout << wstr << std::endl;
		}
		str_ptr = new char* [debug];

		for (int i = 0; i < debug; i++) {
			str_ptr[i] = new char[unknown_str2[i].size() + 1];
			strcpy_s(str_ptr[i], unknown_str2[i].size() + 1, unknown_str2[i].c_str());
			char* char_ptr = str_ptr[i];
			memcpy(P_dump_m, char_ptr, unknown_str2[i].size() + 1);
			printf("[%p]debug1\n", P_dump_m);
			P_dump_m++;
		}
		P_dump_m = p_dll_ptr;
		break;
	}
	case WHEEL_MODE_KEY_SECOND: {
		P_dump_m = p_dll_ptr + KEY_OFFSET_SECOND;
		std::string str2 = std::string(my_c_p_ReadData);
		size_t pos = str2.find("{Key2dwpos}=");
		if (pos != std::string::npos) {
			str2 = str2.substr(pos + strlen("{Key2dwpos}="));
		}
		size_t start_pos = str2.find("{");
		size_t end_pos = str2.find("}");
		int debug = 0;
		while (start_pos != std::string::npos && end_pos != std::string::npos && start_pos < end_pos && debug < 50) {
			unknown_str2[debug] = str2.substr(start_pos + 1, end_pos - start_pos - 1);
			std::cout << unknown_str2[debug] << std::endl;
			start_pos = str2.find("{", end_pos + 1);
			end_pos = str2.find("}", end_pos + 1);
			debug++;
			std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
			std::wstring wstr = conv.from_bytes(unknown_str2[debug]);
			std::wcout << wstr << std::endl;
		}
		str_ptr = new char* [debug];

		for (int i = 0; i < debug; i++) {
			str_ptr[i] = new char[unknown_str2[i].size() + 1];
			strcpy_s(str_ptr[i], unknown_str2[i].size() + 1, unknown_str2[i].c_str());
			char* char_ptr = str_ptr[i];
			memcpy(P_dump_m, char_ptr, unknown_str2[i].size() + 1);
			printf("[%p]debug1\n", P_dump_m);
			P_dump_m++;
		}
		P_dump_m = p_dll_ptr;
		break;
	}


	case WHEEL_MODE_KEY_THIRD: {
		P_dump_m = p_dll_ptr + KEY_OFFSET_THIRD;
		std::string str2 = std::string(my_c_p_ReadData);
		size_t pos = str2.find("{Key3POV}=");
		if (pos != std::string::npos) {
			str2 = str2.substr(pos + strlen("{Key3POV}="));
		}
		size_t start_pos = str2.find("{");
		size_t end_pos = str2.find("}");
		int debug = 0;
		while (start_pos != std::string::npos && end_pos != std::string::npos && start_pos < end_pos && debug < 50) {
			unknown_str2[debug] = str2.substr(start_pos + 1, end_pos - start_pos - 1);
			std::cout << unknown_str2[debug] << std::endl;
			start_pos = str2.find("{", end_pos + 1);
			end_pos = str2.find("}", end_pos + 1);
			debug++;
			std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
			std::wstring wstr = conv.from_bytes(unknown_str2[debug]);
			std::wcout << wstr << std::endl;
		}
		str_ptr = new char* [debug];

		for (int i = 0; i < debug; i++) {
			str_ptr[i] = new char[unknown_str2[i].size() + 1];
			strcpy_s(str_ptr[i], unknown_str2[i].size() + 1, unknown_str2[i].c_str());
			char* char_ptr = str_ptr[i];
			memcpy(P_dump_m, char_ptr, unknown_str2[i].size() + 1);
			printf("[%p]debug1\n", P_dump_m);
			P_dump_m++;
		}
		P_dump_m = p_dll_ptr;
		break;
	}
	case WHEEL_MODE_KEY_FOURTH: {
		P_dump_m = p_dll_ptr + KEY_OFFSET_FOURTH;
		std::string str2 = std::string(my_c_p_ReadData);
		size_t pos = str2.find("{Key4dwSwitch}=");
		if (pos != std::string::npos) {
			str2 = str2.substr(pos + strlen("{Key4dwSwitch}="));
		}
		size_t start_pos = str2.find("{");
		size_t end_pos = str2.find("}");
		int debug = 0;
		while (start_pos != std::string::npos && end_pos != std::string::npos && start_pos < end_pos && debug < 50) {
			unknown_str2[debug] = str2.substr(start_pos + 1, end_pos - start_pos - 1);
			std::cout << unknown_str2[debug] << std::endl;
			start_pos = str2.find("{", end_pos + 1);
			end_pos = str2.find("}", end_pos + 1);
			debug++;
			std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
			std::wstring wstr = conv.from_bytes(unknown_str2[debug]);
			std::wcout << wstr << std::endl;
		}
		str_ptr = new char* [debug];

		for (int i = 0; i < debug; i++) {
			str_ptr[i] = new char[unknown_str2[i].size() + 1];
			strcpy_s(str_ptr[i], unknown_str2[i].size() + 1, unknown_str2[i].c_str());
			char* char_ptr = str_ptr[i];
			memcpy(P_dump_m, char_ptr, unknown_str2[i].size() + 1);
			printf("[%p]debug1\n", P_dump_m);

			P_dump_m++;
		}
		P_dump_m = p_dll_ptr;
		break;
	}
	case WHEEL_MODE_KEY_FIVE: {
		P_dump_m = p_dll_ptr + KEY_OFFSET_FIVE;
		std::string str2 = std::string(my_c_p_ReadData);
		size_t pos = str2.find("{Key5JoySize}=");
		if (pos != std::string::npos) {
			str2 = str2.substr(pos + strlen("{Key5JoySize}="));
		}
		size_t start_pos = str2.find("{");
		size_t end_pos = str2.find("}");
		int debug = 0;
		while (start_pos != std::string::npos && end_pos != std::string::npos && start_pos < end_pos && debug < 50) {
			unknown_str2[debug] = str2.substr(start_pos + 1, end_pos - start_pos - 1);
			std::cout << unknown_str2[debug] << std::endl;
			start_pos = str2.find("{", end_pos + 1);
			end_pos = str2.find("}", end_pos + 1);
			debug++;
			std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
			std::wstring wstr = conv.from_bytes(unknown_str2[debug]);
			std::wcout << wstr << std::endl;
		}
		str_ptr = new char* [debug];

		for (int i = 0; i < debug; i++) {
			str_ptr[i] = new char[unknown_str2[i].size() + 1];
			strcpy_s(str_ptr[i], unknown_str2[i].size() + 1, unknown_str2[i].c_str());
			char* char_ptr = str_ptr[i];
			//memcpy(P_dump_m, char_ptr, unknown_str[i].size() + 1);
		//	printf("[%p]debug1\n", P_dump_m);
			P_dump_m[i] = stoi(unknown_str2[i]);
			printf("zzz");
			//P_dump_m++;
		}
		P_dump_m = p_dll_ptr;
		break;
	}
							break;
	default:
		return -1;
	}
	return result;
}



void TrustMasterWheelParser::parseInfo2(char* input, int* arr, size_t length) {
	std::istringstream ss(input);
	std::string line;
	int i = 0;

	while (getline(ss, line) && i < length) {
		std::string key = line.substr(0, line.find(":"));
		std::string value = line.substr(line.find(":") + 2);
		arr[i] = stoi(value);
		i++;
	}
}





#include <iostream>
#include <sstream>
#include <string>

using namespace std;





void TrustMasterWheelParser::FileOn2(LPVOID x_po) {
	int* p_dll_ptr;
	WIN32_FIND_DATA  filedata2; //파일 데이터 스트럭쳐.
	int* p_ptr;// = (int*)x_po;

	HANDLE hFile2;
	//CString  strpath2=L"C:\\Users\\BigPictures\\Desktop\\FristDll222222323\\FristDll\\Setting.txt";
	int num = 0;
	CString  strpath2 = L"TrustMasterWheelParser.ini";
	TrustMasterWheelParser::x_FindFilePath2(strpath2);
	int* switch_on_off2 = &num;
	char* my_c_p_ReadData = static_cast<char*>(static_cast<void*>(static_cast<int*>(x_po) + 1800));
	wchar_t* str_p_Unicode2 = static_cast<wchar_t*>(static_cast<void*>(static_cast<int*>(x_po) + 2000));

	InTerrupt::StruectureCheckSumFirst(*&switch_on_off2, str_p_Unicode2, my_c_p_ReadData); //생성된 메모리를 디스터브 하는 함수이다.

	TrustMasterWheelParser::Fun_Find_Dir_size2(strpath2, &filedata2);//strpath의 경로 안에 filedata의 스트럭처 데이터를 집어넣는다. size와 잡다한 파일 날짜 등의 데이터를 가져온다.
	TrustMasterWheelParser::Fun_IsFileExist2(strpath2, &hFile2);//strpath의 경로 안에 hFile에 hFile 크레이트파일아 데이터를 가져온다.
	//경로와 hFile핸들 정보를 가져온다. 핸들 정보는 &로 말아서 포인터처럼 리턴할떄 재반환 하게 준비한다. 
	TrustMasterWheelParser::Fun_Read_Dir2(*&my_c_p_ReadData, filedata2, &hFile2, *&str_p_Unicode2);
	//해당 경로의 데이터의 정보를 메모리에 올리고 캐싱한다. 
	InTerrupt::intTrue(*&switch_on_off2); //비활성화 스위치 On
	void* pointersize;
	p_dll_ptr = static_cast<int*>(static_cast<void*>(static_cast<int*>(x_po) + TRUSTMASTER_OFFSET));

	TrustMasterWheelParser::x_Fun_Read_Dir2(p_ptr, pointersize, *&my_c_p_ReadData, WHEEL_MODE_POINTER, p_dll_ptr);
	TrustMasterWheelParser::x_Fun_Read_Dir2(p_ptr, pointersize, *&my_c_p_ReadData, WHEEL_MODE_TEXT, p_dll_ptr);
	TrustMasterWheelParser::x_Fun_Read_Dir2(p_ptr, pointersize, *&my_c_p_ReadData, WHEEL_MODE_KEY_FRIST, p_dll_ptr);
	TrustMasterWheelParser::x_Fun_Read_Dir2(p_ptr, pointersize, *&my_c_p_ReadData, WHEEL_MODE_KEY_SECOND, p_dll_ptr);
	TrustMasterWheelParser::x_Fun_Read_Dir2(p_ptr, pointersize, *&my_c_p_ReadData, WHEEL_MODE_KEY_THIRD, p_dll_ptr);
	TrustMasterWheelParser::x_Fun_Read_Dir2(p_ptr, pointersize, *&my_c_p_ReadData, WHEEL_MODE_KEY_FOURTH, p_dll_ptr);
	TrustMasterWheelParser::x_Fun_Read_Dir2(p_ptr, pointersize, *&my_c_p_ReadData, WHEEL_MODE_KEY_FIVE, p_dll_ptr);

}
