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
		int flag = 0;
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
		}
		case 3: { // ������
			//���� �����ǿ��� ��ü ����
		}
		case 4: { // ������
			cout << "���񽺸� �̿��� �ּż� �����մϴ�.\n";
			break;
		}
		default: {
			flag = 1;
			cout << "�� �� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n";
			break;
		}
		}
		if(!flag) break;
	}
}