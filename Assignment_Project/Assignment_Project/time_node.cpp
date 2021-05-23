#include "time_node.h"
#include <iostream>

time_node::time_node() {
	pUp = nullptr;
	pDown = nullptr;
	memset(data, NULL, 100);
	pHead = nullptr;
	pTail = nullptr;
}

time_node::~time_node() {

}

time_node* time_node::getUp() {
	return pUp;
}
time_node* time_node::getDown() {
	return pDown;
}
char* time_node::getData() {
	return data;
}
Node* time_node::getHead() {
	return pHead;
}
Node* time_node::getTail() {
	return pTail;
}
time_node* time_node::getLeft() {
	return pLeft;
}
time_node* time_node::getRight() {
	return pRight;
}

void time_node::setUp(time_node* pTemp) {
	pUp = pTemp;
}
void time_node::setDown(time_node* pTemp) {
	pDown = pTemp;
}
void time_node::setData(char* pTemp) {
	strcpy_s(data, pTemp);
}
void time_node::setHead(Node* pTemp) {
	pHead = pTemp;
}
void time_node::setTail(Node* pTemp) {
	pTail = pTemp;
}
void time_node::setRight(time_node* pTemp) {
	pRight = pTemp;
}
void time_node::setLeft(time_node* pTemp) {
	pLeft = pTemp;
}