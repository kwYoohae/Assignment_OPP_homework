#pragma once
#include "tree_node.h"
class tree
{
private:
	tree_node* pRoot; // root값

public:
	tree(); // 생성자
	~tree(); // 소명자

	tree_node* getRoot(); //값을 반환하는 매소드

	void setRoot(tree_node* pTemp);// 값을 변경하는 매소드

	void delete_tree(tree_node* Node); //tree를 삭제하는 매소드
};

