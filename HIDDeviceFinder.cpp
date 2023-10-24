#include "pch.h"
#include <windows.h>
#include <devguid.h>    // for GUID_DEVCLASS_CDROM etc
#include <setupapi.h>
#include <cfgmgr32.h>   // for MAX_DEVICE_ID_LEN, CM_Get_Parent and CM_Get_Device_ID
#include <tchar.h>
#include <stdio.h>
#include <windows.h>
#include <hidsdi.h>
#include <setupapi.h>
#include <initguid.h>
#include <stdio.h>
#include <Windows.h>
#include <dinput.h>
#include <tchar.h>
#include <iostream>
#include <hidclass.h>
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "hid.lib")
//hid.lib

DEFINE_DEVPROPKEY(DEVPKEY_Device_PDOName, 0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 16);    // DEVPROP_TYPE_STRING



LPCTSTR HidName = L"Thrustmaster Racing Wheel FFB";
#pragma comment (lib, "setupapi.lib")

#pragma warning(disable : 4996)
static int Wheel_cmp1;
static int Wheel_cmp2;
static int Wheel_cmp3;
static int Wheel_cmp4;

static int Wheel_left[20][20];
static int* WheelMemory;
static int* WheeName;
static int* t_p_dll_ptr;
static int* Key_p_dll_ptr;

std::string ConvertToMultiByteString(const wchar_t* wstr)
{
    int requiredSize = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
    static std::string result(requiredSize, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr, -1, &result[0], requiredSize, NULL, NULL);
    return result;
}
static bool isNegative;
static bool isNegative2;
LPDIRECTINPUT8 dinput = nullptr;
LPDIRECTINPUTDEVICE8 diWheel = nullptr;
static int Arr_copy;
static DWORD_PTR* mini_ptr_Key_Main;
static SHORT* mini_ptr_Key_Main_x;
static SHORT* mini_ptr_Key_Main_y;
static DWORD_PTR* mini_ptr_Key_B;
static DWORD_PTR* mini_ptr_Key_C;
static DWORD_PTR* mini_ptr_Key_E;
static DWORD_PTR* mini_ptr_Key_4;
static DWORD_PTR* mini_ptr_Key_6;
static HWND hWnd_x;
int static WheeldwXpos;
int static WheeldwYpos;
int static WheeldwYposDump;
int static WheeldwXposOn = 0;
int static WheeldwYposOn = 0;
int static WheeldwXposOff = 0;

STACK_T HIDDeviceFinder::mini_ptr_Key_E_API(LPVOID x_po) {
    Sleep(200);
    int onoff_x1 = 0;
    int* mini_ptr_Key_B = (int*)x_po;
    int* p_dll_ptr_THIRD = t_p_dll_ptr + KEY_OFFSET_THIRD;
    int* p_dll_ptr_Second = t_p_dll_ptr + KEY_OFFSET_SECOND;
    int* p_dll_ptr_First_Second_Dump = p_dll_ptr_Second;
    int* p_dll_ptr_First_xy1 = p_dll_ptr_First_Second_Dump;
    int* p_dll_ptr_First_xy2 = p_dll_ptr_First_Second_Dump + 1;
    int* p_dll_ptr_First_xy3 = p_dll_ptr_First_Second_Dump + 2;
    int* p_dll_ptr_First_xy4 = p_dll_ptr_First_Second_Dump + 3;
    int* p_dll_ptr_First_xy5 = p_dll_ptr_First_Second_Dump + 4;
    while (true) {
        switch (*mini_ptr_Key_E)//dwbutton
        {
        case WHEEL_KEY_OFFSET_STOP:
            if (onoff_x1 != NULL) {
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_xy1, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_xy2, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_xy3, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_xy4, 0);
                Sleep(1);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_xy1, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_xy2, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_xy3, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_xy4, 0);
                onoff_x1 = 0;
            }
            break;
        case WHEEL_KEY_OFFSET_LEFT:
            onoff_x1 = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_xy1, 0);
            break;
        case WHEEL_KEY_OFFSET_RIGHT:
            onoff_x1 = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_xy2, 0);
            break;
        case WHEEL_KEY_OFFSET_UP:
            onoff_x1 = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_xy3, 0);
            break;
        case WHEEL_KEY_OFFSET_DOWN:
            onoff_x1 = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_xy4, 0);
            break;

        }
        //휠 로직 스타트.
    }
    return 0;
}


