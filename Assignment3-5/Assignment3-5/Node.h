#pragma once

class Node {
private:
	int data;
	Node* pNext;
	Node* pPrev;
public:
	Node();//������
	~Node(); // �Ҹ���
	
	int getData(); // ���� ��ȯ�ϴ� �żҵ�
	Node* getNext(); // ���� ��ȯ�ϴ� �żҵ�
	Node* getPrev(); // ���� ��ȯ�ϴ� �żҵ�

	void setData(int _Data); // ���� �����ϴ� �żҵ�
	void setNext(Node* pTemp); // ���� �����ϴ� �żҵ�
	void setPrev(Node* pTemp); // ���� �����ϴ� �żҵ�
};