// ComplexLibWebSyncDlg.h: 헤더 파일
//

#pragma once


// CComplexLibWebSyncDlg 대화 상자 클래스 정의
class CComplexLibWebSyncDlg : public CDialogEx {
public:
    // RWX 권한으로 할당된 큰 메모리 포인터 (빅 포인터)
 // 이 포인터는 프로그램의 복잡한 처리를 위해 예외처리, 후속 처리 및 코드 연계에 사용됩니다.
 // 단, 한 번 설정되면 프로그램 실행 동안 변경되지 않으며,
 // 복잡성이 증가할 수 있지만, 필요한 예외처리 및 처리 로직에 대응하기 위해 사용됩니다.
 // 정적 멤버 변수 선언
    static char* pchBigPointer; //중요도:MAX
    // 표준 생성자
    CComplexLibWebSyncDlg(CWnd* pParent = nullptr);

    // 대화 상자 데이터
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_COMPLEXLIBWEBSYNC_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV 지원

    HICON m_hIcon;

    // 생성된 메시지 맵 함수
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()

 
}; 