STACK_T HIDDeviceFinder::mini_ptr_Key_C_API(LPVOID x_po) {
    Sleep(200);
    int onoff_C = 0;
    int* mini_ptr_Key_C = (int*)x_po;
    int* p_dll_ptr_THIRD = t_p_dll_ptr + KEY_OFFSET_THIRD;
    int* p_dll_ptr_Second = t_p_dll_ptr + KEY_OFFSET_SECOND;
    int* p_dll_ptr_First_Second_Dump = p_dll_ptr_Second;
    int* p_dll_ptr_First_Third_Dump = p_dll_ptr_THIRD;
    int* p_dll_ptr_First_Pov1 = p_dll_ptr_First_Third_Dump;
    int* p_dll_ptr_First_Pov2 = p_dll_ptr_First_Third_Dump + 1;
    int* p_dll_ptr_First_Pov3 = p_dll_ptr_First_Third_Dump + 2;
    int* p_dll_ptr_First_Pov4 = p_dll_ptr_First_Third_Dump + 3;
    int* p_dll_ptr_First_Pov5 = p_dll_ptr_First_Third_Dump + 4;
    int m_dll_ptr_First_Pov_onoff = 0;
    int* p_dll_ptr_First_xy5 = p_dll_ptr_First_Second_Dump + 4;
    while (true) {
        switch ((byte)*mini_ptr_Key_C)//dwbutton
        {
        case WHEEL_KEY_OFFSET_C_STOP:
            if (onoff_C != NULL) {
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov1, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov2, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov3, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov4, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov5, 0);

                Sleep(1);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov1, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov2, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov3, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov4, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov5, 0);
                onoff_C = 0;
            }
            break;
        case OFFSET_VALUE_BYTE_C_R2:
            onoff_C = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_Pov1, 0); printf("키SetUP.\n", onoff_C);
            break;
        case OFFSET_VALUE_BYTE_C_L2:
            onoff_C = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_Pov2, 0); printf("키SetUP.\n", onoff_C);
            break;
        case OFFSET_VALUE_BYTE_C_L3:
            onoff_C = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_Pov3, 0); printf("키SetUP.\n", onoff_C);
            break;
        case OFFSET_VALUE_BYTE_C_R3:
            onoff_C = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_Pov4, 0); printf("키SetUP.\n", onoff_C);
            break;
        case OFFSET_VALUE_BYTE_C_ST:
            onoff_C = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_Pov4, 0); printf("키SetUP.\n", onoff_C);
            break;
     


        }
    }
    return 0;
}

STACK_T HIDDeviceFinder::mini_ptr_Key_4_API(LPVOID x_po) {

    Sleep(200);
    int* p_dll_ptr_First = t_p_dll_ptr + KEY_OFFSET_FRIST;
    //p_dll_ptr_Second
    static int* p_dll_ptr_First_Dump = p_dll_ptr_First;
    static int* p_dll_ptr_First_dwButtons1 = p_dll_ptr_First_Dump;
    static int* p_dll_ptr_First_dwButtons2 = p_dll_ptr_First_Dump + 1;
    static int* p_dll_ptr_First_dwButtons3 = p_dll_ptr_First_Dump + 2;
    int onoff_4 = 0;

    while (true) {
        Sleep(1);
        switch ((BYTE)*mini_ptr_Key_4)//dwbutton
        {
        case WHEEL_KEY_OFFSET_4_STOP:
            if (onoff_4 != NULL) {
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_dwButtons1, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_dwButtons2, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_dwButtons3, 0);
                onoff_4 = 0;
            }
            break;
        case WHEEL_KEY_OFFSET_4_FRIST:
            onoff_4 = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_dwButtons1, 0);
            break;
        case WHEEL_KEY_OFFSET_4_SECOND:
            onoff_4 = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_dwButtons2, 0);
            break;
        case WHEEL_KEY_OFFSET_4_ZERO:
            onoff_4 = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_dwButtons3, 0);
            break;
        }
    }
    return 0;

}

