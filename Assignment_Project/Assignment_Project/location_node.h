#pragma once
#include "Node.h"
class location_node {
private:
	char data[100];
	location_node* pUp;
	location_node* pDown;
	Node* pHead;
	Node* pTail;
public:
	location_node();
	~location_node();

	location_node* getUp();
	location_node* getDown();
	char* getData();
	Node* getHead();
	Node* getTail();

	void setUp(location_node* pTemp);
	void setDown(location_node* pTemp);
	void setData(char* pTemp);
	void setHead(Node* pTemp);
	void setTail(Node* pTemp);
};