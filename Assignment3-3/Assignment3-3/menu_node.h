#pragma once

class menu_node {
private:
	char* menu_name;
	int price;
	menu_node* pPrev;
	menu_node* pNext;
public:
	menu_node(); // ������
	~menu_node(); // �Ҹ���
	char* getName(); // ���� ��ȯ�ϴ� �żҵ�
	int getPrice();// ���� ��ȯ�ϴ� �żҵ�
	menu_node* getPrev();// ���� ��ȯ�ϴ� �żҵ�
	menu_node* getNext();// ���� ��ȯ�ϴ� �żҵ�
	void setName(char* name);//���� �����ϴ� �żҵ�
	void setPrice(int price);//���� �����ϴ� �żҵ�
	void setPrev(menu_node* pTemp);//���� �����ϴ� �żҵ�
	void setNext(menu_node* pTemp);//���� �����ϴ� �żҵ�
};