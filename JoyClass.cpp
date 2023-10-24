#include "pch.h"

static HWND hWnd_x;
int static UserNum1 = -1;

int static UserNum2 = 0;
int static iButton2 = 0;
int static pressButton2 = 0;
int static* p_copy1;
LPVOID static abandonx;

static int onoff_x = 0;

int static DebugCount = 0;
int static g_iXMin1 = 0;
int static g_iXMax1 = 0;
int static g_iYMin1 = 0;
int static g_iYMax1 = 0;

int static g_iXMin2 = 0;
int static g_iXMax2 = 0;
int static g_iYMin2 = 0;
int static g_iYMax2 = 0;

unsigned int nCO_LIST[256];
int* p_dll_ptr_x;


int UserNumCopy = 0;

static int Joy_left[JOY_MOVE_LEVEL][40];
//40은 공간 간격입니다. 제곱근이돼지요.

static int Joy_cmp1;
static int Joy_cmp2;
static int Joy_cmp3;
static int Joy_cmp4;


BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData)
{

    MONITORINFOEX MonitorInfo;
    MonitorInfo.cbSize = sizeof(MONITORINFOEX);
    GetMonitorInfo(hMonitor, &MonitorInfo);

    if (DebugCount == 1) {
        g_iXMin2 = MonitorInfo.rcMonitor.left;
        g_iXMax2 = MonitorInfo.rcMonitor.right;
        g_iYMin2 = MonitorInfo.rcMonitor.top;
        g_iYMax2 = MonitorInfo.rcMonitor.bottom;
        return TRUE;
    }
    g_iXMin1 = MonitorInfo.rcMonitor.left;
    g_iXMax1 = MonitorInfo.rcMonitor.right;
    g_iYMin1 = MonitorInfo.rcMonitor.top;
    g_iYMax1 = MonitorInfo.rcMonitor.bottom;
    DebugCount++;
    printf("[%d]", g_iXMin1);
    return TRUE;
}



LPCWSTR HwndName;// = L"AbandonWareCpp (64-bit DebugGame PCD3D_SM5) ";

static HWND hWnd;
int static member[7];



STACK_T JoyClass::Start_ShellStartUp_MonitorInfo_x(LPVOID x_po) {

    // HMONITOR static hMonitor;
    HDC hDC = GetDC(NULL);
    GetSystemMetrics(SM_CMONITORS);
    EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, (LPARAM)hDC);
    return 0;
}



STACK_T JoyClass::STOPS(LPVOID x_po) {
    int* stop = (int*)x_po;
    SendMessage(hWnd_x, WM_KEYDOWN, *stop, 0);
    Sleep(1);
    SendMessage(hWnd_x, WM_KEYUP, *stop, 0);
    return 0;
}


STACK_T JoyClass::STOPS_X(LPVOID x_po) {
    int* stop = (int*)x_po;
    int codeSleep = 0;
    while (codeSleep <= 30) {
        Sleep(1);
        SendMessage(hWnd_x, WM_KEYUP, *stop, 0);
        codeSleep++;
    }
    return 0;
}

//Mov_UP_DOWN


//Joy_dwPOV
STACK_T JoyClass::Joy_dwPOV(LPVOID x_po) {

    return 0;
}


STACK_T JoyClass::Mov_UP_DOWN_Ac(LPVOID x_po) {

    int* ptr_User_dumpMemory = (int*)x_po + 370;//User넘버 포인터 메모리에서 데이터를 받아온다.
    int UserNum = *ptr_User_dumpMemory; //User넘버 포인터 메모리에서 데이터를 받아오고 userNum의 int형 데이터에 집어넣는다.

    int* p_dll_ptr_FirstKey = reinterpret_cast<int*>(x_po) + 3002;
    int* p_dll_ptr_SecondKey = reinterpret_cast<int*>(x_po) + 3003;
    //int *p_dll_ptr_FirstKey = (int*)x_po + KEY_OFFSET_FRIST;
    int Mov_left_Ac_on_off = 0;
    int Mov_left_Ac_on_off2 = 0;

    while (true) {
        Sleep(1);

        int DataDump = Joy_left[JOY_UP_MOVE_LEVEL][UserNum];
        int DataDump2 = Joy_left[JOY_DOWN_MOVE_LEVEL][UserNum];//라이트

        if (DataDump == 1) {
            if (Mov_left_Ac_on_off == 1) {
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
                Mov_left_Ac_on_off = NULL;
            }
        }

        if (DataDump2 == 1) {
            if (Mov_left_Ac_on_off2 == 1) {
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);
                Mov_left_Ac_on_off2 = NULL;
            }
        }



        switch (DataDump) {

            // break;
        case 2:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0); Mov_left_Ac_on_off = 1;
            break;
        case 3:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0); Mov_left_Ac_on_off = 1;
            break;
        case 4:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0); Mov_left_Ac_on_off = 1;
            break;
        case 5:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0); Mov_left_Ac_on_off = 1;
            break;
        case 6:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0); Mov_left_Ac_on_off = 1;
            break;
        case 7:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0); Mov_left_Ac_on_off = 1;
            break;
        case 8:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0); Mov_left_Ac_on_off = 1;
            break;
            //   break;
        case 9:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            break;
        default:
            break;
        }

        if (DataDump != 1) {
            continue;
        }


        switch (DataDump2) {

        case 2:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0); SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0); Mov_left_Ac_on_off2 = 1;
            break;
        case 3:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0); SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0); Mov_left_Ac_on_off2 = 1;
            break;
        case 4:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0); SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0); Mov_left_Ac_on_off2 = 1;
            break;
        case 5:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0); SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0); Mov_left_Ac_on_off2 = 1;
            break;
        case 6:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0); SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0); Mov_left_Ac_on_off2 = 1;
            break;
        case 7:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0); SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0); Mov_left_Ac_on_off2 = 1;
            break;
        case 8:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0); SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0); Mov_left_Ac_on_off2 = 1;
            break;
        case 9:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0); Mov_left_Ac_on_off2 = 1;
            break;
        default:

            break;
        }
    }

}



