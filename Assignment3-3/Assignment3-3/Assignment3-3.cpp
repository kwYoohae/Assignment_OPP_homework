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
	ifstream readFile("menu.txt"); //�޴� �ý�Ʈ�� �ҷ���
	if (!readFile.is_open()) { // �޴��� ������ �ʾ��� ����
		ofstream writeFile; 
		writeFile.open("menu.txt"); //menu.txt����
		writeFile.close(); /// ������ �� ���� �ݱ�
	}
	else {
		readFile.close(); // ������ �� ���� �ݱ�
	}
	while (end) {
		cout << "Command list: LOAD, PRINT, INSERT, SEARCH, DELETE, EXIT" << endl;
		cout << "CMD>> ";
		cin >> command; //Ŀ�ǵ带 �Է¹���
		if (command.compare("INSERT") == 0) { // Ŀ�ǵ尡 Insert�� ��
			while (getchar() != '\n'); // '\n'�� ���ö� ���� ���ڸ� ����
			cout << "Menu Name: "; 
			cin.getline(menu, 100); //menu�� ����
			cout << "Price : ";
			cin >> price; // price�� ����
			Cafe.Insert(price, menu); // �޴��� ������ �����ϴ� �żҵ� ȣ��
		}
		else if (command.compare("PRINT") == 0) {
			if (Cafe.getHead() != nullptr) { //Cafe�� ����� ���� ������� ���� ��
				cout << "Command list: MENU, PRICE" << endl;
				cout << "CMD>> ";
				cin >> menu; // menu �Ǵ� price�� ��������� ������
				if (strcmp(menu, "MENU") == 0) { // menu������ ����ϸ�
					cout << "Print by Name order" << endl;
					Cafe.Print_menu(Cafe.getRoot()); // �޴������� ����ϴ� BST��� �żҵ带 �ҷ���
					cout << '\n';
				}
				else if (strcmp(menu, "PRICE") == 0) {
					cout << "Print by Price order" << endl;
					Cafe.Print_price(); // price���� ����ϴ� �żҵ带 �ҷ���
					cout << '\n';
				}
				else // Menu, Price�� �ƴ� ���� Error�� ���
					cout << "Error" << endl;
			}
			else { // ����� ���� ����ִ� ��Ȳ
				cout << "Cafe Menu is Empty" << endl;
			}
		}
		else if (command.compare("LOAD") == 0) { // Ŀ�ǵ尡 Load�� ��
			ifstream readFile("menu.txt"); // menu.txt�� �ҷ���
			char temp[100];
			while (readFile) {
				int len = 0;
				memset(temp, NULL, 100); // ���� �ʱ�ȭ
				memset(menu, NULL, 100); // ���� �ʱ�ȭ
				price = 0; // ���� �ʱ�ȭ
				readFile.getline(temp, 100, '\n'); //temp�� ������ ���� �� ���� �ҷ���
				if (temp[0] == NULL) // temp�� ��������� ������ ���̱� ������ �о���°��� ������
					break;
				for (; temp[len] != ','; len++) { // ,�� ���� ������ ������
					menu[len] = temp[len]; // �޴��� ����
				}
				for (int i = len + 1; temp[i] != '\0'; i++) {
					price += temp[i] - '0'; // ������ int������ �ٲ�
					price *= 10; //���ݿ� 10�� ���� �ڸ����� �÷��ֱ����ؼ�
				}
				price /= 10; //���������� 10�� �� ��9���������Ƿ� 10���� ��������
				Cafe.Insert(price, menu); // ī��޴��� �߰��ϴ� �żҵ� ȣ��
			}
			readFile.close(); //������ �ݾ���
		}
		else if (command.compare("SEARCH") == 0) { // command�� search�� ��
			if (Cafe.getHead() != nullptr) { // ī���� �޴��� ������� ���� ��
				while (getchar() != '\n'); // // '\n'�� ���ö� ���� ���ڸ� ����
				cout << "Menu Name: ";
				cin.getline(menu, 100); // �޴��ǰ��� ����
				if (Cafe.SEARCH(menu) == -1) // �޴��� ã�� �żҵ忡�� -1�� ��ȯ�ϸ� �޴��� �����Ƿ� ���ٴ� ������
					cout << "Not in menu" << endl;
				else
					cout << "Price: " << Cafe.SEARCH(menu) << endl; // ���� �޴��� ������ �׸޴��� ������ ���
			}
			else
				cout << "Cafe Menu is Empty" << endl; // ī�信 �޴��� ���� �� ���
		}
		else if (command.compare("DELETE") == 0) { // Command�� Delete�ϋ�
			if (Cafe.getHead() != nullptr) { // ī��޴��� ������� ���� ��
				while (getchar() != '\n'); // // '\n'�� ���ö� ���� ���ڸ� ����
				cout << "Menu Name : "; 
				cin.getline(menu, 100); // �޴��� ����
				if (!Cafe.Delete_node(menu)) // ī���� �Է¹��� menu�� �����ϴ� �޼ҵ� ȣ��
					cout << "Not in menu" << endl; // delete�żҵ忡�� false�� ������ �޴��� ���� ������ ���ٰ����
			}
			else { // ī��޴��� ������� ��
				cout << "Cafe Menu is Empty" << endl; 
			}
		}
		else if (command.compare("EXIT") == 0) { //command�� EXIT�� ��
			end = false; //�ݺ�������
		}
		else {
			cout << "Error" << endl;
		}
	}
 
}