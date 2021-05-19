#include "move.h"
moving::moving() {
	step = 0; //moving의 값 초기화
	pNext = nullptr; // pNext의 값 초기화
}
moving::~moving() {
	
}

int moving::getStep() {
	return step; // step을 반환하는 매소드
}
moving* moving::getNext() {
	return pNext; //pNext를 반환하는 매소드
}

void moving::setStep(int temp) {
	step = temp; // step의 값을 변경하는 매소드
}
void moving::setNext(moving* pTemp) {
	pNext = pTemp; //pNext의 값을 변경하는 매소드
}