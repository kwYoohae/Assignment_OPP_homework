#include "cube.h"
#include <iostream>
#include <iomanip>

using namespace std;

cube::cube() {
	pHead = nullptr;
	pTime = nullptr;
	pLocation = nullptr;
	pProduct = nullptr;
}

cube::~cube() {

}

cube_1D* cube::getTime() {
	return pTime;
}
cube_1D* cube::getLocation() {
	return pLocation;
}
cube_1D* cube::getProduct() {
	return pProduct;
}
node* cube::getHead() {
	return pHead;
}

void cube::setTime(cube_1D* pTemp) {
	pTime = pTemp;
}
void cube::setLocation(cube_1D* pTemp) {
	pLocation = pTemp;
}
void cube::setProduct(cube_1D* pTemp) {
	pProduct = pTemp;
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
			if (!pTime) {
				pTime = pNew;
				pNew->setName(pTemp->getData());
			}
			else {
				cube_1D* cube_temp = pTime;
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
			if (!pLocation) {
				pLocation = pNew;
				pNew->setName(pTemp->getData());
			}
			else {
				cube_1D* cube_temp = pLocation;
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
			if (!pProduct) {
				pProduct = pNew;
				pNew->setName(pTemp->getData());
			}
			else {
				cube_1D* cube_temp = pProduct;
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
					while (pWork1->getPnext()) {
						pWork1 = pWork1->getPnext();
					}
					pWork1->setPnext(pNew);
					pNew->setPprev(pWork1);
					pWork2 = pNew;
					pWork3 = pNew;
				}
				else if (k == 0) {
					pWork1 = pHead;
					while (pWork1->getPnext()) {
						pWork1 = pWork1->getPnext();
					}
					pWork2 = pWork1;
					while (pWork2->getLnext()) {
						pWork2 = pWork2->getLnext();
					}
					pWork2->setLnext(pNew);
					pNew->setLprev(pWork2);
					pWork3 = pNew;
				}
				else {
					while (pWork3->getTnext()) {
						pWork3 = pWork3->getTnext();
					}
					pWork3->setTnext(pNew);
					pNew->setTprev(pWork3);
				}
			}
			if (j != 0) {
				pWork1 = pHead;
				while (pWork1->getPnext()) {
					pWork1 = pWork1->getPnext();
				}
				pWork3 = pWork1;
				while (pWork3->getLnext()) {
					pWork3 = pWork3->getLnext();
				}
				pWork2 = pWork3->getLprev();
				while (pWork2) {
					pWork2->setLnext(pWork3);
					pWork3->setLprev(pWork2);
					pWork2 = pWork2->getTnext();
					pWork3 = pWork3->getTnext();
				}
			}
		}
		if (i != 0) {
			pWork1 = pHead;
			while (pWork1->getPnext()) {
				pWork1 = pWork1->getPnext();
			}
			pWork2 = pWork1->getPprev();
			pWork3 = pWork1;
			while (pWork1) {
				while (pWork2) {
					pWork2->setPnext(pWork3);
					pWork3->setPprev(pWork2);
					pWork2 = pWork2->getTnext();
					pWork3 = pWork3->getTnext();
				}
				pWork2 = pWork1->getPprev()->getLnext();
				pWork3 = pWork1->getLnext();
				pWork1 = pWork1->getLnext();
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
	cube_1D* pTemp_l = pLocation;
	cube_1D* pTemp_t = pTime;
	cube_1D* pTemp_p = pProduct;
	for (int i = 0; i < t; i++) {
		pTemp_l = pLocation;
		pTemp_p = pProduct;
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
				pWork3 = pWork3->getPnext();
			}
			cout << '\n';
			pWork2 = pWork2->getLnext();
			pWork3 = pWork2;
		}
		cout << '\n' << '\n';
		pWork1 = pWork1->getTnext();
		pWork2 = pWork1;
		pWork3 = pWork1;
	}
}

int cube::count_time() {
	int count = 0;
	node* pTemp = pHead;
	while (pTemp) {
		pTemp = pTemp->getTnext();
		count++;
	}
	return count;
}
int cube::count_location() {
	int count = 0;
	node* pTemp = pHead;
	while (pTemp) {
		pTemp = pTemp->getLnext();
		count++;
	}
	return count;
}
int cube::count_product() {
	int count = 0;
	node* pTemp = pHead;
	while (pTemp) {
		pTemp = pTemp->getPnext();
		count++;
	}
	return count;
}

void cube::Make_View(cube* raw,tree* Time, tree* Location, tree* Product) {
	node* pWork1 = pHead;
	node* pWork2 = pWork1->getTnext();
	node* pWork1_head = pWork1;
	node* pWork2_head = pWork2;
	node* pTemp;
	cube_1D* time_tree = pTime;
	cube_1D* location_tree = pLocation;
	cube_1D* product_tree = pProduct;
	while(time_tree){
		int number = Time->cnt_chiled(time_tree->getName());
		pWork2 = pWork1;
		for (int i = 1; i < number;i++) {
			pWork2 = pWork2->getTnext();
		}
		pWork1 = pWork2->getTprev();
		pWork2_head = pWork2;
		pWork1_head = pWork1;
		pTemp = pWork2;
		for (int i = 1; i < number; i++) {
			while (pWork1_head) {
				pWork1->setData(pWork2->getData() + pWork1->getData());
				pWork1 = pWork1->getPnext();
				pWork2 = pWork2->getPnext();
				if (!pWork1) {
					pWork1_head = pWork1_head->getLnext();
					pWork2_head = pWork2_head->getLnext();
					pWork1 = pWork1_head;
					pWork2 = pWork2_head;
				}
			}
			pTemp = pTemp->getTprev();
			pWork1 = pTemp->getTprev();
			pWork2 = pTemp;
			pWork1_head = pWork1;
			pWork2_head = pWork2;
		}

		time_tree = time_tree->getNext();
	}

}