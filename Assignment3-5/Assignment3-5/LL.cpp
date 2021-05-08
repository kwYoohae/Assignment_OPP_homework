#include "LL.h"
#include <cstdlib>
#include <ctime>
#include <crtdbg.h>
#include <iostream>

LL::LL() {
	srand(time(NULL));
	int rand_number = rand() % 6;
	Node* pNew;
	Node* pTail = nullptr;
	for (int i = 0; i < 6; i++) {
		pNew = new Node;
		if (i == rand_number) {
			if (i == 0) {
				pNew->setData(1);
				pHead = pNew;
				pTail = pNew;
			}
			else {
				pNew->setData(1);
				pTail->setNext(pNew);
				pNew->setPrev(pNew);
				pTail = pNew;
			}
		}
		else {
			if (i == 0) {
				pHead = pNew;
				pTail = pNew;
			}
			else {
				pTail->setNext(pNew);
				pNew->setPrev(pNew);
				pTail = pNew;
			}
		}
	}
	pTail->setNext(pHead);
	pHead->setPrev(pTail);
}

LL::~LL() {
	Node* pTemp = pHead->getNext();
	pHead->setNext(nullptr);
	while (pTemp) {
		pHead = pTemp->getNext();
		delete pTemp;
		pTemp = pHead;
	}
	
	/*while (true) {
		if (pTemp == pHead) {
			delete pTemp;
			break;
		}
		pHead->setNext(pTemp->getNext());
		delete pTemp;
		pTemp = pHead->getNext();
	}*/
	_CrtDumpMemoryLeaks();
}

void LL::setHead(Node* pTemp) {
	pHead = pTemp;
}

Node* LL::getHead() {
	return pHead;
}

int LL::shoot() {
	bool is_bullet = pHead->getData();
	Node* pTemp = pHead;
	if (pTemp->getShot()) {
		while (pTemp->getShot())
			pTemp = pTemp->getNext();
	}
	pTemp->setShot(true);
	pHead = pHead->getNext();
	return is_bullet;
}

void LL::rotate() {
	srand(time(NULL));
	int number = rand() % 6;
	for (int i = 0; i <= number; i++) {
		pHead = pHead->getNext();
	}
}
