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
	int Rev_r;
	int Rev_c;
	int Rev_h;
	int rotate_LR;
	int rotate_C_CL;
	int rotate_UD;
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
	void copyData(cube* raw);
	void WriteLog(char* command);
	void WriteError(char* command);
	bool Rotate(char* command);
	void check();

	node* (node::*pRight)() = &node::getCnext;
	node*(node::*pLeft)() = &node::getCprev;
	node* (node::* pUp)() = &node::getHprev;
	node*(node::*pDown)() = &node::getHnext;
	node*(node::*pIn)() = &node::getRprev;
	node*(node::*pOut)() = &node::getRnext;
	void (node::*setRight)(node* pTemp) = &node::setCnext;
	void (node::*setLeft)(node* pTemp) = &node::setCprev;
	void (node::*setUp)(node* pTemp) = &node::setHprev;
	void (node::*setDown)(node* pTemp) = &node::setHnext;
	void (node::*setIn)(node* pTemp) = &node::setRprev;
	void (node::*setOut)(node* pTemp) = &node::setRnext;

	cube_1D* (cube::*pRow)() = &cube::getRow;
	cube_1D* (cube::* pColumn)() = &cube::getColumn;
	cube_1D* (cube::* pHeight)() = &cube::getHeight;
	void (cube::* pRow_set)(cube_1D* pTemp) = &cube::setRow;
	void (cube::* pColumn_set)(cube_1D* pTemp) = &cube::setColumn;
	void (cube::* pHeight_set)(cube_1D* pTemp) = &cube::setHeight;
	
	void Reverse(cube_1D* pCube);

	bool Roll_up(char* command);
	bool slice(char* command);
	bool DrillDown(char* command, cube* raw);
	void delete_cube();

};

