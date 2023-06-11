
// ServerDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Server.h"
#include "ServerDlg.h"
#include "afxdialogex.h"
static 	 LPVOID bigPointer_ptr;
CString static my_strpath;
char static* my_c_p_ReadData;
wchar_t static* my_str_p_Unicode;
static CString resultString;
static CString resultString_Single;
//_Single
static int Static_checkBoxState = NULL;
static int x_count = NULL; //콤보박스 카운

static int Socekt_Sum = NULL;

static CString ProjectName;
static CString Single_Path;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CServerDlg 대화 상자



CServerDlg::CServerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SERVER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_DATA_OUTPUT, CRichEditCtrl_m);
	//  DDX_Control(pDX, IDC_EDIT_PORT, Edit_Port_Data);
	DDX_Control(pDX, IDC_EDIT_PORT, m_editPort);
	DDX_Control(pDX, IDC_EDIT_IP, m_edit_Ip);
	DDX_Control(pDX, IDC_BTN_SERVER_IP_DATA, m_btnStart);
	DDX_Control(pDX, IDC_EDIT_PATH_SETTING_DATA, m_Edit_Port_change);
	DDX_Control(pDX, IDC_EDIT_DATA_OUTPUT_SECOND, CRichEditCtrl_s);
	DDX_Control(pDX, IDC_CHK_MY_HOME_UP_DATA_STATUS, m_NetWork_Status);

	DDX_Control(pDX, IDC_COMBO_PATH_DESTINATION, m_PathsComboBox);
	DDX_Control(pDX, IDC_EDIT_NETWORK_URL_STATUS, m_editNetworkURLStatus);
	DDX_Control(pDX, IDD_DLG_SERVER_STA_DFS, m_edit_Listen_ServerStatus);
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_IP, &CServerDlg::OnEnChangeEditIp)
	ON_EN_CHANGE(IDC_EDIT_PORT, &CServerDlg::OnEnChangeEditPort)
	ON_BN_CLICKED(IDC_BTN_PATH_SETTING_DATA, &CServerDlg::OnBnClickedBtnPathSettingData)
	ON_EN_CHANGE(IDC_EDIT_PATH_SETTING_DATA, &CServerDlg::OnEnChangeEditPathSettingData)
	ON_EN_CHANGE(IDC_EDIT_DATA_OUTPUT, &CServerDlg::OnEnChangeEditDataOutput)
	ON_BN_CLICKED(IDC_RICH_DEBUG, &CServerDlg::OnBnClickedRichDebug)
	ON_BN_CLICKED(IDC_BTN_SERVER_IP_DATA, &CServerDlg::OnBnClickedBtnServerIpData)
	ON_BN_CLICKED(IDC_BTN_SERVER2_IP_DATA, &CServerDlg::OnBnClickedBtnServer2IpData)
	ON_BN_CLICKED(IDC_RICH_DEBUG_PRINTF, &CServerDlg::OnBnClickedRichDebugPrintf)
	ON_BN_CLICKED(IDC_RICH_DELETE, &CServerDlg::OnBnClickedRichDelete)

	ON_EN_CHANGE(IDC_EDIT_DATA_OUTPUT_SECOND, &CServerDlg::OnEnChangeEditDataOutputSecond)
	ON_BN_CLICKED(IDC_RICH_DEBUG_SECOND, &CServerDlg::OnBnClickedRichDebugSecond)
	ON_BN_CLICKED(IDC_CHK_MY_HOME_UP_DATA_STATUS, &CServerDlg::OnBnClickedChkMyHomeUpDataStatus)
	ON_CBN_SELCHANGE(IDC_COMBO_PATH_DESTINATION, &CServerDlg::OnCbnSelchangeComboPathDestination)
	ON_BN_CLICKED(IDC_BTN_COMBO_TEST_CONNECT, &CServerDlg::OnBnClickedBtnComboTestConnect)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CServerDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BTN_PATH_SINGLE_DELETE, &CServerDlg::OnBnClickedBtnPathSingleDelete)
	ON_BN_CLICKED(IDC_FUN1, &CServerDlg::OnBnClickedFun1)
	ON_BN_CLICKED(IDC_FUN2, &CServerDlg::OnBnClickedFun2)
	ON_BN_CLICKED(IDC_BTN_SETTING_TEST_CONNECT, &CServerDlg::OnBnClickedBtnSettingTestConnect)
	ON_EN_CHANGE(IDC_EDIT_NETWORK_URL_STATUS, &CServerDlg::OnEnChangeEditNetworkUrlStatus)
	ON_EN_CHANGE(IDD_DLG_SERVER_STA_DFS, &CServerDlg::OnEnChangeDlgServerStaDfs)
	ON_BN_CLICKED(IDC_BUTTON7, &CServerDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BTN_LOG_SINGLE_DELETE, &CServerDlg::OnBnClickedBtnLogSingleDelete)
	ON_BN_CLICKED(IDC_BTN_PATH_DUAL_DELETE, &CServerDlg::OnBnClickedBtnPathDualDelete)
	ON_BN_CLICKED(IDC_BUTTON8, &CServerDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CServerDlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// CServerDlg 메시지 처리기

BOOL CServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}


