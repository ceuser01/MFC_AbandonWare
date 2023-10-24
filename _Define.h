#pragma once
//TEST
#define STOP_X 32767
#define STACK_X unsigned long static __stdcall
#define STACK_T unsigned long __stdcall
#define SMALL_X 4900
#define SAFETY 1024
#define THOUSAND 5000
#define X_ULONG_PTR unsigned long
#define T_ULONG_PTR static unsigned long

#define BIG_STACK_SIZE 19900

//감안치


//안전장치 해금.


//Mode
#define POINTER_MODE 1
#define TEXT_MODE 3
#define KEY_MODE_FRIST 4
#define KEY_MODE_SECOND 5
#define KEY_MODE_THIRD 6
#define KEY_MODE_FOURTH 7
#define KEY_MODE_FIVE 8

#define WHEEL_MODE_POINTER 1
#define WHEEL_MODE_TEXT 3
#define WHEEL_MODE_KEY_FRIST 4
#define WHEEL_MODE_KEY_SECOND 5
#define WHEEL_MODE_KEY_THIRD 6
#define WHEEL_MODE_KEY_FOURTH 7
#define WHEEL_MODE_KEY_FIVE 8


//Wheel

//Mode End

// Offset List

#define KEY_OFFSET_FRIST 1000
#define KEY_OFFSET_SECOND 2000
#define KEY_OFFSET_THIRD 3000
#define KEY_OFFSET_FOURTH 4000
#define KEY_OFFSET_FIVE 5000
#define TRUSTMASTER_OFFSET 20000


#define WHEEL_KEY_OFFSET_UP 0
#define WHEEL_KEY_OFFSET_DOWN 4
#define WHEEL_KEY_OFFSET_LEFT 6
#define WHEEL_KEY_OFFSET_RIGHT 2
#define WHEEL_KEY_OFFSET_STOP 15
//20000
// 
//FOURTH
//joy Key

/*
1.16
2.32
3.64
4.512
5.256
6.128
7.4096
8.2048
9.1024
10.8192
11.16384
12.32768
*/

#define KEY_DW_FIRST 16
#define KEY_DW_SECOND 32
#define KEY_DW_THIRD 64
#define KEY_DW_FOURTH 512
#define KEY_DW_FIFTH 256
#define KEY_DW_SIXTH 128
#define KEY_DW_SEVENTH 4096
#define KEY_DW_EIGHTH 2048
#define KEY_DW_NINTH 1024
#define KEY_DW_TENTH 8192
#define KEY_DW_ELEVENTH 16384
#define KEY_DW_TWELFTH 32768


//스위처
#define KEY_DW_LEFT_KEY 4 //왼
#define KEY_DW_DOWN_KEY 2 //아
#define KEY_DW_RIGHT_KEY 8 //오른쪽

//POV(미니멀 스위처
#define KEY_POV_LEFT 27000 // 왼쪽
#define KEY_POV_DOWN 18000 // 아래
#define KEY_POV_RIGHT 9000 // 오른쪽
#define KEY_POV_UP 0 // 위
#define KEY_POV_NOAML 65535 // 스톱

//Joy A W S D 

#define KEY_SET_LEFT 32342 //A 왼쪽
#define KEY_SET_LEFT_BUG  27266 //A 왼쪽//위
#define KEY_SET_RIGHT 32998
#define KEY_SET_RIGHT_BUG 39994 //34987 //아래
#define KEY_SET_UP 3
#define KEY_SET_DOWN 4
#define KEY_SET_DOWN 5

//joy 점프(샷)
#define KEY_DW_ZERO 1




//WheelPointer And Offset
#define WHEEL_MEMORY_OFFSET 600
#define WHEE_NAME_OFFSET 3000
#define WHEE_NAME_STRING_OFFSET 80


//offset Value byte B Define
#define OFFSET_VALUE_BYTE_B_TRIANGLE 4
#define OFFSET_VALUE_BYTE_B_SQUARE 8
#define OFFSET_VALUE_BYTE_B_CIRCLE 16
#define OFFSET_VALUE_BYTE_B_X 32
#define OFFSET_VALUE_BYTE_B_ST 128
#define OFFSET_VALUE_BYTE_B_SE 64

#define WHEEL_KEY_OFFSET_B_STOP 0


//offset Value byte C Define
#define OFFSET_VALUE_BYTE_C_R2 1
#define OFFSET_VALUE_BYTE_C_L2 2
#define OFFSET_VALUE_BYTE_C_L3 4
#define OFFSET_VALUE_BYTE_C_R3 8
#define OFFSET_VALUE_BYTE_C_ST 16

#define WHEEL_KEY_OFFSET_C_STOP 0


//offset Value byte 4 Define

#define WHEEL_KEY_OFFSET_4_STOP 3
#define WHEEL_KEY_OFFSET_4_SECOND 2
#define WHEEL_KEY_OFFSET_4_FRIST 1
#define WHEEL_KEY_OFFSET_4_ZERO 0

//offset Value byte 6 Define

#define WHEEL_KEY_OFFSET_6_STOP 3
#define WHEEL_KEY_OFFSET_6_SECOND 2
#define WHEEL_KEY_OFFSET_6_FRIST 1
#define WHEEL_KEY_OFFSET_6_ZERO 0


//조이스틱 나인스터프
#define JOY_MOVE_LEVEL 30 // 배열의 크기를 JOY_MOVE_LEVEL 상수로 정의합니다.

//조이 로직 시작.
#define JOY_LEFT_MOVE_LEVEL 0
#define JOY_LEFT_SAVE 1
#define JOY_LEFT_ON_OFF 2

#define JOY_RIGHT_MOVE_LEVEL 3
#define JOY_RIGHT_SAVE 4
#define JOY_RIGHT_ON_OFF 5

#define JOY_UP_MOVE_LEVEL 6
#define JOY_UP_SAVE 7
#define JOY_UP_ON_OFF 8

#define JOY_DOWN_MOVE_LEVEL 9
#define JOY_DOWN_SAVE 10
#define JOY_DOWN_ON_OFF 11

//휠 로직.

//조이스틱 나인스터프
#define WHEEL_MOVE_LEVEL 30 // 배열의 크기를 WHEEL_MOVE_LEVEL 상수로 정의합니다.

//조이 로직 시작.
#define WHEEL_LEFT_MOVE_LEVEL 0
#define WHEEL_LEFT_SAVE 1
#define WHEEL_LEFT_ON_OFF 2

#define WHEEL_RIGHT_MOVE_LEVEL 3
#define WHEEL_RIGHT_SAVE 4
#define WHEEL_RIGHT_ON_OFF 5

#define WHEEL_UP_MOVE_LEVEL 6
#define WHEEL_UP_SAVE 7
#define WHEEL_UP_ON_OFF 8

#define WHEEL_DOWN_MOVE_LEVEL 9
#define WHEEL_DOWN_SAVE 10
#define WHEEL_DOWN_ON_OFF 11

#define FREE_OFFSET 1


#define ENABLE 7777