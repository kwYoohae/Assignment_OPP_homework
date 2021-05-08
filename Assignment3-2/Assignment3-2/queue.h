#pragma once
#include <iostream>
#include "node.h"
#include "BST.h"


class queue {
private:
	int data; //������ ���� ����
	node* pHead; //head��
	node* pTail; // tail��
public:
	queue(); //������
	~queue(); //�Ҹ���
	void Print_Queue(); // Queue���� ����ϴ� �żҵ�
	void Enqueue(int number,int *count); // ť�� �����ϴ� �żҵ�
	void Dequeue(int number, int *count, bst *Bst); // ť�� �����ϰ� BST�� �ִ� �żҵ�
	void All_Dequeue(int *count, bst *Bst); // ��� ť�� �����ϴ� �żҵ� (��� ���� BST�� �ִ� �żҵ�)
};