STACK_T JoyClass::Mov_left_Ac(LPVOID x_po) {
    int Mov_left_Ac_on_off = 0;
    int Mov_left_Ac_on_off2 = 0;
    int* ptr_User_dumpMemory = (int*)x_po + 370;//User넘버 포인터 메모리에서 데이터를 받아온다.
    int UserNum = *ptr_User_dumpMemory; //User넘버 포인터 메모리에서 데이터를 받아오고 userNum의 int형 데이터에 집어넣는다.

    int* p_dll_ptr_FirstKey = reinterpret_cast<int*>(x_po) + 3000;
    int* p_dll_ptr_SecondKey = reinterpret_cast<int*>(x_po) + 3001;
    //int *p_dll_ptr_FirstKey = (int*)x_po + KEY_OFFSET_FRIST;



    while (true) {
        Sleep(1);
        int DataDump = Joy_left[JOY_LEFT_MOVE_LEVEL][UserNum];
        int DataDump2 = Joy_left[JOY_RIGHT_MOVE_LEVEL][UserNum];//라이트


        if (DataDump == 1) {
            if (Mov_left_Ac_on_off == 1) {
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
                Mov_left_Ac_on_off = NULL;
            }
        }

        if (DataDump2 == 1) {
            if (Mov_left_Ac_on_off2 == 1) {
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);
                Mov_left_Ac_on_off2 = NULL;
            }
        }
        switch (DataDump) {


        case 2:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
            Mov_left_Ac_on_off = 1;
            break;
        case 3:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
            Mov_left_Ac_on_off = 1;
            break;
        case 4:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
            Mov_left_Ac_on_off = 1;
            break;
        case 5:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
            Mov_left_Ac_on_off = 1;
            break;
        case 6:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
            Mov_left_Ac_on_off = 1;
            break;
        case 7:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
            Mov_left_Ac_on_off = 1;
            break;
        case 8:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
            Mov_left_Ac_on_off = 1;
            break;
        case 9:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Mov_left_Ac_on_off = 1;
            break;
        default:
            break;
        }

        if (DataDump != 1) {
            continue;
        }


        switch (DataDump2) {

        case 2:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);     Mov_left_Ac_on_off2 = 1;
            break;
        case 3:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);     Mov_left_Ac_on_off2 = 1;
            break;
        case 4:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);     Mov_left_Ac_on_off2 = 1;
            break;
        case 5:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);     Mov_left_Ac_on_off2 = 1;
            break;
        case 6:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);     Mov_left_Ac_on_off2 = 1;
            break;
        case 7:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);     Mov_left_Ac_on_off2 = 1;
            break;
        case 8:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);     Mov_left_Ac_on_off2 = 1;
            break;
        case 9:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            break;
        default:

            break;
        }
    }


}



