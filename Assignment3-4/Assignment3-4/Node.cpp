#include "Node.h"
#include<iostream>

node::node() { // 생성자
	memset(card, NULL, 5);
	pNext = nullptr;
	pPrev = nullptr;
}

node::~node() { // 소멸자

}

node* node::getPrev() { // 값을 반환하는 매소드
	return pPrev;
}

node* node::getNext() { // 값을 반환하는 매소드
	return pNext;
}

char* node::getCard() { // 값을 반환하는 매소드
	return card;
}


void node::setCard(char* data) { // 값을 변경하는 매소드
	strcpy_s(card, data);
}

void node::setNext(node* pTemp) { // 값을 변경하는 매소드
	pNext = pTemp;
}

void node::setPrev(node* pTemp) { // 값을 변경하는 매소드
	pPrev = pTemp;
}

