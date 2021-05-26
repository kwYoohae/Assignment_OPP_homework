#include "cube_1D.h"
#include <iostream>

cube_1D::cube_1D() {
	pHead = nullptr;
	pTail = nullptr;
	pNext = nullptr;
	pPrev = nullptr;
	memset(name, NULL, 100);
}
cube_1D::~cube_1D() {
	
}

Node* cube_1D::getTail() {
	return pTail;
}
Node* cube_1D::getHead() {
	return pHead;
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

void cube_1D::setTail(Node* pTemp) {
	pTail = pTemp;
}
void cube_1D::setHead(Node* pTemp) {
	pHead = pTemp;
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

void cube_1D::make_raw(tree* Tree) {
	
}

void cube_1D::delete_node() {
	Node* pTemp = pHead;
	Node* pTemp_right = pHead;
	while (pTemp) {
		pHead = pHead->getDown();
		delete pTemp;
		pTemp = pHead;
	}
}