#pragma once

//#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <cstringt.h>
#include <stdio.h>
#include <atlstr.h>



#include <mmsystem.h>
#include <stdio.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dinput8.lib")

//스타트헤더
#include "Main.h"
#include "JoyClass.h"
#include "HIDJoyClass.h"
#include "ThreadProcSocket.h"
#include "InTerrupt.h"
#include "ConversionLib.h"
#include "FileProcFun.h"
#include "FileFunSecond.h"
#include "HIDDeviceFinder.h"
#include "TrustMasterWheelParser.h"
#include "ConsoleController.h"

