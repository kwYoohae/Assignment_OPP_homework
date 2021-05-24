#include "cube.h"
#include <iostream>

cube::cube() {
	pHead = nullptr;
	pTail = nullptr;
	memset(name, NULL, 100);
}
cube::~cube() {

}

cube_2D* cube::getHead() {
	return pHead;
}
cube_2D* cube::getTail() {
	return pTail;
}
char* cube::getName() {
	return name;
}

void cube::setHead(cube_2D* pTemp) {
	pHead = pTemp;
}
void cube::setTail(cube_2D* pTemp) {
	pTail = pTemp;
}
void cube::setName(char* pTemp) {
	strcpy_s(name, pTemp);
}

void cube::make_raw(tree* Tree) {
	tree_node* pLow_data = Tree->getRoot();
	tree_node* pLow_parent = nullptr;
	while (pLow_data->getDown()) {
		pLow_data = pLow_data->getDown();
	}
	pLow_parent = pLow_data->getUp();
	while (pLow_parent) {
		while (pLow_data) {
			cube_2D* pNew = new cube_2D;
			pNew->setName(pLow_data->getData());
			if (!pHead) {
				pHead = pNew;
				pTail = pNew;
			}
			else {
				pTail->setNext(pNew);
				pNew->setPrev(pTail);
				pTail = pNew;
			}
			pLow_data = pLow_data->getNext();
		}
		pLow_parent = pLow_parent->getNext();
		pLow_data = pLow_parent->getDown();
	}
}