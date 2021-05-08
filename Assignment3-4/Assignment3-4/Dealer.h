#pragma once
#include "Node.h"
#include "Discard_tray.h"

class Dealer {
private:
	node* pHead;
	node* pTail;
public:
	Dealer();
	~Dealer();

	node* getHead();
	node* getTail();

	void setHead(node* pTemp);
	void setTail(node* pTemp);

	void print(bool end);
	void print_check();
	void delete_card();
	int sum();
};