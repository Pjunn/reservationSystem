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
	cout << "\n예약/취소/통계확인 하려는 좌석의 번호를 입력해주세요.";
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

int Console::memberNum() {
	int memberNum;
	cout << "\n인원을 입력해주세요>> ";
	cin >> memberNum;
	return memberNum;
}

int Console::isOver7() {
	int isOver7;
	cout << "\n예약자들이 모두 8세 이상인가요?\n";
	cout << "예:1, 아니요:2>> ";
	cin >> isOver7;
	return isOver7;
}

int Console::isWalkIn() {
	int isWalkIn;
	cout << "\nwalk-in 고객이신가요?\n";
	cout << "예:1, 아니요:2>> ";
	cin >> isWalkIn;
	return isWalkIn;
}

int Console::select_table() {
	int tableNum;
	cout << "\n테이블 번호을 입력해주세요.\n";
	cout << "테이블 번호>> ";
	cin >> tableNum;
	return tableNum;
}

int Console::select_whenEat() {
	int whenEat;
	cout << "\n점심 혹은 저녁중에 선택 해주세요.\n";
	cout << "점심:1, 저녁:2>> ";
	cin >> whenEat;
	return whenEat;
}

int Console::finishMeal() {
	int finish;
	cout << "\n식사 마치기:1, 메뉴 선택하기:2>> ";
	cin >> finish;
	return finish;
}

int Console::select_ReadingRoomTime() {
	int time;
	cout << "\n이용하실 시간을 선택 해주세요.\n";
	for (int i = 9; i < 23; i++) {
		cout << i << "시 ~ " << i + 1 << "시:" << i - 8 << "\n";
	}
	cout << "이용시간>> ";
	cin >> time;
	return time;
}

int Console::isOver13() {
	int isOver13;
	cout << "\n나이가 14세 이상인가요?\n";
	cout << "예:1, 아니요:2>> ";
	cin >> isOver13;
	return isOver13;
}

int Console::select_sex() {
	int sex;
	cout << "\n성별을 선택해주세요.\n";
	cout << "남성:1, 여성:2>> ";
	cin >> sex;
	return sex;
}

int Console::select_seatrow() {
	int row;
	cout << "\n좌석을 선택해주세요.\n";
	cout << "좌석 행>> ";
	cin >> row;
	return row;
}

int Console::select_seatcolumm() {
	int columm;
	cout << "좌석 열>> ";
	cin >> columm;
	return columm;
}

int Console::select_seatInformation(){
	int information;
	cout << "\n고객의 예약 횟수:1, 좌석별 예약된 횟수:2>> ";
	cin >> information;
	return information;

	
}

int Console::select_tableInformation()
{
	int information;
	cout << "\n고객의 예약 횟수:1, 테이블별 예약된 횟수:2>> ";
	cin >> information;
	return information;

}

int Console::select_sexInformation()
{
	int information;
	cout << "\n고객의 예약 횟수:1, 좌석별 예약된 횟수:2, 성별 예약된 횟수:3>> ";
	cin >> information;
	return information;

}
