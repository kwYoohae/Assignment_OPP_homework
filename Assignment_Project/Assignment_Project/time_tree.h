#pragma once
#include "tree_node.h"
class time_tree
{
private:
	tree_node* pRoot;

public:
	time_tree();
	~time_tree();

	tree_node* getRoot();

	void setRoot(tree_node* pTemp);
	void Plus_Count();

	void Insert_Down(tree_node* pParent, tree_node* pTemp, tree_node** pDown);
};

