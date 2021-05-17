#pragma once
#include <cstdlib>
#include <time.h>
#include <iostream>
#include "move.h"

class yut {
private:
	moving* pHead;
	moving* pTail;
public:
	yut();
	~yut();
	moving* getHead();
	moving* getTail();
	void setHead(moving* pTemp);
	void setTail(moving* pTemp);
	bool Throw_yut();
	void delete_yut(int num);
	void print_yut();
	void yut_delete_all();
};