#pragma once
#include <iostream>
#include "node.h"

class bst {
private:
	node* root; // root값
	int data; // 데이터값을 저장하는 변수
	int count; // 얼마나 생성되었는지 체크하는 변수 
public:
	bst(); //생성자
	~bst(); // 소멸자
	void Insert(node* pNode); // BST에 삽입하는 매소드
	void setRoot(node* pNode); //root값을 변경하는 매소드
	void setData(int number); // 데이터 값을 변경하는 매소드
	int getData(); // data값을 반환하는 매소드
	node* getRoot(); // root값을 반환하는 매소드
	void Print_Post(node* pNode); // 후위 순회로 출력하는 매소드
	void Print_in(node* pNode); // 중위 순회로 출력하는 매소드
	void Print_Pre(node* pNode); // 전위 순회로 출력하는 매소드
	bool is_Empty(); // BST가 비어있는지 확인하는 매소드
	int Search(int number); // 값을 찾는 매소드
	void Remove_Tree(node* pTemp); // 소멸할 때 메모리 할당 해주는 매소드
};