// DlgConfigSetting.cpp: 구현 파일
//

#include "pch.h"
#include "Server.h"
#include "DlgConfigSetting.h"
#include "afxdialogex.h"

static int m_bChk_checkBoxState;
static int Val_m_bChk_Ayns_checkBoxState;
//m_bChk_Ayns_checkBoxState

// DlgConfigSetting 대화 상자

IMPLEMENT_DYNAMIC(DlgConfigSetting, CDialogEx)

DlgConfigSetting::DlgConfigSetting(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SERVER_DIALOG, pParent)
{

}

DlgConfigSetting::~DlgConfigSetting()
{
}

void DlgConfigSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_CHK_AUTO_MODE_UP_TO, m_Paths_Setting_URL);
	DDX_Control(pDX, IDC_BUTTON1, m_Paths_Setting_URL_Edit);
	DDX_Control(pDX, IDD_DLG_CONFIG_SETTING_DFS, m_Paths_Setting_URL2);
	DDX_Control(pDX, IDC_CHK_DOWN_UP_TO, m_Server_Sum);
	DDX_Control(pDX, IDC_CHK_AUTO_MODE_UP_TO, m_Auto_mode_Sum);
	DDX_Control(pDX, IDC_CHK_SYN_SERVER_TO, m_bChkSynServerTo);
	DDX_Control(pDX, IDC_CHK_ASYNC_SERVER_TO, m_bChk_Ayns_checkBoxState);
	DDX_Control(pDX, IDC_EDIT_LOG_SETTING_STACK, m_edit_Log_Stack);
	DDX_Control(pDX, IDC_EDIT_CATALOGUE_SETTING_STACK, m_edit_CataLogue_Stack);
	DDX_Control(pDX, IDC_BTN_PATH_PATCHER_EDIT, m_editConfigSettingDFS);
}


BEGIN_MESSAGE_MAP(DlgConfigSetting, CDialogEx)

	ON_EN_CHANGE(IDC_EDIT_NETWORK_URL_STATUS, &DlgConfigSetting::OnEnChangeEditNetworkUrlStatus)
	ON_EN_CHANGE(IDD_DLG_CONFIG_SETTING_DFS, &DlgConfigSetting::OnEnChangeDlgConfigSettingDfs)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgConfigSetting::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DlgConfigSetting::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CHK_DOWN_UP_TO, &DlgConfigSetting::OnBnClickedChkDownUpTo)
	ON_BN_CLICKED(IDC_BUTTON3, &DlgConfigSetting::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_CHK_AUTO_MODE_UP_TO, &DlgConfigSetting::OnBnClickedChkAutoModeUpTo)
	ON_BN_CLICKED(IDC_BUTTON4, &DlgConfigSetting::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_CHK_ASYNC_SERVER_TO, &DlgConfigSetting::OnBnClickedChkAsyncServerTo)
	ON_BN_CLICKED(IDC_CHK_SYN_SERVER_TO, &DlgConfigSetting::OnBnClickedChkSynServerTo)
	ON_BN_CLICKED(IDC_BUTTON5, &DlgConfigSetting::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &DlgConfigSetting::OnBnClickedButton6)
	ON_EN_CHANGE(IDC_EDIT_LOG_SETTING_STACK, &DlgConfigSetting::OnEnChangeEditLogSettingStack)
	ON_EN_CHANGE(IDC_EDIT_CATALOGUE_SETTING_STACK, &DlgConfigSetting::OnEnChangeEditCatalogueSettingStack)
	ON_BN_CLICKED(IDC_BTN_PATH_PATCHER_EDIT, &DlgConfigSetting::OnBnClickedBtnPathPatcherEdit)
END_MESSAGE_MAP()


// DlgConfigSetting 메시지 처리기




void DlgConfigSetting::OnEnChangeEditNetworkUrlStatus()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void DlgConfigSetting::OnEnChangeDlgConfigSettingDfs()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


