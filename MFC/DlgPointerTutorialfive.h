#pragma once
#include "afxdialogex.h"


// DlgPointerTutorialfive 대화 상자

class DlgPointerTutorialfive : public CDialogEx
{
	DECLARE_DYNAMIC(DlgPointerTutorialfive)

public:
	DlgPointerTutorialfive(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlgPointerTutorialfive();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POINTER};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void ChangeValue(int* nval);
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit3();
	CEdit Edit_save1;
	CEdit Edit_save2;
};
