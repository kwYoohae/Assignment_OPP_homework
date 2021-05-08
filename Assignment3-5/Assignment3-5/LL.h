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

private:
	Node* pHead;
};

