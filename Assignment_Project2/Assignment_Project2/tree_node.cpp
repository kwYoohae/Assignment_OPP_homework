#include "tree_node.h"
#include <iostream>

tree_node::tree_node() { //������(�ʱ�ȭ)
	pUp = nullptr;
	pDown = nullptr;
	memset(data, NULL, 100);
	pNext = nullptr;
	pPrev = nullptr;
	count = 0;
	low = 0;
}

tree_node::~tree_node() { // �Ҹ���

}

tree_node* tree_node::getUp() { // ���� ��ȯ �ϴ� �żҵ�
	return pUp;
}
tree_node* tree_node::getDown() {// ���� ��ȯ �ϴ� �żҵ�
	return pDown;
}
char* tree_node::getData() {// ���� ��ȯ �ϴ� �żҵ�
	return data;
}
int tree_node::getCount() {// ���� ��ȯ �ϴ� �żҵ�
	return count;
}
int tree_node::getLow() {// ���� ��ȯ �ϴ� �żҵ�
	return low;
}


void tree_node::setLow(int temp) { // ���� �����ϴ� �żҵ�
	low = temp;
}
void tree_node::setUp(tree_node* pTemp) {// ���� �����ϴ� �żҵ�
	pUp = pTemp;
}
void tree_node::setDown(tree_node* pTemp) {// ���� �����ϴ� �żҵ�
	pDown = pTemp;
}
void tree_node::setData(char* pTemp) {// ���� �����ϴ� �żҵ�
	strcpy_s(data, pTemp);
}
void tree_node::setCount(int temp) {// ���� �����ϴ� �żҵ�
	count = temp;
}
void tree_node::setNew() {// ���� �����ϴ� �żҵ�

}

tree_node* tree_node::getNext() { // ���� ��ȯ�ϴ� �żҵ�
	return pNext;
}
tree_node* tree_node::getPrev() {// ���� ��ȯ�ϴ� �żҵ�
	return pPrev;
}

void tree_node::setNext(tree_node* pTemp) {// ���� �����ϴ� �żҵ�
	pNext = pTemp;
}
void tree_node::setPrev(tree_node* pTemp) {// ���� �����ϴ� �żҵ�
	pPrev = pTemp;
}