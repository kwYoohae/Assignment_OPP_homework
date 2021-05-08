#pragma once
#include "Node.h"

class discard {
private:
	node* pHead;
	node* pTail;
public:
	discard();
	~discard();

	node* getHead();
	node* getTail();
	void setHead(node* pTemp);
	void setTail(node* pTemp);

	void print();
	void insert(node* pTemp);
	void delete_card();
};