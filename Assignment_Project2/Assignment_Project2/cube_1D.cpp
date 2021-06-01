#include "cube_1D.h"
#include <iostream>

cube_1D::cube_1D() {
	pHead = nullptr;
	pTail = nullptr;
	pNext = nullptr;
	pPrev = nullptr;
	memset(name, NULL, 100);
	pData = nullptr;
}

cube_1D::~cube_1D() {

}

tree_node* cube_1D::getData() {
	return pData;
}
node* cube_1D::getHead() {
	return pHead;
}
node* cube_1D::getTail() {
	return pTail;
}
char* cube_1D::getName() {
	return name;
}
cube_1D* cube_1D::getNext() {
	return pNext;
}
cube_1D* cube_1D::getPrev() {
	return pPrev;
}

void cube_1D::setData(tree_node* pTemp) {
	pData = pTemp;
}
void cube_1D::setHead(node* pTemp) {
	pHead = pTemp;
}
void cube_1D::setTail(node* pTemp) {
	pTail = pTemp;
}
void cube_1D::setName(char* pTemp) {
	strcpy_s(name, pTemp);
}

void cube_1D::setNext(cube_1D* pTemp) {
	pNext = pTemp;
}
void cube_1D::setPrev(cube_1D* pTemp) {
	pPrev = pTemp;
}

