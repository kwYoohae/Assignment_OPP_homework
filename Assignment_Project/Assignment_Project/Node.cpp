#include "Node.h"

Node::Node() {
	pRight = nullptr;
	pLeft = nullptr;
	pUp = nullptr;
	pDown = nullptr;
	pHigh = nullptr;
	pLow = nullptr;
	data = 0;
}
Node::~Node() {

}

Node* Node::getHigh() {
	return pHigh;
}
Node* Node::getLow() {
	return pLow;
}
Node* Node::getLeft() {
	return pLeft;
}
Node* Node::getRight() {
	return pRight;
}
Node* Node::getDown() {
	return pDown;
}
Node* Node::getUp() {
	return pUp;
}
int Node::getData() {
	return data;
}

void Node::setLow(Node* pTemp) {
	pLow = pTemp;
}
void Node::setHigh(Node* pTemp) {
	pHigh = pTemp;
}
void Node::setLeft(Node* pTemp) {
	pLeft = pTemp;
}
void Node::setRight(Node* pTemp) {
	pRight = pTemp;
}
void Node::setDown(Node* pTemp) {
	pDown = pTemp;
}
void Node::setUp(Node* pTemp) {
	pUp = pTemp;
}
void Node::setData(int temp) {
	data = temp;
}