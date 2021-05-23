#pragma once
#include "tree_node.h"
class location_tree
{
private:
	tree_node* pRoot;

public:
	location_tree();
	~location_tree();

	tree_node* getRoot();

	void setRoot(tree_node* pTemp);
};

