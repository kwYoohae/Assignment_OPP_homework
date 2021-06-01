#pragma once
#include "node.h"
#include "cube_1D.h"
#include "tree.h"
class cube
{
private:
	node* pHead;
	cube_1D* Row;
	cube_1D* Column;
	cube_1D* Height;
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
	void copyData(cube* raw);
	void WriteLog(char* command);

	node* (node::*pRight)() = &node::getCnext;
	node*(node::*pLeft)() = &node::getCprev;
	node* (node::* pUp)() = &node::getHprev;
	node*(node::*pDown)() = &node::getHnext;
	node*(node::*pIn)() = &node::getRprev;
	node*(node::*pOut)() = &node::getRnext;

	cube_1D* (cube::*pRow)() = &cube::getRow;
	cube_1D* (cube::* pColumn)() = &cube::getColumn;
	cube_1D* (cube::* pHeight)() = &cube::getHeight;
};

