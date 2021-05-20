#pragma once
#include "Node.h"
#include "Discard_tray.h"
#include "Player.h"
#include "Dealer.h"

class deck {
private:
	node* pHead;
	node* pTail;
public:
	deck(); //생성자
	~deck(); // 소멸자

	node* getHead(); //값을 반환하는 매소드
	node* getTail(); // 값을 반환하는 매소드
	void setHead(node* pTemp); // 값을 변경하는 매소드
	void setTail(node* pTemp); // 값을 변경하는 매소드

	void print(); 
	void delete_deck(); // 덱의 카드를 삭제하는 매소드

	void shuffle(int number, player *Player, discard *Discard); //카드를 섞는 매소드

	void hit_player(player* Player, Dealer* dealer, discard* Discard); // player에게 덱의 카드를 나누어주는 매소드
	void hit_Dealer(player* Player, Dealer* dealer, discard* Discard); // 딜러에게 덱의 카드를 나누어주는 매소드
	int deck_count(); // 덱이 가지고 있는 카드의 개수를 새는 매소드

	void move_PD(discard* Discard, player* Player, Dealer* dealer); // 딜러와 플레이어의 카드를 discard_tray에 보내는 매소드
};