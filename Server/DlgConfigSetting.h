#pragma once
#include "pch.h"
#include "afxdialogex.h"
// DlgConfigSetting 대화 상자

class DlgConfigSetting : public CDialogEx
{
	DECLARE_DYNAMIC(DlgConfigSetting)

public:
	DlgConfigSetting(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlgConfigSetting();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_CONFIG_SETTING_DFS};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEditNetworkUrlStatus();
	afx_msg void OnEnChangeDlgConfigSettingDfs();
	afx_msg void Set_Url();
	afx_msg void WriteNumberToFileOff();
	afx_msg void WriteNumberToFileon();

	afx_msg void Auto_WriteNumberToFileon_Syn();
	afx_msg void Auto_WriteNumberToFileOff_Syn();
	afx_msg void Auto_WriteNumberToFileon_Syn_A();
	afx_msg void Auto_WriteNumberToFileOff_Syn_A();
	//WriteNumberToFileOff
	//Set_Url
//	CButton m_Paths_Setting_URL;
	afx_msg void OnBnClickedButton1();
	CButton m_Paths_Setting_URL_Edit;
	CEdit m_Paths_Setting_URL2;
	afx_msg void OnBnClickedButton2();
	CButton m_Server_Sum;
	afx_msg void OnBnClickedChkDownUpTo();
	afx_msg void OnBnClickedButton3();
	CButton m_Auto_mode_Sum;
	afx_msg void OnBnClickedChkAutoModeUpTo();
	//Auto_
	afx_msg void Auto_WriteNumberToFileOff();
	afx_msg void Auto_WriteNumberToFileon();
	afx_msg void OnBnClickedButton4();

private:
	DlgConfigSetting* m_DlgConfigSetting;
	//DlgConfigSetting
public:
	CButton m_bChkSynServerTo;
	afx_msg void OnBnClickedChkAsyncServerTo();
	afx_msg void OnBnClickedChkSynServerTo();
	CButton m_bChk_Ayns_checkBoxState;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnEnChangeEditLogSettingStack();
	CEdit m_edit_Log_Stack;
	CEdit m_edit_CataLogue_Stack;
	afx_msg void OnEnChangeEditCatalogueSettingStack();
	afx_msg void OnBnClickedBtnPathPatcherEdit();
	CButton m_editConfigSettingDFS;
};
