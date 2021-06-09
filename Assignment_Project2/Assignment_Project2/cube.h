#pragma once
#include "node.h"
#include "cube_1D.h"
#include "tree.h"
class cube
{
private:
	node* pHead; // 큐브의 head값
	cube_1D* Row; // 출력하는 row값들의 이름의 집합
	cube_1D* Column; // 출력하는 column값들의 이름의 집합
	cube_1D* Height; // 출력하는 height값들의 이름의 집합
public:
	cube(); // 생성자
	~cube(); // 소멸자

	node* getHead(); // 값을반환하는 매소드
	cube_1D* getRow();// 값을반환하는 매소드
	cube_1D* getColumn();// 값을반환하는 매소드
	cube_1D* getHeight();// 값을반환하는 매소드

	void setHead(node* pTemp);// 값을 변경하는 매소드
	void setRow(cube_1D* pTemp);// 값을 변경하는 매소드
	void setColumn(cube_1D* pTemp);// 값을 변경하는 매소드
	void setHeight(cube_1D* pTemp);// 값을 변경하는 매소드
	void Make_Cube(int p, int l, int t); // 큐브를 만드는 매소드
	void Make_View(tree* Time, tree* Location, tree* Product); // view큐브의 계층을 합쳐주는 매소드
	void Make_tree(tree* Time, tree* Location, tree* Product ,int product_number, int location_number, int time_number); // tree(cube_1d)를 만드는 매소드
	void copyData(cube* raw); // 데이터를 복사하는 매소드
	void WriteLog(char* command); //  log를 적는 매소드
	void WriteError(char* command); // error메시지를 적는 매소드
	bool Rotate(char* command); // rotate를 하는 매소드

	node* (node::*pRight)() = &node::getCnext; // 함수포인터 값 초기화 및 선언
	node*(node::*pLeft)() = &node::getCprev;// 함수포인터 값 초기화 및 선언
	node* (node::* pUp)() = &node::getHprev;// 함수포인터 값 초기화 및 선언
	node*(node::*pDown)() = &node::getHnext;// 함수포인터 값 초기화 및 선언
	node*(node::*pIn)() = &node::getRprev;// 함수포인터 값 초기화 및 선언
	node*(node::*pOut)() = &node::getRnext;// 함수포인터 값 초기화 및 선언
	void (node::*setRight)(node* pTemp) = &node::setCnext;// 함수포인터 값 초기화 및 선언
	void (node::*setLeft)(node* pTemp) = &node::setCprev;// 함수포인터 값 초기화 및 선언
	void (node::*setUp)(node* pTemp) = &node::setHprev;// 함수포인터 값 초기화 및 선언
	void (node::*setDown)(node* pTemp) = &node::setHnext;// 함수포인터 값 초기화 및 선언
	void (node::*setIn)(node* pTemp) = &node::setRprev;// 함수포인터 값 초기화 및 선언
	void (node::*setOut)(node* pTemp) = &node::setRnext;// 함수포인터 값 초기화 및 선언

	cube_1D* (cube::*pRow)() = &cube::getRow;// 함수포인터 값 초기화 및 선언
	cube_1D* (cube::* pColumn)() = &cube::getColumn;// 함수포인터 값 초기화 및 선언
	cube_1D* (cube::* pHeight)() = &cube::getHeight;// 함수포인터 값 초기화 및 선언
	void (cube::* pRow_set)(cube_1D* pTemp) = &cube::setRow;// 함수포인터 값 초기화 및 선언
	void (cube::* pColumn_set)(cube_1D* pTemp) = &cube::setColumn;// 함수포인터 값 초기화 및 선언
	void (cube::* pHeight_set)(cube_1D* pTemp) = &cube::setHeight;// 함수포인터 값 초기화 및 선언
	
	bool Roll_up(char* command); // Roll_up을 수행하는 매소드
	bool slice(char* command); //slice를 수행하는매소드
	//bool DrillDown(char* command, cube* raw);
	void delete_cube(); // 값을 삭제하는 매소드

};

