#include "Yut.h"

yut::yut() {
	pHead = nullptr;
	pTail = nullptr;
}
yut::~yut() {

}

moving* yut::getHead() {
	return pHead;
}
moving* yut::getTail() {
	return pTail;
}

void yut::setHead(moving* pTemp) {
	pHead = pTemp;
}
void yut::setTail(moving* pTemp) {
	pTail = pTemp;
}

bool yut::Throw_yut() {
	bool yut_arr[4];
	srand(time(NULL));
	int random_number;
	int count = 0;
	for (int i = 0; i < 4; i++) {
		random_number = rand() % 10;
		if (random_number < 4) {
			yut_arr[i] = false;
		}
		else {
			yut_arr[i] = true;
			count++;
		}
	}
	moving* pNew = new moving;
	if (!pHead) {
		pHead = pNew;
		pTail = pNew;
	}
	else {
		pTail->setNext(pNew);
		pTail = pNew;
	}
	if (count == 0) {
		pNew->setStep(5);
		std::cout << "Result is mo" << '\n';
		return true;
	}
	else if (count == 1) {
		if (yut_arr[0] == true) {
			pNew->setStep(-1);
			std::cout << "Result is back do" << '\n';
		}
		else {
			pNew->setStep(1);
			std::cout << "Result is do" << '\n';
		}
	}
	else if (count == 2) {
		pNew->setStep(2);
		std::cout << "Result is gae" << '\n';
	}
	else if (count == 3) {
		pNew->setStep(3);
		std::cout << "Result is geol" << '\n';
	}
	else if (count == 4) {
		pNew->setStep(4);
		std::cout << "Result is yut" << '\n';
		return true;
	}
	return false;
}

void yut::delete_yut(int num) {
	moving* pTemp = pHead;
	moving* pPrev = pTemp;
	for (int i = 1; i < num; i++) {
		pPrev = pTemp;
		pTemp = pTemp->getNext();
	}
	if (pTemp == pHead) {
		if (!pHead->getNext()) {
			delete pTemp;
			pHead = nullptr;
			pTail = nullptr;
		}
		else {
			pHead = pTemp->getNext();
			delete pTemp;
		}
	}
	else {
		if (!pTemp->getNext()) {
			pPrev->setNext(nullptr);
			delete pTemp;
		}
		else {
			pPrev->setNext(pTemp->getNext());
			delete pTemp;
		}
	}
}

void yut::print_yut() {
	moving* pTemp = pHead;
	std::cout << "Yut Results: ";
	int count = 1;
	while (pTemp) {
		std::cout << count << ". " << pTemp->getStep();
		std::cout.width(2);
		pTemp = pTemp->getNext();
		count++;
	}
	std::cout << '\n';
}

void yut::yut_delete_all() {
	moving* pTemp = pHead;
	while (pTemp) {
		pHead = pHead->getNext();
		delete pTemp;
		pTemp = pHead;
	}
	pHead = nullptr;
	pTail = nullptr;
}
