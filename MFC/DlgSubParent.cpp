// DlgSubParent.cpp: 구현 파일
//

#include "pch.h"
#include "MFC.h"
#include "afxdialogex.h"
#include "DlgSubParent.h"


// DlgSubParent 대화 상자

IMPLEMENT_DYNAMIC(DlgSubParent, CDialogEx)

DlgSubParent::DlgSubParent(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PARENT_X, pParent)
{

}

DlgSubParent::~DlgSubParent()
{
}

void DlgSubParent::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgSubParent, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgSubParent::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DlgSubParent::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &DlgSubParent::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &DlgSubParent::OnBnClickedButton5)
END_MESSAGE_MAP()


// DlgSubParent 메시지 처리기


void DlgSubParent::OnBnClickedButton1()
{
	CWnd* subx = GetParent();
	DlgIninheritanceTutorialSix* mainx = (DlgIninheritanceTutorialSix*)subx;
	mainx->Button_11();

}


void DlgSubParent::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CWnd* subx = GetParent();
	DlgIninheritanceTutorialSix* mainx = (DlgIninheritanceTutorialSix*)subx;
	mainx->ButtonHide();
}


void DlgSubParent::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CWnd* subx = GetParent();
	DlgIninheritanceTutorialSix* mainx = (DlgIninheritanceTutorialSix*)subx;
	mainx->ButtonAdd();
}


void DlgSubParent::OnBnClickedButton5()
{
	CWnd* subx = GetParent();
	DlgIninheritanceTutorialSix* mainx = (DlgIninheritanceTutorialSix*)subx;
	mainx->TestOutPut();
}
