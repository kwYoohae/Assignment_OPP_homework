#include "node.h"

node::node() { // ������ (���� �ʱ�ȭ)
	rNext = nullptr;
	rPrev = nullptr;
	cPrev = nullptr;
	cNext = nullptr;
	hNext = nullptr;
	hPrev = nullptr;
	data = 0;
}
node::~node() { // �Ҹ���

}

node* node::getHnext() { // ���� ��ȯ�ϴ� �żҵ�
	return hNext;
}
node* node::getHprev() {// ���� ��ȯ�ϴ� �żҵ�
	return hPrev;
}
node* node::getCnext() {// ���� ��ȯ�ϴ� �żҵ�
	return cNext;
}
node* node::getCprev() {// ���� ��ȯ�ϴ� �żҵ�
	return cPrev;
}
node* node::getRnext() {// ���� ��ȯ�ϴ� �żҵ�
	return rNext;
}
node* node::getRprev() {// ���� ��ȯ�ϴ� �żҵ�
	return rPrev;
}
int node::getData() {// ���� ��ȯ�ϴ� �żҵ�
	return data;
}

void node::setCnext(node* pTemp) { // ���� �����ϴ� �żҵ�
	cNext = pTemp;
}
void node::setCprev(node* pTemp) {// ���� �����ϴ� �żҵ�
	cPrev = pTemp;
}
void node::setHprev(node* pTemp) {// ���� �����ϴ� �żҵ�
	hPrev = pTemp;
}
void node::setHnext(node* pTemp) {// ���� �����ϴ� �żҵ�
	hNext = pTemp;
}
void node::setRnext(node* pTemp) {// ���� �����ϴ� �żҵ�
	rNext = pTemp;
}
void node::setRprev(node* pTemp) {// ���� �����ϴ� �żҵ�
	rPrev = pTemp;
}
void node::setData(int temp) {// ���� �����ϴ� �żҵ�
	data = temp;
}
