
// ServerDlg.h: 헤더 파일
//

#pragma once


// CServerDlg 대화 상자
class CServerDlg : public CDialogEx
{
// 생성입니다.
public:
	CServerDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	CString str_copy;
	HICON m_hIcon;
	CString x_str;
	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditIp();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEditPort();
	afx_msg void OnBnClickedBtnPathSettingData();
	afx_msg void OnEnChangeEditPathSettingData();
	afx_msg void OnEnChangeEditDataOutput();
	CRichEditCtrl CRichEditCtrl_m;
	afx_msg void OnBnClickedRichDebug();
	afx_msg void UpdatePortText();
	afx_msg void SetIpAddress();
	afx_msg void StartServer();
	afx_msg void SynStartServer();
	afx_msg void FileOn();
	afx_msg void m_ComBoxFun();
	afx_msg void SetCommonControlsManifest();
	afx_msg BOOL IsComboBoxDroppedDown();
	afx_msg BOOL IsComboBoxScrolled();
	//IsComboBoxScrolled
	// void CServerDlg::m_ComBoxFun()
	void ParseTextFiles_Single(const CString& filePath);
	void ParseTextFiles(const std::string& directory);
	void ParseTextFilesPrintf(const std::string& directory);
	void ParseTextFilesDelete(const std::string& directory);
	void ParseTextFilesPathGet(const std::string& directory);
	static CString GetMainWindowTitle();

	afx_msg void WriteNumberToFileOn();
	afx_msg void WriteNumberToFileOff();
	afx_msg void Get_AutoMdoe_Status();
	afx_msg void Auto_Server_Status();
	//Auto_Server_Status
	//Get_AutoMdoe_Status
	//IsComboBoxDroppedDown
	//HWND CServerDlg::GetMainWindowTitle()

//	static unsigned long __stdcall m_beginThread(LPVOID x_po);




	/*
	CServerDlg::SetCommonControlsManifest()
	*/

	//ParseTextFilesPathGet
	// 
	// 
	//ParseTextFilesDelete
	//ParseTextFilesPrintf
	//FileOn

	//
	//UpdatePortText
//	CEdit Edit_Port_Data;
	CEdit m_editPort;
	CEdit m_edit_Ip;
	CButton m_btnStart;
	CString ip;
	CString port;
	 	int checkBoxState;

	afx_msg void OnBnClickedBtnServerIpData();


	CEdit m_Edit_Port_change;
	afx_msg void OnBnClickedBtnServer2IpData();
	afx_msg void OnBnClickedRichDebugPrintf();
	afx_msg void OnBnClickedRichDelete();
	afx_msg void OnEnChangeRichedit22();
	afx_msg void OnEnChangeEditDataOutputSecond();
	afx_msg void OnBnClickedRichDebugSecond();
	CRichEditCtrl CRichEditCtrl_s;
	afx_msg void OnBnClickedChkMyHomeUpDataStatus();
	CButton m_NetWork_Status;
	afx_msg void OnCbnSelchangeComboPathDestination();
	afx_msg void OnBnClickedBtnComboTestConnect();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox m_PathsComboBox;
	afx_msg void OnBnClickedBtnPathSingleDelete();
	afx_msg void OnBnClickedFun1();
	afx_msg void OnBnClickedFun2();
	afx_msg void OnBnClickedBtnSettingTestConnect();

private:
	DlgConfigSetting* m_DlgConfigSetting;
public:
	afx_msg void OnEnChangeEditNetworkUrlStatus();
	CEdit m_editNetworkURLStatus;
	afx_msg void OnEnChangeDlgServerStaDfs();
	CEdit m_edit_Listen_ServerStatus;
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedBtnLogSingleDelete();
	afx_msg void OnBnClickedBtnPathDualDelete();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
};
