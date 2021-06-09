#pragma once
#include "node.h"
#include "tree_node.h"

class cube_1D
{
private:
	cube_1D* pNext; // ������
	cube_1D* pPrev; //������
	tree_node* pData; // �������ִ� tree�� data
	int Rev_number; // �Ųٷ� ����ϴ��� Ȯ���ϴ� ����
public:
	cube_1D(); // ������
	~cube_1D(); // �Ҹ���

	int getRev(); //���� ��ȯ�ϴ� �żҵ�
	tree_node* getData(); //���� ��ȯ�ϴ� �żҵ�
	cube_1D* getNext(); //���� ��ȯ�ϴ� �żҵ�
	cube_1D* getPrev(); //���� ��ȯ�ϴ� �żҵ�

	void setRev(int temp);// ���� �����ϴ� �żҵ�
	void setData(tree_node* pTemp);// ���� �����ϴ� �żҵ�
	void setNext(cube_1D* pTemp);// ���� �����ϴ� �żҵ�
	void setPrev(cube_1D* pTemp);// ���� �����ϴ� �żҵ�

};

