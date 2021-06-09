#include "cube.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

cube::cube() { // ������(�ʱ�ȭ)
	pHead = nullptr;
	Row = nullptr;
	Column = nullptr;
	Height = nullptr;
}

cube::~cube() {
}

cube_1D* cube::getRow() {// ���� ��ȯ�ϴ� �żҵ�
	return Row;
}
cube_1D* cube::getColumn() {// ���� ��ȯ�ϴ� �żҵ�
	return Column;
}
cube_1D* cube::getHeight() {// ���� ��ȯ�ϴ� �żҵ�
	return Height;
}
node* cube::getHead() {// ���� ��ȯ�ϴ� �żҵ�
	return pHead;
}

void cube::setRow(cube_1D* pTemp) { // ���� �����ϴ� �żҵ�
	Row = pTemp;
}
void cube::setColumn(cube_1D* pTemp) {// ���� �����ϴ� �żҵ�
	Column = pTemp;
}
void cube::setHeight(cube_1D* pTemp) {// ���� �����ϴ� �żҵ�
	Height = pTemp;
}
void cube::setHead(node* pTemp) {// ���� �����ϴ� �żҵ�
	pHead = pTemp;
}

void cube::WriteLog(char* command) {//log�� ������� �ۼ��ϴ� �żҵ�
	ofstream log;
	cube_1D* Rev_temp = (this->*pRow)();
	log.open("log.txt", ios::app); // log.txt������ ���� ios::app������� ���� �ؽ�Ʈ�� �̾��.
	log << '[' << command << ']' << '\n';//���� Ŀ�ǵ带 �۵��� ������� ����� �Է��Ѵ�. 
	if (Rev_temp->getRev() % 2 == 0) {
		log << (this->*pRow)()->getData()->getData() << '\t'; // Row���� ���� ����Ѵ�.
	}
	else {
		while (Rev_temp->getNext()) { //Rev_temp�� �Ųٷ� ����ϱ� ���� ���� ���� ������ ������.
			Rev_temp = Rev_temp->getNext();
		}
		log << Rev_temp->getData()->getData() << '\t'; // Row���� ���� ����Ѵ�.
	}
	Rev_temp = (this->*pColumn)(); // Column���� ��� ����Ѵ�.
	if (Rev_temp->getRev() % 2 == 0) { // Rev���� % 2���ؼ� 0 �϶��� ���������� ����Ѵ�.
		while (Rev_temp) { // Rev_temp�� ���������� ������ش�.
			log << Rev_temp->getData()->getData() << '\t';
			Rev_temp = Rev_temp->getNext();
		}
	}
	else { // �Ųٷ� ����ϱ� ���� ���ǹ�
		while (Rev_temp->getNext()) { // �ǳ������� �̵�
			Rev_temp = Rev_temp->getNext();
		}
		while (Rev_temp) { // ���������� �̵��ϸ鼭 �ű��� ���
			log << Rev_temp->getData()->getData() << '\t';
			Rev_temp = Rev_temp->getPrev();
		}
	}
	log << '\n';
	cube_1D* pTemp = (this->*pHeight)(); //pHeight���� ����ϱ� ���ؼ� �Ҵ�
	Rev_temp = (this->*pHeight)();
	while (Rev_temp->getNext()) { // ���� ���ʰ����� �̵�
		Rev_temp = Rev_temp->getNext();
	}
	node* pWork1 = pHead;
	node* pWork2 = pWork1;
	while (pWork2) {
		if (pTemp->getRev() % 2 == 0) { // Rev���� % 2 �� ���� �� 0�̸� ���� ������� ���
			log << pTemp->getData()->getData() << '\t'; // Height�� �������� �ϳ��� ����Ѵ�/
			pTemp = pTemp->getNext();
		}
		else {
			log << Rev_temp->getData()->getData() << '\t'; // Height�� �������� �ϳ��� ����Ѵ�/
			Rev_temp = Rev_temp->getPrev();
		}
		while (pWork1) {
			log << pWork1->getData() << '\t' << '\t'; // ����� �����͸� ����Ѵ�.
			pWork1 = (pWork1->*pRight)(); // ���� ������ �̵�
		}
		log << '\n';
		pWork2 = (pWork2->*pDown)(); // ��� Right���� ������ �� ������ Down���� �̵�
		pWork1 = pWork2;
	}
	log << '\n' << '\n';
	log.close();
}

void cube::Make_tree(tree* Time, tree* Location, tree* Product, int product_number, int location_number, int time_number) { // Ʈ���� ����� �żҵ�
	tree_node* pTemp = Time->getRoot(); // time���� Ʈ������
	tree_node* pParent = pTemp;
	for (int i = 1; i < time_number; i++) { // time�� �Է��� ������ŭ ������ ������
		pParent = pTemp;
		pTemp = pTemp->getDown();
		if (!pTemp->getDown()) {
			break;
		}
	}
	while (pParent) { // �θ��尡 ���̻� �ڸų�尡 ���� ������ ����
		while (pTemp) {
			cube_1D* pNew = new cube_1D;
			if (!Row) { // Row���� ������� ����
				Row = pNew;
				pNew->setData(pTemp); // Row�� ������ ����
			}
			else {
				cube_1D* cube_temp = (this->*pRow)();
				while (cube_temp->getNext()) // Row������ �������������̵� 
					cube_temp = cube_temp->getNext();
				cube_temp->setNext(pNew); // �������� ���θ��� ���� �̾���
				pNew->setPrev(cube_temp); // ���������� �������� ��������
				pNew->setData(pTemp); // �����͸� �־���
			}
			pTemp = pTemp->getNext(); // ���� �ڸų���
		}
		pParent = pParent->getNext(); // ���� �ڸų���
		if (!pParent) // ������� �ݺ��� ����
			break;
		pTemp = pParent->getDown();
	}

	pTemp = Location->getRoot(); //���� �Ȱ��� ������� Location�� �ڽ��� �ڸų�带 ��� Ž���ؼ� tree�� �������ش�
	pParent = pTemp;
	for (int i = 1; i < location_number; i++) {
		pParent = pTemp;
		pTemp = pTemp->getDown();
		if (!pTemp->getDown()) {
			break;
		}
	}
	while (pParent) {
		while (pTemp) {
			cube_1D* pNew = new cube_1D;
			if (!Column) {
				Column = pNew;
				pNew->setData(pTemp);
			}
			else {
				cube_1D* cube_temp = (this->*pColumn)();
				while (cube_temp->getNext())
					cube_temp = cube_temp->getNext();
				cube_temp->setNext(pNew);
				pNew->setPrev(cube_temp);
				pNew->setData(pTemp);
			}
			pTemp = pTemp->getNext();
		}
		pParent = pParent->getNext();
		if (!pParent)
			break;
		pTemp = pParent->getDown();
	}

	pTemp = Product->getRoot();//���� �Ȱ��� ������� Time�� �ڽ��� �ڸų�带 ��� Ž���ؼ� tree�� �������ش�
	pParent = pTemp;
	for (int i = 1; i < product_number; i++) {
		pParent = pTemp;
		pTemp = pTemp->getDown();
		if (!pTemp->getDown()) {
			break;
		}
	}
	while (pParent) {
		while (pTemp) {
			cube_1D* pNew = new cube_1D;
			if (!Height) {
				Height = pNew;
				pNew->setData(pTemp);
			}
			else {
				cube_1D* cube_temp = (this->*pHeight)();
				while (cube_temp->getNext())
					cube_temp = cube_temp->getNext();
				cube_temp->setNext(pNew);
				pNew->setPrev(cube_temp);
				pNew->setData(pTemp);
			}
			pTemp = pTemp->getNext();
		}
		pParent = pParent->getNext();
		if (!pParent)
			break;
		pTemp = pParent->getDown();
	}
}