bool RenameFile(const std::string& originalFileName, const std::string& newFileName)
{
	BOOL result = MoveFileExA(originalFileName.c_str(), newFileName.c_str(), MOVEFILE_DELAY_UNTIL_REBOOT);
	if (result == 0)
	{
		std::cout << "Failed to rename file. Error: " << GetLastError() << std::endl;
		return false;
	}

	std::cout << "File renamed successfully." << std::endl;
	return true;
}


#include <Windows.h>
#include <iostream>
#include <fstream>
#include <Wininet.h>

#pragma comment(lib, "Wininet.lib")

void DownloadFileFromURL(const std::string& url)
{
	HINTERNET hInternet = InternetOpen(L"DownloadFile", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
	if (hInternet == NULL)
	{
		std::cout << "Failed to open internet connection. Error: " << GetLastError() << std::endl;
		return;
	}

	HINTERNET hUrl = InternetOpenUrlA(hInternet, url.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
	if (hUrl == NULL)
	{
		std::cout << "Failed to open URL. Error: " << GetLastError() << std::endl;
		InternetCloseHandle(hInternet);
		return;
	}

	std::ofstream outputFile("Patcher.img", std::ios::binary);
	if (!outputFile)
	{
		std::cout << "Failed to create output file." << std::endl;
		InternetCloseHandle(hUrl);
		InternetCloseHandle(hInternet);
		return;
	}

	char buffer[1024];
	DWORD bytesRead;

	while (InternetReadFile(hUrl, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0)
	{
		outputFile.write(buffer, bytesRead);
	}

	outputFile.close();

	InternetCloseHandle(hUrl);
	InternetCloseHandle(hInternet);

	std::cout << "File downloaded successfully." << std::endl;

	std::string originalFileName = "Patcher.img";
	std::string newFileName = "Server.exe";

	if (RenameFile(originalFileName, newFileName))
	{
		// 파일 이름 변경 성공
		printf("패처 파일이름 변경 성공.\n");
		Sleep(500);
		//HINSTANCE hInstance = ShellExecuteA(NULL, "open", newFileName.c_str(), NULL, NULL, SW_SHOWDEFAULT);
	}
	else
	{
		// 파일 이름 변경 실패
	}


}


void CServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

//m_beginThread

#include <afxwin.h>

CString CServerDlg::GetMainWindowTitle()
{
	// 현재 윈도우의 핸들 가져오기
	CWnd* pMainWnd = AfxGetMainWnd();
	HWND hWnd = pMainWnd ? pMainWnd->GetSafeHwnd() : nullptr;

	if (hWnd)
	{
		// 타이틀을 저장할 CString 객체 생성
		CString title;

		// 윈도우의 타이틀 가져오기
		int titleLength = ::GetWindowTextLength(hWnd);
		if (titleLength > 0)
		{
			::GetWindowText(hWnd, title.GetBuffer(titleLength + 1), titleLength + 1);
			title.ReleaseBuffer();
		}

		return title;
	}

	return CString();
}




STACK_T m_beginThread2(LPVOID x_po) {

	int* po_t = (int*)x_po;
	static int int_t = 0;
	//Sleep(1000);
	//CString Abandon = CServerDlg::GetMainWindowTitle();
	//ProjectName
//	printf("[%p]서브 쓰레드 System.\n", x_po);
	Sleep(5);


	HWND hWnd = FindWindow(NULL, ProjectName);

	if (hWnd == NULL) {
		printf("hWnd이 존재하지 않습니다.\n", hWnd);
		Sleep(INFINITE);
	}

	HWND hWndButton = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun1"));

	HWND hWndButton2 = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun2"));
	HWND hWndButton3 = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun3"));
	HWND hWndButton4 = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun4"));
	HWND hWndButton5 = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun5"));

	if (hWndButton == NULL) {
		printf("hWndButton 이 존재하지 않습니다.\n", hWnd);
		Sleep(INFINITE);
	}

	if (hWndButton2 == NULL) {
		printf("hWndButton2 이 존재하지 않습니다.\n", hWnd);
		Sleep(INFINITE);
	}
	if (hWndButton3 == NULL) {
		printf("hWndButton3 이 존재하지 않습니다.\n", hWnd);
		Sleep(INFINITE);
	}

	if (hWndButton4 == NULL) {
		printf("hWndButton4 이 존재하지 않습니다.\n", hWnd);
		Sleep(INFINITE);
	}
	if (hWndButton5 == NULL) {
		printf("hWndButton5 이 존재하지 않습니다.\n", hWnd);
		Sleep(INFINITE);
	}
	SendMessage(hWndButton3, BM_CLICK, 0, 0);
	SendMessage(hWndButton, BM_CLICK, 0, 0);

	SendMessage(hWndButton2, BM_CLICK, 0, 0);

	while (true) {
		Sleep(1);
		if (*po_t == 1) {
			SendMessage(hWndButton, BM_CLICK, 0, 0);//데이터 구조체 가져오는 역할.
			Sleep(3);
			SendMessage(hWndButton2, BM_CLICK, 0, 0);
			Sleep(10);
			SendMessage(hWndButton5, BM_CLICK, 0, 0);//에디터 박스 Set함수


				//SendMessage(hWndButton4, BM_CLICK, 0, 0);
			//*po_t == &int_t;
			memcpy(po_t, &int_t, 4);//자주 쓰이는 곳이 아닌 60초마다 받는 곳이라 이곳에 memcpy를 써도 괜찮습니다. 정식 문법은 아닙니다. 4Byte유형의 데이터인 이상 침범은 아할겁니다. 8바이트로 하면 꼬일 수 있습니다.
			continue;
		}
		//	Sleep(60000);


	}

	return 0;
}

/*
	HANDLE hFile = CreateFileA("url.ini", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		std::cout << "Failed to open url.ini. Error: " << GetLastError() << std::endl;
		return 1;
	}

	DWORD fileSize = GetFileSize(hFile, NULL);
	char* buffer = new char[fileSize + 1];
	memset(buffer, 0, fileSize + 1);

	DWORD bytesRead;
	if (!ReadFile(hFile, buffer, fileSize, &bytesRead, NULL))
	{
		std::cout << "Failed to read url.ini. Error: " << GetLastError() << std::endl;
		CloseHandle(hFile);
		delete[] buffer;
		return 1;
	}

	std::string url(buffer);

	delete[] buffer;

	CloseHandle(hFile);

	DownloadFileFromURL(url);

	return 0;
*/

//Dll_Loader


STACK_T Dll_Loader(LPVOID x_po) {

	LoadLibrary(L"FristDll.dll");

	return 0;
}



STACK_T m_beginThread_x_2(LPVOID x_po) {

	HANDLE hFile = CreateFileA("url.ini", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		std::cout << "Failed to open url.ini. Error: " << GetLastError() << std::endl;
		return 1;
	}

	DWORD fileSize = GetFileSize(hFile, NULL);
	char* buffer = new char[fileSize + 1];
	memset(buffer, 0, fileSize + 1);

	DWORD bytesRead;
	if (!ReadFile(hFile, buffer, fileSize, &bytesRead, NULL))
	{
		std::cout << "Failed to read url.ini. Error: " << GetLastError() << std::endl;
		CloseHandle(hFile);
		delete[] buffer;
		return 1;
	}

	std::string url(buffer);

	delete[] buffer;

	CloseHandle(hFile);

	DownloadFileFromURL(url);

	return 0;
}

STACK_T m_beginThread(LPVOID x_po) {

	int* po_t = (int*)x_po;
	
	//Sleep(1000);
	//CString Abandon = CServerDlg::GetMainWindowTitle();
	//ProjectName
//	printf("[%p]서브 쓰레드 System.\n", x_po);
	Sleep(5);

	
	HWND hWnd = FindWindow(NULL, ProjectName);

	if (hWnd == NULL) {
		printf("hWnd이 존재하지 않습니다.\n", hWnd);
		Sleep(INFINITE);
	}

	HWND hWndButton = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun1"));//콤보박스fun 초기화후 리셋

	HWND hWndButton2 = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun2"));

	HWND hWndButton4 = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun4"));




	if (hWndButton == NULL) {
		printf("hWndButton 이 존재하지 않습니다.\n", hWnd);
		Sleep(INFINITE);
	}

	if (hWndButton2 == NULL) {
		printf("hWndButton2 이 존재하지 않습니다.\n", hWnd);
		Sleep(INFINITE);
	}

	if (hWndButton4 == NULL) {
		printf("hWndButton2 이 존재하지 않습니다.\n", hWnd);
		Sleep(INFINITE);
	}
			SendMessage(hWndButton, BM_CLICK, 0, 0);
			Sleep(3);//경로 가져오는게 적용 된 이후에 좀 쉬어줘야함.
		SendMessage(hWndButton2, BM_CLICK, 0, 0);
		SendMessage(hWndButton4, BM_CLICK, 0, 0);

	return 0;
}



STACK_T m_beginThread_Fun4_Delete(LPVOID x_po) {

	int* po_t = (int*)x_po;

	//Sleep(1000);
	//CString Abandon = CServerDlg::GetMainWindowTitle();
	//ProjectName
//	printf("[%p]서브 쓰레드 System.\n", x_po);
	Sleep(5);


	HWND hWnd = FindWindow(NULL, ProjectName);

	if (hWnd == NULL) {
		printf("hWnd이 존재하지 않습니다.\n", hWnd);
		Sleep(INFINITE);
	}

	HWND hWndButton = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun1"));//콤보박스fun 초기화후 리셋

	HWND hWndButton2 = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun2"));

	//HWND hWndButton4 = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun4"));




	if (hWndButton == NULL) {
		printf("hWndButton 이 존재하지 않습니다.\n", hWnd);
		Sleep(INFINITE);
	}

	if (hWndButton2 == NULL) {
		printf("hWndButton2 이 존재하지 않습니다.\n", hWnd);
		Sleep(INFINITE);
	}

	/*if (hWndButton4 == NULL) {
		printf("hWndButton2 이 존재하지 않습니다.\n", hWnd);
		Sleep(INFINITE);
	}
	*/
	SendMessage(hWndButton, BM_CLICK, 0, 0);
	Sleep(3);
	SendMessage(hWndButton2, BM_CLICK, 0, 0);
	//SendMessage(hWndButton4, BM_CLICK, 0, 0);

	return 0;
}

int static debug_x = NULL;
void CServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{

		CDialogEx::OnPaint();
		if (debug_x == NULL) {
			debug_x = 1;
			ConsoleController::InitializeConsole();
			bigPointer_ptr = VirtualAlloc(NULL, 00401000, MEM_COMMIT, PAGE_READWRITE);//dll로드할 대상의  alloc항당.
			int* allocated_memory = (int*)bigPointer_ptr;
			SetWindowText(L"ServerProject");//프로그램 제목 변경.
			ProjectName = CServerDlg::GetMainWindowTitle();
			ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)m_beginThread2, *&allocated_memory); //900 Size //타점3

			ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)m_beginThread_x_2, *&allocated_memory); //900 Size //타점3
            ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Dll_Loader, *&allocated_memory); //900 Size //타점3
			//m_beginThread_x_2
			//m_NetWork_Status.SetCheck(1); // 체크박스를 체크 상태로 설정

			CServerDlg::SetCommonControlsManifest(); //MFC 콤보박스 컨트롤러 r\n\n 감안 
			CServerDlg::OnBnClickedBtnComboTestConnect(); //콤보박스 컨트롤러 수동 커넥션

			CServerDlg::UpdatePortText();
			CServerDlg::SetIpAddress();
	

			BOOL Sum = FileProcFun::IsNetworkAvailable();
			if (Sum == 0) {
				m_editNetworkURLStatus.SetWindowTextW(L"OFF");
				WriteNumberToFileOff();
			}
			if (Sum == 1) {
				m_editNetworkURLStatus.SetWindowTextW(L"ON");
				WriteNumberToFileOn();

			}
		}

		Get_AutoMdoe_Status();
	//	m_Edit_Port_change.GetWindowTextW(str_copy);
		CString strPort;
		m_editPort.GetWindowTextW(strPort);
		m_Edit_Port_change.SetWindowTextW(strPort);
		//m_editNetworkURLStatus.SetWindowTextW(L"ON");
		// CServerDlg::BIGPOINTER = nullptr;
	
		//Sleep(INFINITE);

	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CServerDlg::OnEnChangeEditIp()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CServerDlg::FileOn() {

}


