#include <iostream>
#include <string.h>
#include "node.h"
#include "list.h"

using namespace std;


int main() {
	list List; // list����
	char word[20]; //�ܾ �޴� ����
	bool exit = true; // while���� ���� ����
	int count = 0; // �ܾ��� ������ ����� ���� ����
	while (exit) {
		cout << "CMD(Word/exit)>> ";
		cin >> word;//�ܾ �Է¹���
		if (strcmp(word,"exit") == 0) { //exit�� �Է��ϸ� 
			exit = false; // exit�� false�� �Ǹ鼭 �ݺ����� �����
		}
		else if (count == 0) { // ó�� �Է��Ҷ�
			List.Insert(word, count); // List�� Insert�żҵ� ȣ��
			List.Print(); // �ܾ ���
			count++; // �ܾ��� ���� �߰�
		}
		else {
			if (List.backward_word(word)) { // �ڿ����ڿ� �Է´ܾ �̾������� Ȯ���ϴ� �żҵ�
				if (List.Search_equal(word)) { // ���� ���ڰ� ���ݱ��� �־����� Ȯ��
					List.Insert(word, count); // ���� �Է�
					List.Print(); //���� ���
					count++; // �ܾ��� ���� �߰�
				}
				else {
					cout << "Already Exists. " << endl; // �̹� �ִ� �ܾ��� �� ���
				}
			}
			else {
				cout << "Not Chained" << endl; //�������ܾ��� ������ ���ڿ� �Է��� ù��° ���ڰ� ���̾��� �� ���
			}

		}
	}
	
}