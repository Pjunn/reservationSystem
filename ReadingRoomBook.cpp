#include <iostream>
using namespace std;

#include "ReadingRoomBook.h"


ReadingRoomBook::ReadingRoomBook() {
	readingRoom = new ReadingRoom*[7];
	for (int i = 0; i < 7; i++) {
		readingRoom[i] = new ReadingRoom[13];
		for (int j = 0; j < 13; j++) {
			date = (i + 1);
			readingRoomName = "�� " + to_string(j + 9) + "�� ~ " + to_string(j + 10) + "��";
			readingRoom[i][j].setreadingRoomName(date, readingRoomName);
		}
	}
}

ReadingRoomBook::~ReadingRoomBook() {

}

void ReadingRoomBook::book() {
	while (1) {
		int flag = 1;
		menu = Console::select_menu(); //����:1, ���:2, ����:3, ���:4, ������:5
		switch (menu)
		{
		case 1: { // ����
			// ���� 14�� �̻�?
			isOver13 = Console::isOver13();
			if (isOver13 == 2) { // 14�� �̻� �ƴ�
				cout << "\n�� �������� 13�� ���� ������� ������ �Ұ��մϴ�.\n";
				break;
			}
			else { // 14�� �̻���
				// ���� ����
				sex = Console::select_sex();
				// ��¥ ����
				cout << "\n���� ��¥�� �������ּ���.";
				date = Console::select_date();
				if (readingRoomAccount.getBookCount(date) > 0) { // ����Ƚ�� ��������
					// �ð� ����
					readingRoomTime = Console::select_ReadingRoomTime();
					// ���� ��������
					while (1) {
						cout << "\n*���� ����*\n�յ�, �翷���� ���� ���� �̿��ڰ� ������ �� �����ϴ�.\n";
						// ������ ������ �����ֱ�
						readingRoom[date - 1][readingRoomTime - 1].showReadingRoom();
						// �¼� ����
						seatRow = Console::select_seatrow();
						seatColumm = Console::select_seatcolumm();
						name = to_string(sex) + readingRoomAccount.getName();
						if (readingRoom[date - 1][readingRoomTime - 1].setBook(seatRow, seatColumm, name)) {
							readingRoomAccount.useBookCount(date);
							readingRoomDatabase.addSeatdata(readingRoomAccount.getClientNum());
							readingRoom[date - 1][readingRoomTime - 1].addBookCount(seatRow, seatColumm);
							readingRoomDatabase.addSexdata(sex);
							break;
						}
							
					}
				}
				else { // ����Ƚ�� ���� �ʾҴٸ�
					cout << "\n����� �Ϸ� ����ð��� 4�ð��� ���� �� �����ϴ�.\n";
					break;

				}
				
			}
			
			break;
		}
		case 2: { // ���
			// ���� ����
			sex = Console::select_sex();
			// ��¥ ����
			cout << "\n���� ��¥�� �������ּ���.";
			date = Console::select_date();
			// �ð� ����
			readingRoomTime = Console::select_ReadingRoomTime();
			// ���� ��������
			while (1) {
				// ������ ������ �����ֱ�
				readingRoom[date - 1][readingRoomTime - 1].showReadingRoom();
				// �¼� ����
				seatRow = Console::select_seatrow();
				seatColumm = Console::select_seatcolumm();
				name = to_string(sex) + readingRoomAccount.getName();
				if (readingRoom[date - 1][readingRoomTime - 1].cancelBook(seatRow, seatColumm, name)) {
					readingRoomAccount.cancelBookCount(date);
					readingRoomDatabase.cancelSeatdata(readingRoomAccount.getClientNum());
					readingRoom[date - 1][readingRoomTime - 1].cancelBookCount(seatRow, seatColumm);
					readingRoomDatabase.cancelSexdata(sex);
					break; // �˸°� ����ϸ� break
				}
					
			}
			break;
		}
		case 3: { // ����
			// ��¥ ����
			cout << "\n���� ��¥�� �������ּ���.";
			date = Console::select_date();
			// �ð� ����
			readingRoomTime = Console::select_ReadingRoomTime();
			// ������ ������ �����ֱ�
			readingRoom[date - 1][readingRoomTime - 1].showReadingRoom();
			break;
		}
		case 4: { // ���
			// � ��踦 ���ϴ��� 
			information = Console::select_sexInformation();
			if (information == 1) { // ���� ���� Ƚ��
				cout << "\n������ ���� Ƚ���� " << readingRoomDatabase.getSeatdata(readingRoomAccount.getClientNum()) << "ȸ �Դϴ�.\n";
			}
			else if (information == 2) { // �¼��� ���� Ƚ��
				// ��¥ ����
				cout << "\n���� ��¥�� �������ּ���.";
				date = Console::select_date();
				// �ð� ����
				readingRoomTime = Console::select_ReadingRoomTime();
				// �¼� ����
				seatRow = Console::select_seatrow();
				seatColumm = Console::select_seatcolumm();
				readingRoom[date - 1][readingRoomTime - 1].showBookCount(seatRow, seatColumm);
			}
			else { //���� ���� Ƚ��
				// ���� ����
				sex = Console::select_sex();
				if (sex == 1) {
					cout << "\n���� ������ ���� Ƚ���� " << readingRoomDatabase.getSexdata(sex) << "ȸ �Դϴ�.\n";
				}
				else {
					cout << "\n���� ������ ���� Ƚ���� " << readingRoomDatabase.getSexdata(sex) << "ȸ �Դϴ�.\n";
				}
			}
			break;
		}
		case 5: { // ������
			flag = 0;
			break;
		}
		default: {
			cout << "�� �� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n";
			break;
		}
		}
		if (!flag) break;
	}
}

void ReadingRoomBook::login() {
	while (1) {
		cout << "\n�� ����Ʈ�� 300���� �ʰ�������Ʈ�� �����Ͻô� ����Ʈ�� ������ ���� ID�Դϴ�.\n";
		loginmenu = Console::loginMenu();
		if (loginmenu == 1) { // �α��� ����
			cout << "�α��� ���ּ���.\n";
			readingRoomAccount.setId(Console::loginID());
			readingRoomAccount.setPassword(Console::loginPass());
			if (readingRoomAccount.isregistered()) { // ture�� ���´ٸ� �α��� �����̶�� ��. false�϶� 1, ��й�ȣ�� Ʋ�� 2, ��ϵ��� ���� ��
				cout << readingRoomAccount.getName() << "�� �ȳ��ϼ���! �޴��� �������ּ���.\n";
				break;
			}
			else {
				cout << "��ϵ��� ���� ���̵��Դϴ�. �ٽ� �α��� ���ּ���.\n";
			}
		}
		else if (loginmenu == 2) { // ȸ������ ����
			cout << "\nȸ�������� �Ҷ� �̸��� �����ַ� ���ֽð� id�� ���� ID�� ���ֽñ� �ٶ��ϴ�.\n";
			readingRoomAccount.makeAccount();
			readingRoomDatabase.save(); // database�� ���� Ƚ�� ���̺�
			cout << "ȸ�������� �Ϸ�Ǿ����ϴ�.\n�α����ϰ� �޴��� �������ּ���.\n";
		}
		else {
			cout << "�� �� �Է��ϼ̽��ϴ�.\n";
		}
	}

}