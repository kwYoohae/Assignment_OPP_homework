#pragma once
class node
{
private:
	int data;
	node* tNext;
	node* tPrev;
	node* pNext;
	node* pPrev;
	node* lNext;
	node* lPrev;
public:
	node();
	~node();

	node* getTnext();
	node* getTprev();
	node* getLnext();
	node* getLprev();
	node* getPprev();
	node* getPnext();
	int getData();

	void setTnext(node* pTemp);
	void setTprev(node* pTemp);
	void setLnext(node* pTemp);
	void setLprev(node* pTemp);
	void setPprev(node* pTemp);
	void setPnext(node* pTemp);
	void setData(int temp);
};

