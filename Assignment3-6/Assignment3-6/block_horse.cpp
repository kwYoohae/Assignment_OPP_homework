#include "block_horse.h"

block::block() {
	pNext = nullptr; //pNext �� �ʱ�ȭ
	pPrev = nullptr; //pPrev �� �ʱ�ȭ
	pShortCut = nullptr; // pShortCut �� �ʱ�ȭ
	pOn = nullptr; //pOn�� �ʱ�ȭ
}
block::~block() { // block�� �Ҹ���

}

block* block::getNext() { 
	return pNext; // pNext�� ���� ��ȯ�ϴ� �żҵ�
}
block* block::getPrev() {
	return pPrev; // pPrev�� ���� ��ȯ�ϴ� �żҵ�
}
block* block::getShortcut() {
	return pShortCut; // pSHortCut�� ���� ��ȯ�ϴ� �żҵ�
}
horse* block::getOn() {
	return pOn; // pOn�� ���� ��ȯ�ϴ� �żҵ�
}

void block::setNext(block* pTemp) {
	pNext = pTemp; // pNext�� ���� �����ϴ� �żҵ�
}
void block::setPrev(block* pTemp) {
	pPrev = pTemp; // pPrev�� ���� �����Ѵ� �żҵ�
}
void block::setShortcut(block* pTemp) {
	pShortCut = pTemp; // pShortCut�� ���� �����ϴ� �żҵ�
}
void block::setOn(horse* pTemp) {
	pOn = pTemp; // pOn�� ���� �����ϴ� �żҵ�
}


horse::horse() {
	pNext = nullptr; // pNext�� ���� �ʱ�ȭ
	pCarry = nullptr; // pCarry�� ���� �ʱ�ȭ
	pPos = nullptr; // pPos�� ���� �ʱ�ȭ
	start = false; // start�� ���� false�� �ʱ�ȭ
	short_cut1 = false; // short_cut1�� ���� �ʱ�ȭ
	short_cut2 = false; // short_cut2�� ���� �ʱ�ȭ
	memset(name, NULL, 5); // name�� ���� �ʱ�ȭ
	now_carry = false; // now_carry�� ���� �ʱ�ȭ
}

int horse::getNow_carry() {
	return now_carry; // now_carry�� ���� ��ȯ�ϴ� �żҵ�
}
bool horse::getStart() {
	return start; // start�� ���� ��ȯ�ϴ� �żҵ�
}
horse* horse::getNext() {
	return pNext; // pNext�� ���� ��ȯ�ϴ� �żҵ�
}
horse* horse::getCarry() {
	return pCarry; // pCarry�� ���� ��ȯ�ϴ� �żҵ�
}
block* horse::getPos() {
	return pPos; // pPos�� ���� ��ȯ�ϴ� �żҵ�
}
char* horse::getName() {
	return name; // name�� ���� ��ȯ�ϴ� �żҵ�
}
bool horse::getShortCut1() {
	return short_cut1; // short_cut1�� ���� ��ȯ�ϴ� �żҵ�
}
bool horse::getShortCut2() {
	return short_cut2; // short_cut2�� ���� ��ȯ�ϴ� �żҵ�
}

void horse::setName(char* temp) {
	strcpy_s(name, temp); // name�� ���� copy�ϴ� �żҵ�
} 
void horse::setNext(horse* pTemp) {
	pNext = pTemp; // pNext�� ���� �����ϴ� �żҵ�
}
void horse::setCarry(horse* pTemp) {
	pCarry = pTemp;// pPrev�� ���� �����ϴ� �żҵ�
}
void horse::setPos(block* pTemp) {
	pPos = pTemp;// pPos�� ���� �����ϴ� �żҵ�
}
void horse::setStart(bool temp) {
	start = temp;// start�� ���� �����ϴ� �żҵ�
}
void horse::setShrotCut1(bool temp) {
	short_cut1 = temp;// short_cut1�� ���� �����ϴ� �żҵ�
}
void horse::setShrotCut2(bool temp) {
	short_cut2 = temp;// short_cut2�� ���� �����ϴ� �żҵ�
}
void horse::setNow_carry(int temp) {
	now_carry = temp;// now_carry�� ���� �����ϴ� �żҵ�
}

void horse::insert_carry(horse* pTemp) {
	if (!pCarry) { //pCarry�� ���� ������� ��쿡��
		pTemp->setNow_carry(true); // now_carry�� �� ����
		this->setCarry(pTemp); // pTemp �� Carry�� ����
	}
}