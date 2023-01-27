// DlgSocketTutorialTen.cpp: 구현 파일
//

#include "pch.h"
#include "MFC.h"
#include "afxdialogex.h"
#include "DlgSocketTutorialTen.h"
//클라이언트
CString static s_Client_Ip_msg;
CString static s_Client_port_msg;
CString static s_Client_log_msg;
//서버
CString static s_Server_Ip_msg;
CString static s_Server_port_msg;
CString static s_Server_log_msg;



// DlgSocketTutorialTen 대화 상자

IMPLEMENT_DYNAMIC(DlgSocketTutorialTen, CDialogEx)

DlgSocketTutorialTen::DlgSocketTutorialTen(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SOCKET, pParent)
{

}

DlgSocketTutorialTen::~DlgSocketTutorialTen()
{
}

void DlgSocketTutorialTen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, Client_Ip_msg);
	DDX_Control(pDX, IDC_EDIT3, Client_port_msg);
	DDX_Control(pDX, IDC_EDIT5, Client_log_msg);
	DDX_Control(pDX, IDC_EDIT2, Server_Ip_msg);
	DDX_Control(pDX, IDC_EDIT4, Server_port_msg);
	DDX_Control(pDX, IDC_EDIT6, Server_log_msg);
}


BEGIN_MESSAGE_MAP(DlgSocketTutorialTen, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT3, &DlgSocketTutorialTen::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT2, &DlgSocketTutorialTen::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT4, &DlgSocketTutorialTen::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT1, &DlgSocketTutorialTen::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT5, &DlgSocketTutorialTen::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &DlgSocketTutorialTen::OnEnChangeEdit6)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgSocketTutorialTen::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DlgSocketTutorialTen::OnBnClickedButton2)
END_MESSAGE_MAP()


// DlgSocketTutorialTen 메시지 처리기


void DlgSocketTutorialTen::OnEnChangeEdit3() //포트Get
{
	Client_port_msg.GetWindowTextW(s_Client_port_msg);
}


void DlgSocketTutorialTen::OnEnChangeEdit2()
{
	Server_Ip_msg.GetWindowTextW(s_Server_Ip_msg);
}


void DlgSocketTutorialTen::OnEnChangeEdit4()
{
	Server_port_msg.GetWindowTextW(s_Server_port_msg);
}


void DlgSocketTutorialTen::OnEnChangeEdit1()
{
	Client_Ip_msg.GetWindowTextW(s_Client_Ip_msg);
}


void DlgSocketTutorialTen::OnEnChangeEdit5()
{
	Client_log_msg.GetWindowTextW(s_Client_log_msg);
}


void DlgSocketTutorialTen::OnEnChangeEdit6()
{
	Server_log_msg.GetWindowTextW(s_Server_log_msg);
}


void DlgSocketTutorialTen::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MessageBox(L"아직 미완성 중입니다.1");
}


void DlgSocketTutorialTen::OnBnClickedButton2()
{
	MessageBox(L"아직 미완성 중입니다.2");
}
