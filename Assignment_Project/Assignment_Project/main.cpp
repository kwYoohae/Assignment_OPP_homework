#include "Node.h"
#include "tree.h"
#include "cube.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <crtdbg.h>
using namespace std;

void Print_Check(tree_node* pTemp);

void Open_Category(tree* type_Data,const char* text_file);
void Insert_data(tree* type, tree_node* pParent, char* data);
void make_node(cube* high);
int count_low(cube_2D* Cube);
int count_2dLow(cube* Cube);
void make_rawNode(cube_1D* pNew, int column_count);
void make_Demention(cube_2D* Cube, tree* Tree, int dimention_number);
void make_2Demention(cube* Cube, tree* Tree, tree* row_tree, tree* column_tree, int high_D, int row_D, int column_D);
void new_node(int high_count, int row_count, int column_count, cube_2D* high_temp, cube_2D* row_temp, cube_2D* column_temp);
Node* select_node(int high_count, int row_count, int column_count, cube_2D* high, cube_2D* row, cube_2D* column);
void print_cube(cube* Cube);
void Load_sales(cube* raw_cube);
void insert_data(cube* Cube, char* product, char* location, char* time, int data);
void roll_up(cube* raw, cube* view,int h , int r , int c);

int main() {
	tree Product;
	tree Location;
	tree Time;
	cube raw_cube;
	cube view_cube;
	char command[100];
	bool end = true;
	ofstream WriteCommad("command.txt");
	while (end) {
		cout << "CMD >> ";
		cin >> command;
		if (strcmp(command, "LOAD") == 0) {
			WriteCommad.write(command, strlen(command));
			Open_Category(&Time, "time.txt");
			Open_Category(&Product, "product.txt");
			Open_Category(&Location, "location.txt");
			make_2Demention(&raw_cube, &Time, &Location, &Product,3,3,3);
			make_node(&raw_cube);
			//print_cube(&raw_cube);
			Load_sales(&raw_cube);
			make_2Demention(&view_cube, &Time, &Location, &Product,2,2,2);
			make_node(&view_cube);
			print_cube(&view_cube);
		}
		else if (strcmp(command, "END") == 0) {
			raw_cube.delete_cube_all();
			_CrtDumpMemoryLeaks();
			end = false;
		}
		else if (strcmp(command, "PRINT") == 0) {
			print_cube(&raw_cube);
		}
	}

}