STACK_T m_beginThread_3(LPVOID x_po) {

	int* po_t = (int*)x_po;

	//Sleep(1000);
	//CString Abandon = CServerDlg::GetMainWindowTitle();
	//ProjectName
//	printf("[%p]서브 쓰레드 System.\n", x_po);
	Sleep(5);


	HWND hWnd = FindWindow(NULL, L"Settings");

	if (hWnd == NULL) {
		printf("hWnd이 존재하지 않습니다.\n", hWnd);
		Sleep(INFINITE);
	}

	HWND hWndButton = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun3"));
	HWND hWndButton2 = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun5"));
	HWND hWndButton3 = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun6"));
	HWND hWndButton4 = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun7"));
	HWND hWndButton5 = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun8"));
	SendMessage(hWndButton, BM_CLICK, 0, 0);

		SendMessage(hWndButton2, BM_CLICK, 0, 0);
		SendMessage(hWndButton3, BM_CLICK, 0, 0);
		SendMessage(hWndButton4, BM_CLICK, 0, 0);
		SendMessage(hWndButton5, BM_CLICK, 0, 0);
	//SendMessage(hWndButton2, BM_CLICK, 0, 0);

	return 0;
}

int* switch_on_off;
//PointerAddress
wchar_t* str_p_Unicode;
char* c_p_ReadData;

WIN32_FIND_DATA  filedata; //파일 데이터 스트럭쳐.
CString  strpath;

void DlgConfigSetting::OnBnClickedButton1()
{
	strpath = "url.ini";
	HANDLE hFile;
	InTerrupt::StruectureCheckSumFirst(*&switch_on_off, str_p_Unicode, c_p_ReadData); //생성된 메모리를 디스터브 하는 함수이다.
	//FIleOpenInPut.GetWindowTextW(strpath);
	FileProcFun::Fun_Find_Dir_size(strpath, &filedata);//strpath의 경로 안에 filedata의 스트럭처 데이터를 집어넣는다. size와 잡다한 파일 날짜 등의 데이터를 가져온다.
	FileProcFun::Fun_IsFileExist(strpath, &hFile);//strpath의 경로 안에 hFile에 hFile 크레이트파일아 데이터를 가져온다.
	//경로와 hFile핸들 정보를 가져온다. 핸들 정보는 &로 말아서 포인터처럼 리턴할떄 재반환 하게 준비한다. 
	FileProcFun::Fun_Read_Dir(*&c_p_ReadData, filedata, &hFile, *&str_p_Unicode);
	//해당 경로의 데이터의 정보를 메모리에 올리고 캐싱한다. 
	InTerrupt::intTrue(*&switch_on_off); //비활성화 스위치 On
	m_Paths_Setting_URL2.SetWindowTextW(str_p_Unicode);

}

void DlgConfigSetting::Set_Url() {
	//m_Paths_Setting_URL.SetWindowTextW(L"Test");
	int* allocated_memory;
	ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)m_beginThread_3, *&allocated_memory); //900 Size //타점3
}

void DlgConfigSetting::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}




void DlgConfigSetting::Auto_WriteNumberToFileOff()
{
	HANDLE hFile = CreateFile(L"AutoStatus.ini", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwBytesWritten;
		char buffer[] = "0";
		BOOL result = WriteFile(hFile, buffer, sizeof(buffer), &dwBytesWritten, NULL);
		if (result)
		{
			std::cout << "WriteNumberToFileOff." << std::endl;
		}
		else
		{
			std::cout << "Failed to write number to file. Error code: " << GetLastError() << std::endl;
		}

		CloseHandle(hFile);
	}
	else
	{
		std::cout << "Failed to create file. Error code: " << GetLastError() << std::endl;
	}
}




void DlgConfigSetting::Auto_WriteNumberToFileon()
{
	HANDLE hFile = CreateFile(L"AutoStatus.ini", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwBytesWritten;
		char buffer[] = "1";
		BOOL result = WriteFile(hFile, buffer, sizeof(buffer), &dwBytesWritten, NULL);
		if (result)
		{
			std::cout << "WriteNumberToFileon." << std::endl;
		}
		else
		{
			std::cout << "Failed to write number to file. Error code: " << GetLastError() << std::endl;
		}

		CloseHandle(hFile);
	}
	else
	{
		std::cout << "Failed to create file. Error code: " << GetLastError() << std::endl;
	}
}



