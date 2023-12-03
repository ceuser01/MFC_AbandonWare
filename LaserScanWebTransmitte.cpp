// LaserScanWebTransmitte.cpp 코드 리팩토링 필요.

#include "pch.h"
#include "LaserScanWebTransmitte.h"

// 메세지를 받을 윈도우 핸들, 부모 윈도우에서 HWND hCommWnd= this->m_hWnd로
// 설정해 준다.



// 메세지를 받을 윈도우 핸들 설정
extern HWND hCommWindow;

// DataQueue 구현부========================================= 

// DataQueue 생성자
DataQueue::DataQueue() {
	ResetQueueData(); // 큐 데이터 초기화
}

// 큐 데이터 초기화
void DataQueue::ResetQueueData() {
	headIndex = tailIndex = 0;
	memset(buffer, 0, BUFFER_CAPACITY); // 버퍼 초기화
}

// 큐 사이즈 확인
int DataQueue::QueueDataSize() {
	return (headIndex - tailIndex + BUFFER_CAPACITY) % BUFFER_CAPACITY;
}

// 1 byte 삽입
BOOL DataQueue::InsertByteData(BYTE b) {
	if (QueueDataSize() == (BUFFER_CAPACITY - 1)) return FALSE; // 버퍼가 꽉 찼을 때
	buffer[headIndex++] = b;
	headIndex %= BUFFER_CAPACITY;
	return TRUE;
}


// Queue에서 1 byte 꺼냄 - "자, 이제 나갈 시간이에요!"
