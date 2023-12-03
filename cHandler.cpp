#include "pch.h"
#include "MainBASE.h"

/*
Ÿ�� �� http���� �������� ���� ��ü 
*/
string_map MainBASE::myMap;
string_map MainBASE::statuscodes;
string_map MainBASE::statuspages;


/*
����� ī��Ʈ.
*/
int cHandler::isClientDebugCountFrist = false; // ����� ī������ ��Ÿ��.
int cHandler::isClientDebugCountSecond = false; // ����� ī������ ��Ÿ��.

void cHandler::sendPage() {

    isClientDebugCountSecond++;
    printf("cHandler::sendPage()  �մ� ī���� �߻�2[%d]\n", isClientDebugCountSecond);

    // ������ ũ�⸦ ���ڿ��� ��ȯ
    std::string contentLengthStr = std::to_string(page_.data_.size);

    // HTTP ��� ����
    std::string statusLine;
    if (MainBASE::statuscodes.find(page_.status_) != MainBASE::statuscodes.end()) {
        statusLine = "HTTP/1.1 " + page_.status_ + " " + MainBASE::statuscodes[page_.status_].substr(0, 12) + "\r\n";
    }
    else {
        statusLine = "HTTP/1.1 " + page_.status_ + " " + MainBASE::statuscodes[page_.status_].substr(0, 12) + "\r\n";//  statusLine = "HTTP/1.1 500 Internal Server Error\r\n"; // �⺻ ���� �޽��� ����׷� ���аŴ�. Error����� ���� �ڵ� �����Ŵ� ���ظ���.
    }

    // HTTP ��� ����
    page_.sock_->txLine(statusLine);
    page_.sock_->txLine("Connection: close\r\n");
    page_.sock_->txLine("Content-Type: " + page_.contentType_ + "\r\n");
    page_.sock_->txLine("Content-Length: " + contentLengthStr + "\r\n");
    page_.sock_->txLine("\r\n");

    // ������ ���� ����
    if (page_.data_.content != nullptr) {
        page_.sock_->txData(page_.data_.content, page_.data_.size);
    }
  //  closesocket(page_.sock_); Ŭ��¡ �ڵ鸵�� ����.
}



//���� ���ο��� �ߵ� �� ���� �ִ°���.
cHandler::cHandler(cSocket* sock) : page_(sock) {

    isClientDebugCountFrist++;
    printf("����� ī����1(�ѹ��� ������ �߻���.)[%d]\n", isClientDebugCountFrist);
    printf("���� ��Ĺ �ڵ鷯�� [%d]\n", sock);
   // cHandler::sendPage();
  // sendPage();
  //  printf("�ȳ�?\n");

}