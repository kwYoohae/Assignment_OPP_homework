#pragma once

class node{
private:
	char card[5];
	node* pNext;
	node* pPrev;
public:
	node(); //생성자
	~node(); //소멸자
	
	node* getNext(); // 값을 반환하는 매소드
	node* getPrev(); // 값을 반환하는 매소드
	char* getCard(); // 값을 반환하는 매소드

	void setPrev(node* pTemp); // 값을 변경하는 매소드
	void setNext(node* pTemp); // 값을 변경하는 매소드
	void setCard(char* data); // 값을 변경하는 매소드
};