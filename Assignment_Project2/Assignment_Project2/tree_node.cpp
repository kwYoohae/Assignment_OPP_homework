#include "tree_node.h"
#include <iostream>

tree_node::tree_node() { //생성자(초기화)
	pUp = nullptr;
	pDown = nullptr;
	memset(data, NULL, 100);
	pNext = nullptr;
	pPrev = nullptr;
	count = 0;
	low = 0;
}

tree_node::~tree_node() { // 소멸자

}

tree_node* tree_node::getUp() { // 값을 반환 하는 매소드
	return pUp;
}
tree_node* tree_node::getDown() {// 값을 반환 하는 매소드
	return pDown;
}
char* tree_node::getData() {// 값을 반환 하는 매소드
	return data;
}
int tree_node::getCount() {// 값을 반환 하는 매소드
	return count;
}
int tree_node::getLow() {// 값을 반환 하는 매소드
	return low;
}


void tree_node::setLow(int temp) { // 값을 변경하는 매소드
	low = temp;
}
void tree_node::setUp(tree_node* pTemp) {// 값을 변경하는 매소드
	pUp = pTemp;
}
void tree_node::setDown(tree_node* pTemp) {// 값을 변경하는 매소드
	pDown = pTemp;
}
void tree_node::setData(char* pTemp) {// 값을 변경하는 매소드
	strcpy_s(data, pTemp);
}
void tree_node::setCount(int temp) {// 값을 변경하는 매소드
	count = temp;
}
void tree_node::setNew() {// 값을 변경하는 매소드

}

tree_node* tree_node::getNext() { // 값을 반환하는 매소드
	return pNext;
}
tree_node* tree_node::getPrev() {// 값을 반환하는 매소드
	return pPrev;
}

void tree_node::setNext(tree_node* pTemp) {// 값을 변경하는 매소드
	pNext = pTemp;
}
void tree_node::setPrev(tree_node* pTemp) {// 값을 변경하는 매소드
	pPrev = pTemp;
}