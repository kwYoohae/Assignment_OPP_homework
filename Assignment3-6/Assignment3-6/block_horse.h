#pragma once
#include <iostream>

class horse;

class block {
private:
	block* pNext;
	block* pPrev;
	block* pShortCut;
	horse* pOn;
public:
	block() {
		pNext = nullptr;
		pPrev = nullptr;
		pShortCut = nullptr;
		pOn = nullptr;
	}
	~block() {

	}

	block* getNext() {
		return pNext;
	}
	block* getPrev() {
		return pPrev;
	}
	block* getShortcut() {
		return pShortCut;
	}
	horse* getOn() {
		return pOn;
	}

	void setNext(block* pTemp) {
		pNext = pTemp;
	}
	void setPrev(block* pTemp) {
		pPrev = pTemp;
	}
	void setShortcut(block* pTemp) {
		pShortCut = pTemp;
	}
	void setOn(horse* pTemp) {
		pOn = pTemp;
	}
};

class horse {
private:
	horse* pNext;
	horse* pCarry;
	block* pPos;
	bool start;
	bool short_cut1;
	bool short_cut2;
	char name[5];
	bool now_carry;
public:
	horse() {
		pNext = nullptr;
		pCarry = nullptr;
		pPos = nullptr;
		start = false;
		short_cut1 = false;
		short_cut2 = false;
		memset(name, NULL, 5);
		now_carry = false;
	}

	int getNow_carry() {
		return now_carry;
	}
	bool getStart() {
		return start;
	}
	horse* getNext() {
		return pNext;
	}
	horse* getCarry() {
		return pCarry;
	}
	block* getPos() {
		return pPos;
	}
	char* getName() {
		return name;
	}
	bool getShortCut1() {
		return short_cut1;
	}
	bool getShortCut2() {
		return short_cut2;
	}

	void setName(char* temp) {
		strcpy_s(name, temp);
	}
	void setNext(horse* pTemp) {
		pNext = pTemp;
	}
	void setCarry(horse* pTemp) {
		pCarry = pTemp;
	}
	void setPos(block* pTemp) {
		pPos = pTemp;
	}
	void setStart(bool temp) {
		start = temp;
	}
	void setShrotCut1(bool temp) {
		short_cut1 = temp;
	}
	void setShrotCut2(bool temp) {
		short_cut2 = temp;
	}
	void setNow_carry(int temp) {
		now_carry = temp;
	}

	void insert_carry(horse* pTemp) {
		if (!pCarry) {
			pTemp->setNow_carry(true);
			this->setCarry(pTemp);
		}
	}
};