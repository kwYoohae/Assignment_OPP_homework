#pragma once
#include "tree_node.h"
class tree
{
private:
	tree_node* pRoot; // root��

public:
	tree(); // ������
	~tree(); // �Ҹ���

	tree_node* getRoot(); //���� ��ȯ�ϴ� �żҵ�

	void setRoot(tree_node* pTemp);// ���� �����ϴ� �żҵ�

	void delete_tree(tree_node* Node); //tree�� �����ϴ� �żҵ�
};

