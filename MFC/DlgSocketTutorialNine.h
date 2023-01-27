#pragma once
#include "afxdialogex.h"


// DlgSocketTutorialNine 대화 상자

class DlgSocketTutorialNine : public CDialogEx
{
	DECLARE_DYNAMIC(DlgSocketTutorialNine)

public:
	DlgSocketTutorialNine(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlgSocketTutorialNine();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SOCKET_SERIAL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
private:
	CString packet_data1;

public:
	afx_msg void StartText();
	afx_msg void Server_listen();
	afx_msg void Client_Con();
	afx_msg void OnBnClickedButton1();
	CEdit Edit_Packet_Data;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton4();
	CEdit edit_server_log1;
	CEdit edit_server_log2;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void UnlimitedFun();
	//StartText
	afx_msg void OnBnClickedPacketlogsave();
	CEdit PacktData_log;
};
