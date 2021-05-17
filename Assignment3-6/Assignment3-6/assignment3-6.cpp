#include "block_horse.h"
#include "board1D.h"
#include "Player.h"
#include "move.h"
#include <Windows.h>

void make_board(board* Board, board* Board_short1, board* Board_short2);
//void throw_print(int turn);
using namespace std;

int main() {
	board Board;
	board Board_short1;
	board Board_short2;
	player Player1;
	player Player2;
	yut Yut;
	Player1.inster_name('A');
	Player2.inster_name('B');
	make_board(&Board, &Board_short1, &Board_short2);
	//cout << Board.getHead()->getNext() << endl;
	int turn = 0;
	bool end = true;
	char command[20];
	int select_move = 0;
	int select_horse = 0;
	int happen = 0;
	while (end) {
		Board.Print(&Board_short1, &Board_short2);
		if (happen == 2) {
			turn--;
			cout << "You caught opponent's horse!" << endl;
		}
		cout << "Player "<< turn % 2 + 1 <<" trun!(throw/exit)" << '\n';
		cout << "CMD>> ";
		cin >> command;
		if (strcmp(command, "throw") == 0) {
			bool return_throw = Yut.Throw_yut();
			while (return_throw) {
				cin.clear();
				cout << "Throw agin!" << endl;
				cout << "CMD>> ";
				cin >> command;
				if (strcmp(command, "throw") == 0) {
					return_throw = Yut.Throw_yut();
				}
				else if (strcmp(command, "exit") == 0) {
					end = false;
				}
				else {
					cout << "wrong command" << endl;
				}
			}
			if (end) {
				happen = 0;
				while (Yut.getHead()) {
					Board.Print(&Board_short1, &Board_short2);
					Yut.print_yut();
					cout << "Select move: ";
					cin >> select_move;
					if (turn % 2 == 0)
						Player1.print_horse();
					else
						Player2.print_horse();
					cout << "Select horse: ";
					cin >> select_horse;
					if (turn % 2 == 0)
						happen = Player1.move_horse(select_move, select_horse, &Yut, &Board);
					else
						happen = Player2.move_horse(select_move, select_horse, &Yut, &Board);
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
}