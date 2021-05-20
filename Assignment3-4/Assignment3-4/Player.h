#pragma once
#include "Node.h"
#include "Discard_tray.h"

class player {
private:
	node* pHead;
	node* pTail;
public:
	player(); // ������
	~player(); // �Ҹ���

	node* getHead(); // ���� ��ȯ�ϴ� �żҵ�
	node* getTail(); // ���� ��ȯ�ϴ� �żҵ�

	void setHead(node* pTemp); // ���� �����ϴ� �żҵ�
	void setTail(node* pTemp); // ���� �����ϴ� �żҵ�

	void print_check(); 
	void print(); // player�� ī�带 ����ϴ� �żҵ�
	void delete_card(); // player�� ī�带 �����ϴ� �żҵ�
	int sum(); // player�� �������ִ� ī���� ���� ���ϴ� �żҵ�
};