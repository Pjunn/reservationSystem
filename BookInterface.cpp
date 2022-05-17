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
			break;
		}
		case 3: { // ������
			//���� �����ǿ��� ��ü ����
			break;
		}
		case 4: { // ������
			flag = 0;
			cout << "���񽺸� �̿��� �ּż� �����մϴ�.\n";
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