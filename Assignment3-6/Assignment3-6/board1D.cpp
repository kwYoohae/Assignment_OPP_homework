#include "board1D.h"

board::board() {
	pHead = nullptr; // pHead�� �ʱ�ȭ
	pTail = nullptr; // pTail�� �ʱ�ȭ
	pCenter = nullptr; // pCenter�� �ʱ�ȭ
}

board::~board() { // board�� �Ҹ���
	pTail->setNext(nullptr); // pTail�� �������� null�� �ʱ�ȭ (circle�̱� ������)
	block* pTemp = pHead; // pTemp�� ���� pHead�� ����Ŵ
	while (pTemp) { // pTemp�� nullptr�� �� 
		pHead = pHead->getNext(); //pHead�� ���� ���������� 
		delete pTemp; // pTemp�� �� �����Ҵ� ����
		pTemp = pHead; // pTemp�� ���� pHead��
	}
	pHead = nullptr; // pHead�� �� �ʱ�ȭ
	pTail = nullptr; // pTail�� �� �ʱ�ȭ
}

block* board::getHead() {
	return pHead; // pHead�� ���� ��ȯ�ϴ� �żҵ�
}
block* board::getTail() {
	return pTail;// pTail�� ���� ��ȯ�ϴ� �żҵ�
}
block* board::getCenter() {
	return pCenter;// pCenter�� ���� ��ȯ�ϴ� �żҵ�
}

void board::setHead(block* pTemp) {
	pHead = pTemp; // pHead�� ���� ��ȯ�ϴ� �żҵ�
}
void board::setTail(block* pTemp) {
	pTail = pTemp;// pHead�� ���� ��ȯ�ϴ� �żҵ�
}
void board::setCenter(block* pTemp) {
	pCenter = pTemp;// pHead�� ���� ��ȯ�ϴ� �żҵ�
}

void board::Insert() { 
	if (!pHead) { // pHead�� ���� ������� ��
		block* pNew = new block; // pNew�� ���ο� block��ü ����
		pHead = pNew;; // pHead�� ��������Ƿ� pNew�� ����
		pTail = pNew; // pTail�� ��������Ƿ� pNew�� ����
	}
	else {
		block* pNew = new block; // pNew�� ���ο� block��ü ����
		pNew->setPrev(pTail); // ���ο� ��ü pNew�� �������� pTail�� ����Ŵ
		pTail->setNext(pNew); // pTail�� ���� ���� pNew�� ����Ŵ
		pTail = pNew; // pTail�� pNew�� ����
	}
}

void board::Print_Check(block* pTemp) { // Block�� ���� �ִ��� ������ üũ�ϰ� ����ϴ� �żҵ�
	if (!pTemp->getOn()) {  // ���� ���� ������ �� ����� 
		std::cout << "��"; 
	}
	else {
		std::cout << pTemp->getOn()->getName(); // ���� ������ �� ���� �̸��� ���
	}
}

int board::Check_center(block* pTemp1, block* pTemp2) { // �� short_cut�� ��� ���� ��尡 �ΰ��̹Ƿ� �Ǵ����ֱ� ���� �żҵ�
	bool temp1; // short_cut1�� �Ǵ��ϴ� �żҵ�
	bool temp2; // short_cut2�� �Ǵ��ϴ� �żҵ�
	if (!pTemp1->getOn()) { //���� short_cut1�� ����� ������� ��
		temp1 = false; // false����
	}
	else {
		temp1 = true; // true����
	}
	if (!pTemp2->getOn()) { // ���� short_cut2�� ����� ������� �� 
		temp2 = false; // false����
	}
	else {
		temp2 = true; // true����
	}
	if (temp1 == true && temp2 == true) { //temp1 , temp2��� �ڸ��� ���� ����
		return 3; //  3�� ��ȯ
	}
	else if (temp1 == true) { // temp1�� true�� ��
		return 1; // 1�� ��ȯ
	}
	else if (temp2 == true) { // temp2�� true�� ��
		return 2; //  2�� ��ȯ
	}
	else {
		return 0; // 0�� ��ȯ
	}
}

