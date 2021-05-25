#include "Node.h"
#include "tree.h"
#include "cube.h"
#include <iostream>
#include <fstream>

using namespace std;

void Print_Check(tree_node* pTemp);

void Open_Category(tree* type_Data,const char* text_file);
void Insert_data(tree* type, tree_node* pParent, char* data);
void make_node(cube* high);
int count_low(cube_2D* Cube);
int count_2dLow(cube* Cube);
void make_rawNode(cube_1D* pNew, int column_count);
void make_Demention(cube_2D* Cube, tree* Tree);
void make_2Demention(cube* Cube, tree* Tree, tree* row_tree, tree* column_tree);
void new_node(int high_count, int row_count, int column_count, cube_2D* high_temp, cube_2D* row_temp, cube_2D* column_temp,int cnt);
Node* select_node(int high_count, int row_count, int column_count, cube_2D* high, cube_2D* row, cube_2D* column);


int main() {
	tree Product;
	tree Location;
	tree Time;
	cube Cube_time;
	Open_Category(&Time,"time.txt");
	Open_Category(&Product,"product.txt");
	Open_Category(&Location,"location.txt");
	make_2Demention(&Cube_time, &Time , &Location, &Product);
	make_node(&Cube_time);
	int high_cnt = count_2dLow(&Cube_time);
	int row_cnt = count_low(Cube_time.getHead()->getRow());
	int column_cnt = count_low(Cube_time.getHead()->getRow());
	cube_2D* pHigh = Cube_time.getHead();
	for (int i = 0; i < high_cnt; i++) {
		for (int j = 0; j < row_cnt; j++) {
			for (int k = 0; k < column_cnt; k++) {
				//new_node(i, j, k, high_temp, row_temp, column_temp);
				cout <<" data: " <<select_node(i, j, k, pHigh, pHigh->getRow(), pHigh->getColumn())->getData() << '\n';
			}
		}
	}
}

void make_node(cube* high) {
	int high_cnt = count_2dLow(high);
	int row_cnt = count_low(high->getHead()->getRow());
	int column_cnt = count_low(high->getHead()->getColumn());
	int cnt = 0;
	cube_2D* pHigh = high->getHead();
	for (int i = 0; i < high_cnt; i++) {
		for (int j = 0; j < row_cnt; j++) {
			for (int k = 0; k < column_cnt; k++) {
				new_node(i, j, k, pHigh, pHigh->getRow(), pHigh->getColumn(),cnt);
				cnt++;
				//cout << select_node(i, j, k, high_temp, row_temp, column_temp);
			}
		}
		pHigh = pHigh->getNext();
	}
}

Node* select_node(int high_count, int row_count, int column_count, cube_2D* high, cube_2D* row, cube_2D* column) {
	cube_2D* high_temp = high;
	for (int i = 0; i < high_count;i++) {
		high_temp = high_temp->getNext();
	}
	cube_1D* row_temp = row->getHead();
	cube_1D* column_temp = column->getHead();
	Node* pTemp = high_temp->getRow()->getHead()->getHead();
	for (int i = 0; i < row_count; i++) {
		pTemp = pTemp->getRight();
		row_temp = row_temp->getNext();
	}
	for (int i = 0; i < column_count; i++) {
		pTemp = pTemp->getDown();
		column_temp = column_temp->getNext();
	}
	cout << "i : " << high_temp->getName() << " j : " << row_temp->getName() << " k : " << column_temp->getName() << " ";
	return pTemp;
}

void new_node(int high_count, int row_count, int column_count, cube_2D* high_temp , cube_2D* row_temp, cube_2D* column_temp, int cnt) {
	cube_1D* row = row_temp->getHead();
	cube_1D* column = column_temp->getHead();
	for (int i = 0; i < row_count; i++) {
		row = row->getNext();
	}
	for (int i = 0; i < column_count; i++) {
		column = column->getNext();
	}
	Node* pNew = new Node;
	pNew->setData(cnt);
	if (!row->getHead()) {
		row->setHead(pNew);
		row->setTail(pNew);
	}
	else {
		pNew->setUp(row->getTail());
		row->getTail()->setDown(pNew);
		row->setTail(pNew);
	}
	if (!column->getHead()) {
		column->setHead(pNew);
		column->setTail(pNew);
	}
	else {
		pNew->setLeft(column->getTail());
		column->getTail()->setRight(pNew);
		column->setTail(pNew);
	}
	cout << "high : " << high_temp->getName() << " row : " << row->getName() << " column : " << column->getName() << " Data : " << pNew->getData() << '\n';
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

void make_2Demention(cube* Cube, tree* Tree, tree* row_tree, tree* column_tree) {
	tree_node* pLow_data = Tree->getRoot();
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
				cube_2D* pRow = new cube_2D;
				cube_2D* pColumn = new cube_2D;
				pNew->setRow(pRow);
				pNew->setColumn(pColumn);
				make_Demention(pRow, row_tree);
				make_Demention(pColumn, column_tree);
			}
			else {
				Cube->getTail()->setNext(pNew);
				pNew->setPrev(Cube->getTail());
				Cube->setTail(pNew);
 				cube_2D* pRow = new cube_2D;
				cube_2D* pColumn = new cube_2D;
				make_Demention(pRow, row_tree);
				make_Demention(pColumn, column_tree);
				pNew->setRow(pRow);
				pNew->setColumn(pColumn);
			}
			pLow_data = pLow_data->getNext();
		}
		pLow_parent = pLow_parent->getNext();
		if (!pLow_parent)
			break;
		pLow_data = pLow_parent->getDown();
	}
}


void make_Demention(cube_2D* Cube, tree* Tree) {
	tree_node* pLow_data = Tree->getRoot();
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
			}
			else {
				Cube->getTail()->setNext(pNew);
				pNew->setPrev(Cube->getTail());
				Cube->setTail(pNew);
			}
			pLow_data = pLow_data->getNext();
		}
		pLow_parent = pLow_parent->getNext();
		if (!pLow_parent)
			break;
		pLow_data = pLow_parent->getDown();
	}
}

int count_low(cube_2D* Cube) {
	int count = 0;
	cube_1D* pTemp = Cube->getHead();
	while (pTemp) {
		pTemp = pTemp->getNext();
		count++;
	}
	return count;
}
int count_2dLow(cube* Cube) {
	int count = 0;
	cube_2D* pTemp = Cube->getHead();
	while (pTemp) {
		pTemp = pTemp->getNext();
		count++;
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
