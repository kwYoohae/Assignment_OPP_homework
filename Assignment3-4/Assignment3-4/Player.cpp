#include "Player.h"
#include <iostream>

player::player() { // 생성자
	pHead = nullptr;
	pTail = nullptr;
}

player::~player() { //소멸자

}

void player::setHead(node* pTemp) { // 값을 변경하는 매소드
	pHead = pTemp;
}

void player::setTail(node* pTemp) { // 값을 변경하는 매소드
	pTail = pTemp;
}

node* player::getHead() { // 값을 반환하는 매소드
	return pHead;
}

node* player::getTail() { // 값을 반환하는 매소드
	return pTail;
}

void player::print_check() {
	int count = 0;
	node* pTemp = pHead;
	while (pTemp) {
		std::cout << pTemp->getCard() << '\n';
		pTemp = pTemp->getNext();
		count++;
	}
	std::cout << "count : " << count << '\n';
}

void player::delete_card() { // 카드를 삭제하는 매소드
	node* pTemp;
	while (pHead) { // pHead부터 마지막 카드까지
		pTemp = pHead; 
		pHead = pHead->getNext(); //pHead는 계속이동
		delete pTemp; // 동적할당해제
	}
	pHead = nullptr; // 모든카드삭제후 해드 초기화
	pTail = nullptr; // 모든카드 삭제후 테일 초기화
}

void player::print() { // player가 받은 카드 출력
	std::cout << "Player Cards :";
	std::cout.width(5);
	node* pTemp = pHead; 
	while (pTemp) { // pTemp의 값이 nullptr될때까지 반복
		std::cout << pTemp->getCard();; // 카드를 출력
		std::cout.width(5);
		pTemp = pTemp->getNext(); // 다음값으로
	}
	std::cout << '\n';
}

int player::sum() { // player의 카드의 합을 반환하는 매소드
	int res = 0; // 카드의 합을 저장하는 변수
	int number_A = 0; // A카드를 받은 횟수를 카운트하는 변수
	node* pTemp = pHead;
	while (pTemp) {
		if (pTemp->getCard()[1] == '1' && pTemp->getCard()[2] == '0') // 10카드를 받을때는 10을 더해줌
			res += 10;
		else if (pTemp->getCard()[1] == 'K' || pTemp->getCard()[1] == 'J' || pTemp->getCard()[1] == 'Q') // j,k,q를 받을 떄는 10을 더해줌
			res += 10;
		else if (pTemp->getCard()[1] == 'A') // 에이스 카드를 받을 때 개수를 세어줌
			number_A++;
		else { // 나머지 카드는 나오는 숫자대로 더해줌
			res += pTemp->getCard()[1] - '0'; 
		}
		pTemp = pTemp->getNext(); // 계속다음카드로
	}
	for (int i = 0; i < number_A; i++) {
		if (res + 11 <= 21) // 총합의 11을 더했을 때 21보다 작으면 11로 에이스를 더해줌
			res += 11;
		else // 아니면 1을더해줌
			res += 1;
	}
	return res; // 카드의 합 반환
}