STACK_T JoyClass::Mov_UP_DOWN(LPVOID x_po) {
    static int ErrorCodeSum = 0;
    int* Pointer_X = (int*)x_po;
    int* ptr_User_dumpMemory = Pointer_X + 370;//User넘버 포인터 메모리에서 데이터를 받아온다.
    int* HwndSaver = Pointer_X + 378;//User넘버 포인터 메모리에서 데이터를 받아온다.
    int UserNum = *ptr_User_dumpMemory; //User넘버 포인터 메모리에서 데이터를 받아오고 userNum의 int형 데이터에 집어넣는다.
    int* p_dll_ptr_FirstKey = nullptr;
    MMRESULT errorCode; //에러코드 발생시 비교 할 수 있게 만든 구문인데 조이스틱의 USB 휴먼 인터페이스 단자가 떨어져 나갈때 체크하기 위함이다.
    int* BigPointerCopy = reinterpret_cast<int*>(x_po) + 3000; //파서에서 읽어 온 Hwnd의 이름 (예:AbandonWareCpp (64-bit DebugGame PCD3D_SM5

    JOYINFOEX  joyinfo; //조이스틱의 객체를 저장하는 저장소이다.




    p_dll_ptr_FirstKey = p_dll_ptr_x + KEY_OFFSET_FRIST;

    printf("현재 왼쪽 연산 집중 포인터 키는[%p]입니다.", p_dll_ptr_FirstKey);

    printf("현재 왼쪽 연산 식별자 넘버는[%d]입니다.", UserNum);
    errorCode = joyGetPosEx(UserNum, &joyinfo);
    Joy_left[JOY_LEFT_SAVE][UserNum] = joyinfo.dwXpos;

    CloseHandle(CreateThread(0, 17900, Mov_UP_DOWN_Ac, *&x_po, 0, 0));


    while (true) {//메인 연산.
        Sleep(1);
        errorCode = joyGetPosEx(UserNum, &joyinfo);
        if (joyinfo.dwYpos == Joy_cmp1) {
            Joy_left[JOY_UP_MOVE_LEVEL][UserNum] = 1;
            Joy_left[JOY_DOWN_MOVE_LEVEL][UserNum] = 1;
            continue;

        }
        if (joyinfo.dwYpos == NULL) { //NULLPointer진행시 최대치로 왼쪽.
            Joy_left[JOY_UP_MOVE_LEVEL][UserNum] = 9;
            continue;
        }

        if (joyinfo.dwYpos <= Joy_cmp1 - 24000) {
            Joy_left[JOY_UP_MOVE_LEVEL][UserNum] = 8;
            continue;
        }

        if (joyinfo.dwYpos <= Joy_cmp1 - 20000) {
            Joy_left[JOY_UP_MOVE_LEVEL][UserNum] = 7;
            continue;
        }
        if (joyinfo.dwYpos <= Joy_cmp1 - 16000) {
            Joy_left[JOY_UP_MOVE_LEVEL][UserNum] = 6;
            continue;
        }
        if (joyinfo.dwYpos <= Joy_cmp1 - 12000) {
            Joy_left[JOY_UP_MOVE_LEVEL][UserNum] = 5;
            continue;
        }
        if (joyinfo.dwYpos <= Joy_cmp1 - 8000) {
            Joy_left[JOY_UP_MOVE_LEVEL][UserNum] = 4;
            continue;
        }
        if (joyinfo.dwYpos <= Joy_cmp1 - 4000) {
            Joy_left[JOY_UP_MOVE_LEVEL][UserNum] = 3;
            continue;
        }
        if (joyinfo.dwYpos <= Joy_cmp1 - 2000) {
            Joy_left[JOY_UP_MOVE_LEVEL][UserNum] = 2;
            continue;
        }


        if (joyinfo.dwYpos == 65535) {
            Joy_left[JOY_DOWN_MOVE_LEVEL][UserNum] = 9;
            continue;
        }

        if (joyinfo.dwYpos <= Joy_cmp1 + 2000) {
            Joy_left[JOY_DOWN_MOVE_LEVEL][UserNum] = 2;
            continue;
        }
        if (joyinfo.dwYpos <= Joy_cmp1 + 4000) {
            Joy_left[JOY_DOWN_MOVE_LEVEL][UserNum] = 3;
            continue;
        }
        if (joyinfo.dwYpos <= Joy_cmp1 + 8000) {
            Joy_left[JOY_DOWN_MOVE_LEVEL][UserNum] = 4;
            continue;
        }
        if (joyinfo.dwYpos <= Joy_cmp1 + 12000) {
            Joy_left[JOY_DOWN_MOVE_LEVEL][UserNum] = 5;
            continue;
        }
        if (joyinfo.dwYpos <= Joy_cmp1 + 16000) {
            Joy_left[JOY_DOWN_MOVE_LEVEL][UserNum] = 6;
            continue;
        }
        if (joyinfo.dwYpos <= Joy_cmp1 + 20000) {
            Joy_left[JOY_DOWN_MOVE_LEVEL][UserNum] = 7;
            continue;
        }
        if (joyinfo.dwYpos <= Joy_cmp1 + 24000) {
            Joy_left[JOY_DOWN_MOVE_LEVEL][UserNum] = 8;
            continue;
        }


    }
    printf("Mov_left_Ac 여기에 떨어질 리 없다고;;;..");
    Sleep(INT_MAX);


    // SendMessage(hWnd, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
    // Sleep(1);
    // SendMessage(hWnd, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
    return 0;
}


