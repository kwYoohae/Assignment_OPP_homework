#pragma once
#include "block_horse.h"
#include <iostream>

class board {
private:
	block* pHead;
	block* pTail;
	block* pCenter;
public:
	board() {
		pHead = nullptr;
		pTail = nullptr;
		pCenter = nullptr;
	}

	~board() {

	}

	block* getHead() {
		return pHead;
	}
	block* getTail() {
		return pTail;
	}
	block* getCenter() {
		return pCenter;
	}

	void setHead(block* pTemp) {
		pHead = pTemp;
	}
	void setTail(block* pTemp) {
		pTail = pTemp;
	}
	void setCenter(block* pTemp) {
		pCenter = pTemp;
	}

	void Insert() {
		if (!pHead) {
			block* pNew = new block;
			pHead = pNew;;
			pTail = pNew;
		}
		else {
			block* pNew = new block;
			pNew->setPrev(pTail);
			pTail->setNext(pNew);
			pTail = pNew;
		}
	}

	void Print_Check(block* pTemp) {
		if (!pTemp->getOn()) {
			std::cout << "o";
		}
		else {
			std::cout << pTemp->getOn()->getName();
		}
	}

	int Check_center(block* pTemp1, block* pTemp2) {
		bool temp1;
		bool temp2;
		if (!pTemp1->getOn()) {
			temp1 = false;
		}
		else {
			temp1 = true;
		}
		if (!pTemp2->getOn()) {
			temp2 = false;
		}
		else {
			temp2 = true;
		}
		if (temp1 == true && temp2 == true) {
			return 3;
		}
		else if (temp1 == true) {
			return 1;
		}
		else if (temp2 == true) {
			return 2;
		}
		else {
			return 0;
		}
	}

	void Print(board* short1, board* short2) {
		block* pTemp = short2->getHead()->getPrev();
		block* pTemp1 = short1->getHead()->getPrev()->getPrev();
		block* pShort1 = short1->getHead();
		block* pShort2 = short2->getHead();
		for (int i = 0; i < 6; i++) {
			if (i == 3)
				std::cout.width(10);
			Print_Check(pTemp);
			std::cout.width(5);
			pTemp = pTemp->getPrev();
		}
		std::cout << '\n' << '\n';
		pTemp = pShort2->getPrev()->getNext();
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 4; j++) {
				if (j == 0) {
					Print_Check(pTemp);
					pTemp = pTemp->getNext();
					if (i == 0)
						std::cout.width(5);
					else-
						std::cout.width(10);
				}
				else if (j == 1) {
					Print_Check(pShort2);
					pShort2 = pShort2->getNext();
					if (i == 0)
						std::cout.width(20);
					else
						std::cout.width(10);
				}
				else if (j == 2) {
					Print_Check(pShort1);
					pShort1 = pShort1->getNext();
					if (i == 0)
						std::cout.width(5);
					else
						std::cout.width(10);
				}
				else {
					Print_Check(pTemp1);
					pTemp1 = pTemp1->getPrev();
					
				}
			}
			std::cout << '\n' << '\n';
		}
		std::cout.width(15);
		int num = Check_center(pShort1, pShort2);
		if (num == 1)
			Print_Check(pShort1);
		else if (num == 2)
			Print_Check(pShort2);
		else {
			Print_Check(pShort1);
		}
		pShort1 = pShort1->getNext();
		pShort2 = pShort2->getNext();
		std::cout << '\n' << '\n';

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 4; j++) {
				if (j == 0) {
					Print_Check(pTemp);
					pTemp = pTemp->getNext();
					if (i == 1)
						std::cout.width(5);
					else
						std::cout.width(10);
				}
				else if (j == 1) {
					Print_Check(pShort1);
					pShort1 = pShort1->getNext();
					if (i == 1)
						std::cout.width(20);
					else
						std::cout.width(10);
				}
				else if (j == 2) {
					Print_Check(pShort2);
					pShort2 = pShort2->getNext();
					if (i == 1)
						std::cout.width(5);
					else
						std::cout.width(10);
				}
				else {
					Print_Check(pTemp1);
					pTemp1 = pTemp1->getPrev();

				}
			}
			std::cout << '\n' << '\n';
		}
		
		for (int i = 0; i < 6; i++) {
			if (i == 3)
				std::cout.width(10);
			Print_Check(pTemp);
			std::cout.width(5);
			pTemp = pTemp->getNext();
		}
		std::cout << '\n' << '\n';
	}
};