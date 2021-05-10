#include "Deck.h"
#include <iostream>

deck::deck() { // deck의 생성자
	pHead = nullptr; // phead초기화
	pTail = nullptr; // pTail초기화
	char card[5]; // 카드 변수 생성
	for (int i = 0; i < 4; i++) { // 스페이드, 클로버, 하트, 다이아몬드를 입력해야 함으로 4번 반복문을 실행
		for (int j = 1; j <= 13; j++) { // 총 13장의 카드 이므요 13번을 돈다
			memset(card, NULL, 5); // card변수 초기화
			if (i == 0) //카드 무늬 결정
				card[0] = 'C';
			if (i == 1)//카드 무늬 결정
				card[0] = 'S';
			if (i == 2)//카드 무늬 결정
				card[0] = 'D';
			if (i == 3)//카드 무늬 결정
				card[0] = 'H';
			if (j == 1) // 1일 때 'A'입력
				card[1] = 'A';
			else if (j == 10) { // 10일 떄 '1', '0' 차례로입력
				card[1] = '1';
				card[2] = '0';
			}
			else if (j == 11) { // 11일 때 J입력
				card[1] = 'J';
			}
			else if (j == 12) { // 12일 때 Q입력
				card[1] = 'Q';
			}
			else if (j == 13) { // 13일 때 K입력
				card[1] = 'K';
			} 
			else { // 나머지일 떄는 그냥 숫자이므로 j에서 '0'을 더한값 입력
				card[1] = j + '0';
			}
			node* pNew = new node; // node생성
			pNew->setCard(card); // 카드의 갑 설정
			if (i == 0 && j == 1) { // 첫번째 노드는 pHead와 pTail을 가짐
				pHead = pNew;
				pTail = pNew;
			}
			else {// 두번째 노드 부터는 pHead만 움직임 (stack)
				pNew->setNext(pHead); // 새로운 노드는 pHead를 Next로 가리킴
				pHead = pNew; // 새로운 노드가 Head가 됨
			}
		}
	}
	
}

deck::~deck() { // 소멸자

}

void deck::setHead(node* pTemp) { //Head의 값을 바꾸는 매소드
	pHead = pTemp;
}

void deck::setTail(node* pTemp) { //Tail의 값을 바꾸는 매소드
	pTail = pTemp;
}

node* deck::getHead() { // Head의 값을 반환하는 매소드
	return pHead;
}

node* deck::getTail(){ //Tail의 값을 반환하는 매소드
	return pTail;
}

void deck::print() { 
	int count = 0;
	node* pTemp = pHead;
	while (pTemp) {
		std::cout << pTemp->getCard() << '\n';
		pTemp = pTemp->getNext();
		count++;
	}
	std::cout << "count : " << count << '\n';
}

void deck::shuffle(int number, player *Player, discard *Discard) { //덱을 섞는 매소드
	srand(time(NULL)); // 시간 시드는 현재시간으로
		node* discard_head = Discard->getHead(); // discard의 Head를 가리키는 노드
		while (discard_head) { // discard_head변수가 null일때까지
			node* pNew = new node; // 새로운 노드 생성
			pNew->setCard(discard_head->getCard()); // 새로운 노드에 discard_head의 데이터를 저장
			pNew->setNext(pHead); // 덱에 새로운 노드를 쌓음 (새로운노드는 덱의 head를 가리킴)
			pHead = pNew; // 덱에 새로운 노드를 쌓음 (새로운 노드는 head가 된다)
			discard_head = discard_head->getNext(); // discard_head는 다음 노드로 이동
		}
		Discard->delete_card(); // 모든 값을 덱에 복사한 뒤는 discard_head에 쌓였던 카드들을 제거
		for (int i = 0; i < number; i++) {
			int count = 0; // random으로 복사한 값이 얼마나되는지를 count해주는 변수
			Player->delete_card(); // Player의 카드를 삭제
			node* pTemp = pHead; // pTemp노드는 pHead를 가리킴
			node* pNew = new node; // 새로운 노드 생성
			player player_temp; // player 객체 생성
			node* pPlayer; // pPlayer노드 생성
			player_temp.delete_card(); // playet_temp객체에 있는 모든 카드들을 삭제
			pNew->setCard(pTemp->getCard()); // 새로운 객체는 현재 덱에 pTemp가 가리키고 있는 노드의 데이터 값을 저장
			player_temp.setHead(pNew); // player_temp는 삭제해서 head와 tail이 없으므로 새로운 노드로 설정
			player_temp.setTail(pNew); // tail 노드 설정
			pTemp = pTemp->getNext(); // pTemp는 다음을 가리키는 노드로 이동
			while (pTemp) { // pTemp가 nullptr을 만날 때 까지
				int random_number = rand() % 53; // 랜덤으로 떌 숫자 결정
				for (int j = 0; j < random_number; j++) {
					if (!pTemp) // pTemp가 nullptr값이면 반복문 종료
						break;
					pNew = new node; // 새로운 객체 생성
					pNew->setCard(pTemp->getCard()); // 새로운 객체에 pTemp가 가리키고 있는 노드의 데이터 값을 저장
					pNew->setNext(player_temp.getHead()); // 새로운 객체의 가리키는 노드 설정
					pTemp = pTemp->getNext(); // pTemp는 그다음 노드로 이동
					player_temp.setHead(pNew); //player_temp의 해드를 새로운 객채로 변경
					count++; //얼마나 저장했는지 count
				}
				pPlayer = player_temp.getHead();// pPlayer는 player_temp의 해드를 가리킴
				if (Player->getHead() == nullptr) { // 만약 Player의 헤드가 nullptr값이면 head를 설정해줌
					pNew = new node; //새로운 노드 생성
					pNew->setCard(pPlayer->getCard()); // player_temp에 있는 pPlayer가 가리키는 객체값을 새로운 노드에 저장
					Player->setHead(pNew); // Player의 head값이 없으므로 새로운 객체로 지정
					Player->setTail(pNew); // Player의 tail값이 없으므로 새로운 객체로 지정 
					pPlayer = pPlayer->getNext(); // pPlayer는 다음 가리키는 곳으로 이동
				}
				for (int j = 0; j < count; j++) {
					pNew = new node; // 새로운 객체 생성
					pNew->setCard(pPlayer->getCard()); // pPlayer노드가 가지고 있는 데이터 값을 새로운 노드에 저장
					pNew->setNext(Player->getHead()); // 새로운 노드의 다음 값을 설정
					pPlayer = pPlayer->getNext(); // pPlayer는 다음 값으로 이동 
					Player->setHead(pNew); // Player의 Head를 새로운 객체로 변경
				}
				count = 0; // count값 초기화
				player_temp.delete_card(); //player_temp에 있는 모든 값 삭제
			}
			pTemp = pHead; //pTemp는 덱의 pHead를 가리킴
			pPlayer = Player->getHead(); // pPlayer는 Player의 pHead를 가리킴
			while(pTemp) { // pTemp가 nullptr일 때 까지
				pTemp->setCard(pPlayer->getCard()); // 덱에 pPlayer의 카드값을 저장
				pTemp = pTemp->getNext(); // pTemp는 다음값으로 이동
				pPlayer = pPlayer->getNext(); // pPlayer도 다음값으로 이동
			}
			player_temp.delete_card(); //player_temp에 있는 모든 값 삭제
		}
}

