#pragma once
#include "afxdialogex.h"


// DlgSocketTutorialTen 대화 상자

class DlgSocketTutorialTen : public CDialogEx
{
	DECLARE_DYNAMIC(DlgSocketTutorialTen)

public:
	DlgSocketTutorialTen(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlgSocketTutorialTen();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SOCKET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit6();
	CEdit Client_Ip_msg;
	CEdit Client_port_msg;
	CEdit Client_log_msg;
	CEdit Server_Ip_msg;
	CEdit Server_port_msg;
	CEdit Server_log_msg;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
