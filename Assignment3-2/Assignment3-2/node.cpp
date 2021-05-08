#include <iostream>
#include "node.h"

using namespace std;

node::node() {
	data = 0; // data값 초기화
	pPrev = nullptr; // 이전값 초기화
	pNext = nullptr; // 다음값 초기화
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