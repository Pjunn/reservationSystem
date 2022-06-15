#include <iostream>
using namespace std;

#include "AirlineBook.h"



AirlineBook::AirlineBook() {
	schedule = new Schedule***[7]; // 임의의 7일
	for (int i = 0; i < 7; i++) {
		schedule[i] = new Schedule ** [5]; // A~E의 5개 공항비즈니스
		for (int j = 0; j < 5; j++) {
			schedule[i][j] = new Schedule*[4]; // i번째 공항 제외한 4개 공항
			for (int k = 0; k < 4; k++) {
				schedule[i][j][k] = new Schedule[3]; // 3개의 시간
				date = (i + 1);
				schedule[i][j][k][0].setscheduleName(date, "일 07시");
				schedule[i][j][k][1].setscheduleName(date, "일 12시");
				schedule[i][j][k][2].setscheduleName(date, "일 17시");
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
				delete[] schedule[i][j][k]; // 3개의 시간
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
		case 1: { // 예약
			cout << "\n출발 공항을 선택해주세요.";
			departureAirport = Console::select_airport(); // j에 대응
			while (1) {
				cout << "\n도착 공항을 선택해주세요.";
				arrivalAirport = Console::select_airport(); // k에 대응
				if (departureAirport != arrivalAirport) break;
				else {
					cout << "\n도착지를 다시 입력해주세요.\n";
				}
			}
			wayType = Console::select_waytype();
			if (wayType == 1) { // 편도
				//갈때 날짜 
				cout << "\n출발 일자를 선택해주세요.";
				departureDate = Console::select_date(); // i에 대응
				//갈때 시간
				cout << "\n출발 시간를 선택해주세요.";
				departureTime = Console::select_time(); // 마지막 0,1,2에 대응

				cout << "\n좌석번호 1~4는 비즈니스 좌석, 5~8은 이코노미 좌석입니다.";
				cout << "\n이코노미: " << economyTicketPrice * wayType << "원 비즈니스: " << businessTicketPrice * wayType << "원\n";
				budget = Console::getBudget();
				cout << "\n예산범위에 따른 예약가능 좌석은 ---로 표시됩니다.\n";
				if (budget >= businessTicketPrice * wayType) {
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
				}
				else if(budget >= economyTicketPrice * wayType) {
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showScheduleEconomy();
				}
				else {
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showScheduleNone();
				}
				// 이제 예약하자
				while (1) {
					// 좌석 현상태 보여주기
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
					//갈때 좌석
					seatNum = Console::select_seat();
					if (schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].setBook(seatNum, airlineAccount.getName())) {
						airlineAccount.addMileage();
						mileage = airlineAccount.getMileage();
						airlineDatabase.addSeatdata(airlineAccount.getClientNum());
						schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].addBookCount(seatNum);
						//예약정보(이름) 저장
						fout.open("airlineBook_nameSet.txt", ios::out | ios::app);
						fout << departureDate << " " << departureAirport << " " << arrivalAirport << " " << departureTime << " " << seatNum << " " << airlineAccount.getName() << endl;
						fout.close();
						//예약자의 예약횟수 정보 저장
						fout.open("airlineBook_seatDataSet.txt", ios::out | ios::app);
						fout << airlineAccount.getClientNum() << " " << airlineDatabase.getSeatdata(airlineAccount.getClientNum()) << endl;
						fout.close();
						//예약정보(좌석의 예약횟수) 저장
						fout.open("airlineBook_bookCountSet.txt", ios::out | ios::app);
						fout << departureDate << " " << departureAirport << " " << arrivalAirport << " " << departureTime << " " << seatNum << " " << schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].getBookCount(seatNum) << endl;
						fout.close();
						break; // 빈자리에 예약하면 break
					}
				}

			}
			else { //왕복 wayType == 2
				//갈때 날짜 
				cout << "\n출발 일자를 선택해주세요.";
				departureDate = Console::select_date(); // i에 대응
				//갈때 시간
				cout << "\n출발 시간를 선택해주세요.";
				departureTime = Console::select_time(); // 마지막 0,1,2에 대응

				cout << "\n좌석번호 1~4는 비즈니스 좌석, 5~8은 이코노미 좌석입니다.";
				cout << "\n이코노미: " << economyTicketPrice * wayType << "원 비즈니스: " << businessTicketPrice * wayType << "원\n";
				budget = Console::getBudget();
				cout << "\n예산범위에 따른 예약가능 좌석은 ---로 표시됩니다.\n";
				if (budget >= businessTicketPrice * wayType) {
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showScheduleBusiness();
				}
				else if (budget >= economyTicketPrice * wayType) {
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showScheduleEconomy();
				}
				else {
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showScheduleNone();
				}

				// 이제 예약하자
				while (1) {
					// 좌석 현상태 보여주기
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
					//갈때 좌석
					seatNum = Console::select_seat();
					if (schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].setBook(seatNum, airlineAccount.getName())) {
						airlineAccount.addMileage();
						mileage = airlineAccount.getMileage();
						airlineDatabase.addSeatdata(airlineAccount.getClientNum());
						schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].addBookCount(seatNum);
						//예약정보(이름) 저장
						fout.open("airlineBook_nameSet.txt", ios::out | ios::app);
						fout << departureDate << " " << departureAirport << " " << arrivalAirport << " " << departureTime << " " << seatNum << " " << airlineAccount.getName() << endl;
						fout.close();
						//예약자의 예약횟수 정보 저장
						fout.open("airlineBook_seatDataSet.txt", ios::out | ios::app);
						fout << airlineAccount.getClientNum() << " " << airlineDatabase.getSeatdata(airlineAccount.getClientNum()) << endl;
						fout.close();
						//예약정보(좌석의 예약횟수) 저장
						fout.open("airlineBook_bookCountSet.txt", ios::out | ios::app);
						fout << departureDate << " " << departureAirport << " " << arrivalAirport << " " << departureTime << " " << seatNum << " " << schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].getBookCount(seatNum) << endl;
						fout.close();
						break; // 빈자리에 예약하면 break
					}
				}
				//올때 날짜
				while (1) {
					cout << "\n돌아올 일자를 선택해주세요.";
					arrivalDate = Console::select_date(); // i에 대응
					if (departureDate >= arrivalDate) { // 출발일과 돌아오는 날이 같을수 없다 가정.
						cout << "다시 입력해주세요.\n";
					}
					else break;
				}

				//올때 시간
				cout << "\n돌아올 시간을 선택해주세요.";
				arrivalTime = Console::select_time(); // 마지막 0,1,2에 대응

				/*cout << "\n좌석번호 1~4는 비즈니스 좌석, 5~8은 이코노미 좌석입니다.";
				cout << "\n이코노미: " << economyTicketPrice * wayType << "원 비즈니스: " << businessTicketPrice * wayType << "원\n";
				budget = Console::getBudget();*/
				cout << "\n예산범위에 따른 예약가능 좌석은 ---로 표시됩니다.\n";
				if (budget >= businessTicketPrice * wayType) {
					schedule[arrivalDate - 1][departureAirport - 1][arrivalAirport - 1][arrivalTime - 1].showScheduleBusiness();
				}
				else if (budget >= economyTicketPrice * wayType) {
					schedule[arrivalDate - 1][departureAirport - 1][arrivalAirport - 1][arrivalTime - 1].showScheduleEconomy();
				}
				else {
					schedule[arrivalDate - 1][departureAirport - 1][arrivalAirport - 1][arrivalTime - 1].showScheduleNone();
				}

				// 이제 예약하자
				while (1) {
					// 좌석 현상태 보여주기
					schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].showSchedule();
					//갈때 좌석
					seatNum = Console::select_seat();
					if (schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].setBook(seatNum, airlineAccount.getName())) {
						airlineAccount.addMileage();
						mileage = airlineAccount.getMileage();
						airlineDatabase.addSeatdata(airlineAccount.getClientNum());
						schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].addBookCount(seatNum);
						//예약정보(이름) 저장
						fout.open("airlineBook_nameSet.txt", ios::out | ios::app);
						fout << arrivalDate << " " << arrivalAirport << " " << departureAirport << " " << arrivalTime << " " << seatNum << " " << airlineAccount.getName() << endl;
						fout.close();
						//예약자의 예약횟수 정보 저장
						fout.open("airlineBook_seatDataSet.txt", ios::out | ios::app);
						fout << airlineAccount.getClientNum() << " " << airlineDatabase.getSeatdata(airlineAccount.getClientNum()) << endl;
						fout.close();
						//예약정보(좌석의 예약횟수) 저장
						fout.open("airlineBook_bookCountSet.txt", ios::out | ios::app);
						fout << arrivalDate << " " << arrivalAirport << " " << departureAirport << " " << arrivalTime << " " << seatNum << " " << schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].getBookCount(seatNum) << endl;
						fout.close();
						break; // 빈자리에 예약하면 break
					}
				}
			}
			break;
		}
		case 2: { // 취소
			// 취소 방법이 다 입력해서 마지막에 취소하는거랑
			// 로그인된 사람꺼 그냥 취소하는거랑 나뉨
			cout << "\n출발 공항을 선택해주세요.";
			departureAirport = Console::select_airport(); // j에 대응
			while (1) {
				cout << "\n도착 공항을 선택해주세요.";
				arrivalAirport = Console::select_airport(); // k에 대응
				if (departureAirport != arrivalAirport) break;
				else {
					cout << "\n도착지를 다시 입력해주세요.\n";
				}
			}
			wayType = Console::select_waytype();
			if (wayType == 1) { // 편도
				//갈때 날짜 
				cout << "\n출발 일자를 선택해주세요.";
				departureDate = Console::select_date(); // i에 대응
				//갈때 시간
				cout << "\n출발 시간를 선택해주세요.";
				departureTime = Console::select_time(); // 마지막 0,1,2에 대응
				// 이제 예약하자
				while (1) {
					// 좌석 현상태 보여주기
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
					//갈때 좌석
					seatNum = Console::select_seat();
					if (schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].cancelBook(seatNum, airlineAccount.getName())) {
						airlineAccount.minusMileage();
						mileage = airlineAccount.getMileage();
						airlineDatabase.cancelSeatdata(airlineAccount.getClientNum());
						schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].cancelBookCount(seatNum);
						break; // 알맞게 취소하면 break
					}
				}

			}
			else { //왕복 wayType == 2
				//갈때 날짜 
				cout << "\n출발 일자를 선택해주세요.";
				departureDate = Console::select_date(); // i에 대응
				//갈때 시간
				cout << "\n출발 시간를 선택해주세요.";
				departureTime = Console::select_time(); // 마지막 0,1,2에 대응
				// 이제 예약하자
				while (1) {
					// 좌석 현상태 보여주기
					schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
					//갈때 좌석
					seatNum = Console::select_seat();
					if (schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].setBook(seatNum, airlineAccount.getName())) {
						airlineAccount.minusMileage();
						mileage = airlineAccount.getMileage();
						airlineDatabase.cancelSeatdata(airlineAccount.getClientNum());
						schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].cancelBookCount(seatNum);
						break; // 알맞게 취소하면 break
					}
				}
				//올때 날짜
				while (1) {
					cout << "\n돌아올 일자를 선택해주세요.";
					arrivalDate = Console::select_date(); // i에 대응
					if (departureDate >= arrivalDate) { // 출발일과 돌아오는 날이 같을수 없다 가정.
						cout << "다시 입력해주세요.\n";
					}
					else break;
				}

				//올때 시간
				cout << "\n돌아올 시간을 선택해주세요.";
				arrivalTime = Console::select_time(); // 마지막 0,1,2에 대응
				// 이제 예약하자
				while (1) {
					// 좌석 현상태 보여주기
					schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].showSchedule();
					//갈때 좌석
					seatNum = Console::select_seat();
					if (schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].cancelBook(seatNum, airlineAccount.getName())) {
						airlineAccount.minusMileage();
						mileage = airlineAccount.getMileage();
						airlineDatabase.cancelSeatdata(airlineAccount.getClientNum());
						schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].cancelBookCount(seatNum);
						break; // 알맞게 취소하면 break
					}
				}
			}
			break;
		}
		case 3: { // 보기
			cout << "\n출발 공항을 선택해주세요.";
			departureAirport = Console::select_airport(); // j에 대응
			while (1) {
				cout << "\n도착 공항을 선택해주세요.";
				arrivalAirport = Console::select_airport(); // k에 대응
				if (departureAirport != arrivalAirport) break;
				else {
					cout << "\n도착지를 다시 입력해주세요.\n";
				}
			}
			wayType = Console::select_waytype();
			if (wayType == 1) { // 편도
				//갈때 날짜 
				cout << "\n출발 일자를 선택해주세요.";
				departureDate = Console::select_date(); // i에 대응
				//갈때 시간
				cout << "\n출발 시간를 선택해주세요.";
				departureTime = Console::select_time(); // 마지막 0,1,2에 대응
				// 이제 예약하자
				// 좌석 현상태 보여주기
				schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
				

			}
			else { //왕복 wayType == 2
				//갈때 날짜 
				cout << "\n출발 일자를 선택해주세요.";
				departureDate = Console::select_date(); // i에 대응
				//갈때 시간
				cout << "\n출발 시간를 선택해주세요.";
				departureTime = Console::select_time(); // 마지막 0,1,2에 대응
				// 이제 예약하자
				// 좌석 현상태 보여주기
				schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showSchedule();
				
				//올때 날짜
				while (1) {
					cout << "\n돌아올 일자를 선택해주세요.";
					arrivalDate = Console::select_date(); // i에 대응
					if (departureDate >= arrivalDate) { // 출발일과 돌아오는 날이 같을수 없다 가정.
						cout << "다시 입력해주세요.\n";
					}
					else break;
				}

				//올때 시간
				cout << "\n돌아올 시간을 선택해주세요.";
				arrivalTime = Console::select_time(); // 마지막 0,1,2에 대응
				// 이제 예약하자
				// 좌석 현상태 보여주기
				schedule[arrivalDate - 1][arrivalAirport - 1][departureAirport - 1][arrivalTime - 1].showSchedule();
				
			}
			break;
		}
		case 4: { // 통계
			// 어떤 통계를 원하는지 
			information = Console::select_seatInformation();
			if (information == 1) { // 고객의 예약 횟수
				cout << "\n고객님의 예약 횟수는 " << airlineDatabase.getSeatdata(airlineAccount.getClientNum()) << "회 입니다.\n";
			}
			else { // 좌석별 예약 횟수
				cout << "\n출발 공항을 선택해주세요.";
				departureAirport = Console::select_airport(); // j에 대응
				while (1) {
					cout << "\n도착 공항을 선택해주세요.";
					arrivalAirport = Console::select_airport(); // k에 대응
					if (departureAirport != arrivalAirport) break;
					else {
						cout << "\n도착지를 다시 입력해주세요.\n";
					}
				}
				//갈때 날짜 
				cout << "\n출발 일자를 선택해주세요.";
				departureDate = Console::select_date(); // i에 대응
				//갈때 시간
				cout << "\n출발 시간를 선택해주세요.";
				departureTime = Console::select_time(); // 마지막 0,1,2에 대응
				//갈때 좌석
				seatNum = Console::select_seat();
				schedule[departureDate - 1][departureAirport - 1][arrivalAirport - 1][departureTime - 1].showBookCount(seatNum);

			}
			break;
		}
		case 5: { // 끝내기
			flag = 0;
			break;
		}
		default: {
			cout << "잘 못 입력하셨습니다. 다시 입력해주세요.\n";
			break;
		}
		}
		if (!flag) break;
	}
	
	
}

