#pragma once
#include "product_node.h"

class product_tree
{
private:
	product_node* pRoot;

public:
	product_tree();
	~product_tree();

	product_node* getRoot();

	void setRoot(product_node* pTemp);
};



