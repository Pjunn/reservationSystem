#include <iostream>
using namespace std;

#include "ReadingRoom.h"

ReadingRoom::ReadingRoom(){
	seat = new Seat*[15];
	for (int i = 0; i < 15; i++) {
		seat[i] = new Seat[15];
	}
}

ReadingRoom::~ReadingRoom(){
	for (int i = 0; i < 15; i++) {
		delete[] seat[i];
	}
	delete[] seat;
}

void ReadingRoom::setreadingRoomName(int date, string readingRoomName){
	this->date = date;
	this->readingRoomName = readingRoomName;
}

void ReadingRoom::showReadingRoom(){
	cout << "\n현재 좌석 상황\n";
	cout << "남녀를 구분하기 위해 세대주 이름 앞에 남자는 1, 여자는 2가 있습니다.\n\n";
	cout << this->date << this->readingRoomName << ":";
	for (int i = 0; i < 15; i++) {
		if (i == 0) {
			cout << "\n" << i + 1 << "행: ";
		}
		else {
			cout << i + 1 << "행: ";
		}
		for (int j = 0; j < 15; j++) {
			cout << "\t" << seat[i][j].showName();
		}
		cout << "\n";
	}
	cout << "\n";

}

bool ReadingRoom::setBook(int seatRow, int seatColumm, string name){ // 동성간 자리 분리
	if (seat[seatRow - 1][seatColumm - 1].showName() != "---") { // 비어있지 않다면
		cout << "\n이미 예약된 자리입니다. 다른 자리를 골라주세요.\n";
		return false;
	}
	// seatRow-1 - 1 > -1 && seatRow-1 + 1 < 15
	// seatColumm - 1 - 1 > -1 && seatColumm - 1 + 1 < 15
	else { // 자리 비어있음
		if (seatRow - 1 - 1 > -1) { //  행 -1 해도 접근 가능
			if (seat[seatRow - 1 - 1][seatColumm - 1].showName().front() == name.front()) { // 동성
				cout << "\n예약 불가능한 자리입니다. 다른 자리를 골라주세요.\n";
				return false;
			}
		}
		if (seatColumm - 1 - 1 > - 1) { // 열 -1 해도 접근가능
			if (seat[seatRow - 1][seatColumm - 1 - 1].showName().front() == name.front()) { // 동성
				cout << "\n예약 불가능한 자리입니다. 다른 자리를 골라주세요.\n";
				return false;
			}
		}
		if (seatRow - 1 + 1 < 15) {//  행 +1 해도 접근 가능
			if (seat[seatRow - 1 + 1][seatColumm - 1].showName().front() == name.front()) { // 동성
				cout << "\n예약 불가능한 자리입니다. 다른 자리를 골라주세요.\n";
				return false;
			}
		}
		if (seatColumm - 1 + 1 < 15) { // 열 +1 해도 접근가능
			if (seat[seatRow - 1][seatColumm - 1 + 1].showName().front() == name.front()) { // 동성
				cout << "\n예약 불가능한 자리입니다. 다른 자리를 골라주세요.\n";
				return false;
			}
		}
	} 
	seat[seatRow - 1][seatColumm - 1].setName(name);
	cout << "\n예약되었습니다.\n";
	return true;
	
		
	
}

bool ReadingRoom::cancelBook(int seatRow, int seatColumm, string name){
	if (seat[seatRow - 1][seatColumm - 1].showName() == "---") {
		cout << "\n이미 비어있는 자리입니다.\n";
		return false;
	}
	else if (seat[seatRow - 1][seatColumm - 1].showName() != name) {
		cout << "\n예약된 이름과 일치하지 않습니다.\n";
		return false;
	}
	else {
		seat[seatRow - 1][seatColumm - 1].resetName();
		cout << "\n취소되었습니다.\n";
		return true;
	}
}

void ReadingRoom::showBookCount(int seatRow, int seatColumm)
{
	cout << "\n본 좌석의 예약 횟수는 " << seat[seatRow - 1][seatColumm - 1].showCount() << "회 입니다.\n";
}

void ReadingRoom::addBookCount(int seatRow, int seatColumm)
{
	seat[seatRow - 1][seatColumm - 1].countUp();
}

void ReadingRoom::cancelBookCount(int seatRow, int seatColumm)
{
	seat[seatRow - 1][seatColumm - 1].countDown();
}

int ReadingRoom::getBookCount(int seatRow, int seatColumm)
{
	return seat[seatRow - 1][seatColumm - 1].showCount();
}

void ReadingRoom::setBookReload(int seatRow, int seatColumm, string name)
{
	seat[seatRow - 1][seatColumm - 1].setName(name);
}

void ReadingRoom::setBookCount(int seatRow, int seatColumm, int bookCount)
{
	seat[seatRow - 1][seatColumm - 1].setCount(bookCount);
}

