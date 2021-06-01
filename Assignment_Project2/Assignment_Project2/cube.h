#pragma once
#include "node.h"
#include "cube_1D.h"
#include "tree.h"
class cube
{
private:
	node* pHead;
	cube_1D* pTime;
	cube_1D* pLocation;
	cube_1D* pProduct;
public:
	cube();
	~cube();

	void Print();
	node* getHead();
	cube_1D* getTime();
	cube_1D* getLocation();
	cube_1D* getProduct();

	void setHead(node* pTemp);
	void setTime(cube_1D* pTemp);
	void setLocation(cube_1D* pTemp);
	void setProduct(cube_1D* pTemp);
	void Make_Cube(int p, int l, int t);
	void Make_View(cube* raw, tree* Time, tree* Location, tree* Product);
	void Make_tree(tree* Time, tree* Location, tree* Product ,int number);
	int count_time();
	int count_location();
	int count_product();
};

