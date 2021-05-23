#include "Node.h"

Node::Node() {
	pRight = nullptr;
	pLeft = nullptr;
	pUp = nullptr;
	pDown = nullptr;
	data = 0;
}
Node::~Node() {

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