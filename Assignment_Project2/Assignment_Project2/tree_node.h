#pragma once
class tree_node {
private:
	char data[100]; // ������ ��
	int low; // ������
	tree_node* pUp; // ����
	tree_node* pDown; // �Ʒ���
	tree_node* pNext; // ������
	tree_node* pPrev; // ������
public:
	tree_node(); // ������
	~tree_node(); // �Ҹ���

	int getLow(); //���� ��ȯ���ִ� �żҵ�
	tree_node* getUp();//���� ��ȯ���ִ� �żҵ�
	tree_node* getDown();//���� ��ȯ���ִ� �żҵ�
	char* getData();//���� ��ȯ���ִ� �żҵ�
	tree_node* getNext();//���� ��ȯ���ִ� �żҵ�
	tree_node* getPrev();//���� ��ȯ���ִ� �żҵ�

	void setLow(int temp); // ���� �����ϴ� �żҵ�
	void setUp(tree_node* pTemp);// ���� �����ϴ� �żҵ�
	void setDown(tree_node* pTemp);// ���� �����ϴ� �żҵ�
	void setData(char* pTemp);// ���� �����ϴ� �żҵ�
	void setNext(tree_node* pTemp);// ���� �����ϴ� �żҵ�
	void setPrev(tree_node* pTemp);// ���� �����ϴ� �żҵ�
};