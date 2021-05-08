#pragma once
#include "menu_node.h"

class bst_node {
private:
	menu_node* pNode;
	bst_node* pLeft;
	bst_node* pRight;
public:
	bst_node();
	~bst_node();
	menu_node* getNode();
	bst_node* getLeft();
	bst_node* getRight();
	void setNode(menu_node* pTemp);
	void setLeft(bst_node* pTemp);
	void setRight(bst_node* pTemp);
	
};