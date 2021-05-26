#pragma once
#include "Node.h"
#include "tree.h"

class cube_1D
{
private:
	Node* pHead;
	Node* pTail;
	cube_1D* pNext;
	cube_1D* pPrev;
	char name[100];
public:
	cube_1D();
	~cube_1D();

	Node* getHead();
	Node* getTail();
	char* getName();
	cube_1D* getNext();
	cube_1D* getPrev();

	void setNext(cube_1D* pTemp);
	void setPrev(cube_1D* pTemp);
	void setTail(Node* pTemp);
	void setHead(Node* pTemp);
	void setName(char* pTemp);

	void make_raw(tree* Tree);
	void delete_node();
};

