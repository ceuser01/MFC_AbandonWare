// DlgPointerTutorialfive.cpp: 구현 파일
//

#include "pch.h"
#include "MFC.h"
#include "afxdialogex.h"
#include "DlgPointerTutorialfive.h"

CString static Edit_String1;
CString static Edit_String2;


// DlgPointerTutorialfive 대화 상자

IMPLEMENT_DYNAMIC(DlgPointerTutorialfive, CDialogEx)

DlgPointerTutorialfive::DlgPointerTutorialfive(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_POINTER, pParent)
{

}

DlgPointerTutorialfive::~DlgPointerTutorialfive()
{
}

void DlgPointerTutorialfive::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, Edit_save1);
	DDX_Control(pDX, IDC_EDIT2, Edit_save2);
}


BEGIN_MESSAGE_MAP(DlgPointerTutorialfive, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &DlgPointerTutorialfive::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &DlgPointerTutorialfive::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgPointerTutorialfive::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT3, &DlgPointerTutorialfive::OnEnChangeEdit3)
END_MESSAGE_MAP()


// DlgPointerTutorialfive 메시지 처리기


void DlgPointerTutorialfive::ChangeValue(int* nval)
{



	printf("[%p] 포인터 주소가 출력 됩니다.\n", nval);
	printf("[%p] 해당 주소 값에 있는 [%d] 데이터에 +3을 더 합니다.\n", nval, *nval);
//	int Third = 3;
	*nval+= 3;

	printf("[%p] 의 주소의 포인터에 변환 된 값은 [%d] 입니다.\n", nval, *nval);


}



int arr[3][4] = {    // 세로 3, 가로 4 크기의 int형 2차원 배열 선언
			{ 11, 22, 33, 44 },
			{ 55, 66, 77, 88 },
			{ 99, 110, 121, 132 }
};



void DlgPointerTutorialfive::OnEnChangeEdit1()
{
	//Edit_Save1.GetWindowTextW(Edit_String1);
	Edit_save1.GetWindowTextW(Edit_String1);
}


void DlgPointerTutorialfive::OnEnChangeEdit2()
{
	Edit_save2.GetWindowTextW(Edit_String2);
}



void DlgPointerTutorialfive::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

     //std::stoi()
//	stoi(Edit_String2);
	wchar_t* w_pointer=0; //= Edit_String1;

	int(*pointer)[4] = arr;
	ChangeValue(*arr);

}


void DlgPointerTutorialfive::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
