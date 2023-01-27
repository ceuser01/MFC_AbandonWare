// DlgFileOpenTutorialFirst.cpp: 구현 파일
//

#include "pch.h"
#include "MFC.h"
#include "afxdialogex.h"
#include "DlgFileOpenTutorialFirst.h"


//Test인클루드//
#include <windows.h>
#include <iostream>

#include <cstringt.h>


IMPLEMENT_DYNAMIC(DlgFileOpenTutorialFirst, CDialogEx)

DlgFileOpenTutorialFirst::DlgFileOpenTutorialFirst(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_DLG_FILEOPEN_1, pParent)
{

}

DlgFileOpenTutorialFirst::~DlgFileOpenTutorialFirst()
{
}

void DlgFileOpenTutorialFirst::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_FILEDATA_INPUT, FIleOpenOutPut);
	DDX_Control(pDX, IDC_EDIT_NAME_INPUT, FIleOpenInPut);

}


BEGIN_MESSAGE_MAP(DlgFileOpenTutorialFirst, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgFileOpenTutorialFirst::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgFileOpenTutorialFirst::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_EDIT_FILEOPEN_ON, &DlgFileOpenTutorialFirst::OnBnClickedEditFileopenOn)//1 파일 디파인더
	ON_BN_CLICKED(IDC_EDIT_FILEOPEN_SAVE, &DlgFileOpenTutorialFirst::OnBnClickedEditFileopenSave)
	ON_BN_CLICKED(IDC_EDIT_FILEOPEN_CLOSE, &DlgFileOpenTutorialFirst::OnBnClickedEditFileopenClose)
	ON_EN_CHANGE(IDC_EDIT_FILEDATA_INPUT, &DlgFileOpenTutorialFirst::OnEnChangeEditFiledataInput)
	ON_EN_CHANGE(IDC_EDIT_NAME_INPUT, &DlgFileOpenTutorialFirst::OnEnChangeEditNameInput)
	ON_EN_CHANGE(IDC_EDIT_FILEDATA_OUTPUT, &DlgFileOpenTutorialFirst::OnEnChangeEditFiledataOutput)
END_MESSAGE_MAP()


// DlgFileOpenTutorialFirst 메시지 처리기


void DlgFileOpenTutorialFirst::OnBnClickedFileOpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void DlgFileOpenTutorialFirst::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}



void DlgFileOpenTutorialFirst::FileOn(){
	HANDLE hFile;
	InTerrupt::StruectureCheckSumFirst(*&switch_on_off, str_p_Unicode, c_p_ReadData); //생성된 메모리를 디스터브 하는 함수이다.
	FIleOpenInPut.GetWindowTextW(strpath);
	FileProcFun::Fun_Find_Dir_size(strpath, &filedata);//strpath의 경로 안에 filedata의 스트럭처 데이터를 집어넣는다. size와 잡다한 파일 날짜 등의 데이터를 가져온다.
	FileProcFun::Fun_IsFileExist(strpath, &hFile);//strpath의 경로 안에 hFile에 hFile 크레이트파일아 데이터를 가져온다.
	//경로와 hFile핸들 정보를 가져온다. 핸들 정보는 &로 말아서 포인터처럼 리턴할떄 재반환 하게 준비한다. 
	FileProcFun::Fun_Read_Dir(*&c_p_ReadData, filedata, &hFile, *&str_p_Unicode);
	//해당 경로의 데이터의 정보를 메모리에 올리고 캐싱한다. 
	InTerrupt::intTrue(*&switch_on_off); //비활성화 스위치 On
}


void DlgFileOpenTutorialFirst::OnBnClickedEditFileopenOn()
{
	FileOn();
	FIleOpenOutPut.SetWindowTextW(str_p_Unicode); 	//free(str_p_Unicode); //디버깅 메세지End
}

void DlgFileOpenTutorialFirst::OnBnClickedEditFileopenSave()
{
	FIleOpenOutPut.GetWindowTextW(str_copy);

	FileProcFun::Fun_Save_Dir(strpath, str_copy);
}


void DlgFileOpenTutorialFirst::OnBnClickedEditFileopenClose()
{
	cout << "OnBnClickedEditFileopenClose" << endl;
}


void DlgFileOpenTutorialFirst::OnEnChangeEditFiledataInput()
{

	cout << "OnEnChangeEditFiledataInput" << endl;

}


void DlgFileOpenTutorialFirst::OnEnChangeEditNameInput()
{
}


void DlgFileOpenTutorialFirst::OnEnChangeEditFiledataOutput()
{
}
