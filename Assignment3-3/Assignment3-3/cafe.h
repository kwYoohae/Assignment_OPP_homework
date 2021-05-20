#pragma once
#include "bst_node.h"

class cafe {
private:
	bst_node* pRoot;
	menu_node* pHead;
public:
	cafe();
	~cafe();
	bst_node* getRoot(); // 값을 반환하는 매소드
	menu_node* getHead();// 값을 반환하는 매소드
	void setRoot(bst_node* pTemp); // 값을 변경하는 매소드
	void setHead(menu_node* pTemp); // 값을 변경하는 매소드
	void Insert(int price, char* Name); // 값을 넣어주는 매소드
	int Compare(char* Insert_Name, char* Name); // 값을 비교하는 매소드
	void Print_menu(bst_node* pTemp); // menu순으로 출력하는 매소드
	void Print_price(); // price순으로 출력하는 매소드
	int SEARCH(char* Name); // 값을 찾아주는 매소드 
	bool Delete_node(char* name); // 노드를 삭제하는 매소드
	void Remove_Tree(bst_node* pTemp); // bst에 있는 노드들을 삭제한느 매소드
};