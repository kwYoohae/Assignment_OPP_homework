#include "cube_2D.h"
#include <iostream>

cube_2D::cube_2D() {
	pHead = nullptr;
	pTail = nullptr;
	pNext = nullptr;
	pPrev = nullptr;
	memset(name, NULL, 100);
}
cube_2D::~cube_2D() {

}

cube_1D* cube_2D::getHead() {
	return pHead;
}
cube_1D* cube_2D::getTail() {
	return pTail;
}
char* cube_2D::getName() {
	return name;
}
cube_2D* cube_2D::getNext() {
	return pNext;
}
cube_2D* cube_2D::getPrev() {
	return pPrev;
}

void cube_2D::setNext(cube_2D* pTemp) {
	pNext = pTemp;
}
void cube_2D::setPrev(cube_2D* pTemp) {
	pPrev = pTemp;
}
void cube_2D::setHead(cube_1D* pTemp) {
	pHead = pTemp;
}
void cube_2D::setTail(cube_1D* pTemp) {
	pTail = pTemp;
}
void cube_2D::setName(char* pTemp) {
	strcpy_s(name, pTemp);
}