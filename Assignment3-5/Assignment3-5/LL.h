#pragma once
#include "Node.h"

class LL
{
public:
	LL();
	~LL();

	Node* getHead();
	void setHead(Node* pTemp);

	int shoot();
	void rotate();
	void print();

private:
	Node* pHead;
};

