// DlgThreadTutorialEight.cpp: 구현 파일
//

#include "pch.h"
#include "MFC.h"
#include "afxdialogex.h"
#include "DlgThreadTutorialEight.h"


// DlgThreadTutorialEight 대화 상자

IMPLEMENT_DYNAMIC(DlgThreadTutorialEight, CDialogEx)

DlgThreadTutorialEight::DlgThreadTutorialEight(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_THREAD_LOCK, pParent)
{

}

DlgThreadTutorialEight::~DlgThreadTutorialEight()
{
}

void DlgThreadTutorialEight::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, x_Thread_log);
}


BEGIN_MESSAGE_MAP(DlgThreadTutorialEight, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgThreadTutorialEight::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DlgThreadTutorialEight::OnBnClickedButton2)
END_MESSAGE_MAP()


// DlgThreadTutorialEight 메시지 처리기

#define THREADCOUNT 2
HANDLE static ghSemaphore;
#define MAX_SEM_COUNT 10
int static debug_count1 = 0;
int static debug_count2 = 0;
CString Thread_String;
DWORD WINAPI DBVMAPI(LPVOID lpParam)
{

	UNREFERENCED_PARAMETER(lpParam);
	DWORD dwWaitResult;
	BOOL bContinue = TRUE;
	while (bContinue)
	{
		// Try to enter the semaphore gate.
		dwWaitResult = WaitForSingleObject(
			ghSemaphore,   // handle to semaphore
			0L);           // zero-second time-out interval
		switch (dwWaitResult)
		{
			// The semaphore object was signaled.
		case WAIT_OBJECT_0:

			while (debug_count2 < 30) {

				debug_count2++;
				debug_count1 += debug_count2;
				//exit(0);
			}
	
			bContinue = FALSE;
			//	Sleep(5);
				// Release the semaphore when task is finished
			if (!ReleaseSemaphore(
				ghSemaphore,  // handle to semaphore
				1,            // increase count by one
				NULL))       // not interested in previous count
			{

				printf("ReleaseSemaphore error: %d\n", GetLastError());
			}
			break;
			// The semaphore was nonsignaled, so a time-out occurred.
		case WAIT_TIMEOUT:
			printf("Thread %d: wait timed out\n", GetCurrentThreadId());
			break;
		}
	}
	return TRUE;
}
void DlgThreadTutorialEight::ThreadFun1()
{
	HANDLE static aThread[THREADCOUNT];
	DWORD static ThreadID;
	int static debugcount;
	ghSemaphore = CreateSemaphore(
		NULL,           // default security attributes
		MAX_SEM_COUNT,  // initial count
		MAX_SEM_COUNT,  // maximum count
		NULL);          // unnamed semaphore
	for (debugcount = 0; debugcount < THREADCOUNT; debugcount++)
	{
		aThread[debugcount] = CreateThread(
			0,       //Fret
			900,          // Stacksize
			(LPTHREAD_START_ROUTINE)DBVMAPI,
			NULL,       // no thread function arguments
			0,          // default creation flags
			&ThreadID); // receive thread identifier
	}
	// closehmain = CreateThread(0, sizes, apiname, *&bigpointers, NULL, 0);
	// Wait for all threads to terminate
	WaitForMultipleObjects(THREADCOUNT, aThread, TRUE, INFINITE);

	Thread_String.Format(_T("%d"), debug_count1);

	//x_guiret.SetWindowTextW((LPCTSTR)Threadstr1+ "쓰레드 카운팅이 진행 되었습니다.");
	x_Thread_log.SetWindowTextW(Thread_String + L"쓰레드 카운팅이 진행 되었습니다.");

	for (debugcount = 0; debugcount < THREADCOUNT; debugcount++)
		CloseHandle(aThread[debugcount]);
	CloseHandle(ghSemaphore);
	if (debug_count1 == THREADCOUNT) {
		debug_count1 = 0;//초기화
		debugcount = 0;
	}
}


void DlgThreadTutorialEight::ThreadFun2(){
}

void DlgThreadTutorialEight::OnBnClickedButton1()
{
	ThreadFun1();
}


void DlgThreadTutorialEight::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MessageBox(L"미완성 입니다.");
}
