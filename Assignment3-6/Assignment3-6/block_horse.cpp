#include "block_horse.h"

block::block() {
	pNext = nullptr; //pNext 값 초기화
	pPrev = nullptr; //pPrev 값 초기화
	pShortCut = nullptr; // pShortCut 값 초기화
	pOn = nullptr; //pOn값 초기화
}
block::~block() { // block의 소멸자

}

block* block::getNext() { 
	return pNext; // pNext의 값을 반환하는 매소드
}
block* block::getPrev() {
	return pPrev; // pPrev의 값을 반환하는 매소드
}
block* block::getShortcut() {
	return pShortCut; // pSHortCut의 값을 반환하는 매소드
}
horse* block::getOn() {
	return pOn; // pOn의 값을 반환하는 매소드
}

void block::setNext(block* pTemp) {
	pNext = pTemp; // pNext의 값을 변경하는 매소드
}
void block::setPrev(block* pTemp) {
	pPrev = pTemp; // pPrev의 값을 변경한느 매소드
}
void block::setShortcut(block* pTemp) {
	pShortCut = pTemp; // pShortCut의 값을 변경하는 매소드
}
void block::setOn(horse* pTemp) {
	pOn = pTemp; // pOn의 값을 변경하는 매소드
}


horse::horse() {
	pNext = nullptr; // pNext의 값을 초기화
	pCarry = nullptr; // pCarry의 값을 초기화
	pPos = nullptr; // pPos의 값을 초기화
	start = false; // start의 값을 false를 초기화
	short_cut1 = false; // short_cut1의 값을 초기화
	short_cut2 = false; // short_cut2의 값을 초기화
	memset(name, NULL, 5); // name의 값을 초기화
	now_carry = false; // now_carry의 값을 초기화
}

int horse::getNow_carry() {
	return now_carry; // now_carry의 값을 반환하는 매소드
}
bool horse::getStart() {
	return start; // start의 값을 반환하는 매소드
}
horse* horse::getNext() {
	return pNext; // pNext의 값을 반환하는 매소드
}
horse* horse::getCarry() {
	return pCarry; // pCarry의 값을 반환하는 매소드
}
block* horse::getPos() {
	return pPos; // pPos의 값을 반환하는 매소드
}
char* horse::getName() {
	return name; // name의 값을 반환하는 매소드
}
bool horse::getShortCut1() {
	return short_cut1; // short_cut1의 값을 반환하는 매소드
}
bool horse::getShortCut2() {
	return short_cut2; // short_cut2의 값을 반환하는 매소드
}

void horse::setName(char* temp) {
	strcpy_s(name, temp); // name의 값을 copy하는 매소드
} 
void horse::setNext(horse* pTemp) {
	pNext = pTemp; // pNext의 값을 변경하는 매소드
}
void horse::setCarry(horse* pTemp) {
	pCarry = pTemp;// pPrev의 값을 변경하는 매소드
}
void horse::setPos(block* pTemp) {
	pPos = pTemp;// pPos의 값을 변경하는 매소드
}
void horse::setStart(bool temp) {
	start = temp;// start의 값을 변경하는 매소드
}
void horse::setShrotCut1(bool temp) {
	short_cut1 = temp;// short_cut1의 값을 변경하는 매소드
}
void horse::setShrotCut2(bool temp) {
	short_cut2 = temp;// short_cut2의 값을 변경하는 매소드
}
void horse::setNow_carry(int temp) {
	now_carry = temp;// now_carry의 값을 변경하는 매소드
}

void horse::insert_carry(horse* pTemp) {
	if (!pCarry) { //pCarry의 값이 비어있을 경우에는
		pTemp->setNow_carry(true); // now_carry의 값 변경
		this->setCarry(pTemp); // pTemp 를 Carry값 저장
	}
}