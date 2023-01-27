#pragma once
#include "afxdialogex.h"


// DlgThreadTutorialEight 대화 상자

class DlgThreadTutorialEight : public CDialogEx
{
	DECLARE_DYNAMIC(DlgThreadTutorialEight)

public:
	DlgThreadTutorialEight(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlgThreadTutorialEight();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THREAD_LOCK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit x_Thread_log;
	afx_msg void ThreadFun1();
	afx_msg void ThreadFun2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
