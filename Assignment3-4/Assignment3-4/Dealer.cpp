#include "Dealer.h"
#include <iostream>

Dealer::Dealer() { //������
	pHead = nullptr;
	pTail = nullptr;
}

Dealer::~Dealer() { // �Ҹ���

}

void Dealer::setHead(node* pTemp) { //���� �����ϴ� �żҵ�
	pHead = pTemp;
}

void Dealer::setTail(node* pTemp) {//���� �����ϴ� �żҵ�
	pTail = pTemp;
}

node* Dealer::getHead() {//���� ��ȯ���ִ� �żҵ�
	return pHead;
}

node* Dealer::getTail() {//���� ��ȯ���ִ� �żҵ�
	return pTail;
}

void Dealer::print_check() {
	int count = 0;
	node* pTemp = pHead;
	while (pTemp) {
		std::cout << pTemp->getCard() << '\n';
		pTemp = pTemp->getNext();
		count++;
	}
	std::cout << "count : " << count << '\n';
}

void Dealer::delete_card() { // ������ ī�带 �����ϴ� �żҵ�
	node* pTemp;
	while (pHead) { // pHead�� null�϶����� �ݺ�
		pTemp = pHead; // pTemp�� pHead�� ����Ŵ
		pHead = pHead->getNext(); // ���������� pHead�� 
		delete pTemp; // pTmep�� ����
	}
	pHead = nullptr; //�ٻ����� �� �ʱ�ȭ
	pTail = nullptr; // �ٻ����� �� �ʱ�ȭ
}

void Dealer::print(bool end) { // ������ ī�带 ���
	node* pTemp = pHead;
	if (end) { //������ ������ ����� ī�带 ����ؾߵǴ��� Ȯ��
		std::cout << "Dealer Cards :";
		std::cout.width(5);
		while (pTemp) {
			std::cout << pTemp->getCard(); //ī�带 ���
			std::cout.width(5);
			pTemp = pTemp->getNext(); // pTemp�� ����������
		}
	}
	else { // �������̶� ������ ī�带 �̰����� �ҋ�
		std::cout << "Dealer Cards :";
		std::cout.width(5);
		while (pTemp) {
			if (pTemp == pHead) { // ���� ó�� ī��� ?�� ���
				std::cout << "?";
				std::cout.width(5);
				pTemp = pTemp->getNext();
			} 
			else { // ������ī��� �׳� ���
				std::cout << pTemp->getCard();
				std::cout.width(5);
				pTemp = pTemp->getNext();
			}
		}
	}
	std::cout << '\n';
}
 
int Dealer::sum() { // ����ī���� ���� ������ �� 
	int res = 0; // ���� �޴� ����
	int number_A = 0; // Aī���� ���ڸ� ���� ����
	node* pTemp = pHead;
	while (pTemp) {
		if (pTemp->getCard()[1] == '1' && pTemp->getCard()[2] == '0') // 10ī���� �� 10�� �־���
			res += 10; 
		else if (pTemp->getCard()[1] == 'K' || pTemp->getCard()[1] == 'J' || pTemp->getCard()[1] == 'Q') // k,j,q�� 10�� ������
			res += 10;
		else if (pTemp->getCard()[1] == 'A') // Aī��� ������ ��� ���߿� ���
			number_A++;
		else { // �������� ī�忡 ��� ���ڸ�ŭ ������
			res += pTemp->getCard()[1] - '0';
		}
		pTemp = pTemp->getNext();
	}
	for (int i = 0; i < number_A; i++) { // Aī���� ������ŭ ������
		if (res + 11 <= 21) // ���� �տ� 11�� ���ص� ���� 21�� �ȳ��� ���� 11�� ������
			res += 11;
		else // 21�̳��� ���� 1�� ���
			res += 1;
	}
	return res; // ī���� ���� ��ȯ
}