void DlgConfigSetting::WriteNumberToFileOff()
{
	HANDLE hFile = CreateFile(L"DownLoadStatus.ini", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwBytesWritten;
		char buffer[] = "0";
		BOOL result = WriteFile(hFile, buffer, sizeof(buffer), &dwBytesWritten, NULL);
		if (result)
		{
			std::cout << "WriteNumberToFileOff." << std::endl;
		}
		else
		{
			std::cout << "Failed to write number to file. Error code: " << GetLastError() << std::endl;
		}

		CloseHandle(hFile);
	}
	else
	{
		std::cout << "Failed to create file. Error code: " << GetLastError() << std::endl;
	}
}




void DlgConfigSetting::WriteNumberToFileon()
{
	HANDLE hFile = CreateFile(L"DownLoadStatus.ini", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwBytesWritten;
		char buffer[] = "1";
		BOOL result = WriteFile(hFile, buffer, sizeof(buffer), &dwBytesWritten, NULL);
		if (result)
		{
			std::cout << "WriteNumberToFileon." << std::endl;
		}
		else
		{
			std::cout << "Failed to write number to file. Error code: " << GetLastError() << std::endl;
		}

		CloseHandle(hFile);
	}
	else
	{
		std::cout << "Failed to create file. Error code: " << GetLastError() << std::endl;
	}
}


void DlgConfigSetting::OnBnClickedChkDownUpTo()
{
	int checkBoxState;
	checkBoxState = m_Server_Sum.GetCheck();
	printf("체크박스 검사 2[%d]\n", checkBoxState); //on 1 off 0

	if (checkBoxState == 0) { //off
	//	m_editNetworkURLStatus.SetWindowTextW(L"OFF");
		DlgConfigSetting::WriteNumberToFileOff();
	}
	if (checkBoxState == 1) { //on
	//	m_editNetworkURLStatus.SetWindowTextW(L"ON");
		DlgConfigSetting::WriteNumberToFileon();


		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	}
}


void DlgConfigSetting::OnBnClickedButton3()
{
	HANDLE hFile = CreateFile(L"DownLoadStatus.ini", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwFileSize = GetFileSize(hFile, NULL);
		char* buffer = new char[dwFileSize + 1];
		DWORD dwBytesRead;

		if (ReadFile(hFile, buffer, dwFileSize, &dwBytesRead, NULL))
		{
			if (dwBytesRead > 0)
			{
				buffer[dwBytesRead] = '\0';
				int status = atoi(buffer);

				// Set the check state based on the status value
				if (status == 1)
				{
					m_Server_Sum.SetCheck(1);
				}
				else if (status == 0)
				{
					m_Server_Sum.SetCheck(0);
				}
				else
				{
					std::cout << "Invalid status value in the file." << std::endl;
				}
			}
			else
			{
				std::cout << "The file is empty." << std::endl;
			}
		}
		else
		{
			std::cout << "Failed to read the file. Error code: " << GetLastError() << std::endl;
		}

		delete[] buffer;
		CloseHandle(hFile);
	}
	else
	{
		std::cout << "Failed to open the file. Error code: " << GetLastError() << std::endl;
	}
}



void DlgConfigSetting::OnBnClickedChkAutoModeUpTo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다. m_Auto_mode_Sum
	int checkBoxState;
	checkBoxState = m_Auto_mode_Sum.GetCheck();
	printf("체크박스 검사 2[%d]\n", checkBoxState); //on 1 off 0

	if (checkBoxState == 0) { //off
	//	m_editNetworkURLStatus.SetWindowTextW(L"OFF");
		DlgConfigSetting::Auto_WriteNumberToFileOff();
	}
	if (checkBoxState == 1) { //on
	//	m_editNetworkURLStatus.SetWindowTextW(L"ON");
		DlgConfigSetting::Auto_WriteNumberToFileon();


		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	}
}


