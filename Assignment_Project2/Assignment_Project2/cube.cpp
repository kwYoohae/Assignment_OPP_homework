#include "cube.h"
#include <iostream>
#include <iomanip>

using namespace std;

cube::cube() {
	pHead = nullptr;
	pRow = nullptr;
	pColumn = nullptr;
	pHeight = nullptr;
}

cube::~cube() {

}

cube_1D* cube::getRow() {
	return pRow;
}
cube_1D* cube::getColumn() {
	return pColumn;
}
cube_1D* cube::getHeight() {
	return pHeight;
}
node* cube::getHead() {
	return pHead;
}

void cube::setRow(cube_1D* pTemp) {
	pRow = pTemp;
}
void cube::setColumn(cube_1D* pTemp) {
	pColumn = pTemp;
}
void cube::setHeight(cube_1D* pTemp) {
	pHeight = pTemp;
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
			if (!pRow) {
				pRow = pNew;
				pNew->setName(pTemp->getData());
			}
			else {
				cube_1D* cube_temp = pRow;
				while (cube_temp->getNext())
					cube_temp = cube_temp->getNext();
				cube_temp->setNext(pNew);
				pNew->setPrev(cube_temp);
				pNew->setName(pTemp->getData());
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
			if (!pColumn) {
				pColumn = pNew;
				pNew->setName(pTemp->getData());
			}
			else {
				cube_1D* cube_temp = pColumn;
				while (cube_temp->getNext())
					cube_temp = cube_temp->getNext();
				cube_temp->setNext(pNew);
				pNew->setPrev(cube_temp);
				pNew->setName(pTemp->getData());
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
			if (!pHeight) {
				pHeight = pNew;
				pNew->setName(pTemp->getData());
			}
			else {
				cube_1D* cube_temp = pHeight;
				while (cube_temp->getNext())
					cube_temp = cube_temp->getNext();
				cube_temp->setNext(pNew);
				pNew->setPrev(cube_temp);
				pNew->setName(pTemp->getData());
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
					while (pWork2->getCnext()) {
						pWork2 = pWork2->getCnext();
					}
					pWork2->setCnext(pNew);
					pNew->setCprev(pWork2);
					pWork3 = pNew;
				}
				else {
					while (pWork3->getRnext()) {
						pWork3 = pWork3->getRnext();
					}
					pWork3->setRnext(pNew);
					pNew->setRprev(pWork3);
				}
			}
			if (j != 0) {
				pWork1 = pHead;
				while (pWork1->getHnext()) {
					pWork1 = pWork1->getHnext();
				}
				pWork3 = pWork1;
				while (pWork3->getCnext()) {
					pWork3 = pWork3->getCnext();
				}
				pWork2 = pWork3->getCprev();
				while (pWork2) {
					pWork2->setCnext(pWork3);
					pWork3->setCprev(pWork2);
					pWork2 = pWork2->getRnext();
					pWork3 = pWork3->getRnext();
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
					pWork2 = pWork2->getRnext();
					pWork3 = pWork3->getRnext();
				}
				pWork2 = pWork1->getHprev()->getCnext();
				pWork3 = pWork1->getCnext();
				pWork1 = pWork1->getCnext();
			}
		}
	}
}

void cube::Print() {
	cout.setf(ios::left);
	int t = count_time();
	int p = count_product();
	int l = count_location();
	node* pWork1 = pHead;
	node* pWork2 = pHead;
	node* pWork3 = pHead;
	cube_1D* pTemp_l = pColumn;
	cube_1D* pTemp_t = pRow;
	cube_1D* pTemp_p = pHeight;
	for (int i = 0; i < t; i++) {
		pTemp_l = pColumn;
		pTemp_p = pHeight;
		cout << pTemp_t->getName() << '\t';
		pTemp_t = pTemp_t->getNext();
		for (int j = 0; j < l;j++) {
			while (pTemp_p) {
				cout << pTemp_p->getName() << '\t';
				pTemp_p = pTemp_p->getNext();
			}
			cout << '\n';
			for (int k = 0; k < p; k++) {
				if (k == 0) {
					cout << pTemp_l->getName() << '\t';
					pTemp_l = pTemp_l->getNext();
				}
				cout << pWork3->getData() << '\t';
				pWork3 = pWork3->getHnext();
			}
			cout << '\n';
			pWork2 = pWork2->getCnext();
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

void cube::Make_View(cube* raw,tree* Time, tree* Location, tree* Product) {
	node* pWork1 = pHead;
	node* pWork2 = pWork1->getRnext();
	node* pWork1_head = pWork1;
	node* pWork2_head = pWork2;
	node* pTemp;
	cube_1D* time_tree = pRow;
	cube_1D* location_tree = pColumn;
	cube_1D* product_tree = pHeight;
	while(time_tree){
		int number = Time->cnt_chiled(time_tree->getName());
		pWork2 = pWork1;
		for (int i = 1; i < number;i++) {
			pWork2 = pWork2->getRnext();
		}
		pWork1 = pWork2->getRprev();
		pWork2_head = pWork2;
		pWork1_head = pWork1;
		pTemp = pWork2;
		for (int i = 1; i < number; i++) {
			while (pWork1_head) {
				pWork1->setData(pWork2->getData() + pWork1->getData());
				pWork1 = pWork1->getHnext();
				pWork2 = pWork2->getHnext();
				if (!pWork1) {
					pWork1_head = pWork1_head->getCnext();
					pWork2_head = pWork2_head->getCnext();
					pWork1 = pWork1_head;
					pWork2 = pWork2_head;
				}
			}
			pTemp = pTemp->getRprev();
			pWork1 = pTemp->getRprev();
			pWork2 = pTemp;
			pWork1_head = pWork1;
			pWork2_head = pWork2;
		}

		time_tree = time_tree->getNext();
	}

}