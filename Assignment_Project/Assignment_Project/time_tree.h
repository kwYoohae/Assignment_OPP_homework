#pragma once
#include "time_node.h"
class time_tree
{
private:
	time_node* pRoot;
	time_node* pHead;
	time_node* pTail;

public:
	time_tree();
	~time_tree();

	time_node* getRoot();


	void setRoot(time_node* pTemp);

};

