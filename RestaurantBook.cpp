#include <iostream>
using namespace std;

#include "RestaurantBook.h"

RestaurantBook::RestaurantBook() {
	sale = new Sale * [7];
	for (int i = 0; i < 7; i++) {
		sale[i] = new Sale[2];
		date = i + 1;
		sale[i][0].setSaleName(date, "�� ����");
		sale[i][1].setSaleName(date, "�� ����");
	}
	walkinTable = new Table[2];
}

RestaurantBook::~RestaurantBook() {
	//sale�� delete�ؾ���
	delete[] walkinTable;
}


void RestaurantBook::book() {
	while (1) {
		int flag = 1;
		if (walkinTable[0].showName() == restaurantAccount.getName() || walkinTable[1].showName() == restaurantAccount.getName()) { // ���� ��ũ�� ���̺� �̿��ڿ��Ը� �ߴ� �޼���
			finishMeal = Console::finishMeal();
			if (finishMeal == 1) { // �Ļ� ��ġ�⸦ ����
				cout << "\n�� ������!\n\n";
				if (!waitingQueue.empty()) {
					cout << waitingQueue.front() << "�� ��������! �Ļ� ���ְ� �ϼ���!\n";
					if (walkinTable[0].showName() == restaurantAccount.getName()) { // 1�� ���̺� �����
						walkinTable[0].resetName();
						walkinTable[0].setName(waitingQueue.front());
						waitingQueue.pop();
					}
					else { // 2�� ���̺� �����
						walkinTable[1].resetName();
						walkinTable[1].setName(waitingQueue.front());
						waitingQueue.pop();
					}
					break;
				}
				
			}
		}
		menu = Console::select_menu(); //����:1, ���:2, ����:3, ���:4, ������:5
		switch (menu)
		{
		case 1: { // ����
			// ��ũ�� �����
			isWalkIn = Console::isWalkIn();
			if (isWalkIn == 1) { // ��ũ�� �մ�
				// �ο� �����
				memberNum = Console::memberNum();
				if (memberNum > 6) {
					cout << "\n�� �Ĵ��� 6�� ���̺�� �����Ǿ��ֽ��ϴ�.\n";
					cout << "6�� �̻��� ������ �Ұ��մϴ�.\n";
					break;
				}
				else { // 6�� ���� �ο�
					// 8�� �̻� �����
					isOver7 = Console::isOver7();
					if (isOver7 == 2) {
						cout << "\n�� �Ĵ��� 7�� ���� �Ƶ��� ������ �Ұ��մϴ�.\n";
						break;
					}
					else { // ��� 8�� �̻�
						if (walkinTable[0].showName() == "---" || walkinTable[1].showName() == "---") { // �� ��ũ�����̺��� �ִٸ�
							cout << "\n�Ļ� ���ְ� �ϼ���!\n";
							if (walkinTable[0].showName() == "---") {
								walkinTable[0].setName(restaurantAccount.getName());
							}
							else {
								walkinTable[1].setName(restaurantAccount.getName());
							}
							flag = 0;
						}
						else { // �� ��ũ�����̺��� ���ٸ�
							cout << "\n��� " << (int)waitingQueue.size() + 1 << "�� �Դϴ�.\n���ݸ� ��ٷ� �ּ���.\n";
							waitingQueue.push(restaurantAccount.getName());
						}
					
					}
				}
			}
			else { // �Ϲ� ���� �մ�
				// �ο� �����
				memberNum = Console::memberNum();
				if (memberNum > 6) {
					cout << "\n�� �Ĵ��� 6�� ���̺�� �����Ǿ��ֽ��ϴ�.\n";
					cout << "6�� �̻��� ������ �Ұ��մϴ�.\n";
					break;
				}
				else { // 6�� ���� �ο�
					// 8�� �̻� �����
					isOver7 = Console::isOver7();
					if (isOver7 == 2) {
						cout << "\n�� �Ĵ��� 7�� ���� �Ƶ��� ������ �Ұ��մϴ�.\n";
						break;
					}
					else { // ��� 8�� �̻�
						// ��¥ ����
						cout << "\n���� ��¥�� �������ּ���.";
						date = Console::select_date();
						// ���� ������ ����
						whenEat = Console::select_whenEat();
						//���� ��������
						while (1) {
							// ���̺� ������ �����ֱ�
							sale[date - 1][whenEat - 1].showSale();
							//���̺� ����
							tableNum = Console::select_table();
							if (sale[date - 1][whenEat - 1].setBook(tableNum, restaurantAccount.getName())) {
								restaurantDatabase.addTabledata(restaurantAccount.getClientNum());
								sale[date - 1][whenEat - 1].addBookCount(tableNum);
								break;
							}
						}
					}
				}
			}
			

			break;
		}
		case 2: { // ���
			// ��ũ�� �����
			isWalkIn = Console::isWalkIn();
			if (isWalkIn == 1) { // ��ũ�� �մ�
				
				cout << "\n��ũ�� ��� ��Ҵ� �������� ���� �ϼ���\n";
			}
			else { // �Ϲ� ���� �մ�
				cout << "\n���� ��¥�� �������ּ���.";
				// ��¥ ����
				date = Console::select_date();
				// ���� ������ ����
				whenEat = Console::select_whenEat();
				//���� ��������
				while (1) {
					// ���̺� ������ �����ֱ�
					sale[date - 1][whenEat - 1].showSale();
					//���̺� ����
					tableNum = Console::select_table();
					if (sale[date - 1][whenEat - 1].cancelBook(tableNum, restaurantAccount.getName())) {
						restaurantDatabase.cancelTabledata(restaurantAccount.getClientNum());
						sale[date - 1][whenEat - 1].cancelBookCount(tableNum);
						break; // �˸°� ����ϸ� break
					}
				}
			}
			break;
		}
		case 3: { // ����
			// ��ũ�� �����
			isWalkIn = Console::isWalkIn();
			if (isWalkIn == 1) { // ��ũ�� �մ�

				cout << "\n��ũ�� ��� ����� �������� ���� �ϼ���\n";
			}
			else { // �Ϲ� ���� �մ�
				cout << "\n���� ��¥�� �������ּ���.";
				// ��¥ ����
				date = Console::select_date();
				// ���� ������ ����
				whenEat = Console::select_whenEat();
				//���� ��������
				// ���̺� ������ �����ֱ�
				sale[date - 1][whenEat - 1].showSale();
			}
			break;
		}
		case 4: { // ���
			// � ��踦 ���ϴ��� 
			information = Console::select_tableInformation();
			if (information == 1) { // ���� ���� Ƚ��
				cout << "\n������ ���� Ƚ���� " << restaurantDatabase.getTabledata(restaurantAccount.getClientNum()) << "ȸ �Դϴ�.\n";
			}
			else { // �¼��� ���� Ƚ��
				// ��¥ ����
				cout << "\n���� ��¥�� �������ּ���.";
				date = Console::select_date();
				// ���� ������ ����
				whenEat = Console::select_whenEat();
				//���̺� ����
				tableNum = Console::select_table();
				sale[date - 1][whenEat - 1].showBookCount(tableNum);
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

void RestaurantBook::login() {
	while (1) {
		loginmenu = Console::loginMenu();
		if (loginmenu == 1) { // �α��� ����
			cout << "�α��� ���ּ���.\n";
			restaurantAccount.setId(Console::loginID());
			restaurantAccount.setPassword(Console::loginPass());
			if (restaurantAccount.isregistered()) { // ture�� ���´ٸ� �α��� �����̶�� ��. false�϶� 1, ��й�ȣ�� Ʋ�� 2, ��ϵ��� ���� ��
				cout << restaurantAccount.getName() << "�� �ȳ��ϼ���! �޴��� �������ּ���.\n";
				break;
			}
			else {
				cout << "��ϵ��� ���� ���̵��Դϴ�. �ٽ� �α��� ���ּ���.\n";
			}
		}
		else if (loginmenu == 2) { // ȸ������ ����
			restaurantAccount.makeAccount();
			restaurantDatabase.save(); // database�� ���� Ƚ�� ���̺�
			cout << "ȸ�������� �Ϸ�Ǿ����ϴ�.\n�α����ϰ� �޴��� �������ּ���.\n";
		}
		else {
			cout << "�� �� �Է��ϼ̽��ϴ�.\n";
		}
	}

}