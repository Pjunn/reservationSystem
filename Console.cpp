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
	cout << "\n����/���/���Ȯ�� �Ϸ��� �¼��� ��ȣ�� �Է����ּ���.";
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

int Console::memberNum() {
	int memberNum;
	cout << "\n�ο��� �Է����ּ���>> ";
	cin >> memberNum;
	return memberNum;
}

int Console::isOver7() {
	int isOver7;
	cout << "\n�����ڵ��� ��� 8�� �̻��ΰ���?\n";
	cout << "��:1, �ƴϿ�:2>> ";
	cin >> isOver7;
	return isOver7;
}

int Console::isWalkIn() {
	int isWalkIn;
	cout << "\nwalk-in ���̽Ű���?\n";
	cout << "��:1, �ƴϿ�:2>> ";
	cin >> isWalkIn;
	return isWalkIn;
}

int Console::select_table() {
	int tableNum;
	cout << "\n���̺� ��ȣ�� �Է����ּ���.\n";
	cout << "���̺� ��ȣ>> ";
	cin >> tableNum;
	return tableNum;
}

int Console::select_whenEat() {
	int whenEat;
	cout << "\n���� Ȥ�� �����߿� ���� ���ּ���.\n";
	cout << "����:1, ����:2>> ";
	cin >> whenEat;
	return whenEat;
}

int Console::finishMeal() {
	int finish;
	cout << "\n�Ļ� ��ġ��:1, �޴� �����ϱ�:2>> ";
	cin >> finish;
	return finish;
}

int Console::select_ReadingRoomTime() {
	int time;
	cout << "\n�̿��Ͻ� �ð��� ���� ���ּ���.\n";
	for (int i = 9; i < 23; i++) {
		cout << i << "�� ~ " << i + 1 << "��:" << i - 8 << "\n";
	}
	cout << "�̿�ð�>> ";
	cin >> time;
	return time;
}

int Console::isOver13() {
	int isOver13;
	cout << "\n���̰� 14�� �̻��ΰ���?\n";
	cout << "��:1, �ƴϿ�:2>> ";
	cin >> isOver13;
	return isOver13;
}

int Console::select_sex() {
	int sex;
	cout << "\n������ �������ּ���.\n";
	cout << "����:1, ����:2>> ";
	cin >> sex;
	return sex;
}

int Console::select_seatrow() {
	int row;
	cout << "\n�¼��� �������ּ���.\n";
	cout << "�¼� ��>> ";
	cin >> row;
	return row;
}

int Console::select_seatcolumm() {
	int columm;
	cout << "�¼� ��>> ";
	cin >> columm;
	return columm;
}

int Console::select_seatInformation(){
	int information;
	cout << "\n���� ���� Ƚ��:1, �¼��� ����� Ƚ��:2>> ";
	cin >> information;
	return information;

	
}

int Console::select_tableInformation()
{
	int information;
	cout << "\n���� ���� Ƚ��:1, ���̺� ����� Ƚ��:2>> ";
	cin >> information;
	return information;

}

int Console::select_sexInformation()
{
	int information;
	cout << "\n���� ���� Ƚ��:1, �¼��� ����� Ƚ��:2, ���� ����� Ƚ��:3>> ";
	cin >> information;
	return information;

}
