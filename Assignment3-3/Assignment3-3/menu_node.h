#pragma once

class menu_node {
private:
	char* menu_name;
	int price;
	menu_node* pPrev;
	menu_node* pNext;
public:
	menu_node(); // 생성자
	~menu_node(); // 소멸자
	char* getName(); // 값을 반환하는 매소드
	int getPrice();// 값을 반환하는 매소드
	menu_node* getPrev();// 값을 반환하는 매소드
	menu_node* getNext();// 값을 반환하는 매소드
	void setName(char* name);//값을 변경하는 매소드
	void setPrice(int price);//값을 변경하는 매소드
	void setPrev(menu_node* pTemp);//값을 변경하는 매소드
	void setNext(menu_node* pTemp);//값을 변경하는 매소드
};