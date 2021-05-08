#pragma once

class node{
private:
	char card[5];
	node* pNext;
public:
	node();
	~node();
	
	node* getNext();
	char* getCard();

	void setNext(node* pTemp);
	void setCard(char* data);
};