STACK_T JoyClass::Joy_Button_Twelve(LPVOID x_po) {
    static int ErrorCodeSum = 0;
    int* Pointer_X = (int*)x_po;
    int* ptr_User_dumpMemory = Pointer_X + 370;//User넘버 포인터 메모리에서 데이터를 받아온다.
    int* HwndSaver = Pointer_X + 378;//User넘버 포인터 메모리에서 데이터를 받아온다.
    int UserNum = *ptr_User_dumpMemory; //User넘버 포인터 메모리에서 데이터를 받아오고 userNum의 int형 데이터에 집어넣는다.

    int* p_dll_ptr_First = p_dll_ptr_x + KEY_OFFSET_FRIST;
    //p_dll_ptr_Second
    int* p_dll_ptr_Five1 = nullptr;
    int* p_dll_ptr_Five2 = nullptr;
    int* p_dll_ptr_Five3 = nullptr;
    int* p_dll_ptr_Five4 = nullptr;
    int* p_dll_ptr_Fourth = nullptr;
    int* p_dll_ptr_First_Dump = p_dll_ptr_First;
    int* p_dll_ptr_First_dwButtons1 = p_dll_ptr_First_Dump;
    int* p_dll_ptr_First_dwButtons2 = p_dll_ptr_First_Dump + 1;
    int* p_dll_ptr_First_dwButtons3 = p_dll_ptr_First_Dump + 2;
    int* p_dll_ptr_First_dwButtons4 = p_dll_ptr_First_Dump + 3;
    int* p_dll_ptr_First_dwButtons5 = p_dll_ptr_First_Dump + 4;
    int* p_dll_ptr_First_dwButtons6 = p_dll_ptr_First_Dump + 5;
    int* p_dll_ptr_First_dwButtons7 = p_dll_ptr_First_Dump + 6;
    int* p_dll_ptr_First_dwButtons8 = p_dll_ptr_First_Dump + 7;
    int* p_dll_ptr_First_dwButtons9 = p_dll_ptr_First_Dump + 8;
    int* p_dll_ptr_First_dwButtons10 = p_dll_ptr_First_Dump + 9;
    int* p_dll_ptr_First_dwButtons11 = p_dll_ptr_First_Dump + 10;
    int* p_dll_ptr_First_dwButtons12 = p_dll_ptr_First_Dump + 11;
    int* p_dll_ptr_Third = nullptr;
    MMRESULT errorCode; //에러코드 발생시 비교 할 수 있게 만든 구문인데 조이스틱의 USB 휴먼 인터페이스 단자가 떨어져 나갈때 체크하기 위함이다.
    int* BigPointerCopy = reinterpret_cast<int*>(x_po) + 3000; //파서에서 읽어 온 Hwnd의 이름 (예:AbandonWareCpp (64-bit DebugGame PCD3D_SM5

    JOYINFOEX  joyinfo; //조이스틱의 객체를 저장하는 저장소이다.
    p_dll_ptr_Third = p_dll_ptr_x + KEY_OFFSET_THIRD;
    int* p_dll_ptr_First_Third_Dump = p_dll_ptr_Third;
    int* p_dll_ptr_First_Pov1 = p_dll_ptr_First_Third_Dump;
    int* p_dll_ptr_First_Pov2 = p_dll_ptr_First_Third_Dump + 1;
    int* p_dll_ptr_First_Pov3 = p_dll_ptr_First_Third_Dump + 2;
    int* p_dll_ptr_First_Pov4 = p_dll_ptr_First_Third_Dump + 3;
    int* p_dll_ptr_First_Pov_onoff = 0;
    int m_dll_ptr_First_Pov_onoff = 0;

    int m_dll_ptr_First_Fourth_onoff = 0;
    int onoff_x1 = 0;

    int* p_dll_ptr_First_Fourth1 = nullptr;
    int* p_dll_ptr_First_Fourth2 = nullptr;
    int* p_dll_ptr_First_Fourth3 = nullptr;
    p_dll_ptr_Fourth = p_dll_ptr_x + KEY_OFFSET_FOURTH;
    p_dll_ptr_First_Fourth1 = p_dll_ptr_Fourth;
    p_dll_ptr_First_Fourth2 = p_dll_ptr_Fourth + 1;
    p_dll_ptr_First_Fourth3 = p_dll_ptr_Fourth + 2;
    p_dll_ptr_Five1 = p_dll_ptr_x + KEY_OFFSET_FIVE;
    p_dll_ptr_Five2 = p_dll_ptr_x + KEY_OFFSET_FIVE + 1;
    p_dll_ptr_Five3 = p_dll_ptr_x + KEY_OFFSET_FIVE + 2;
    p_dll_ptr_Five4 = p_dll_ptr_x + KEY_OFFSET_FIVE + 3;
    int* p_dll_ptr_Second = nullptr;
    int Joy_cmp1 = *p_dll_ptr_Five1;
    int Joy_cmp2 = *p_dll_ptr_Five2;
    int Joy_cmp3 = *p_dll_ptr_Five3;
    int Joy_cmp4 = *p_dll_ptr_Five4;

    p_dll_ptr_Second = p_dll_ptr_x + KEY_OFFSET_SECOND;
    int* p_dll_ptr_First_Second_Dump = p_dll_ptr_Second;
    int* p_dll_ptr_First_xy1 = p_dll_ptr_First_Second_Dump;
    while (true) {
        Sleep(1);
        joyGetPosEx(UserNum, &joyinfo);

        if (joyinfo.dwPOV == KEY_POV_NOAML) {
            if (m_dll_ptr_First_Pov_onoff == 1) {
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov1, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov2, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov3, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov4, 0);
                Sleep(1);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov1, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov2, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov3, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov4, 0);
                m_dll_ptr_First_Pov_onoff = 0;
            }
        }

        switch (joyinfo.dwPOV)//미니멀 스위처 로직
        {

        case KEY_POV_LEFT:
            m_dll_ptr_First_Pov_onoff = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_Pov1, 0);
            break;
        case KEY_POV_RIGHT:
            m_dll_ptr_First_Pov_onoff = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_Pov2, 0);
            break;
        case KEY_POV_UP:
            m_dll_ptr_First_Pov_onoff = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_Pov3, 0);
            break;
        case KEY_POV_DOWN:
            m_dll_ptr_First_Pov_onoff = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_Pov4, 0);
            break;

        }

        //미니멀 버튼 휠 로직
        if (joyinfo.dwButtons == NULL) {
            if (m_dll_ptr_First_Fourth_onoff == 1) {
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Fourth1, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Fourth2, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Fourth3, 0);
                Sleep(1);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Fourth1, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Fourth2, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Fourth3, 0);
                m_dll_ptr_First_Fourth_onoff = 0;
            }
        }
        switch (joyinfo.dwButtons)//dwbutton
        {
        case KEY_DW_LEFT_KEY:
            m_dll_ptr_First_Fourth_onoff = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_Fourth1, 0);
            break;
        case KEY_DW_DOWN_KEY:
            m_dll_ptr_First_Fourth_onoff = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_Fourth2, 0);
            break;
        case KEY_DW_RIGHT_KEY:
            m_dll_ptr_First_Fourth_onoff = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_Fourth3, 0);
            break;
        }

        if (joyinfo.dwXpos <= Joy_cmp1 + Joy_cmp1) { //왼쪽으로 증감됨

            if (joyinfo.dwXpos >= Joy_cmp1 - Joy_cmp1) { //왼쪽으로 증감됨

                if (onoff_x1 == 1) {
                    // SendMessage(hWnd, WM_KEYUP, *p_dll_ptr_First_xy1, 0); //왼쪽
                    CloseHandle(CreateThread(0, 200, STOPS_X, *&p_dll_ptr_First_xy1, 0, 0));
                    //    SendMessage(hWnd, WM_KEYUP, *p_dll_ptr_First_xy2, 0);
                    onoff_x1 = 0;
                    printf("스톱 dwXpos\n");
                }
            }
        }
    }
}



