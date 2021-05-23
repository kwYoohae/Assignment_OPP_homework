#pragma once
#include "Node.h"
class tree_node {
private:
	int count;
	char data[100];
	tree_node* pUp;
	tree_node* pDown;
	Node* pHead;
	Node* pTail;
	tree_node* pNext;
	tree_node* pPrev;
public:
	tree_node();
	~tree_node();
	
	tree_node* getUp();
	tree_node* getDown();
	char* getData();
	Node* getHead();
	Node* getTail();
	int getCount();
	tree_node* getNext();
	tree_node* getPrev();

	void setUp(tree_node* pTemp);
	void setDown(tree_node* pTemp);
	void setData(char* pTemp);
	void setHead(Node* pTemp);
	void setTail(Node* pTemp);
	void setCount(int temp);
	void setNew();
	void setNext(tree_node* pTemp);
	void setPrev(tree_node* pTemp);
};