#include "LL.h"
#include <cstdlib>
#include <ctime>
#include <crtdbg.h>
#include <iostream>

LL::LL() {
	srand(time(NULL)); //랜덤시드값을 줌
	int rand_number = rand() % 6; // 랜던값을 설정
	Node* pNew;
	Node* pTail = nullptr;
	for (int i = 0; i < 6; i++) { // 6개중 하나에 탄알을 넣음
		pNew = new Node;
		if (i == rand_number) { // 설정해준 random넘버일 때 탄환을 넣음
			if (i == 0) { // Head가 없을 때 Head와 Tail설정
				pNew->setData(1); // 총알이 있는곳에는 데이터 1을 넣어줌
				pHead = pNew;
				pTail = pNew;
			}
			else { // Head가 아닌곳에 총알을 넣을때
				pNew->setData(1); // 총알이 있는곳에 데이터 1을 넣어줌
				pTail->setNext(pNew); 
				pNew->setPrev(pNew);
				pTail = pNew;
			}
		}
		else {
			if (i == 0) { // head일때 head Tail설정
				pHead = pNew;
				pTail = pNew;
			}
			else { // tail과 next와 prev를 설정해줌
				pTail->setNext(pNew);
				pNew->setPrev(pNew);
				pTail = pNew;
			}
		}
	}
	pTail->setNext(pHead); // 마지막노드의 다음값을 head값으로
	pHead->setPrev(pTail); // head노드의 뒤를 마지막노드로
}

LL::~LL() { // 소멸자
	Node* pTemp = pHead->getNext(); // Temp값은 Head의 다음값으로
	pHead->setNext(nullptr); // Head의 next값을 null로 만들어서 circle을 끊어버림
	while (pTemp) { // nullptr을 만날때까지 동적할당해제
		pHead = pTemp->getNext();
		delete pTemp;//동적할당 해제
		pTemp = pHead;
	}

	_CrtDumpMemoryLeaks();
}

void LL::setHead(Node* pTemp) { // 값을 변경해 주는 매소드
	pHead = pTemp;
}

Node* LL::getHead() {// 값을 반환해 주는 매소드
	return pHead;
}

int LL::shoot() { // 총알을 발사하는 매소드
	bool is_bullet = pHead->getData(); //불렛을 발사해서 총알의 값을 저장
	Node* pTemp = pHead;
	pHead = pHead->getNext(); // 다음값으로 이동
	return is_bullet; // 총알값을 반환
}

void LL::rotate() { // 리볼버의 총알을 돌리는 매소드
	srand(time(NULL)); // 랜덤값을 시드로 생성
	int number = rand() % 6; // 랜덤값 설정
	for (int i = 0; i <= number; i++) { //랜덤 값 만큼 Head를 돌림
		pHead = pHead->getNext();
	}
}

void LL::print() { 
	Node* pTemp = pHead->getNext();
	std::cout << pHead->getData() << '\n';
	while (pTemp != pHead) {
		std::cout << pTemp->getData() << '\n';
		pTemp = pTemp->getNext();
	}
}