STACK_T JoyClass::Mov_Left_Right(LPVOID x_po) {
    static int ErrorCodeSum = 0;
    int* Pointer_X = (int*)x_po;
    int* ptr_User_dumpMemory = Pointer_X + 370;//User넘버 포인터 메모리에서 데이터를 받아온다.
    int* HwndSaver = Pointer_X + 378;//User넘버 포인터 메모리에서 데이터를 받아온다.
    int UserNum = *ptr_User_dumpMemory; //User넘버 포인터 메모리에서 데이터를 받아오고 userNum의 int형 데이터에 집어넣는다.

    int* p_dll_ptr_FirstKey = nullptr;
    MMRESULT errorCode; //에러코드 발생시 비교 할 수 있게 만든 구문인데 조이스틱의 USB 휴먼 인터페이스 단자가 떨어져 나갈때 체크하기 위함이다.
    int* BigPointerCopy = reinterpret_cast<int*>(x_po) + 3000; //파서에서 읽어 온 Hwnd의 이름 (예:AbandonWareCpp (64-bit DebugGame PCD3D_SM5

    JOYINFOEX  joyinfo; //조이스틱의 객체를 저장하는 저장소이다.




    p_dll_ptr_FirstKey = p_dll_ptr_x + KEY_OFFSET_FRIST;

    printf("현재 왼쪽 연산 집중 포인터 키는[%p]입니다.", p_dll_ptr_FirstKey);

    printf("현재 왼쪽 연산 식별자 넘버는[%d]입니다.", UserNum);
    errorCode = joyGetPosEx(UserNum, &joyinfo);
    Joy_left[JOY_LEFT_SAVE][UserNum] = joyinfo.dwXpos;

    CloseHandle(CreateThread(0, 17900, Mov_left_Ac, *&x_po, 0, 0));


    while (true) {//메인 연산.
        Sleep(1);
        errorCode = joyGetPosEx(UserNum, &joyinfo);
        if (joyinfo.dwXpos == Joy_cmp1) {
            Joy_left[JOY_LEFT_MOVE_LEVEL][UserNum] = 1;
            Joy_left[JOY_RIGHT_MOVE_LEVEL][UserNum] = 1;
            //  Joy_left[JOY_RIGHT_MOVE_LEVEL][UserNum] = 1;
            continue;

        }
        if (joyinfo.dwXpos == NULL) { //NULLPointer진행시 최대치로 왼쪽.
            Joy_left[JOY_LEFT_MOVE_LEVEL][UserNum] = 9;
            continue;
        }

        if (joyinfo.dwXpos <= Joy_cmp1 - 24000) {
            Joy_left[JOY_LEFT_MOVE_LEVEL][UserNum] = 8;
            continue;
        }

        if (joyinfo.dwXpos <= Joy_cmp1 - 20000) {
            Joy_left[JOY_LEFT_MOVE_LEVEL][UserNum] = 7;
            continue;
        }
        if (joyinfo.dwXpos <= Joy_cmp1 - 16000) {
            Joy_left[JOY_LEFT_MOVE_LEVEL][UserNum] = 6;
            continue;
        }
        if (joyinfo.dwXpos <= Joy_cmp1 - 12000) {
            Joy_left[JOY_LEFT_MOVE_LEVEL][UserNum] = 5;
            continue;
        }
        if (joyinfo.dwXpos <= Joy_cmp1 - 8000) {
            Joy_left[JOY_LEFT_MOVE_LEVEL][UserNum] = 4;
            continue;
        }
        if (joyinfo.dwXpos <= Joy_cmp1 - 4000) {
            Joy_left[JOY_LEFT_MOVE_LEVEL][UserNum] = 3;
            continue;
        }
        if (joyinfo.dwXpos <= Joy_cmp1 - 2000) {
            Joy_left[JOY_LEFT_MOVE_LEVEL][UserNum] = 1;
            continue;
        }
        if (joyinfo.dwXpos <= Joy_cmp1 + 1000) {
            Joy_left[JOY_RIGHT_MOVE_LEVEL][UserNum] = 1;
            continue;
        }


        if (joyinfo.dwXpos == 65535) {
            Joy_left[JOY_RIGHT_MOVE_LEVEL][UserNum] = 9;
            printf("유저[%d]\n", UserNum);
            continue;
        }


        if (joyinfo.dwXpos <= Joy_cmp1 + 1000) {
            Joy_left[JOY_RIGHT_MOVE_LEVEL][UserNum] = 1;
            continue;
        }
        if (joyinfo.dwXpos <= Joy_cmp1 + 2000) {
            Joy_left[JOY_RIGHT_MOVE_LEVEL][UserNum] = 1;
            continue;
        }
        if (joyinfo.dwXpos <= Joy_cmp1 + 4000) {
            Joy_left[JOY_RIGHT_MOVE_LEVEL][UserNum] = 3;
            continue;
        }
        if (joyinfo.dwXpos <= Joy_cmp1 + 8000) {
            Joy_left[JOY_RIGHT_MOVE_LEVEL][UserNum] = 4;
            continue;
        }
        if (joyinfo.dwXpos <= Joy_cmp1 + 12000) {
            Joy_left[JOY_RIGHT_MOVE_LEVEL][UserNum] = 5;
            continue;
        }
        if (joyinfo.dwXpos <= Joy_cmp1 + 16000) {
            Joy_left[JOY_RIGHT_MOVE_LEVEL][UserNum] = 6;
            continue;
        }
        if (joyinfo.dwXpos <= Joy_cmp1 + 20000) {
            Joy_left[JOY_RIGHT_MOVE_LEVEL][UserNum] = 7;
            continue;
        }
        if (joyinfo.dwXpos <= Joy_cmp1 + 24000) {
            Joy_left[JOY_RIGHT_MOVE_LEVEL][UserNum] = 8;
            continue;
        }


    }
    printf("Mov_left_Ac 여기에 떨어질 리 없다고;;;..");
    Sleep(INT_MAX);


    // SendMessage(hWnd, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
    // Sleep(1);
    // SendMessage(hWnd, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
    return 0;
}


