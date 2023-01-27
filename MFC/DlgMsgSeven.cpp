// DlgMsgSeven.cpp: 구현 파일
//

#include "pch.h"
#include "MFC.h"
#include "afxdialogex.h"
#include "DlgMsgSeven.h"
#include "ThreadProcSocket.h"


// DlgMsgSeven 대화 상자

IMPLEMENT_DYNAMIC(DlgMsgSeven, CDialogEx)

DlgMsgSeven::DlgMsgSeven(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MESSAGE, pParent)
{

}

DlgMsgSeven::~DlgMsgSeven()
{
}

void DlgMsgSeven::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_EDIT1, x_msg_output);
    DDX_Control(pDX, IDC_EDIT3, x_outPut_log);
}


BEGIN_MESSAGE_MAP(DlgMsgSeven, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgMsgSeven::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DlgMsgSeven::OnBnClickedButton2)
    ON_EN_CHANGE(IDC_EDIT1, &DlgMsgSeven::OnEnChangeEdit1)
    ON_BN_CLICKED(IDC_BUTTON4, &DlgMsgSeven::OnBnClickedButton4)
    ON_BN_CLICKED(IDC_BUTTON5, &DlgMsgSeven::OnBnClickedButton5)

    ON_EN_CHANGE(IDC_EDIT3, &DlgMsgSeven::OnEnChangeEdit3)
END_MESSAGE_MAP()


// DlgMsgSeven 메시지 처리기
#include <stdio.h>
#include <windows.h>



STACK_X StartMsgFun(LPVOID x_po) {

    HWND hWnd = FindWindow(NULL, TEXT("IDD_IDD_MESSAGE_8"));
    HWND hWndButton = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun1"));

    if (hWnd)
        SendMessage(hWndButton, BM_CLICK, 0, 0);
    else
        printf("폼을 실행하지 않았습니다.\n");
    return 0;
}

STACK_X StartMsgFun2(LPVOID x_po) {

    HWND hWnd = FindWindow(NULL, TEXT("IDD_IDD_MESSAGE_8"));
    HWND hWndButton = FindWindowEx(hWnd, NULL, NULL, TEXT("Fun2"));

    if (hWnd)
        PostMessage(hWndButton, BM_CLICK, 0, 0);
    else
        printf("폼을 실행하지 않았습니다.\n");
    return 0;
}


void DlgMsgSeven::OnBnClickedButton1()
{
    int* x_pointer;

    ThreadProcSocket::First_CreateThread_Collector(900, StartMsgFun, *&x_pointer); //900 Size
}
  



void DlgMsgSeven::OnBnClickedButton2()
{
    int* x_pointer;
    ThreadProcSocket::First_CreateThread_Collector(900, StartMsgFun2, *&x_pointer); //900 Size
}


void DlgMsgSeven::OnEnChangeEdit1()
{
  
}


void DlgMsgSeven::OnBnClickedButton4()
{
    x_msg_output.SetWindowTextW(L"DlgMsgSeven::OnBnClickedButton4 함수가 사용 되었습니다.");
    x_outPut_log.SetWindowTextW(L"SendMessage : 처리가 완료되면 다음 코드로 진행 됩니다. 완료되지 못할 시 그대로 남습니다.");
}


void DlgMsgSeven::OnBnClickedButton5()
{
    x_msg_output.SetWindowTextW(L"DlgMsgSeven::OnBnClickedButton5 함수가 사용 되었습니다.");
    x_outPut_log.SetWindowTextW(L"PostMessage : 처리가 되든,안되든 발생 이후 바로 다음 코드로 넘어가서 GUI의 연산 처리가 언제 완료 되는지 알 수 없습니다..");
}



void DlgMsgSeven::OnEnChangeEdit3()
{
    // TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
    // CDialogEx::OnInitDialog() 함수를 재지정 
    //하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
    // 이 알림 메시지를 보내지 않습니다.

    // TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
