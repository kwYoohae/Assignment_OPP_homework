#include "Node.h"
#include <iostream>

Node::Node() {
	data = 0;
	pNext = nullptr;
	pPrev = nullptr;
}

Node::~Node() {

}

int Node::getData() {
	return data;
}

Node* Node::getNext() {
	return pNext;
}

Node* Node::getPrev() {
	return pPrev;
}

void Node::setData(int _Data) {
	data = _Data;
}

void Node::setNext(Node* pTemp) {
	pNext = pTemp;
}

void Node::setPrev(Node* pTemp) {
	pPrev = pTemp;
}
