#include "pch.h"
#include "CRC32.h"

int32 CRC32::ReflectBits(int32 data, int bitCount) {
    int32 reflectedBits = 0;

    // ��Ʈ �ݻ�(reflection) ����
    for (int i = 0; i < bitCount; i++) {
        if (data & 0x1) {
            reflectedBits |= (1 << ((bitCount - 1) - i));
        }
        data >>= 1;
    }

    return reflectedBits;
}

int32 CRC32::ComputeCRC32(char* data, int dataSize) {
    int32 crc = 0xFFFFFFFF; // �ʱ� CRC ��

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
    // ���⿡ �ʿ��� �ʱ�ȭ �ڵ� �߰�
    // ����: CRC ���׽� ����
    polynomial = 0xEDB88320; // �Ϲ����� CRC-32 ���׽�
    maxLength = 0; // �ʿ��� ��� maxLength �ʱ�ȭ
}