#include "Player.h"
#include <iostream>

player::player() {
	pHead = nullptr;
	pTail = nullptr;
}

player::~player() {

}

void player::setHead(node* pTemp) {
	pHead = pTemp;
}

void player::setTail(node* pTemp) {
	pTail = pTemp;
}

node* player::getHead() {
	return pHead;
}

node* player::getTail() {
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

void player::delete_card() {
	node* pTemp;
	while (pHead) {
		pTemp = pHead;
		pHead = pHead->getNext();
		delete pTemp;
	}
	pHead = nullptr;
	pTail = nullptr;
}

void player::print() {
	std::cout << "Player Cards :";
	std::cout.width(5);
	node* pTemp = pHead;
	while (pTemp) {
		std::cout << pTemp->getCard();;
		std::cout.width(5);
		pTemp = pTemp->getNext();
	}
	std::cout << '\n';
}

int player::sum() {
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