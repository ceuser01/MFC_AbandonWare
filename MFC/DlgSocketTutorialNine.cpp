// DlgSocketTutorialNine.cpp: 구현 파일
//

#include "pch.h"
#include "MFC.h"
#include "afxdialogex.h"
#include "DlgSocketTutorialNine.h"

#include "FileProcFun.h"

#define X_SIZE 5000

//스타틱 영역
SOCKET static skt; //skt식별자
wchar_t static str_uni[256] = { 0, }; //출력 전용 로고 유니코드
 //캐릭터형 데이터다.
char static x_compare[5000] = "Hello";// = recv로 나오는 비교 데이터다. 나중에 교정해야한다.
char static strMultibyte_x[256] = { 0, }; //멀티바이트 변환 전용 heap데이터다 미리 저장한다.
char static c_data[5000] = "";//recv로 올 데이터다. heap영역으로 5000 Size정도 가져와 줘야한다.
/// /////////////////// 파일 파싱 애뮬레이터///

CString static strpath;
WIN32_FIND_DATA static filedata; //파일 데이터 스트럭쳐.
char static* c_p_ReadData;
wchar_t static* str_p_Unicode;
/// /////////////////// 파일 파싱 애뮬레이터///
//heap
CString Welcome_data;
int data_lost;
#pragma warning(disable: 4996)
#include <stdio.h>
#include <windows.h>
#include <string.h>//void형 기호의 체계 어렌이지 함수
#include <stdlib.h> // malloc, free 함수가 선언된 헤더 파일
#include <iostream>
#include <string.h>    // memset 함수가 선언된 헤더 파일
#pragma comment(lib, "Ws2_32.lib")
#include <iostream>
#include <string>
#include <map>
#include <io.h>


#include <stdio.h>
#include <iostream>
#include <windows.h> 
#pragma comment (lib,"ws2_32.lib") // 윈속 라이브러리 링크
#include <iostream>
#include <winsock2.h>
#include <thread> //멀티쓰레드를 사용하기위한!!!
using namespace std;

#define PACKET_SIZE 1024



void proc_recv() {
	char buffer[PACKET_SIZE] = {}; //char 생성
	string cmd; //string 생성
	while (!WSAGetLastError()) {
		ZeroMemory(&buffer, PACKET_SIZE); //buffer 비우기
		recv(skt, buffer, PACKET_SIZE, 0); //데이터받아오기
		cmd = buffer; //buffer의값이 cmd에 들어갑니다
		if (cmd == "hi") break; //cmd의값이 "exit"일경우 데이터받아오기'만' 종료
		cout << "받은 메세지: " << buffer << endl;
	}
}

char static msg[PACKET_SIZE] = { 0 };

STACK_X DBVMAPI3(LPVOID lpParam)
{

#include <iostream>
#include <winsock2.h>
#include <thread>
	using namespace std;

#define PACKET_SIZE 1024

	WSADATA wsa;




	WSAStartup(MAKEWORD(2, 2), &wsa); //Windows 소켓 구현의 세부 정보를 수신하는 WSADATA 데이터 구조에 대한 포인터입니다.

	skt = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8484);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	while (1) {
		if (!connect(skt, (SOCKADDR*)&addr, sizeof(addr))) break;
	}
	thread proc1(proc_recv);


	while (!WSAGetLastError()) {
		cin >> msg;


		send(skt, msg, strlen(msg), 0);
	}
	proc1.join();
	closesocket(skt);
	WSACleanup();
	return 0;
}



// DlgSocketTutorialNine 대화 상자

IMPLEMENT_DYNAMIC(DlgSocketTutorialNine, CDialogEx)

DlgSocketTutorialNine::DlgSocketTutorialNine(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SOCKET_SERIAL, pParent)
{

}

DlgSocketTutorialNine::~DlgSocketTutorialNine()
{
}

void DlgSocketTutorialNine::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, Edit_Packet_Data);
	DDX_Control(pDX, IDC_EDIT2, edit_server_log1);
	DDX_Control(pDX, IDC_EDIT3, edit_server_log2);
	DDX_Control(pDX, IDC_PACKET_DATA_LOG, PacktData_log);
}


