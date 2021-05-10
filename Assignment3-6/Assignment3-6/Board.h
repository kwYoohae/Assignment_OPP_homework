#pragma once

#include "Board_Node.h"

class Board {
private:
	Board_Node* pHead;

public:

	Board() {
		pHead = nullptr;
		make_board();
	}

	Board_Node* getHead() {
		return pHead;
	}

	void setHead(Board_Node* pTemp) {
		pHead = pTemp;
	}

	void make_board() {
		Board_Node* pTail;
		int count = 1;
		for (int i = 0; i < 5; i++) {
			Board_Node* pNew = new Board_Node;
			if (i == 0) {
				pNew->setPos(count);
				pHead = pNew;
				pTail = pNew;
				pNew->setFinsh(true);
			}
			else {
				pNew->setPos(count);
				pTail->setNext(pNew);
				pTail = pNew;
			}
		}
		for (int i = 0; i < 5; i++) {
			Board_Node* pNew = new Board_Node;
			pNew->setPos(count);
			if (i == 0) {
				pNew->setRight_up(true);
			}
			pTail->setNext(pNew);
			pTail = pNew;
		}
		for (int i = 0; i < 5; i++) {
			Board_Node* pNew = new Board_Node;
			pNew->setPos(count);
			if (i == 0) {
				pNew->setLeft_up(true);
			}
			pTail->setNext(pNew);
			pTail = pNew;
		}
		for (int i = 0; i < 5; i++) {
			Board_Node* pNew = new Board_Node;
			pNew->setPos(count);
			if (i == 0) {
				pNew->setLeft_down(true);
			}
			pTail->setNext(pNew);
			pTail = pNew;
		}
		for (int i = 0; i < 5; i++) {
			Board_Node* pNew = new Board_Node;
			pNew->setPos(count);
			if (i == 2) {
				pNew->setCenter(true);
			}
			pTail->setNext(pNew);
			pTail = pNew;
		}
	}
}
