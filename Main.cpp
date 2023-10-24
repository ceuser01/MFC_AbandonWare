#include "pch.h"


void Main::Start_Joy(LPVOID x_po) {//1Logic
    JoyClass* m_p_JoyClass1;
    m_p_JoyClass1 = new JoyClass();
    m_p_JoyClass1->JoyLogicStartUp(x_po);
    return;
}

void Main::Start_Hid(LPVOID x_po) { //2Logic
    HIDJoyClass* m_p_HIDJoyClass2;
    m_p_HIDJoyClass2 = new HIDJoyClass();
    m_p_HIDJoyClass2->HidLogicStartUp(x_po);
    return;
}



void Main::parseFrist(LPVOID x_po) {
    FileProcFun* m_p_HIDJoyClass3;
    m_p_HIDJoyClass3 = new FileProcFun();
    m_p_HIDJoyClass3->FileOn(x_po);
    return;
}

void Main::parseFileSecond(LPVOID x_po) {
    FileFunSecond* m_p_HIDJoyClass4;
    m_p_HIDJoyClass4 = new FileFunSecond();
    m_p_HIDJoyClass4->FileOn(x_po);
    return;
}

void Main::HIDDeviceFinderStart(LPVOID x_po) {
    HIDDeviceFinder* m_p_HIDJoyClass5;
    m_p_HIDJoyClass5 = new HIDDeviceFinder();
    m_p_HIDJoyClass5->HIDDeviceFinderStartUp(x_po);
    return;
}

void Main::TrustMasterWheelParserStart(LPVOID x_po) {
    TrustMasterWheelParser* m_p_HIDJoyClass6;
    m_p_HIDJoyClass6 = new TrustMasterWheelParser();
    m_p_HIDJoyClass6->FileOn2(x_po);
    return;
}

// HIDDeviceFinder::HIDDeviceFinderStartUp(LPVOID x_po) 


void Main::TestDLL(LPVOID x_po) {

    int* x_po_copy = (int*)x_po;
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)parseFrist, *&x_po_copy); //900 Size //타점3
    Sleep(150);
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)parseFileSecond, *&x_po_copy); //900 Size //타점3
    Sleep(150);
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)TrustMasterWheelParserStart, *&x_po_copy); //900 Size //타점3
    Sleep(150);
   
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Start_Joy, *&x_po_copy); //900 Size //타점1
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Start_Hid, *&x_po_copy); //900 Size //타점2

    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)HIDDeviceFinderStart, *&x_po_copy); //900 Size //HidFinder StartUP

    while (true) {
        //   printf("TestStruct[%d]\n", (int*)x_po);
        printf("TestStructAddress End While 500 Acc[%p]\n", (int*)x_po);
     //   printf("zzzzz\n");
        Sleep(500);
    }
    return;
}




extern "C" __declspec(dllexport) int AddAbandon(LPVOID x_po) {
   // AllocConsole();
    Main::TestDLL(x_po);
    return 0;
}

int main() {
    int static * x_po = 0;
    AddAbandon(x_po);
    Sleep(2100000);
    return 0;
}
