#include "Node.h"
#include<iostream>

node::node() {
	memset(card, NULL, 5);
	pNext = nullptr;
	pPrev = nullptr;
}

node::~node() {

}

node* node::getPrev() {
	return pPrev;
}

node* node::getNext() {
	return pNext;
}

char* node::getCard() {
	return card;
}


void node::setCard(char* data) {
	strcpy_s(card, data);
}

void node::setNext(node* pTemp) {
	pNext = pTemp;
}

void node::setPrev(node* pTemp) {
	pPrev = pTemp;
}