BEGIN_MESSAGE_MAP(DlgSocketTutorialNine, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgSocketTutorialNine::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DlgSocketTutorialNine::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &DlgSocketTutorialNine::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON4, &DlgSocketTutorialNine::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT2, &DlgSocketTutorialNine::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &DlgSocketTutorialNine::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_PacketLogSave, &DlgSocketTutorialNine::OnBnClickedPacketlogsave)
END_MESSAGE_MAP()


// DlgSocketTutorialNine 메시지 처리기




STACK_X StartServerTh(LPVOID Clih) {


disable: //C++문법에 위배되어서 지울부분
	
	Sleep(1);
	int closeuserh = 0;
	int* copys3;
	closeuserh = (int)Clih;
	HANDLE THIDServer2 = 0;
	copys3 = (int*)closeuserh;
	HANDLE filedbvmx = 0;

	int dumpmem2 = 0;
	int* dumpmem3 = 0;
	memset(&c_data, 0, (int)3000); //Size
	dumpmem2 = (int)c_data;
	dumpmem3 = (int*)dumpmem2;
	data_lost = recv(closeuserh, c_data, (int)1000, 0);

	if (data_lost == (int)-1) {
	overbufret: //C++문법에 위배되어서 지울부분
		//Sleep(10000000);//많은 사용자 종료시 락을 걸어야한다 WringLevel5
		closesocket(closeuserh);
		printf("종료\n");
		return 0;

	}

	if (*c_data == *x_compare) {
		printf("Welcome .일치 합니다.\n");
		strcpy_s(strMultibyte_x, 256, (char*)x_compare);
		int nLen = MultiByteToWideChar(CP_ACP, 0, x_compare, strlen(x_compare), NULL, NULL);

		MultiByteToWideChar(CP_ACP, 0, x_compare, strlen(x_compare), str_uni, nLen);
		Welcome_data = L"Welcome"; 		
		goto disable; //C++문법에 위배되어서 지울부분

		return 0;
	}
	Welcome_data = L"Not Welcome"; 	
	printf("일치하지 않습니다.\n");

	goto disable; //C++문법에 위배되어서 지울부분

}



STACK_X ServerMain(LPVOID lpParam)
{
	HANDLE THIDServer;
	WSADATA wsa;
	SOCKADDR_IN ArrSocket = {};
	SOCKADDR_IN UserSocketC = {};
	int socketAccount = 0; //순간 기억장치  //heap으로 나중에 바꿔야한다.
	int pathcloseh = 0;
	int* p_s;
	int static* AccountList = 0;
	int static AccountListSize = 5000;
	int static port = 0;
	int short static htonldata = 0;
	int short static ShortPortdata = 0;

	AccountList = (int*)malloc(sizeof(int) * AccountListSize / 4); //할당
	memset(AccountList, 0, AccountListSize);
	port = 8484;
	printf("[%d]포트가  입력 되었습니다.\n", port);
	WSAStartup(MAKEWORD(2, 2), &wsa); //Windows 소켓 구현의 세부 정보를 수신하는 WSADATA 데이터 구조에 대한 포인터입니다.
	socketAccount = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); //1,2,6
	printf("[%d]포트가  소캣 데이터.\n", socketAccount);
	ArrSocket.sin_family = AF_INET;
	ArrSocket.sin_port = htons(port);
	ArrSocket.sin_addr.s_addr = htonl(INADDR_ANY);
	htonldata = ArrSocket.sin_addr.s_addr;
	ShortPortdata = ArrSocket.sin_port;
	bind(socketAccount, (SOCKADDR*)&ArrSocket, sizeof(ArrSocket));
	listen(socketAccount, SOMAXCONN);

	while (true) {
		pathcloseh = accept(socketAccount, 0, 0);
		p_s = (int*)pathcloseh;
		ThreadProcSocket::First_CreateThread_Collector(6000, StartServerTh, *&p_s); //쓰레드 사이즈를 더 많이 만든다.
	}
	return 0;
}