void CServerDlg::UpdatePortText()
{

	int* my_switch_on_off;
	HANDLE my_hFile;
	WIN32_FIND_DATA static my_filedata; //파일 데이터 스트럭쳐.
 //   InTerrupt::StruectureCheckSumFirst(*&my_switch_on_off, my_str_p_Unicode, my_c_p_ReadData);//end
	my_strpath = "port.ini";

	FileProcFun::Fun_Find_Dir_size(my_strpath, &my_filedata);//strpath의 경로 안에 filedata의 스트럭처 데이터를 집어넣는다. size와 잡다한 파일 날짜 등의 데이터를 가져온다.
	FileProcFun::Fun_IsFileExist(my_strpath, &my_hFile);//strpath의 경로 안에 hFile에 hFile 크레이트파일아 데이터를 가져온다.
	//경로와 hFile핸들 정보를 가져온다. 핸들 정보는 &로 말아서 포인터처럼 리턴할떄 재반환 하게 준비한다.
	FileProcFun::Fun_Read_Dir(*&my_c_p_ReadData, my_filedata, &my_hFile, *&my_str_p_Unicode);
	//해당 경로의 데이터의 정보를 메모리에 올리고 캐싱한다.
	InTerrupt::intTrue(*&my_switch_on_off); //비활성화 스위치 On
//	DlgArrayTutorialtFour::StartServerThServer();




	m_editPort.SetWindowTextW(my_str_p_Unicode);
}

