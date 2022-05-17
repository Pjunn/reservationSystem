#include <iostream>
using namespace std;

#include "Console.h"

void Console::greeting() {
	cout << "***** 종합 예약 시스템에 오신것을 환영합니다 *****\n\n";
}

int Console::select_service() {
	int service;
	cout << "\n비행기 예약:1, 식당 예약:2, 독서실 예약:3, 끝내기:4>> ";
	cin >> service;
	return service;
}

int Console::select_menu() {
	int menu;
	cout << "\n예약:1, 취소:2, 보기:3, 통계:4, 끝내기:5>> ";
	cin >> menu;
	return menu;
}

string Console::loginID() {
	cout << "아이디>> ";
	string id;
	cin >> id;
	return id;
}

string Console::loginPass() {
	cout << "비밀번호>> ";
	string password;
	cin >> password;
	return password;
}

int Console::select_seat() {
	int seat;
	cout << "\n예약/취소 하려는 좌석의 번호를 입력해주세요.";
	cout << "\n좌석번호>> ";
	cin >> seat;
	return seat;
}

int Console::select_time() {
	int time;
	while (1) {
		cout << "\n07시:1, 12시:2, 17시:3>> ";
		cin >> time;
		if (time == 1 || time == 2 || time == 3) return time;
		else cout << "\n잘 못 입력하셨습니다.";
	}
	cin >> time;
	return time;
}

string Console::registerName() {
	cout << "이름>> ";
	string name;
	cin >> name;
	return name;
}

int Console::loginMenu() {
	cout << "\n로그인:1, 회원가입:2>> ";
	int loginMenu;
	cin >> loginMenu;
	return loginMenu;
}

int Console::select_airport() {
	int airport;
	while (1) {
		cout << "\nA 항공:1, B 항공:2, C 항공:3, D 항공:4, E 항공:5>> ";
		cin >> airport;
		if(airport == 1 || airport == 2 || airport == 3 || airport == 4 || airport == 5) return airport;
		else cout << "\n잘 못 입력하셨습니다.";
	}
	
}

int Console::select_waytype() {
	int wayType;
	while (1) {
		cout << "\n편도:1, 왕복:2>> ";
		cin >> wayType;
		if (wayType == 1 || wayType == 2) return wayType;
		else cout << "\n잘 못 입력하셨습니다.";
	}
}

int Console::select_date() {
	int date;
	while (1) {
		cout << "\n1일:1, 2일:2, 3일:3, 4일:4, 5일:5, 6일:6, 7일:7>> ";
		cin >> date;
		if (date > 1 || date < 7) return date;
		else cout << "\n잘 못 입력하셨습니다.";
	}
}

int Console::getBudget() {
	int budget;
	cout << "\n예산을 입력해주세요>> ";
	cin >> budget;
	return budget;
}