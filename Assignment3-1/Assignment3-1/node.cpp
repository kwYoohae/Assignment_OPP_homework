#include "node.h"

node::node() {
	memset(data, NULL, sizeof(data)); // data를 초기화
	pPrev = nullptr; // prev를 초기화
	pNext = nullptr; // next를 초기화
}

node::~node() {

}

void node::setData(char* str) {
	strcpy_s(data, str); // data를 copy
}

void node::setNext(node* pNode) { // 값을 변경하는 매소드
	pNext = pNode; 
}

void node::setPrev(node* pNode) { // 값을 변경하는 매소드
	pPrev = pNode;
}

char* node::getData() { //값을 반환하는 매소드
	return data;
}

node* node::getNext() {//값을 반환하는 매소드
	return pNext;
}

node* node::getPrev() {//값을 반환하는 매소드
	return pPrev;
}