void DlgConfigSetting::OnBnClickedButton4()
{
	HANDLE hFile = CreateFile(L"AutoStatus.ini", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwFileSize = GetFileSize(hFile, NULL);
		char* buffer = new char[dwFileSize + 1];
		DWORD dwBytesRead;

		if (ReadFile(hFile, buffer, dwFileSize, &dwBytesRead, NULL))
		{
			if (dwBytesRead > 0)
			{
				buffer[dwBytesRead] = '\0';
				int status = atoi(buffer);

				// Set the check state based on the status value
				if (status == 1)
				{
					m_Auto_mode_Sum.SetCheck(1);
				}
				else if (status == 0)
				{
					m_Auto_mode_Sum.SetCheck(0);
				}
				else
				{
					std::cout << "Invalid status value in the file." << std::endl;
				}
			}
			else
			{
				std::cout << "The file is empty." << std::endl;
			}
		}
		else
		{
			std::cout << "Failed to read the file. Error code: " << GetLastError() << std::endl;
		}

		delete[] buffer;
		CloseHandle(hFile);
	}
	else
	{
		std::cout << "Failed to open the file. Error code: " << GetLastError() << std::endl;
	}
}






void DlgConfigSetting::Auto_WriteNumberToFileOff_Syn()
{
	HANDLE hFile = CreateFile(L"Auto_Server_Status.ini", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwBytesWritten;
		char buffer[] = "0";
		BOOL result = WriteFile(hFile, buffer, sizeof(buffer), &dwBytesWritten, NULL);
		if (result)
		{
			std::cout << "WriteNumberToFileOff." << std::endl;
		}
		else
		{
			std::cout << "Failed to write number to file. Error code: " << GetLastError() << std::endl;
		}

		CloseHandle(hFile);
	}
	else
	{
		std::cout << "Failed to create file. Error code: " << GetLastError() << std::endl;
	}
}



void DlgConfigSetting::Auto_WriteNumberToFileon_Syn()
{
	HANDLE hFile = CreateFile(L"Auto_Server_Status.ini", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwBytesWritten;
		char buffer[] = "1";
		BOOL result = WriteFile(hFile, buffer, sizeof(buffer), &dwBytesWritten, NULL);
		if (result)
		{
			std::cout << "WriteNumberToFileon." << std::endl;
		}
		else
		{
			std::cout << "Failed to write number to file. Error code: " << GetLastError() << std::endl;
		}

		CloseHandle(hFile);
	}
	else
	{
		std::cout << "Failed to create file. Error code: " << GetLastError() << std::endl;
	}
}




void DlgConfigSetting::Auto_WriteNumberToFileOff_Syn_A()
{
	HANDLE hFile = CreateFile(L"Auto_Server_Status.ini", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwBytesWritten;
		char buffer[] = "0";
		BOOL result = WriteFile(hFile, buffer, sizeof(buffer), &dwBytesWritten, NULL);
		if (result)
		{
			std::cout << "WriteNumberToFileOff." << std::endl;
		}
		else
		{
			std::cout << "Failed to write number to file. Error code: " << GetLastError() << std::endl;
		}

		CloseHandle(hFile);
	}
	else
	{
		std::cout << "Failed to create file. Error code: " << GetLastError() << std::endl;
	}
}



void DlgConfigSetting::Auto_WriteNumberToFileon_Syn_A()
{
	HANDLE hFile = CreateFile(L"Auto_Server_Status.ini", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwBytesWritten;
		char buffer[] = "2";
		BOOL result = WriteFile(hFile, buffer, sizeof(buffer), &dwBytesWritten, NULL);
		if (result)
		{
			std::cout << "WriteNumberToFileon." << std::endl;
		}
		else
		{
			std::cout << "Failed to write number to file. Error code: " << GetLastError() << std::endl;
		}

		CloseHandle(hFile);
	}
	else
	{
		std::cout << "Failed to create file. Error code: " << GetLastError() << std::endl;
	}
}





