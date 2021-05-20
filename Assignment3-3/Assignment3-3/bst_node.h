#pragma once
#include "menu_node.h"

class bst_node {
private:
	menu_node* pNode;
	bst_node* pLeft;
	bst_node* pRight;
public:
	bst_node(); //생성자
	~bst_node(); // 소멸자
	menu_node* getNode(); //값 반환매소드
	bst_node* getLeft();//값 반환매소드
	bst_node* getRight();//값 반환매소드
	void setNode(menu_node* pTemp);//값 변경매소드
	void setLeft(bst_node* pTemp);//값 변경매소드
	void setRight(bst_node* pTemp);//값 변경매소드
	
};