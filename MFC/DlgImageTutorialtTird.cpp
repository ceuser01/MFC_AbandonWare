// DlgImageTutorialtTird.cpp: 구현 파일
//

#include "pch.h"
#include "MFC.h"
#include "afxdialogex.h"
#include "DlgImageTutorialtTird.h"


// DlgImageTutorialtTird 대화 상자

IMPLEMENT_DYNAMIC(DlgImageTutorialtTird, CDialogEx)

DlgImageTutorialtTird::DlgImageTutorialtTird(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_IMAGE, pParent)
{

}

DlgImageTutorialtTird::~DlgImageTutorialtTird()
{
}

void DlgImageTutorialtTird::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, line_color);
	DDX_Control(pDX, IDC_COMBO2, ComBox_color);
}


BEGIN_MESSAGE_MAP(DlgImageTutorialtTird, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &DlgImageTutorialtTird::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgImageTutorialtTird::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DlgImageTutorialtTird::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &DlgImageTutorialtTird::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &DlgImageTutorialtTird::OnBnClickedButton5)
	ON_CBN_SELCHANGE(IDC_COMBO1, &DlgImageTutorialtTird::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// DlgImageTutorialtTird 메시지 처리기


void DlgImageTutorialtTird::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void DlgImageTutorialtTird::BitbltFun() {
	HBITMAP hImage, hOldBitmap;
	static HBITMAP hBitmap;
	CDC* pDC = GetDC();
	ReleaseDC(pDC);
	CClientDC dc(this);
	hBitmap = CreateCompatibleBitmap((HDC)dc, 1024, 768);
	HDC mem = CreateCompatibleDC((HDC)dc);
	hImage = (HBITMAP)LoadImage(NULL, TEXT("img\\1.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	HBITMAP old = (HBITMAP)SelectObject(mem, hImage);
	BitBlt(dc, 500 + 100, 100, 600, 200, mem, 0, 0, SRCCOPY);
	DeleteDC(mem);
}
void DlgImageTutorialtTird::OnBnClickedButton1()
{
	BitbltFun();
}


void DlgImageTutorialtTird::OnBnClickedButton2()
{
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.  
	CDC* pDC = GetDC();
	ReleaseDC(pDC);
	CClientDC dc(this); 



	pDC->Ellipse(500, 100, 600, 200); //원 그리기





}


void DlgImageTutorialtTird::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDC* pDC = GetDC();
	ReleaseDC(pDC);
	CClientDC dc(this);
	CPen pen;
	pen.CreatePen(PS_DOT, 3, RGB(255, 0, 0));    // 빨간색 펜을 생성
	CPen* oldPen = dc.SelectObject(&pen);
	CBrush brush;
	brush.CreateSolidBrush(RGB(255, 128, 0));     // 오렌지색 채움색을 생성
	CBrush* oldBrush = dc.SelectObject(&brush);
	pDC->Rectangle(300, 100, 400, 200); //네모 그리기
	dc.SelectObject(oldBrush);

}


void DlgImageTutorialtTird::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDC* pDC = GetDC();
	ReleaseDC(pDC);
	CClientDC dc(this);
	pDC->MoveTo(100, 100);//선 그리기
	pDC->LineTo(200, 200); //선 그리기
}


void DlgImageTutorialtTird::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
