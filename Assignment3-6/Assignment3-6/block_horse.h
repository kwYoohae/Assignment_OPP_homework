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
	block();
	~block();

	block* getNext();
	block* getPrev();
	block* getShortcut();
	horse* getOn();

	void setNext(block* pTemp);
	void setPrev(block* pTemp);
	void setShortcut(block* pTemp);
	void setOn(horse* pTemp);
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
	horse();

	int getNow_carry();
	bool getStart();
	horse* getNext();
	horse* getCarry();
	block* getPos();
	char* getName();
	bool getShortCut1();
	bool getShortCut2();

	void setName(char* temp);
	void setNext(horse* pTemp);
	void setCarry(horse* pTemp);
	void setPos(block* pTemp);
	void setStart(bool temp);
	void setShrotCut1(bool temp);
	void setShrotCut2(bool temp);
	void setNow_carry(int temp);

	void insert_carry(horse* pTemp);
};