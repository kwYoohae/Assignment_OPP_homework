#include "block_horse.h"
#include "board1D.h"
#include "Player.h"
#include "move.h"
#include <Windows.h>
#include <crtdbg.h>

void make_board(board* Board, board* Board_short1, board* Board_short2); //���带 �����ϴ� �Լ�
bool select_exists(player Player2, int number); // ���� select�� �� �̵��� �� �ִ� ������ Ȯ���ϴ� �Լ�
using namespace std;

int main() {
	board Board; // �ٱ��� Board����
	board Board_short1; // ���� ������ 1�� Board���� 
	board Board_short2; // ���� ������ 2�� Board����
	player Player1; // Player1�� ����
	player Player2; // Player2�� ����
	yut Yut; // �� ��ü ����
	Player1.inster_name('A'); // Player�� �� ���� �̸� �ٿ��ִ� �żҵ� ȣ��
	Player2.inster_name('B');// Player�� �� ���� �̸� �ٿ��ִ� �żҵ� ȣ��
	make_board(&Board, &Board_short1, &Board_short2); // ���� �����ϴ� �Լ� ȣ��
	int turn = 0; // ������ ������ Ȯ���ϴ� ����
	bool end = true; // ������ ��� �����ϴ��� Ȯ�� �ϴ� ����
	char command[20]; // Command�Է��� �޴� ����
	int select_move = 0; // ���° ���� ������ ���� Ȯ���ϴ� ����
	int select_horse = 0; //���° ���� ������ ���� Ȯ���ϴ� ����
	int happen = 0; // ������ �� ���� �ൿ�� �����ϴ� ����
	while (end) { // end�� false�� �ɶ����� ������
		Board.Print(&Board_short1, &Board_short2); // Board�� ����ϴ� �żҵ� ȣ��
		if (happen == 2 || happen==3 || happen==4) { // happen�� ���� 2 , 3 , 4 �϶��� ��븻�� ������ ����̱� ������
			turn--; // �ٽ� ���� �÷��̾ ������ �����Ҽ� �ֵ��� turn-1;
			cout << "You caught opponent's horse!" << endl; 
		}
		else if (happen == -2) { // happen == -2�� ���� �ƹ����� �ȳ��Դµ� ������ ��Ȳ
			cout << "Horses in the hand are impossible to 'back do'" << endl;
		}
		cout << "Player "<< turn % 2 + 1 <<" trun!(throw/exit)" << '\n'; 
		cout << "CMD>> ";
		cin >> command; // command�Է��� ����
		if (strcmp(command, "throw") == 0) { //command�� throw�� ��
			bool return_throw = Yut.Throw_yut(); // ���������� �żҵ��� ��ȯ���� ����(�� ������ �ȴ�����)
			while (return_throw) { // return_throw�� 0�� �ɶ����� �ݺ���
				cin.clear(); // cin���۸� ����
				cout << "Throw agin!" << endl; 
				cout << "CMD>> ";
				cin >> command; //Ŀ�ǵ带 ����
				if (strcmp(command, "throw") == 0) { // command�� throw���� Ȯ��
					return_throw = Yut.Throw_yut(); // throw�� �Է��ϸ� ���������� ��ȯ���� ����
				}
				else if (strcmp(command, "exit") == 0) { //exit�� �Է��ϴ��� Ȯ��
					return_throw = false; // �ݺ����� ������ ���ؼ� false�� �־���
					end = false; // �ݺ��� ����
				}
				else {
					cout << "wrong command" << endl; //�ΰ��� command �̿��� ���� �Է����� ��
				}
			}
			if (end) { // end�� false�� �ݺ����� ������ ���� �ȵ�
				happen = 0; // happen �ʱ�ȭ
				while (Yut.getHead()) { // Yut�� ���� ���� ���� �� ���� ��� �ݺ�
					if (happen == 2 || happen == 3 || happen == 4) { // happen 2, 3, 4�϶��� ��븻�� ������Ƿ� �ѹ��� ������ ���ؼ� ����ó��
						break;
					}
					Board.Print(&Board_short1, &Board_short2); // Board�� print�ϴ� �żҵ� ȣ��
					Yut.print_yut(); // ��
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