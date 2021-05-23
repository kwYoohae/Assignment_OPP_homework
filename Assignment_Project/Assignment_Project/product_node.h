#pragma once
#include "Node.h"
class product_node {
private:
	char data[100];
	product_node* pUp;
	product_node* pDown;
	Node* pHead;
	Node* pTail;
public:
	product_node();
	~product_node();

	product_node* getUp();
	product_node* getDown();
	char* getData();
	Node* getHead();
	Node* getTail();

	void setUp(product_node* pTemp);
	void setDown(product_node* pTemp);
	void setData(char* pTemp);
	void setHead(Node* pTemp);
	void setTail(Node* pTemp);
};