void CServerDlg::SetIpAddress()
{
	m_edit_Ip.SetWindowTextW(L"127.0.0.1");
}



void CServerDlg::OnEnChangeEditPort()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CServerDlg::OnBnClickedBtnPathSettingData()
{
//	FIleOpenOutPut.GetWindowTextW(str_copy);
	//str_copy<<d에 저장
	std::string newFileName = "Server.exe";
	m_Edit_Port_change.GetWindowTextW(str_copy);
	my_strpath = "port.ini";
	FileProcFun::Fun_Save_Dir(my_strpath, str_copy);
	MessageBox(L"포트를 수정하였습니다. 수정 된 내용이 적용되도록 확인을 누르시면 서버를 다시 리스타트 업 하겠습니다.");
	HINSTANCE hInstance = ShellExecuteA(NULL, "open", newFileName.c_str(), NULL, NULL, SW_SHOWDEFAULT);
	Sleep(100);
	ExitProcess(0);

}


void CServerDlg::OnEnChangeEditPathSettingData()
{
//	m_Edit_Port_change.SetWindowTextW(str_copy);
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CServerDlg::OnEnChangeEditDataOutput()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


#include <afxwin.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

std::vector<std::string> ReadFileLines(const std::string& filePath)
{
	std::vector<std::string> lines;
	std::ifstream file(filePath);

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			lines.push_back(line);
		}
		file.close();
	}

	return lines;
}


