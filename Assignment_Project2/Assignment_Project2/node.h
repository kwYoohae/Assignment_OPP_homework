#pragma once
class node
{
private:
	int data;
	node* rNext;
	node* rPrev;
	node* cNext;
	node* cPrev;
	node* hNext;
	node* hPrev;
public:
	node();
	~node();

	node* getRnext();
	node* getRprev();
	node* getCnext();
	node* getCprev();
	node* getHprev();
	node* getHnext();
	int getData();

	void setRnext(node* pTemp);
	void setRprev(node* pTemp);
	void setCnext(node* pTemp);
	void setCprev(node* pTemp);
	void setHprev(node* pTemp);
	void setHnext(node* pTemp);
	void setData(int temp);
};

