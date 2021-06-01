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
	return hNext;
}
node* node::getHprev() {
	return hPrev;
}
node* node::getCnext() {
	return cNext;
}
node* node::getCprev() {
	return cPrev;
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
	cNext = pTemp;
}
void node::setCprev(node* pTemp) {
	cPrev = pTemp;
}
void node::setHprev(node* pTemp) {
	hPrev = pTemp;
}
void node::setHnext(node* pTemp) {
	hNext = pTemp;
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