static int debugcount = 0;

STACK_T JoyClass::dll_ptr_First_dwButtons(LPVOID x_po) {
    static int ErrorCodeSum = 0;
    int* Pointer_X = (int*)x_po;
    int* ptr_User_dumpMemory = Pointer_X + 370;//User넘버 포인터 메모리에서 데이터를 받아온다.
    int* HwndSaver = Pointer_X + 378;//User넘버 포인터 메모리에서 데이터를 받아온다.
    int UserNum = *ptr_User_dumpMemory; //User넘버 포인터 메모리에서 데이터를 받아오고 userNum의 int형 데이터에 집어넣는다.

    JOYINFOEX  joyinfo;
    MMRESULT errorCode;
    int* p_dll_ptr_First = nullptr;
    p_dll_ptr_First = p_dll_ptr_x + KEY_OFFSET_FRIST;
    int* p_dll_ptr_First_Dump = p_dll_ptr_First;

    int* p_dll_ptr_First_dwButtons1 = p_dll_ptr_First_Dump;
    int* p_dll_ptr_First_dwButtons2 = p_dll_ptr_First_Dump + 1;
    int* p_dll_ptr_First_dwButtons3 = p_dll_ptr_First_Dump + 2;
    int* p_dll_ptr_First_dwButtons4 = p_dll_ptr_First_Dump + 3;
    int* p_dll_ptr_First_dwButtons5 = p_dll_ptr_First_Dump + 4;
    int* p_dll_ptr_First_dwButtons6 = p_dll_ptr_First_Dump + 5;
    int* p_dll_ptr_First_dwButtons7 = p_dll_ptr_First_Dump + 6;
    int* p_dll_ptr_First_dwButtons8 = p_dll_ptr_First_Dump + 7;
    int* p_dll_ptr_First_dwButtons9 = p_dll_ptr_First_Dump + 8;
    int* p_dll_ptr_First_dwButtons10 = p_dll_ptr_First_Dump + 9;
    int* p_dll_ptr_First_dwButtons11 = p_dll_ptr_First_Dump + 10;
    int* p_dll_ptr_First_dwButtons12 = p_dll_ptr_First_Dump + 11;
    int* p_dll_ptr_First_dwButtons13 = p_dll_ptr_First_Dump + 12;

    while (true) {
        Sleep(1);
        errorCode = joyGetPosEx(UserNum, &joyinfo);

        switch (joyinfo.dwButtons)//dwbutton
        {
        case KEY_DW_ZERO:
            CloseHandle(CreateThread(0, 200, STOPS, *&p_dll_ptr_First_dwButtons13, 0, 0));
            break;
        case KEY_DW_FIRST:
            CloseHandle(CreateThread(0, 200, STOPS, *&p_dll_ptr_First_dwButtons1, 0, 0));
            break;
        case KEY_DW_SECOND:
            CloseHandle(CreateThread(0, 200, STOPS, *&p_dll_ptr_First_dwButtons2, 0, 0));
            break;
        case KEY_DW_THIRD:
            CloseHandle(CreateThread(0, 200, STOPS, *&p_dll_ptr_First_dwButtons3, 0, 0));
            break;
        case KEY_DW_FOURTH:
            CloseHandle(CreateThread(0, 200, STOPS, *&p_dll_ptr_First_dwButtons4, 0, 0));
            break;
        case KEY_DW_FIFTH:
            CloseHandle(CreateThread(0, 200, STOPS, *&p_dll_ptr_First_dwButtons5, 0, 0));
            break;
        case KEY_DW_SIXTH:
            CloseHandle(CreateThread(0, 200, STOPS, *&p_dll_ptr_First_dwButtons6, 0, 0));
            break;
        case KEY_DW_SEVENTH:
            CloseHandle(CreateThread(0, 200, STOPS, *&p_dll_ptr_First_dwButtons7, 0, 0));
            break;
        case KEY_DW_EIGHTH:
            CloseHandle(CreateThread(0, 200, STOPS, *&p_dll_ptr_First_dwButtons8, 0, 0));
            break;
        case KEY_DW_NINTH:
            CloseHandle(CreateThread(0, 200, STOPS, *&p_dll_ptr_First_dwButtons9, 0, 0));
            break;
        case KEY_DW_TENTH:
            CloseHandle(CreateThread(0, 200, STOPS, *&p_dll_ptr_First_dwButtons10, 0, 0));
            break;
        case KEY_DW_ELEVENTH:
            CloseHandle(CreateThread(0, 200, STOPS, *&p_dll_ptr_First_dwButtons11, 0, 0));
            break;
        case KEY_DW_TWELFTH:
            CloseHandle(CreateThread(0, 200, STOPS, *&p_dll_ptr_First_dwButtons12, 0, 0));
            break;
        }

    }
}