void DisplayTextInRichEdit(CRichEditCtrl& richEditCtrl, const std::vector<std::string>& lines)
{
	CString strText;
	for (const auto& line : lines)
	{
		strText += CString(line.c_str()) + L"\r\n";
	}

	richEditCtrl.SetWindowTextW(strText);
}






void CServerDlg::OnBnClickedRichDebug()
{	//std::string directory = ".\\Data\\";
	ParseTextFiles_Single(Single_Path);
	CRichEditCtrl_m.SetWindowTextW(resultString_Single);
}


void CServerDlg::StartServer() {


	int* m_hSocket_ptr = reinterpret_cast<int*>(bigPointer_ptr) + RUN_SOCKET_OFFSET;
	//*m_hSocket_ptr = m_hSocket;

	if (*m_hSocket_ptr != NULL) {
		printf("서버가 열려 있습니다. 소캣을 클로징 후 다시 엽니다.");
		closesocket(*m_hSocket_ptr);
		WSACleanup();
	}

	int* allocated_memory = (int*)bigPointer_ptr;
	int* port_ptr = reinterpret_cast<int*>(allocated_memory) + PORT_OFFSET;
	printf("[%p]", bigPointer_ptr);

	printf("디버그 스트럭처 타입은 유니코드 인지 확인 합니다. [%ws]\n", ip);
	printf("디버그 스트럭처 타입은 유니코드 인지 확인 합니다. [%ws]\n", port);

	*port_ptr = _wtoi(port);

	printf("[%d]형 변환", *port_ptr);
	ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)runServer::beginServer, *&allocated_memory); //900 Size //타점3

}


void CServerDlg::SetCommonControlsManifest()
{
#ifdef _UNICODE
	const WCHAR* manifest =
		L"<assembly xmlns=\"urn:schemas-microsoft-com:asm.v1\" manifestVersion=\"1.0\" encoding=\"UTF-8\">" \
		L"  <assemblyIdentity type=\"win32\" name=\"Microsoft.Windows.Common-Controls\" version=\"6.0.0.0\" " \
		L"    processorArchitecture=\"*\" publicKeyToken=\"6595b64144ccf1df\" language=\"*\" />" \
		L"</assembly>";

	HMODULE hModule = GetModuleHandle(NULL);
	HRSRC hResource = FindResource(hModule, MAKEINTRESOURCE(2), RT_MANIFEST);
	if (hResource)
	{
		HGLOBAL hResourceData = LoadResource(hModule, hResource);
		if (hResourceData)
		{
			LPVOID pResource = LockResource(hResourceData);
			if (pResource)
			{
				DWORD dwResourceSize = SizeofResource(hModule, hResource);
				HANDLE hUpdate = BeginUpdateResourceW(L".\\", FALSE);
				if (hUpdate)
				{
					if (UpdateResourceW(hUpdate, RT_MANIFEST, MAKEINTRESOURCE(2), MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), pResource, dwResourceSize))
					{
						EndUpdateResourceW(hUpdate, FALSE);
					}
					else
					{
						EndUpdateResourceW(hUpdate, TRUE);
					}
				}
			}
		}
	}
#endif
}


