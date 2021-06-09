#include "cube_1D.h"
#include <iostream>

cube_1D::cube_1D() { // 생성자(초기화)
	pNext = nullptr;
	pPrev = nullptr;
	pData = nullptr;
	Rev_number = 0;
}

cube_1D::~cube_1D() { // 소멸자

}

tree_node* cube_1D::getData() { // 값을 반환하는 매소드
	return pData;
}
cube_1D* cube_1D::getNext() {// 값을 반환하는 매소드
	return pNext;
}
cube_1D* cube_1D::getPrev() {// 값을 반환하는 매소드
	return pPrev;
}
int cube_1D::getRev() {// 값을 반환하는 매소드
	return Rev_number;
}

void cube_1D::setRev(int temp) {// 값을 변경하는 매소드
	Rev_number = temp;
}
void cube_1D::setData(tree_node* pTemp) {// 값을 변경하는 매소드
	pData = pTemp;
}

void cube_1D::setNext(cube_1D* pTemp) {// 값을 변경하는 매소드
	pNext = pTemp;
}
void cube_1D::setPrev(cube_1D* pTemp) {// 값을 변경하는 매소드
	pPrev = pTemp;
}

