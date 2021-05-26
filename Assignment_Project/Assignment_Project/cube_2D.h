#pragma once
#include "cube_1D.h"

class cube_2D
{
private:
	cube_1D* pHead;
	cube_1D* pTail;
	cube_2D* pNext;
	cube_2D* pPrev;
	cube_2D* pRow;
	cube_2D* pColumn;
	char name[100];
public:
	cube_2D();
	~cube_2D();

	cube_1D* getHead();
	cube_1D* getTail();
	cube_2D* getNext();
	cube_2D* getPrev();
	cube_2D* getRow();
	cube_2D* getColumn();
	char* getName();

	void setRow(cube_2D* pTemp);
	void setColumn(cube_2D* pTemp);

	void setPrev(cube_2D* pTemp);
	void setNext(cube_2D* pTemp);
	void setHead(cube_1D* pTemp);
	void setTail(cube_1D* pTemp);
	void setName(char* pTemp);
	void make_cube();
	void delete_cube();
};

