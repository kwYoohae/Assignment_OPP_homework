#include "menu_node.h"
#include <iostream>
#include <string.h>

menu_node::menu_node() {
	price = 0;
	pNext = nullptr;
	pPrev = nullptr;
	menu_name = new char[100];
}

menu_node::~menu_node() {
	delete[] menu_name;
}

void menu_node::setName(char * name) {
	for (int i = 0; i <= strlen(name); i++) {
		menu_name[i] = name[i];
	}
}

void menu_node::setNext(menu_node* pTemp) {
	pNext = pTemp;
}

void menu_node::setPrev(menu_node* pTemp) {
	pPrev = pTemp;
}

void menu_node::setPrice(int price) {
	this->price = price;
}

char* menu_node::getName() {
	return this->menu_name;
}

menu_node* menu_node::getNext() {
	return pNext;
}

menu_node* menu_node::getPrev() {
	return pPrev;
}

int menu_node::getPrice() {
	return price;
}

