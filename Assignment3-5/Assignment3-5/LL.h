#pragma once
#include "Node.h"

class LL
{
public:
	LL();//������
	~LL(); // �Ҹ���

	Node* getHead(); //���� ��ȯ���ִ� �żҵ�
	void setHead(Node* pTemp); // ���� �����ϴ� �żҵ�

	int shoot(); // �Ѿ��� ��� �żҵ�
	void rotate(); // �Ѿ��� ������ �żҵ�
	void print();

private:
	Node* pHead;
};

