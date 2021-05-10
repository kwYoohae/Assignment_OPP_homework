#include "Discard_tray.h"
#include <iostream>

discard::discard() {
	pHead = nullptr;
	pTail = nullptr;
}

discard::~discard() {

}

void discard::setHead(node* pTemp) {
	pHead = pTemp;
}

void discard::setTail(node* pTemp) {
	pTail = pTemp;
}

node* discard::getHead() {
	return pHead;
}

node* discard::getTail() {
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

void discard::delete_card() {
	node* pTemp;
	while (pHead) {
		pTemp = pHead;
		pHead = pHead->getNext();
		delete pTemp;
	}
	pHead = nullptr;
	pTail = nullptr;
}

void discard::insert(node* pTemp) {
	node* pNew = new node;
	if (pHead == nullptr) {
		pHead = pNew;
		pTail = pNew;
		pNew->setCard(pTemp->getCard());
	}
	else {
		pNew->setCard(pTemp->getCard());
		pTail->setNext(pNew);
		pTail = pNew;
	}
}
