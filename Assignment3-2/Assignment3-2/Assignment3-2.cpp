#include <iostream>
#include "node.h"
#include "queue.h"


using namespace std;

int is_Enqueue(char* command) { // Enqueue ��� �Է��� �� �Ǿ����� Ȯ���ϴ� �Լ�
	int count = 0; // ������ ������ Ȯ��
	int number = 0; // atoi(�ܾ ���ڷ� �����Ͽ� ����)

	for (int i = 7; i < strlen(command); i++) { //Enqueue ������ ������ �󸶳� �ִ��� Ȯ��
		if (command[i] == ' ')
			count++; // ������ ���� �� ���� ������ ����
	}
	if(count == 1){ // ������ �ϳ��� �־����
		for (int i = 8; i < strlen(command); i++) { //���ڸ� ���ڷ� ��ȯ�ϱ� ���� for��
			if (command[7] == ' ') { // Enqueue������ ������ ���� �ݺ���ó��
				if (command[i] - '0' > 9 || command[i] - '0' < 0) //������ ���� ó��
					return -1; //���ڰ� �ƴϸ� -1��ȯ
				number += command[i] - '0'; // number�� �о�� ���� '0'�� ���� ���ڷ� ��ȯ
				number *= 10; //*10�� ���� ���
			}
			else
				return -1;//Enqueue ���� ���� ������ �ƴϸ� -1��ȯ
		}
		return number / 10; //number�� ���� ��ȯ�ϸ� *10�� �������� ������ 10�� ������ ��ȯ
	}
	else {
		return -1; //������ �������� -1�� ��ȯ
	}
}

int is_Dequeue(char* command, int count) { // Dequeue�� ����� �Է��ߴ��� Ȯ���ϴ� �Լ�
	int number = 0; // �ܾ ���ڷ� �����ϱ� ���� ����
	int count_wspace = 0; //������ ������ ���� ����
	for (int i = 7; i < strlen(command); i++) {
		if (command[i] == ' ') //Dequeue ���� ������ ����� Ȯ��
			count_wspace++;
	}
	if (count_wspace != 1) //������ �Ѱ����� ������
		return -1; // -1�� ��ȯ
	else {
		for (int i = 8; i < strlen(command); i++) {
			if (command[7] == ' ') { //Dequeue������ �׻� ������ ��
				if (command[i] - '0' > 9 || command[i] - '0' < 0) 
					return -1;// ���ڰ� �ƴ� �� -1 ��ȯ
				number += command[i] - '0'; // ���ڸ� ���ڷ� -'0'�� ���־� ��ȯ
				number *= 10; // ���ڿ� 10�� ������
			}
			else
				return -1;//Dequeue������ ������ �ƴ� ���� -1��ȯ
		}
		return number / 10; //�ݺ����� ������� 10��ŭ�� ���� ������ /10�� ���־� ��ȯ
	}
}

int is_Search(char* command) { // Search�� ����� �ԷµǾ����� Ȯ��
	int number = 0; //���ڸ� ���ڷ� ��ȯ �ϴ� ����
	int count_wspace = 0; // ������ ����Ȯ��
	for (int i = 6; i < strlen(command); i++) {
		if (command[i] == ' ') // ������ ������ üũ
			count_wspace++;
	}
	if (count_wspace != 1) //������ 1���� ���� ��
		return -1; //-1�� ��ȯ
	else {
		for (int i = 7; i < strlen(command); i++) {
			if (command[6] == ' ') { //SEARCH �ܾ� �ڿ� �������� �ƴ��� Ȯ��
				if (command[i] - '0' > 9 || command[i] - '0' < 0) //���ڰ� �ƴҰ��
					return -1; // -1�� ��ȯ
				number += command[i] - '0'; // - '0'�� ���־ ���ڸ� ���ڷ� �ٲ�
				number *= 10; //�ڸ����� ������
			}
			else
				return -1; // SEARCH������ ������ �ƴҰ�쿡 -1�� ��ȯ
		}
		return number / 10; //���ڸ��� ���� ������ /10�� ���ش�
	}
}

