#pragma once
#include "afxdialogex.h"


// DlgArrayTutorialtFour 대화 상자

class DlgArrayTutorialtFour : public CDialogEx
{
	DECLARE_DYNAMIC(DlgArrayTutorialtFour)

public:
	DlgArrayTutorialtFour(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlgArrayTutorialtFour();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_ARRAY_5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnEnChangeEdit8();
	CEdit OutPut1;
	CEdit OutPut2;
	CEdit InPut1;
	CEdit InPut2;
	CEdit InPut3;
	CEdit InPut4;
	CEdit InPut5;
	CEdit InPut6;
};
