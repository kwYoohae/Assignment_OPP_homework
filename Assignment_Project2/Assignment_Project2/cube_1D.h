#pragma once
#include "node.h"
#include "tree_node.h"

class cube_1D
{
private:
	cube_1D* pNext;
	cube_1D* pPrev;
	tree_node* pData;
	int Rev_number;
public:
	cube_1D();
	~cube_1D();

	int getRev();
	tree_node* getData();
	cube_1D* getNext();
	cube_1D* getPrev();

	void setRev(int temp);
	void setData(tree_node* pTemp);
	void setNext(cube_1D* pTemp);
	void setPrev(cube_1D* pTemp);

};

