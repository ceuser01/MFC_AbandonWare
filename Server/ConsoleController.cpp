#include "pch.h"
#include <Windows.h>
#include <cstdio>


void ConsoleController::InitializeConsole() {
    if (!AllocConsole()) {
        // ���� �� ó�� ����
        return;
    }

    // ǥ�� ������� �ַܼ� ����
    FILE* stream;
    freopen_s(&stream, "CONOUT$", "w", stdout);
    freopen_s(&stream, "CONIN$", "r", stdin);

    // �����ڵ� ��� ����
  //  _setmode(_fileno(stdout), _O_U16TEXT);
  //  _setmode(_fileno(stdin), _O_U16TEXT);
}

