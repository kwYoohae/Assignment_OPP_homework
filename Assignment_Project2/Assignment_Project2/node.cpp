#include "node.h"

node::node() { // 생성자 (값을 초기화)
	rNext = nullptr;
	rPrev = nullptr;
	cPrev = nullptr;
	cNext = nullptr;
	hNext = nullptr;
	hPrev = nullptr;
	data = 0;
}
node::~node() { // 소멸자

}

node* node::getHnext() { // 값을 반환하는 매소드
	return hNext;
}
node* node::getHprev() {// 값을 반환하는 매소드
	return hPrev;
}
node* node::getCnext() {// 값을 반환하는 매소드
	return cNext;
}
node* node::getCprev() {// 값을 반환하는 매소드
	return cPrev;
}
node* node::getRnext() {// 값을 반환하는 매소드
	return rNext;
}
node* node::getRprev() {// 값을 반환하는 매소드
	return rPrev;
}
int node::getData() {// 값을 반환하는 매소드
	return data;
}

void node::setCnext(node* pTemp) { // 값을 변경하는 매소드
	cNext = pTemp;
}
void node::setCprev(node* pTemp) {// 값을 변경하는 매소드
	cPrev = pTemp;
}
void node::setHprev(node* pTemp) {// 값을 변경하는 매소드
	hPrev = pTemp;
}
void node::setHnext(node* pTemp) {// 값을 변경하는 매소드
	hNext = pTemp;
}
void node::setRnext(node* pTemp) {// 값을 변경하는 매소드
	rNext = pTemp;
}
void node::setRprev(node* pTemp) {// 값을 변경하는 매소드
	rPrev = pTemp;
}
void node::setData(int temp) {// 값을 변경하는 매소드
	data = temp;
}