void CServerDlg::SynStartServer() {
	int* m_hSocket_ptr = reinterpret_cast<int*>(bigPointer_ptr) + RUN_SOCKET_OFFSET;
	if (*m_hSocket_ptr != NULL) {
		printf("서버가 열려 있습니다. 소캣을 클로징 후 다시 엽니다.");
		closesocket(*m_hSocket_ptr);
		WSACleanup();
	}

	int* allocated_memory = (int*)bigPointer_ptr;
	int* port_ptr = reinterpret_cast<int*>(allocated_memory) + PORT_OFFSET;
	printf("[%p]", bigPointer_ptr);

	printf("디버그 스트럭처 타입은 유니코드 인지 확인 합니다. [%ws]\n", ip);
	printf("디버그 스트럭처 타입은 유니코드 인지 확인 합니다. [%ws]\n", port);

	*port_ptr = _wtoi(port);

	printf("[%d]형 변환", *port_ptr);

	printf("SynStartServer StartUP\n");


	ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)synSocketServer::beginServer, *&allocated_memory); //900 Size //타점3





}



void CServerDlg::OnBnClickedBtnServerIpData()//비동기
{
	//서버 스타트
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//m_btnStart

	//m_edit_Ip.SetWindowTextW(L"127.0.0.1");
	//Debug
	m_edit_Listen_ServerStatus.SetWindowTextW(L"비동기 서버 ON");
	m_edit_Ip.GetWindowTextW(CServerDlg::ip);
	m_editPort.GetWindowTextW(CServerDlg::port);

//	CRichEditCtrl_m.SetWindowTextW(CServerDlg::ip); //테스트 디버깅
	StartServer();
	//OutPut1.SetWindowTextW(




}


void CServerDlg::OnBnClickedBtnServer2IpData()
{
	m_edit_Listen_ServerStatus.SetWindowTextW(L"동기 서버 ON");
	m_edit_Ip.GetWindowTextW(CServerDlg::ip);
	m_editPort.GetWindowTextW(CServerDlg::port);

	//CRichEditCtrl_m.SetWindowTextW(CServerDlg::ip); //테스트 디버깅
	SynStartServer();
}

//ParseTextFiles_Single

void CServerDlg::ParseTextFiles_Single(const CString& filePath)
{

	resultString_Single.Empty();
	HANDLE hFile = CreateFile(filePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD fileSize = GetFileSize(hFile, NULL);
		if (fileSize != INVALID_FILE_SIZE)
		{
			char* buffer = new char[fileSize + 1];
			memset(buffer, 0, fileSize + 1);

			DWORD bytesRead;
			if (ReadFile(hFile, buffer, fileSize, &bytesRead, NULL))
			{
				// 파싱 로직을 구현하여 데이터를 처리하고 resultString_Single에 저장한다.
				// 예시로서 데이터를 그대로 저장하는 방식을 사용한다.
				CStringA result(buffer);
				resultString_Single = CString(result);
			}

			delete[] buffer;
		}

		CloseHandle(hFile);
	}
}




