#include "Node.h"
#include<iostream>

node::node() { // ������
	memset(card, NULL, 5);
	pNext = nullptr;
	pPrev = nullptr;
}

node::~node() { // �Ҹ���

}

node* node::getPrev() { // ���� ��ȯ�ϴ� �żҵ�
	return pPrev;
}

node* node::getNext() { // ���� ��ȯ�ϴ� �żҵ�
	return pNext;
}

char* node::getCard() { // ���� ��ȯ�ϴ� �żҵ�
	return card;
}


void node::setCard(char* data) { // ���� �����ϴ� �żҵ�
	strcpy_s(card, data);
}

void node::setNext(node* pTemp) { // ���� �����ϴ� �żҵ�
	pNext = pTemp;
}

void node::setPrev(node* pTemp) { // ���� �����ϴ� �żҵ�
	pPrev = pTemp;
}

