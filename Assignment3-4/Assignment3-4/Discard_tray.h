#pragma once
#include "Node.h"

class discard {
private:
	node* pHead;
	node* pTail;
public:
	discard(); // ������
	~discard(); // �Ҹ���

	node* getHead(); // ���� ��ȯ�ϴ� �żҵ�
	node* getTail(); // ���� ��ȯ�ϴ� �żҵ�
	void setHead(node* pTemp); // ���� �����ϴ� �żҵ�
	void setTail(node* pTemp); // ���� �����ϴ� �żҵ�

	void print(); 
	void insert(node* pTemp); // ī�带 �ִ� �żҵ�
	void delete_card(); // ��� ī�带 �����ϴ� �żҵ�
};