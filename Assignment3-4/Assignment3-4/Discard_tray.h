#pragma once
#include "Node.h"

class discard {
private:
	node* pHead;
	node* pTail;
public:
	discard(); // 생성자
	~discard(); // 소멸자

	node* getHead(); // 값을 반환하는 매소드
	node* getTail(); // 값을 반환하는 매소드
	void setHead(node* pTemp); // 값을 변경하는 매소드
	void setTail(node* pTemp); // 값을 변경하는 매소드

	void print(); 
	void insert(node* pTemp); // 카드를 넣는 매소드
	void delete_card(); // 모든 카드를 삭제하는 매소드
};