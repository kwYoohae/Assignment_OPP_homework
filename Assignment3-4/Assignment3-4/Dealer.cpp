#include "Dealer.h"
#include <iostream>

Dealer::Dealer() {
	pHead = nullptr;
	pTail = nullptr;
}

Dealer::~Dealer() {

}

void Dealer::setHead(node* pTemp) {
	pHead = pTemp;
}

void Dealer::setTail(node* pTemp) {
	pTail = pTemp;
}

node* Dealer::getHead() {
	return pHead;
}

node* Dealer::getTail() {
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

void Dealer::delete_card() {
	node* pTemp;
	while (pHead) {
		pTemp = pHead;
		pHead = pHead->getNext();
		delete pTemp;
	}
	pHead = nullptr;
	pTail = nullptr;
}

void Dealer::print(bool end) {
	node* pTemp = pHead;
	if (end) {
		std::cout << "Dealer Cards :";
		std::cout.width(5);
		while (pTemp) {
			std::cout << pTemp->getCard();
			std::cout.width(5);
			pTemp = pTemp->getNext();
		}
	}
	else {
		std::cout << "Dealer Cards :";
		std::cout.width(5);
		while (pTemp) {
			if (pTemp == pHead) {
				std::cout << "?";
				std::cout.width(5);
				pTemp = pTemp->getNext();
			}
			else {
				std::cout << pTemp->getCard();
				std::cout.width(5);
				pTemp = pTemp->getNext();
			}
		}
	}
	std::cout << '\n';
}

int Dealer::sum() {
	int res = 0;
	int number_A = 0;
	node* pTemp = pHead;
	while (pTemp) {
		if (pTemp->getCard()[1] == '1' && pTemp->getCard()[2] == '0')
			res += 10;
		else if (pTemp->getCard()[1] == 'K' || pTemp->getCard()[1] == 'J' || pTemp->getCard()[1] == 'Q')
			res += 10;
		else if (pTemp->getCard()[1] == 'A')
			number_A++;
		else {
			res += pTemp->getCard()[1] - '0';
		}
		pTemp = pTemp->getNext();
	}
	for (int i = 0; i < number_A; i++) {
		if (res + 11 <= 21)
			res += 11;
		else
			res += 1;
	}
	return res;
}