
// MFCDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC.h"
#include "DlgMfcMain.h"
#include "afxdialogex.h"

//DLG
#include "DlgFileOpenTutorialFirst.h"
#include "DlgUIControlTutorialSecond.h"

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


// CMFCDlg 대화 상자



DlgMfcMain::DlgMfcMain(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void DlgMfcMain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(DlgMfcMain, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &DlgMfcMain::OnBnClickedBtnDlgFileOpenTutorialFirst)
	ON_BN_CLICKED(IDC_BUTTON2, &DlgMfcMain::OnBnClickedOnbnclickedbtndlguitutorialsecond)
	ON_BN_CLICKED(IDC_BUTTON0, &DlgMfcMain::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON4, &DlgMfcMain::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &DlgMfcMain::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &DlgMfcMain::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &DlgMfcMain::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &DlgMfcMain::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &DlgMfcMain::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &DlgMfcMain::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &DlgMfcMain::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &DlgMfcMain::OnBnClickedButton12)
END_MESSAGE_MAP()


// CMFCDlg 메시지 처리기

BOOL DlgMfcMain::OnInitDialog()
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

	CWnd* pWnd = AfxGetMainWnd();
	HWND hxx = pWnd->m_hWnd;



	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void DlgMfcMain::OnSysCommand(UINT nID, LPARAM lParam)
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

void DlgMfcMain::OnPaint()
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
HCURSOR DlgMfcMain::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


using namespace std;
void DlgMfcMain::OnBnClickedButton0()
{
	FileProcFun::ExitKey();
}



// 퍼스트 튜토리얼
	//
void DlgMfcMain::OnBnClickedBtnDlgFileOpenTutorialFirst()
{
	// 퍼스트 튜토리얼
	//
	////CLogger			*m_pLogger;
	//DlgFileOpenTutorialFirst* m_pFileOpenTutoria1;
	m_pFileOpenTutoria1 = new DlgFileOpenTutorialFirst();
	m_pFileOpenTutoria1->Create(IDD_MFC_DLG_FILEOPEN_1, this);
	m_pFileOpenTutoria1->ShowWindow(SW_SHOW);
	m_pFileOpenTutoria1->SetWindowText(L"IDD_MFC_DLG_FILEOPEN_1");//프로그램 제목 변경.
}


//DlgUIControlTutorialSecond

void DlgMfcMain::OnBnClickedOnbnclickedbtndlguitutorialsecond()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//m_pUIControlTutoria2
	m_pUIControlTutoria2 = new DlgUIControlTutorialSecond();
	m_pUIControlTutoria2->Create(IDD_UI_CONTROL_X, this);
	m_pUIControlTutoria2->ShowWindow(SW_SHOW);
	m_pUIControlTutoria2->SetWindowText(L"IDD_UI_CONTROL_X");//프로그램 제목 변경.
}


void DlgMfcMain::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//m_pDlgImageTutorialtTir3
	m_pDlgImageTutorialtTir3 = new DlgImageTutorialtTird();
	m_pDlgImageTutorialtTir3->Create(IDD_IMAGE, this);
	m_pDlgImageTutorialtTir3->ShowWindow(SW_SHOW);
	m_pDlgImageTutorialtTir3->SetWindowText(L"IDD_IMAGE_4");//프로그램 제목 변경.
	m_pDlgImageTutorialtTir3->line_color.AddString(_T("Black"));
	m_pDlgImageTutorialtTir3->line_color.AddString(_T("yellow"));
	m_pDlgImageTutorialtTir3->ComBox_color.AddString(_T("Black"));
	m_pDlgImageTutorialtTir3->ComBox_color.AddString(_T("yellow"));
		//Com_Box_Test.AddString(_T("콤보박스 생성" + x_str));
}


