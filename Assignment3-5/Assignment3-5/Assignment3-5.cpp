#include <iostream>
#include "LL.h"
#include <Windows.h>
using namespace std;

int main() { 
	LL roulette; // ��ü����
	char command[20];
	bool end = true;
	cout << "Command list(shoot/rotate)" << endl;
	while (end) { // end�� false�϶����� �ݺ�
		cout << "CMD>> ";\
		cin >> command; 
		if (strcmp(command, "shoot") == 0) { //command�� shoot�϶�
			int roulette_number = roulette.shoot(); //�Ѿ��� �ִ� node���� Ȯ��
			if (roulette_number == 1) { // 1�� ��ȯ�ϸ� �Ѿ��� �����Ƿ� �߻��ϰ� die�޽��� ����� �ݺ�������
				cout << "You Died..." << endl;
				end = false; // �ݺ��� ����
			}
			else { // 1�� �ƴҶ��� ������Ƿ� You survived���
				cout << "You Survived!" << endl;
			}
		}
		else if (strcmp(command, "rotate") == 0) { //command�� rotate�� ��
			roulette.rotate(); // head�� rotate�ϴ� �żҵ� ȣ��
			system("cls"); // cls�� ���ݱ��� ����� ����
			//roulette.print();
			cout << "Command list(shoot/rotate)" << endl;
		}
		else { // command�� �ƴ� �ܾ �Է½�
			cout << "Wrong Command!" << endl;
		}
	}
}