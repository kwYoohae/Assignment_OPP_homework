#include "cube_1D.h"
#include <iostream>

cube_1D::cube_1D() { // ������(�ʱ�ȭ)
	pNext = nullptr;
	pPrev = nullptr;
	pData = nullptr;
	Rev_number = 0;
}

cube_1D::~cube_1D() { // �Ҹ���

}

tree_node* cube_1D::getData() { // ���� ��ȯ�ϴ� �żҵ�
	return pData;
}
cube_1D* cube_1D::getNext() {// ���� ��ȯ�ϴ� �żҵ�
	return pNext;
}
cube_1D* cube_1D::getPrev() {// ���� ��ȯ�ϴ� �żҵ�
	return pPrev;
}
int cube_1D::getRev() {// ���� ��ȯ�ϴ� �żҵ�
	return Rev_number;
}

void cube_1D::setRev(int temp) {// ���� �����ϴ� �żҵ�
	Rev_number = temp;
}
void cube_1D::setData(tree_node* pTemp) {// ���� �����ϴ� �żҵ�
	pData = pTemp;
}

void cube_1D::setNext(cube_1D* pTemp) {// ���� �����ϴ� �żҵ�
	pNext = pTemp;
}
void cube_1D::setPrev(cube_1D* pTemp) {// ���� �����ϴ� �żҵ�
	pPrev = pTemp;
}

