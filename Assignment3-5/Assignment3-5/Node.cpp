#include "Node.h"
#include <iostream>

Node::Node() { //������
	data = 0;
	pNext = nullptr;
	pPrev = nullptr;
}

Node::~Node() { // �Ҹ���

}

int Node::getData() { // ���� ��ȯ���ִ� �żҵ�
	return data;
}

Node* Node::getNext() {// ���� ��ȯ���ִ� �żҵ�
	return pNext;
}

Node* Node::getPrev() {// ���� ��ȯ���ִ� �żҵ�
	return pPrev;
}

void Node::setData(int _Data) {//���� �������ִ� �żҵ�
	data = _Data;
}

void Node::setNext(Node* pTemp) {//���� �������ִ� �żҵ�
	pNext = pTemp;
}

void Node::setPrev(Node* pTemp) {//���� �������ִ� �żҵ�
	pPrev = pTemp;
}
