#include "Node.h"
#include "tree.h"
#include "cube.h"
#include <iostream>
#include <fstream>

using namespace std;

void Print_Check(tree_node* pTemp);

void Open_Category(tree* type_Data,const char* text_file);
void Insert_data(tree* type, tree_node* pParent, char* data);
void Load_salse(cube* Cube, cube_2D* Cube_2d, cube_1D* Cube_1d);
void make_raw(cube* Cube, tree *product, tree* location, tree *time);
void make_2D(cube_2D* cube, tree* row_tree, tree* colomn_tree);
int count_low(tree* Tree);
void make_rawNode(cube_1D* pNew, int column_count);


int main() {
	tree Product;
	tree Location;
	tree Time;
	
	Open_Category(&Time,"time.txt");
	Open_Category(&Product,"product.txt");
	Open_Category(&Location,"location.txt");
	
}

void Print_Check(tree_node* pTemp) {
	if (pTemp) {
		cout << pTemp->getData() << endl;
		Print_Check(pTemp->getDown());
		Print_Check(pTemp->getNext());
	}
}

void Insert_data(tree* type, tree_node* pParent, char* data) {
	if (!type->getRoot()) {
		tree_node* pNew = new tree_node;
		pNew->setData(data);
		type->setRoot(pNew);
	}
	else if (pParent == type->getRoot()) {
		tree_node* pNew = new tree_node;
		pNew->setData(data);
		if(!pParent->getDown())
			pParent->setDown(pNew);
		else {
			tree_node* pTemp = pParent->getDown();
			while (pTemp->getNext())
				pTemp = pTemp->getNext();
			tree_node* pNew = new tree_node;
			pNew->setData(data);
			pNew->setPrev(pTemp);
			pTemp->setNext(pNew);
		}
		pNew->setUp(pParent);
	}
	else {
		tree_node* pNew = new tree_node;
		pNew->setData(data);
		if (!pParent->getDown())
			pParent->setDown(pNew);
		else {
			tree_node* pTemp = pParent->getDown();
			while (pTemp->getNext())
				pTemp = pTemp->getNext();
			tree_node* pNew = new tree_node;
			pNew->setData(data);
			pNew->setPrev(pTemp);
			pTemp->setNext(pNew);
		}
		pNew->setUp(pParent);

	}
}

void Open_Category(tree* type_Data,const char *text_file) {
	ifstream readFile(text_file);
	if (!readFile.is_open()) {
		cout << "Error" << endl;
		readFile.close();
	}
	tree_node* pParent = type_Data->getRoot();
	char temp[100];
	char data[100];
	int len = 0;
	int count = -1;
	while (true) {
		tree_node* pTemp = nullptr;
		int i = 0;
		memset(temp, NULL, 100);
		memset(data, NULL, 100);
		readFile.getline(temp, 100, '\n');
		if (temp[0] == NULL)
			break;
		if (count == -1) {
			while (temp[len] != '\0') {
				data[i] = temp[len];
				len++;
				i++;
				if (temp[len] == ' ') {
					i = 0;
					Insert_data(type_Data, type_Data->getRoot(), data);
					memset(data, NULL, 100);
					len++;
				}
				else if (temp[len] == '\0') {
					Insert_data(type_Data, type_Data->getRoot(), data);
					memset(data, NULL, 100);
				}
			}
			pParent = type_Data->getRoot();
			count++;
			len = 0;
		}
		else {
			while (temp[len] != ' ') {
				data[len] = temp[len];
				len++;
			}
			pTemp = pParent->getDown();
			while (pTemp->getNext()) {
				if (strcmp(pTemp->getData(), data) == 0)
					break;
				else
					pTemp = pTemp->getNext();
			}
			if (pTemp) {
				memset(data, NULL, 100);
				len++;
				while (temp[len] != '\0') {
					data[i] = temp[len];
					len++;
					i++;
					if (temp[len] == ' ') {
						i = 0;
						Insert_data(type_Data, pTemp, data);
						memset(data, NULL, 100);
						len++;
					}
					else if (temp[len] == '\0') {
						Insert_data(type_Data, pTemp, data);
						memset(data, NULL, 100);
					}
				}
			}
			len = 0;
		}
	}
	readFile.close();
}

