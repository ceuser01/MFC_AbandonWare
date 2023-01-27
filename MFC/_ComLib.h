#pragma once

//#define	StartCursor()		SetCapture(); BeginWaitCursor()
//#define	EndCursor()			EndWaitCursor(); ReleaseCapture()

/////////////////////////////////////////////////////////////////////////////
//	Format to CString
// ==========================================================================
inline CString FormatStr(const TCHAR* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	CString sTemp;
	sTemp.FormatV(fmt, args);
	va_end(args);
	//
	return (sTemp);
}


/////////////////////////////////////////////////////////////////////////////
//	해당시간 동안 Wait
// ==========================================================================
inline void _WAIT_TIME_(int iMiliSecond)
{
	MSG msg;

	ULONGLONG uTickStart = GetTickCount64();

	while ((GetTickCount64() - uTickStart) < iMiliSecond)
	{
		if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}

		Sleep(1);
	}
}



#define WM_LOG_MSG				WM_USER + 9999
#define WM_LOG_ERR				WM_USER + 9998
#define WM_LOG_UPLOAD_CNT		WM_USER + 9997
#define WM_LOG_SOLACE_DEBUG		WM_USER + 9996
#define	WM_POPUP_ALARM			WM_USER + 306

inline void _LOG_(int nLogType, bool bDisplayFlag, ULONGLONG uSEQ, const TCHAR* fmt, ...)
{
	try
	{
		CString strTemp = _T("");
	//jwelee
		//strTemp.Format(_T("%s,%I64u,"), GetLogTypeStr(nLogType), uSEQ);

		va_list args;
		va_start(args, fmt);
		strTemp.AppendFormatV(fmt, args);
		va_end(args);

		CWinApp* pWin = AfxGetApp();
		CWnd* pWnd = pWin->GetMainWnd();
		if (pWnd->GetSafeHwnd()) {
			//if (nLogType == _LOG_ERROR_ || nLogType == _LOG_WARNING_)
			if (nLogType == _LOG_ERROR_)
			{
				SendMessage(pWnd->m_hWnd, WM_LOG_ERR, (WPARAM)bDisplayFlag, (LPARAM)(LPCTSTR)strTemp);
				//SendMessage(pWnd->m_hWnd, WM_LOG_ERR, (WPARAM)bDisplayFlag, (LPARAM)(LPCTSTR)strTemp.Left(1000).GetString());
			}
			else if (nLogType == _LOG_SOLACE_DEBUG_)
			{
				SendMessage(pWnd->m_hWnd, WM_LOG_SOLACE_DEBUG, (WPARAM)bDisplayFlag, (LPARAM)(LPCTSTR)strTemp);
			}
			else
			{
				SendMessage(pWnd->m_hWnd, WM_LOG_MSG, (WPARAM)bDisplayFlag, (LPARAM)(LPCTSTR)strTemp.Left(1000).GetString());
			}
		}
	}
	catch (...)
	{
		//_LOG_(nLogType, true, uSEQ, _T("_LOG_() catch(%d:%s)"), GetLastError(), GetLastErrorString());
	}
}

inline void _LOG_(int nLogType, ULONGLONG uSolaceTotalCount, const TCHAR* fmt, ...)
{
	try
	{
		CString strTemp = _T("");
		//strTemp.Format(_T("%s,"), GetLogTypeStr(nLogType));

		va_list args;
		va_start(args, fmt);
		strTemp.AppendFormatV(fmt, args);
		va_end(args);

		CWinApp* pWin = AfxGetApp();
		CWnd* pWnd = pWin->GetMainWnd();
		if (pWnd->GetSafeHwnd())
		{
			if (nLogType == _LOG_UPLOAD_CNT)
			{
				SendMessage(pWnd->m_hWnd, WM_LOG_UPLOAD_CNT, (WPARAM)uSolaceTotalCount, (LPARAM)(LPCTSTR)strTemp.Left(1000).GetString());
			}
		}
	}
	catch (...)
	{
		//_LOG_(nLogType, true, uSEQ, _T("_LOG_() catch(%d:%s)"), GetLastError(), GetLastErrorString());
	}
}


