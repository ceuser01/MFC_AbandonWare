// DlgArrayTutorialtFour.cpp: 구현 파일
//

#include "pch.h"
#include "MFC.h"
#include "afxdialogex.h"
#include "DlgArrayTutorialtFour.h"


// DlgArrayTutorialtFour 대화 상자

IMPLEMENT_DYNAMIC(DlgArrayTutorialtFour, CDialogEx)

DlgArrayTutorialtFour::DlgArrayTutorialtFour(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_ARRAY_5, pParent)
{

}

DlgArrayTutorialtFour::~DlgArrayTutorialtFour()
{
}

void DlgArrayTutorialtFour::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT7, OutPut1);
	DDX_Control(pDX, IDC_EDIT8, OutPut2);
	DDX_Control(pDX, IDC_EDIT1, InPut1);
	DDX_Control(pDX, IDC_EDIT2, InPut2);
	DDX_Control(pDX, IDC_EDIT3, InPut3);
	DDX_Control(pDX, IDC_EDIT4, InPut4);
	DDX_Control(pDX, IDC_EDIT5, InPut5);
	DDX_Control(pDX, IDC_EDIT6, InPut6);
}


BEGIN_MESSAGE_MAP(DlgArrayTutorialtFour, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &DlgArrayTutorialtFour::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &DlgArrayTutorialtFour::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &DlgArrayTutorialtFour::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgArrayTutorialtFour::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DlgArrayTutorialtFour::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT4, &DlgArrayTutorialtFour::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &DlgArrayTutorialtFour::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &DlgArrayTutorialtFour::OnEnChangeEdit6)
	ON_EN_CHANGE(IDC_EDIT7, &DlgArrayTutorialtFour::OnEnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT8, &DlgArrayTutorialtFour::OnEnChangeEdit8)
END_MESSAGE_MAP()


// DlgArrayTutorialtFour 메시지 처리기

CString static second[3];//
void DlgArrayTutorialtFour::OnEnChangeEdit1()
{
	
	InPut1.GetWindowTextW(second[0]);
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void DlgArrayTutorialtFour::OnEnChangeEdit2()
{
	InPut2.GetWindowTextW(second[1]);
}


void DlgArrayTutorialtFour::OnEnChangeEdit3()
{
	InPut3.GetWindowTextW(second[2]);
}




void DlgArrayTutorialtFour::OnEnChangeEdit4()
{
	InPut4.GetWindowTextW(second[0]);
}


void DlgArrayTutorialtFour::OnEnChangeEdit5()
{
	InPut5.GetWindowTextW(second[1]);
}


void DlgArrayTutorialtFour::OnEnChangeEdit6()
{
	InPut6.GetWindowTextW(second[2]);
}


void DlgArrayTutorialtFour::OnEnChangeEdit7()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void DlgArrayTutorialtFour::OnEnChangeEdit8()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void DlgArrayTutorialtFour::OnBnClickedButton1()
{
	OutPut1.SetWindowTextW(L"현재 사번은" + second[0] + L"이며, " + "현재 이름은" + second[1] + L"이며, ""현재 전화번호는" + second[2] + L"입니다. \n");
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

static CString x_name = L"admin";
void DlgArrayTutorialtFour::OnBnClickedButton2()
{

	if (x_name == second[1]) {
		OutPut2.SetWindowTextW(L"관리자 이름 입니다.\n");

	}
	else
		OutPut2.SetWindowTextW(L"관리자 이름이 아닙니다.\n");
	
}

