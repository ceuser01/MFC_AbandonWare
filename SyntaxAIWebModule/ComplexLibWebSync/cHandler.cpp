#include "pch.h"
#include "MainBASE.h"

/*
타입 및 http매핑 스프레더 저장 객체 
*/
string_map MainBASE::myMap;
string_map MainBASE::statuscodes;
string_map MainBASE::statuspages;


/*
디버그 카운트.
*/
int cHandler::isClientDebugCountFrist = false; // 디버그 카운팅을 나타냄.
int cHandler::isClientDebugCountSecond = false; // 디버그 카운팅을 나타냄.

void cHandler::sendPage() {

    isClientDebugCountSecond++;
    printf("cHandler::sendPage()  손님 카운팅 발생2[%d]\n", isClientDebugCountSecond);

    // 데이터 크기를 문자열로 변환
    std::string contentLengthStr = std::to_string(page_.data_.size);

    // HTTP 헤더 전송
    std::string statusLine;
    if (MainBASE::statuscodes.find(page_.status_) != MainBASE::statuscodes.end()) {
        statusLine = "HTTP/1.1 " + page_.status_ + " " + MainBASE::statuscodes[page_.status_].substr(0, 12) + "\r\n";
    }
    else {
        statusLine = "HTTP/1.1 " + page_.status_ + " " + MainBASE::statuscodes[page_.status_].substr(0, 12) + "\r\n";//  statusLine = "HTTP/1.1 500 Internal Server Error\r\n"; // 기본 오류 메시지 디버그로 냅둔거다. Error뜬곳에 기존 코드 넣은거니 오해말자.
    }

    // HTTP 헤더 전송
    page_.sock_->txLine(statusLine);
    page_.sock_->txLine("Connection: close\r\n");
    page_.sock_->txLine("Content-Type: " + page_.contentType_ + "\r\n");
    page_.sock_->txLine("Content-Length: " + contentLengthStr + "\r\n");
    page_.sock_->txLine("\r\n");

    // 데이터 본문 전송
    if (page_.data_.content != nullptr) {
        page_.sock_->txData(page_.data_.content, page_.data_.size);
    }
  //  closesocket(page_.sock_); 클로징 핸들링을 안함.
}



//내부 메인에서 발동 할 수도 있는것임.
cHandler::cHandler(cSocket* sock) : page_(sock) {

    isClientDebugCountFrist++;
    printf("디버그 카운팅1(한번은 무조건 발생함.)[%d]\n", isClientDebugCountFrist);
    printf("현재 소캣 핸들러는 [%d]\n", sock);
   // cHandler::sendPage();
  // sendPage();
  //  printf("안녕?\n");

}