int main() {
	queue Queue; //ť�� ����
	bst Bst; //����Ʈ���� ����
	char command[20]; //��ɾ �Է¹޴� ����
	int data; // ������ ���� �޴� ����
	int count = 0; //���ݱ��� Queue�� ���� �󸶳� �ִ��� Ȯ���ϴ� ����
	int count_bst = 0; //bst�� ���ڰ� �󸶳� ����Ǿ����� Ȯ���ϴ� ����
	bool end = true; //�ݺ����� ������ ���� �Լ�
	while (end) {
		cin.getline(command , 20); //��ɾ� �Է�
		//cout << is_Enqueue(command) << endl;
		if (strncmp(command, "Enqueue" , 7) == 0) { //Enqueue�� ���� ��
			if (is_Enqueue(command) == -1) {//��ɾ ��¥ Enqueue���� �Լ��� ���� ���� Ȯ�� �� �ƴ� ��
				cout << "Error 200" << endl; //Error�޽��� ���
			}
			else {
				Queue.Enqueue(is_Enqueue(command) , &count); // ���� ���� Enqueue�� �Է��� ���� Queue�� Enqueue�żҵ带 ȣ��
			}
			
		}
		else if (strncmp(command, "Dequeue", 7) == 0) { // Dequeue�� �´��� Ȯ��
			if (is_Dequeue(command, count) == -1) { //��ɾ Dequeue�� �Է� ������ �ȸ��� ���
				cout << "Error 200" << endl; //�����޽��� ���
			}
			else if (count == 0) { // �Է��� Queue�� ���� ���
				cout << "Error 400" << endl; //�����޽��� ���
			}
			else if (is_Dequeue(command, count) >= count) { //Dequeue�� ������ ���� �����ϴ� Queue�� �������� ���� ���
				Queue.All_Dequeue(&count, &Bst); //��� queue�� �����ϴ� �żҵ� ȣ��
			}
			else {
				Queue.Dequeue(is_Dequeue(command,count),&count, &Bst); //�Է��� ������ŭ queue�� �����ϴ� �żҵ� ȣ��
			}
		}
		else if (strcmp(command, "Print_Queue") == 0) { //Print_Queue�� �´��� Ȯ��
			if (count == 0) { // ����� Queue�� �ϳ��� ���� ���
				cout << "Error 500" << endl; //�����޽��� ȣ��
			}
			else {
				Queue.Print_Queue(); //Queue�� 1���̻� �����ϴ� ��� ����ϴ� �żҵ� ȣ��
			}
		}
		else if (strcmp(command, "PRINT POST") == 0) { //PRINT POST�� �´��� Ȯ��
			if (Bst.is_Empty()) { // BST�� ����ִ��� Ȯ��
				cout << "Error 700" << endl; //������� �� �����޽��� ȣ��
			}
			else {
				Bst.Print_Post(Bst.getRoot()); //�ƴ� �� ���� ��ȸ�� ������ ���
				std::cout << '\n';
			}
		}
		else if (strcmp(command, "PRINT IN") == 0) { //PRINT IN�� �´��� Ȯ��
			if (Bst.is_Empty()) { // BST�� ����ִ��� Ȯ��
				cout << "Error 700" << endl;//������� �� �����޽��� ȣ��
			}
			else {
				Bst.Print_in(Bst.getRoot()); //�ƴ� �� ���� ��ȸ�� ������ ���
				std::cout << '\n';
			}
		}
		else if (strcmp(command, "PRINT PRE") == 0) { // PRINT PRE�� �´��� Ȯ��
			if (Bst.is_Empty()) { //BST�� ����ִ��� Ȯ��
				cout << "Error 700" << endl; //������� �� �����޽��� ȣ��
			}
			else {
				Bst.Print_Pre(Bst.getRoot()); //BST�� ���� ��ȸ�� ���� ���
				std::cout << '\n';
			}
		}
		else if (strncmp(command, "SEARCH", 6) == 0) { //SEARCH�� �´��� Ȯ��
			int search_number = is_Search(command); //SEARCH�ϴ� data�� ������ ���� Ȯ��
			if (search_number == -1) { // -1�ϰ�� SEARCH�� �Է������� �߸��Ȱ�
				cout << "Error 200" << endl; // �����޽��� ȣ��
			}
			else {
				if (Bst.Search(search_number) == -1) { // SEARCH�޼ҵ忡�� ���� ���� ��
					cout << "Error 600" << endl; //�����޽��� ȣ��
				}
				else {
					cout << Bst.Search(is_Search(command)) << "is exists" << endl; // SEARCH���� ���� �� SEARCH�ϴ� ���� ���
				}
			}
		}
		else if (strcmp(command, "EXIT") == 0) { //�ݺ��� ����
			end = false; //end�� ���� false�� ����
		}
		else {
			cout << "Error 100" << endl; //��ɾ �߸� �Է� ���� ��� �����޽��� ���
		}
	}
	return 0;
}