#pragma once
#include <iostream>
#include "node.h"

class bst {
private:
	node* root; // root��
	int data; // �����Ͱ��� �����ϴ� ����
	int count; // �󸶳� �����Ǿ����� üũ�ϴ� ���� 
public:
	bst(); //������
	~bst(); // �Ҹ���
	void Insert(node* pNode); // BST�� �����ϴ� �żҵ�
	void setRoot(node* pNode); //root���� �����ϴ� �żҵ�
	void setData(int number); // ������ ���� �����ϴ� �żҵ�
	int getData(); // data���� ��ȯ�ϴ� �żҵ�
	node* getRoot(); // root���� ��ȯ�ϴ� �żҵ�
	void Print_Post(node* pNode); // ���� ��ȸ�� ����ϴ� �żҵ�
	void Print_in(node* pNode); // ���� ��ȸ�� ����ϴ� �żҵ�
	void Print_Pre(node* pNode); // ���� ��ȸ�� ����ϴ� �żҵ�
	bool is_Empty(); // BST�� ����ִ��� Ȯ���ϴ� �żҵ�
	int Search(int number); // ���� ã�� �żҵ�
	void Remove_Tree(node* pTemp); // �Ҹ��� �� �޸� �Ҵ� ���ִ� �żҵ�
};