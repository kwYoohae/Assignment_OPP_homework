#pragma once
#include "Node.h"
class time_node {
private:
	char data[100];
	time_node* pUp;
	time_node* pDown;
	Node* pHead;
	Node* pTail;
	time_node* pRight;
	time_node* pLeft;
public:
	time_node();
	~time_node();
	
	time_node* getUp();
	time_node* getDown();
	char* getData();
	Node* getHead();
	Node* getTail();
	time_node* getRight();
	time_node* getLeft();

	void setUp(time_node* pTemp);
	void setDown(time_node* pTemp);
	void setData(char* pTemp);
	void setHead(Node* pTemp);
	void setTail(Node* pTemp);
	void setRight(time_node* pTemp);
	void setLeft(time_node* pTemp);
};