int static serverdebugcount;
HANDLE static h_server_th[1];
DWORD static server_thid;

void DlgSocketTutorialNine::Server_listen() { //서버 리스너 형성
	int* p_s;
	ThreadProcSocket::First_CreateThread_Collector(9000, ServerMain, *&p_s);
}

int static clientdebugcount;
HANDLE static h_client_th[1];
DWORD static client_thid;
void DlgSocketTutorialNine::Client_Con() {

	int* p_s;
	ThreadProcSocket::First_CreateThread_Collector(9000, DBVMAPI3, *&p_s);

}


void DlgSocketTutorialNine::OnBnClickedButton1() //서버 소캣 형성
{
	Server_listen();
}


void DlgSocketTutorialNine::OnBnClickedButton2()
{
	Client_Con();
}


void DlgSocketTutorialNine::StartText()
{
	Edit_Packet_Data.SetWindowTextW(L"Hello");
}

void DlgSocketTutorialNine::OnEnChangeEdit1()
{
	Edit_Packet_Data.GetWindowTextW(packet_data1);
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void DlgSocketTutorialNine::UnlimitedFun() { //패킷 데이터 보내고, 스트링 센드 함수
	int nLen2 = WideCharToMultiByte(CP_ACP, 0, packet_data1, -1, NULL, 0, NULL, NULL);

	char* pMultibyte2 = new char[nLen2 + SAFETY];//여분연산 
	memset(pMultibyte2, 0x00, (nLen2) * sizeof(char));
	WideCharToMultiByte(CP_ACP, 0, packet_data1, -1, pMultibyte2, nLen2, NULL, NULL);
	send(skt, pMultibyte2, strlen(pMultibyte2), NULL);
	Sleep(20);
	edit_server_log1.SetWindowTextW(Welcome_data);
}


void DlgSocketTutorialNine::OnBnClickedButton4()
{
	UnlimitedFun();
}


void DlgSocketTutorialNine::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void DlgSocketTutorialNine::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

//CString test_t;
void DlgSocketTutorialNine::OnBnClickedPacketlogsave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//PacktData_log.WindowGet

	printf("TestPacketDataDumpSystem.\n");
	HANDLE hFile; //Heap영역의 hFile이다.
	//PacketData
	//FIleOpenInPut.GetWindowTextW(strpath);
	//edit_server_log2.GetWindowTextW(strpath);
	PacktData_log.GetWindowTextW(strpath);
	FileProcFun::Fun_Save_Dir(strpath, str_uni);

	printf("디버그 스트럭처 타입은 유니코드 인지 확인 합니다. [%ws]\n", strpath);
	FileProcFun::Fun_Find_Dir_size(strpath, &filedata);

	FileProcFun::Fun_IsFileExist(strpath, &hFile); //디스크 캐싱을 CreatFIlea로 진행 합니다.
	FileProcFun::Fun_Read_Dir(*&c_p_ReadData, filedata, &hFile, *&str_p_Unicode);
	//캐싱 된 데이터를 c_p포인터 ReadData에 담고, str_p_Unicode에 변환 된 유니코드 데이터를 담는다.
	//포인터로 매개변수로 운반을 한 이유는 CharRead디스크 파서가 진행 된 데이터와,
	//유니코드 데이터가 담기는데 해당 데이터를 디스터브를 하기 위한 위함이다.
	//malloc,new로 디스크로 파싱 된 데이터가 담기게 될 경우 디스터브를 안 할 경우 메모리 누수가 발생되기에
	//디스크 파싱시 new연산자로 적절한 공간 할당 후 디스터브를 할 재귀 데이터를 담을 준비를 해야한다.
	printf("해당 경로에서 디스크 파싱 된 유니코드 데이터는 [%ws] 입니다.\n", str_p_Unicode);
	edit_server_log2.SetWindowTextW(str_p_Unicode);
	
}
