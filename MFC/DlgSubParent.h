#pragma once
#include "afxdialogex.h"


// DlgSubParent 대화 상자

class DlgSubParent : public CDialogEx
{
	DECLARE_DYNAMIC(DlgSubParent)

public:
	DlgSubParent(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlgSubParent();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PARENT_X};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};
