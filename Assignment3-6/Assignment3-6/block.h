#pragma once
#include "horse.h"

class block
{
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

	block* getNext() {
		return pNext;
	}
	block* getPrev() {
		return pPrev;
	}
	block* getShortCut() {
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
	void setShortCut(block* pTemp) {
		pShortCut = pTemp;
	}
	void setOn(horse* pTemp) {
		pOn = pTemp;
	}
};