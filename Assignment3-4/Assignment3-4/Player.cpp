#include "Player.h"
#include <iostream>

player::player() { // ������
	pHead = nullptr;
	pTail = nullptr;
}

player::~player() { //�Ҹ���

}

void player::setHead(node* pTemp) { // ���� �����ϴ� �żҵ�
	pHead = pTemp;
}

void player::setTail(node* pTemp) { // ���� �����ϴ� �żҵ�
	pTail = pTemp;
}

node* player::getHead() { // ���� ��ȯ�ϴ� �żҵ�
	return pHead;
}

node* player::getTail() { // ���� ��ȯ�ϴ� �żҵ�
	return pTail;
}

void player::print_check() {
	int count = 0;
	node* pTemp = pHead;
	while (pTemp) {
		std::cout << pTemp->getCard() << '\n';
		pTemp = pTemp->getNext();
		count++;
	}
	std::cout << "count : " << count << '\n';
}

void player::delete_card() { // ī�带 �����ϴ� �żҵ�
	node* pTemp;
	while (pHead) { // pHead���� ������ ī�����
		pTemp = pHead; 
		pHead = pHead->getNext(); //pHead�� ����̵�
		delete pTemp; // �����Ҵ�����
	}
	pHead = nullptr; // ���ī������� �ص� �ʱ�ȭ
	pTail = nullptr; // ���ī�� ������ ���� �ʱ�ȭ
}

void player::print() { // player�� ���� ī�� ���
	std::cout << "Player Cards :";
	std::cout.width(5);
	node* pTemp = pHead; 
	while (pTemp) { // pTemp�� ���� nullptr�ɶ����� �ݺ�
		std::cout << pTemp->getCard();; // ī�带 ���
		std::cout.width(5);
		pTemp = pTemp->getNext(); // ����������
	}
	std::cout << '\n';
}

int player::sum() { // player�� ī���� ���� ��ȯ�ϴ� �żҵ�
	int res = 0; // ī���� ���� �����ϴ� ����
	int number_A = 0; // Aī�带 ���� Ƚ���� ī��Ʈ�ϴ� ����
	node* pTemp = pHead;
	while (pTemp) {
		if (pTemp->getCard()[1] == '1' && pTemp->getCard()[2] == '0') // 10ī�带 �������� 10�� ������
			res += 10;
		else if (pTemp->getCard()[1] == 'K' || pTemp->getCard()[1] == 'J' || pTemp->getCard()[1] == 'Q') // j,k,q�� ���� ���� 10�� ������
			res += 10;
		else if (pTemp->getCard()[1] == 'A') // ���̽� ī�带 ���� �� ������ ������
			number_A++;
		else { // ������ ī��� ������ ���ڴ�� ������
			res += pTemp->getCard()[1] - '0'; 
		}
		pTemp = pTemp->getNext(); // ��Ӵ���ī���
	}
	for (int i = 0; i < number_A; i++) {
		if (res + 11 <= 21) // ������ 11�� ������ �� 21���� ������ 11�� ���̽��� ������
			res += 11;
		else // �ƴϸ� 1��������
			res += 1;
	}
	return res; // ī���� �� ��ȯ
}