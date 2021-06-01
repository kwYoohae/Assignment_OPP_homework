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
				cube_1D* cube_temp = (this->*pRow)();
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

void cube::Make_Cube(int p, int l, int t) {
	int cnt = 1;
	node* pWork1 = nullptr;
	node* pWork2 = nullptr;
	node* pWork3 = nullptr;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < l; k++) {
				node* pNew = new node;
				if (i == 0 && j == 0 && k == 0) {
					pHead = pNew;
					pWork1 = pHead;
					pWork2 = pHead;
					pWork3 = pHead;
				}
				else if (i != 0 && k == 0 && j == 0) {
					pWork1 = pHead;
					while (pWork1->getRnext()) {
						pWork1 = pWork1->getRnext();
					}
					pWork1->setRnext(pNew);
					pNew->setRprev(pWork1);
					pWork2 = pNew;
					pWork3 = pNew;
				}
				else if (k == 0) {
					pWork1 = pHead;
					while (pWork1->getRnext()) {
						pWork1 = pWork1->getRnext();
					}
					pWork2 = pWork1;
					while (pWork2->getHnext()) {
						pWork2 = pWork2->getHnext();
					}
					pWork2->setHnext(pNew);
					pNew->setHprev(pWork2);
					pWork3 = pNew;
				}
				else {
					while (pWork3->getCnext()) {
						pWork3 = pWork3->getCnext();
					}
					pWork3->setCnext(pNew);
					pNew->setCprev(pWork3);
				}
				pNew->setData(cnt);
				//cnt++;
			}
			if (j != 0) {
				pWork1 = pHead;
				while (pWork1->getRnext()) {
					pWork1 = pWork1->getRnext();
				}
				pWork3 = pWork1;
				while (pWork3->getHnext()) {
					pWork3 = pWork3->getHnext();
				}
				pWork2 = pWork3->getHprev();
				while (pWork2) {
					pWork2->setHnext(pWork3);
					pWork3->setHprev(pWork2);
					pWork2 = pWork2->getCnext();
					pWork3 = pWork3->getCnext();
				}
			}
		}
		if (i != 0) {
			pWork1 = pHead;
			while (pWork1->getRnext()) {
				pWork1 = pWork1->getRnext();
			}
			pWork2 = pWork1->getRprev();
			pWork3 = pWork1;
			while (pWork1) {
				while (pWork2) {
					pWork2->setRnext(pWork3);
					pWork3->setRprev(pWork2);
					pWork2 = pWork2->getCnext();
					pWork3 = pWork3->getCnext();
				}
				pWork2 = pWork1->getRprev()->getHnext();
				pWork3 = pWork1->getHnext();
				pWork1 = pWork1->getHnext();
			}
		}
	}
}

void cube::Print() {
	cout.setf(ios::left);
	int R = 0;
	int C = 0;
	int H = 0;
	cube_1D* pTemp = (this->*pRow)();
	while (pTemp) {
		R++;
		pTemp = pTemp->getNext();
	}
	pTemp = (this->*pColumn)();
	while (pTemp) {
		C++;
		pTemp = pTemp->getNext();
	}
	pTemp = (this->*pHeight)();
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
				pWork3 = (pWork3->*pRight)();
			}
			cout << '\n';
			pWork2 = (pWork2->*pDown)();
			pWork3 = pWork2;
		}
		cout << '\n' << '\n';
		pWork1 = (pWork1->*pOut)();
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
			pWork1 = (pWork1->*pRight)();
		}
		log << '\n';
		pWork2 = (pWork2->*pDown)();
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

