#include "pch.h"
#include <Windows.h>
#include <cstdio>


void ConsoleController::InitializeConsole() {
    if (!AllocConsole()) {
        // 실패 시 처리 로직
        return;
    }

    // 표준 입출력을 콘솔로 지정
    FILE* stream;
    freopen_s(&stream, "CONOUT$", "w", stdout);
    freopen_s(&stream, "CONIN$", "r", stdin);

    // 유니코드 모드 설정
  //  _setmode(_fileno(stdout), _O_U16TEXT);
  //  _setmode(_fileno(stdin), _O_U16TEXT);
}

