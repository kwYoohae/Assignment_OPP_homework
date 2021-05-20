#pragma once
#include "menu_node.h"

class bst_node {
private:
	menu_node* pNode;
	bst_node* pLeft;
	bst_node* pRight;
public:
	bst_node(); //������
	~bst_node(); // �Ҹ���
	menu_node* getNode(); //�� ��ȯ�żҵ�
	bst_node* getLeft();//�� ��ȯ�żҵ�
	bst_node* getRight();//�� ��ȯ�żҵ�
	void setNode(menu_node* pTemp);//�� ����żҵ�
	void setLeft(bst_node* pTemp);//�� ����żҵ�
	void setRight(bst_node* pTemp);//�� ����żҵ�
	
};