void cube::Make_Cube(int p, int l, int t) { //cube�� ����� �żҵ� 
	node* pWork1 = nullptr;
	node* pWork2 = nullptr;
	node* pWork3 = nullptr;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < l; k++) {
				node* pNew = new node; // cube�� ����
				if (i == 0 && j == 0 && k == 0) { // ó������ Head�� ����
					pHead = pNew;
					pWork1 = pHead;
					pWork2 = pHead;
					pWork3 = pHead;
				}
				else if (i != 0 && k == 0 && j == 0) { // Row��(Time���� �����ϱ� ���� ���ǹ�)
					pWork1 = pHead;
					while (pWork1->getRnext()) { // Row�� �������� ���� ����
						pWork1 = pWork1->getRnext();
					}
					pWork1->setRnext(pNew); // ���ο� Row(Time)������
					pNew->setRprev(pWork1); // ������ ����
					pWork2 = pNew; // ���ο� Row(Time)���� 2���� �迭�� ������ֱ� ���Ѽ���
					pWork3 = pNew;// ���ο� Row(Time)���� 2���� �迭�� ������ֱ� ���Ѽ���
				}
				else if (k == 0) { // 2�����迭 Height(product�� ������ֱ� ���� ���ǹ�)
					pWork1 = pHead;
					while (pWork1->getRnext()) { // Row(Time)�� ������ �̵�
						pWork1 = pWork1->getRnext();
					}
					pWork2 = pWork1; // �ű⼭���� ���ݱ��� ���� product�� ������ �̵�
					while (pWork2->getHnext()) {
						pWork2 = pWork2->getHnext();
					}
					pWork2->setHnext(pNew); // ���ο� product�� ������ ������ ����
					pNew->setHprev(pWork2);
					pWork3 = pNew;
				}
				else { // �׳� column(location)�� ������ ��� location�� �������� �̵� �� �������
					while (pWork3->getCnext()) {
						pWork3 = pWork3->getCnext();
					}
					pWork3->setCnext(pNew); // ���λ��� location�� next,prev�� ����
					pNew->setCprev(pWork3);
				}
			}
			if (j != 0) { // j(product)�� 2���̻��϶� ������ product���� ���� �̾��ִ� �żҵ�
				pWork1 = pHead;
				while (pWork1->getRnext()) { // Time�� �����Ȱ����� �̵�
					pWork1 = pWork1->getRnext();
				}
				pWork3 = pWork1;
				while (pWork3->getHnext()) { // product�� �����Ȱ� �����̵�
					pWork3 = pWork3->getHnext();
				}
				pWork2 = pWork3->getHprev(); // ������ product�� �������� ����
				while (pWork2) {
					pWork2->setHnext(pWork3); // ������ product�� ����
					pWork3->setHprev(pWork2);
					pWork2 = pWork2->getCnext(); // �״��� location���� �̵�
					pWork3 = pWork3->getCnext();
				}
			}
		}
		if (i != 0) { // Time���� 2���� ��
			pWork1 = pHead;
			while (pWork1->getRnext()) { //time�� ������ �������� �̵��Ѵ�
				pWork1 = pWork1->getRnext();
			}
			pWork2 = pWork1->getRprev(); // ���������� �������� ����
			pWork3 = pWork1;
			while (pWork1) { // time�� 2�����迭���� ������ ���������� �ݺ�
				while (pWork2) { // location�� Ž���Ͽ� time�� �̾��ִ� �ݺ���
					pWork2->setRnext(pWork3);
					pWork3->setRprev(pWork2);
					pWork2 = pWork2->getCnext(); // ���� location������ �̵�
					pWork3 = pWork3->getCnext();
				}
				pWork2 = pWork1->getRprev()->getHnext();
				pWork3 = pWork1->getHnext();
				pWork1 = pWork1->getHnext();
			}
		}
	}
}