void DlgMfcMain::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//m_pDlgArrayTutorialtFour4
	m_pDlgArrayTutorialtFour4 = new DlgArrayTutorialtFour();
	m_pDlgArrayTutorialtFour4->Create(IDD_MFC_ARRAY_5, this);
	m_pDlgArrayTutorialtFour4->ShowWindow(SW_SHOW);
	m_pDlgArrayTutorialtFour4->SetWindowText(L"IDD_MFC_ARRAY_5");//프로그램 제목 변경.
}


void DlgMfcMain::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pDlgPointerTutorialfive5 = new DlgPointerTutorialfive();
	m_pDlgPointerTutorialfive5->Create(IDD_POINTER, this);
	m_pDlgPointerTutorialfive5->ShowWindow(SW_SHOW);
	m_pDlgPointerTutorialfive5->SetWindowText(L"IDD_POINTER_6");//프로그램 제목 변경.

}


void DlgMfcMain::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//m_pDlgIninheritanceTutorialSix6
	m_pDlgIninheritanceTutorialSix6 = new DlgIninheritanceTutorialSix();
	m_pDlgIninheritanceTutorialSix6->Create(IDD_INHERITANCE, this);
	m_pDlgIninheritanceTutorialSix6->ShowWindow(SW_SHOW);
	m_pDlgIninheritanceTutorialSix6->SetWindowText(L"IDD_INHERITANCE_7");//프로그램 제목 변경.

}


void DlgMfcMain::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// //DlgMsgSeven
	//IDD_MESSAGE
	//m_pDlgMsgSeven7
	m_pDlgMsgSeven7 = new DlgMsgSeven();
	m_pDlgMsgSeven7->Create(IDD_MESSAGE, this);
	m_pDlgMsgSeven7->ShowWindow(SW_SHOW);
	m_pDlgMsgSeven7->SetWindowText(L"IDD_IDD_MESSAGE_8");//프로그램 제목 변경.
}

//m_pDlgThreadTutorialEight8

void DlgMfcMain::OnBnClickedButton9()
{
	m_pDlgThreadTutorialEight8 = new DlgThreadTutorialEight();
	m_pDlgThreadTutorialEight8->Create(IDD_THREAD_LOCK, this);
	m_pDlgThreadTutorialEight8->ShowWindow(SW_SHOW);
	m_pDlgThreadTutorialEight8->SetWindowText(L"IDD_THREAD_LOCK_9");//프로그램 제목 변경.
	//DlgSocketTutorialNine
}


void DlgMfcMain::OnBnClickedButton10()
{

	m_pDlgSocketTutorialNine9 = new DlgSocketTutorialNine();
	m_pDlgSocketTutorialNine9->Create(IDD_SOCKET_SERIAL, this);
	m_pDlgSocketTutorialNine9->ShowWindow(SW_SHOW);
	m_pDlgSocketTutorialNine9->SetWindowText(L"IDD_SOCKET_SERIAL_10");//프로그램 제목 변경.
	m_pDlgSocketTutorialNine9->DlgSocketTutorialNine::Server_listen();//서버 리스너 서버 형성
	m_pDlgSocketTutorialNine9->DlgSocketTutorialNine::Client_Con();//클라이언트 커넥티드
	m_pDlgSocketTutorialNine9->DlgSocketTutorialNine::StartText();//텍스트 영역에 데이터 넣기
	// DlgSocketTutorialNine::StartText
}


void DlgMfcMain::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//DlgSocketTutorialTen
	m_pDlgSocketTutorialTen10 = new DlgSocketTutorialTen();
	m_pDlgSocketTutorialTen10->Create(IDD_SOCKET, this);
	m_pDlgSocketTutorialTen10->ShowWindow(SW_SHOW);
	m_pDlgSocketTutorialTen10->SetWindowText(L"IDD_SOCKET_11");//프로그램 제목 변경.
}



void DlgMfcMain::OnBnClickedButton12()
{
	wchar_t* p_m_Unicode;
	char static test_c[300] = "ddddddd";
	ConversionLib::MultiCodeConversion_mem_delete(p_m_Unicode, test_c);

}



