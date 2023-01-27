#pragma once
#include "afxdialogex.h"


// DlgUIControlTutorialSecond 대화 상자

class DlgUIControlTutorialSecond : public CDialogEx
{
	DECLARE_DYNAMIC(DlgUIControlTutorialSecond)

public:
	DlgUIControlTutorialSecond(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlgUIControlTutorialSecond();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UI_CONTROL_X };
#endif


private:
	CString get_text;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString x_str;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedRadio1();
	CEdit PathSaveName;
	afx_msg void OnEnChangeEdit2();
	CEdit OutPut;
	CComboBox Com_Box_Test;
	afx_msg void x_ComBoxFun();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedAcButton();
};
