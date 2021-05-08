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
	deck();
	~deck();

	node* getHead();
	node* getTail();
	void setHead(node* pTemp);
	void setTail(node* pTemp);

	void print();
	void delete_deck();

	void shuffle(int number, player *Player, discard *Discard);

	void hit_player(player* Player, Dealer* dealer, discard* Discard);
	void hit_Dealer(player* Player, Dealer* dealer, discard* Discard);
	int deck_count();
};