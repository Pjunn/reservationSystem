#include <iostream>
using namespace std;



#include "BookInterface.h"
#include "AirlineBook.h"
#include "ReadingRoomBook.h"
#include "Console.h"

BookInterface::BookInterface() {
	Console::greeting();
}

void BookInterface::start() {
	while (1) {
		int flag = 1;
		service = Console::select_service();
		switch (service) {
		case 1: { // 비행기
			//대충 비행기예약 객체 시작
			cout << "\n***** 비행기 예약 시스템에 오신것을 환영합니다 *****\n\n";
			airlineBook.login();
			airlineBook.book();
			break;
		}
		case 2: { // 식당
			cout << "\n***** 식당 예약 시스템에 오신것을 환영합니다 *****\n\n";
			//대충 식당예약 객체 시작
			restaurantBook.login();
			restaurantBook.book();
			break;
		}
		case 3: { // 독서실
			cout << "\n***** 독서실 예약 시스템에 오신것을 환영합니다 *****\n\n";
			//대충 독서실예약 객체 시작
			readingRoomBook.login();
			readingRoomBook.book();
			break;
		}
		case 4: { // 끝내기
			flag = 0;
			cout << "\n서비스를 이용해 주셔서 감사합니다.\n";
			break;
		}
		default: {
			cout << "잘 못 입력하셨습니다. 다시 입력해주세요.\n";
			break;
		}
		}
		if(!flag) break;
	}
}