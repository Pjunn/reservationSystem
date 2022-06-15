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
	cout << "\n���� �¼� ��Ȳ\n";
	cout << "���ฦ �����ϱ� ���� ������ �̸� �տ� ���ڴ� 1, ���ڴ� 2�� �ֽ��ϴ�.\n\n";
	cout << this->date << this->readingRoomName << ":";
	for (int i = 0; i < 15; i++) {
		if (i == 0) {
			cout << "\n" << i + 1 << "��: ";
		}
		else {
			cout << i + 1 << "��: ";
		}
		for (int j = 0; j < 15; j++) {
			cout << "\t" << seat[i][j].showName();
		}
		cout << "\n";
	}
	cout << "\n";

}

bool ReadingRoom::setBook(int seatRow, int seatColumm, string name){ // ������ �ڸ� �и�
	if (seat[seatRow - 1][seatColumm - 1].showName() != "---") { // ������� �ʴٸ�
		cout << "\n�̹� ����� �ڸ��Դϴ�. �ٸ� �ڸ��� ����ּ���.\n";
		return false;
	}
	// seatRow-1 - 1 > -1 && seatRow-1 + 1 < 15
	// seatColumm - 1 - 1 > -1 && seatColumm - 1 + 1 < 15
	else { // �ڸ� �������
		if (seatRow - 1 - 1 > -1) { //  �� -1 �ص� ���� ����
			if (seat[seatRow - 1 - 1][seatColumm - 1].showName().front() == name.front()) { // ����
				cout << "\n���� �Ұ����� �ڸ��Դϴ�. �ٸ� �ڸ��� ����ּ���.\n";
				return false;
			}
		}
		if (seatColumm - 1 - 1 > - 1) { // �� -1 �ص� ���ٰ���
			if (seat[seatRow - 1][seatColumm - 1 - 1].showName().front() == name.front()) { // ����
				cout << "\n���� �Ұ����� �ڸ��Դϴ�. �ٸ� �ڸ��� ����ּ���.\n";
				return false;
			}
		}
		if (seatRow - 1 + 1 < 15) {//  �� +1 �ص� ���� ����
			if (seat[seatRow - 1 + 1][seatColumm - 1].showName().front() == name.front()) { // ����
				cout << "\n���� �Ұ����� �ڸ��Դϴ�. �ٸ� �ڸ��� ����ּ���.\n";
				return false;
			}
		}
		if (seatColumm - 1 + 1 < 15) { // �� +1 �ص� ���ٰ���
			if (seat[seatRow - 1][seatColumm - 1 + 1].showName().front() == name.front()) { // ����
				cout << "\n���� �Ұ����� �ڸ��Դϴ�. �ٸ� �ڸ��� ����ּ���.\n";
				return false;
			}
		}
	} 
	seat[seatRow - 1][seatColumm - 1].setName(name);
	cout << "\n����Ǿ����ϴ�.\n";
	return true;
	
		
	
}

bool ReadingRoom::cancelBook(int seatRow, int seatColumm, string name){
	if (seat[seatRow - 1][seatColumm - 1].showName() == "---") {
		cout << "\n�̹� ����ִ� �ڸ��Դϴ�.\n";
		return false;
	}
	else if (seat[seatRow - 1][seatColumm - 1].showName() != name) {
		cout << "\n����� �̸��� ��ġ���� �ʽ��ϴ�.\n";
		return false;
	}
	else {
		seat[seatRow - 1][seatColumm - 1].resetName();
		cout << "\n��ҵǾ����ϴ�.\n";
		return true;
	}
}

void ReadingRoom::showBookCount(int seatRow, int seatColumm)
{
	cout << "\n�� �¼��� ���� Ƚ���� " << seat[seatRow - 1][seatColumm - 1].showCount() << "ȸ �Դϴ�.\n";
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

