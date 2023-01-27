#pragma once
#include "afxdialogex.h"

using namespace std;
// DlgFileOpenTutorialFirst 대화 상자

class DlgFileOpenTutorialFirst : public CDialogEx
{

	DECLARE_DYNAMIC(DlgFileOpenTutorialFirst)
		//	DlgMfcMain* CDlgPopupAlarm* m_pDlgPopupAlarm;;
		//	DlgMfcMain* CDlgPopupAlarm* m_pDlgPopupAlarm;;
private:
	 CString str_copy;
	 int *switch_on_off;
	 //PointerAddress
	 wchar_t * str_p_Unicode;
	 char * c_p_ReadData;
	 //
	 WIN32_FIND_DATA  filedata; //파일 데이터 스트럭쳐.
	 CString  strpath;
public:

	DlgFileOpenTutorialFirst(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlgFileOpenTutorialFirst();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_DLG_FILEOPEN_1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFileOpen();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedEditFileopenOn();
	afx_msg void OnBnClickedEditFileopenSave();

public:
	afx_msg void FileOn();
	//void WriteLog(int nLogType, bool bDisplayFlag, ULONGLONG uSEQ, const TCHAR* fmt, ...);
	BOOL IsFileWritable(ULONGLONG uSEQ, LPCTSTR szFile);
	BOOL DlgFileOpenTutorialFirst::IsFileExist(CString sPathName, HANDLE* h);
	//BOOL DlgFileOpenTutorialFirst::FindProc_Dir(CString sPathName_x
	BOOL DlgFileOpenTutorialFirst::Find_Dir_size(CString sPathName_x, WIN32_FIND_DATA *data);
	//DlgFileOpenTutorialFirst::Read_Dir(char Read[], WIN32_FIND_DATA* data) 
	void DlgFileOpenTutorialFirst::Read_Dir(char*& Read, WIN32_FIND_DATA data , HANDLE* h, wchar_t*& strUnicode2);
	afx_msg void OnBnClickedEditFileopenClose();
	afx_msg void OnEnChangeEditFiledataInput();
	CEdit FIleOpenOutPut;
	afx_msg void OnEnChangeEditNameInput();
	CEdit FIleOpenInPut;
	void DlgFileOpenTutorialFirst::Save_Dir();



public : //filestruct

	afx_msg void OnEnChangeEditFiledataOutput();
};
