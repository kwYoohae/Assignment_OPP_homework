#include <iostream>
#include "node.h"

using namespace std;

node::node() {
	data = 0; // data�� �ʱ�ȭ
	pPrev = nullptr; // ������ �ʱ�ȭ
	pNext = nullptr; // ������ �ʱ�ȭ
}

node::~node() {

}

 int node::getData() {
	return data;
}

node* node::getNext() {
	return pNext;
}

node* node::getPrev() {
	return pPrev;
}

void node::setData(int number) {
	data = number;
}

void node::setNext(node* pNode) {
	pNext = pNode;
}

void node::setPrev(node* pNode) {
	pPrev = pNode;
}