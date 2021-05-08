#include "Node.h"
#include <iostream>

Node::Node() {
	data = 0;
	pNext = nullptr;
	pPrev = nullptr;
	shot = false;
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

bool Node::getShot() {
	return shot;
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

void Node::setShot(bool temp) {
	shot = temp;
}