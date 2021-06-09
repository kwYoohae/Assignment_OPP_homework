#pragma once
#include "node.h"
#include "cube_1D.h"
#include "tree.h"
class cube
{
private:
	node* pHead; // ť���� head��
	cube_1D* Row; // ����ϴ� row������ �̸��� ����
	cube_1D* Column; // ����ϴ� column������ �̸��� ����
	cube_1D* Height; // ����ϴ� height������ �̸��� ����
public:
	cube(); // ������
	~cube(); // �Ҹ���

	node* getHead(); // ������ȯ�ϴ� �żҵ�
	cube_1D* getRow();// ������ȯ�ϴ� �żҵ�
	cube_1D* getColumn();// ������ȯ�ϴ� �żҵ�
	cube_1D* getHeight();// ������ȯ�ϴ� �żҵ�

	void setHead(node* pTemp);// ���� �����ϴ� �żҵ�
	void setRow(cube_1D* pTemp);// ���� �����ϴ� �żҵ�
	void setColumn(cube_1D* pTemp);// ���� �����ϴ� �żҵ�
	void setHeight(cube_1D* pTemp);// ���� �����ϴ� �żҵ�
	void Make_Cube(int p, int l, int t); // ť�긦 ����� �żҵ�
	void Make_View(tree* Time, tree* Location, tree* Product); // viewť���� ������ �����ִ� �żҵ�
	void Make_tree(tree* Time, tree* Location, tree* Product ,int product_number, int location_number, int time_number); // tree(cube_1d)�� ����� �żҵ�
	void copyData(cube* raw); // �����͸� �����ϴ� �żҵ�
	void WriteLog(char* command); //  log�� ���� �żҵ�
	void WriteError(char* command); // error�޽����� ���� �żҵ�
	bool Rotate(char* command); // rotate�� �ϴ� �żҵ�

	node* (node::*pRight)() = &node::getCnext; // �Լ������� �� �ʱ�ȭ �� ����
	node*(node::*pLeft)() = &node::getCprev;// �Լ������� �� �ʱ�ȭ �� ����
	node* (node::* pUp)() = &node::getHprev;// �Լ������� �� �ʱ�ȭ �� ����
	node*(node::*pDown)() = &node::getHnext;// �Լ������� �� �ʱ�ȭ �� ����
	node*(node::*pIn)() = &node::getRprev;// �Լ������� �� �ʱ�ȭ �� ����
	node*(node::*pOut)() = &node::getRnext;// �Լ������� �� �ʱ�ȭ �� ����
	void (node::*setRight)(node* pTemp) = &node::setCnext;// �Լ������� �� �ʱ�ȭ �� ����
	void (node::*setLeft)(node* pTemp) = &node::setCprev;// �Լ������� �� �ʱ�ȭ �� ����
	void (node::*setUp)(node* pTemp) = &node::setHprev;// �Լ������� �� �ʱ�ȭ �� ����
	void (node::*setDown)(node* pTemp) = &node::setHnext;// �Լ������� �� �ʱ�ȭ �� ����
	void (node::*setIn)(node* pTemp) = &node::setRprev;// �Լ������� �� �ʱ�ȭ �� ����
	void (node::*setOut)(node* pTemp) = &node::setRnext;// �Լ������� �� �ʱ�ȭ �� ����

	cube_1D* (cube::*pRow)() = &cube::getRow;// �Լ������� �� �ʱ�ȭ �� ����
	cube_1D* (cube::* pColumn)() = &cube::getColumn;// �Լ������� �� �ʱ�ȭ �� ����
	cube_1D* (cube::* pHeight)() = &cube::getHeight;// �Լ������� �� �ʱ�ȭ �� ����
	void (cube::* pRow_set)(cube_1D* pTemp) = &cube::setRow;// �Լ������� �� �ʱ�ȭ �� ����
	void (cube::* pColumn_set)(cube_1D* pTemp) = &cube::setColumn;// �Լ������� �� �ʱ�ȭ �� ����
	void (cube::* pHeight_set)(cube_1D* pTemp) = &cube::setHeight;// �Լ������� �� �ʱ�ȭ �� ����
	
	bool Roll_up(char* command); // Roll_up�� �����ϴ� �żҵ�
	bool slice(char* command); //slice�� �����ϴ¸żҵ�
	//bool DrillDown(char* command, cube* raw);
	void delete_cube(); // ���� �����ϴ� �żҵ�

};

