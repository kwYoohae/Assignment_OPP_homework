#include "cube.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

cube::cube() {
	pHead = nullptr;
	Row = nullptr;
	Column = nullptr;
	Height = nullptr;
}

cube::~cube() {
}

cube_1D* cube::getRow() {
	return Row;
}
cube_1D* cube::getColumn() {
	return Column;
}
cube_1D* cube::getHeight() {
	return Height;
}
node* cube::getHead() {
	return pHead;
}

void cube::setRow(cube_1D* pTemp) {
	Row = pTemp;
}
void cube::setColumn(cube_1D* pTemp) {
	Column = pTemp;
}
void cube::setHeight(cube_1D* pTemp) {
	Height = pTemp;
}
void cube::setHead(node* pTemp) {
	pHead = pTemp;
}

void cube::Make_tree(tree* Time, tree* Location, tree* Product, int number) {
	tree_node* pTemp = Time->getRoot();
	tree_node* pParent = pTemp;
	for (int i = 1; i < number; i++) {
		pParent = pTemp;
		pTemp = pTemp->getDown();
		if (!pTemp->getDown()) {
			break;
		}
	}
	while (pParent) {
		while (pTemp) {
			cube_1D* pNew = new cube_1D;
			if (!Row) {
				Row = pNew;
				pNew->setData(pTemp);
			}
			else {
				cube_1D* cube_temp = Row;
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

	pTemp = Location->getRoot();
	pParent = pTemp;
	for (int i = 1; i < number; i++) {
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
				cube_1D* cube_temp = Column;
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

	pTemp = Product->getRoot();
	pParent = pTemp;
	for (int i = 1; i < number; i++) {
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
				pNew->setName(pTemp->getData());
				pNew->setData(pTemp);
			}
			else {
				cube_1D* cube_temp = Height;
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

void cube::Make_Cube(int p, int l, int t) {
	int cnt = 1;
	node* pWork1 = nullptr;
	node* pWork2 = nullptr;
	node* pWork3 = nullptr;
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < l; j++) {
			for (int k = 0; k < t; k++) {
				node* pNew = new node;
				if (i == 0 && j == 0 && k == 0) {
					pHead = pNew;
					pWork1 = pHead;
					pWork2 = pHead;
					pWork3 = pHead;
				}
				else if (i != 0 && k == 0 && j == 0) {
					pWork1 = pHead;
					while (pWork1->getHnext()) {
						pWork1 = pWork1->getHnext();
					}
					pWork1->setHnext(pNew);
					pNew->setHprev(pWork1);
					pWork2 = pNew;
					pWork3 = pNew;
				}
				else if (k == 0) {
					pWork1 = pHead;
					while (pWork1->getHnext()) {
						pWork1 = pWork1->getHnext();
					}
					pWork2 = pWork1;
					while (pWork2->getRnext()) {
						pWork2 = pWork2->getRnext();
					}
					pWork2->setRnext(pNew);
					pNew->setRprev(pWork2);
					pWork3 = pNew;
				}
				else {
					while (pWork3->getCnext()) {
						pWork3 = pWork3->getCnext();
					}
					pWork3->setCnext(pNew);
					pNew->setCprev(pWork3);
				}
				//pNew->setData(cnt);
				//cnt++;
			}
			if (j != 0) {
				pWork1 = pHead;
				while (pWork1->getHnext()) {
					pWork1 = pWork1->getHnext();
				}
				pWork3 = pWork1;
				while (pWork3->getRnext()) {
					pWork3 = pWork3->getRnext();
				}
				pWork2 = pWork3->getRprev();
				while (pWork2) {
					pWork2->setRnext(pWork3);
					pWork3->setRprev(pWork2);
					pWork2 = pWork2->getCnext();
					pWork3 = pWork3->getCnext();
				}
			}
		}
		if (i != 0) {
			pWork1 = pHead;
			while (pWork1->getHnext()) {
				pWork1 = pWork1->getHnext();
			}
			pWork2 = pWork1->getHprev();
			pWork3 = pWork1;
			while (pWork1) {
				while (pWork2) {
					pWork2->setHnext(pWork3);
					pWork3->setHprev(pWork2);
					pWork2 = pWork2->getCnext();
					pWork3 = pWork3->getCnext();
				}
				pWork2 = pWork1->getHprev()->getRnext();
				pWork3 = pWork1->getRnext();
				pWork1 = pWork1->getRnext();
			}
		}
	}
}

void cube::Print() {
	cout.setf(ios::left);
	int R = 0;
	int C = 0;
	int H = 0;
	cube_1D* pTemp = Row;
	while (pTemp) {
		R++;
		pTemp = pTemp->getNext();
	}
	pTemp = Column;
	while (pTemp) {
		C++;
		pTemp = pTemp->getNext();
	}
	pTemp = Height;
	while (pTemp) {
		H++;
		pTemp = pTemp->getNext();
	}
	node* pWork1 = pHead;
	node* pWork2 = pHead;
	node* pWork3 = pHead;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < C;k++) {
				cout << pWork3->getData() << '\t';
				pWork3 = pWork3->getCnext();
			}
			cout << '\n';
			pWork2 = pWork2->getHnext();
			pWork3 = pWork2;
		}
		cout << '\n' << '\n';
		pWork1 = pWork1->getRnext();
		pWork2 = pWork1;
		pWork3 = pWork1;
	}
}

int cube::count_time() {
	int count = 0;
	node* pTemp = pHead;
	while (pTemp) {
		pTemp = pTemp->getRnext();
		count++;
	}
	return count;
}
int cube::count_location() {
	int count = 0;
	node* pTemp = pHead;
	while (pTemp) {
		pTemp = pTemp->getCnext();
		count++;
	}
	return count;
}
int cube::count_product() {
	int count = 0;
	node* pTemp = pHead;
	while (pTemp) {
		pTemp = pTemp->getHnext();
		count++;
	}
	return count;
}

void cube::Make_View(tree* Time, tree* Location, tree* Product) {
	int number = 0;
	node* pWork1 = pHead;
	node* pWork2;
	node* pWork3;
	node* pWork4;
	tree_node* pTemp;
	tree_node* tree_temp = Height->getData();
	tree_node* tree_down = tree_temp->getDown();
	pTemp = tree_temp;
	while (tree_down->getNext()) {
		tree_down = tree_down->getNext();
		number++;
	}
	while (tree_temp) {
		for (int i = 0; i < number; i++) {
			pWork2 = pWork1;
			while (pWork2) {
				pWork3 = pWork2;
				while (pWork3) {
					pWork4 = pWork3->getHnext();
					//pWork3->setData(pWork3->getData() + pWork4->getData());
					pWork3->setHnext(pWork4->getHnext());
					if (pWork4->getHnext()) {
						pWork4->getHnext()->setHprev(pWork3);
					}
					delete pWork4;
					pWork3 = pWork3->getCnext();
				}
				pWork2 = pWork2->getRnext();
			}
		}
		pWork1 = pWork1->getHnext();
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

	tree_temp = Row->getData();
	pTemp = tree_temp;
	pWork1 = pHead;
	number = 0;
	tree_down = tree_temp->getDown();
	while (tree_down->getNext()) {
		tree_down = tree_down->getNext();
		number++;
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

	tree_temp = Column->getData();
	pTemp = tree_temp;
	pWork1 = pHead;
	number = 0;
	tree_down = tree_temp->getDown();
	while (tree_down->getNext()) {
		tree_down = tree_down->getNext();
		number++;
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

void cube::WriteLog(char* command) {
	ofstream log;
	log.open("log.txt", ios::app);
	log << '[' << command << ']' <<'\n';
	log << (this->*pRow)()->getData()->getData() << '\t';
	cube_1D* pTemp = (this->*pColumn)();
	while (pTemp) {
		log << pTemp->getData()->getData() << '\t';
		pTemp = pTemp->getNext();
	}
	log << '\n';
	pTemp = (this->*pHeight)();
	node* pWork1 = pHead;
	node* pWork2 = pWork1;
	while (pWork2) {
		log << pTemp->getData()->getData() << '\t';
		pTemp = pTemp->getNext();
		while (pWork1) {
			log << pWork1->getData() << '\t' << '\t';
			pWork1 = pWork1->getCnext();
		}
		log << '\n';
		pWork2 = pWork2->getHnext();
		pWork1 = pWork2;
	}
	log << '\n' << '\n';
	log.close();
}

void cube::copyData(cube* raw) {
	node* pWork1 = raw->getHead();
	node* pWork2 = pWork1;
	node* pWork3 = pWork1;
	node* pCopy1 = pHead;
	node* pCopy2 = pCopy1;
	node* pCopy3 = pCopy1;
	while (pWork1) {
		while (pWork2) {
			while (pWork3) {
				pCopy3->setData(pWork3->getData());
				pWork3 = pWork3->getCnext();
				pCopy3 = pCopy3->getCnext();
			}
			pWork2 = pWork2->getHnext();
			pCopy2 = pCopy2->getHnext();
			pWork3 =pWork2;
			pCopy3 = pCopy2;
		}
		pWork1 = pWork1->getRnext();
		pCopy1 = pCopy1->getRnext();
		pWork2 = pWork1;
		pWork3 = pWork1;
		pCopy3 = pCopy1;
		pCopy2 = pCopy1;
	}
}