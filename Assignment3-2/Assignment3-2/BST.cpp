#include <iostream>
#include "BST.h"
#include <crtdbg.h>

bst::bst() {
	count = 0; //count�� �ʱ�ȭ
	data = 0; //data�� �ʱ�ȭ
	root = nullptr; //root�� �ʱ�ȭ
}

bst::~bst() {
	Remove_Tree(root); // delete�ϱ� ���� �żҵ� ȣ��
	root = nullptr; //root�� ���� nullptr�� �ʱ�ȭ
	_CrtDumpMemoryLeaks();
}

void bst::Insert(node* pNode) { //����Ʈ���� �� �����ϴ� �żҵ�
	bool prev = false; //�������� ���� �����ؾ��ϴ��� �����ʿ� ���� �����ؾ��ϴ��� Ȯ���ϴ� ����
	node* pTemp = new node; //���ο� ��� ����
	pTemp->setData(pNode->getData()); // ���ο� ��忡 �����Ͱ��� ����
	if (count == 0) { //ó�� �����ϴ� ����� ��
		root = pTemp; //root�� ó�� �����ϴ� ���
		pTemp->setNext(nullptr); //���� �����Ƿ� nullptr
		pTemp->setPrev(nullptr); //���� �����Ƿ� nullptr
		count++; //�����Ͽ����Ƿ� count++
	}
	else{
		node* pParent = root; //�θ� ��� 
		node* pWork = root; // �ڽ� ���
		while (pWork) { //�ڽĳ�尡 nullptr�� ������ �ݺ���
			pParent = pWork; // �θ��� = �ڽĳ���� ����Ǳ� ������ ���� ����
			if (pWork->getData() > pTemp->getData()) { //�Է��� ���� node�� ������ �������
				pWork = pWork->getPrev(); //������ ã�ƺ�
				prev = true; // �������� ���� ������ true�� Ȯ��
			}
			else if (pWork->getData() < pTemp->getData()) { //�Է��� ���� node�� ������ Ŭ ���
				pWork = pWork->getNext(); // �������� Ȯ��
				prev = false; // ���������� ���� ������ false
			}
			else {
				delete pTemp; //���� �ߺ��ϰ�쿡�� ���� �ؾ������� pTemp�� ����
				return; // ��ȯ
			}
		}
		if (prev) { //�����϶�
			pParent->setPrev(pTemp); //�θ����� ���ʿ� ����
		}
		else {
			pParent->setNext(pTemp); //	�θ����� �����ʿ� ����
		}
	}
}

void bst::Print_Post(node *pNode) { //���� ��ȸ�� ����ϴ� ���(����Լ�)
	if (pNode) { //pNode�� ���� nullptr�� �ƴ� ��
		Print_Post(pNode->getPrev()); // �������� �ִ��� �� ��
		Print_Post(pNode->getNext()); // ���������� �ִ��� �� ��
		std::cout << pNode->getData(); // ���� ���
		std::cout.width(5); //���ݵα�
	}
}

void bst::setRoot(node* pNode) { // root�� ���� �����ϴ� �żҵ�
	root = pNode;
}
void bst::setData(int number) { // data�� ���� �����ϴ� �żҵ�
	data = number;
}
int bst::getData() { //data�� ���� ��ȯ�ϴ� �żҵ�
	return data;
}
node* bst::getRoot() { //root�� ���� ��ȯ�ϴ� �żҵ�
	return root;
}

bool bst::is_Empty() { // bst�� ����ִ��� Ȯ���ϴ� �żҵ�
	if (getRoot() == NULL) // root�� ���� null�϶� 
		return true; //true�� ��ȯ
	else
		return false; //root�� ���� ���� �� false�� ��ȯ
}

int bst::Search(int number) { // bst�� ���� ã�� �żҵ�
	node* pNode = root; // pNode��� �����Ͱ� root�� ����Ŵ
	while (pNode) { //pNode�� nullptr�� ���� �� ���� �ݺ�
		if (pNode->getData() == number) // ���� data ���� �ִ��� Ȯ��
			return pNode->getData(); // data���� ��ȯ
		else if (pNode->getData() > number) { // �Է��� ������ ���� ���ϴ� ������ ���� ��� ���� Ʈ�� Ž��
			pNode = pNode->getPrev();
		}
 		else if (pNode->getData() < number) { // �Է��� ������ ���� ���ϴ� ������ Ŭ ��� ������ Ʈ�� Ž��
			pNode = pNode->getNext();
		}
	}
	return -1; // Ʈ���� ���Ǵ�� ã�ƺ��� ���� ��� -1 ��ȯ
}

void bst::Print_Pre(node* pNode) { //���� ��ȸ�� ���� ���
	if (pNode) { //pNode�� nullptr�� �ƾƴ� ��쿡��
		std::cout << pNode->getData(); //root���� ��� ���
		std::cout.width(5); // ����
		Print_Pre(pNode->getPrev()); //���� Ž��
		Print_Pre(pNode->getNext()); //������ Ž��
	}
}

void bst::Print_in(node* pNode) { // ���� ��ȸ�� ���� ���
	if (pNode) { //pNode�� nullptr�� �ƴ� ��쿡��
		Print_in(pNode->getPrev()); // �ִ��� �������� ���
		std::cout << pNode->getData(); //���� ���
		std::cout.width(5); // ����
		Print_in(pNode->getNext()); // ������ �� Ž��
	}
}

void bst::Remove_Tree(node* pTemp) { // tree�� �����ϴ� �żҵ�
	if (pTemp) { // pTemp�� ���� ���� �Ҷ�
		Remove_Tree(pTemp->getPrev()); // ���� �������� Ž��
		Remove_Tree(pTemp->getNext()); // ������ Ž��
		delete pTemp; //�� �Ҵ� ����
	}
}