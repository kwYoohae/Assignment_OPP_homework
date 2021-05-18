#include "move.h"
moving::moving() {
	step = 0;
	pNext = nullptr;
}
moving::~moving() {
	
}

int moving::getStep() {
	return step;
}
moving* moving::getNext() {
	return pNext;
}

void moving::setStep(int temp) {
	step = temp;
}
void moving::setNext(moving* pTemp) {
	pNext = pTemp;
}