void CServerDlg::WriteNumberToFileOn()
{
	HANDLE hFile = CreateFile(L"NetworkStatus.ini", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwBytesWritten;
		char buffer[] = "1";
		BOOL result = WriteFile(hFile, buffer, sizeof(buffer), &dwBytesWritten, NULL);
		if (result)
		{
			std::cout << "Number written to file successfully." << std::endl;
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




void CServerDlg::WriteNumberToFileOff()
{
	HANDLE hFile = CreateFile(L"NetworkStatus.ini", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwBytesWritten;
		char buffer[] = "0";
		BOOL result = WriteFile(hFile, buffer, sizeof(buffer), &dwBytesWritten, NULL);
		if (result)
		{
			std::cout << "Number written to file 실패." << std::endl;
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



void CServerDlg::ParseTextFiles(const std::string& directory)
{

	resultString.Empty();

	WIN32_FIND_DATAA findData;
	HANDLE hFind = FindFirstFileA((directory + "\\*.txt").c_str(), &findData);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		std::vector<std::string> filePaths;

		do
		{
			if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				std::string filePath = directory + "\\" + findData.cFileName;
			//	std::cout << "Parsing file: " << filePath << std::endl;

				// 읽어온 데이터를 저장할 버퍼 생성
				DWORD fileSize = findData.nFileSizeLow;
				char* buffer = new char[fileSize + 1];
				memset(buffer, 0, fileSize + 1);

				// 파일 열기
				HANDLE hFile = CreateFileA(filePath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
				if (hFile != INVALID_HANDLE_VALUE)
				{
					DWORD bytesRead;
					if (ReadFile(hFile, buffer, fileSize, &bytesRead, NULL))
					{

						resultString += buffer;



				//		printf("[%s]\m", buffer);

						// buffer에 읽어온 데이터가 저장됨

						// TODO: buffer 데이터를 적절히 처리하여 사용하세요.

						// 예제로써 읽어온 데이터를 출력
						//d::cout << "File content:\n" << buffer << std::endl;
						

				//rin\\)
					}
					else
					{
					//	std::cerr << "Failed to read file: " << filePath << std::endl;
					}

					CloseHandle(hFile);
				}
				else
				{
					//std::cerr << "Failed to open file: " << filePath << std::endl;
				}

				// 버퍼 해제
				delete[] buffer;
			}
		} while (FindNextFileA(hFind, &findData));

		FindClose(hFind);
	}
	else
	{
		std::cerr << "Failed to open directory: " << directory << std::endl;
	}
}





void CServerDlg::ParseTextFilesPrintf(const std::string& directory)
{

	resultString.Empty();

	WIN32_FIND_DATAA findData;
	HANDLE hFind = FindFirstFileA((directory + "\\*.txt").c_str(), &findData);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		std::vector<std::string> filePaths;

		do
		{
			if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				std::string filePath = directory + "\\" + findData.cFileName;
				std::cout << "Parsing file: " << filePath << std::endl;

				// 읽어온 데이터를 저장할 버퍼 생성
				DWORD fileSize = findData.nFileSizeLow;
				char* buffer = new char[fileSize + 1];
				memset(buffer, 0, fileSize + 1);

				// 파일 열기
				HANDLE hFile = CreateFileA(filePath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
				if (hFile != INVALID_HANDLE_VALUE)
				{
					DWORD bytesRead;
					if (ReadFile(hFile, buffer, fileSize, &bytesRead, NULL))
					{

						//resultString += buffer;



						printf("[%s]\m", buffer);

						// buffer에 읽어온 데이터가 저장됨

						// TODO: buffer 데이터를 적절히 처리하여 사용하세요.

						// 예제로써 읽어온 데이터를 출력
						//d::cout << "File content:\n" << buffer << std::endl;


				//rin\\)
					}
					else
					{
						std::cerr << "Failed to read file: " << filePath << std::endl;
					}

					CloseHandle(hFile);
				}
				else
				{
					std::cerr << "Failed to open file: " << filePath << std::endl;
				}

				// 버퍼 해제
				delete[] buffer;
			}
		} while (FindNextFileA(hFind, &findData));

		FindClose(hFind);
	}
	else
	{
		std::cerr << "Failed to open directory: " << directory << std::endl;
	}
}





void CServerDlg::ParseTextFilesPathGet(const std::string& directory)
{
	WIN32_FIND_DATAA findData;
	HANDLE hFind = FindFirstFileA((directory + "\\*.txt").c_str(), &findData);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				std::string filePath = directory + "\\" + findData.cFileName;
			//	std::cout << "Parsing file: " << filePath << std::endl;
				//	x_str.Format(_T("%d"), x_count);
			//		m_PathsComboBox.AddString((filePath.c_str() + x_str));

				CStringA filePathA(filePath.c_str());
				CStringW filePathW(filePathA);
				x_str.Format(_T("%s"), filePathW.GetBuffer());
				m_PathsComboBox.AddString(x_str);
				filePathW.ReleaseBuffer();
				{
					std::cerr << "Failed to delete file: " << filePath << std::endl;
				}
			}
		} while (FindNextFileA(hFind, &findData));

		FindClose(hFind);
	}
	else
	{
		std::cerr << "Failed to open directory: " << directory << std::endl;
	}
}



void CServerDlg::ParseTextFilesDelete(const std::string& directory)
{
	WIN32_FIND_DATAA findData;
	HANDLE hFind = FindFirstFileA((directory + "\\*.txt").c_str(), &findData);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				std::string filePath = directory + "\\" + findData.cFileName;
				std::cout << "Parsing file: " << filePath << std::endl;

				// 파일 삭제 로직 추가
				if (DeleteFileA(filePath.c_str()))
				{
					std::cout << "File deleted: " << filePath << std::endl;
				}
				else
				{
					std::cerr << "Failed to delete file: " << filePath << std::endl;
				}
			}
		} while (FindNextFileA(hFind, &findData));

		FindClose(hFind);
	}
	else
	{
		std::cerr << "Failed to open directory: " << directory << std::endl;
	}
}


void CServerDlg::OnBnClickedRichDebugPrintf()
{
	std::string directory = ".\\Data\\";
	ParseTextFilesPrintf(directory);
}


void CServerDlg::OnBnClickedRichDelete()
{
	std::string directory = ".\\Data\\";
	ParseTextFilesDelete(directory);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}




void CServerDlg::OnEnChangeEditDataOutputSecond()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CServerDlg::OnBnClickedRichDebugSecond()
{


		std::string directory = ".\\Data\\";
	ParseTextFiles(directory);



	CRichEditCtrl_s.SetWindowTextW(resultString);




	//CRichEditCtrl_s
//	CRichEditCtrl_m.SetWindowTextW(CServerDlg::ip); //테스트 디버깅
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	/*
	std::string directory = ".\\Data\\";
	ParseTextFiles(directory);



	CRichEditCtrl_m.SetWindowTextW(resultString);
	*/
}


void CServerDlg::OnBnClickedChkMyHomeUpDataStatus()
{
	//m_NetWork_Status.
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CServerDlg::checkBoxState = m_NetWork_Status.GetCheck();
	Static_checkBoxState = checkBoxState;
	//CHECKBOX_OFFSET
	int * checkBoxSSumPointer = (int*)bigPointer_ptr + CHECKBOX_OFFSET;
	*checkBoxSSumPointer = Static_checkBoxState;
	printf("%d현재 체크박스 사용 상태는\n", checkBoxState);
}

