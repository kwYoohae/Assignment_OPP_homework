#pragma once
#include "tree_node.h"
class tree
{
private:
	tree_node* pRoot;

public:
	tree();
	~tree();

	tree_node* getRoot();

	void setRoot(tree_node* pTemp);

	void delete_tree(tree_node* Node);
};

