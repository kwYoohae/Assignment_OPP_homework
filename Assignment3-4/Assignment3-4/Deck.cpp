#include "Deck.h"
#include <iostream>

deck::deck() { // deck�� ������
	pHead = nullptr; // phead�ʱ�ȭ
	pTail = nullptr; // pTail�ʱ�ȭ
	char card[5]; // ī�� ���� ����
	for (int i = 0; i < 4; i++) { // �����̵�, Ŭ�ι�, ��Ʈ, ���̾Ƹ�带 �Է��ؾ� ������ 4�� �ݺ����� ����
		for (int j = 1; j <= 13; j++) { // �� 13���� ī�� �̹ǿ� 13���� ����
			memset(card, NULL, 5); // card���� �ʱ�ȭ
			if (i == 0) //ī�� ���� ����
				card[0] = 'C';
			if (i == 1)//ī�� ���� ����
				card[0] = 'S';
			if (i == 2)//ī�� ���� ����
				card[0] = 'D';
			if (i == 3)//ī�� ���� ����
				card[0] = 'H';
			if (j == 1) // 1�� �� 'A'�Է�
				card[1] = 'A';
			else if (j == 10) { // 10�� �� '1', '0' ���ʷ��Է�
				card[1] = '1';
				card[2] = '0';
			}
			else if (j == 11) { // 11�� �� J�Է�
				card[1] = 'J';
			}
			else if (j == 12) { // 12�� �� Q�Է�
				card[1] = 'Q';
			}
			else if (j == 13) { // 13�� �� K�Է�
				card[1] = 'K';
			} 
			else { // �������� ���� �׳� �����̹Ƿ� j���� '0'�� ���Ѱ� �Է�
				card[1] = j + '0';
			}
			node* pNew = new node; // node����
			pNew->setCard(card); // ī���� �� ����
			if (i == 0 && j == 1) { // ù��° ���� pHead�� pTail�� ����
				pHead = pNew;
				pTail = pNew;
			}
			else {// �ι�° ��� ���ʹ� pHead�� ������ (stack)
				pNew->setNext(pHead); // ���ο� ���� pHead�� Next�� ����Ŵ
				pHead = pNew; // ���ο� ��尡 Head�� ��
			}
		}
	}
	
}

deck::~deck() { // �Ҹ���

}

void deck::setHead(node* pTemp) { //Head�� ���� �ٲٴ� �żҵ�
	pHead = pTemp;
}

void deck::setTail(node* pTemp) { //Tail�� ���� �ٲٴ� �żҵ�
	pTail = pTemp;
}

node* deck::getHead() { // Head�� ���� ��ȯ�ϴ� �żҵ�
	return pHead;
}

