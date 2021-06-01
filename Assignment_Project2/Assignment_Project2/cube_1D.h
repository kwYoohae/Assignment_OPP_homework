#pragma once
#include "node.h"

class cube_1D
{
private:
	node* pHead;
	node* pTail;
	cube_1D* pNext;
	cube_1D* pPrev;
	char name[100];
public:
	cube_1D();
	~cube_1D();

	node* getHead();
	node* getTail();
	char* getName();
	cube_1D* getNext();
	cube_1D* getPrev();

	void setHead(node* pTemp);
	void setTail(node* pTemp);
	void setName(char* pTemp);
	void setNext(cube_1D* pTemp);
	void setPrev(cube_1D* pTemp);
};