void DlgConfigSetting::OnBnClickedChkSynServerTo() //동기서버
{
	if (Val_m_bChk_Ayns_checkBoxState == 1) {
		m_edit_Log_Stack.SetWindowTextW(L"비동기 서버 체크박스를 풀고 동기 서버 체크박스를 클릭 해 주세요.");
		m_bChkSynServerTo.SetCheck(0);
		return;
	}
	m_bChk_checkBoxState = m_bChkSynServerTo.GetCheck();
	printf("체크박스 검사 2[%d]\n", m_bChk_checkBoxState); //on 1 off 0

	if (m_bChk_checkBoxState == 0) { //off
	//   m_editNetworkURLStatus.SetWindowTextW(L"OFF");
		DlgConfigSetting::Auto_WriteNumberToFileOff_Syn();
	}
	if (m_bChk_checkBoxState == 1) { //on
	//   m_editNetworkURLStatus.SetWindowTextW(L"ON");
		DlgConfigSetting::Auto_WriteNumberToFileon_Syn();


		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void DlgConfigSetting::OnBnClickedChkAsyncServerTo() //비동기 서버
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//m_bChk_Ayns_checkBoxState
	if (m_bChk_checkBoxState == 1) {
		m_edit_Log_Stack.SetWindowTextW(L"동기 서버 체크박스를 풀고 동기 서버 체크박스를 클릭 해 주세요.");
		m_bChk_Ayns_checkBoxState.SetCheck(0);
		return;
	}
	Val_m_bChk_Ayns_checkBoxState = m_bChk_Ayns_checkBoxState.GetCheck();
	printf("체크박스 검사 2[%d]\n", Val_m_bChk_Ayns_checkBoxState); //on 1 off 0

	if (Val_m_bChk_Ayns_checkBoxState == 0) { //off
	//   m_editNetworkURLStatus.SetWindowTextW(L"OFF");
		DlgConfigSetting::Auto_WriteNumberToFileOff_Syn_A();
	}
	if (Val_m_bChk_Ayns_checkBoxState == 1) { //on
	//   m_editNetworkURLStatus.SetWindowTextW(L"ON");
		DlgConfigSetting::Auto_WriteNumberToFileon_Syn_A();


		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	}
}




void DlgConfigSetting::OnBnClickedButton5()
{
	HANDLE hFile = CreateFile(L"Auto_Server_Status.ini", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwFileSize = GetFileSize(hFile, NULL);
		char* buffer = new char[dwFileSize + 1];
		DWORD dwBytesRead;

		if (ReadFile(hFile, buffer, dwFileSize, &dwBytesRead, NULL))
		{
			if (dwBytesRead > 0)
			{
				buffer[dwBytesRead] = '\0';
				int status = atoi(buffer);

				// Set the check state based on the status value
				if (status == 1)
				{
					m_bChkSynServerTo.SetCheck(1);
				}
				else if (status == 0)
				{
					m_bChkSynServerTo.SetCheck(0);
					m_bChk_Ayns_checkBoxState.SetCheck(0);
				}
				else if (status == 2)
				{
					m_bChk_Ayns_checkBoxState.SetCheck(1);
				}
				else
				{
					std::cout << "Invalid status value in the file." << std::endl;
				}
			}
			else
			{
				std::cout << "The file is empty." << std::endl;
			}
		}
		else
		{
			std::cout << "Failed to read the file. Error code: " << GetLastError() << std::endl;
		}

		delete[] buffer;
		CloseHandle(hFile);
	}
	else
	{
		std::cout << "Failed to open the file. Error code: " << GetLastError() << std::endl;
	}
}


void DlgConfigSetting::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Val_m_bChk_Ayns_checkBoxState = m_bChk_Ayns_checkBoxState.GetCheck();
	m_bChk_checkBoxState = m_bChkSynServerTo.GetCheck();


}


void DlgConfigSetting::OnEnChangeEditLogSettingStack()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void DlgConfigSetting::OnEnChangeEditCatalogueSettingStack()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void DlgConfigSetting::OnBnClickedBtnPathPatcherEdit()
{
	CString str_copy;
	CString strpath="url.ini";
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_Paths_Setting_URL2.GetWindowTextW(str_copy);
	m_edit_CataLogue_Stack.SetWindowTextW(L"패치 웹 서버의 URL을 수정 합니다.");
	FileProcFun::Fun_Save_Dir(strpath, str_copy);

}
