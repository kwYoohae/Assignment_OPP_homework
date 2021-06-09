#pragma once
#include "node.h"
#include "tree_node.h"

class cube_1D
{
private:
	node* pHead;
	node* pTail;
	node* pNode;
	cube_1D* pNext;
	cube_1D* pPrev;
	tree_node* pData;
	char name[100];
	int Rev_number;
public:
	cube_1D();
	~cube_1D();

	int getRev();
	tree_node* getData();
	node* getNode();
	node* getHead();
	node* getTail();
	char* getName();
	cube_1D* getNext();
	cube_1D* getPrev();

	void setRev(int temp);
	void setNode(node* pTemp);
	void setData(tree_node* pTemp);
	void setHead(node* pTemp);
	void setTail(node* pTemp);
	void setName(char* pTemp);
	void setNext(cube_1D* pTemp);
	void setPrev(cube_1D* pTemp);

};

