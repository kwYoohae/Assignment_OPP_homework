#pragma once
#include "tree_node.h"

class product_tree
{
private:
	tree_node* pRoot;

public:
	product_tree();
	~product_tree();

	tree_node* getRoot();

	void setRoot(tree_node* pTemp);
};



