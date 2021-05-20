#pragma once
#include "Node.h"

class LL
{
public:
	LL();//생성자
	~LL(); // 소멸자

	Node* getHead(); //값을 반환해주는 매소드
	void setHead(Node* pTemp); // 값을 변경하는 매소드

	int shoot(); // 총알을 쏘는 매소드
	void rotate(); // 총알을 돌리는 매소드
	void print();

private:
	Node* pHead;
};