void cube::Make_View(tree* Time, tree* Location, tree* Product) { //viewť���� �ʱ������ �ϴ� �żҵ�(row,column,height�� 3�������� 2�������� rollup�ϴ� ���
	int number = 0;
	node* pWork1 = pHead;
	node* pWork2;
	node* pWork3;
	node* pWork4;
	tree_node* pTemp;
	tree_node* tree_temp = Height->getData();
	tree_node* tree_down = tree_temp->getDown();
	pTemp = tree_temp;
	if (tree_down) { // high�� �ڽĳ�尡 ������� ������
		while (tree_down->getNext()) { // ���ϴ� �������� �̵�
			tree_down = tree_down->getNext();
			number++;
		}
	}
	while (tree_temp) { // tree_temp�� ������ �ڸų����� �湮���� ������ �ݺ�
		for (int i = 0; i < number; i++) { // �ڽĳ���� ������ŭ �ݺ� rollup�� ����
			pWork2 = pWork1;
			while (pWork2) {
				pWork3 = pWork2;
				while (pWork3) { // height�� �������� ������ ������ �̾���
					pWork4 = pWork3->getHnext(); // height�� �������� ������ height�� ������
					pWork3->setData(pWork3->getData() + pWork4->getData()); // ������ ���� ���� �����͸� ��ħ
					pWork3->setHnext(pWork4->getHnext()); // �����ҵ������� �������� ��ġ�� ���� �������� ��������
					if (pWork4->getHnext()) { // pWork4�� �������� ������� ������(������ ���� �ƴҶ�)
						pWork4->getHnext()->setHprev(pWork3); // �״��� ���� �������� ��������
						//break;
					}
					delete pWork4; //������
					pWork3 = pWork3->getCnext(); // �״��� ���� �̵� Column��
				}
				pWork2 = pWork2->getRnext(); // ��� Column���� �������־����� ���� Row������ �̵�
			}
		}
		pWork1 = pWork1->getHnext(); //��� Height�� ���Ѱ��� �����ϸ� ���� Height�� �̵�
		tree_temp = tree_temp->getNext(); // tree_temp���������� �̵��Ѵ�
		if (!tree_temp) // ������ ����
			break;
		tree_down = tree_temp->getDown(); // tree_temp�� �ڽĳ��� �̵��Ѵ�.
		number = 0;
		while (tree_down->getNext()) { // �ڽĳ���� ������ ����
			tree_down = tree_down->getNext();
			number++;
		}
	}

	tree_temp = Row->getData(); // ���� Height�� �Ȱ��� ������� Row�� 3������ 2�������� ��ġ�� ������.
	pTemp = tree_temp;
	pWork1 = pHead;
	number = 0;
	tree_down = tree_temp->getDown();
	if (tree_down) {
		while (tree_down->getNext()) {
			tree_down = tree_down->getNext();
			number++;
		}
	}
	while (tree_temp) {
		for (int i = 0; i < number; i++) {
			pWork2 = pWork1;
			while (pWork2) {
				pWork3 = pWork2;
				while (pWork3) {
					pWork4 = pWork3->getRnext();
					pWork3->setData(pWork3->getData() + pWork4->getData());
					pWork3->setRnext(pWork4->getRnext());
					if (pWork4->getRnext()) {
						pWork4->getRnext()->setRprev(pWork3);
						//break;
					}
					delete pWork4;
					pWork3 = pWork3->getCnext();
				}
				pWork2 = pWork2->getHnext();
			}
		}
		pWork1 = pWork1->getRnext();
		tree_temp = tree_temp->getNext();
		if (!tree_temp)
			break;
		tree_down = tree_temp->getDown();
		number = 0;
		while (tree_down->getNext()) {
			tree_down = tree_down->getNext();
			number++;
		}
	}

	tree_temp = Column->getData();// ���� Height�� �Ȱ��� ������� Column�� 3������ 2�������� ��ġ�� ������.
	pTemp = tree_temp;
	pWork1 = pHead;
	number = 0;
	tree_down = tree_temp->getDown();
	if (tree_down) {
		while (tree_down->getNext()) {
			tree_down = tree_down->getNext();
			number++;
		}
	}
	while (tree_temp) {
		for (int i = 0; i < number; i++) {
			pWork2 = pWork1;
			while (pWork2) {
				pWork3 = pWork2;
				while (pWork3) {
					pWork4 = pWork3->getCnext();
					pWork3->setData(pWork3->getData() + pWork4->getData());
					pWork3->setCnext(pWork4->getCnext());
					if (pWork4->getCnext()) {
						pWork4->getCnext()->setCprev(pWork3);
						//break;
					}
					delete pWork4;
					pWork3 = pWork3->getHnext();
				}
				pWork2 = pWork2->getRnext();
			}
		}
		pWork1 = pWork1->getCnext();
		tree_temp = tree_temp->getNext();
		if (!tree_temp)
			break;
		tree_down = tree_temp->getDown();
		number = 0;
		while (tree_down->getNext()) {
			tree_down = tree_down->getNext();
			number++;
		}
	}
}


void cube::copyData(cube* raw) { // rawť���� �����͸� �����ؼ� �������� �żҵ�
	node* pWork1 = raw->getHead();  // rawť���ǰ�
	node* pWork2 = pWork1;// rawť���ǰ�
	node* pWork3 = pWork1;// rawť���ǰ�
	node* pCopy1 = pHead; // viewť���� ��
	node* pCopy2 = pCopy1; // viewť���� ��
	node* pCopy3 = pCopy1; // viewť���� ��
	while (pWork1) {
		while (pWork2) {
			while (pWork3) {
				pCopy3->setData(pWork3->getData()); // �����͸� ��������
				pWork3 = pWork3->getCnext(); // column(RIght)������ ����̵�
				pCopy3 = pCopy3->getCnext();
			}
			pWork2 = pWork2->getHnext(); // Height(Down)������ ����̵�
			pCopy2 = pCopy2->getHnext();
			pWork3 = pWork2;
			pCopy3 = pCopy2;
		}
		pWork1 = pWork1->getRnext(); // Row(Out)������ ����̵�
		pCopy1 = pCopy1->getRnext();
		pWork2 = pWork1;
		pWork3 = pWork1;
		pCopy3 = pCopy1;
		pCopy2 = pCopy1;
	}
}

