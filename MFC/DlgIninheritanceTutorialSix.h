#pragma once
#include "afxdialogex.h"


// DlgIninheritanceTutorialSix 대화 상자

class DlgIninheritanceTutorialSix : public CDialogEx
{
	DECLARE_DYNAMIC(DlgIninheritanceTutorialSix)


private:
//	DlgSubParent* m_pDlgSubParent;

public:
	DlgIninheritanceTutorialSix(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlgIninheritanceTutorialSix();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INHERITANCE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CEdit OutPut;
	afx_msg void OnBnClickedButton4();
	afx_msg void ButtonAdd();
	afx_msg void ButtonHide();
	afx_msg void TestOutPut();
	afx_msg void Button_11();
	//TestOutPut
	//ButtonHide
	CButton Button_x;
};
