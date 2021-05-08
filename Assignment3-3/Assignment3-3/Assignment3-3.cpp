#include <iostream>
#include <fstream>
#include "cafe.h"

using namespace std;

int main() {
	cafe Cafe;
	bool end = true;
	char command[100];
	int price;
	char menu[100];
	ifstream readFile("menu.txt");
	if (!readFile.is_open()) {
		ofstream writeFile;
		writeFile.open("menu.txt");
		writeFile.close();
	}
	else {
		readFile.close();
	}
	while (end) {
		cout << "Command list: LOAD, PRINT, INSERT, SEARCH, DELETE, EXIT" << endl;
		cout << "CMD>> ";
		cin >> command;
		if (strcmp(command, "INSERT") == 0) {
			while (getchar() != '\n');
			cout << "Menu Name: ";
			cin.getline(menu, 100);
			cout << "Price : ";
			cin >> price;
			Cafe.Insert(price, menu);
		}
		else if (strcmp(command, "PRINT") == 0) {
			if (Cafe.getHead() != nullptr) {
				cout << "Command list: MENU, PRICE" << endl;
				cout << "CMD>> ";
				cin >> menu;
				if (strcmp(menu, "MENU") == 0) {
					cout << "Print by Name order" << endl;
					Cafe.Print_menu(Cafe.getRoot());
					cout << '\n';
				}
				else if (strcmp(menu, "PRICE") == 0) {
					cout << "Print by Price order" << endl;
					Cafe.Print_price();
					cout << '\n';
				}
				else
					cout << "Error" << endl;
			}
			else {
				cout << "Cafe Menu is Empty" << endl;
			}
		}
		else if (strcmp(command, "LOAD") == 0) {
			ifstream readFile("menu.txt");
			char temp[100];
			while (readFile) {
				int len = 0;
				memset(temp, NULL, 100);
				memset(menu, NULL, 100);
				price = 0;
				readFile.getline(temp, 100, '\n');
				if (temp[0] == NULL)
					break;
				for (; temp[len] != ','; len++) {
					menu[len] = temp[len];
				}
				for (int i = len + 1; temp[i] != '\0'; i++) {
					price += temp[i] - '0';
					price *= 10;
				}
				price /= 10;
				Cafe.Insert(price, menu);
			}
			readFile.close();
		}
		else if (strcmp(command, "SEARCH") == 0) {
			if (Cafe.getHead() != nullptr) {
				while (getchar() != '\n');
				cout << "Menu Name: ";
				cin.getline(menu, 100);
				if (Cafe.SEARCH(menu) == -1)
					cout << "Not in menu" << endl;
				else
					cout << "Price: " << Cafe.SEARCH(menu) << endl;
			}
			else
				cout << "Cafe Menu is Empty" << endl;
		}
		else if (strcmp(command, "DELETE") == 0) {
			if (Cafe.getHead() != nullptr) {
				while (getchar() != '\n');
				cout << "Menu Name : ";
				cin.getline(menu, 100);
				if (!Cafe.Delete_node(menu))
					cout << "Not in menu" << endl;
			}
			else {
				cout << "Cafe Menu is Empty" << endl;
			}
		}
		else if (strcmp(command, "EXIT") == 0) {
			end = false;
		}
		else {
			cout << "Error" << endl;
		}
	}
 
}