#pragma once
#include "bst_node.h"

class cafe {
private:
	bst_node* pRoot;
	menu_node* pHead;
public:
	cafe();
	~cafe();
	bst_node* getRoot(); // ���� ��ȯ�ϴ� �żҵ�
	menu_node* getHead();// ���� ��ȯ�ϴ� �żҵ�
	void setRoot(bst_node* pTemp); // ���� �����ϴ� �żҵ�
	void setHead(menu_node* pTemp); // ���� �����ϴ� �żҵ�
	void Insert(int price, char* Name); // ���� �־��ִ� �żҵ�
	int Compare(char* Insert_Name, char* Name); // ���� ���ϴ� �żҵ�
	void Print_menu(bst_node* pTemp); // menu������ ����ϴ� �żҵ�
	void Print_price(); // price������ ����ϴ� �żҵ�
	int SEARCH(char* Name); // ���� ã���ִ� �żҵ� 
	bool Delete_node(char* name); // ��带 �����ϴ� �żҵ�
	void Remove_Tree(bst_node* pTemp); // bst�� �ִ� ������ �����Ѵ� �żҵ�
};