#include "Node.h"
#include <iostream>

Node::Node() { //생성자
	data = 0;
	pNext = nullptr;
	pPrev = nullptr;
}

Node::~Node() { // 소멸자

}

int Node::getData() { // 값을 반환해주는 매소드
	return data;
}

Node* Node::getNext() {// 값을 반환해주는 매소드
	return pNext;
}

Node* Node::getPrev() {// 값을 반환해주는 매소드
	return pPrev;
}

void Node::setData(int _Data) {//값을 변경해주는 매소드
	data = _Data;
}

void Node::setNext(Node* pTemp) {//값을 변경해주는 매소드
	pNext = pTemp;
}

void Node::setPrev(Node* pTemp) {//값을 변경해주는 매소드
	pPrev = pTemp;
}
