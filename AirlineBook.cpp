#include <iostream>
using namespace std;

#include "AirlineBook.h"



AirlineBook::AirlineBook() {
	schedule = new Schedule***[7]; // ������ 7��
	for (int i = 0; i < 7; i++) {
		schedule[i] = new Schedule ** [5]; // A~E�� 5�� ���׺���Ͻ�
		for (int j = 0; j < 5; j++) {
			schedule[i][j] = new Schedule*[4]; // i��° ���� ������ 4�� ����
			for (int k = 0; k < 4; k++) {
				schedule[i][j][k] = new Schedule[3]; // 3���� �ð�
				date = (i + 1);
				schedule[i][j][k][0].setscheduleName(date, "�� 07��");
				schedule[i][j][k][1].setscheduleName(date, "�� 12��");
				schedule[i][j][k][2].setscheduleName(date, "�� 17��");
			}
		}
	}
	this->economyTicketPrice = 50000;
	this->businessTicketPrice = 100000;
}

AirlineBook::~AirlineBook() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 4; k++) {
				delete[] schedule[i][j][k]; // 3���� �ð�
			}
		}
	}
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			delete[] schedule[i][j];
		}
	}
	for (int i = 0; i < 7; i++) {
		delete[] schedule[i];
		
	}
	delete[] schedule;
}

