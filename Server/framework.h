#pragma once
#include<iostream>
#include <conio.h> //_getch가 포함되어있는 헤더
#include <afxrich.h>
#include <afxcmn.h> // CListCtrl을 사용할 경우 추가
#include <wininet.h>
#include  "ThreadProcSocket.h"
#include "runServer.h"
#include "synSocketServer.h"
#include "ConsoleController.h"
#include "FileProcFun.h"
#include  "InTerrupt.h"
#include  "ConversionLib.h"
#include "DlgConfigSetting.h"
//mini
#pragma once

#ifndef PCH_H
#define PCH_H

#ifdef _DEBUG
#define _DEBUG_WAS_DEFINED
#undef _DEBUG
#define NDEBUG
#endif

// -- Windows and MFC Inclusions --

#include "afxwin.h"
#include "afx.h"
#include "framework.h"
#include <Windows.h>

// -- Project Inclusions --
#include <xxxxx.h>

#if defined(_AFXEXT) && defined(__cplusplus)
#include <afxcoll.h>
#endif
#endif //PCH_H
#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 일부 CString 생성자는 명시적으로 선언됩니다.

// MFC의 공통 부분과 무시 가능한 경고 메시지에 대한 숨기기를 해제합니다.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 핵심 및 표준 구성 요소입니다.
#include <afxext.h>         // MFC 확장입니다.


#include <afxdisp.h>        // MFC 자동화 클래스입니다.

#include "afxrich.h"

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 공용 컨트롤에 대한 MFC 지원입니다.
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // Windows 공용 컨트롤에 대한 MFC 지원입니다.
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC의 리본 및 컨트롤 막대 지원




//아래거 안넣으면 콤보박스가 실행이 안됨.


#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")

#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif



