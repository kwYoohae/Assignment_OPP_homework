#include "location_node.h"
#include <iostream>

location_node::location_node() {
	pUp = nullptr;
	pDown = nullptr;
	memset(data, NULL, 100);
	pHead = nullptr;
	pTail = nullptr;
}

location_node::~location_node() {

}

location_node* location_node::getUp() {
	return pUp;
}
location_node* location_node::getDown() {
	return pDown;
}
char* location_node::getData() {
	return data;
}
Node* location_node::getHead() {
	return pHead;
}
Node* location_node::getTail() {
	return pTail;
}

void location_node::setUp(location_node* pTemp) {
	pUp = pTemp;
}
void location_node::setDown(location_node* pTemp) {
	pDown = pTemp;
}
void location_node::setData(char* pTemp) {
	strcpy_s(data, pTemp);
}
void location_node::setHead(Node* pTemp) {
	pHead = pTemp;
}
void location_node::setTail(Node* pTemp) {
	pTail = pTemp;
}