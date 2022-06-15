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
	for (int i = 0; i < 7; i++) {
		delete[] readingRoom[i];
	}
	delete[] readingRoom;
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

							//�������� ����
							fout.open("readingRoomBook_reloadSet.txt", ios::out | ios::app);
							fout << date << " " << readingRoomTime << " " << seatRow << " " << seatColumm << " " << name << " " << readingRoomAccount.getBookCount(date) << " " << readingRoom[date - 1][readingRoomTime - 1].getBookCount(seatRow, seatColumm) << " " << readingRoomAccount.getClientNum() << endl;
							fout.close();

							//�������� ����Ƚ��, ���� ����Ƚ�� ���� ����
							fout.open("readingRoomBook_DataSet.txt", ios::out | ios::app);
							fout << readingRoomAccount.getClientNum() << " " << readingRoomDatabase.getSeatdata(readingRoomAccount.getClientNum()) << " " << readingRoomDatabase.getSexdata(1) << " " << readingRoomDatabase.getSexdata(2) << endl;
							fout.close();
							

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
	if (readingRoomAccount.getClientNum() == -1) {
		//���ε�
		//idset�� ����� id ���� ������ ��������
		fin.open("readingRoomAccount_idSet.txt", ios::in | ios::out | ios::app);
		while (!fin.eof()) {
			getline(fin, id);
			readingRoomAccount.pushId(id);
			readingRoomDatabase.save();
		}
		fin.close();

		//passwordset�� ����� password ���� ������ ��������
		fin.open("readingRoomAccount_passwordSet.txt", ios::in | ios::out | ios::app);
		while (!fin.eof()) {
			getline(fin, password);
			readingRoomAccount.pushPassword(password);
		}
		fin.close();

		//nameset�� ����� name ���� ������ ��������
		fin.open("readingRoomAccount_nameSet.txt", ios::in | ios::out | ios::app);
		while (!fin.eof()) {
			getline(fin, name);
			readingRoomAccount.pushName(name);
		}
		fin.close();

		//���� �ҷ�����
		fin.open("readingRoomBook_reloadSet.txt", ios::in | ios::out | ios::app);
		while (!fin.eof()) {
			getline(fin, bookInformation);
			istringstream ss(bookInformation);
			string strBuf;
			stringSet.clear();
			while (getline(ss, strBuf, ' ')) {
				stringSet.push_back(strBuf);
			}
			if (bookInformation != "") {
				readingRoom[stoi(stringSet[0]) - 1][stoi(stringSet[1]) - 1].setBookReload(stoi(stringSet[2]), stoi(stringSet[3]), stringSet[4]);
				readingRoomAccount.setBookCount(stoi(stringSet[0]), stoi(stringSet[5]), stoi(stringSet[7]));
				readingRoom[stoi(stringSet[0]) - 1][stoi(stringSet[1]) - 1].setBookCount(stoi(stringSet[2]), stoi(stringSet[3]), stoi(stringSet[6]));
			}

		}
		fin.close();
		//�������� ����Ƚ�� ���� �ҷ�����
		fin.open("readingRoomBook_DataSet.txt", ios::in | ios::out | ios::app);
		while (!fin.eof()) {
			getline(fin, bookInformation);
			istringstream ss(bookInformation);
			string strBuf;
			stringSet.clear();
			while (getline(ss, strBuf, ' ')) {
				stringSet.push_back(strBuf);
			}
			if (bookInformation != "") {
				readingRoomDatabase.setSeatdata(stoi(stringSet[1]), stoi(stringSet[0]));
				readingRoomDatabase.setSexdata(stoi(stringSet[2]), stoi(stringSet[3]));
			}
		}
		fin.close();

	}
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
			//id ���Ͽ�����
			fout.open("readingRoomAccount_idSet.txt", ios::out | ios::app);
			fout << readingRoomAccount.getId() << endl;
			fout.close();
			//password ���Ͽ� ����
			fout.open("readingRoomAccount_passwordSet.txt", ios::out | ios::app);
			fout << readingRoomAccount.getPassword() << endl;
			fout.close();
			//name ���Ͽ� ����
			fout.open("readingRoomAccount_nameSet.txt", ios::out | ios::app);
			fout << readingRoomAccount.getName() << endl;
			fout.close();

			readingRoomDatabase.save(); // database�� ���� Ƚ�� ���̺�
			cout << "ȸ�������� �Ϸ�Ǿ����ϴ�.\n�α����ϰ� �޴��� �������ּ���.\n";
		}
		else {
			cout << "�� �� �Է��ϼ̽��ϴ�.\n";
		}
	}

}