STACK_T JoyClass::Mov_Main(LPVOID x_po) {
    int* p_dll_ptr_Five1 = nullptr;
    int* p_dll_ptr_Five2 = nullptr;
    int* p_dll_ptr_Five3 = nullptr;
    int* p_dll_ptr_Five4 = nullptr;
    int* HwndSaver = (int*)x_po + 378;//User넘버 포인터 메모리에서 데이터를 받아온다.
    if (debugcount == 0) {
        debugcount = 1;
        hWnd_x = FindWindowA(NULL, (LPCSTR)x_po);//파서에서 파싱 된 데이터의 Hwnd를 저장한다.
        *HwndSaver = (int)hWnd_x;
        p_dll_ptr_Five1 = p_dll_ptr_x + KEY_OFFSET_FIVE;
        p_dll_ptr_Five2 = p_dll_ptr_x + KEY_OFFSET_FIVE + 1;
        p_dll_ptr_Five3 = p_dll_ptr_x + KEY_OFFSET_FIVE + 2;
        p_dll_ptr_Five4 = p_dll_ptr_x + KEY_OFFSET_FIVE + 3;
        Joy_cmp1 = *p_dll_ptr_Five1;
        Joy_cmp2 = *p_dll_ptr_Five2;
        Joy_cmp3 = *p_dll_ptr_Five3;
        Joy_cmp4 = *p_dll_ptr_Five4;
    }

    CloseHandle(CreateThread(0, BIG_STACK_SIZE, Mov_Left_Right, *&p_dll_ptr_x, 0, 0));
    CloseHandle(CreateThread(0, BIG_STACK_SIZE, Mov_UP_DOWN, *&p_dll_ptr_x, 0, 0));



    return 0;
}






STACK_T JoyClass::Start_JoyLogicStartUP(LPVOID x_po) {

    int* p_time_ = (int*)x_po + 200;
    int timedump = *p_time_;
    Sleep(timedump);
    UserNum1++;
    UserNumCopy = UserNum1;
    int* ptr_User_dumpMemory;
    if (UserNumCopy == 0) {
        printf("1 Start\n");
        p_dll_ptr_x = static_cast<int*>(static_cast<void*>(static_cast<int*>(x_po) + 3000));
        ptr_User_dumpMemory = p_dll_ptr_x + 370;
        *ptr_User_dumpMemory = 0;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Mov_Main, *&p_dll_ptr_x, 0, 0));
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Joy_Button_Twelve, *&p_dll_ptr_x, 0, 0));
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, dll_ptr_First_dwButtons, *&p_dll_ptr_x, 0, 0));
        Sleep(timedump);
    }
    if (UserNumCopy == 1) {
        printf("2 Start\n");
        p_dll_ptr_x = static_cast<int*>(static_cast<void*>(static_cast<int*>(x_po) + 10000));
        ptr_User_dumpMemory = p_dll_ptr_x + 370;
        *ptr_User_dumpMemory = 1;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Mov_Main, *&p_dll_ptr_x, 0, 0));
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Joy_Button_Twelve, *&p_dll_ptr_x, 0, 0));
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, dll_ptr_First_dwButtons, *&p_dll_ptr_x, 0, 0));
        Sleep(timedump);
    }

    if (UserNumCopy == 2) {
        printf("3 Start\n");
        p_dll_ptr_x = static_cast<int*>(static_cast<void*>(static_cast<int*>(x_po) + 13000));
        ptr_User_dumpMemory = p_dll_ptr_x + 370;
        *ptr_User_dumpMemory = 2;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Mov_Main, *&p_dll_ptr_x, 0, 0));
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Joy_Button_Twelve, *&p_dll_ptr_x, 0, 0));
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, dll_ptr_First_dwButtons, *&p_dll_ptr_x, 0, 0));
        Sleep(timedump);
    }

    //Joy_Button_Twelve


   // CloseHandle(CreateThread(0, BIG_STACK_SIZE, Mov_UP_DOWN, *&p_dll_ptr_x, 0, 0));

    while (true) {
        Sleep(1000);
        printf("메인 Start_JoyLogicStartUP 원점 연산 다이아그램.\n", x_po);
    }

    printf("여기에 떨어질 리 없다고;;;..");
    Sleep(INT_MAX);
    return 0;

}

static int debug = 0;