node* deck::getTail(){ //Tail�� ���� ��ȯ�ϴ� �żҵ�
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

void deck::shuffle(int number, player *Player, discard *Discard) { //���� ���� �żҵ�
	srand(time(NULL)); // �ð� �õ�� ����ð�����
		node* discard_head = Discard->getHead(); // discard�� Head�� ����Ű�� ���
		while (discard_head) { // discard_head������ null�϶�����
			node* pNew = new node; // ���ο� ��� ����
			pNew->setCard(discard_head->getCard()); // ���ο� ��忡 discard_head�� �����͸� ����
			pNew->setNext(pHead); // ���� ���ο� ��带 ���� (���ο���� ���� head�� ����Ŵ)
			pHead = pNew; // ���� ���ο� ��带 ���� (���ο� ���� head�� �ȴ�)
			discard_head = discard_head->getNext(); // discard_head�� ���� ���� �̵�
		}
		Discard->delete_card(); // ��� ���� ���� ������ �ڴ� discard_head�� �׿��� ī����� ����
		for (int i = 0; i < number; i++) {
			int count = 0; // random���� ������ ���� �󸶳��Ǵ����� count���ִ� ����
			Player->delete_card(); // Player�� ī�带 ����
			node* pTemp = pHead; // pTemp���� pHead�� ����Ŵ
			node* pNew = new node; // ���ο� ��� ����
			player player_temp; // player ��ü ����
			node* pPlayer; // pPlayer��� ����
			player_temp.delete_card(); // playet_temp��ü�� �ִ� ��� ī����� ����
			pNew->setCard(pTemp->getCard()); // ���ο� ��ü�� ���� ���� pTemp�� ����Ű�� �ִ� ����� ������ ���� ����
			player_temp.setHead(pNew); // player_temp�� �����ؼ� head�� tail�� �����Ƿ� ���ο� ���� ����
			player_temp.setTail(pNew); // tail ��� ����
			pTemp = pTemp->getNext(); // pTemp�� ������ ����Ű�� ���� �̵�
			while (pTemp) { // pTemp�� nullptr�� ���� �� ����
				int random_number = rand() % 53; // �������� �� ���� ����
				for (int j = 0; j < random_number; j++) {
					if (!pTemp) // pTemp�� nullptr���̸� �ݺ��� ����
						break;
					pNew = new node; // ���ο� ��ü ����
					pNew->setCard(pTemp->getCard()); // ���ο� ��ü�� pTemp�� ����Ű�� �ִ� ����� ������ ���� ����
					pNew->setNext(player_temp.getHead()); // ���ο� ��ü�� ����Ű�� ��� ����
					pTemp = pTemp->getNext(); // pTemp�� �״��� ���� �̵�
					player_temp.setHead(pNew); //player_temp�� �ص带 ���ο� ��ä�� ����
					count++; //�󸶳� �����ߴ��� count
				}
				pPlayer = player_temp.getHead();// pPlayer�� player_temp�� �ص带 ����Ŵ
				if (Player->getHead() == nullptr) { // ���� Player�� ��尡 nullptr���̸� head�� ��������
					pNew = new node; //���ο� ��� ����
					pNew->setCard(pPlayer->getCard()); // player_temp�� �ִ� pPlayer�� ����Ű�� ��ü���� ���ο� ��忡 ����
					Player->setHead(pNew); // Player�� head���� �����Ƿ� ���ο� ��ü�� ����
					Player->setTail(pNew); // Player�� tail���� �����Ƿ� ���ο� ��ü�� ���� 
					pPlayer = pPlayer->getNext(); // pPlayer�� ���� ����Ű�� ������ �̵�
				}
				for (int j = 0; j < count; j++) {
					pNew = new node; // ���ο� ��ü ����
					pNew->setCard(pPlayer->getCard()); // pPlayer��尡 ������ �ִ� ������ ���� ���ο� ��忡 ����
					pNew->setNext(Player->getHead()); // ���ο� ����� ���� ���� ����
					pPlayer = pPlayer->getNext(); // pPlayer�� ���� ������ �̵� 
					Player->setHead(pNew); // Player�� Head�� ���ο� ��ü�� ����
				}
				count = 0; // count�� �ʱ�ȭ
				player_temp.delete_card(); //player_temp�� �ִ� ��� �� ����
			}
			pTemp = pHead; //pTemp�� ���� pHead�� ����Ŵ
			pPlayer = Player->getHead(); // pPlayer�� Player�� pHead�� ����Ŵ
			while(pTemp) { // pTemp�� nullptr�� �� ����
				pTemp->setCard(pPlayer->getCard()); // ���� pPlayer�� ī�尪�� ����
				pTemp = pTemp->getNext(); // pTemp�� ���������� �̵�
				pPlayer = pPlayer->getNext(); // pPlayer�� ���������� �̵�
			}
			player_temp.delete_card(); //player_temp�� �ִ� ��� �� ����
		}
}

void deck::hit_player(player* Player, Dealer* dealer, discard* Discard) { //player���� ī�带 �ִ� �żҵ�
	node* pTemp = pHead; // pHead�� ����Ű�� ��� ����
	node* pNew = new node; // ���ο� ��� ����
	if (Player->getHead() == nullptr) { // ���� Player�� �ƹ��� ī�嵵 ������ ���� ���� ��
		Player->setHead(pNew); // Player�� head���� ���ο� ���� ����
		Player->setTail(pNew); // Player�� Tail���� ���ο� ���� ����
		pNew->setCard(pTemp->getCard()); // ���ο� ����� ī�� ���� ������ ������(pTemp)
		pHead = pHead->getNext(); // pHead�� �״��� ������ �ű�
		delete pTemp; // pTemp��带 �����Ҵ� ����
		
	}
	else {
		pNew->setCard(pTemp->getCard()); //���ο� ��ü�� ���� ������ ������(pTemp)
		Player->getTail()->setNext(pNew); // Tail�� ���� ���� pNew�� ���� (queue)
		Player->setTail(pNew); // Tail�� ���ο� ��ü�� ����
		pHead = pHead->getNext(); // ���� Head�� �� ���� ������ ����
		delete pTemp; // pTemp�� �޸� �Ҵ� ����
	}
}

void deck::hit_Dealer(player* Player, Dealer* dealer, discard* Discard) { // Dealer���� ī�带 �ִ� �żҵ�
	node* pTemp = pHead; // pTemp�� pHead�� ����Ŵ
	node* pNew = new node; // ���ο� ��� ����
	if (dealer->getHead() == nullptr) { // dealer�� Head�� ������� �� 
		dealer->setHead(pNew); // dealer�� Head�� ���ο� ���� ����
		dealer->setTail(pNew); // dealer�� Tail�� ���ο� ���� ����
		pNew->setCard(pTemp->getCard()); // ���ο� ����� ���� pTemp(deck)�� ī�� ������ ����
		pHead = pHead->getNext(); // deck�� ��� ���� ���� ������ ����
		delete pTemp; // pTemp�� �� ����


	}
	else {
		pNew->setCard(pTemp->getCard()); // ���ο� ��忡 deck�� ���� ī�� ���� ���� �Ǽ���
		dealer->getTail()->setNext(pNew); // ������ tail�� Next���� ���ο� ���� ����
		dealer->setTail(pNew); // dealer�� tail���� ���ο� ���� ����
		pHead = pHead->getNext(); // deck�� head���� ���������� ����
		delete pTemp; // pTemp��带 �޸��Ҵ� ����
	}
}

int deck::deck_count() { // ���� ī�� ���ڸ� �����ִ� �żҵ�
	int count = 0; // ī��Ʈ�ϴ� ���� ����
	node* pTemp = pHead; // pTemp�� pHead�� ����Ŵ
	while (pTemp) { // pTemp�� nullptr �϶�����
		pTemp = pTemp->getNext(); //pTemp�� Next������ �̵�
		count++; // count�� ������
	}
	return count; // ī�带 ���� ���� ��ȯ
}

void deck::delete_deck() { // deck�� �ִ� ī�带 ���� ����
	node* pTemp; // node ������ ���� ����
	while (pHead) { // pHead�� nullptr�� ������
		pTemp = pHead; // pTemp�� pHead�� ����Ŵ
		pHead = pHead->getNext(); // pHead�� ���� ������ �̵�
		delete pTemp;//pTemp�� �޸� �Ҵ� ����
	}
	pHead = nullptr; // ��� ���� ����� pHead�� nullptr�� �ʱ�ȭ
	pTail = nullptr; // ��� ���� ����� pTail�� nullptr�� �ʱ�ȭ
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