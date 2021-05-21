#include <iostream>
#include <fstream>
#include "cafe.h"
#include <string>
using namespace std;

int main() {
	cafe Cafe;
	bool end = true;
	string command;
	int price;
	char menu[100];
	ifstream readFile("menu.txt"); //메뉴 택스트를 불러옴
	if (!readFile.is_open()) { // 메뉴가 열리지 않았을 때는
		ofstream writeFile; 
		writeFile.open("menu.txt"); //menu.txt생성
		writeFile.close(); /// 파일을 연 것을 닫기
	}
	else {
		readFile.close(); // 파일을 연 것을 닫기
	}
	while (end) {
		cout << "Command list: LOAD, PRINT, INSERT, SEARCH, DELETE, EXIT" << endl;
		cout << "CMD>> ";
		cin >> command; //커맨드를 입력받음
		if (command.compare("INSERT") == 0) { // 커맨드가 Insert일 때
			while (getchar() != '\n'); // '\n'이 나올때 까지 문자를 받음
			cout << "Menu Name: "; 
			cin.getline(menu, 100); //menu를 받음
			cout << "Price : ";
			cin >> price; // price를 받음
			Cafe.Insert(price, menu); // 메뉴와 가격을 저장하는 매소드 호출
		}
		else if (command.compare("PRINT") == 0) {
			if (Cafe.getHead() != nullptr) { //Cafe에 저장된 값이 비어있지 않을 떄
				cout << "Command list: MENU, PRICE" << endl;
				cout << "CMD>> ";
				cin >> menu; // menu 또는 price로 출력할지를 ㅂ다음
				if (strcmp(menu, "MENU") == 0) { // menu순으로 출력하면
					cout << "Print by Name order" << endl;
					Cafe.Print_menu(Cafe.getRoot()); // 메뉴순으로 출력하는 BST출력 매소드를 불러옴
					cout << '\n';
				}
				else if (strcmp(menu, "PRICE") == 0) {
					cout << "Print by Price order" << endl;
					Cafe.Print_price(); // price별로 출력하는 매소드를 불러옴
					cout << '\n';
				}
				else // Menu, Price가 아닐 떄는 Error를 출력
					cout << "Error" << endl;
			}
			else { // 저장된 값이 비어있는 상황
				cout << "Cafe Menu is Empty" << endl;
			}
		}
		else if (command.compare("LOAD") == 0) { // 커맨드가 Load일 떄
			ifstream readFile("menu.txt"); // menu.txt를 불러옴
			char temp[100];
			while (readFile) {
				int len = 0;
				memset(temp, NULL, 100); // 값을 초기화
				memset(menu, NULL, 100); // 값을 초기화
				price = 0; // 값을 초기화
				readFile.getline(temp, 100, '\n'); //temp에 한줄이 끝날 때 까지 불러옴
				if (temp[0] == NULL) // temp가 비어있으면 마지막 줄이기 때문에 읽어오는것을 종료함
					break;
				for (; temp[len] != ','; len++) { // ,가 있을 떄까지 물러옴
					menu[len] = temp[len]; // 메뉴를 저장
				}
				for (int i = len + 1; temp[i] != '\0'; i++) {
					price += temp[i] - '0'; // 가격을 int형으로 바꿈
					price *= 10; //가격에 10을 곱합 자릿수를 올려주기위해서
				}
				price /= 10; //마지막값은 10이 더 곱9해져있으므로 10으로 나누어줌
				Cafe.Insert(price, menu); // 카페메뉴를 추가하는 매소드 호출
			}
			readFile.close(); //파일을 닫아줌
		}
		else if (command.compare("SEARCH") == 0) { // command가 search일 대
			if (Cafe.getHead() != nullptr) { // 카페의 메뉴가 비어있지 않을 때
				while (getchar() != '\n'); // // '\n'이 나올때 까지 문자를 받음
				cout << "Menu Name: ";
				cin.getline(menu, 100); // 메뉴의값을 받음
				if (Cafe.SEARCH(menu) == -1) // 메뉴를 찾는 매소드에서 -1을 반환하면 메뉴가 없으므로 없다는 명령출력
					cout << "Not in menu" << endl;
				else
					cout << "Price: " << Cafe.SEARCH(menu) << endl; // 만약 메뉴가 있으면 그메뉴의 가격을 출력
			}
			else
				cout << "Cafe Menu is Empty" << endl; // 카페에 메뉴가 없을 때 출력
		}
		else if (command.compare("DELETE") == 0) { // Command가 Delete일떄
			if (Cafe.getHead() != nullptr) { // 카페메뉴가 비어있지 않을 때
				while (getchar() != '\n'); // // '\n'이 나올때 까지 문자를 받음
				cout << "Menu Name : "; 
				cin.getline(menu, 100); // 메뉴를 받음
				if (!Cafe.Delete_node(menu)) // 카페의 입력받은 menu를 삭제하는 메소드 호출
					cout << "Not in menu" << endl; // delete매소드에서 false를 받으면 메뉴가 없기 때문에 없다고출력
			}
			else { // 카페메뉴가 비어있을 때
				cout << "Cafe Menu is Empty" << endl; 
			}
		}
		else if (command.compare("EXIT") == 0) { //command가 EXIT일 떄
			end = false; //반복문종료
		}
		else {
			cout << "Error" << endl;
		}
	}
 
}