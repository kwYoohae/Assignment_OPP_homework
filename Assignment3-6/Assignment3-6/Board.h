#pragma once
#include "block.h"

class board{
private:
	block* pHead;
	block* pTail;
public:
	board() {
		for (int i = 0; i < 6; i++) {
			if (!pHead) {
				block* pNew = new block;
				pHead = pNew;
				pTail = pNew;
			}
			else {
				block* pNew = new block;
				pNew->setPrev(pTail);
				pTail->setNext(pNew);
				pTail = pNew;
				if (i == 5) {
					board* pNewB = new board;
					for (int j = 0; j < 6; j++) {
						block* pNew = new block;
						pNew->setShortCut(pNew);
						
					}
				}
			}
		}
	}

};