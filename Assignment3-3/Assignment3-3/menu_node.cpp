#include "menu_node.h"
#include <iostream>
#include <string.h>

menu_node::menu_node() { // 생성자 배열들 초기화 (menu_name은 동적할당))
	price = 0;
	pNext = nullptr;
	pPrev = nullptr;
	menu_name = new char[100];
}

menu_node::~menu_node() { // 소멸자
	delete[] menu_name;
}

void menu_node::setName(char * name ) { // 값을 변경해주는 매소드
	for (int i = 0; i <= strlen(name); i++) {
		menu_name[i] = name[i];
	}
}

void menu_node::setNext(menu_node* pTemp) {// 값을 변경해주는 매소드
	pNext = pTemp;
}

void menu_node::setPrev(menu_node* pTemp) {// 값을 변경해주는 매소드
	pPrev = pTemp;
}

void menu_node::setPrice(int price) { // 값을 변경해주는 매소드
	this->price = price;
}

char* menu_node::getName() { //값을 반환해주는 매소드
	return this->menu_name;
}

menu_node* menu_node::getNext() {//값을 반환해주는 매소드
	return pNext;
}

menu_node* menu_node::getPrev() {//값을 반환해주는 매소드
	return pPrev;
}

int menu_node::getPrice() {//값을 반환해주는 매소드
	return price;
}

