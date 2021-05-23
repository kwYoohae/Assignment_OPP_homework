#pragma once
class Node
{
private:
	int data;
	Node* pLeft;
	Node* pRight;
	Node* pDown;
	Node* pUp;
public:
	Node();
	~Node();

	Node* getLeft();
	Node* getRight();
	Node* getDown();
	Node* getUp();
	int getData();

	void setLeft(Node* pTemp);
	void setRight(Node* pTemp);
	void setDown(Node* pTemp);
	void setUp(Node* pTemp);
	void setData(int temp);
};

