#include <iostream>
using namespace std;

#include "RestaurantBook.h"

RestaurantBook::RestaurantBook() {
	sale = new Sale * [7];
	for (int i = 0; i < 7; i++) {
		sale[i] = new Sale[2];
		date = i + 1;
		sale[i][0].setSaleName(date, "일 점심");
		sale[i][1].setSaleName(date, "일 저녁");
	}
	walkinTable = new Table[2];
}

RestaurantBook::~RestaurantBook() {
	//sale도 delete해야함
	delete[] walkinTable;
}


void RestaurantBook::book() {
	while (1) {
		int flag = 1;
		if (walkinTable[0].showName() == restaurantAccount.getName() || walkinTable[1].showName() == restaurantAccount.getName()) { // 현재 워크인 테이블 이용자에게만 뜨는 메세지
			finishMeal = Console::finishMeal();
			if (finishMeal == 1) { // 식사 마치기를 선택
				cout << "\n또 오세요!\n\n";
				if (!waitingQueue.empty()) {
					cout << waitingQueue.front() << "님 들어오세요! 식사 맛있게 하세요!\n";
					if (walkinTable[0].showName() == restaurantAccount.getName()) { // 1번 테이블 사용자
						walkinTable[0].resetName();
						walkinTable[0].setName(waitingQueue.front());
						waitingQueue.pop();
					}
					else { // 2번 테이블 사용자
						walkinTable[1].resetName();
						walkinTable[1].setName(waitingQueue.front());
						waitingQueue.pop();
					}
					break;
				}
				
			}
		}
		menu = Console::select_menu(); //예약:1, 취소:2, 보기:3, 통계:4, 끝내기:5
		switch (menu)
		{
		case 1: { // 예약
			// 워크인 물어보기
			isWalkIn = Console::isWalkIn();
			if (isWalkIn == 1) { // 워크인 손님
				// 인원 물어보기
				memberNum = Console::memberNum();
				if (memberNum > 6) {
					cout << "\n이 식당은 6인 테이블로 구성되어있습니다.\n";
					cout << "6인 이상은 예약이 불가합니다.\n";
					break;
				}
				else { // 6인 이하 인원
					// 8세 이상 물어보기
					isOver7 = Console::isOver7();
					if (isOver7 == 2) {
						cout << "\n이 식당은 7세 이하 아동은 예약이 불가합니다.\n";
						break;
					}
					else { // 모두 8세 이상
						if (walkinTable[0].showName() == "---" || walkinTable[1].showName() == "---") { // 빈 워크인테이블이 있다면
							cout << "\n식사 맛있게 하세요!\n";
							if (walkinTable[0].showName() == "---") {
								walkinTable[0].setName(restaurantAccount.getName());
							}
							else {
								walkinTable[1].setName(restaurantAccount.getName());
							}
							flag = 0;
						}
						else { // 빈 워크인테이블이 없다면
							cout << "\n대기 " << (int)waitingQueue.size() + 1 << "번 입니다.\n조금만 기다려 주세요.\n";
							waitingQueue.push(restaurantAccount.getName());
						}
					
					}
				}
			}
			else { // 일반 예약 손님
				// 인원 물어보기
				memberNum = Console::memberNum();
				if (memberNum > 6) {
					cout << "\n이 식당은 6인 테이블로 구성되어있습니다.\n";
					cout << "6인 이상은 예약이 불가합니다.\n";
					break;
				}
				else { // 6인 이하 인원
					// 8세 이상 물어보기
					isOver7 = Console::isOver7();
					if (isOver7 == 2) {
						cout << "\n이 식당은 7세 이하 아동은 예약이 불가합니다.\n";
						break;
					}
					else { // 모두 8세 이상
						// 날짜 선택
						cout << "\n예약 날짜를 선택해주세요.";
						date = Console::select_date();
						// 점심 저녁중 선택
						whenEat = Console::select_whenEat();
						//이제 예약하자
						while (1) {
							// 테이블 현상태 보여주기
							sale[date - 1][whenEat - 1].showSale();
							//테이블 선택
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
		case 2: { // 취소
			// 워크인 물어보기
			isWalkIn = Console::isWalkIn();
			if (isWalkIn == 1) { // 워크인 손님
				
				cout << "\n워크인 대기 취소는 직원에게 문의 하세요\n";
			}
			else { // 일반 예약 손님
				cout << "\n예약 날짜를 선택해주세요.";
				// 날짜 선택
				date = Console::select_date();
				// 점심 저녁중 선택
				whenEat = Console::select_whenEat();
				//이제 예약하자
				while (1) {
					// 테이블 현상태 보여주기
					sale[date - 1][whenEat - 1].showSale();
					//테이블 선택
					tableNum = Console::select_table();
					if (sale[date - 1][whenEat - 1].cancelBook(tableNum, restaurantAccount.getName())) {
						restaurantDatabase.cancelTabledata(restaurantAccount.getClientNum());
						sale[date - 1][whenEat - 1].cancelBookCount(tableNum);
						break; // 알맞게 취소하면 break
					}
				}
			}
			break;
		}
		case 3: { // 보기
			// 워크인 물어보기
			isWalkIn = Console::isWalkIn();
			if (isWalkIn == 1) { // 워크인 손님

				cout << "\n워크인 대기 보기는 직원에게 문의 하세요\n";
			}
			else { // 일반 예약 손님
				cout << "\n예약 날짜를 선택해주세요.";
				// 날짜 선택
				date = Console::select_date();
				// 점심 저녁중 선택
				whenEat = Console::select_whenEat();
				//이제 예약하자
				// 테이블 현상태 보여주기
				sale[date - 1][whenEat - 1].showSale();
			}
			break;
		}
		case 4: { // 통계
			// 어떤 통계를 원하는지 
			information = Console::select_tableInformation();
			if (information == 1) { // 고객의 예약 횟수
				cout << "\n고객님의 예약 횟수는 " << restaurantDatabase.getTabledata(restaurantAccount.getClientNum()) << "회 입니다.\n";
			}
			else { // 좌석별 예약 횟수
				// 날짜 선택
				cout << "\n예약 날짜를 선택해주세요.";
				date = Console::select_date();
				// 점심 저녁중 선택
				whenEat = Console::select_whenEat();
				//테이블 선택
				tableNum = Console::select_table();
				sale[date - 1][whenEat - 1].showBookCount(tableNum);
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

void RestaurantBook::login() {
	while (1) {
		loginmenu = Console::loginMenu();
		if (loginmenu == 1) { // 로그인 선택
			cout << "로그인 해주세요.\n";
			restaurantAccount.setId(Console::loginID());
			restaurantAccount.setPassword(Console::loginPass());
			if (restaurantAccount.isregistered()) { // ture가 나온다면 로그인 성공이라는 뜻. false일때 1, 비밀번호가 틀림 2, 등록되지 않은 고객
				cout << restaurantAccount.getName() << "님 안녕하세요! 메뉴를 선택해주세요.\n";
				break;
			}
			else {
				cout << "등록되지 않은 아이디입니다. 다시 로그인 해주세요.\n";
			}
		}
		else if (loginmenu == 2) { // 회원가입 선택
			restaurantAccount.makeAccount();
			restaurantDatabase.save(); // database에 예약 횟수 세이브
			cout << "회원가입이 완료되었습니다.\n로그인하고 메뉴를 선택해주세요.\n";
		}
		else {
			cout << "잘 못 입력하셨습니다.\n";
		}
	}

}