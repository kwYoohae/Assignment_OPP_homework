#pragma once
class Node
{
private:
	int data;
	Node* pLeft;
	Node* pRight;
	Node* pDown;
	Node* pUp;
	Node* pHigh;
	Node* pLow;
public:
	Node();
	~Node();

	Node* getLow();
	Node* getHigh();
	Node* getLeft();
	Node* getRight();
	Node* getDown();
	Node* getUp();
	int getData();

	void setLow(Node* pTemp);
	void setHigh(Node* pTemp);
	void setLeft(Node* pTemp);
	void setRight(Node* pTemp);
	void setDown(Node* pTemp);
	void setUp(Node* pTemp);
	void setData(int temp);
};

