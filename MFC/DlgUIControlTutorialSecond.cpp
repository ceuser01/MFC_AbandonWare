// DlgUIControlTutorialSecond.cpp: 구현 파일
//

#include "pch.h"
#include "MFC.h"
#include "afxdialogex.h"
#include "DlgUIControlTutorialSecond.h"


// DlgUIControlTutorialSecond 대화 상자

IMPLEMENT_DYNAMIC(DlgUIControlTutorialSecond, CDialogEx)

DlgUIControlTutorialSecond::DlgUIControlTutorialSecond(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UI_CONTROL_X, pParent)
{

}

DlgUIControlTutorialSecond::~DlgUIControlTutorialSecond()
{
}

void DlgUIControlTutorialSecond::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, PathSaveName);
	DDX_Control(pDX, IDC_EDIT2, OutPut);
	DDX_Control(pDX, IDC_COMBO1, Com_Box_Test);
}


BEGIN_MESSAGE_MAP(DlgUIControlTutorialSecond, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &DlgUIControlTutorialSecond::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &DlgUIControlTutorialSecond::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_CHECK1, &DlgUIControlTutorialSecond::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_RADIO1, &DlgUIControlTutorialSecond::OnBnClickedRadio1)
	ON_EN_CHANGE(IDC_EDIT2, &DlgUIControlTutorialSecond::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgUIControlTutorialSecond::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_AC_BUTTON, &DlgUIControlTutorialSecond::OnBnClickedAcButton)
END_MESSAGE_MAP()


// DlgUIControlTutorialSecond 메시지 처리기


void DlgUIControlTutorialSecond::OnEnChangeEdit1()
{
	//MessageBox(L"OnEnChangeEdit1");
	PathSaveName.GetWindowTextW(get_text);

}

void DlgUIControlTutorialSecond::OnCbnSelchangeCombo1()
{
	MessageBox(L"OnCbnSelchangeCombo1");
	
}



void DlgUIControlTutorialSecond::OnBnClickedCheck1()
{
	//MessageBox(L"OnBnClickedCheck1");
	OutPut.SetWindowTextW(get_text);
}


void DlgUIControlTutorialSecond::OnBnClickedRadio1()
{
	//MessageBox(L"OnBnClickedRadio1");
	OutPut.SetWindowTextW(L"라디오 사용중");
}


void DlgUIControlTutorialSecond::OnEnChangeEdit2()
{
	//OutPut.SetWindowTextW(get_text);
}

//x_ComBoxFun
void DlgUIControlTutorialSecond::x_ComBoxFun() { //콤보박스 기능
	int static x_count = NULL; //콤보박스 카운
	while (x_count < 9) {

		x_count++;
		x_str.Format(_T("%d"), x_count);
		Com_Box_Test.AddString(_T("콤보박스 생성" + x_str));
	}
	x_count = NULL; //콤보박스 카운팅 제거
}

void DlgUIControlTutorialSecond::OnBnClickedButton1()
{
	x_ComBoxFun();//콤보박스 생성 함수
}


void DlgUIControlTutorialSecond::OnBnClickedAcButton()
{
	OutPut.SetWindowTextW(get_text);
}