void make_node(cube* high) {
	int high_cnt = count_2dLow(high);
	int row_cnt = count_low(high->getHead()->getRow());
	int column_cnt = count_low(high->getHead()->getColumn());
	cube_2D* pHigh = high->getHead();
	for (int i = 0; i < high_cnt; i++) {
		for (int j = 0; j < row_cnt; j++) {
			for (int k = 0; k < column_cnt; k++) {
				new_node(i, j, k, pHigh, pHigh->getRow(), pHigh->getColumn());
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

void new_node(int high_count, int row_count, int column_count, cube_2D* high_temp , cube_2D* row_temp, cube_2D* column_temp) {
	cube_1D* row = row_temp->getHead();
	cube_1D* column = column_temp->getHead();
	for (int i = 0; i < row_count; i++) {
		row = row->getNext();
	}
	for (int i = 0; i < column_count; i++) {
		column = column->getNext();
	}
	Node* pNew = new Node;
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
	//cout << "high : " << high_temp->getName() << " row : " << row->getName() << " column : " << column->getName() << " Data : " << pNew->getData() << '\n';
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

void make_2Demention(cube* Cube, tree* Tree, tree* row_tree, tree* column_tree, int high_D, int row_D, int column_D) {
	tree_node* pLow_data = Tree->getRoot();
	tree_node* pLow_parent = nullptr;
	for (int i = 1; i < high_D; i++) {
		if (!pLow_data->getDown())
			break;
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
				make_Demention(pRow, row_tree,row_D);
				make_Demention(pColumn, column_tree,column_D);
			}
			else {
				Cube->getTail()->setNext(pNew);
				pNew->setPrev(Cube->getTail());
				Cube->setTail(pNew);
 				cube_2D* pRow = new cube_2D;
				cube_2D* pColumn = new cube_2D;
				make_Demention(pRow, row_tree,row_D);
				make_Demention(pColumn, column_tree,column_D);
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


void make_Demention(cube_2D* Cube, tree* Tree, int dimention_number) {
	tree_node* pLow_data = Tree->getRoot();
	tree_node* pLow_parent = nullptr;
	for (int i = 1; i < dimention_number; i++) {
		if (!pLow_data->getDown())
			break;
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
		cout << pTemp->getName() << endl;
		pTemp = pTemp->getNext();
		count++;
	}
	return count;
}
int count_low(tree* Tree, int num) {
	int count = 0;
	tree_node* pTemp = Tree->getRoot();
	for (int i = 1; i < num; i++) {
		pTemp = pTemp->getDown();
	}
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
		cout << pTemp->getName() << endl;
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

void print_cube(cube* Cube) {
	int high_cnt = count_2dLow(Cube);
	int row_cnt = count_low(Cube->getHead()->getRow());
	int column_cnt = count_low(Cube->getHead()->getColumn());
	cube_2D* pHigh = Cube->getHead();
	for (int i = 0; i < high_cnt; i++) {
		for (int j = 0; j < row_cnt; j++) {
			for (int k = 0; k < column_cnt; k++) {
				//new_node(i, j, k, high_temp, row_temp, column_temp);
				//cout << "i : " << i << " j : " << j << " k : " << k << " data : ";
				cout << select_node(i, j, k, pHigh, pHigh->getRow(), pHigh->getColumn())->getData() << '\n';
			}
		}
	}
}

void Load_sales(cube* Cube) {
	ifstream readFile("sales.txt");
	if (!readFile.is_open()) {
		cout << "Error" << endl;
		readFile.close();
	}
	char temp[200];
	char product[200];
	char location[200];
	char time[200];
	int product_number = 0;
	int location_nubmer = 0;
	int time_number = 0;
	int data = 0;
	int len = 0;
	while (true) {
		memset(temp, NULL, 200);
		memset(product, NULL, 200);
		memset(location, NULL, 200);
		memset(time, NULL, 200);
		data = 0;
		readFile.getline(temp, 200, '\n');
		if (temp[0] == NULL)
			break;
		for (int i = 0; temp[len] != ' '; i++, len++) {
			product[i] = temp[len];
		}
		len++;
		for (int i = 0; temp[len] != ' '; i++, len++) {
			location[i] = temp[len];
		}
		len++;
		for (int i = 0; temp[len] != ' '; i++, len++) {
			time[i] = temp[len];
		}
		len++;
		for (int i = 0; temp[len] != '\0'; i++,len++) {
			data += temp[len] - '0';
			data *= 10;
		}
		data /= 10;
		insert_data(Cube, product, location, time, data);
		len = 0;
	}
	readFile.close();
}

void insert_data(cube* Cube, char* product, char* location, char* time, int data) {
	cube_2D* pTime = Cube->getHead();
	while (pTime) {
		if (strcmp(pTime->getName(), time) == 0) {
			break;
		}
		pTime = pTime->getNext();
	}
	cube_1D* find_number = pTime->getRow()->getHead();
	while (find_number) {
		if (strcmp(find_number->getName(), location) == 0)
			break;
		find_number = find_number->getNext();
	}
	Node* pTemp = find_number->getHead();
	find_number = pTime->getColumn()->getHead();
	while (find_number) {
		if (strcmp(find_number->getName(), product) == 0) {
			break;
		}
		find_number = find_number->getNext();
		pTemp = pTemp->getDown();
	}
	pTemp->setData(data);
}

void Make_view(cube* raw, cube* view, int high_d, int row_d, int column_d) {

}