#include "tree_node.h"
#include <iostream>

tree_node::tree_node() {
	pUp = nullptr;
	pDown = nullptr;
	memset(data, NULL, 100);
	pNext = nullptr;
	pPrev = nullptr;
	count = 0;
	low = 0;
}

tree_node::~tree_node() {

}

tree_node* tree_node::getUp() {
	return pUp;
}
tree_node* tree_node::getDown() {
	return pDown;
}
char* tree_node::getData() {
	return data;
}
int tree_node::getCount() {
	return count;
}
int tree_node::getLow() {
	return low;
}


void tree_node::setLow(int temp) {
	low = temp;
}
void tree_node::setUp(tree_node* pTemp) {
	pUp = pTemp;
}
void tree_node::setDown(tree_node* pTemp) {
	pDown = pTemp;
}
void tree_node::setData(char* pTemp) {
	strcpy_s(data, pTemp);
}
void tree_node::setCount(int temp) {
	count = temp;
}
void tree_node::setNew() {

}

tree_node* tree_node::getNext() {
	return pNext;
}
tree_node* tree_node::getPrev() {
	return pPrev;
}

void tree_node::setNext(tree_node* pTemp) {
	pNext = pTemp;
}
void tree_node::setPrev(tree_node* pTemp) {
	pPrev = pTemp;
}