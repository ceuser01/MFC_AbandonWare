#include "pch.h"
#include <windows.h>
#include <devguid.h>
#include <setupapi.h>
#include <cfgmgr32.h>
#include <tchar.h>

#define INITGUID
#include <tchar.h>
#include <stdio.h>

static CString PortchecksumArr0[31];
static CString PortchecksumArr1[31];
static CString PortchecksumArr2[31];

// PortchecksumArr0
// Port_#0007.Hub_#0002

#ifdef DEFINE_DEVPROPKEY
#undef DEFINE_DEVPROPKEY
#endif

#ifdef INITGUID
#define DEFINE_DEVPROPKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) \
    EXTERN_C const DEVPROPKEY DECLSPEC_SELECTANY name = { \
        { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }, \
        pid \
    }
#else
#define DEFINE_DEVPROPKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) \
    EXTERN_C const DEVPROPKEY name
#endif

DEFINE_DEVPROPKEY(DEVPKEY_Device_BusReportedDeviceDesc, 0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 4);     // DEVPROP_TYPE_STRING
DEFINE_DEVPROPKEY(DEVPKEY_Device_ContainerId, 0x8c7ed206, 0x3f8a, 0x4827, 0xb3, 0xab, 0xae, 0x9e, 0x1f, 0xae, 0xfc, 0x6c, 2);     // DEVPROP_TYPE_GUID
DEFINE_DEVPROPKEY(DEVPKEY_Device_FriendlyName, 0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 14);    // DEVPROP_TYPE_STRING
DEFINE_DEVPROPKEY(DEVPKEY_DeviceDisplay_Category, 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x5a);  // DEVPROP_TYPE_STRING_LIST
DEFINE_DEVPROPKEY(DEVPKEY_Device_LocationInfo, 0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 15);    // DEVPROP_TYPE_STRING
DEFINE_DEVPROPKEY(DEVPKEY_Device_Manufacturer, 0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 13);    // DEVPROP_TYPE_STRING
DEFINE_DEVPROPKEY(DEVPKEY_Device_SecuritySDS, 0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 26);    // DEVPROP_TYPE_SECURITY_DESCRIPTOR_STRING
DEFINE_DEVPROPKEY(DEVPKEY_Device_PDOName, 0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 16);    // DEVPROP_TYPE_STRING

//DEVPKEY_Device_InstanceId
DEFINE_DEVPROPKEY(DEVPKEY_Device_InstanceId, 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 256);   // DEVPROP_TYPE_STRING
DEFINE_DEVPROPKEY(DEVPKEY_Device_TransportRelations, 0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 11);
#define ARRAY_SIZE(arr)     (sizeof(arr)/sizeof(arr[0]))

#pragma comment (lib, "setupapi.lib")

typedef BOOL(WINAPI* FN_SetupDiGetDevicePropertyW)(
    __in       HDEVINFO DeviceInfoSet,
    __in       PSP_DEVINFO_DATA DeviceInfoData,
    __in       const DEVPROPKEY* PropertyKey,
    __out      DEVPROPTYPE* PropertyType,
    __out_opt  PBYTE PropertyBuffer,
    __in       DWORD PropertyBufferSize,
    __out_opt  PDWORD RequiredSize,
    __in       DWORD Flags
    );

HDEVINFO hDevInfo = NULL;
GUID* pClassGuid = NULL;
LPCTSTR pszEnumerator = L"USB";
unsigned int Hid_count = 0;
SP_DEVINFO_DATA DeviceInfoData = { 0 };
DEVPROPTYPE ulPropertyType = 0;
DWORD dwSize = 0;

WCHAR CopyBuffer1[4096] = { 0 };
WCHAR CopyBuffer2[4096] = { 0 };

LPCTSTR HID1 = L"T.16000M";
LPCTSTR HID2 = L"Thrustmaster T150RS";
//Thrustmaster T150RS
int* address1 = NULL;
int* address2 = NULL;

