#include "move.h"
moving::moving() {
	step = 0; //moving�� �� �ʱ�ȭ
	pNext = nullptr; // pNext�� �� �ʱ�ȭ
}
moving::~moving() {
	
}

int moving::getStep() {
	return step; // step�� ��ȯ�ϴ� �żҵ�
}
moving* moving::getNext() {
	return pNext; //pNext�� ��ȯ�ϴ� �żҵ�
}

void moving::setStep(int temp) {
	step = temp; // step�� ���� �����ϴ� �żҵ�
}
void moving::setNext(moving* pTemp) {
	pNext = pTemp; //pNext�� ���� �����ϴ� �żҵ�
}