void board::Print(board* short1, board* short2) { //board�� print�ϴ� �żҵ�
	block* pTemp = short2->getHead()->getPrev(); //ù��° ������� ���� ���� ����Ŵ
	block* pTemp1 = short1->getHead()->getPrev()->getPrev(); //ó�� ���ۿ��� ���� ������ ���� ���� ����Ŵ
	block* pShort1 = short1->getHead(); //ù��° �������� haed�� ����Ŵ 
	block* pShort2 = short2->getHead(); //�ι��� �������� haed�� ����Ŵ
	for (int i = 0; i < 6; i++) { // �� ������ ���
		if (i == 3)
			std::cout.width(10); // ����� ����
		Print_Check(pTemp); // �����ִ��� ������ Ȯ���� ���
		std::cout.width(5);
		pTemp = pTemp->getPrev(); // �������� ��� (Board��� ��ü�� 10��° ������ 5��° ���������)
	}
	std::cout << '\n' << '\n'; 
	pTemp = pShort2->getPrev()->getNext(); //pTemp�� ���� Board��ü�� 11��° ������ ����
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (j == 0) {
				Print_Check(pTemp); // block�� ���� �ִ��� Ȯ�� �� ���(Board��ü ����11���� 12����)
				pTemp = pTemp->getNext(); // pTemp�� ���� ������
				if (i == 0)
					std::cout.width(5);
				else -
					std::cout.width(10);
			}
			else if (j == 1) {
				Print_Check(pShort2); // block�� ���� �ִ��� Ȯ�� �� ��� (Board_shortcut2 list���� pHead���� �� ������ ����)
				pShort2 = pShort2->getNext(); // pShort2�� ���� ������ 
				if (i == 0)
					std::cout.width(20);
				else
					std::cout.width(10);
			}
			else if (j == 2) {
				Print_Check(pShort1); // block�� ���� �ִ��� Ȯ�� �� ���(Board_shortcut1 list���� pHead���� �� ������ ����)
				pShort1 = pShort1->getNext(); // pShort1�� ���� �������� 
				if (i == 0)
					std::cout.width(5);
				else
					std::cout.width(10);
			}
			else {
				Print_Check(pTemp1); // block�� ���� �ִ��� Ȯ�� �� ���(Board���� 4(���ڸ�) , 3(���ڸ�)���)
				pTemp1 = pTemp1->getPrev(); // pTemp1�� ����������

			}
		}
		std::cout << '\n' << '\n';
	}
	std::cout.width(15);
	int num = Check_center(pShort1, pShort2); // Check_center center�� ���� Ȯ���ϴ� �żҵ� ȣ��
	if (num == 1) 
		Print_Check(pShort1); // pShort1�� ���Ϳ��� ���� �ִ� ��Ȳ�̹Ƿ� pShort1�� �������
	else if (num == 2)
		Print_Check(pShort2); // pShort2�� ���Ϳ��� ���� �ִ� ��Ȳ�̹Ƿ� pShort2�� �������
	else {
		Print_Check(pShort1); // pShort1, pShort2�Ѵ� ���� �����Ƿ� �ƹ����̳� ���
	}
	pShort1 = pShort1->getNext(); // pShort1�� ���ǰ��� ����ϱ� ���ؼ� ����������
	pShort2 = pShort2->getNext(); // pShort2�� ���ǰ��� ����ϱ� ���ؼ� ����������
	std::cout << '\n' << '\n';

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (j == 0) {
				Print_Check(pTemp); // Board list ���ؿ��� Board(13,14)���� ���� ��� 
				pTemp = pTemp->getNext(); // pTemp���� ���� ������ 
				if (i == 1)
					std::cout.width(5); 
				else
					std::cout.width(10);
			}
			else if (j == 1) {
				Print_Check(pShort1); // pShort1�� ���� Center �������� pTail���� ���
				pShort1 = pShort1->getNext(); // pShort1�� ���� ���������� 
				if (i == 1)
					std::cout.width(20);
				else
					std::cout.width(10);
			}
			else if (j == 2) {
				Print_Check(pShort2); // pSHort2�� ���� Center�� �������� pTail���� ���
				pShort2 = pShort2->getNext(); // pShort2�� pShort2�� ����������
				if (i == 1)
					std::cout.width(5);
				else
					std::cout.width(10);
			}
			else {
				Print_Check(pTemp1); // pTemp1�� Board �������� 2 , 1�� ������
				pTemp1 = pTemp1->getPrev(); // pTemp�� pTemp�� ����������

			}
		}
		std::cout << '\n' << '\n';
	}

	for (int i = 0; i < 6; i++) {
		if (i == 3)
			std::cout.width(10);
		Print_Check(pTemp); // Board list�������� (15~���� pHead���� ���)
		std::cout.width(5);
		pTemp = pTemp->getNext(); //pTemp�� pTemp�� ����������
	}
	std::cout << '\n' << '\n';
}