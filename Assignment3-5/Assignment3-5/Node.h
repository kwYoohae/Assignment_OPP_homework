#pragma once

class Node {
private:
	int data;
	Node* pNext;
	Node* pPrev;
public:
	Node();
	~Node();
	
	int getData();
	Node* getNext();
	Node* getPrev();

	void setData(int _Data);
	void setNext(Node* pTemp);
	void setPrev(Node* pTemp);
};