int HidCount = 0;
int m_Stop_ORG[30] = { 0 };
int* p_Stop_ORG = m_Stop_ORG;
int m_Stop_COUT = 0;

static int count_xx;


STACK_X Hid_SystemMain(LPVOID x_po) {
    PortchecksumArr0[0] = L"Port_#0001.Hub_#0000";
    PortchecksumArr0[1] = L"Port_#0001.Hub_#0000";
    PortchecksumArr0[2] = L"Port_#0001.Hub_#0000";
    PortchecksumArr0[3] = L"Port_#0003.Hub_#0000";
    PortchecksumArr0[4] = L"Port_#0004.Hub_#0000";
    PortchecksumArr0[5] = L"Port_#0005.Hub_#0000";
    PortchecksumArr0[6] = L"Port_#0006.Hub_#0000";
    PortchecksumArr0[7] = L"Port_#0007.Hub_#0000";
    PortchecksumArr0[8] = L"Port_#0008.Hub_#0000";
    PortchecksumArr0[9] = L"Port_#0009.Hub_#0000";
    PortchecksumArr0[10] = L"Port_#0010.Hub_#0000";
    PortchecksumArr0[11] = L"Port_#0011.Hub_#0000";
    PortchecksumArr0[12] = L"Port_#0012.Hub_#0000";
    PortchecksumArr0[13] = L"Port_#0013.Hub_#0000";
    PortchecksumArr0[14] = L"Port_#0014.Hub_#0000";
    PortchecksumArr0[15] = L"Port_#0015.Hub_#0000";
    PortchecksumArr0[16] = L"Port_#0016.Hub_#0000";
    PortchecksumArr0[17] = L"Port_#0017.Hub_#0000";
    PortchecksumArr0[18] = L"Port_#0018.Hub_#0000";
    PortchecksumArr0[19] = L"Port_#0019.Hub_#0000";
    PortchecksumArr0[20] = L"Port_#0020.Hub_#0000";
    PortchecksumArr0[21] = L"Port_#0021.Hub_#0000";
    PortchecksumArr0[22] = L"Port_#0022.Hub_#0000";
    PortchecksumArr0[23] = L"Port_#0023.Hub_#0000";
    PortchecksumArr0[24] = L"Port_#0024.Hub_#0000";
    PortchecksumArr0[25] = L"Port_#0025.Hub_#0000";
    PortchecksumArr0[26] = L"Port_#0026.Hub_#0000";
    PortchecksumArr0[27] = L"Port_#0027.Hub_#0000";
    PortchecksumArr0[28] = L"Port_#0028.Hub_#0000";
    PortchecksumArr0[29] = L"Port_#0029.Hub_#0000";
    PortchecksumArr0[30] = L"Port_#0030.Hub_#0000";



    PortchecksumArr1[0] = L"Port_#0001.Hub_#0001";
    PortchecksumArr1[1] = L"Port_#0001.Hub_#0001";
    PortchecksumArr1[2] = L"Port_#0001.Hub_#0001";
    PortchecksumArr1[3] = L"Port_#0003.Hub_#0001";
    PortchecksumArr1[4] = L"Port_#0004.Hub_#0001";
    PortchecksumArr1[5] = L"Port_#0005.Hub_#0001";
    PortchecksumArr1[6] = L"Port_#0006.Hub_#0001";
    PortchecksumArr1[7] = L"Port_#0007.Hub_#0001";
    PortchecksumArr1[8] = L"Port_#0008.Hub_#0001";
    PortchecksumArr1[9] = L"Port_#0009.Hub_#0001";
    PortchecksumArr1[10] = L"Port_#0010.Hub_#0001";
    PortchecksumArr1[11] = L"Port_#0011.Hub_#0001";
    PortchecksumArr1[12] = L"Port_#0012.Hub_#0001";
    PortchecksumArr1[13] = L"Port_#0013.Hub_#0001";
    PortchecksumArr1[14] = L"Port_#0014.Hub_#0001";
    PortchecksumArr1[15] = L"Port_#0015.Hub_#0001";
    PortchecksumArr1[16] = L"Port_#0016.Hub_#0001";
    PortchecksumArr1[17] = L"Port_#0017.Hub_#0001";
    PortchecksumArr1[18] = L"Port_#0018.Hub_#0001";
    PortchecksumArr1[19] = L"Port_#0019.Hub_#0001";
    PortchecksumArr1[20] = L"Port_#0020.Hub_#0001";
    PortchecksumArr1[21] = L"Port_#0021.Hub_#0001";
    PortchecksumArr1[22] = L"Port_#0022.Hub_#0001";
    PortchecksumArr1[23] = L"Port_#0023.Hub_#0001";
    PortchecksumArr1[24] = L"Port_#0024.Hub_#0001";
    PortchecksumArr1[25] = L"Port_#0025.Hub_#0001";
    PortchecksumArr1[26] = L"Port_#0026.Hub_#0001";
    PortchecksumArr1[27] = L"Port_#0027.Hub_#0001";
    PortchecksumArr1[28] = L"Port_#0028.Hub_#0001";
    PortchecksumArr1[29] = L"Port_#0029.Hub_#0001";
    PortchecksumArr1[30] = L"Port_#0030.Hub_#0001";

    PortchecksumArr2[0] = L"Port_#0001.Hub_#0002";
    PortchecksumArr2[1] = L"Port_#0001.Hub_#0002";
    PortchecksumArr2[2] = L"Port_#0001.Hub_#0002";
    PortchecksumArr2[3] = L"Port_#0003.Hub_#0002";
    PortchecksumArr2[4] = L"Port_#0004.Hub_#0002";
    PortchecksumArr2[5] = L"Port_#0005.Hub_#0002";
    PortchecksumArr2[6] = L"Port_#0006.Hub_#0002";
    PortchecksumArr2[7] = L"Port_#0007.Hub_#0002";
    PortchecksumArr2[8] = L"Port_#0008.Hub_#0002";
    PortchecksumArr2[9] = L"Port_#0009.Hub_#0002";
    PortchecksumArr2[10] = L"Port_#0010.Hub_#0002";
    PortchecksumArr2[11] = L"Port_#0011.Hub_#0002";
    PortchecksumArr2[12] = L"Port_#0012.Hub_#0002";
    PortchecksumArr2[13] = L"Port_#0013.Hub_#0002";
    PortchecksumArr2[14] = L"Port_#0014.Hub_#0002";
    PortchecksumArr2[15] = L"Port_#0015.Hub_#0002";
    PortchecksumArr2[16] = L"Port_#0016.Hub_#0002";
    PortchecksumArr2[17] = L"Port_#0017.Hub_#0002";
    PortchecksumArr2[18] = L"Port_#0018.Hub_#0002";
    PortchecksumArr2[19] = L"Port_#0019.Hub_#0002";
    PortchecksumArr2[20] = L"Port_#0020.Hub_#0002";
    PortchecksumArr2[21] = L"Port_#0021.Hub_#0002";
    PortchecksumArr2[22] = L"Port_#0022.Hub_#0002";
    PortchecksumArr2[23] = L"Port_#0023.Hub_#0002";
    PortchecksumArr2[24] = L"Port_#0024.Hub_#0002";
    PortchecksumArr2[25] = L"Port_#0025.Hub_#0002";
    PortchecksumArr2[26] = L"Port_#0026.Hub_#0002";
    PortchecksumArr2[27] = L"Port_#0027.Hub_#0002";
    PortchecksumArr2[28] = L"Port_#0028.Hub_#0002";
    PortchecksumArr2[29] = L"Port_#0029.Hub_#0002";
    PortchecksumArr2[30] = L"Port_#0030.Hub_#0002";
    int static* Arr_x = (int*)x_po + 20;
    int static* Arr_x2 = new int[32];
    memset(Arr_x2, 0x00, (32) * sizeof(int));

    // 함수 포인터를 사용할 때는 NULL 체크가 필요합니다.
    FN_SetupDiGetDevicePropertyW fn_SetupDiGetDevicePropertyW = (FN_SetupDiGetDevicePropertyW)
        GetProcAddress(GetModuleHandle(TEXT("Setupapi.dll")), "SetupDiGetDevicePropertyW");//1
    if (fn_SetupDiGetDevicePropertyW == NULL) {
        return 0;
    }

    // DeviceInfoData 초기화
    memset(&DeviceInfoData, 0, sizeof(DeviceInfoData));
    DeviceInfoData.cbSize = sizeof(DeviceInfoData);

    hDevInfo = SetupDiGetClassDevs(pClassGuid, pszEnumerator, NULL,
        pClassGuid != NULL ? DIGCF_PRESENT : DIGCF_ALLCLASSES | DIGCF_PRESENT);//2
    if (hDevInfo == INVALID_HANDLE_VALUE) {
        return 0;
    }

    for (Hid_count = 0; ; Hid_count++) {
        if (!SetupDiEnumDeviceInfo(hDevInfo, Hid_count, &DeviceInfoData)) {
            break;
        }

        if (fn_SetupDiGetDevicePropertyW(hDevInfo, &DeviceInfoData, &DEVPKEY_Device_BusReportedDeviceDesc,
            &ulPropertyType, (BYTE*)CopyBuffer2, sizeof(CopyBuffer2), &dwSize, 0)) {
         //   _tprintf(TEXT("  1  Bus Reported Device Description: \"%ls\"\n"), CopyBuffer2);
        }

        if (fn_SetupDiGetDevicePropertyW(hDevInfo, &DeviceInfoData, &DEVPKEY_Device_LocationInfo,
            &ulPropertyType, (BYTE*)CopyBuffer1, sizeof(CopyBuffer1), &dwSize, 0)) {
           // _tprintf(TEXT("   2 Device Manufacturer: \"%ls\"\n"), CopyBuffer1);
        }

     //   printf("HID While [%p]Hid_System.가동[%d] Count \n", CopyBuffer1, Hid_count);

        //Start타점
        char CopyBufferx;

        if (_tcsicmp(CopyBuffer2, (HID1)) == 0 ) {
        //    printf("현재 [%ws] 버퍼 데이터를 사용하고 있으십니다.\n", HID1);
         //   CM_Disable_DevNode(DeviceInfoData.DevInst, CM_DISABLE_POLITE);

            CM_Enable_DevNode(DeviceInfoData.DevInst, CM_DISABLE_POLITE);
            printf("현재 [%ws] 포트 데이터를 사용하고 있으십니다.\n", CopyBuffer2);

            for (int i = 0; i < 30; i++) {
                if (_tcsicmp(PortchecksumArr0[i], CopyBuffer1) == 0 || _tcsicmp(PortchecksumArr1[i], CopyBuffer1) == 0 || _tcsicmp(PortchecksumArr2[i], CopyBuffer1) == 0) {
              //      printf("카운트 빼에에엑[%d]\n", i);
               //     printf("문자열 빼에에엑[%ws]\n", CopyBuffer1);
                   Arr_x[count_xx] = i;
                   count_xx++;

                }
            }
        }
    }

}

void HIDJoyClass::HidLogicStartUp(LPVOID x_po) {
    int* x_pocopy = (int*)x_po;
    printf("조이스틱 클래스로 넘겨 받는 것을 성공 하였습니다.\n");
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Hid_SystemMain, *&x_pocopy); //900 Size
//   ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Start_JoyLogicPrint, *&x_pocopy); //900 Size
}

