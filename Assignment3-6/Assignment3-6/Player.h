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
				if (!pTemp->getNow_carry()) {
					std::cout << count << ". " << "Hand";
					std::cout.width(4);
				}
			}
			else {
				if (!pTemp->getNow_carry()) {
					std::cout << count << ". " << pTemp->getName();
					std::cout.width(4);
				}
			}
			pTemp = pTemp->getNext();
			count++;
		}
		std::cout << '\n';
	}

	int is_exisist(block* pBoard, horse* pHorse, block* short_center1, block* short_center2) {
		if (short_center1 == pBoard || short_center2 == pBoard) {
			if (!short_center1->getOn() && !short_center2->getOn())
				return 0;
			else {
				if (short_center2->getOn()) {
					if (short_center2->getOn()->getName()[0] != pHorse->getName()[0]) {
						return 3;
					}
					else
						return 5;
				}
				else {
					if (short_center1->getOn()->getName()[0] != pHorse->getName()[0]) {
						return 4;
					}
					else
						return 6;
				}
			}
		}
		else {
			if (!pBoard->getOn()) {
				return 0;
			}
			else if (pBoard->getOn()) {
				if (pBoard->getOn()->getName()[0] != pHorse->getName()[0]) {
					return 2;
				}
				else
					return 1;
			}
		}
	}

	void caught_horse(block* pTemp, horse* pHorse) {
		horse* temp_horse = pTemp->getOn();
		horse* carry = temp_horse->getCarry();
		while (temp_horse) {
			temp_horse->setStart(false);
			temp_horse->setShrotCut1(false);
			temp_horse->setShrotCut2(false);
			temp_horse->setPos(nullptr);
			temp_horse->setNow_carry(false);
			temp_horse->setCarry(nullptr);
			temp_horse = carry;
			if (!carry)
				break;
			carry = carry->getCarry();
		}
		if (pHorse->getPos()) {
			pHorse->getPos()->setOn(nullptr);
		}
		pHorse->setPos(pTemp);
		pTemp->setOn(pHorse);
	}

	void run_horse(block* pBlock, horse* pHorse) {
		if (!pHorse->getPos()) {
			pHorse->setPos(pBlock);
			pBlock->setOn(pHorse);
		}
		else {
			pHorse->getPos()->setOn(nullptr);
			pHorse->setPos(pBlock);
			pBlock->setOn(pHorse);
		}
		pHorse->setStart(true);
	}

	void finished_horse(block* pBlock, horse* pHorse) {
		horse* carry = pHorse->getCarry();
		std::cout << "Finishted the horse";
		while (pHorse) {
			pHorse->getPos()->setOn(nullptr);
			pHorse->setPos(nullptr);
			std::cout << " " << pHorse->getName();
			horse_delete(pHorse);
			pHorse = carry;
			if (!carry)
				break;
			carry = carry->getCarry();
		}
		std::cout << "!" << '\n';

	}

	int move_horse(int move_number, int select_number, yut* Yut, board* Board, board* Board_short1, board* Board_short2) {
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
			if (run == -1 && is_hand() == true && Yut->getHead()->getNext() == nullptr) {
				Yut->delete_yut(move_number);
				return -2;
			}
			if (!horse_temp->getPos()) { // 만약 말이 진출하지 않아서 비어있을 때는
				block* pTemp = Board->getHead();
				for (int i = 0; i < run; i++) {
					pTemp = pTemp->getNext();
				}
				return_number = is_exisist(pTemp, horse_temp, Board_short1->getCenter(), Board_short2->getCenter());
				if (return_number == 2 || return_number == 3 || return_number == 4) {
					if (return_number == 3)
						pTemp = Board_short2->getCenter();
					else if (return_number == 4)
						pTemp = Board_short1->getCenter();
					caught_horse(pTemp, horse_temp);
					if (run == 4 || run == 5) {
						Yut->delete_yut(move_number);
						return 7;
					}
				}
				else if (return_number == 1 || return_number == 5 || return_number == 6) {
					if (return_number == 5)
						pTemp = Board_short2->getCenter();
					else if (return_number == 6)
						pTemp = Board_short1->getCenter();
					horse_temp->insert_carry(pTemp->getOn());
					run_horse(pTemp, horse_temp);
				}
				else {
					horse_temp->setPos(pTemp); // 말을 이동위치로 이동한다.
					horse_temp->getPos()->setOn(horse_temp);
					horse_temp->setStart(true);
				}
				Yut->delete_yut(move_number);
			}
			else if (run == -1) { // 빽도일 때는
				block* pTemp = horse_temp->getPos()->getPrev();
				if (horse_temp->getPos() != Board->getHead()) {
					return_number = is_exisist(horse_temp->getPos()->getPrev(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter());
				}
				else {
					if (Board_short2->getCenter()->getShortcut() == horse_temp->getPos()) {
						if (horse_temp->getShortCut1()) {
							return_number = is_exisist(Board_short2->getCenter()->getPrev(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter());
							pTemp = Board_short2->getCenter()->getPrev();
						}
						else {
							return_number = is_exisist(horse_temp->getPos()->getPrev(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter());
							pTemp = horse_temp->getPos()->getPrev();
						}
					}
					else if (Board->getHead() == horse_temp->getPos()) {
						block* pTemp = horse_temp->getPos();
						if (horse_temp->getShortCut1() || horse_temp->getShortCut2()) {
							return_number = is_exisist(Board_short2->getTail(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter());
							horse_temp->setPos(Board_short2->getTail());
						}
						else {
							return_number = is_exisist(Board->getHead()->getPrev(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter());
							horse_temp->setPos(horse_temp->getPos()->getPrev()); // 말의 위치를 뒤로 지정해준다.
						}
						pTemp->setOn(nullptr);
						horse_temp->getPos()->setOn(horse_temp); //board에 말이 있다고 알려줌
					}
				}
				if (return_number == 2 || return_number == 3 || return_number == 4) {
					if (return_number == 3)
						pTemp = Board_short2->getCenter();
					else if (return_number == 4)
						pTemp = Board_short1->getCenter();
					caught_horse(pTemp, horse_temp);
					if (run == 5 || run == 4) {
						Yut->delete_yut(move_number);
						return 7;
					}
				}
				else if (return_number == 1 || return_number == 5 || return_number == 6) {
					if (return_number == 5)
						pTemp = Board_short2->getCenter();
					else if (return_number == 6)
						pTemp = Board_short1->getCenter();
					horse_temp->insert_carry(pTemp->getOn());
					run_horse(pTemp, horse_temp);

				}
				else {
					run_horse(pTemp, horse_temp);
				}
				Yut->delete_yut(move_number); // 이동횟수를 썼기 때문에 삭제
				return return_number;
			}
			else {
				block* pRun_horse = horse_temp->getPos();
				if (!pRun_horse->getShortcut()) {
					for (int i = 0; i < run; i++) {
						if (pRun_horse == Board->getHead() && horse_temp->getStart() == true) {
							finished_horse(pRun_horse, horse_temp);
							if (!pHead)
								Yut->yut_delete_all();
							else
								Yut->delete_yut(move_number);
							return 0;
						}
						pRun_horse = pRun_horse->getNext();
					}
					return_number = is_exisist(pRun_horse, horse_temp, Board_short1->getCenter(), Board_short2->getCenter());
				}
				else {
					if (pRun_horse == Board_short1->getHead()->getPrev()) {
						horse_temp->setShrotCut1(true);
					}
					else if (pRun_horse == Board_short2->getHead()->getPrev()) {
						horse_temp->setShrotCut2(true);
					}
					for (int i = 0; i < run; i++) {
						if (pRun_horse == Board->getHead() && horse_temp->getStart() == true) {
							finished_horse(pRun_horse, horse_temp);
							if (!pHead)
								Yut->yut_delete_all();
							else
								Yut->delete_yut(move_number);
							return 0;
						}
						if (i == 0)
							pRun_horse = pRun_horse->getShortcut();
						else
							pRun_horse = pRun_horse->getNext();
					}
					return_number = is_exisist(pRun_horse, horse_temp, Board_short1->getCenter(), Board_short2->getCenter());
				}
				if (return_number == 0) {
					run_horse(pRun_horse, horse_temp);
				}
				else if (return_number == 2 || return_number == 3 || return_number == 4) {
					if (return_number == 3)
						pRun_horse = Board_short2->getCenter();
					else if (return_number == 4)
						pRun_horse = Board_short1->getCenter();
					caught_horse(pRun_horse, horse_temp);
					if (run == 5 || run == 4) {
						Yut->delete_yut(move_number);
						return 7;
					}
				}
				else {
					if (return_number == 5) {
						pRun_horse = Board_short2->getCenter();
					}
					else if (return_number == 6)
						pRun_horse = Board_short1->getCenter();
					horse_temp->insert_carry(pRun_horse->getOn());
					run_horse(pRun_horse, horse_temp);
				}
				Yut->delete_yut(move_number);
			}
		}
		return return_number;
	}

	void horse_delete(horse* pHorse) {
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

	bool is_hand() {
		horse* pTemp = pHead;
		while (pTemp) {
			if (pTemp->getPos())
				return false;
			pTemp = pTemp->getNext();
		}
		return true;
	}
};