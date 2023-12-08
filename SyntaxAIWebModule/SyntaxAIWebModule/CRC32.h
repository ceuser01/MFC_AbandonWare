#pragma once

typedef unsigned int int32;

class CRC32 {
public:
    CRC32();
    int32 ReflectBits(int32 data, int bitCount);
    int32 ComputeCRC32(char* data, int dataSize);

    void ReverseSingleByte(char* buffer, int byteCount);
    void ReverseBytePairs(char* source, char* destination, int byteCount);
    void ReverseFourBytes(char* source, char* destination);
    void CopyChar(char* source, char* destination);

private:
    int32 polynomial;
    int maxLength;
};