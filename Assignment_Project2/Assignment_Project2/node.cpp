#include "node.h"

node::node() {
	rNext = nullptr;
	rPrev = nullptr;
	cPrev = nullptr;
	cNext = nullptr;
	hNext = nullptr;
	hPrev = nullptr;
	data = 0;
}
node::~node() {

}

node* node::getHnext() {
	return cNext;
}
node* node::getHprev() {
	return cPrev;
}
node* node::getCnext() {
	return hNext;
}
node* node::getCprev() {
	return hPrev;
}
node* node::getRnext() {
	return rNext;
}
node* node::getRprev() {
	return rPrev;
}
int node::getData() {
	return data;
}

void node::setCnext(node* pTemp) {
	hNext = pTemp;
}
void node::setCprev(node* pTemp) {
	hPrev = pTemp;
}
void node::setHprev(node* pTemp) {
	cPrev = pTemp;
}
void node::setHnext(node* pTemp) {
	cNext = pTemp;
}
void node::setRnext(node* pTemp) {
	rNext = pTemp;
}
void node::setRprev(node* pTemp) {
	rPrev = pTemp;
}
void node::setData(int temp) {
	data = temp;
}