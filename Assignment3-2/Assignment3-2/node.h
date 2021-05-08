#pragma once
#include <iostream>

class node
{
public:
	node(); // 생성자
	~node(); // 소멸자
	int getData(); // 데이터 값 반환
	node* getPrev(); // 이전값 저장 노드
	node* getNext(); // 다음값 저장 노드
	void setData(int number); // 데이터 값 변경 매소드
	void setPrev(node* pNode); // 이전값 변경 매소드
	void setNext(node* pNode); // 다음값 변경 매소드
private: 
	int data; //데이터 저장 변수
	node* pPrev; // 이전값을 알려주는 노드
	node* pNext; // 다음값을 알려주는 노드
};
