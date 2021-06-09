#include "tree.h"
#include <iostream>
tree::tree() { // ������
	pRoot = nullptr;
}
tree::~tree() { // �Ҹ���
	delete_tree(pRoot); // tree�� �������ִ� �żҵ� ȣ��
	pRoot = nullptr;
}

tree_node* tree::getRoot() {// ���� ��ȯ�ϴ� �żҵ�
	return pRoot;
}

void tree::setRoot(tree_node* pTemp) { // ���� �����ϴ� �żҵ�
	pRoot = pTemp;
}

void tree::delete_tree(tree_node* pNode) { // tree�� �����ϴ� �żҵ�
	if (!pNode) { // ��������� ����
		delete_tree(pNode->getDown()); // ���� �� ���� �湮 
		delete_tree(pNode->getNext()); // �ڸų�� ����
		delete pNode;
	}
}

