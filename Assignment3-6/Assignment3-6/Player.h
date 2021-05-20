#pragma once
#include "block_horse.h"
#include "Yut.h"
#include "move.h"
#include "board1D.h"
class player {
private:
	horse* pHead;
	horse* pTail;
public:
	player();
	~player();

	horse* getHead();
	horse* getTail();

	void setHead(horse* pTemp);
	void setTail(horse* pTemp);

	void inster_name(char ch);

	void print_horse();
	int is_exisist(block* pBoard, horse* pHorse, block* short_center1, block* short_center2);

	void caught_horse(block* pTemp, horse* pHorse);
	void run_horse(block* pBlock, horse* pHorse);
	void finished_horse(block* pBlock, horse* pHorse);
	int move_horse(int move_number, int select_number, yut* Yut, board* Board, board* Board_short1, board* Board_short2);

	void horse_delete(horse* pHorse);
	bool is_hand();

	void delete_player();
	bool possible_backdo();
};