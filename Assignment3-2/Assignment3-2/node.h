#pragma once
#include <iostream>

class node
{
public:
	node(); // ������
	~node(); // �Ҹ���
	int getData(); // ������ �� ��ȯ
	node* getPrev(); // ������ ���� ���
	node* getNext(); // ������ ���� ���
	void setData(int number); // ������ �� ���� �żҵ�
	void setPrev(node* pNode); // ������ ���� �żҵ�
	void setNext(node* pNode); // ������ ���� �żҵ�
private: 
	int data; //������ ���� ����
	node* pPrev; // �������� �˷��ִ� ���
	node* pNext; // �������� �˷��ִ� ���
};
