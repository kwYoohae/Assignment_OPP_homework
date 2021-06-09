#pragma once
#include "node.h"
#include "tree_node.h"

class cube_1D
{
private:
	cube_1D* pNext; // 다음값
	cube_1D* pPrev; //이전값
	tree_node* pData; // 가지고있는 tree의 data
	int Rev_number; // 거꾸로 출력하는지 확인하는 변수
public:
	cube_1D(); // 생성자
	~cube_1D(); // 소멸자

	int getRev(); //값을 반환하는 매소드
	tree_node* getData(); //값을 반환하는 매소드
	cube_1D* getNext(); //값을 반환하는 매소드
	cube_1D* getPrev(); //값을 반환하는 매소드

	void setRev(int temp);// 값을 변경하는 매소드
	void setData(tree_node* pTemp);// 값을 변경하는 매소드
	void setNext(cube_1D* pTemp);// 값을 변경하는 매소드
	void setPrev(cube_1D* pTemp);// 값을 변경하는 매소드

};

