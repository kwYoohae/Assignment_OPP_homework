#pragma once

class Node {
private:
	int data;
	Node* pNext;
	Node* pPrev;
public:
	Node();//생성자
	~Node(); // 소멸자
	
	int getData(); // 값을 반환하는 매소드
	Node* getNext(); // 값을 반환하는 매소드
	Node* getPrev(); // 값을 반환하는 매소드

	void setData(int _Data); // 값을 변경하는 매소드
	void setNext(Node* pTemp); // 값을 변경하는 매소드
	void setPrev(Node* pTemp); // 값을 변경하는 매소드
};