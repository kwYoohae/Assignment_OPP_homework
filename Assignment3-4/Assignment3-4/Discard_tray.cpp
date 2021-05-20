#include "Discard_tray.h"
#include <iostream>

discard::discard() { //생성자
	pHead = nullptr;
	pTail = nullptr;
}

discard::~discard() { // 소멸자

}

void discard::setHead(node* pTemp) { // 값을 변경해주는 매소드
	pHead = pTemp;
}

void discard::setTail(node* pTemp) {// 값을 변경해주는 매소드
	pTail = pTemp;
}

node* discard::getHead() { //값을 반환해주는 매소드
	return pHead;
}

node* discard::getTail() { // 값을 반환해주는 매소드
	return pTail;
}

void discard::print() { 
	int count = 0;
	node* pTemp = pHead;
	while (pTemp) {
		std::cout << pTemp->getCard() << '\n';
		pTemp = pTemp->getNext();
		count++;
	}
	std::cout << "count : " << count << '\n';
}

void discard::delete_card() { // discard_tray에서 카드를 모두 삭제하는 매소드
	node* pTemp; 
	while (pHead) { // pHead부터 마지막카드까지 반복문을 계속돌림
		pTemp = pHead;
		pHead = pHead->getNext(); // 해드의 다음값으로 
		delete pTemp; // 동적할당해제
	}
	pHead = nullptr; // 모든카드 제거후 해드 초기화
	pTail = nullptr; // 모든카드 제거후 테일 초기화
}

void discard::insert(node* pTemp) { // discard_tary에 카드를 옮길 때
	node* pNew = new node;
	if (pHead == nullptr) { // 해드가 비어있을 떄는 해드와 테일도 설정
		pHead = pNew;
		pTail = pNew;
		pNew->setCard(pTemp->getCard());
	}
	else { // 해드가 비어있지 않을 때는 Next, Prev , Tail설정
		pNew->setCard(pTemp->getCard());
		pTail->setNext(pNew);
		pTail = pNew;
	}
}
