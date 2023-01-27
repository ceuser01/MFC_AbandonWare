#pragma once
#include "afxdialogex.h"


// DlgImageTutorialtTird 대화 상자

class DlgImageTutorialtTird : public CDialogEx
{
	DECLARE_DYNAMIC(DlgImageTutorialtTird)

public:
	DlgImageTutorialtTird(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlgImageTutorialtTird();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IMAGE };
#endif




protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnEnChangeEdit1();
	afx_msg void BitbltFun();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	CComboBox line_color;
	CComboBox ComBox_color;
	afx_msg void OnCbnSelchangeCombo1();
};