void cube::Rotate(char* command) {
	node* (node:: * pRight_temp)() = pRight;
	node* (node:: * pLeft_temp)() = pLeft;
	node* (node:: * pUp_temp)() = pUp;
	node* (node:: * pDown_temp)() = pDown;
	node* (node:: * pIn_temp)() = pIn;
	node* (node:: * pOut_temp)() = pOut;
	void (node:: * setRight_temp)(node * pTemp) = setRight;
	void (node:: * setLeft_temp)(node * pTemp) = setLeft;
	void (node:: * setUp_temp)(node * pTemp) = setUp;
	void (node:: * setDown_temp)(node * pTemp) = setDown;
	void (node:: * setIn_temp)(node * pTemp) = setIn;
	void (node:: * setOut_temp)(node * pTemp) = setOut;

	cube_1D* (cube:: * pRow_temp)() = pRow;
	cube_1D* (cube:: * pColumn_temp)() = pColumn;
	cube_1D* (cube:: * pHeight_temp)() = pHeight;
	void (cube:: * pRow_set_temp)(cube_1D * pTemp) = pRow_set;
	void (cube:: * pColumn_set_temp)(cube_1D * pTemp) = pColumn_set;
	void (cube:: * pHeight_set_temp)(cube_1D * pTemp) = pHeight_set;
	if (strcmp(command, "clockwise") == 0) {
		while ((pHead->*pDown)()) {
			pHead = (pHead->*pDown)();
		}
		pRight = pUp_temp;
		setRight = setUp_temp;
		pLeft = pDown_temp;
		setLeft = setDown_temp;
		pDown = pRight_temp;
		setDown = setRight_temp;
		pUp = pLeft_temp;
		setUp = setLeft_temp;
		pHeight = pColumn_temp;
		pColumn = pHeight_temp;
		pHeight_set = pColumn_set_temp;
		pColumn_set = pHeight_set_temp;
		Reverse((this->*pColumn)());
	}
	else if (strcmp(command, "c_clockwise") == 0) {
		while ((pHead->*pRight)()) {
			pHead = (pHead->*pRight)();
		}
		pRight = pDown_temp;
		setRight = setDown_temp;
		pLeft = pUp_temp;
		setLeft = setUp_temp;
		pDown = pLeft_temp;
		setDown = setLeft_temp;
		pUp = pRight_temp;
		setUp = setRight_temp;
		pHeight = pColumn_temp;
		pColumn = pHeight_temp;
		pHeight_set = pColumn_set_temp;
		pColumn_set = pHeight_set_temp;
		Reverse((this->*pHeight)());
	}
	else if (strcmp(command, "left") == 0) {
		while ((pHead->*pRight)()) {
			pHead = (pHead->*pRight)();
		}
		pRight = pOut_temp;
		setRight = setOut_temp;
		pLeft = pIn_temp;
		setLeft = setIn_temp;
		pOut = pLeft_temp;
		setOut = setLeft_temp;
		pIn = pRight_temp;
		setIn = setRight_temp;
		pColumn = pRow_temp;
		pRow = pColumn_temp;
		pColumn_set = pRow_set_temp;
		pRow_set = pColumn_set_temp;
	}
	else if (strcmp(command, "right") == 0) {
		while ((pHead->*pOut)()) {
			pHead = (pHead->*pOut)();
		}
		pRight = pIn_temp;
		setRight = setIn_temp;
		pLeft = pOut_temp;
		setLeft = setOut_temp;
		pOut = pRight_temp;
		setOut = setRight_temp;
		pIn = pLeft_temp;
		setIn = setLeft_temp;
		pColumn = pRow_temp;
		pRow = pColumn_temp;
	}
	else if (strcmp(command, "up") == 0) {
		while ((pHead->*pDown)()) {
			pHead = (pHead->*pDown)();
		}
		pDown = pOut_temp;
		setDown = setOut_temp;
		pUp = pIn_temp;
		setUp = setIn_temp;
		pOut = pUp_temp;
		setOut = setUp_temp;
		pIn = pDown_temp;
		setIn = setDown_temp;
		pHeight = pRow_temp;
		pRow = pHeight_temp;
		pHeight_set = pRow_set_temp;
		pRow_set = pHeight_set_temp;
		Reverse((this->*pHeight)());
		Reverse((this->*pRow)());
	}
	else if (strcmp(command, "down") == 0) {
		while ((pHead->*pOut)()) {
			pHead = (pHead->*pOut)();
		}
		pDown = pIn_temp;
		setDown = setIn_temp;
		pUp = pOut_temp;
		setUp = setOut_temp;
		pOut = pDown_temp;
		setOut = setDown_temp;
		pIn = pUp_temp;
		setIn = setUp_temp;
		pHeight = pRow_temp;
		pRow = pHeight_temp;
		pHeight_set = pRow_set_temp;
		pRow_set = pHeight_set_temp;
		Reverse((this->*pHeight)());
		Reverse((this->*pRow)());
	}
}

void cube::check() {
	cube_1D* pTemp = (this->*pRow)();
	cout << "Row :";
	while (pTemp) {
		cout << pTemp->getData()->getData() << '\t';
		pTemp = pTemp->getNext();
	}
	cout << '\n';
	pTemp = (this->*pColumn)();
	cout << "pColumn :";
	while (pTemp) {
		cout << pTemp->getData()->getData() << '\t';
		pTemp = pTemp->getNext();
	}
	cout << '\n';
	pTemp = (this->*pHeight)();
	cout << "pHeight :";
	while (pTemp) {
		cout << pTemp->getData()->getData() << '\t';
		pTemp = pTemp->getNext();
	}
	cout << '\n';
}

void cube::Reverse(cube_1D* pCube) {
	cube_1D* pHead = pCube;
	cube_1D* pTemp1 = pHead;
	cube_1D* pPrev = nullptr;
	cube_1D* pNode = pHead;
	int cnt = 0;
	while (pNode->getNext()) {
		pNode = pNode->getNext();
		cnt++;
	}
	pTemp1 = pNode;
	while (cnt != 0) {
		pNode = pHead;
		for (int i = 0; i < cnt; i++) {
			pPrev = pNode;
			pNode = pNode->getNext();
		}
		pNode->setNext(pPrev);
		cnt--;
	}
	pPrev->setNext(nullptr);
	if (pCube == Row)
		Row = pTemp1;
	else if (pCube == Column)
		Column = pTemp1;
	else if (pCube == Height)
		Height = pTemp1;
	while (pTemp1) {
		cout << pTemp1->getData()->getData() << '\t';
		pTemp1 = pTemp1->getNext();
	}
}

void cube::Roll_up(char* command) {

}

void cube::delete_cube() {
	node* pWork1 = pHead;
	node* pWork2 = pHead;
	node* pWork3 = pHead;
	node* pWork4 = pHead;
	while (pWork1) {
		pWork2 = pWork1;
		pWork1 = (pWork1->*pOut)();
		while (pWork2) {
			pWork3 = pWork2;
			pWork2 = (pWork2->*pDown)();
			while (pWork3) {
				pWork4 = pWork3;
				pWork3 = (pWork3->*pRight)();
				delete pWork4;
			}
		}
	}
	cube_1D* pTemp = Row;
	while (pTemp) {
		Row = Row->getNext();
		delete pTemp;
		pTemp = Row;
	}
	pTemp = Column;
	while (pTemp) {
		Column = Column->getNext();
		delete pTemp;
		pTemp = Column;
	}
	pTemp = Height;
	while (pTemp) {
		Height = Height->getNext();
		delete pTemp;
		pTemp = Height;
	}
}