bool cube::Rotate(char* command) {
	node* (node:: * pRight_temp)() = pRight; //�� temp�� ����
	node* (node:: * pLeft_temp)() = pLeft; //�� temp�� ����
	node* (node:: * pUp_temp)() = pUp; //�� temp�� ����
	node* (node:: * pDown_temp)() = pDown; //�� temp�� ����
	node* (node:: * pIn_temp)() = pIn; //�� temp�� ����
	node* (node:: * pOut_temp)() = pOut; //�� temp�� ����
	void (node:: * setRight_temp)(node * pTemp) = setRight; //�� temp�� ����
	void (node:: * setLeft_temp)(node * pTemp) = setLeft; //�� temp�� ����
	void (node:: * setUp_temp)(node * pTemp) = setUp; //�� temp�� ����
	void (node:: * setDown_temp)(node * pTemp) = setDown; //�� temp�� ����
	void (node:: * setIn_temp)(node * pTemp) = setIn; //�� temp�� ����
	void (node:: * setOut_temp)(node * pTemp) = setOut; //�� temp�� ����

	cube_1D* (cube:: * pRow_temp)() = pRow; //�� temp�� ����
	cube_1D* (cube:: * pColumn_temp)() = pColumn; //�� temp�� ����
	cube_1D* (cube:: * pHeight_temp)() = pHeight; //�� temp�� ����
	void (cube:: * pRow_set_temp)(cube_1D * pTemp) = pRow_set; //�� temp�� ����
	void (cube:: * pColumn_set_temp)(cube_1D * pTemp) = pColumn_set; //�� temp�� ����
	void (cube:: * pHeight_set_temp)(cube_1D * pTemp) = pHeight_set; //�� temp�� ����
	if (strcmp(command, "clockwise") == 0) {
		while ((pHead->*pDown)()) { //Head�� ���� ������
			pHead = (pHead->*pDown)();
		}
		pRight = pUp_temp; // right = up��������
		setRight = setUp_temp;
		pLeft = pDown_temp; // left = down��������
		setLeft = setDown_temp;
		pDown = pRight_temp; // down = right��������
		setDown = setRight_temp;
		pUp = pLeft_temp; // up = left��������
		setUp = setLeft_temp;
		pHeight = pColumn_temp; // Height = column��������
		pColumn = pHeight_temp; // Column = Height��������
		pHeight_set = pColumn_set_temp;
		pColumn_set = pHeight_set_temp;
		(this->*pColumn)()->setRev((this->*pColumn)()->getRev() + 1); // column�� �Ųٷ����
	}
	else if (strcmp(command, "c_clockwise") == 0) {
		while ((pHead->*pRight)()) { // Head�� ���� ����������
			pHead = (pHead->*pRight)();
		}
		pRight = pDown_temp; // right = down����
		setRight = setDown_temp;
		pLeft = pUp_temp; // left = up����
		setLeft = setUp_temp;
		pDown = pLeft_temp; // down�� left��
		setDown = setLeft_temp;
		pUp = pRight_temp; // up�� right��
		setUp = setRight_temp;
		pHeight = pColumn_temp; // height = column����
		pColumn = pHeight_temp; // column = height����
		pHeight_set = pColumn_set_temp;
		pColumn_set = pHeight_set_temp;
		(this->*pHeight)()->setRev((this->*pHeight)()->getRev() + 1); // height�� �Ųٷ� ���
	}
	else if (strcmp(command, "left") == 0) {
		while ((pHead->*pRight)()) { // Head�� ���� right������
			pHead = (pHead->*pRight)();
		}
		pRight = pOut_temp; // right = out����
		setRight = setOut_temp;
		pLeft = pIn_temp; // left= in����
		setLeft = setIn_temp;
		pOut = pLeft_temp; // out = left��
		setOut = setLeft_temp;
		pIn = pRight_temp; // in = right��
		setIn = setRight_temp;
		pColumn = pRow_temp; // column�� row��
		pRow = pColumn_temp; // row�� column����
		pColumn_set = pRow_set_temp;
		pRow_set = pColumn_set_temp;
		(this->*pRow)()->setRev((this->*pRow)()->getRev() + 1); // row�� �Ųٷ� ���
	}
	else if (strcmp(command, "right") == 0) {
		while ((pHead->*pOut)()) { // pHead�� ���� out������
			pHead = (pHead->*pOut)();
		}
		pRight = pIn_temp; //right = in����
		setRight = setIn_temp;
		pLeft = pOut_temp; // left�� out����
		setLeft = setOut_temp;
		pOut = pRight_temp; // out�� right��
		setOut = setRight_temp;
		pIn = pLeft_temp; // in�� left��
		setIn = setLeft_temp;
		pColumn = pRow_temp; // columb�� row��
		pRow = pColumn_temp;// row�� column����
		(this->*pColumn)()->setRev((this->*pColumn)()->getRev() + 1); //Column�� �Ųٷ� ���
	}
	else if (strcmp(command, "up") == 0) {
		while ((pHead->*pDown)()) { //haed�� down�� ��������
			pHead = (pHead->*pDown)();
		}
		pDown = pOut_temp; // down = out����
		setDown = setOut_temp;
		pUp = pIn_temp; // up �� in����
		setUp = setIn_temp;
		pOut = pUp_temp; // out�� up���� 
		setOut = setUp_temp;
		pIn = pDown_temp; // in�� down����
		setIn = setDown_temp;
		pHeight = pRow_temp; // height�� row��
		pRow = pHeight_temp; // row�� height��
		pHeight_set = pRow_set_temp;
		pRow_set = pHeight_set_temp;
		(this->*pRow)()->setRev((this->*pRow)()->getRev() + 1); // row�� �Ųٷ� ���
	}
	else if (strcmp(command, "down") == 0) {
		while ((pHead->*pOut)()) { // head�� out�� ������
			pHead = (pHead->*pOut)();
		}
		pDown = pIn_temp; // down�� in����
		setDown = setIn_temp;
		pUp = pOut_temp; // up�� out����
		setUp = setOut_temp;
		pOut = pDown_temp; // out�� down����
		setOut = setDown_temp;
		pIn = pUp_temp; // in�� up����
		setIn = setUp_temp;
		pHeight = pRow_temp; // height�� row��
		pRow = pHeight_temp; // row�� height��
		pHeight_set = pRow_set_temp;
		pRow_set = pHeight_set_temp;
		(this->*pHeight)()->setRev((this->*pHeight)()->getRev() + 1); // height�� �Ųٷ� ���
	}
	else {
		return false;
	}
	return true;
}

