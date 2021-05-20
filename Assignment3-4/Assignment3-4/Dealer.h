#pragma once
#include "Node.h"
#include "Discard_tray.h"

class Dealer {
private:
	node* pHead;
	node* pTail;
public:
	Dealer(); // 생성자
	~Dealer(); // 소멸자

	node* getHead(); //값을 반환하는 매소드
	node* getTail(); // 값을 반환하는 매소드

	void setHead(node* pTemp); // 값을 변경하는 매소드
	void setTail(node* pTemp); // 값을 변경하는 매소드

	void print(bool end); // 값을 출력하는 매소드
	void print_check(); 
	void delete_card(); // 카드를 삭제하는 매소드
	int sum(); // 카드의 합을 세어주는 매소드
};