#pragma once
#include "block_horse.h"
#include <iostream>

class board {
private:
	block* pHead;
	block* pTail;
	block* pCenter;
public:
	board();

	~board();

	block* getHead();
	block* getTail();
	block* getCenter();

	void setHead(block* pTemp);
	void setTail(block* pTemp);
	void setCenter(block* pTemp);

	void Insert();

	void Print_Check(block* pTemp);

	int Check_center(block* pTemp1, block* pTemp2);

	void Print(board* short1, board* short2);
};