//콤보박스



BOOL CServerDlg::IsComboBoxDroppedDown()
{
	return m_PathsComboBox.GetDroppedState();
}



void CServerDlg::OnCbnSelchangeComboPathDestination()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//BOOL Sum =CServerDlg::IsComboBoxDroppedDown();
	
	//printf("[%d]", Sum);
	//m_PathsComboBox.GetWindowTextW(Single_Path);
	CServerDlg::OnBnClickedRichDebug();
	int* allocated_memory = (int*)bigPointer_ptr;
	ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)m_beginThread, *&allocated_memory); //900 Size //타점3
	

	//printf("[%ws]", Single_Path);


}
//IsComboBoxScrolled



void CServerDlg::OnBnClickedBtnComboTestConnect() //Fun5
{

	m_PathsComboBox.ResetContent();

	std::string directory = ".\\Data\\";
	ParseTextFilesPathGet(directory);


}


void CServerDlg::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CServerDlg::OnBnClickedBtnPathSingleDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CServerDlg::OnBnClickedFun1()//경로 가져오기
{
	m_PathsComboBox.GetWindowTextW(Single_Path);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CServerDlg::OnBnClickedFun2()
{
	m_PathsComboBox.ResetContent();

	std::string directory = ".\\Data\\";
	ParseTextFilesPathGet(directory);
	m_PathsComboBox.SetWindowTextW(Single_Path);
}



void CServerDlg::OnBnClickedBtnSettingTestConnect()
{
	m_DlgConfigSetting = new DlgConfigSetting();
	m_DlgConfigSetting->Create(IDD_DLG_CONFIG_SETTING_DFS, this);
	m_DlgConfigSetting->ShowWindow(SW_SHOW);
	m_DlgConfigSetting->SetWindowText(L"Settings");//프로그램 제목 변경.
	m_DlgConfigSetting->DlgConfigSetting::Set_Url();
	//m_DlgConfigSetting->
}


void CServerDlg::OnEnChangeEditNetworkUrlStatus()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}




void CServerDlg::Get_AutoMdoe_Status()
{

	//m_DlgConfigSetting = new DlgConfigSetting();


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
					m_NetWork_Status.SetCheck(1);
					m_PathsComboBox.SetWindowTextW(x_str);
					ParseTextFiles_Single(x_str);
					CRichEditCtrl_m.SetWindowTextW(resultString_Single);
				}
				else if (status == 0)
				{
				    m_NetWork_Status.SetCheck(0);
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




void CServerDlg::Auto_Server_Status()
{

	//m_DlgConfigSetting = new DlgConfigSetting();


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
				//	m_NetWork_Status.SetCheck(1);
			//		m_PathsComboBox.SetWindowTextW(x_str);
		//			ParseTextFiles_Single(x_str);
	//				CRichEditCtrl_m.SetWindowTextW(resultString_Single);
				}
				else if (status == 0)
				{
			//		m_NetWork_Status.SetCheck(0);
				}
				else if (status == 2)
				{
					//		m_NetWork_Status.SetCheck(0);
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







/*
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
*/

void CServerDlg::OnEnChangeDlgServerStaDfs()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CServerDlg::OnBnClickedButton7()
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

				if (status == 1)
				{
					OnBnClickedBtnServer2IpData();
				//	m_edit_Listen_ServerStatus.SetWindowTextW(L"동기서버 ON");
				}
				else if (status == 0)
				{
					printf("서버가 안켜진 상태 입니다.\n");
					//m_bChkSynServerTo.SetCheck(0);
					//m_bChk_Ayns_checkBoxState.SetCheck(0);
				}
				else if (status == 2)
				{
					OnBnClickedBtnServerIpData();
			//		m_edit_Listen_ServerStatus.SetWindowTextW(L"비동기 서버 ON");
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



void CServerDlg::OnBnClickedBtnLogSingleDelete()
{
	CRichEditCtrl_m.SetWindowTextW(L"");
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CServerDlg::OnBnClickedBtnPathDualDelete()
{
	CRichEditCtrl_s.SetWindowTextW(L"");
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CServerDlg::OnBnClickedButton8() //컨트롤 타워 리치 에디터에서 체인지 버튼 누를떄 영향을 받음.
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	int* allocated_memory = (int*)bigPointer_ptr;
	//OnBnClickedFun2()
	//ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)m_beginThread_Fun4_Delete, *&allocated_memory); //900 Size //타점3
}


void CServerDlg::OnBnClickedButton9()
{

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnBnClickedFun2();
	m_PathsComboBox.SetWindowTextW(x_str);
	OnBnClickedRichDebug();
}
