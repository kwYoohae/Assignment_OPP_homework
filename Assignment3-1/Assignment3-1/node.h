#pragma once
#include <iostream>

using namespace std;

class node {
private:
	char data[20]; //단어를 저장하는 변수
	node* pPrev; //이전 값을 가리키는 변수
	node* pNext; //다음 값을 가리키는 변수
public:
	node();//생성자
	~node();//소멸자

	void setData(char* str); //privat변수를 사용할 수 있게 하는 매소드(값을 변경)
	void setNext(node* pNode);//privat변수를 사용할 수 있게 하는 매소드(값을 변경)
	void setPrev(node* pNode);//privat변수를 사용할 수 있게 하는 매소드(값을 변경)
	char* getData();//privat변수를 사용할 수 있게 하는 매소드(값을 가져옴return)
	node* getNext();//privat변수를 사용할 수 있게 하는 매소드(값을 가져옴return)
	node* getPrev();//privat변수를 사용할 수 있게 하는 매소드(값을 가져옴return)
};