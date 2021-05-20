#include "LL.h"
#include <cstdlib>
#include <ctime>
#include <crtdbg.h>
#include <iostream>

LL::LL() {
	srand(time(NULL)); //�����õ尪�� ��
	int rand_number = rand() % 6; // �������� ����
	Node* pNew;
	Node* pTail = nullptr;
	for (int i = 0; i < 6; i++) { // 6���� �ϳ��� ź���� ����
		pNew = new Node;
		if (i == rand_number) { // �������� random�ѹ��� �� źȯ�� ����
			if (i == 0) { // Head�� ���� �� Head�� Tail����
				pNew->setData(1); // �Ѿ��� �ִ°����� ������ 1�� �־���
				pHead = pNew;
				pTail = pNew;
			}
			else { // Head�� �ƴѰ��� �Ѿ��� ������
				pNew->setData(1); // �Ѿ��� �ִ°��� ������ 1�� �־���
				pTail->setNext(pNew); 
				pNew->setPrev(pNew);
				pTail = pNew;
			}
		}
		else {
			if (i == 0) { // head�϶� head Tail����
				pHead = pNew;
				pTail = pNew;
			}
			else { // tail�� next�� prev�� ��������
				pTail->setNext(pNew);
				pNew->setPrev(pNew);
				pTail = pNew;
			}
		}
	}
	pTail->setNext(pHead); // ����������� �������� head������
	pHead->setPrev(pTail); // head����� �ڸ� ����������
}

LL::~LL() { // �Ҹ���
	Node* pTemp = pHead->getNext(); // Temp���� Head�� ����������
	pHead->setNext(nullptr); // Head�� next���� null�� ���� circle�� �������
	while (pTemp) { // nullptr�� ���������� �����Ҵ�����
		pHead = pTemp->getNext();
		delete pTemp;//�����Ҵ� ����
		pTemp = pHead;
	}

	_CrtDumpMemoryLeaks();
}

void LL::setHead(Node* pTemp) { // ���� ������ �ִ� �żҵ�
	pHead = pTemp;
}

Node* LL::getHead() {// ���� ��ȯ�� �ִ� �żҵ�
	return pHead;
}

int LL::shoot() { // �Ѿ��� �߻��ϴ� �żҵ�
	bool is_bullet = pHead->getData(); //�ҷ��� �߻��ؼ� �Ѿ��� ���� ����
	Node* pTemp = pHead;
	pHead = pHead->getNext(); // ���������� �̵�
	return is_bullet; // �Ѿ˰��� ��ȯ
}

void LL::rotate() { // �������� �Ѿ��� ������ �żҵ�
	srand(time(NULL)); // �������� �õ�� ����
	int number = rand() % 6; // ������ ����
	for (int i = 0; i <= number; i++) { //���� �� ��ŭ Head�� ����
		pHead = pHead->getNext();
	}
}

void LL::print() { 
	Node* pTemp = pHead->getNext();
	std::cout << pHead->getData() << '\n';
	while (pTemp != pHead) {
		std::cout << pTemp->getData() << '\n';
		pTemp = pTemp->getNext();
	}
}