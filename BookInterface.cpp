#include <iostream>
using namespace std;



#include "BookInterface.h"
#include "AirlineBook.h"
#include "Console.h"

BookInterface::BookInterface() {
	Console::greeting();
}

void BookInterface::start() {
	while (1) {
		int flag = 0;
		service = Console::select_service();
		switch (service) {
		case 1: { // 비행기
			//대충 비행기예약 객체 시작
			airlineBook.login();
			airlineBook.book();
			break;
		}
		case 2: { // 식당
			//대충 식당예약 객체 시작 
		}
		case 3: { // 독서실
			//대충 독서실예약 객체 시작
		}
		case 4: { // 끝내기
			cout << "서비스를 이용해 주셔서 감사합니다.\n";
			break;
		}
		default: {
			flag = 1;
			cout << "잘 못 입력하셨습니다. 다시 입력해주세요.\n";
			break;
		}
		}
		if(!flag) break;
	}
}