void Load_salse(cube* Cube, cube_2D* Cube_2d, cube_1D* Cube_1d) {

}

void make_raw(cube* Cube, tree* product, tree* location, tree* time) {
	tree_node* pLow_data = time->getRoot();
	tree_node* pLow_parent = nullptr;
	while (pLow_data->getDown()) {
		pLow_data = pLow_data->getDown();
	}
	pLow_parent = pLow_data->getUp();
	while (pLow_parent) {
		while (pLow_data) {
			cube_2D* pNew = new cube_2D;
			pNew->setName(pLow_data->getData());
			if (!Cube->getHead()) {
				Cube->setHead(pNew);
				Cube->setTail(pNew);
			}
			else {
				Cube->getTail()->setNext(pNew);
				pNew->setPrev(Cube->getTail());
				Cube->setTail(pNew);
			}
			pLow_data = pLow_data->getNext();
		}
		pLow_parent = pLow_parent->getNext();
		pLow_data = pLow_parent->getDown();
	}
}

void make_2D(cube_2D* Cube, tree* row_tree, tree* column_tree) {
	int column_count = count_low(column_tree);
	tree_node* pLow_data = row_tree->getRoot();
	tree_node* pLow_parent = nullptr;
	while (pLow_data->getDown()) {
		pLow_data = pLow_data->getDown();
	}
	pLow_parent = pLow_data->getUp();
	while (pLow_parent) {
		while (pLow_data) {
			cube_1D* pNew = new cube_1D;
			pNew->setName(pLow_data->getData());
			if (!Cube->getHead()) {
				Cube->setHead(pNew);
				Cube->setTail(pNew);
				make_rawNode(pNew, column_count);
			}
			else {
				Cube->getTail()->setNext(pNew);
				pNew->setPrev(Cube->getTail());
				Cube->setTail(pNew);
				make_rawNode(pNew, column_count);
			}
			pLow_data = pLow_data->getNext();
		}
		pLow_parent = pLow_parent->getNext();
		pLow_data = pLow_parent->getDown();
	}

	pLow_data = column_tree->getRoot();
	pLow_parent = nullptr;
	cube_1D* pTemp;
	while (pLow_data->getDown()) {
		pLow_data = pLow_data->getDown();
	}
	while (pLow_parent) {
		while (pLow_data) {
			cube_1D* pNew = new cube_1D;
			pNew->setName(pLow_data->getData());
			if (!Cube->getHead()) {
				Cube->setHead(pNew);
				Cube->setTail(pNew);
				make_rawNode(pNew, column_count);
			}
			else {
				Cube->getTail()->setNext(pNew);
				pNew->setPrev(Cube->getTail());
				Cube->setTail(pNew);
				make_rawNode(pNew, column_count);
			}
			pLow_data = pLow_data->getNext();
		}
		pLow_parent = pLow_parent->getNext();
		pLow_data = pLow_parent->getDown();
	}
}

int count_low(tree* Tree) {
	tree_node* pTemp = Tree->getRoot();
	tree_node* pParent = Tree->getRoot();
	int count = 0;
	while (pTemp->getDown()) {
		pParent = pTemp;
		pTemp = pTemp->getDown();
	}
	while (pParent) {
		while (pTemp) {
			pTemp = pTemp->getNext();
			count++;
		}
		pParent = pParent->getNext();
		pTemp = pParent->getDown();
	}
	return count;
}

void make_rawNode(cube_1D* pNew , int column_count) {
	for (int i = 0; i < column_count; i++) {
		Node* pNode = new Node;
		if (!pNew->getHead()) {
			pNew->setHead(pNode);
			pNew->setTail(pNode);
		}
		else {
			pNew->getTail()->setRight(pNode);
			pNode->setLeft(pNew->getTail());
			pNew->setTail(pNode);
		}
	}
}