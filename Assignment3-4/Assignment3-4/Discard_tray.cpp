#include "Discard_tray.h"
#include <iostream>

discard::discard() { //������
	pHead = nullptr;
	pTail = nullptr;
}

discard::~discard() { // �Ҹ���

}

void discard::setHead(node* pTemp) { // ���� �������ִ� �żҵ�
	pHead = pTemp;
}

void discard::setTail(node* pTemp) {// ���� �������ִ� �żҵ�
	pTail = pTemp;
}

node* discard::getHead() { //���� ��ȯ���ִ� �żҵ�
	return pHead;
}

node* discard::getTail() { // ���� ��ȯ���ִ� �żҵ�
	return pTail;
}

void discard::print() { 
	int count = 0;
	node* pTemp = pHead;
	while (pTemp) {
		std::cout << pTemp->getCard() << '\n';
		pTemp = pTemp->getNext();
		count++;
	}
	std::cout << "count : " << count << '\n';
}

void discard::delete_card() { // discard_tray���� ī�带 ��� �����ϴ� �żҵ�
	node* pTemp; 
	while (pHead) { // pHead���� ������ī����� �ݺ����� ��ӵ���
		pTemp = pHead;
		pHead = pHead->getNext(); // �ص��� ���������� 
		delete pTemp; // �����Ҵ�����
	}
	pHead = nullptr; // ���ī�� ������ �ص� �ʱ�ȭ
	pTail = nullptr; // ���ī�� ������ ���� �ʱ�ȭ
}

void discard::insert(node* pTemp) { // discard_tary�� ī�带 �ű� ��
	node* pNew = new node;
	if (pHead == nullptr) { // �ص尡 ������� ���� �ص�� ���ϵ� ����
		pHead = pNew;
		pTail = pNew;
		pNew->setCard(pTemp->getCard());
	}
	else { // �ص尡 ������� ���� ���� Next, Prev , Tail����
		pNew->setCard(pTemp->getCard());
		pTail->setNext(pNew);
		pTail = pNew;
	}
}