STACK_T HIDDeviceFinder::mini_ptr_Key_B_API(LPVOID x_po) {
    Sleep(200);
    int onoff_B = 0;
    int* mini_ptr_Key_B = (int*)x_po;
    int* p_dll_ptr_THIRD = t_p_dll_ptr + KEY_OFFSET_THIRD;
    int* p_dll_ptr_Second = t_p_dll_ptr + KEY_OFFSET_SECOND;
    int* p_dll_ptr_First_Second_Dump = p_dll_ptr_Second;
    int* p_dll_ptr_First_Third_Dump = p_dll_ptr_THIRD;
    int* p_dll_ptr_First_Pov1 = p_dll_ptr_First_Third_Dump;
    int* p_dll_ptr_First_Pov2 = p_dll_ptr_First_Third_Dump + 1;
    int* p_dll_ptr_First_Pov3 = p_dll_ptr_First_Third_Dump + 2;
    int* p_dll_ptr_First_Pov4 = p_dll_ptr_First_Third_Dump + 3;
    int* p_dll_ptr_First_Pov5 = p_dll_ptr_First_Third_Dump + 4;
    int m_dll_ptr_First_Pov_onoff = 0;
    int* p_dll_ptr_First_xy5 = p_dll_ptr_First_Second_Dump + 4;
    while (true) {
        switch ((BYTE)*mini_ptr_Key_B)//dwbutton
        {
        case WHEEL_KEY_OFFSET_B_STOP:
            if (onoff_B != NULL) {
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov1, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov2, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov3, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov4, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov5, 0);
                Sleep(1);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov1, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov2, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov3, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov4, 0);
                SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_First_Pov5, 0);
                onoff_B = 0;
            }
            break;
        case OFFSET_VALUE_BYTE_B_TRIANGLE:
            onoff_B = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_Pov1, 0);
            break;
        case OFFSET_VALUE_BYTE_B_SQUARE:
            onoff_B = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_Pov2, 0);
            break;
        case OFFSET_VALUE_BYTE_B_CIRCLE:
            onoff_B = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_Pov3, 0);
            break;
        case OFFSET_VALUE_BYTE_B_X:
            onoff_B = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_Pov4, 0);
            break;
        case OFFSET_VALUE_BYTE_B_ST:
            onoff_B = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_Pov5, 0);
            break;
        case OFFSET_VALUE_BYTE_B_SE:
            onoff_B = 1;
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_First_xy5, 0);
            break;


        }
    }
    return 0;
}

STACK_X STOPS_X(LPVOID x_po) {
    int* stop = (int*)x_po;
    int codeSleep = 0;
    while (codeSleep <= 30) {
        Sleep(1);
        SendMessage(hWnd_x, WM_KEYUP, *stop, 0);
        codeSleep++;
    }
    return 0;
}
static int t_p_dll_ptrdump_val;

// STACK_T HIDDeviceFinder::Start_JoyLogicStartUP(LPVOID x_po);
STACK_T HIDDeviceFinder::Mov_left_Ac(LPVOID x_po) {

    int* p_dll_ptr_FirstKey = reinterpret_cast<int*>(x_po) + 3000;
    int* p_dll_ptr_SecondKey = reinterpret_cast<int*>(x_po) + 3001;
    //int *p_dll_ptr_FirstKey = (int*)x_po + KEY_OFFSET_FRIST;
    Sleep(400);


    while (true) {
        Sleep(1);
        int DataDump = Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL];
        int DataDump2 = Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL];

        switch (DataDump) {
        case 2:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
        case 3:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
        case 4:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
        case 5:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
        case 6:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
        case 7:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
        case 8:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_FirstKey, 0);
            Sleep(DataDump * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_FirstKey, 0);
            break;
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
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);
            break;
        case 3:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);
            break;
        case 4:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);
            break;
        case 5:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);
            break;
        case 6:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);
            break;
        case 7:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);
            break;
        case 8:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            Sleep(DataDump2 * 10);
            SendMessage(hWnd_x, WM_KEYUP, *p_dll_ptr_SecondKey, 0);
            break;
        case 9:
            SendMessage(hWnd_x, WM_KEYDOWN, *p_dll_ptr_SecondKey, 0);
            break;
        default:

            break;
        }

     
    }


}

#include <windows.h>
#include <hidsdi.h>
#include <hidpi.h>

void DisconnectHid(HANDLE hFile) {
    HIDD_ATTRIBUTES attrib;
    attrib.Size = sizeof(HIDD_ATTRIBUTES);
    HidD_GetAttributes(hFile, &attrib);

    PHIDP_PREPARSED_DATA preparsedData;
    HidD_GetPreparsedData(hFile, &preparsedData);
    HidD_FreePreparsedData(preparsedData);

    CloseHandle(hFile);
}

