#pragma once

class menu_node {
private:
	char* menu_name;
	int price;
	menu_node* pPrev;
	menu_node* pNext;
public:
	menu_node();
	~menu_node();
	char* getName();
	int getPrice();
	menu_node* getPrev();
	menu_node* getNext();
	void setName(char* name);
	void setPrice(int price);
	void setPrev(menu_node* pTemp);
	void setNext(menu_node* pTemp);
};