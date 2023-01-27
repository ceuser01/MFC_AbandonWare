
// MFCDlg.h: 헤더 파일
//

#pragma once

#include "pch.h"
// CMFCDlg 대화 상자
class DlgMfcMain : public CDialogEx
{
// 생성입니다.
public:
	DlgMfcMain(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_MAIN};
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.

private:
	DlgFileOpenTutorialFirst* m_pFileOpenTutoria1;
	DlgUIControlTutorialSecond* m_pUIControlTutoria2;
	//DlgImageTutorialtTird
	DlgImageTutorialtTird* m_pDlgImageTutorialtTir3;
	DlgArrayTutorialtFour* m_pDlgArrayTutorialtFour4;
	DlgPointerTutorialfive* m_pDlgPointerTutorialfive5;
	//DlgIninheritanceTutorialSix
	DlgIninheritanceTutorialSix* m_pDlgIninheritanceTutorialSix6;
	DlgMsgSeven* m_pDlgMsgSeven7;
	DlgThreadTutorialEight* m_pDlgThreadTutorialEight8;
	DlgSocketTutorialNine* m_pDlgSocketTutorialNine9;
	DlgSocketTutorialTen* m_pDlgSocketTutorialTen10;
	//DlgMsgSeven
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedBtnDlgFileOpenTutorialFirst();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOnbnclickedbtndlguitutorialsecond();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
};
