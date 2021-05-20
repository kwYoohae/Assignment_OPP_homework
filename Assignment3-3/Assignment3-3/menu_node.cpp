#include "menu_node.h"
#include <iostream>
#include <string.h>

menu_node::menu_node() { // ������ �迭�� �ʱ�ȭ (menu_name�� �����Ҵ�))
	price = 0;
	pNext = nullptr;
	pPrev = nullptr;
	menu_name = new char[100];
}

menu_node::~menu_node() { // �Ҹ���
	delete[] menu_name;
}

void menu_node::setName(char * name ) { // ���� �������ִ� �żҵ�
	for (int i = 0; i <= strlen(name); i++) {
		menu_name[i] = name[i];
	}
}

void menu_node::setNext(menu_node* pTemp) {// ���� �������ִ� �żҵ�
	pNext = pTemp;
}

void menu_node::setPrev(menu_node* pTemp) {// ���� �������ִ� �żҵ�
	pPrev = pTemp;
}

void menu_node::setPrice(int price) { // ���� �������ִ� �żҵ�
	this->price = price;
}

char* menu_node::getName() { //���� ��ȯ���ִ� �żҵ�
	return this->menu_name;
}

menu_node* menu_node::getNext() {//���� ��ȯ���ִ� �żҵ�
	return pNext;
}

menu_node* menu_node::getPrev() {//���� ��ȯ���ִ� �żҵ�
	return pPrev;
}

int menu_node::getPrice() {//���� ��ȯ���ִ� �żҵ�
	return price;
}

