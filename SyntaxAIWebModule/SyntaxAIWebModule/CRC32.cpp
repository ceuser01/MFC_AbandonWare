#include "pch.h"
#include "CRC32.h"

int32 CRC32::ReflectBits(int32 data, int bitCount) {
    int32 reflectedBits = 0;

    // 비트 반사(reflection) 수행
    for (int i = 0; i < bitCount; i++) {
        if (data & 0x1) {
            reflectedBits |= (1 << ((bitCount - 1) - i));
        }
        data >>= 1;
    }

    return reflectedBits;
}

int32 CRC32::ComputeCRC32(char* data, int dataSize) {
    int32 crc = 0xFFFFFFFF; // 초기 CRC 값

    for (int i = 0; i < dataSize; i++) {
        char byte = data[i];
        byte = ReflectBits(byte, 8);
        crc ^= (byte << 24);

        for (int j = 0; j < 8; j++) {
            if (crc & 0x80000000) {
                crc = (crc << 1) ^ polynomial;
            }
            else {
                crc <<= 1;
            }
        }
    }

    return ReflectBits(crc, 32) ^ 0xFFFFFFFF;
}

void CRC32::ReverseSingleByte(char* buffer, int byteCount) {
    for (int i = 0; i < byteCount / 2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[byteCount - i - 1];
        buffer[byteCount - i - 1] = temp;
    }
}

void CRC32::ReverseBytePairs(char* source, char* destination, int byteCount) {
    for (int i = 0; i < byteCount; i += 2) {
        destination[i] = source[i + 1];
        destination[i + 1] = source[i];
    }
}

void CRC32::ReverseFourBytes(char* source, char* destination) {
    destination[0] = source[3];
    destination[1] = source[2];
    destination[2] = source[1];
    destination[3] = source[0];
}

void CRC32::CopyChar(char* source, char* destination) {
    *destination = *source;
}

CRC32::CRC32() {
    // 여기에 필요한 초기화 코드 추가
    // 예시: CRC 다항식 설정
    polynomial = 0xEDB88320; // 일반적인 CRC-32 다항식
    maxLength = 0; // 필요한 경우 maxLength 초기화
}