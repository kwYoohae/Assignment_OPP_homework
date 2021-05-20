#include "Dealer.h"
#include <iostream>

Dealer::Dealer() { //생성자
	pHead = nullptr;
	pTail = nullptr;
}

Dealer::~Dealer() { // 소멸자

}

void Dealer::setHead(node* pTemp) { //값을 변경하는 매소드
	pHead = pTemp;
}

void Dealer::setTail(node* pTemp) {//값을 변경하는 매소드
	pTail = pTemp;
}

node* Dealer::getHead() {//값을 반환해주는 매소드
	return pHead;
}

node* Dealer::getTail() {//값을 반환해주는 매소드
	return pTail;
}

void Dealer::print_check() {
	int count = 0;
	node* pTemp = pHead;
	while (pTemp) {
		std::cout << pTemp->getCard() << '\n';
		pTemp = pTemp->getNext();
		count++;
	}
	std::cout << "count : " << count << '\n';
}

void Dealer::delete_card() { // 딜러의 카드를 삭제하는 매소드
	node* pTemp;
	while (pHead) { // pHead가 null일때까지 반복
		pTemp = pHead; // pTemp는 pHead를 가리킴
		pHead = pHead->getNext(); // 다음값으로 pHead는 
		delete pTemp; // pTmep를 삭제
	}
	pHead = nullptr; //다삭제후 값 초기화
	pTail = nullptr; // 다삭제후 값 초기화
}

void Dealer::print(bool end) { // 딜러의 카드를 출력
	node* pTemp = pHead;
	if (end) { //게임이 끝나서 비공개 카드를 출력해야되는지 확인
		std::cout << "Dealer Cards :";
		std::cout.width(5);
		while (pTemp) {
			std::cout << pTemp->getCard(); //카드를 출력
			std::cout.width(5);
			pTemp = pTemp->getNext(); // pTemp는 다음값으로
		}
	}
	else { // 게임중이라 딜러의 카드를 미공개로 할떄
		std::cout << "Dealer Cards :";
		std::cout.width(5);
		while (pTemp) {
			if (pTemp == pHead) { // 제일 처음 카드는 ?로 출력
				std::cout << "?";
				std::cout.width(5);
				pTemp = pTemp->getNext();
			} 
			else { // 나머지카드는 그냥 출력
				std::cout << pTemp->getCard();
				std::cout.width(5);
				pTemp = pTemp->getNext();
			}
		}
	}
	std::cout << '\n';
}
 
int Dealer::sum() { // 딜러카드의 합을 세어줄 때 
	int res = 0; // 합을 받는 변수
	int number_A = 0; // A카드의 숫자를 세는 변수
	node* pTemp = pHead;
	while (pTemp) {
		if (pTemp->getCard()[1] == '1' && pTemp->getCard()[2] == '0') // 10카드일 때 10을 넣어줌
			res += 10; 
		else if (pTemp->getCard()[1] == 'K' || pTemp->getCard()[1] == 'J' || pTemp->getCard()[1] == 'Q') // k,j,q는 10을 더해줌
			res += 10;
		else if (pTemp->getCard()[1] == 'A') // A카드는 개수를 세어서 나중에 계산
			number_A++;
		else { // 나머지는 카드에 담긴 숫자만큼 더해줌
			res += pTemp->getCard()[1] - '0';
		}
		pTemp = pTemp->getNext();
	}
	for (int i = 0; i < number_A; i++) { // A카드의 개수만큼 더해줌
		if (res + 11 <= 21) // 현재 합에 11을 더해도 값이 21이 안넘을 때는 11을 더해줌
			res += 11;
		else // 21이넘을 때는 1로 사용
			res += 1;
	}
	return res; // 카드의 합을 반환
}