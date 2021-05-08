#pragma once
#include <iostream>
#include "node.h"
#include "BST.h"


class queue {
private:
	int data; //데이터 저장 변수
	node* pHead; //head값
	node* pTail; // tail값
public:
	queue(); //생성자
	~queue(); //소멸자
	void Print_Queue(); // Queue값을 출력하는 매소드
	void Enqueue(int number,int *count); // 큐를 삽입하는 매소드
	void Dequeue(int number, int *count, bst *Bst); // 큐를 삭제하고 BST에 넣는 매소드
	void All_Dequeue(int *count, bst *Bst); // 모든 큐를 삭제하는 매소드 (모든 값을 BST에 넣는 매소드)
};