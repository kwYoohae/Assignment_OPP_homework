#pragma once
class node
{
private:
	int data; // data��
	node* rNext; //row�� nect
	node* rPrev; // row�� prev
	node* cNext; // column�� next
	node* cPrev; // column�� prev
	node* hNext; // height�� next
	node* hPrev; // height��  prev
public:
	node(); // ������
	~node(); // �Ҹ���

	node* getRnext(); //���� ��ȯ�ϴ� �żҵ�
	node* getRprev();//���� ��ȯ�ϴ� �żҵ�
	node* getCnext();//���� ��ȯ�ϴ� �żҵ�
	node* getCprev();//���� ��ȯ�ϴ� �żҵ�
	node* getHprev();//���� ��ȯ�ϴ� �żҵ�
	node* getHnext();//���� ��ȯ�ϴ� �żҵ�
	int getData();//���� ��ȯ�ϴ� �żҵ�

	void setRnext(node* pTemp); // ���� �����ϴ� �żҵ�
	void setRprev(node* pTemp);// ���� �����ϴ� �żҵ�
	void setCnext(node* pTemp);// ���� �����ϴ� �żҵ�
	void setCprev(node* pTemp);// ���� �����ϴ� �żҵ�
	void setHprev(node* pTemp);// ���� �����ϴ� �żҵ�
	void setHnext(node* pTemp);// ���� �����ϴ� �żҵ�
	void setData(int temp);// ���� �����ϴ� �żҵ�
};