BOOL DisableUsbDevice(LPCWSTR deviceId)
{
    DEVINST devInst;
    if (CM_Locate_DevNode(&devInst, (LPWSTR)"USB\\VID_044F&PID_B677\\5&356B5377&0&5", CM_LOCATE_DEVNODE_NORMAL) != CR_SUCCESS) {
        return FALSE;
    }
    if (CM_Disable_DevNode(devInst, CM_DISABLE_POLITE) != CR_SUCCESS) {
        return FALSE;
    }
    return TRUE;
}



STACK_T HIDDeviceFinder::Start_JoyLogicStartUP(LPVOID x_po) {
    PBYTE PropertyBuffer = (PBYTE)malloc(4096);
    memset(PropertyBuffer, 0, 4096);

    WheelMemory = (int*)x_po + WHEEL_MEMORY_OFFSET;
    WheeName = (int*)x_po + WHEE_NAME_OFFSET;
    WheeName = WheeName + WHEE_NAME_STRING_OFFSET / 4;
    t_p_dll_ptr = static_cast<int*>(static_cast<void*>(static_cast<int*>(x_po) + TRUSTMASTER_OFFSET));
    Key_p_dll_ptr = static_cast<int*>(static_cast<void*>(static_cast<int*>(x_po) + 3000));

    HANDLE hDev = INVALID_HANDLE_VALUE;
    DWORD dwSize, dwMemberIndex;
    SP_DEVICE_INTERFACE_DATA DeviceInterfaceData;
    SP_DEVICE_INTERFACE_DETAIL_DATA* pDeviceInterfaceDetailData = NULL;
    HDEVINFO DeviceInfoSet = SetupDiGetClassDevs(&GUID_CLASS_INPUT, NULL, NULL, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);
    if (DeviceInfoSet == INVALID_HANDLE_VALUE) {
        return 0;
    }
    DeviceInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);
    for (dwMemberIndex = 0; SetupDiEnumDeviceInterfaces(DeviceInfoSet, NULL, &GUID_CLASS_INPUT, dwMemberIndex, &DeviceInterfaceData); dwMemberIndex++) {
        SetupDiGetDeviceInterfaceDetail(DeviceInfoSet, &DeviceInterfaceData, NULL, 0, &dwSize, NULL);
        pDeviceInterfaceDetailData = (SP_DEVICE_INTERFACE_DETAIL_DATA*)malloc(dwSize);
        if (pDeviceInterfaceDetailData == NULL) {
            SetupDiDestroyDeviceInfoList(DeviceInfoSet);
            return 0;
        }

        pDeviceInterfaceDetailData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);
        if (!SetupDiGetDeviceInterfaceDetail(DeviceInfoSet, &DeviceInterfaceData, pDeviceInterfaceDetailData, dwSize, NULL, NULL)) {
            free(pDeviceInterfaceDetailData);
            continue;
        }

        HANDLE hFile = CreateFile(pDeviceInterfaceDetailData->DevicePath, GENERIC_READ | GENERIC_WRITE,
            FILE_SHARE_READ | FILE_SHARE_WRITE,
            0,
            OPEN_EXISTING,
            0,
            0);
        if (hFile == INVALID_HANDLE_VALUE) {
            free(pDeviceInterfaceDetailData);
            continue;
        }
        LPDWORD static checksum = 0;
        TCHAR buffer[MAX_PATH];
        DWORD bufferSize = sizeof(buffer);
        SP_DEVINFO_DATA DeviceInfoData2 = { 0 };
        DeviceInfoData2.cbSize = sizeof(DeviceInfoData2);
        SetupDiEnumDeviceInfo(DeviceInfoSet, 0, &DeviceInfoData2);
        if (SetupDiGetDeviceRegistryProperty(DeviceInfoSet, &DeviceInfoData2, SPDRP_DEVICEDESC, NULL, (PBYTE)buffer, bufferSize, NULL)) {
            _tprintf(TEXT("Device Name: %s\n"), buffer);
            HIDD_ATTRIBUTES attrib;
            attrib.Size = sizeof(HIDD_ATTRIBUTES);
            HidD_GetAttributes(hFile, &attrib);
            HidD_GetProductString(hFile, PropertyBuffer, 248);
        
            int requiredSize = WideCharToMultiByte(CP_UTF8, 0, (LPCWCH)PropertyBuffer, -1, NULL, 0, NULL, NULL);
            std::string result(requiredSize, 0);
            WideCharToMultiByte(CP_UTF8, 0, (LPCWCH)PropertyBuffer, -1, &result[0], requiredSize, NULL, NULL);

            const char* result_char = result.c_str();
            char* char_ptr = new char[result.length() + 1];
            strcpy(char_ptr, result_char);
            printf("Test1 텍스처.[%s]\n", char_ptr);
            printf("Test2.텍스처[%s]\n", WheeName);

            printf("Test1.포인터[%p]\n", char_ptr);
            printf("Test2. 포인터[%p]\n", WheeName);
            
            _tprintf(TEXT("HID Product Name: %s\n"), PropertyBuffer);
            if (lstrcmpiA((LPCSTR)WheeName, char_ptr) == 0) {
                //여기서 일치함.
                Sleep(150);

             //   DisableUsbDevice(pDeviceInterfaceDetailData->DevicePath);
            //    CM_Disable_DevNode(DeviceInfoData2.DevInst, CM_DISABLE_POLITE);
               // CM_Locate_DevNode(&DeviceInfoData2.DevInst, NULL, CM_LOCATE_DEVNODE_NORMAL);
               // PPNP_VETO_TYPE pVetoType = nullptr;
               // WCHAR pszVetoName[MAX_PATH] = { 0 };
              //  DWORD cmResult = CM_Query_And_Remove_SubTreeW(DeviceInfoData2.DevInst, pVetoType, pszVetoName, MAX_PATH, 0);
               // DWORD cmResult = CM_Query_And_Remove_SubTreeW(DeviceInfoData2.DevInst, NULL, NULL, 0, CM_REMOVE_NO_RESTART | CM_REMOVE_UI_OK);

              //  DisconnectHid(hFile);



         
         

                printf("일치합니다.[%p]\n", WheeName);
                PHIDP_PREPARSED_DATA preparsedData;
                PHIDP_CAPS caps = (PHIDP_CAPS)malloc(sizeof(HIDP_CAPS));
                memset(caps, 0, sizeof(HIDP_CAPS));
                HidD_GetPreparsedData(hFile, &preparsedData);
                HidP_GetCaps(preparsedData, caps);
                PCHAR buffer_x = (PCHAR)malloc(caps->InputReportByteLength);
                printf("휠 구조체 Struect[%p]\n", WheelMemory);
                printf("AbandonWare휠 구조체 Struect[%p]\n", WheelMemory);
                printf("트러스트 마스터 포인터 오프셋 스트럭쳐 입니다.[%p]\n", t_p_dll_ptr);

                mini_ptr_Key_Main_x = (SHORT*)((BYTE*)WheelMemory + 0x01);

                mini_ptr_Key_Main_y = (SHORT*)((BYTE*)WheelMemory + 0x01);
                mini_ptr_Key_B = (DWORD_PTR*)((BYTE*)WheelMemory + 0x0b);
                mini_ptr_Key_C = (DWORD_PTR*)((BYTE*)WheelMemory + 0x0c);
                mini_ptr_Key_E = (DWORD_PTR*)((BYTE*)WheelMemory + 0x0e);

                mini_ptr_Key_4 = (DWORD_PTR*)((BYTE*)WheelMemory + 0x04);


                mini_ptr_Key_6 = (DWORD_PTR*)((BYTE*)WheelMemory + 0x06);


                mini_ptr_Key_Main = (DWORD_PTR*)((BYTE*)WheelMemory);

                int onoff_x1 = 0;
                int onoff_B = 0;
                int onoff_4 = 0;
                int onoff_main = 0;
                int onoff_mainSecond = 0;
                int *p_dll_ptr_Second = t_p_dll_ptr + KEY_OFFSET_SECOND;
                int* p_dll_ptr_First_Second_Dump = p_dll_ptr_Second;
                int* p_dll_ptr_First_xy1 = p_dll_ptr_First_Second_Dump;
                int* p_dll_ptr_First_xy2 = p_dll_ptr_First_Second_Dump + 1;
                int* p_dll_ptr_First_xy3 = p_dll_ptr_First_Second_Dump + 2;
                int* p_dll_ptr_First_xy4 = p_dll_ptr_First_Second_Dump + 3;
                int* p_dll_ptr_First_xy5 = p_dll_ptr_First_Second_Dump + 4;
                int* p_dll_ptr_First_xyonoff = 0;


                int* p_dll_ptr_THIRD = t_p_dll_ptr + KEY_OFFSET_THIRD;
                int* p_dll_ptr_First_Third_Dump = p_dll_ptr_THIRD;
                int* p_dll_ptr_First_Pov1 = p_dll_ptr_First_Third_Dump;
                int* p_dll_ptr_First_Pov2 = p_dll_ptr_First_Third_Dump + 1;
                int* p_dll_ptr_First_Pov3 = p_dll_ptr_First_Third_Dump + 2;
                int* p_dll_ptr_First_Pov4 = p_dll_ptr_First_Third_Dump + 3;
                int* p_dll_ptr_First_Pov5 = p_dll_ptr_First_Third_Dump + 4;
                int m_dll_ptr_First_Pov_onoff = 0;

                int* p_dll_ptr_MainAdd1 = t_p_dll_ptr + KEY_OFFSET_FIVE;
                int* p_dll_ptr_MainAdd2 = t_p_dll_ptr + KEY_OFFSET_FIVE+1;
                int* p_dll_ptr_MainAdd3 = t_p_dll_ptr + KEY_OFFSET_FIVE + 2;
                int* p_dll_ptr_MainAdd4 = t_p_dll_ptr + KEY_OFFSET_FIVE + 3;
                int* p_dll_ptr_MainAdd5 = t_p_dll_ptr + KEY_OFFSET_FIVE + 4;
                int Joy_cmp1 = *p_dll_ptr_MainAdd1;

                int Joy_cmp2 = *p_dll_ptr_MainAdd2;
                int Joy_cmp3 = *p_dll_ptr_MainAdd3;

                int Joy_cmp4 = *p_dll_ptr_MainAdd4;
                int Joy_cmp5 = *p_dll_ptr_MainAdd5;

                int *p_dll_ptr_First = t_p_dll_ptr + KEY_OFFSET_FRIST;
                //p_dll_ptr_Second
                static int * p_dll_ptr_First_Dump = p_dll_ptr_First;
                static int* p_dll_ptr_First_dwButtons1 = p_dll_ptr_First_Dump;
                static int* p_dll_ptr_First_dwButtons2 = p_dll_ptr_First_Dump + 1;
                static int* p_dll_ptr_First_dwButtons3 = p_dll_ptr_First_Dump + 2;
                static int* p_dll_ptr_First_dwButtons4 = p_dll_ptr_First_Dump + 3;
                static int* p_dll_ptr_First_dwButtons5 = p_dll_ptr_First_Dump + 4;
                static int* p_dll_ptr_First_dwButtons6 = p_dll_ptr_First_Dump + 5;
                static int* p_dll_ptr_First_dwButtons7 = p_dll_ptr_First_Dump + 6;
                static int* p_dll_ptr_First_dwButtons8 = p_dll_ptr_First_Dump + 7;
                static int* p_dll_ptr_First_dwButtons9 = p_dll_ptr_First_Dump + 8;
                static int* p_dll_ptr_First_dwButtons10 = p_dll_ptr_First_Dump + 9;
                static int* p_dll_ptr_First_dwButtons11 = p_dll_ptr_First_Dump + 10;
                static int* p_dll_ptr_First_dwButtons12 = p_dll_ptr_First_Dump + 11;
                int* p_dll_ptr_Five1 = nullptr;
                int* p_dll_ptr_Five2 = nullptr;
                int* p_dll_ptr_Five3 = nullptr;
                int* p_dll_ptr_Five4 = nullptr;
                p_dll_ptr_Five1 = t_p_dll_ptr + KEY_OFFSET_FIVE;
                p_dll_ptr_Five2 = t_p_dll_ptr + KEY_OFFSET_FIVE + 1;
                p_dll_ptr_Five3 = t_p_dll_ptr + KEY_OFFSET_FIVE + 2;
                p_dll_ptr_Five4 = t_p_dll_ptr + KEY_OFFSET_FIVE + 3;
                Wheel_cmp1 = *p_dll_ptr_Five1;
                Wheel_cmp2 = *p_dll_ptr_Five2;
                Wheel_cmp3 = *p_dll_ptr_Five3;
                Wheel_cmp4 = *p_dll_ptr_Five4;


                hWnd_x = FindWindowA(NULL, (LPCSTR)t_p_dll_ptr);
                CloseHandle(CreateThread(0, 17900, Mov_left_Ac, *&Key_p_dll_ptr, 0, 0));
                    CloseHandle(CreateThread(0, 17900, mini_ptr_Key_B_API, *&mini_ptr_Key_B, 0, 0));
                    CloseHandle(CreateThread(0, 17900, mini_ptr_Key_E_API, *&mini_ptr_Key_E, 0, 0));
                    CloseHandle(CreateThread(0, 17900, mini_ptr_Key_C_API, *&mini_ptr_Key_C, 0, 0));
                   // CloseHandle(CreateThread(0, 17900, mini_ptr_Key_4_API, *&mini_ptr_Key_4, 0, 0));
                    //mini_ptr_Key_4
                // BOOLEAN AbandonW = HidD_GetInputReport(hFile, buffer_x, caps->InputReportByteLength);
                
                while (true) {
                    Sleep(1);

                    BOOL success = ReadFile(hFile, WheelMemory, caps->InputReportByteLength, checksum, 0);



      
                    WheeldwXpos = (int)*mini_ptr_Key_Main_x;
                    WheeldwYpos = (int)*mini_ptr_Key_Main_x;

                    isNegative = (WheeldwXpos & 0x8000) != 0;
                    isNegative2 = (WheeldwYpos & 0x8000) != 0;


                    if (isNegative == false && WheeldwXposOn== NULL) {
       
                        WheeldwXposOn = 1;
                    }

                    if (isNegative == true && WheeldwYposOn == NULL) {

                         WheeldwYposOn = 1;
                        WheeldwYposDump = -WheeldwYpos;
                        goto start;
                    }

                    if (WheeldwXpos == NULL && WheeldwXposOn == 1) {

                        Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL] = 9;
                        Arr_copy = Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL];
                        WheeldwXposOn = NULL;
                        printf("x휠 이동 스톱.[%d]\n", Arr_copy);
                        continue;
                    }

                    if (WheeldwXpos <= STOP_X - 24000 && WheeldwXposOn == 1) {
                 
                        Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL] = 8;
                        Arr_copy = Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL];
                        printf("휠 이동.[%d]\n", Arr_copy);
                        WheeldwXposOn = NULL;
                        continue;
                    }

                    if (WheeldwXpos <= STOP_X - 20000 && WheeldwXposOn == 1) {
                        Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL] = 7;
                        Arr_copy = Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL];
                        printf("휠 이동.[%d]\n", Arr_copy);
                        WheeldwXposOn = NULL;
                        continue;
                    }
                    if (WheeldwXpos <= STOP_X - 16000 && WheeldwXposOn == 1) {
                        Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL] = 6;
                        Arr_copy = Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL];
                        printf("휠 이동.[%d]\n", Arr_copy);
                        WheeldwXposOn = NULL;
                        continue;
                    }
                    if (WheeldwXpos <= STOP_X - 12000 && WheeldwXposOn == 1) {
          
                        Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL] = 5;
                        Arr_copy = Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL];
                        printf("휠 이동.[%d]\n", Arr_copy);
                        WheeldwXposOn = NULL;
                        continue;
                    }
                    if (WheeldwXpos <= STOP_X - 8000 && WheeldwXposOn == 1) {
                        Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL] = 4;
                        Arr_copy = Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL];
                        printf("휠 이동.[%d]\n", Arr_copy);
                        WheeldwXposOn = NULL;
                        continue;
                    }
                    if (WheeldwXpos <= STOP_X - 4000 && WheeldwXposOn == 1) {
                        Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL] = 3;
                        Arr_copy = Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL];
                        printf("휠 이동.[%d]\n", Arr_copy);
                        WheeldwXposOn = NULL;
                        continue;
                    }
                    if (WheeldwXpos <= STOP_X - 2000 && WheeldwXposOn == 1) {
                        Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL] =1;
                        Arr_copy = Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL];
                        printf("휠 이동.[%d]\n", Arr_copy);
                        WheeldwXposOn = NULL;
                        continue;
                    }

                    if (WheeldwXpos <= STOP_X - 1000 && WheeldwXposOn == 1) {
                        Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL] = 1;
                        Arr_copy = Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL];
                        printf("STOPX휠 이동.[%d]\n", Arr_copy);
                        WheeldwXposOn = NULL;
                        continue;
                    }


                start:

                    if (WheeldwYposDump == 1 && WheeldwYposOn == 1) {
                        Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL] = 9;
                        Arr_copy = Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL];
                        WheeldwYposOn = NULL;
                        printf("1스톱연산 휠 이동.[%d]\n", Arr_copy);
                        continue;
                    }

                    if (WheeldwYposDump >= STOP_X - 1000 && WheeldwYposOn == 1) {
                        Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL] = 1;
                        Arr_copy = Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL];
                        WheeldwYposOn = NULL;
                        printf("X스톱 휠 이동.[%d]\n", Arr_copy);
                        continue;
                    }

                    if (WheeldwYposDump >= STOP_X - 2000 && WheeldwYposOn == 1) {
                        Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL] = 1;
                        Arr_copy = Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL];
                        WheeldwYposOn = NULL;
                        printf("Y휠 이동.[%d]\n", Arr_copy);
                        continue;
                    }
                    if (WheeldwYposDump >= STOP_X - 4000 && WheeldwYposOn == 1) {
                        Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL] = 3;
                        Arr_copy = Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL];
                        WheeldwYposOn = NULL;
                        printf("Y휠 이동.[%d]\n", Arr_copy);
                        continue;
                    }
                    if (WheeldwYposDump >= STOP_X - 8000 && WheeldwYposOn == 1) {
                        Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL] = 4;
                        Arr_copy = Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL];
                        printf("Y휠 이동.[%d]\n", Arr_copy);
                        WheeldwYposOn = NULL;
                        continue;
                    }
                    if (WheeldwYposDump >= STOP_X - 12000 && WheeldwYposOn == 1) {

                        Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL] = 5;
                        Arr_copy = Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL];
                        WheeldwYposOn = NULL;
                        printf("Y휠 이동.[%d]\n", Arr_copy);
                        continue;
                    }
                    if (WheeldwYposDump >= STOP_X - 16000 && WheeldwYposOn == 1) {
                        Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL] = 6;
                        Arr_copy = Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL];
                        WheeldwYposOn = NULL;
                        printf("Y휠 이동.[%d]\n", Arr_copy);
                        continue;
                    }

                    if (WheeldwYposDump >= STOP_X - 20000 && WheeldwYposOn == 1) {
                        Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL] = 7;
                        Arr_copy = Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL];
                        WheeldwYposOn = NULL;
                        printf("Y휠 이동.[%d]\n", Arr_copy);
                        continue;
                    }
                    if (WheeldwYposDump >= STOP_X - 24000 && WheeldwYposOn == 1) {

                        Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL] = 8;
                        Arr_copy = Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL];
                        WheeldwYposOn = NULL;
                        printf("Y휠 이동.[%d]\n", Arr_copy);
                        continue;
                    }

                    if (WheeldwYposDump >= STOP_X - 28000 && WheeldwYposOn == 1) {

                        Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL] = 9;
                        Arr_copy = Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL];
                        WheeldwYposOn = NULL;
                        printf("Y휠 이동1.[%d]\n", Arr_copy);
                        continue;
                    }
                    if (WheeldwYposDump >= STOP_X - 34000 && WheeldwYposOn == 1) {

                        Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL] = 9;
                        Arr_copy = Wheel_left[WHEEL_RIGHT_MOVE_LEVEL][NULL];
                        WheeldwYposOn = NULL;
                        printf("Y휠 이동2.[%d]\n", Arr_copy);
                        continue;
                    }



                }



                
                //YStart
           /*     if (WheeldwYposDump == NULL) {

                    Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL] = 1;
                    Arr_copy = Wheel_left[WHEEL_LEFT_MOVE_LEVEL][NULL];
                    printf("휠 이동 스톱.[%d]\n", Arr_copy);
                    continue;
                }

                */
              
                


                
                  
              
                  
              
                    
                    //휠 로직 스타트.
                
            }

        }
      //  CloseHandle(hFile);

    }
    return 0;
}


void HIDDeviceFinder::HIDDeviceFinderStartUp(LPVOID x_po) {
    int* x_pocopy = (int*)x_po;
    printf("조이스틱 클래스로 넘겨 받는 것을 성공 하였습니다.\n");
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Start_JoyLogicStartUP, *&x_pocopy); //900 Size
//   ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Start_JoyLogicPrint, *&x_pocopy); //900 Size
}