bool cube::Roll_up(char* command) { // ROLLUP�� �ϴ� �żҵ�
	bool find = false;
	int h = 0;
	int r = 0;
	int c = 0;
	int cnt = 0;
	int end = 0;
	int start = 0;
	int low_number = 0;
	cube_1D* pTemp = (this->*pRow)(); // Row�� ���� �����´�.
	while (!find) { //find�� ã������ false�̸� �ݺ����� �����Ѵ�.
		while (pTemp) {
			if (strcmp(pTemp->getData()->getData(), command) == 0) { // row���� ������ Ȯ��
				cnt++;
				r = cnt;
				find = true;
				break; // ������ �ݺ�������
			}
			pTemp = pTemp->getNext(); // ����������
			cnt++;
		}
		if (find)
			break; // find�� ������ break���� �ݺ����� ��������
		pTemp = (this->*pColumn)(); // Column���� ���ϱ� ���� �Ҵ�
		cnt = 0;
		while (pTemp) {
			if (strcmp(pTemp->getData()->getData(), command) == 0) { //���������� Ȯ��
				cnt++;
				c = cnt;
				find = true;
				break; //�ݺ�������
			}
			pTemp = pTemp->getNext(); //����������
			cnt++;
		}
		if (find)
			break; //�ݺ�������
		pTemp = (this->*pHeight)(); // Height���� ���ϱ� ���� �Ҵ�
		cnt = 0;
		while (pTemp) {
			if (strcmp(pTemp->getData()->getData(), command) == 0) { // ���� ������ Ȯ��
				cnt++;
				h = cnt;
				find = true;
				break; // �ݺ�������
			}
			pTemp = pTemp->getNext(); // ����������
			cnt++;
		}
		break; // �ݺ��� ����
	}
	if (find == true) {//���� ���� ã���� ��
		if (!pTemp->getData()->getUp()) { // up�� ������ 1�����̹Ƿ� ROLLUP�Ұ� �����Ƿ� false�� return
			return false;
		}
		else {
			low_number = pTemp->getData()->getLow() - 1; // ���� �����͸� ����
			tree_node* pCount = pTemp->getData()->getNext(); // end�� start�� �����ֱ� ���� ����
			node* pWork1 = pHead;
			while (pCount) { // next�� ���鼭 end�� ������ ������ ����.
				end++;
				pCount = pCount->getNext(); // Next�� ���� �̵�
			}
			pCount = pTemp->getData()->getPrev(); //prev������ start������ �Ÿ��� ��� ���ؼ� �Ҵ�
			while (pCount) {
				start++;
				pCount = pCount->getPrev(); // ���������� ����̵�
			}
			if (!pTemp->getData()->getUp()->getDown()->getNext()) { //�ڽĳ�尡 �ϳ����� Ȯ���ϴ� �żҵ�
				pTemp->setData(pTemp->getData()->getUp()); // ���� ���� ������ cube_1d�� ������ ����
				return true; //true��ȯ �� �żҵ� ����
			}
			else if (!pTemp->getNext() && !pTemp->getPrev()) { // ���� node�� next prev�� �Ѵ� ��� ȥ�ڸ� �ִ� ��Ȳ�� ��
				pTemp->setData(pTemp->getData()->getUp()); // ���� ���� ������ cube_1D�� ������ ����
				return true; // true��ȯ �� �żҵ� ����
			}
			for (int i = 0; i < start; i++) { // ROLLUP�Ϸ��� ������ ���۰����� �̵��Ѵ�.
				r--; // ������ ���߿� ���ű� ������ �̵��ϴ� ��ŭ ���ҽ�Ų��.
				h--;
				c--;
				if (!pTemp->getPrev()) // ���� �������� ������� ���� �ݺ��� ���� (ȥ�ڸ� �ִ� ť�� �� ��)
					break;
				pTemp = pTemp->getPrev();
			}
			if (h > 0) { //h >0 �̾ Height���� ROLLUP�� ������ ���� �ִ� ���
				for (int i = 0; i < h - 1; i++) { // Head���� ROLLUP�� ���� ������ ��带 �̵�
					pWork1 = (pWork1->*pDown)(); // Height�̹Ƿ� down�������� �̵�
				}
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < start + end; i++) { // ������ �ڸų���� ������ŭ �ݺ��� ����
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pDown)(); //pWork4�� �״��� Height�� �� (�����Ұ�)
							pWork3->setData(pWork3->getData() + pWork4->getData()); // �����͸� �����Ѵ�.
							(pWork3->*setDown)((pWork4->*pDown)()); // Down���� pWork4�� ���������� �̵�
							if ((pWork4->*pDown)()) {  //���̻� ROLLUP�� ��尡 ����(Cube�� �� �� �� �ݺ����� �������� ���� ��)
								((pWork4->*pDown)()->*setUp)(pWork3); // pDown�� ���� Height�� ����
							}
							delete pWork4; // ť�����
							pWork3 = (pWork3->*pRight)(); // ���� column������ �̵�
						}
						pWork2 = (pWork2->*pOut)(); // column���� �� �������� ���� Out������ �̵�
					}
				}
			}
			else if (c > 0) {//c >0�� ���� Column���� ROLLUP�� ������ ���� �ִ� ���
				for (int i = 0; i < c - 1; i++) { // Column�̹Ƿ� right�� �̵�
					pWork1 = (pWork1->*pRight)();
				}
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < start + end; i++) { // ������ �ڸų�� ������ŭ �ݺ��� ����
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pRight)(); // pWork�� ���� Column�� ��
							pWork3->setData(pWork3->getData() + pWork4->getData()); // ������ �����Ϳ� ���ص����͸� ��ģ��.
							(pWork3->*setRight)((pWork4->*pRight)()); //���ذ��� ���� Right���� ������ ���� ���� right������ ����
							if ((pWork4->*pRight)()) { // �� �̻� Rollup�� ��尡 ���� �� (Cube�� �� �� Column���� ���ذ��̶� �ݺ����� �������� ���� ��)
								((pWork4->*pRight)()->*setLeft)(pWork3);
							}
							delete pWork4;//ť�긦 ����
							pWork3 = (pWork3->*pDown)(); // ���� Down������ �̵�
						}
						pWork2 = (pWork2->*pOut)(); // ���� Out������ �̵�
					}
				}
			}
			else if (r > 0) { //r > 0�� ���� Row���� ROLLUP�� ������ ���� �ִ� ���
				for (int i = 0; i < r - 1; i++) { // Row���̹Ƿ� Out������ �̵�
					pWork1 = (pWork1->*pOut)();
				}
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < start + end; i++) { // ������ �ڸ� ����� ������ŭ �ݺ��� ����
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pOut)(); // pWork�� ���� Row ��
							pWork3->setData(pWork3->getData() + pWork4->getData()); // ������ �����Ϳ� ���ص����͸� ��ħ
							(pWork3->*setOut)((pWork4->*pOut)()); // ���ذ��� ���� out���� ������ ���� ������ ���� out������ ����
							if ((pWork4->*pOut)()) { // �� �̻� ROLLUP�� ��尡 ���� �� (Cube�� �� ������ ���ذ��ϰ��)
								((pWork4->*pOut)()->*setIn)(pWork3);
							}
							delete pWork4; // ť�긦 ����
							pWork3 = (pWork3->*pRight)(); // ���� Right������ �̵�
						}
						pWork2 = (pWork2->*pDown)(); // ���� Down������ �̵�
					}
				}
			}
			pTemp->setData(pTemp->getData()->getUp()); // �����͸� �� ������ ������ �����Ų��.
			cube_1D* pTemp_next = pTemp->getNext();
			for (int i = 0; i < start + end; i++) { // Cube_1D�� �����͵� �����ϱ� ���ؼ� �ݺ����� ����
				pTemp->setNext(pTemp_next->getNext()); // next�����͸� ������ ���� ���� ������ ����
				delete pTemp_next; // cube_1D�� �����͸� ����
				pTemp_next = pTemp->getNext(); // ���������� �̵�
				if (pTemp_next == nullptr) { // �������� ���̻���� ��
					pTemp->setNext(nullptr); // null�����ͷ� �ʱ�ȭ
					break; // �ݺ��� ����
				}
				pTemp_next->setPrev(pTemp); //�������� ����
			}
		}
	}
	else { // ���� ã�� ������ �� false�� ��ȯ
		return false;
	}
	if (low_number == 1) { // ������ 1������ �� 3������ ������ ������ ��ġ�� ���ؼ� ���ǹ�����
		node* pWork1 = pHead;
		node* pWork2 = pWork1;
		node* pWork3 = pWork1;
		node* pWork4 = pWork1;
		while (pTemp->getPrev()) { // ���� ���� ������ �̵�
			pTemp = pTemp->getPrev();
		}
		cnt = 0;
		while (pTemp->getNext()) {
			cnt++; // �� ��� ��尡 �ִ��� count
			pTemp = pTemp->getNext();
		}
		while (pTemp->getPrev()) { // �ٽ� ó�� ������ �̵�
			pTemp = pTemp->getPrev();
		}
		if (h > 0) { // h >0 �� �� ���ذ��� Height�� �����Ƿ� Height�������� �� ������ ������ ����
			for (int i = 0; i < cnt; i++) { // ó������ ������ ����
				pWork2 = pWork1;
				while (pWork2) {
					pWork3 = pWork2;
					while (pWork3) {
						pWork4 = (pWork3->*pDown)(); // Height�̹Ƿ� Down���� �̵�
						pWork3->setData(pWork3->getData() + pWork4->getData()); // Data���� ����
						(pWork3->*setDown)((pWork4->*pDown)()); // ���ذ��� Down�� ���� ������ ���� Down���� ����
						if ((pWork4->*pDown)()) { // ���� �� �̻� ���� ���°��
							((pWork4->*pDown)()->*setUp)(pWork3);
						}
						delete pWork4; // ���� �������ش�
						pWork3 = (pWork3->*pRight)(); // ���� right������ �̵�
					}
					pWork2 = (pWork2->*pOut)(); // ���� out������ �̵�
				}
			}
		}
		else if (c > 0) { //  c> 0 �� �� ���ذ��� Column�� �����Ƿ� Column�������� �� ���� �� ������ ����
			for (int i = 0; i < cnt; i++) { // ó������ ������ ����
				pWork2 = pWork1;
				while (pWork2) {
					pWork3 = pWork2;
					while (pWork3) {
						pWork4 = (pWork3->*pRight)(); // Column�̹Ƿ� Right���̵�
						pWork3->setData(pWork3->getData() + pWork4->getData()); // Data���� ����
						(pWork3->*setRight)((pWork4->*pRight)()); // �������� Right�� ������ ���� right�� ����
						if ((pWork4->*pRight)()) { // ���̻� ���� ���� ���� ���
							((pWork4->*pRight)()->*setLeft)(pWork3);
						}
						delete pWork4; // ť�� ����
						pWork3 = (pWork3->*pDown)(); // ���� down������ �̵�
					}
					pWork2 = (pWork2->*pOut)(); // ���� out������ �̵�
				}
			}
		}
		else if (r > 0) { //r>0�� �� ���ذ��� row�� �����Ƿ�  row�������� �� ������ ������ ����
			for (int i = 0; i < cnt;i++) { // ó������ ������ ����
				pWork2 = pWork1;
				while (pWork2) {
					pWork3 = pWork2;
					while (pWork3) {
						pWork4 = (pWork3->*pOut)(); // Row�̹Ƿ� Out���� �̵�
						pWork3->setData(pWork3->getData() + pWork4->getData()); // Data���� ����
						(pWork3->*setOut)((pWork4->*pOut)()); // �������� Out�� ������ ���� Out���� ����
						if ((pWork4->*pOut)()) { // �� �̻� ���� ���� ���� ���
							((pWork4->*pOut)()->*setIn)(pWork3);
						}
						delete pWork4; // ť�� ���� ����
						pWork3 = (pWork3->*pRight)(); // ���� Right������ �̵�
					}
					pWork2 = (pWork2->*pDown)(); // ���� Down������ �̵�
				}
			}
		}
		cube_1D* pTemp_next = pTemp->getNext();
		for (int i = 0; i < cnt; i++) { // Cube_1D�� ���� ����
			pTemp->setNext(pTemp_next->getNext()); // ������ ���� ���� ���� ���ذ��� ���� ������ ����
			delete pTemp_next; // Cube_1D�� ����
			pTemp_next = pTemp->getNext(); // ���������� �̵�
			if (pTemp_next == nullptr) { // �������� �ͼ� nullptr�� �� ���� ���� nullptr�� ���� �� �ݺ��� ����
				pTemp->setNext(nullptr);
				break;
			}
			pTemp_next->setPrev(pTemp); // �������� �������� ����
		}
		tree_node* temp_tree = pTemp->getData();
		while (temp_tree->getUp()) { // root��带 �湮�ϱ� ���� ��� up�������� �̵�
			temp_tree = temp_tree->getUp();
		}
		pTemp->setData(temp_tree); // 1���� �̹Ƿ� ���� root����� ������ ����
	}
	return true; // true ��ȯ
}

