#include <iostream>
#include "LL.h"
#include <Windows.h>
using namespace std;

int main() { 
	LL roulette; // 객체생성
	char command[20];
	bool end = true;
	cout << "Command list(shoot/rotate)" << endl;
	while (end) { // end가 false일때까지 반복
		cout << "CMD>> ";\
		cin >> command; 
		if (strcmp(command, "shoot") == 0) { //command가 shoot일때
			int roulette_number = roulette.shoot(); //총알이 있는 node인지 확인
			if (roulette_number == 1) { // 1을 반환하면 총알이 있으므로 발사하고 die메시지 출력후 반복문종료
				cout << "You Died..." << endl;
				end = false; // 반복문 종료
			}
			else { // 1이 아닐때는 살았으므로 You survived출력
				cout << "You Survived!" << endl;
			}
		}
		else if (strcmp(command, "rotate") == 0) { //command가 rotate일 때
			roulette.rotate(); // head를 rotate하는 매소드 호출
			system("cls"); // cls로 지금까지 출력을 지움
			//roulette.print();
			cout << "Command list(shoot/rotate)" << endl;
		}
		else { // command가 아닌 단어를 입력시
			cout << "Wrong Command!" << endl;
		}
	}
}