inline CString GetPrivateProfileStr(CString strAppName, CString strKeyName, CString strDefault, CString strFileName, BOOL bTrim = TRUE)
{
	TCHAR szBuf[MAX_PATH] = { 0, };

	GetPrivateProfileString(strAppName, strKeyName, strDefault, szBuf, MAX_PATH, strFileName);

	//return szBuf;

	CString str = _T("");
	str.Format(_T("%s"), szBuf);
	//jwlee 
	//if (bTrim) str.Replace(" ", "");

	return str;
}


inline CString CurrTimeToString()
{
	CString str = _T("");

	SYSTEMTIME time;
	::GetLocalTime(&time);

	//str.Format(_T("%04d-%02d-%02d %02d:%02d:%02d.%03d")
	str.Format(_T("%04d%02d%02d%02d%02d%02d%03d")
		, time.wYear, time.wMonth, time.wDay
		, time.wHour, time.wMinute, time.wSecond, time.wMilliseconds
	);

	return str;
}

inline CString CurrTimeToString(int nDiffDay, int nDiffHour, int nDiffMin, int nDiffSec)
{
	CString str = _T("");

	CTime dtTime = CTime::GetCurrentTime() + CTimeSpan(nDiffDay, nDiffHour, nDiffMin, nDiffSec);
	str.Format(_T("%04d%02d%02d%02d%02d%02d%03d"),
		dtTime.GetYear(), dtTime.GetMonth(), dtTime.GetDay(),
		dtTime.GetHour(), dtTime.GetMinute(), dtTime.GetSecond(), 0
	);

	return str;
}

inline CString CTimeToString(CTime dtTime)
{
	CString str = _T("");
	str.Format(_T("%04d-%02d-%02d %02d:%02d:%02d"),
		dtTime.GetYear(), dtTime.GetMonth(), dtTime.GetDay(),
		dtTime.GetHour(), dtTime.GetMinute(), dtTime.GetSecond()
	);

	return str;
}

inline CTime StringToCTime(const CString strTime)
{
	COleDateTime dt;

	//dtTimecookie.Format(_T("%Y-%m-%d %H:%M:%S"));
	dt.ParseDateTime(strTime);

	int yy = dt.GetYear();
	int mm = dt.GetMonth();
	int dd = dt.GetDay();
	int hr = dt.GetHour();
	int min = dt.GetMinute();
	int sec = dt.GetSecond();

	CTime dtTime(yy, mm, dd, hr, min, sec);
	return dtTime;
}

inline CString GetTime_DiffMin(CTime dtBaseTime, int nDiffMin)
{
	CString strTime = _T("");

	CTime time = dtBaseTime - CTimeSpan(0, 0, nDiffMin, 0);

	strTime.Format(_T("%04d%02d%02d%02d%02d%02d%03d")
		, time.GetYear(), time.GetMonth(), time.GetDay()
		, time.GetHour(), time.GetMinute(), time.GetSecond(), 0
	);

	return strTime;
}


inline CString GetLastErrorString(DWORD err = 0)
{
	LPVOID lpMsgBuf = NULL;
	TCHAR szErrString[BUFSIZ] = { 0, };

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		((err == 0) ? GetLastError() : err),
		//0, // Default Language	//MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
		(LPTSTR)&lpMsgBuf,
		0,
		NULL) == 0)
	{
		_stprintf_s(szErrString, BUFSIZ, _T("Unknown Error (%d)"), GetLastError());
		lpMsgBuf = NULL;
	}
	else
	{
		_stprintf_s(szErrString, BUFSIZ, _T("(%s)"), (TCHAR*)lpMsgBuf);
	}

	if (lpMsgBuf) LocalFree(lpMsgBuf);

	return szErrString;
};