STACK_T JoyClass::Start_JoyLogic1(LPVOID x_po) {

    debug++;
    if (debug == 2) {
        return 0;
    }
    int static* p_Key = (int*)x_po;
    int static* p_hid_id_Frist = (int*)x_po + 20;
    int static* p_hid_id_Second = (int*)x_po + 21;
    int static* p_hid_id_Third = (int*)x_po + 22;
    int static* p_time_ = (int*)x_po + 200;
    HWND hWnd = FindWindowW(NULL, HwndName);

    while (hWnd == 0) {
        hWnd = FindWindow(NULL, HwndName);
        printf("핸들을 찾는 중입니다....\n");
        Sleep(800);
        continue;
    }

    Sleep(1800);





    switch (*p_hid_id_Frist) {
    case 1: {
        *p_time_ = 100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);
        break;
    }
    case 2: {
        *p_time_ = 200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 3: {
        *p_time_ = 300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 4: {
        *p_time_ = 400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 5: {
        *p_time_ = 500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 6: {
        *p_time_ = 600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 7: {
        *p_time_ = 700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 8: {
        *p_time_ = 800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 9: {
        *p_time_ = 800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 10: {
        *p_time_ = 1000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 11: {
        *p_time_ = 1100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 12: {
        *p_time_ = 1200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 13: {
        *p_time_ = 1300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 14: {
        *p_time_ = 1400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 15: {
        *p_time_ = 1500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 16: {
        *p_time_ = 1600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 17: {
        *p_time_ = 1700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 18: {
        *p_time_ = 1800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 19: {
        *p_time_ = 1900;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 20: {
        *p_time_ = 2000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 21: {
        *p_time_ = 2100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 22: {
        *p_time_ = 2200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 23: {
        *p_time_ = 2300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 24: {
        *p_time_ = 2400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 25: {
        *p_time_ = 2500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 26: {
        *p_time_ = 2600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 27: {
        *p_time_ = 2700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 28: {
        *p_time_ = 2800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 29: {
        *p_time_ = 2900;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 30: {
        *p_time_ = 3000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }


    }
    switch (*p_hid_id_Second) {
    case 1: {
        *p_time_ = 100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 2: {
        *p_time_ = 200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 3: {
        *p_time_ = 300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 4: {
        *p_time_ = 400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 5: {
        *p_time_ = 500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 6: {
        *p_time_ = 600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 7: {
        *p_time_ = 700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 8: {
        *p_time_ = 800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 9: {
        *p_time_ = 800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 10: {
        *p_time_ = 1000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 11: {
        *p_time_ = 1100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 12: {
        *p_time_ = 1200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 13: {
        *p_time_ = 1300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 14: {
        *p_time_ = 1400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 15: {
        *p_time_ = 1500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 16: {
        *p_time_ = 1600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 17: {
        *p_time_ = 1700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 18: {
        *p_time_ = 1800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 19: {
        *p_time_ = 1900;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 20: {
        *p_time_ = 2000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 21: {
        *p_time_ = 2100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 22: {
        *p_time_ = 2200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 23: {
        *p_time_ = 2300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 24: {
        *p_time_ = 2400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 25: {
        *p_time_ = 2500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 26: {
        *p_time_ = 2600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 27: {
        *p_time_ = 2700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 28: {
        *p_time_ = 2800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 29: {
        *p_time_ = 2900;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 30: {
        *p_time_ = 3000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }

    }
    switch (*p_hid_id_Third) {
    case 1: {
        *p_time_ = 100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 2: {
        *p_time_ = 200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 3: {
        *p_time_ = 300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 4: {
        *p_time_ = 400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 5: {
        *p_time_ = 500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 6: {
        *p_time_ = 600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 7: {
        *p_time_ = 700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 8: {
        *p_time_ = 800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 9: {
        *p_time_ = 800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 10: {
        *p_time_ = 1000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 11: {
        *p_time_ = 1100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 12: {
        *p_time_ = 1200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 13: {
        *p_time_ = 1300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 14: {
        *p_time_ = 1400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 15: {
        *p_time_ = 1500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 16: {
        *p_time_ = 1600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 17: {
        *p_time_ = 1700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 18: {
        *p_time_ = 1800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 19: {
        *p_time_ = 1900;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 20: {
        *p_time_ = 2000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 21: {
        *p_time_ = 2100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 22: {
        *p_time_ = 2200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 23: {
        *p_time_ = 2300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 24: {
        *p_time_ = 2400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 25: {
        *p_time_ = 2500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 26: {
        *p_time_ = 2600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 27: {
        *p_time_ = 2700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 28: {
        *p_time_ = 2800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 29: {
        *p_time_ = 2900;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 30: {
        *p_time_ = 3000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }

    }
    switch (*p_hid_id_Third) {
    case 1: {
        *p_time_ = 100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 2: {
        *p_time_ = 200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 3: {
        *p_time_ = 300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 4: {
        *p_time_ = 400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 5: {
        *p_time_ = 500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 6: {
        *p_time_ = 600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 7: {
        *p_time_ = 700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 8: {
        *p_time_ = 800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 9: {
        *p_time_ = 800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 10: {
        *p_time_ = 1000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 11: {
        *p_time_ = 1100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 12: {
        *p_time_ = 1200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 13: {
        *p_time_ = 1300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 14: {
        *p_time_ = 1400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 15: {
        *p_time_ = 1500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 16: {
        *p_time_ = 1600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 17: {
        *p_time_ = 1700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 18: {
        *p_time_ = 1800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 19: {
        *p_time_ = 1900;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 20: {
        *p_time_ = 2000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 21: {
        *p_time_ = 2100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 22: {
        *p_time_ = 2200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 23: {
        *p_time_ = 2300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 24: {
        *p_time_ = 2400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 25: {
        *p_time_ = 2500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 26: {
        *p_time_ = 2600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 27: {
        *p_time_ = 2700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 28: {
        *p_time_ = 2800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 29: {
        *p_time_ = 2900;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 30: {
        *p_time_ = 3000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    }
}







STACK_X Start_JoyLogicPrint(LPVOID x_po) {

    while (true) {
        //   printf("TestStruct[%d]\n", (int*)x_po);
        printf("TestStructAddress[%p]\n", (int*)x_po);

        Sleep(500);
    }
}


void JoyClass::JoyLogicStartUp(LPVOID x_po) {
    int* x_pocopy = (int*)x_po;

    printf("조이스틱 클래스로 넘겨 받는 것을 성공 하였습니다.\n");
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Start_ShellStartUp_MonitorInfo_x, *&x_pocopy); //900 Size 
    Sleep(150);
    //Start_ShellStartUp_MonitorInfo_x
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Start_JoyLogic1, *&x_pocopy); //900 Size
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Start_JoyLogicPrint, *&x_pocopy); //900 Size
}