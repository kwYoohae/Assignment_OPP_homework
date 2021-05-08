#include <iostream>
#include "LL.h"
#include <Windows.h>
using namespace std;

int main() {
	LL roulette;
	char command[20];
	bool end = true;
	cout << "Command list(shoot/rotate)" << endl;
	while (end) {
		cout << "CMD>> ";\
		cin >> command;
		if (strcmp(command, "shoot") == 0) {
			int roulette_number = roulette.shoot();
			if (roulette_number == 1) {
				cout << "You Died..." << endl;
				end = false;
			}
			else {
				cout << "You Survived!" << endl;
			}
		}
		else if (strcmp(command, "rotate") == 0) {
			roulette.rotate();
			system("cls");
			cout << "Command list(shoot/rotate)" << endl;
		}
		else {
			cout << "Wrong Command!" << endl;
		}
	}
}