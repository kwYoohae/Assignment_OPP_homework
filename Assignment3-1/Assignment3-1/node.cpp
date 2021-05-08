#include "node.h"

node::node() {
	memset(data, NULL, sizeof(data));
	pPrev = nullptr;
	pNext = nullptr;
}

node::~node() {

}

void node::setData(char* str) {
	strcpy_s(data, str);
}

void node::setNext(node* pNode) {
	pNext = pNode;
}

void node::setPrev(node* pNode) {
	pPrev = pNode;
}

char* node::getData() {
	return data;
}

node* node::getNext() {
	return pNext;
}

node* node::getPrev() {
	return pPrev;
}
