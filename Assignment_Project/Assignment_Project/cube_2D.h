#pragma once
#include "cube_1D.h"

class cube_2D
{
private:
	cube_1D* pRhead;
	cube_1D* pChead;
	cube_1D* pRtail;
	cube_1D* pCtail
	cube_2D* pNext;
	cube_2D* pPrev;
	char name[100];
public:
	cube_2D();
	~cube_2D();

	cube_1D* getRhaed();
	cube_1D* getChead();
	cube_1D* getTail();
	cube_2D* getNext();
	cube_2D* getPrev();
	char* getName();

	void setRhaed(cube_1D* pTemp);
	void setPrev(cube_2D* pTemp);
	void setNext(cube_2D* pTemp);
	void setChead(cube_1D* pTemp);
	void setTail(cube_1D* pTemp);
	void setName(char* pTemp);
	void make_cube();
};

