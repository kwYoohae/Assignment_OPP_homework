#include <iostream>
#include "queue.h"
#include <crtdbg.h>
using namespace std;

queue::queue() {
	data = 0; //������ �ʱ�ȭ
	pHead = nullptr; //head �ʱ�ȭ
	pTail = nullptr; // tail �ʱ�ȭ
}

queue::~queue() { // queue�Ҹ���
	node* pTemp; //pTemp��� ������ ����
	while (pHead) { //head�� nullptr�� ���� �� ����
		pTemp = pHead; //pTemp�� head�� ����Ŵ
		pHead = pHead->getNext(); //head�� next������ �̵�
		delete pTemp; //�����Ҵ� ����
	}
	_CrtDumpMemoryLeaks();
}

void queue::Enqueue(int number , int *count) {
	node* pTemp = new node; //���ο� ��� ����
	if (*count >= 5) // ť�� ���� 5���� Ŀ�� ��
		cout << "Error 300" << endl; //�����޽��� ���
	else if (*count == 0) { //ó�� ������ ��
		pTemp->setData(number); // ��忡 �����Ͱ� �ֱ�
		pHead = pTemp; // ��尪 �ֱ�
		pTail = pTemp; // tail�� �ֱ�
		pTemp->setNext(nullptr); //�ƹ����� �����Ƿ� nullptr
		pTemp->setPrev(nullptr); //�ƹ����� �����Ƿ� nullptr
		(*count)++; //������ ��ŭ count �߰�
	}
	else {
		pTemp->setPrev(pTail); // ���� ������ ���� ���� �������Ƿ� pTail�� ���� ������ ���̹Ƿ� ���� ������ ����
		pTail->setNext(pTemp); // pTail�� ���� �������� �ƴϹǷ� pTemp�� �������� ����Ŵ
		pTemp->setNext(nullptr); // pTemp�� ������ ���̹Ƿ� nullptr�� ���
		pTemp->setData(number); // data���� ����
		pTail = pTemp; // pTail�� �� ����
		(*count)++; // count����
	}
}

void queue::Print_Queue() { //ť�� ����ϴ� �żҵ�
	node* pWork = pHead; // pWork�� pHead�� ����Ŵ
	while (pWork) { //pWork�� nullptr�� ����ų �� ���� �ݺ�
		cout << pWork->getData(); //pWork�� ������ ���
		cout.width(5); // ����
		pWork = pWork->getNext(); // pWork�� Next������ ����
	}
	cout << '\n';
}

void queue::Dequeue(int number, int *count, bst* Bst) { // queue�� �����ϴ� �żҵ�
	node* pTemp; //pTemp���� ����
	for (int i = 0; i < number; i++) {
		if (*count == 1) { // ť�� ���� �ϳ��� ���Ƽ� queue�� ��带 ���� �� ��
			pTemp = pHead; // pHead�� ����Ŵ( ť�� head�ۿ� ���� �ʾƼ�)
			Bst->Insert(pTemp); //������ ���� BST�� ����
			pHead = nullptr; // ��带 ���� �Ұ��̱� ������ ��� �ʱ�ȭ
			pTail = nullptr; // ���ϵ� �ʱ�ȭ
			delete pTemp; // �� ����
		}
		else {
			pTemp = pHead; // pHead�� ���� ������
			Bst->Insert(pTemp); // ������ ���� BST�� ����
			pHead = pHead->getNext(); // pHead�� ���� ���� pHead�� �ٲ�(�����Ұ��̱� ������)
			pHead->setPrev(pHead); // pHead�� �������� �ڽ��� ��
			delete pTemp; // �� ����
		}
		(*count)--; // �ϳ� ���� �� ������ ť ���� �پ�� count--
	}
}

void queue::All_Dequeue(int *count, bst *Bst) { //��� ť�� �����ϴ� �żҵ�
	node* pTemp; // pTemp������ ����
	for (int i = 0; *count > i; i++) {
		if (i == *count - 1) { // ť�� �ϳ� ������ ��
			pTemp = pHead; // pTemp�� head�� ����Ŵ
			Bst->Insert(pTemp); // BST�� ������ �� �־���
			pHead = nullptr; // ť�� �ƹ��͵� ���� ������ head�ʱ�ȭ
			pTail = nullptr; // ť�� �ƹ��͵� ���� ������ tail�ʱ�ȭ
			delete pTemp; // �� �޸� ����
		}
		else {
			pTemp = pHead; // pTemp�� ��带 ����Ŵ
			Bst->Insert(pTemp); // ������ ���� BST�� INSERT
			pHead = pHead->getNext(); // pHead�� ���� ���� ����
			pHead->setPrev(pHead); // pHead�� �������� �����Ǽ� �����Ƿ� �ڱ� �ڽ��� ����Ŵ
			delete pTemp; // �� �޸� ����
		}
	}
	*count = 0; // ��� ť���� ���������� count = 0
}