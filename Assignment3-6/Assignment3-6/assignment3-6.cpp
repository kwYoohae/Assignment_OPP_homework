#include "block_horse.h"
#include "board1D.h"
#include "Player.h"
#include "move.h"
#include <Windows.h>
#include <crtdbg.h>

void make_board(board* Board, board* Board_short1, board* Board_short2); //보드를 생성하는 함수
bool select_exists(player Player2, int number); // 말을 select할 때 이동할 수 있는 말인지 확인하는 함수
using namespace std;

int main() {
	board Board; // 바깥쪽 Board생성
	board Board_short1; // 안쪽 지름길 1번 Board생성 
	board Board_short2; // 안쪽 지름길 2번 Board생성
	player Player1; // Player1번 생성
	player Player2; // Player2번 생성
	yut Yut; // 윷 객체 생성
	Player1.inster_name('A'); // Player의 각 말에 이름 붙여주는 매소드 호출
	Player2.inster_name('B');// Player의 각 말에 이름 붙여주는 매소드 호출
	make_board(&Board, &Board_short1, &Board_short2); // 보드 생성하는 함수 호출
	int turn = 0; // 누구의 턴인지 확인하는 변수
	bool end = true; // 게임을 계속 시작하는지 확인 하는 변수
	char command[20]; // Command입력을 받는 변수
	int select_move = 0; // 몇번째 윷을 움직일 건지 확인하는 변수
	int select_horse = 0; //몇번째 말을 움직인 건지 확인하는 변수
	int happen = 0; // 던지고 난 뒤의 행동을 결정하는 변수
	while (end) { // end가 false가 될때까지 움직임
		Board.Print(&Board_short1, &Board_short2); // Board를 출력하는 매소드 호출
		if (happen == 2 || happen==3 || happen==4) { // happen이 각각 2 , 3 , 4 일때는 상대말이 잡히는 경우이기 떄문에
			turn--; // 다시 잡은 플레이어가 동작을 실행할수 있도록 turn-1;
			cout << "You caught opponent's horse!" << endl; 
		}
		else if (happen == -2) { // happen == -2일 때는 아무말도 안나왔는데 뺵도인 상황
			cout << "Horses in the hand are impossible to 'back do'" << endl;
		}
		cout << "Player "<< turn % 2 + 1 <<" trun!(throw/exit)" << '\n'; 
		cout << "CMD>> ";
		cin >> command; // command입력을 받음
		if (strcmp(command, "throw") == 0) { //command가 throw일 때
			bool return_throw = Yut.Throw_yut(); // 윷을던지는 매소드의 반환값을 받음(더 던질지 안던질지)
			while (return_throw) { // return_throw가 0이 될때까지 반복함
				cin.clear(); // cin버퍼를 지움
				cout << "Throw agin!" << endl; 
				cout << "CMD>> ";
				cin >> command; //커맨드를 받음
				if (strcmp(command, "throw") == 0) { // command가 throw인지 확인
					return_throw = Yut.Throw_yut(); // throw를 입력하면 윷을던지고 반환값을 받음
				}
				else if (strcmp(command, "exit") == 0) { //exit를 입력하는지 확인
					return_throw = false; // 반복문을 나가기 위해서 false를 넣어줌
					end = false; // 반복문 종료
				}
				else {
					cout << "wrong command" << endl; //두개의 command 이외의 값을 입력했을 때
				}
			}
			if (end) { // end가 false로 반복문을 종료할 때는 안들어감
				happen = 0; // happen 초기화
				while (Yut.getHead()) { // Yut을 던진 값이 없을 때 까지 계속 반복
					if (happen == 2 || happen == 3 || happen == 4) { // happen 2, 3, 4일때는 상대말을 잡았으므로 한번더 던지기 위해서 예외처리
						break;
					}
					Board.Print(&Board_short1, &Board_short2); // Board를 print하는 매소드 호출
					Yut.print_yut(); // 윷
					cout << "Select move: ";
					cin >> select_move;
					if (turn % 2 == 0)
						Player1.print_horse();
					else
						Player2.print_horse();
					cout << "Select horse: ";
					cin >> select_horse;
					if (turn % 2 == 0) {
						if (select_exists(Player1, select_horse)) {
							happen = Player1.move_horse(select_move, select_horse, &Yut, &Board, &Board_short1, &Board_short2);
						}
					}
					else {
						if(select_exists(Player2, select_horse))
							happen = Player2.move_horse(select_move, select_horse, &Yut, &Board, &Board_short1, &Board_short2);
					}
				}
			}
			turn++;
			if (Player1.getHead() == nullptr) {
				cout << "Player 1 Win!" << '\n';
				end = false;
			}
			else if (Player2.getHead() == nullptr) {
				cout << "Player 2 Win!" << '\n';
				end = false;
			}
		}
		else if (strcmp(command, "exit") == 0) {
			cout << "end" << endl;
			end = false;
		}
		else {
			cout << "wrong command!" << endl;
		}
	}
	Player1.delete_player();
	Player2.delete_player();
	return 0;
	_CrtDumpMemoryLeaks();
}

void make_board(board* Board, board* Board_short1, board* Board_short2) {
	for (int i = 0; i < 5; i++) {
		Board_short2->Insert();
		if (i == 2) {
			Board_short2->setCenter(Board_short2->getTail());
		}
	}

	for (int i = 0; i < 5; i++) {
		Board_short1->Insert();
		if (i == 2) {
			Board_short1->setCenter(Board_short1->getTail());
			Board_short1->getCenter()->setShortcut(Board_short2->getCenter()->getNext());
		}
	}

	for (int i = 0; i < 20; i++) {
		Board->Insert();
		if (i == 0) {
			Board_short2->getTail()->setNext(Board->getHead());
		}
		else if (i == 5) {
			Board->getTail()->setShortcut(Board_short1->getHead());
			Board_short1->getHead()->setPrev(Board->getTail());
		}
		else if (i == 10) {
			Board->getTail()->setShortcut(Board_short2->getHead());
			Board_short2->getHead()->setPrev(Board->getTail());
		}
		else if (i == 15) {
			Board_short1->getTail()->setNext(Board->getTail());
		}
	}
	Board->getTail()->setNext(Board->getHead());
	Board->getHead()->setPrev(Board->getTail()->getPrev());
}

bool select_exists(player Player , int number) {
	horse *pTemp = Player.getHead();
	if (number > 5 || number < 1)
		return false;
	else {
		for (int i = 1; i < number; i++) {
			pTemp = pTemp->getNext();
		}
		if (pTemp->getNow_carry()) {
			cout << "now carry horse you must choose diffrent horse" << '\n';
			return false;
		}
		return true;
	}
}