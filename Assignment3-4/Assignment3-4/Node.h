#pragma once

class node{
private:
	char card[5];
	node* pNext;
	node* pPrev;
public:
	node();
	~node();
	
	node* getNext();
	node* getPrev();
	char* getCard();

	void setPrev(node* pTemp);
	void setNext(node* pTemp);
	void setCard(char* data);
};