#pragma once
#include "node.h"
#include "cube_1D.h"
#include "tree.h"
class cube
{
private:
	node* pHead;
	cube_1D* pRow;
	cube_1D* pColumn;
	cube_1D* pHeight;
public:
	cube();
	~cube();

	void Print();
	node* getHead();
	cube_1D* getRow();
	cube_1D* getColumn();
	cube_1D* getHeight();

	void setHead(node* pTemp);
	void setRow(cube_1D* pTemp);
	void setColumn(cube_1D* pTemp);
	void setHeight(cube_1D* pTemp);
	void Make_Cube(int p, int l, int t);
	void Make_View(tree* Time, tree* Location, tree* Product);
	void Make_tree(tree* Time, tree* Location, tree* Product ,int number);
	int count_time();
	int count_location();
	int count_product();
	void WriteLog(char* command);
};

