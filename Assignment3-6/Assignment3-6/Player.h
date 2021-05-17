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

	int is_exisist(block* pBoard , horse* pHorse) {
		if (!pBoard->getOn()) {
			return 0;
		}
		else if (pBoard->getOn()) {
			if (pBoard->getOn()->getName()[0] != pHorse->getName()[0]) {
				return 2;
			}
			else
				return 0;
		}
	}

	int move_horse(int move_number, int select_number, yut* Yut, board *Board) {
		if (!pHead) {
			Yut->yut_delete_all();
			return 0;
		}
		int return_number = 0;
		moving* yut_temp = Yut->getHead(); // 윳을 던진 값의 haed값을 불러옴
		horse* horse_temp = pHead; // 말의 haed값을 불러옴
		for (int i = 1; i < move_number; i++) {
			yut_temp = yut_temp->getNext(); // 내가 선택한 윷을 던진 값까지 감
		}
		for (int i = 1; i < select_number; i++) {
			horse_temp = horse_temp->getNext(); // 내가 선택한 말의 값까지 감
		}
		if (!yut_temp || !horse_temp) {
			return -1; // 매소드 반환하여 종료
		}
		else {
			int run = yut_temp->getStep(); // yut이 저장하고 있던 step값을 불러온다.
			if(!horse_temp->getPos()) // 만약 말이 진출하지 않아서 비어있을 때는
				horse_temp->setPos(Board->getHead()); // 말을 시작점으로 이동하고 시작한다.
			if (run == -1) { // 빽도일 때는 
				if (horse_temp->getPos() != Board->getHead() && horse_temp->getStart() == true) {
					block* pTemp = horse_temp->getPos();
					return_number = is_exisist(horse_temp->getPos()->getPrev(), horse_temp);
					horse_temp->setPos(horse_temp->getPos()->getPrev()); // 말의 위치를 뒤로 지정해준다.
					pTemp->setOn(nullptr);
					horse_temp->getPos()->setOn(horse_temp); //board에 말이 있다고 알려줌
				}
				else {

				}
				Yut->delete_yut(move_number); // 이동횟수를 썼기 때문에 삭제
			}
			else {
				block* pRun_horse = horse_temp->getPos();
				if (!pRun_horse->getShortcut()) {
					for (int i = 0; i < run; i++) {
						if (pRun_horse == Board->getHead() && horse_temp->getStart() == true) {
							horse_temp->getPos()->setOn(nullptr);
							horse_temp->setPos(nullptr);
							std::cout << "Finished the horse " << horse_temp->getName() << "!" << '\n';
							horse_delete(horse_temp);
							Yut->delete_yut(move_number);
							return 0;
						}
						pRun_horse = pRun_horse->getNext();
					}
				}
				else {
					for (int i = 0; i < run; i++) {
						if (pRun_horse == Board->getHead() && horse_temp->getStart() == true) {
							horse_temp->getPos()->setOn(nullptr);
							horse_temp->setPos(nullptr);
							std::cout << "Finished the horse " << horse_temp->getName() << "!" << '\n';
							horse_delete(horse_temp);
							Yut->delete_yut(move_number);
							return 0;
						}
						if (i == 0)
							pRun_horse = pRun_horse->getShortcut();
						else
							pRun_horse = pRun_horse->getNext();
					}
				}
			return_number = is_exisist(pRun_horse, horse_temp);
			if (return_number == 0) {
				horse_temp->getPos()->setOn(nullptr);
				horse_temp->setPos(pRun_horse);
				pRun_horse->setOn(horse_temp);
				Yut->delete_yut(move_number);
				horse_temp->setStart(true);
			}
			else if (return_number == 2) {
				pRun_horse->getOn()->setStart(false);
				pRun_horse->getOn()->setPos(nullptr);
				horse_temp->getPos()->setOn(nullptr);
				horse_temp->setPos(pRun_horse);
				pRun_horse->setOn(horse_temp);
				Yut->delete_yut(move_number);
			}
				return return_number;
			}
		}
		return 0;
	}

	void horse_delete(horse *pHorse) {
		horse* pTemp = pHead;
		horse* pPrev = pTemp;
		horse* pCarry = pHorse->getCarry();
		while (pTemp) {
			if (pTemp == pHorse)
				break;
			pPrev = pTemp;
			pTemp = pTemp->getNext();
		}
		if (pTemp == pHead) {
			if (pHead->getNext() == nullptr) {
				delete pTemp;
				pHead = nullptr;
				pTail = nullptr;
			}
			else {
				pHead = pHead->getNext();
				delete pTemp;
			}
		}
		else if (pTemp == pTail) {
			pPrev->setNext(nullptr);
			delete pTemp;
		}
		else {
			pPrev->setNext(pTemp->getNext());
			delete pTemp;
		}
	}
};