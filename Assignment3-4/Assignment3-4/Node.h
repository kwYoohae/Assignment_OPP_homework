#pragma once

class node{
private:
	char card[5];
	node* pNext;
	node* pPrev;
public:
	node(); //������
	~node(); //�Ҹ���
	
	node* getNext(); // ���� ��ȯ�ϴ� �żҵ�
	node* getPrev(); // ���� ��ȯ�ϴ� �żҵ�
	char* getCard(); // ���� ��ȯ�ϴ� �żҵ�

	void setPrev(node* pTemp); // ���� �����ϴ� �żҵ�
	void setNext(node* pTemp); // ���� �����ϴ� �żҵ�
	void setCard(char* data); // ���� �����ϴ� �żҵ�
};