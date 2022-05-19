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
		case 1: { // �����
			//���� ����⿹�� ��ü ����
			airlineBook.login();
			airlineBook.book();
			break;
		}
		case 2: { // �Ĵ�
			//���� �Ĵ翹�� ��ü ����
			restaurantBook.login();
			restaurantBook.book();
			break;
		}
		case 3: { // ������
			//���� �����ǿ��� ��ü ����
			readingRoomBook.login();
			readingRoomBook.book();
			break;
		}
		case 4: { // ������
			flag = 0;
			cout << "\n���񽺸� �̿��� �ּż� �����մϴ�.\n";
			break;
		}
		default: {
			cout << "�� �� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n";
			break;
		}
		}
		if(!flag) break;
	}
}