#pragma once
#include "cube_2D.h"
class cube
{
private:
	cube_2D* pHead;
	cube_2D* pTail;
	char name[100];
public:
	cube();
	~cube();

	cube_2D* getHead();
	cube_2D* getTail();
	char* getName();

	void setHead(cube_2D* pTemp);
	void setTail(cube_2D* pTemp);
	void setName(char* pTemp);

	void make_raw(tree* Tree);
	void delete_cube_all();
};

