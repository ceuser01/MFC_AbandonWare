// DlgIninheritanceTutorialSix.cpp: 구현 파일
//

#include "pch.h"
#include "MFC.h"
#include "afxdialogex.h"
#include "DlgIninheritanceTutorialSix.h"


// DlgIninheritanceTutorialSix 대화 상자

IMPLEMENT_DYNAMIC(DlgIninheritanceTutorialSix, CDialogEx)

DlgIninheritanceTutorialSix::DlgIninheritanceTutorialSix(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INHERITANCE, pParent)
{

}

DlgIninheritanceTutorialSix::~DlgIninheritanceTutorialSix()
{
}

void DlgIninheritanceTutorialSix::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, OutPut);
	DDX_Control(pDX, IDC_BUTTON1, Button_x);
}


BEGIN_MESSAGE_MAP(DlgIninheritanceTutorialSix, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &DlgIninheritanceTutorialSix::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgIninheritanceTutorialSix::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DlgIninheritanceTutorialSix::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &DlgIninheritanceTutorialSix::OnBnClickedButton4)
END_MESSAGE_MAP()


// DlgIninheritanceTutorialSix 메시지 처리기


void DlgIninheritanceTutorialSix::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void DlgIninheritanceTutorialSix::OnBnClickedButton1()
{
	OutPut.SetWindowTextW(L"");
}


void DlgIninheritanceTutorialSix::OnBnClickedButton2()
{
	OutPut.SetWindowTextW(L"EditBox Test 출력");
}


void DlgIninheritanceTutorialSix::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DlgSubParent* m_pDlgSubParent;
	m_pDlgSubParent = new DlgSubParent();
	m_pDlgSubParent->Create(IDD_PARENT_X, this);
	m_pDlgSubParent->ShowWindow(SW_SHOW);
	m_pDlgSubParent->SetWindowText(L"Parent Window");//프로그램 제목 변경.

}

void DlgIninheritanceTutorialSix::ButtonAdd()
{
	//x_guiret.SetWindowTextW(L"12.");
	OutPut.ShowWindow(SW_SHOW); // 

}

void DlgIninheritanceTutorialSix::ButtonHide()
{
	//x_guiret.SetWindowTextW(L"12.");
	OutPut.ShowWindow(SW_HIDE); // 
}

void DlgIninheritanceTutorialSix::TestOutPut()
{
	//x_guiret.SetWindowTextW(L"12.");
	OutPut.SetWindowTextW(L"EditBox Test 출력으로 .");
}
//Button_11
//OutPut.SetWindowTextW(L"EditBox Test 출력으로 .");
//Button_x

void DlgIninheritanceTutorialSix::Button_11()
{
	//x_guiret.SetWindowTextW(L"12.");
	Button_x.SetWindowTextW(L"11");
}