#pragma once
class tree_node {
private:
	int count;
	char data[100];
	int low;
	tree_node* pUp;
	tree_node* pDown;
	tree_node* pNext;
	tree_node* pPrev;
public:
	tree_node();
	~tree_node();

	int getLow();
	tree_node* getUp();
	tree_node* getDown();
	char* getData();
	int getCount();
	tree_node* getNext();
	tree_node* getPrev();

	void setLow(int temp);
	void setUp(tree_node* pTemp);
	void setDown(tree_node* pTemp);
	void setData(char* pTemp);
	void setCount(int temp);
	void setNew();
	void setNext(tree_node* pTemp);
	void setPrev(tree_node* pTemp);
};