void AirlineBook::book() {
	while (1) {
		int flag = 1;
		menu = Console::select_menu();
		switch (menu) {
		case 1: { // ����
			cout << "\n��� ������ �������ּ���.";
			departureAirport = Console::select_airport(); // j�� ����
			while (1) {
				cout << "\n���� ������ �������ּ���.";
				arrivalAirport = Console::select_airport(); // k�� ����
				if (departureAirport != arrivalAirport) break;
				else {
					cout << "\n�������� �ٽ� �Է����ּ���.\n";
				}
			}
			wayType = Console::select_waytype();
			if (wayType == 1) { // ��
				//���� ��¥ 
				cout << "\n��� ���ڸ� �������ּ���.";
				departureDate = Console::select_date(); // i�� ����
				//���� �ð�
				cout << "\n��� �ð��� �������ּ���.";
				departureTime = Console::select_time(); // ������ 0,1,2�� ����

				cout << "\n�¼���ȣ 1~4�� ����Ͻ� �¼�, 5~8�� ���ڳ�� �¼��Դϴ�.";
				cout << "\n���ڳ��: " << economyTicketPrice * wayType << "�� ����Ͻ�: " << businessTicketPrice * wayType << "��\n";
				budget = Console::getBudget();
				cout << "\n��������� ���� ���డ�� �¼��� ---�� ǥ�õ˴ϴ�.\n";
				if (budget >= businessTicketPrice * wayType) {
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
				}
				else if(budget >= economyTicketPrice * wayType) {
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showScheduleEconomy();
				}
				else {
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showScheduleNone();
				}
				// ���� ��������
				while (1) {
					// �¼� ������ �����ֱ�
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
					//���� �¼�
					seatNum = Console::select_seat();
					if (schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].setBook(seatNum, airlineAccount.getName())) {
						airlineAccount.addMileage();
						mileage = airlineAccount.getMileage();
						airlineDatabase.addSeatdata(airlineAccount.getClientNum());
						schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].addBookCount(seatNum);
						//��������(�̸�) ����
						fout.open("airlineBook_nameSet.txt", ios::out | ios::app);
						fout << departureDate << " " << departureAirport << " " << arrivalAirport << " " << departureTime << " " << seatNum << " " << airlineAccount.getName() << endl;
						fout.close();
						//�������� ����Ƚ�� ���� ����
						fout.open("airlineBook_seatDataSet.txt", ios::out | ios::app);
						fout << airlineAccount.getClientNum() << " " << airlineDatabase.getSeatdata(airlineAccount.getClientNum()) << endl;
						fout.close();
						//��������(�¼��� ����Ƚ��) ����
						fout.open("airlineBook_bookCountSet.txt", ios::out | ios::app);
						fout << departureDate << " " << departureAirport << " " << arrivalAirport << " " << departureTime << " " << seatNum << " " << schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].getBookCount(seatNum) << endl;
						fout.close();
						break; // ���ڸ��� �����ϸ� break
					}
				}

			}
			else { //�պ� wayType == 2
				//���� ��¥ 
				cout << "\n��� ���ڸ� �������ּ���.";
				departureDate = Console::select_date(); // i�� ����
				//���� �ð�
				cout << "\n��� �ð��� �������ּ���.";
				departureTime = Console::select_time(); // ������ 0,1,2�� ����

				cout << "\n�¼���ȣ 1~4�� ����Ͻ� �¼�, 5~8�� ���ڳ�� �¼��Դϴ�.";
				cout << "\n���ڳ��: " << economyTicketPrice * wayType << "�� ����Ͻ�: " << businessTicketPrice * wayType << "��\n";
				budget = Console::getBudget();
				cout << "\n��������� ���� ���డ�� �¼��� ---�� ǥ�õ˴ϴ�.\n";
				if (budget >= businessTicketPrice * wayType) {
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showScheduleBusiness();
				}
				else if (budget >= economyTicketPrice * wayType) {
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showScheduleEconomy();
				}
				else {
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showScheduleNone();
				}

				// ���� ��������
				while (1) {
					// �¼� ������ �����ֱ�
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
					//���� �¼�
					seatNum = Console::select_seat();
					if (schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].setBook(seatNum, airlineAccount.getName())) {
						airlineAccount.addMileage();
						mileage = airlineAccount.getMileage();
						airlineDatabase.addSeatdata(airlineAccount.getClientNum());
						schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].addBookCount(seatNum);
						//��������(�̸�) ����
						fout.open("airlineBook_nameSet.txt", ios::out | ios::app);
						fout << departureDate << " " << departureAirport << " " << arrivalAirport << " " << departureTime << " " << seatNum << " " << airlineAccount.getName() << endl;
						fout.close();
						//�������� ����Ƚ�� ���� ����
						fout.open("airlineBook_seatDataSet.txt", ios::out | ios::app);
						fout << airlineAccount.getClientNum() << " " << airlineDatabase.getSeatdata(airlineAccount.getClientNum()) << endl;
						fout.close();
						//��������(�¼��� ����Ƚ��) ����
						fout.open("airlineBook_bookCountSet.txt", ios::out | ios::app);
						fout << departureDate << " " << departureAirport << " " << arrivalAirport << " " << departureTime << " " << seatNum << " " << schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].getBookCount(seatNum) << endl;
						fout.close();
						break; // ���ڸ��� �����ϸ� break
					}
				}
				//�ö� ��¥
				while (1) {
					cout << "\n���ƿ� ���ڸ� �������ּ���.";
					arrivalDate = Console::select_date(); // i�� ����
					if (departureDate >= arrivalDate) { // ����ϰ� ���ƿ��� ���� ������ ���� ����.
						cout << "�ٽ� �Է����ּ���.\n";
					}
					else break;
				}

				//�ö� �ð�
				cout << "\n���ƿ� �ð��� �������ּ���.";
				arrivalTime = Console::select_time(); // ������ 0,1,2�� ����

				/*cout << "\n�¼���ȣ 1~4�� ����Ͻ� �¼�, 5~8�� ���ڳ�� �¼��Դϴ�.";
				cout << "\n���ڳ��: " << economyTicketPrice * wayType << "�� ����Ͻ�: " << businessTicketPrice * wayType << "��\n";
				budget = Console::getBudget();*/
				cout << "\n��������� ���� ���డ�� �¼��� ---�� ǥ�õ˴ϴ�.\n";
				if (budget >= businessTicketPrice * wayType) {
					schedule[arrivalDate - 1][departureAirport - 1][arrivalAirport - 1][arrivalTime - 1].showScheduleBusiness();
				}
				else if (budget >= economyTicketPrice * wayType) {
					schedule[arrivalDate - 1][departureAirport - 1][arrivalAirport - 1][arrivalTime - 1].showScheduleEconomy();
				}
				else {
					schedule[arrivalDate - 1][departureAirport - 1][arrivalAirport - 1][arrivalTime - 1].showScheduleNone();
				}

				// ���� ��������
				while (1) {
					// �¼� ������ �����ֱ�
					schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].showSchedule();
					//���� �¼�
					seatNum = Console::select_seat();
					if (schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].setBook(seatNum, airlineAccount.getName())) {
						airlineAccount.addMileage();
						mileage = airlineAccount.getMileage();
						airlineDatabase.addSeatdata(airlineAccount.getClientNum());
						schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].addBookCount(seatNum);
						//��������(�̸�) ����
						fout.open("airlineBook_nameSet.txt", ios::out | ios::app);
						fout << arrivalDate << " " << arrivalAirport << " " << departureAirport << " " << arrivalTime << " " << seatNum << " " << airlineAccount.getName() << endl;
						fout.close();
						//�������� ����Ƚ�� ���� ����
						fout.open("airlineBook_seatDataSet.txt", ios::out | ios::app);
						fout << airlineAccount.getClientNum() << " " << airlineDatabase.getSeatdata(airlineAccount.getClientNum()) << endl;
						fout.close();
						//��������(�¼��� ����Ƚ��) ����
						fout.open("airlineBook_bookCountSet.txt", ios::out | ios::app);
						fout << arrivalDate << " " << arrivalAirport << " " << departureAirport << " " << arrivalTime << " " << seatNum << " " << schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].getBookCount(seatNum) << endl;
						fout.close();
						break; // ���ڸ��� �����ϸ� break
					}
				}
			}
			break;
		}
		case 2: { // ���
			// ��� ����� �� �Է��ؼ� �������� ����ϴ°Ŷ�
			// �α��ε� ����� �׳� ����ϴ°Ŷ� ����
			cout << "\n��� ������ �������ּ���.";
			departureAirport = Console::select_airport(); // j�� ����
			while (1) {
				cout << "\n���� ������ �������ּ���.";
				arrivalAirport = Console::select_airport(); // k�� ����
				if (departureAirport != arrivalAirport) break;
				else {
					cout << "\n�������� �ٽ� �Է����ּ���.\n";
				}
			}
			wayType = Console::select_waytype();
			if (wayType == 1) { // ��
				//���� ��¥ 
				cout << "\n��� ���ڸ� �������ּ���.";
				departureDate = Console::select_date(); // i�� ����
				//���� �ð�
				cout << "\n��� �ð��� �������ּ���.";
				departureTime = Console::select_time(); // ������ 0,1,2�� ����
				// ���� ��������
				while (1) {
					// �¼� ������ �����ֱ�
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
					//���� �¼�
					seatNum = Console::select_seat();
					if (schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].cancelBook(seatNum, airlineAccount.getName())) {
						airlineAccount.minusMileage();
						mileage = airlineAccount.getMileage();
						airlineDatabase.cancelSeatdata(airlineAccount.getClientNum());
						schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].cancelBookCount(seatNum);
						break; // �˸°� ����ϸ� break
					}
				}

			}
			else { //�պ� wayType == 2
				//���� ��¥ 
				cout << "\n��� ���ڸ� �������ּ���.";
				departureDate = Console::select_date(); // i�� ����
				//���� �ð�
				cout << "\n��� �ð��� �������ּ���.";
				departureTime = Console::select_time(); // ������ 0,1,2�� ����
				// ���� ��������
				while (1) {
					// �¼� ������ �����ֱ�
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
					//���� �¼�
					seatNum = Console::select_seat();
					if (schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].setBook(seatNum, airlineAccount.getName())) {
						airlineAccount.minusMileage();
						mileage = airlineAccount.getMileage();
						airlineDatabase.cancelSeatdata(airlineAccount.getClientNum());
						schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].cancelBookCount(seatNum);
						break; // �˸°� ����ϸ� break
					}
				}
				//�ö� ��¥
				while (1) {
					cout << "\n���ƿ� ���ڸ� �������ּ���.";
					arrivalDate = Console::select_date(); // i�� ����
					if (departureDate >= arrivalDate) { // ����ϰ� ���ƿ��� ���� ������ ���� ����.
						cout << "�ٽ� �Է����ּ���.\n";
					}
					else break;
				}

				//�ö� �ð�
				cout << "\n���ƿ� �ð��� �������ּ���.";
				arrivalTime = Console::select_time(); // ������ 0,1,2�� ����
				// ���� ��������
				while (1) {
					// �¼� ������ �����ֱ�
					schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].showSchedule();
					//���� �¼�
					seatNum = Console::select_seat();
					if (schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].cancelBook(seatNum, airlineAccount.getName())) {
						airlineAccount.minusMileage();
						mileage = airlineAccount.getMileage();
						airlineDatabase.cancelSeatdata(airlineAccount.getClientNum());
						schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].cancelBookCount(seatNum);
						break; // �˸°� ����ϸ� break
					}
				}
			}
			break;
		}
		case 3: { // ����
			cout << "\n��� ������ �������ּ���.";
			departureAirport = Console::select_airport(); // j�� ����
			while (1) {
				cout << "\n���� ������ �������ּ���.";
				arrivalAirport = Console::select_airport(); // k�� ����
				if (departureAirport != arrivalAirport) break;
				else {
					cout << "\n�������� �ٽ� �Է����ּ���.\n";
				}
			}
			wayType = Console::select_waytype();
			if (wayType == 1) { // ��
				//���� ��¥ 
				cout << "\n��� ���ڸ� �������ּ���.";
				departureDate = Console::select_date(); // i�� ����
				//���� �ð�
				cout << "\n��� �ð��� �������ּ���.";
				departureTime = Console::select_time(); // ������ 0,1,2�� ����
				// ���� ��������
				// �¼� ������ �����ֱ�
				schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
				

			}
			else { //�պ� wayType == 2
				//���� ��¥ 
				cout << "\n��� ���ڸ� �������ּ���.";
				departureDate = Console::select_date(); // i�� ����
				//���� �ð�
				cout << "\n��� �ð��� �������ּ���.";
				departureTime = Console::select_time(); // ������ 0,1,2�� ����
				// ���� ��������
				// �¼� ������ �����ֱ�
				schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
				
				//�ö� ��¥
				while (1) {
					cout << "\n���ƿ� ���ڸ� �������ּ���.";
					arrivalDate = Console::select_date(); // i�� ����
					if (departureDate >= arrivalDate) { // ����ϰ� ���ƿ��� ���� ������ ���� ����.
						cout << "�ٽ� �Է����ּ���.\n";
					}
					else break;
				}

				//�ö� �ð�
				cout << "\n���ƿ� �ð��� �������ּ���.";
				arrivalTime = Console::select_time(); // ������ 0,1,2�� ����
				// ���� ��������
				// �¼� ������ �����ֱ�
				schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].showSchedule();
				
			}
			break;
		}
		case 4: { // ���
			// � ��踦 ���ϴ��� 
			information = Console::select_seatInformation();
			if (information == 1) { // ���� ���� Ƚ��
				cout << "\n������ ���� Ƚ���� " << airlineDatabase.getSeatdata(airlineAccount.getClientNum()) << "ȸ �Դϴ�.\n";
			}
			else { // �¼��� ���� Ƚ��
				cout << "\n��� ������ �������ּ���.";
				departureAirport = Console::select_airport(); // j�� ����
				while (1) {
					cout << "\n���� ������ �������ּ���.";
					arrivalAirport = Console::select_airport(); // k�� ����
					if (departureAirport != arrivalAirport) break;
					else {
						cout << "\n�������� �ٽ� �Է����ּ���.\n";
					}
				}
				//���� ��¥ 
				cout << "\n��� ���ڸ� �������ּ���.";
				departureDate = Console::select_date(); // i�� ����
				//���� �ð�
				cout << "\n��� �ð��� �������ּ���.";
				departureTime = Console::select_time(); // ������ 0,1,2�� ����
				//���� �¼�
				seatNum = Console::select_seat();
				schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showBookCount(seatNum);

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

void AirlineBook::login() {
	if (airlineAccount.getClientNum() == -1) {
		//���ε�
		//idset�� ����� id ���� ������ ��������
		fin.open("airlineAccount_idSet.txt", ios::in | ios::out | ios::app);
		while (!fin.eof()) {
			getline(fin, id);
			airlineAccount.pushId(id);
			airlineDatabase.save();
		}
		fin.close();
		
		//passwordset�� ����� password ���� ������ ��������
		fin.open("airlineAccount_passwordSet.txt", ios::in | ios::out | ios::app);
		while (!fin.eof()) {
			getline(fin, password);
			airlineAccount.pushPassword(password);
		}
		fin.close();
		
		//nameset�� ����� name ���� ������ ��������
		fin.open("airlineAccount_nameSet.txt", ios::in | ios::out | ios::app);
		while (!fin.eof()) {
			getline(fin, name);
			airlineAccount.pushName(name);
		}
		fin.close();
		
		//���� �ҷ�����
		fin.open("airlineBook_nameSet.txt", ios::in | ios::out | ios::app);
		while (!fin.eof()) {
			getline(fin, bookInformation);
			istringstream ss(bookInformation);
			string strBuf;
			stringSet.clear();
			while (getline(ss, strBuf, ' ')) {
				stringSet.push_back(strBuf);
			}
			if (bookInformation != "") {
				schedule[stoi(stringSet[0]) - 1][stoi(stringSet[1]) - 1][stoi(stringSet[2]) - 1][stoi(stringSet[3]) - 1].setBookReload(stoi(stringSet[4]), stringSet[5]);
			}
			
		}
		fin.close();

		//���� �ҷ�����
		fin.open("airlineBook_bookCountSet.txt", ios::in | ios::out | ios::app);
		while (!fin.eof()) {
			getline(fin, bookInformation);
			istringstream ss(bookInformation);
			string strBuf;
			stringSet.clear();
			while (getline(ss, strBuf, ' ')) {
				stringSet.push_back(strBuf);
			}
			if (bookInformation != "") {
				schedule[stoi(stringSet[0]) - 1][stoi(stringSet[1]) - 1][stoi(stringSet[2]) - 1][stoi(stringSet[3]) - 1].setBookCount(stoi(stringSet[4]), stoi(stringSet[5]));
			}
			
		}
		fin.close();
		//�������� ����Ƚ�� ���� �ҷ�����
		fin.open("airlineBook_seatDataSet.txt", ios::in | ios::out | ios::app);
		while (!fin.eof()) {
			getline(fin, seatData);
			istringstream ss(seatData);
			string strBuf;
			stringSet.clear();
			while (getline(ss, strBuf, ' ')) {
				stringSet.push_back(strBuf);
			}
			if (seatData != "") {
				airlineDatabase.setSeatdata(stoi(stringSet[1]), stoi(stringSet[0]));
			}
		}
		fin.close();

	}
	while (1) {
		loginmenu = Console::loginMenu();
		if (loginmenu == 1) { // �α��� ����
			cout << "�α��� ���ּ���.\n";
			airlineAccount.setId(Console::loginID());
			airlineAccount.setPassword(Console::loginPass());
			if (airlineAccount.isregistered()) { // ture�� ���´ٸ� �α��� �����̶�� ��. false�϶� 1, ��й�ȣ�� Ʋ�� 2, ��ϵ��� ���� ��
				cout << airlineAccount.getName() << "�� �ȳ��ϼ���! �޴��� �������ּ���.\n";
				break;
			}
			else {
				cout << "��ϵ��� ���� ���̵��Դϴ�. �ٽ� �α��� ���ּ���.\n";
			}
		}
		else if (loginmenu == 2) { // ȸ������ ����
			airlineAccount.makeAccount();
			//id ���Ͽ�����
			fout.open("airlineAccount_idSet.txt", ios::out | ios::app);
			fout << airlineAccount.getId() << endl;
			fout.close();
			//password ���Ͽ� ����
			fout.open("airlineAccount_passwordSet.txt", ios::out | ios::app);
			fout << airlineAccount.getPassword() << endl;
			fout.close();
			//name ���Ͽ� ����
			fout.open("airlineAccount_nameSet.txt", ios::out | ios::app);
			fout << airlineAccount.getName() << endl;
			fout.close();

			airlineDatabase.save(); // database�� ���� Ƚ�� ���̺�
			cout << "ȸ�������� �Ϸ�Ǿ����ϴ�.\n�α����ϰ� �޴��� �������ּ���.\n";
		}
		else {
			cout << "�� �� �Է��ϼ̽��ϴ�.\n";
		}
	}
	

}
