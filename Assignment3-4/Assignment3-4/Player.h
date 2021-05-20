#pragma once
#include "Node.h"
#include "Discard_tray.h"

class player {
private:
	node* pHead;
	node* pTail;
public:
	player(); // 생성자
	~player(); // 소멸자

	node* getHead(); // 값을 반환하는 매소드
	node* getTail(); // 값을 반환하는 매소드

	void setHead(node* pTemp); // 값을 변경하는 매소드
	void setTail(node* pTemp); // 값을 변경하는 매소드

	void print_check(); 
	void print(); // player의 카드를 출력하는 매소드
	void delete_card(); // player의 카드를 삭제하는 매소드
	int sum(); // player가 가지고있는 카드의 합을 구하는 매소드
};