#include "product_node.h"
#include <iostream>

product_node::product_node() {
	pUp = nullptr;
	pDown = nullptr;
	memset(data, NULL, 100);
	pHead = nullptr;
	pTail = nullptr;
}

product_node::~product_node() {

}

product_node* product_node::getUp() {
	return pUp;
}
product_node* product_node::getDown() {
	return pDown;
}
char* product_node::getData() {
	return data;
}
Node* product_node::getHead() {
	return pHead;
}
Node* product_node::getTail() {
	return pTail;
}

void product_node::setUp(product_node* pTemp) {
	pUp = pTemp;
}
void product_node::setDown(product_node* pTemp) {
	pDown = pTemp;
}
void product_node::setData(char* pTemp) {
	strcpy_s(data, pTemp);
}
void product_node::setHead(Node* pTemp) {
	pHead = pTemp;
}
void product_node::setTail(Node* pTemp) {
	pTail = pTemp;
}