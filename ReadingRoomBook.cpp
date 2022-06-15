#include <iostream>
using namespace std;

#include "ReadingRoomBook.h"


ReadingRoomBook::ReadingRoomBook() {
	readingRoom = new ReadingRoom*[7];
	for (int i = 0; i < 7; i++) {
		readingRoom[i] = new ReadingRoom[13];
		for (int j = 0; j < 13; j++) {
			date = (i + 1);
			readingRoomName = "일 " + to_string(j + 9) + "시 ~ " + to_string(j + 10) + "시";
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
		menu = Console::select_menu(); //예약:1, 취소:2, 보기:3, 통계:4, 끝내기:5
		switch (menu)
		{
		case 1: { // 예약
			// 나이 14세 이상?
			isOver13 = Console::isOver13();
			if (isOver13 == 2) { // 14세 이상 아님
				cout << "\n이 독서실은 13세 이하 세대원은 예약이 불가합니다.\n";
				break;
			}
			else { // 14세 이상임
				// 성별 선택
				sex = Console::select_sex();
				// 날짜 선택
				cout << "\n예약 날짜를 선택해주세요.";
				date = Console::select_date();
				if (readingRoomAccount.getBookCount(date) > 0) { // 예약횟수 남았으면
					// 시간 선택
					readingRoomTime = Console::select_ReadingRoomTime();
					// 이제 예약하자
					while (1) {
						cout << "\n*주의 사항*\n앞뒤, 양옆에는 같은 성의 이용자가 예약할 수 없습니다.\n";
						// 독서실 현상태 보여주기
						readingRoom[date - 1][readingRoomTime - 1].showReadingRoom();
						// 좌석 선택
						seatRow = Console::select_seatrow();
						seatColumm = Console::select_seatcolumm();
						name = to_string(sex) + readingRoomAccount.getName();
						if (readingRoom[date - 1][readingRoomTime - 1].setBook(seatRow, seatColumm, name)) {
							readingRoomAccount.useBookCount(date);
							readingRoomDatabase.addSeatdata(readingRoomAccount.getClientNum());
							readingRoom[date - 1][readingRoomTime - 1].addBookCount(seatRow, seatColumm);
							readingRoomDatabase.addSexdata(sex);

							//예약정보 저장
							fout.open("readingRoomBook_reloadSet.txt", ios::out | ios::app);
							fout << date << " " << readingRoomTime << " " << seatRow << " " << seatColumm << " " << name << " " << readingRoomAccount.getBookCount(date) << " " << readingRoom[date - 1][readingRoomTime - 1].getBookCount(seatRow, seatColumm) << " " << readingRoomAccount.getClientNum() << endl;
							fout.close();

							//예약자의 예약횟수, 성별 예약횟수 정보 저장
							fout.open("readingRoomBook_DataSet.txt", ios::out | ios::app);
							fout << readingRoomAccount.getClientNum() << " " << readingRoomDatabase.getSeatdata(readingRoomAccount.getClientNum()) << " " << readingRoomDatabase.getSexdata(1) << " " << readingRoomDatabase.getSexdata(2) << endl;
							fout.close();
							

							break;
						}
							
					}
				}
				else { // 예약횟수 남지 않았다면
					cout << "\n세대당 하루 예약시간이 4시간을 넘을 수 없습니다.\n";
					break;

				}
				
			}
			
			break;
		}
		case 2: { // 취소
			// 성별 선택
			sex = Console::select_sex();
			// 날짜 선택
			cout << "\n예약 날짜를 선택해주세요.";
			date = Console::select_date();
			// 시간 선택
			readingRoomTime = Console::select_ReadingRoomTime();
			// 이제 예약하자
			while (1) {
				// 독서실 현상태 보여주기
				readingRoom[date - 1][readingRoomTime - 1].showReadingRoom();
				// 좌석 선택
				seatRow = Console::select_seatrow();
				seatColumm = Console::select_seatcolumm();
				name = to_string(sex) + readingRoomAccount.getName();
				if (readingRoom[date - 1][readingRoomTime - 1].cancelBook(seatRow, seatColumm, name)) {
					readingRoomAccount.cancelBookCount(date);
					readingRoomDatabase.cancelSeatdata(readingRoomAccount.getClientNum());
					readingRoom[date - 1][readingRoomTime - 1].cancelBookCount(seatRow, seatColumm);
					readingRoomDatabase.cancelSexdata(sex);
					break; // 알맞게 취소하면 break
				}
					
			}
			break;
		}
		case 3: { // 보기
			// 날짜 선택
			cout << "\n예약 날짜를 선택해주세요.";
			date = Console::select_date();
			// 시간 선택
			readingRoomTime = Console::select_ReadingRoomTime();
			// 독서실 현상태 보여주기
			readingRoom[date - 1][readingRoomTime - 1].showReadingRoom();
			break;
		}
		case 4: { // 통계
			// 어떤 통계를 원하는지 
			information = Console::select_sexInformation();
			if (information == 1) { // 고객의 예약 횟수
				cout << "\n고객님의 예약 횟수는 " << readingRoomDatabase.getSeatdata(readingRoomAccount.getClientNum()) << "회 입니다.\n";
			}
			else if (information == 2) { // 좌석별 예약 횟수
				// 날짜 선택
				cout << "\n예약 날짜를 선택해주세요.";
				date = Console::select_date();
				// 시간 선택
				readingRoomTime = Console::select_ReadingRoomTime();
				// 좌석 선택
				seatRow = Console::select_seatrow();
				seatColumm = Console::select_seatcolumm();
				readingRoom[date - 1][readingRoomTime - 1].showBookCount(seatRow, seatColumm);
			}
			else { //성별 예약 횟수
				// 성별 선택
				sex = Console::select_sex();
				if (sex == 1) {
					cout << "\n남성 고객님의 예약 횟수는 " << readingRoomDatabase.getSexdata(sex) << "회 입니다.\n";
				}
				else {
					cout << "\n여성 고객님의 예약 횟수는 " << readingRoomDatabase.getSexdata(sex) << "회 입니다.\n";
				}
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

void ReadingRoomBook::login() {
	if (readingRoomAccount.getClientNum() == -1) {
		//리로드
		//idset에 저장된 id 벡터 셋으로 가져오기
		fin.open("readingRoomAccount_idSet.txt", ios::in | ios::out | ios::app);
		while (!fin.eof()) {
			getline(fin, id);
			readingRoomAccount.pushId(id);
			readingRoomDatabase.save();
		}
		fin.close();

		//passwordset에 저장된 password 벡터 셋으로 가져오기
		fin.open("readingRoomAccount_passwordSet.txt", ios::in | ios::out | ios::app);
		while (!fin.eof()) {
			getline(fin, password);
			readingRoomAccount.pushPassword(password);
		}
		fin.close();

		//nameset에 저장된 name 벡터 셋으로 가져오기
		fin.open("readingRoomAccount_nameSet.txt", ios::in | ios::out | ios::app);
		while (!fin.eof()) {
			getline(fin, name);
			readingRoomAccount.pushName(name);
		}
		fin.close();

		//정보 불러오기
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
		//예약자의 예약횟수 정보 불러오기
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
		cout << "\n본 아파트는 300층의 초고층아파트로 거주하시는 아파트의 층수가 세대 ID입니다.\n";
		loginmenu = Console::loginMenu();
		if (loginmenu == 1) { // 로그인 선택
			cout << "로그인 해주세요.\n";
			readingRoomAccount.setId(Console::loginID());
			readingRoomAccount.setPassword(Console::loginPass());
			if (readingRoomAccount.isregistered()) { // ture가 나온다면 로그인 성공이라는 뜻. false일때 1, 비밀번호가 틀림 2, 등록되지 않은 고객
				cout << readingRoomAccount.getName() << "님 안녕하세요! 메뉴를 선택해주세요.\n";
				break;
			}
			else {
				cout << "등록되지 않은 아이디입니다. 다시 로그인 해주세요.\n";
			}
		}
		else if (loginmenu == 2) { // 회원가입 선택
			cout << "\n회원가입을 할때 이름을 세대주로 해주시고 id는 세대 ID로 해주시기 바랍니다.\n";
			readingRoomAccount.makeAccount();
			//id 파일에저장
			fout.open("readingRoomAccount_idSet.txt", ios::out | ios::app);
			fout << readingRoomAccount.getId() << endl;
			fout.close();
			//password 파일에 저장
			fout.open("readingRoomAccount_passwordSet.txt", ios::out | ios::app);
			fout << readingRoomAccount.getPassword() << endl;
			fout.close();
			//name 파일에 저장
			fout.open("readingRoomAccount_nameSet.txt", ios::out | ios::app);
			fout << readingRoomAccount.getName() << endl;
			fout.close();

			readingRoomDatabase.save(); // database에 예약 횟수 세이브
			cout << "회원가입이 완료되었습니다.\n로그인하고 메뉴를 선택해주세요.\n";
		}
		else {
			cout << "잘 못 입력하셨습니다.\n";
		}
	}

}