void AirlineBook::login() {
	if (airlineAccount.getClientNum() == -1) {
		//리로드
		//idset에 저장된 id 벡터 셋으로 가져오기
		fin.open("airlineAccount_idSet.txt", ios::in | ios::out | ios::app);
		while (!fin.eof()) {
			getline(fin, id);
			airlineAccount.pushId(id);
			airlineDatabase.save();
		}
		fin.close();
		
		//passwordset에 저장된 password 벡터 셋으로 가져오기
		fin.open("airlineAccount_passwordSet.txt", ios::in | ios::out | ios::app);
		while (!fin.eof()) {
			getline(fin, password);
			airlineAccount.pushPassword(password);
		}
		fin.close();
		
		//nameset에 저장된 name 벡터 셋으로 가져오기
		fin.open("airlineAccount_nameSet.txt", ios::in | ios::out | ios::app);
		while (!fin.eof()) {
			getline(fin, name);
			airlineAccount.pushName(name);
		}
		fin.close();
		
		//정보 불러오기
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

		//정보 불러오기
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
		//예약자의 예약횟수 정보 불러오기
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
		if (loginmenu == 1) { // 로그인 선택
			cout << "로그인 해주세요.\n";
			airlineAccount.setId(Console::loginID());
			airlineAccount.setPassword(Console::loginPass());
			if (airlineAccount.isregistered()) { // ture가 나온다면 로그인 성공이라는 뜻. false일때 1, 비밀번호가 틀림 2, 등록되지 않은 고객
				cout << airlineAccount.getName() << "님 안녕하세요! 메뉴를 선택해주세요.\n";
				break;
			}
			else {
				cout << "등록되지 않은 아이디입니다. 다시 로그인 해주세요.\n";
			}
		}
		else if (loginmenu == 2) { // 회원가입 선택
			airlineAccount.makeAccount();
			//id 파일에저장
			fout.open("airlineAccount_idSet.txt", ios::out | ios::app);
			fout << airlineAccount.getId() << endl;
			fout.close();
			//password 파일에 저장
			fout.open("airlineAccount_passwordSet.txt", ios::out | ios::app);
			fout << airlineAccount.getPassword() << endl;
			fout.close();
			//name 파일에 저장
			fout.open("airlineAccount_nameSet.txt", ios::out | ios::app);
			fout << airlineAccount.getName() << endl;
			fout.close();

			airlineDatabase.save(); // database에 예약 횟수 세이브
			cout << "회원가입이 완료되었습니다.\n로그인하고 메뉴를 선택해주세요.\n";
		}
		else {
			cout << "잘 못 입력하셨습니다.\n";
		}
	}
	

}
