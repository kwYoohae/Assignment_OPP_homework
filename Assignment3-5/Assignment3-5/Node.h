#pragma once

class Node {
private:
	int data;
	bool shot;
	Node* pNext;
	Node* pPrev;
public:
	Node();
	~Node();
	
	int getData();
	Node* getNext();
	Node* getPrev();
	bool getShot();

	void setData(int _Data);
	void setNext(Node* pTemp);
	void setPrev(Node* pTemp);
	void setShot(bool temp);
};