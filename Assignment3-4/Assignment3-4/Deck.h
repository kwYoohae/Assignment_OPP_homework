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
	deck(); //������
	~deck(); // �Ҹ���

	node* getHead(); //���� ��ȯ�ϴ� �żҵ�
	node* getTail(); // ���� ��ȯ�ϴ� �żҵ�
	void setHead(node* pTemp); // ���� �����ϴ� �żҵ�
	void setTail(node* pTemp); // ���� �����ϴ� �żҵ�

	void print(); 
	void delete_deck(); // ���� ī�带 �����ϴ� �żҵ�

	void shuffle(int number, player *Player, discard *Discard); //ī�带 ���� �żҵ�

	void hit_player(player* Player, Dealer* dealer, discard* Discard); // player���� ���� ī�带 �������ִ� �żҵ�
	void hit_Dealer(player* Player, Dealer* dealer, discard* Discard); // �������� ���� ī�带 �������ִ� �żҵ�
	int deck_count(); // ���� ������ �ִ� ī���� ������ ���� �żҵ�

	void move_PD(discard* Discard, player* Player, Dealer* dealer); // ������ �÷��̾��� ī�带 discard_tray�� ������ �żҵ�
};