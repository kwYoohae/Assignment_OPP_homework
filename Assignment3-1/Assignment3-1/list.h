#pragma once
#include <iostream>
#include "node.h"

using namespace std;

class list {
private:
	node*  pHead; //pHead변수
	node* pTail; //pTail변수
public:
	list(); //생성자
	~list(); //소멸자

	void Insert(char* str , int count); //단어를 넣는 매소드
	void Print(); // 출력하는 매소드
	bool Search_equal(char* str); //같은 값이 있는지 찾는 매소드
	bool backward_word(char* str); // 마지막단어의 마지막글자와 입력단어의 첫번재 글자와 이어지는지 확인하는 매소드
};