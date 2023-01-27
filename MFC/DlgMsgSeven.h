#pragma once
#include "afxdialogex.h"


// DlgMsgSeven 대화 상자

class DlgMsgSeven : public CDialogEx
{
	DECLARE_DYNAMIC(DlgMsgSeven)

public:
	DlgMsgSeven(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlgMsgSeven();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MESSAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CEdit x_msg_output;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();

	afx_msg void OnEnChangeEdit3();
	CEdit x_outPut_log;
};
