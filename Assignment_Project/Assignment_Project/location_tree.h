#pragma once
#include "location_node.h"
class location_tree
{
private:
	location_node* pRoot;

public:
	location_tree();
	~location_tree();

	location_node* getRoot();

	void setRoot(location_node* pTemp);
};

