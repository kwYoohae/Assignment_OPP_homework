#include "node.h"

node::node() {
	tNext = nullptr;
	tPrev = nullptr;
	pPrev = nullptr;
	pNext = nullptr;
	lNext = nullptr;
	lPrev = nullptr;
	data = 0;
}
node::~node() {

}

node* node::getPnext() {
	return pNext;
}
node* node::getPprev() {
	return pPrev;
}
node* node::getLnext() {
	return lNext;
}
node* node::getLprev() {
	return lPrev;
}
node* node::getTnext() {
	return tNext;
}
node* node::getTprev() {
	return tPrev;
}
int node::getData() {
	return data;
}

void node::setLnext(node* pTemp) {
	lNext = pTemp;
}
void node::setLprev(node* pTemp) {
	lPrev = pTemp;
}
void node::setPprev(node* pTemp) {
	pPrev = pTemp;
}
void node::setPnext(node* pTemp) {
	pNext = pTemp;
}
void node::setTnext(node* pTemp) {
	tNext = pTemp;
}
void node::setTprev(node* pTemp) {
	tPrev = pTemp;
}
void node::setData(int temp) {
	data = temp;
}