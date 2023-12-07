
// ComplexLibWebSyncDlg.cpp: 구현 파일
//

#include "pch.h"
#include "DllLoadCollector.h" //cMain
#include "framework.h"
#include "ComplexLibWebSync.h"
#include "ComplexLibWebSyncDlg.h"
#include "afxdialogex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//정적 맴버변수 초기화 캐스팅.
// 정적 멤버 변수 초기화
char* CComplexLibWebSyncDlg::pchBigPointer = nullptr;


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


// CComplexLibWebSyncDlg 대화 상자



CComplexLibWebSyncDlg::CComplexLibWebSyncDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COMPLEXLIBWEBSYNC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CComplexLibWebSyncDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CComplexLibWebSyncDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CComplexLibWebSyncDlg 메시지 처리기
// 
//MainStart



BOOL CComplexLibWebSyncDlg::OnInitDialog()
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
		// Creating the thread
	  // RWX 권한으로 메모리 할당

	// 쓰레드 생성 및 핸들 저장
		static const char EnableFlag = ENABLE_FLAG; // ENABLE_FLAG 값을 가지는 상수 변수

		if (pchBigPointer == nullptr) {
		pchBigPointer = (char*)EnableFlag; // 첫 번째 바이트에 활성화 플래그 설정
		}

		HANDLE threadHandle = CreateThread(NULL, MAIN_STACK_SIZE, DllLoadCollector::MainStart, pchBigPointer , 0, NULL); //한번만 사용함. 그리고

		if (threadHandle != NULL) {
			// 쓰레드 작업 완료 대기 (옵션: INFINITE 또는 적절한 시간을 지정)
			//WaitForSingleObject(threadHandle, INFINITE);

			// 핸들 닫기
			CloseHandle(threadHandle);
		}
		else {
			// 쓰레드 생성 실패 처리
			// 필요한 경우 메모리 해제 및 오류 처리
			//Sleep(500);//메인 쓰레드 생성 진입이후에 실패 콘솔이 켜져야 하는 시간 떄문에 조금 쉬어져야한다.
			//delete[] pchBigPointer; //굳이? 빅포인터를 삭제해줄 필요 없다. 계속 쓸거야. pchBigPointer 쓰레드가 죽어도 검사를 하려면 메인 포인터 만큼은 살아 있어야해. 그리고 오해하지 마라. 한번만 쓰이는 예외처리용 대용량 포인터라 누수걱정이 없다.
		//	std::cerr << "Failed to create thread." << std::endl;
		//	CloseHandle(threadHandle);
		}

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

void CComplexLibWebSyncDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CComplexLibWebSyncDlg::OnPaint()
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
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CComplexLibWebSyncDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

