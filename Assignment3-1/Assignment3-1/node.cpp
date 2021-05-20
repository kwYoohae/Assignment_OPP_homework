#include "node.h"

node::node() {
	memset(data, NULL, sizeof(data)); // data�� �ʱ�ȭ
	pPrev = nullptr; // prev�� �ʱ�ȭ
	pNext = nullptr; // next�� �ʱ�ȭ
}

node::~node() {

}

void node::setData(char* str) {
	strcpy_s(data, str); // data�� copy
}

void node::setNext(node* pNode) { // ���� �����ϴ� �żҵ�
	pNext = pNode; 
}

void node::setPrev(node* pNode) { // ���� �����ϴ� �żҵ�
	pPrev = pNode;
}

char* node::getData() { //���� ��ȯ�ϴ� �żҵ�
	return data;
}

node* node::getNext() {//���� ��ȯ�ϴ� �żҵ�
	return pNext;
}

node* node::getPrev() {//���� ��ȯ�ϴ� �żҵ�
	return pPrev;
}
