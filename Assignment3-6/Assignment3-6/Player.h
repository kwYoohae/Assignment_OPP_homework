#pragma once
#include "block_horse.h"
#include "Yut.h"
#include "move.h"
class player {
private:
	horse* pHead;
	horse* pTail;
public:
	player() {
		pHead = nullptr;
		pTail = nullptr;
	}
	~player() {

	}

	horse* getHead() {
		return pHead;
	}
	horse* getTail() {
		return pTail;
	}

	void setHead(horse* pTemp) {
		pHead = pTemp;
	}
	void setTail(horse* pTemp) {
		pTail = pTemp;
	}

	void inster_name(char ch) {
		char name[5];
		memset(name, NULL, 5);
		for (int i = 0; i < 4; i++) {
			name[0] = ch;
			name[1] = '1' + i;
			horse* pNew = new horse;
			if (!pHead) {
				pHead = pNew;
				pTail = pNew;
				pNew->setName(name);
			}
			else {
				pTail->setNext(pNew);
				pTail = pNew;
				pNew->setName(name);
			}
		}
	}
	
	void print_horse() {
		int count = 1;
		horse* pTemp = pHead;
		while (pTemp) {
			if (!pTemp->getPos()) {
				std::cout << count << ". " << "Hand";
				std::cout.width(4);
			}
			else {
				std::cout << count << ". " << pTemp->getName();
				std::cout.width(4);
			}
			pTemp = pTemp->getNext();
			count++;
		}
		std::cout << '\n';
	}

	void move_horse(int move_number, int select_number, yut* Yut, board *Board) {
		moving* yut_temp = Yut->getHead();
		horse* horse_temp = pHead;
		for (int i = 0; i < select_number; i++) {
			yut_temp = yut_temp->getNext();
		}
		for (int i = 0; i < select_number; i++) {
			horse_temp = horse_temp->getNext();
		}
		if (!yut_temp || !horse_temp) {
			std::cout << "Wrong Command" << '\n';
			return;
		}
		else {
			int run = yut_temp->getStep();
			if(!horse_temp->getPos())
				horse_temp->setPos(Board->getHead());
			if (run == -1) {
				horse_temp->setPos(horse_temp->getPos()->getPrev());
			}
			else {
				for (int i = 0; i < run; i++) {
					horse_temp->setPos(horse_temp->getPos()->getNext());
				}
			}
		}
	}
};