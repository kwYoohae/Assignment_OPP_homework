#include "list.h"
#include "node.h"
#include <iostream>

using namespace std;

list::list() {
	pHead = nullptr; //pHead�� �ʱ�ȭ
	pTail = nullptr; //pTail�� �ʱ�ȭ
}
list::~list() {
	node* pTemp; // node�� pTemp������ ����
	while (pHead) { // pHead�� null���� �� ���� �ݺ�
		pTemp = pHead; //pTemp�� pHead�� ����Ŵ
		pHead = pHead->getNext(); // pHead�� ���� node������ ����
		delete pTemp; // pTemp�� pHead �� ����Ų ���� ����
	}
	_CrtDumpMemoryLeaks();
}

void list::Insert(char* str, int count) { //�ܾ �����ϴ� �żҵ�
	node* pNew = new node; // ���ο� ��� ����
	if (count == 0) { // ó�� ������ ��
		pNew->setData(str); // pNew����� ������ ����
		pHead = pNew; // pHead����
		pTail = pNew; // pTail����
		pNew->setPrev(pHead); //pHead�� ������ ����
		pNew->setNext(nullptr); // ���� ���� ó���̶� ���� ������ nullptr����
	}
	else { //ó�� ��尡 �ƴ� ��
		pNew->setPrev(pTail); //���ο� ����� ���� ���� ��������(pTail) 
		pTail->setNext(pNew); //pTail�� �ڿ� �ٸ� ��尡 ���� �Ǿ����Ƿ� Next���� ���� ������ pNew�� ������ ����Ŵ
		pNew->setNext(nullptr); // pNew�� �ް��� ���� ������ Next���� nullptr�̴�
		pNew->setData(str); // pNew��忡 ������ �߰�
		pTail = pNew; // pTail�� ���� pNew�� �������� �Ǿ��� ������ pNew�� ����
	}
	
}

void list::Print() {
	node* pWork = pHead; //pWork�� pHead�� ����Ŵ
	while (pWork) { // pWork�� ������ �ܾ��� Next�� ����ų �� ���� �ݺ���
		cout << pWork->getData() << "->"; //node�� �ܾ �Է�
		pWork = pWork->getNext(); // pWork�� ���� ���� ����
	}
	cout << '\n';
}

bool list::Search_equal(char* str) { //���� ���� �ִ��� Ȯ���ϴ� �żҵ�
	node* pWork = pHead; //pHead���� �˻��ϱ� ���ؼ� pWork��� ��带 �����ؼ� pHead�� ����Ŵ
	char temp_node[20]; // node�� data���� �ҹ��ڷ� �����ϱ� ���� ����
	char temp_insert[20];  // ��� �Է��� data���� �ҹ��ڷ� �����ϱ� ���� ����
	memset(temp_node, NULL, 20); //NULL�� �ʱ�ȭ
	memset(temp_insert, NULL, 20); // NULL�� �ʱ�ȭ
	for (int i = 0; i <= strlen(str); i++) { //str�� ���� �����ϴ� for��
		if (str[i] >= 'A' && str[i] <= 'Z') { //���� �빮�ڸ� +32���ؼ� �ҹ��ڷ� �ٲپ temp_insert�� ���� ����
			temp_insert[i] = str[i] + 32;
		 }
		else {
			temp_insert[i] = str[i]; //Ư�����ڰų� �ҹ����� ������ �׳� ����
		}
	}
	while (pWork) { // pWork�� ������ ���ΰ��� null�� �ɶ� ���� �ݺ�
		for (int i = 0; i <= strlen(pWork->getData()); i++) { // ���� pWork�� ����Ű�� �ִ� ������ ���� �ҹ��ڷ� �ٽ� �����ϱ� ���� for��
			if (pWork->getData()[i] >= 'A' && pWork->getData()[i] <= 'Z') { // �빮���� ��� +32���ؼ� temp_node�� ����
				temp_node[i] = pWork->getData()[i] + 32;
			}
			else {
				temp_node[i] = pWork->getData()[i]; //�ƴҰ�� �׳�����
			}
		}
		if (strcmp(temp_node, temp_insert) == 0) //strcmp�� ����ؼ� ���� ������ ��
			return false; // �������� ������ false�� ��ȯ
		pWork = pWork->getNext(); // pWork�� ���� Next������ �̵�
		memset(temp_node, NULL, 20); // temp_node�� null�� �ٽ� �ʱ�ȭ
	}
	return true; // ���� �ɸ��°� ��� false�� ��ȯ���� �ʾҴٸ� true �� ��ȯ
}

bool list::backward_word(char * str) { //�ڿ� �ܾ��� ���� ���ڰ� �Է��� ���ڿ� �̾������� Ȯ��
	int len = strlen(pTail->getData()); // linked list�� ���κ�(tail)�� �ܾ �ҷ���
	bool upper = false; //pTail���� �빮���� ���
	bool lower = false; //pTail���� �ҹ����ΰ��
	if ((pTail->getData()[len - 1] >= 'a' && pTail->getData()[len - 1] <= 'z') || (pTail->getData()[len - 1] >= 'A' && pTail->getData()[len - 1] <= 'Z')) { //������ ���ڰ� �������� ����
		if (str[0] >= 'a' && str[0] <= 'z') { //�Է´ܾ �ҹ����� ���
			if (pTail->getData()[len - 1] == str[0]) { // �� �ܾ��� ������ �ܾ�� ������ Ȯ��
				lower = true; //pTail�� �ҹ����� �� ������ true
			}
			else if(pTail->getData()[len - 1] == str[0] - 32){
				upper = true; //pTail�� �빮�� �϶� ������ true
			}
		}
		else if (str[0] >= 'A' && str[0] <= 'Z') { // �Է´ܾ �빮���� ��
			if (pTail->getData()[len - 1] == str[0] + 32) { // pTail�� �ҹ��ڶ� �����ϰ� +32�� ���־� ������
				upper = true; //pTail�� �빮�� �϶� ������ true
			}
			else if (pTail->getData()[len - 1] == str[0]) { // pTail�� �빮�ڶ� �����ϰ� ������ 
				lower = true;//pTail�� �ҹ��� �� �� ������ true
			}
		}
		else {
			return false; // (�ҹ��ҹ�/�빮�ҹ�/�ҹ��빮/�빮�빮)�� ��츦 ������Ű�� ���� �� false�� return
		}
	}
	else {
		if (pTail->getData()[len - 1] == str[0]) { // ������ ���ڰ� Ư�������� ��� ���� �� true �ƴϸ� false�� ����
			return true;
		}
		return false;
	}
	if (upper == true || lower == true)//��ҹ����� �ϳ��� ������ �־��ٸ� true�� ��ȯ �ƴϸ� false�� ��ȯ
		return true;
	else
		return false;
}