/////////////////////////////////////////////////////////////////////////////
//
//	Class Name  : CApp
//	Description : Global�� ����� ���� �� ����
//	Remark		: 
//	Create		: 
//	History		:
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <afx.h>

#include "pch.h"


#define HOME_DIR()			(theApp.HomeDir())
#define EXE_FILE_NAME()		(theApp.ExeFileName())
#define CONFIG_FILE()		(theApp.ConfigFile())

#define CONFIG()			(theApp.Config())

#define GLOBAL()			(&CGlobal::Instance())

//#define _LOG_(log_type, displayflag, seq, fmt, ...)		g_pMainDlg->WriteLog(log_type, displayflag, seq, fmt, __VA_ARGS__)


#define PROC_MAIN()			(g_pMainDlg->ProcMain())

#define PROC_SOLACE()		(g_pMainDlg->ProcSolace())
#define PROC_DFS()			(g_pMainDlg->ProcDFS())

#define PROC_REST()			(g_pMainDlg->ProcRest())

#define PROC_DB()			(g_pMainDlg->ProcDB())
#define PROC_FILE_DELETE()	(g_pMainDlg->ProcFileDelete())

class CGlobal
{
public:
	CGlobal()
	{
		Init();
	}

	~CGlobal()
	{

	}

	void Init()
	{
	}

	void Exit()
	{
	}

	static CGlobal& Instance()
	{
		static CGlobal clsGlobal;
		return clsGlobal;
	}

	// 20221101 ubslhi - Image ��� Ȯ�� ���� ó�� : ������� ����
	BOOL CheckImageJudge(CString strFileName, CString strFindJudge)
	{
		BOOL bResult = FALSE;

		strFileName.MakeUpper();

		// 20221103 ubslhi - ���� ���Ŀ� SeqNo�� ���ԵǴ� ���� �־� ��缭��� �Ľ��ؼ��� �ȵ�
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//CString strTemp = _T("");
		//CStringArray arrTemp;
		//arrTemp.RemoveAll();

		//int nSeq = 0;
		//while (1)
		//{
		//	AfxExtractSubString(strTemp, strFileName, nSeq++, '_');
		//	arrTemp.Add(strTemp);
		//	if( (strTemp.Find(_T(".JPG")) > 0 ) || (strTemp.Find(_T(".BMP")) > 0) || (strTemp.Find(_T(".PNG")) > 0) )
		//	{
		//		break;
		//	}
		//}

		////  ��˻������_�����ϻ����ð�_�鼳��ID_��RECIPE_ID_��LOT_ID_��Cell ID_��ī�޶� ��ġ_��ī�޶� ��ȣ_�ｺũ�� ��ȣ_��˻���ġ_�� �̹����������_�� �����������
		//for (nSeq = arrTemp.GetCount() - 1; nSeq > arrTemp.GetCount() - 3; nSeq--)
		//{
		//	strTemp = arrTemp.GetAt(nSeq);
		//	_LOG_(_LOG_MAIN_, false, 0, _T("CheckImageJudge -  find : %s,  file : %s"), strFindJudge, strTemp);
		//	if (strTemp.Find(strFindJudge) >= 0)
		//	{
		//		bResult = TRUE;
		//	}
		//}

		CString strTemp1 = _T("");
		CString strTemp2 = _T("");
		CString strTemp3 = _T("");

		//strTemp1.Format("%s,", strFindJudge);
		//strTemp2.Format("%s.", strFindJudge);
		//strTemp3.Format("%s_", strFindJudge);
		if ((strFileName.Find(strTemp1) > 0) || (strFileName.Find(strTemp2) > 0))
		{
			bResult = TRUE;
		}
		else if (strFileName.Find(strTemp3) > 0)
		{
			int nStartPos = 0;
			while (strFileName.Find(strTemp3, nStartPos) > 0)
			{
				int nPos = strFileName.Find(strTemp3, nStartPos);
				CString strFrontChar = strFileName.Mid(nPos - 1, 1);
				if ((strFrontChar == _T("_")) || (strFrontChar == _T(",")))
				{
					bResult = TRUE;
					break;
				}
				nStartPos = nPos + 1;
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////

		_LOG_(_LOG_MAIN_, false, 0, _T("CheckImageJudge -  Result : %d"), bResult);
		return bResult;
	}

};
