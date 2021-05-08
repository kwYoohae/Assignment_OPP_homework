#pragma once
#include <iostream>
#include "node.h"

using namespace std;

class list {
private:
	node*  pHead; //pHead����
	node* pTail; //pTail����
public:
	list(); //������
	~list(); //�Ҹ���

	void Insert(char* str , int count); //�ܾ �ִ� �żҵ�
	void Print(); // ����ϴ� �żҵ�
	bool Search_equal(char* str); //���� ���� �ִ��� ã�� �żҵ�
	bool backward_word(char* str); // �������ܾ��� ���������ڿ� �Է´ܾ��� ù���� ���ڿ� �̾������� Ȯ���ϴ� �żҵ�
};