void deck::hit_player(player* Player, Dealer* dealer, discard* Discard) { //player에게 카드를 주는 매소드
	node* pTemp = pHead; // pHead를 가리키는 노드 생성
	node* pNew = new node; // 새로운 노드 생성
	if (Player->getHead() == nullptr) { // 만약 Player가 아무런 카드도 가지고 있지 않을 때
		Player->setHead(pNew); // Player의 head값을 새로운 노드로 결정
		Player->setTail(pNew); // Player의 Tail값을 새로운 노드로 결정
		pNew->setCard(pTemp->getCard()); // 새로운 노드의 카드 값을 덱에서 가져옴(pTemp)
		pHead = pHead->getNext(); // pHead는 그다음 값으로 옮김
		delete pTemp; // pTemp노드를 동적할당 해제
		
	}
	else {
		pNew->setCard(pTemp->getCard()); //새로운 객체의 값을 덱에서 가져옴(pTemp)
		Player->getTail()->setNext(pNew); // Tail의 다음 값을 pNew로 설정 (queue)
		Player->setTail(pNew); // Tail을 새로운 객체로 설정
		pHead = pHead->getNext(); // 덱의 Head를 그 다음 값으로 변경
		delete pTemp; // pTemp는 메모리 할당 해제
	}
}

void deck::hit_Dealer(player* Player, Dealer* dealer, discard* Discard) { // Dealer에게 카드를 주는 매소드
	node* pTemp = pHead; // pTemp는 pHead를 가리킴
	node* pNew = new node; // 새로운 노드 생성
	if (dealer->getHead() == nullptr) { // dealer의 Head가 비어있을 때 
		dealer->setHead(pNew); // dealer의 Head를 새로운 노드로 설정
		dealer->setTail(pNew); // dealer의 Tail를 새로운 노드로 설정
		pNew->setCard(pTemp->getCard()); // 새로운 노드의 값을 pTemp(deck)의 카드 값으로 설정
		pHead = pHead->getNext(); // deck의 헤드 값을 다음 값으로 변경
		delete pTemp; // pTemp의 값 삭제


	}
	else {
		pNew->setCard(pTemp->getCard()); // 새로운 노드에 deck의 맨위 카드 값을 값을 ㅗ설정
		dealer->getTail()->setNext(pNew); // 딜러의 tail의 Next값을 새로운 노드로 설정
		dealer->setTail(pNew); // dealer의 tail값을 새로운 노드로 설정
		pHead = pHead->getNext(); // deck의 head값을 다음값으로 설정
		delete pTemp; // pTemp노드를 메모리할당 해제
	}
}

int deck::deck_count() { // 덱의 카드 숫자를 세어주는 매소드
	int count = 0; // 카운트하는 변수 생성
	node* pTemp = pHead; // pTemp는 pHead를 가리킴
	while (pTemp) { // pTemp가 nullptr 일때까지
		pTemp = pTemp->getNext(); //pTemp는 Next값으로 이동
		count++; // count를 더해줌
	}
	return count; // 카드를 더한 값을 반환
}

void deck::delete_deck() { // deck에 있는 카드를 전부 삭제
	node* pTemp; // node 포인터 변수 생성
	while (pHead) { // pHead가 nullptr일 때까지
		pTemp = pHead; // pTemp는 pHead를 가리킴
		pHead = pHead->getNext(); // pHead는 다음 값으로 이동
		delete pTemp;//pTemp의 메모리 할당 해제
	}
	pHead = nullptr; // 모든 값을 지우면 pHead는 nullptr로 초기화
	pTail = nullptr; // 모든 값을 지우면 pTail은 nullptr로 초기화
}

void deck::move_PD(discard* Discard, player* Player, Dealer* dealer) {
	node* pTemp = Player->getHead();
	while (pTemp) {
		Discard->insert(pTemp);
		pTemp = pTemp->getNext();
	}
	pTemp = dealer->getHead();
	while (pTemp) {
		Discard->insert(pTemp);
		pTemp = pTemp->getNext();
	}
}