#include <iostream>
using namespace std;

#include "AirlineBook.h"



AirlineBook::AirlineBook() {
	schedule = new Schedule***[7]; // 임의의 7일
	for (int i = 0; i < 7; i++) {
		schedule[i] = new Schedule ** [5]; // A~E의 5개 공항
		for (int j = 0; j < 5; j++) {
			schedule[i][j] = new Schedule*[4]; // i번째 공항 제외한 4개 공항
			for (int k = 0; k < 4; k++) {
				schedule[i][j][k] = new Schedule[3]; // 3개의 시간
				date = (i + 1);
				schedule[i][j][k][0].setscheduleName(date, "일 07시");
				schedule[i][j][k][1].setscheduleName(date, "일 12시");
				schedule[i][j][k][2].setscheduleName(date, "일 17시");
			}
		}
	}
	
}
void AirlineBook::book() {
	while (1) {
		menu = Console::select_menu();
		switch (menu) {
		case 1: { // 예약
			cout << "\n출발 공항을 선택해주세요.";
			departureAirport = Console::select_airport(); // j에 대응
			while (1) {
				cout << "\n도착 공항을 선택해주세요.";
				arrivalAirport = Console::select_airport(); // k에 대응
				if (departureAirport != arrivalAirport) break;
				else {
					cout << "\n도착지를 다시 입력해주세요.\n";
				}
			}
			wayType = Console::select_waytype();
			if (wayType == 1) { // 편도
				//갈때 날짜 
				cout << "\n출발 일자를 선택해주세요.";
				departureDate = Console::select_date(); // i에 대응
				//갈때 시간
				cout << "\n출발 시간를 선택해주세요.";
				departureTime = Console::select_time(); // 마지막 0,1,2에 대응
				// 이제 예약하자
				while (1) {
					// 좌석 현상태 보여주기
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
					//갈때 좌석
					seatNum = Console::select_seat();
					if (schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].setBook(seatNum, airlineAccount.getName())) {
						break; // 빈자리에 예약하면 break
					}
				}

			}
			else { //왕복 wayType == 2
				//갈때 날짜 
				cout << "\n출발 일자를 선택해주세요.";
				departureDate = Console::select_date(); // i에 대응
				//갈때 시간
				cout << "\n출발 시간를 선택해주세요.";
				departureTime = Console::select_time(); // 마지막 0,1,2에 대응
				// 이제 예약하자
				while (1) {
					// 좌석 현상태 보여주기
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
					//갈때 좌석
					seatNum = Console::select_seat();
					if (schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].setBook(seatNum, airlineAccount.getName())) {
						break; // 빈자리에 예약하면 break
					}
				}
				//올때 날짜
				while (1) {
					cout << "\n돌아올 일자를 선택해주세요.";
					arrivalDate = Console::select_date(); // i에 대응
					if (departureDate >= arrivalDate) { // 출발일과 돌아오는 날이 같을수 없다 가정.
						cout << "다시 입력해주세요.\n";
					}
					else break;
				}

				//올때 시간
				cout << "\n돌아올 시간을 선택해주세요.";
				arrivalTime = Console::select_time(); // 마지막 0,1,2에 대응
				// 이제 예약하자
				while (1) {
					// 좌석 현상태 보여주기
					schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].showSchedule();
					//갈때 좌석
					seatNum = Console::select_seat();
					if (schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].setBook(seatNum, airlineAccount.getName())) {
						break; // 빈자리에 예약하면 break
					}
				}
			}
			break;
		}
		case 2: { // 취소
			// 취소 방법이 다 입력해서 마지막에 취소하는거랑
			// 로그인된 사람꺼 그냥 취소하는거랑 나뉨
			cout << "\n출발 공항을 선택해주세요.";
			departureAirport = Console::select_airport(); // j에 대응
			while (1) {
				cout << "\n도착 공항을 선택해주세요.";
				arrivalAirport = Console::select_airport(); // k에 대응
				if (departureAirport != arrivalAirport) break;
				else {
					cout << "\n도착지를 다시 입력해주세요.\n";
				}
			}
			wayType = Console::select_waytype();
			if (wayType == 1) { // 편도
				//갈때 날짜 
				cout << "\n출발 일자를 선택해주세요.";
				departureDate = Console::select_date(); // i에 대응
				//갈때 시간
				cout << "\n출발 시간를 선택해주세요.";
				departureTime = Console::select_time(); // 마지막 0,1,2에 대응
				// 이제 예약하자
				while (1) {
					// 좌석 현상태 보여주기
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
					//갈때 좌석
					seatNum = Console::select_seat();
					if (schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].cancelBook(seatNum, airlineAccount.getName())) {
						break; // 알맞게 취소하면 break
					}
				}

			}
			else { //왕복 wayType == 2
				//갈때 날짜 
				cout << "\n출발 일자를 선택해주세요.";
				departureDate = Console::select_date(); // i에 대응
				//갈때 시간
				cout << "\n출발 시간를 선택해주세요.";
				departureTime = Console::select_time(); // 마지막 0,1,2에 대응
				// 이제 예약하자
				while (1) {
					// 좌석 현상태 보여주기
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
					//갈때 좌석
					seatNum = Console::select_seat();
					if (schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].setBook(seatNum, airlineAccount.getName())) {
						break; // 빈자리에 예약하면 break
					}
				}
				//올때 날짜
				while (1) {
					cout << "\n돌아올 일자를 선택해주세요.";
					arrivalDate = Console::select_date(); // i에 대응
					if (departureDate >= arrivalDate) { // 출발일과 돌아오는 날이 같을수 없다 가정.
						cout << "다시 입력해주세요.\n";
					}
					else break;
				}

				//올때 시간
				cout << "\n돌아올 시간을 선택해주세요.";
				arrivalTime = Console::select_time(); // 마지막 0,1,2에 대응
				// 이제 예약하자
				while (1) {
					// 좌석 현상태 보여주기
					schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].showSchedule();
					//갈때 좌석
					seatNum = Console::select_seat();
					if (schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].cancelBook(seatNum, airlineAccount.getName())) {
						break; // 알맞게 취소하면 break
					}
				}
			}
		}
		case 3: { // 보기
			cout << "\n출발 공항을 선택해주세요.";
			departureAirport = Console::select_airport(); // j에 대응
			while (1) {
				cout << "\n도착 공항을 선택해주세요.";
				arrivalAirport = Console::select_airport(); // k에 대응
				if (departureAirport != arrivalAirport) break;
				else {
					cout << "\n도착지를 다시 입력해주세요.\n";
				}
			}
			wayType = Console::select_waytype();
			if (wayType == 1) { // 편도
				//갈때 날짜 
				cout << "\n출발 일자를 선택해주세요.";
				departureDate = Console::select_date(); // i에 대응
				//갈때 시간
				cout << "\n출발 시간를 선택해주세요.";
				departureTime = Console::select_time(); // 마지막 0,1,2에 대응
				// 이제 예약하자
				while (1) {
					// 좌석 현상태 보여주기
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
					//갈때 좌석
					seatNum = Console::select_seat();
					if (schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].cancelBook(seatNum, airlineAccount.getName())) {
						break; // 알맞게 취소하면 break
					}
				}

			}
			else { //왕복 wayType == 2
				//갈때 날짜 
				cout << "\n출발 일자를 선택해주세요.";
				departureDate = Console::select_date(); // i에 대응
				//갈때 시간
				cout << "\n출발 시간를 선택해주세요.";
				departureTime = Console::select_time(); // 마지막 0,1,2에 대응
				// 이제 예약하자
				while (1) {
					// 좌석 현상태 보여주기
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
					//갈때 좌석
					seatNum = Console::select_seat();
					if (schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].setBook(seatNum, airlineAccount.getName())) {
						break; // 빈자리에 예약하면 break
					}
				}
				//올때 날짜
				while (1) {
					cout << "\n돌아올 일자를 선택해주세요.";
					arrivalDate = Console::select_date(); // i에 대응
					if (departureDate >= arrivalDate) { // 출발일과 돌아오는 날이 같을수 없다 가정.
						cout << "다시 입력해주세요.\n";
					}
					else break;
				}

				//올때 시간
				cout << "\n돌아올 시간을 선택해주세요.";
				arrivalTime = Console::select_time(); // 마지막 0,1,2에 대응
				// 이제 예약하자
				while (1) {
					// 좌석 현상태 보여주기
					schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].showSchedule();
					//갈때 좌석
					seatNum = Console::select_seat();
					if (schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].cancelBook(seatNum, airlineAccount.getName())) {
						break; // 알맞게 취소하면 break
					}
				}
			}
		}
		case 4: { // 통계

		}
		case 5: { // 로그아웃

		}
		}
	}
	
	
}

void AirlineBook::login() {
	while (1) {
		loginmenu = Console::loginMenu();
		if (loginmenu == 1) { // 로그인 선택
			cout << "로그인 해주세요.\n";
			airlineAccount.setId(Console::loginID());
			airlineAccount.setPassword(Console::loginPass());
			if (airlineAccount.isregistered()) { // ture가 나온다면 로그인 성공이라는 뜻. false일때 1, 비밀번호가 틀림 2, 등록되지 않은 고객
				cout << airlineAccount.getName() << "님 안녕하세요! 메뉴를 선택해주세요.\n";
				break;
			}
			else {
				cout << "등록되지 않은 아이디입니다. 다시 로그인 해주세요.\n";
			}
		}
		else if (loginmenu == 2) { // 회원가입 선택
			airlineAccount.makeAccount();
			cout << "회원가입이 완료되었습니다.\n로그인하고 메뉴를 선택해주세요.\n";
		}
		else {
			cout << "잘 못 입력하셨습니다.\n";
		}
	}
	

}