void cube::delete_cube() { // cube�� �����ϴ� �żҵ�
	node* pWork1 = pHead;
	node* pWork2 = pHead;
	node* pWork3 = pHead;
	node* pWork4 = pHead;
	while (pWork1) { // Row���� �̵�
		pWork2 = pWork1;
		pWork1 = (pWork1->*pOut)(); // ����������
		while (pWork2) { // Height������ �̵�
			pWork3 = pWork2;
			pWork2 = (pWork2->*pDown)(); // ���������� �̵�
			while (pWork3) { // Column������ �̵� �� ����
				pWork4 = pWork3;
				pWork3 = (pWork3->*pRight)();
				delete pWork4;
			}
		}
	}
	cube_1D* pTemp = Row;
	while (pTemp) { // cube_1D�� Row���� ����
		Row = Row->getNext();
		delete pTemp;
		pTemp = Row;
	}
	pTemp = Column;
	while (pTemp) { // cube_1D�� Column���� ����
		Column = Column->getNext();
		delete pTemp;
		pTemp = Column;
	}
	pTemp = Height;
	while (pTemp) { // cube_1D�� Height���� ����
		Height = Height->getNext();
		delete pTemp;
		pTemp = Height;
	}
	Row = nullptr;
	Column = nullptr;
	Height = nullptr;
	pHead = nullptr;
	pRight = &node::getCnext; // �Լ������� �� �ʱ�ȭ
	pLeft = &node::getCprev;// �Լ������� �� �ʱ�ȭ 
	pUp = &node::getHprev;// �Լ������� �� �ʱ�ȭ 
	pDown = &node::getHnext;// �Լ������� �� �ʱ�ȭ 
	pIn = &node::getRprev;// �Լ������� �� �ʱ�ȭ 
	pOut = &node::getRnext;// �Լ������� �� �ʱ�ȭ 
	setRight = &node::setCnext;// �Լ������� �� �ʱ�ȭ 
	setLeft = &node::setCprev;// �Լ������� �� �ʱ�ȭ 
	setUp = &node::setHprev;// �Լ������� �� �ʱ�ȭ 
	setDown = &node::setHnext;// �Լ������� �� �ʱ�ȭ 
	setIn = &node::setRprev;// �Լ������� �� �ʱ�ȭ 
	setOut = &node::setRnext;// �Լ������� �� �ʱ�ȭ

	pRow = &cube::getRow;// �Լ������� �� �ʱ�ȭ 
	pColumn = &cube::getColumn;// �Լ������� �� �ʱ�ȭ 
	pHeight = &cube::getHeight;// �Լ������� �� �ʱ�ȭ 
	pRow_set = &cube::setRow;// �Լ������� �� �ʱ�ȭ 
	pColumn_set = &cube::setColumn;// �Լ������� �� �ʱ�ȭ 
	pHeight_set = &cube::setHeight;// �Լ������� �� �ʱ�ȭ 
}

