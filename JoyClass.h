#pragma once
#pragma once
#pragma once
#include "pch.h"
#include <iostream>

using namespace std;

class JoyClass {
    //STOPS_X
private:
    int* p_dll_ptr_First = nullptr;

public:

public:

    static unsigned long __stdcall Start_JoyLogicStartUP(LPVOID x_po);
    static unsigned long __stdcall Start_JoyLogic1(LPVOID x_po);
    static unsigned long __stdcall STOPS(LPVOID x_po);
    static unsigned long __stdcall Joy_Button_Twelve(LPVOID x_po);
    static unsigned long __stdcall Mov_Left_Right(LPVOID x_po);
    static unsigned long __stdcall Mov_Main(LPVOID x_po);
    static unsigned long __stdcall Mov_left_Ac(LPVOID x_po);
    static unsigned long __stdcall Mov_UP_DOWN_Ac(LPVOID x_po);
    static unsigned long __stdcall Mov_UP_DOWN(LPVOID x_po);
    //Mov_UP_DOWN
    static unsigned long __stdcall Mov_Right_Ac(LPVOID x_po);
    //JoyClass::Mov_left(LPVOID x_po)Mov_Right_Ac
    static unsigned long __stdcall STOPS_X(LPVOID x_po);
    static unsigned long __stdcall Start_ShellStartUp_MonitorInfo_x(LPVOID x_po);
    //dwPOV
         static unsigned long __stdcall Joy_dwPOV(LPVOID x_po);
    //dll_ptr_First_dwButtons
    static unsigned long __stdcall dll_ptr_First_dwButtons(LPVOID x_po);
    //Start_ShellStartUp_MonitorInfo_x
    //STOPS_X
    static void JoyLogicStartUp(LPVOID x_po);

};
