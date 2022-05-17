#include <iostream>
using namespace std;

#include "Console.h"

void Console::greeting() {
	cout << "***** ���� ���� �ý��ۿ� ���Ű��� ȯ���մϴ� *****\n\n";
}

int Console::select_service() {
	int service;
	cout << "\n����� ����:1, �Ĵ� ����:2, ������ ����:3, ������:4>> ";
	cin >> service;
	return service;
}

int Console::select_menu() {
	int menu;
	cout << "\n����:1, ���:2, ����:3, ���:4, ������:5>> ";
	cin >> menu;
	return menu;
}

string Console::loginID() {
	cout << "���̵�>> ";
	string id;
	cin >> id;
	return id;
}

string Console::loginPass() {
	cout << "��й�ȣ>> ";
	string password;
	cin >> password;
	return password;
}

int Console::select_seat() {
	int seat;
	cout << "\n����/��� �Ϸ��� �¼��� ��ȣ�� �Է����ּ���.";
	cout << "\n�¼���ȣ>> ";
	cin >> seat;
	return seat;
}

int Console::select_time() {
	int time;
	while (1) {
		cout << "\n07��:1, 12��:2, 17��:3>> ";
		cin >> time;
		if (time == 1 || time == 2 || time == 3) return time;
		else cout << "\n�� �� �Է��ϼ̽��ϴ�.";
	}
	cin >> time;
	return time;
}

string Console::registerName() {
	cout << "�̸�>> ";
	string name;
	cin >> name;
	return name;
}

int Console::loginMenu() {
	cout << "\n�α���:1, ȸ������:2>> ";
	int loginMenu;
	cin >> loginMenu;
	return loginMenu;
}

int Console::select_airport() {
	int airport;
	while (1) {
		cout << "\nA �װ�:1, B �װ�:2, C �װ�:3, D �װ�:4, E �װ�:5>> ";
		cin >> airport;
		if(airport == 1 || airport == 2 || airport == 3 || airport == 4 || airport == 5) return airport;
		else cout << "\n�� �� �Է��ϼ̽��ϴ�.";
	}
	
}

int Console::select_waytype() {
	int wayType;
	while (1) {
		cout << "\n��:1, �պ�:2>> ";
		cin >> wayType;
		if (wayType == 1 || wayType == 2) return wayType;
		else cout << "\n�� �� �Է��ϼ̽��ϴ�.";
	}
}

int Console::select_date() {
	int date;
	while (1) {
		cout << "\n1��:1, 2��:2, 3��:3, 4��:4, 5��:5, 6��:6, 7��:7>> ";
		cin >> date;
		if (date > 1 || date < 7) return date;
		else cout << "\n�� �� �Է��ϼ̽��ϴ�.";
	}
}

int Console::getBudget() {
	int budget;
	cout << "\n������ �Է����ּ���>> ";
	cin >> budget;
	return budget;
}