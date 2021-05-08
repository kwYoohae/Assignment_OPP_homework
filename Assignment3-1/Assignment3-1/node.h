#pragma once
#include <iostream>

using namespace std;

class node {
private:
	char data[20]; //�ܾ �����ϴ� ����
	node* pPrev; //���� ���� ����Ű�� ����
	node* pNext; //���� ���� ����Ű�� ����
public:
	node();//������
	~node();//�Ҹ���

	void setData(char* str); //privat������ ����� �� �ְ� �ϴ� �żҵ�(���� ����)
	void setNext(node* pNode);//privat������ ����� �� �ְ� �ϴ� �żҵ�(���� ����)
	void setPrev(node* pNode);//privat������ ����� �� �ְ� �ϴ� �żҵ�(���� ����)
	char* getData();//privat������ ����� �� �ְ� �ϴ� �żҵ�(���� ������return)
	node* getNext();//privat������ ����� �� �ְ� �ϴ� �żҵ�(���� ������return)
	node* getPrev();//privat������ ����� �� �ְ� �ϴ� �żҵ�(���� ������return)
};