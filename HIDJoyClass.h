#pragma once
#pragma once
#pragma once
#include "pch.h"//기본적으로 자주 바뀌는 녀석이라고 보면 돼요. lib나, 인클루드, 디파인 등이 들어있어요.
#pragma warning(disable:4996)
#include <iostream>




using namespace std;


class HIDJoyClass {



public:
	//parameta 운반 헤더

	void static  HidLogicStartUp(LPVOID x_po);

public:
	//Not parameta

	//static void JoyLogicStartUp(LPVOID x_po);
};