bool cube::slice(char* command) { //slice�ϴ� �żҵ�
	bool find = false;
	int h = 0;
	int r = 0;
	int c = 0;
	int cnt = 0;
	int end = 0;
	int start = 0;
	cube_1D* pTemp = (this->*pRow)();
	while (!find) { // slice�ϰ� ���� ���� ã�� ���� ����
		while (pTemp) { // Row�� ��ȸ�ϸ鼭 ���� ���� �ִ��� Ȯ��
			if (strcmp(pTemp->getData()->getData(), command) == 0) {
				cnt++;
				r = cnt;
				find = true;
				break; // ������ ã���� �ݺ��� ����
			}
			pTemp = pTemp->getNext(); // ���������� �̵�
			cnt++;
		}
		if (find) // ���� ã���� �� �ݺ��� ����
			break;
		pTemp = (this->*pColumn)();
		cnt = 0;
		while (pTemp) { // Column���� ���� ã�� �ݺ���
			if (strcmp(pTemp->getData()->getData(), command) == 0) {
				cnt++;
				c = cnt;
				find = true;
				break; // ���� ã���� �� �ݺ�������
			}
			pTemp = pTemp->getNext(); // ���� ������ �̵�
			cnt++;
		}
		if (find)// ���� ã���� �� �ݺ��� ����
			break;
		pTemp = (this->*pHeight)();
		cnt = 0;
		while (pTemp) { // Height���� ���� ã�� �ݺ���
			if (strcmp(pTemp->getData()->getData(), command) == 0) {
				cnt++;
				h = cnt;
				find = true;
				break; //ã������ �ݺ��� ����
			}
			pTemp = pTemp->getNext(); // ���������� �̵�
			cnt++;
		}
		break; //�ݺ��� ����
	}
	if (find == true) { // ���� ã���� ��
		if (!pTemp->getData()->getUp()) { // 1�����϶��� slice�� ���� �� �ʿ䰡 �����Ƿ� true��ȯ
			return true;
		}
		else {
			cube_1D* pCount = pTemp->getNext(); // Count�� �ϱ� ���� �� �Ҵ�
			node* pWork1 = pHead;
			while (pCount) { // end������ ���� count
				end++;
				pCount = pCount->getNext();
			}
			pCount = pTemp->getPrev(); // start������ ���� count�ϱ� ���� �Ҵ�
			while (pCount) { // start������ ���� count
				start++;
				pCount = pCount->getPrev(); // ���������� ��� �̵�
			}
			pWork1 = pHead;
			if (h > 0) { // ���� Height�� ���� ��
				node* Copy_Work1 = pWork1; // ���� �ѹ��� ���� ���ؼ� ���� �س���
				for (int i = 0; i < h - 1; i++) { // Head�� Height�̱� ������ Down���� �̵�
					Copy_Work1 = (Copy_Work1->*pDown)();
				}
				pHead = Copy_Work1;
				pWork1 = Copy_Work1;
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < end; i++) { // ���ذ����� �������� ����
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pDown)(); // ���ذ��� Down������ �̵�
							(pWork3->*setDown)((pWork4->*pDown)()); //������ ���� ���� ������ ���� ���� �������� ����
							if ((pWork4->*pDown)()) { // ���̻� Down���� ���� ���
								((pWork4->*pDown)()->*setUp)(pWork3);
							}
							delete pWork4; // ť�� ����
							pWork3 = (pWork3->*pRight)(); // ���� right�� �̵�
						}
						pWork2 = (pWork2->*pOut)(); // ���� Out���� �̵�
					}
				}
				pWork1 = Copy_Work1;
				pWork2 = pWork1;
				pWork3 = pWork1;
				pWork4 = pWork1;
				for (int i = 0; i < start; i++) { // ���� ������ start������ ���� 
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pUp)(); // ���� up������ �̵�
							(pWork3->*setUp)((pWork4->*pUp)()); // ������ ���� ���� ������ ���������� ����
							if ((pWork4->*pUp)()) { // ���̻� up���� ���� ���
								((pWork4->*pUp)()->*setDown)(pWork3);
							}
							delete pWork4; // ť�� ����
							pWork3 = (pWork3->*pRight)(); // ���� right������ �̵�
						}
						pWork2 = (pWork2->*pOut)(); // ���� out������ �̵�
					}
				}
			}
			else if (c > 0) { // ���� column�� ���� �� Height�� ���� ����
				node* Copy_Work1 = pHead;
				for (int i = 0; i < c - 1; i++) { // head�̵�
					Copy_Work1 = (Copy_Work1->*pRight)();
				}
				pHead = Copy_Work1;
				pWork1 = Copy_Work1;
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < end; i++) { //end�� ���� �̵�
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pRight)(); // ���� right ���� ����
							(pWork3->*setRight)((pWork4->*pRight)()); // ������ ���� ���� ������ ���� ���� ����
							if ((pWork4->*pRight)()) { // ���̻� right���� ���� ���
								((pWork4->*pRight)()->*setLeft)(pWork3);
							}
							delete pWork4; // ť�� ����
							pWork3 = (pWork3->*pDown)(); // Down���� �̵�
						}
						pWork2 = (pWork2->*pOut)(); // ���� Out���� �̵�
					}
				}
				pWork1 = Copy_Work1;
				pWork2 = pWork1;
				pWork3 = pWork1;
				pWork4 = pWork1;
				for (int i = 0; i < start; i++) { // start������ �̵� �̵�
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pLeft)(); // ���� left ���� ����
							(pWork3->*setLeft)((pWork4->*pLeft)()); // ���� �� ���� ���� ���� �������� ���������� ����
							if ((pWork4->*pLeft)()) { // left���� ���� ���
								((pWork4->*pLeft)()->*setRight)(pWork3);
							}
							delete pWork4; // ť�긦 ����
							pWork3 = (pWork3->*pDown)(); // ���� down���� �̵�
						}
						pWork2 = (pWork2->*pOut)(); // ���� out���� �̵�
					}
				}
			}
			else if (r > 0) { // ���� column�� ���� ��
				node* Copy_Work1 = pHead;
				for (int i = 0; i < r - 1; i++) { // head���� �̵�
					Copy_Work1 = (Copy_Work1->*pOut)();
				}
				pHead = Copy_Work1;
				pWork1 = Copy_Work1;
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < end; i++) { // end�� ���� ����
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pOut)(); // ���� out ���� ����
							(pWork3->*setOut)((pWork4->*pOut)()); // ������ ���� ���� ���� ���� ���� ���� ������ ����
							if ((pWork4->*pOut)()) { // out���� ���� ���
								((pWork4->*pOut)()->*setIn)(pWork3);
							}
							delete pWork4; //ť�긦 ����
							pWork3 = (pWork3->*pRight)(); // ���� right������ �̵�
						}
						pWork2 = (pWork2->*pDown)(); // ���� Down������ �̵�
					}
				}
				pWork1 = Copy_Work1;
				pWork2 = pWork1;
				pWork3 = pWork1;
				pWork4 = pWork1;
				for (int i = 0; i < start; i++) { // start�� ���� ����
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pIn)(); // ���� In���� ����
							(pWork3->*setIn)((pWork4->*pIn)()); // ������ ���� ���� ���� ���� ���� ���� ������ ����
							if ((pWork4->*pIn)()) { // in���� ���� ���
								((pWork4->*pIn)()->*setOut)(pWork3);
							}
							delete pWork4; // ť�긦 ����
							pWork3 = (pWork3->*pRight)(); // ���� Right������ �̵�
						}
						pWork2 = (pWork2->*pDown)(); // ���� down������ �̵�
					}
				}

			}
			cube_1D* pTemp_next = pTemp->getNext();
			cube_1D* pTemp_prev = pTemp->getPrev();
			for (int i = 0; i < end; i++) { // end������ cube_1D�� ���� ����
				pTemp->setNext(pTemp_next->getNext()); // ������ ���� ���� ���� ���� ���� ���� ������ ����
				delete pTemp_next; // cube_1D���� ����
				pTemp_next = pTemp->getNext(); // ���� ������ �̵�
				if (pTemp_next == nullptr) { // �������� ���� ���
					pTemp->setNext(nullptr); // nullptr�� ����
					break; // �ݺ��� ����
				}
				pTemp_next->setPrev(pTemp); // ����������
			}
			for (int i = 0; i < start; i++) { // start�� ���� �̵�
				pTemp->setPrev(pTemp_prev->getPrev()); // ������ ���� ���� ���� ���� ���� ���� ������ ����
				delete pTemp_prev; // cube_1D���� ����
				pTemp_prev = pTemp->getPrev(); // ���������� �̵�
				if (pTemp_prev == nullptr) { // �������� ���� ���
					pTemp->setPrev(nullptr); // nullptr�� ����
					break; // �ݺ�������
				}
			}
			if (h > 0) { // head���� �ٽ� �������ִ� ���ǹ�
				(this->*pHeight_set)(pTemp);
			}
			else if (c > 0) {
				(this->*pColumn_set)(pTemp);
			}
			else if (r > 0) {
				(this->*pRow_set)(pTemp);
			}
		}
	}
	else { //���� ���� ��� false�� return
		return false;
	}

}

/*(bool cube::DrillDown(char* command ) {
	//������ ����մϴ�...
}*/

void cube::WriteError(char* command) { // ���� log�� ����� �żҵ�
	ofstream log;
	log.open("log.txt", ios::app); // log.txt������ ����
	log << "[" << command << "]" << endl; // ������
	log << "ERROR" << '\n' << '\n';
	log.close(); // ���ϴݱ�
}