#pragma once
#include "bst_node.h"

class cafe {
private:
	bst_node* pRoot;
	menu_node* pHead;
public:
	cafe();
	~cafe();
	bst_node* getRoot();
	menu_node* getHead();
	void setRoot(bst_node* pTemp);
	void setHead(menu_node* pTemp);
	void Insert(int price, char* Name);
	int Compare(char* Insert_Name, char* Name);
	void Print_menu(bst_node* pTemp);
	void Print_price();
	int SEARCH(char* Name);
	bool Delete_node(char* name);
	void Remove_Tree(bst_node* pTemp);
};