#pragma once
#include "Node.h"
#include "Discard_tray.h"

class player {
private:
	node* pHead;
	node* pTail;
public:
	player();
	~player();

	node* getHead();
	node* getTail();

	void setHead(node* pTemp);
	void setTail(node* pTemp);

	void print_check();
	void print();
	void delete_card();
	int sum();
};