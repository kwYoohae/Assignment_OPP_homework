#include "Node.h"
#include "tree.h"
#include "cube.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <crtdbg.h>
using namespace std;

void Print_Check(tree_node* pTemp);

void Open_Category(tree* type_Data, const char* text_file);
void Insert_data(tree* type, tree_node* pParent, char* data);
void Load_sales(cube* Cube);
int count_low(tree* Tree, int number);
//int Role_up(tree* product, tree* time, tree* , cube* raw, cube* view);
void insert_data(cube* Cube, char* product, char* location, char* time, int data);
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
			raw_cube.Make_Cube(count_low(&Product, 3), count_low(&Location, 3), count_low(&Time, 3));
			raw_cube.Make_tree(&Time, &Location, &Product, 3);
			//Load_sales(&raw_cube);
			raw_cube.Print();
			view_cube.Make_Cube(count_low(&Product, 3), count_low(&Location, 3), count_low(&Time, 3));
			view_cube.Make_tree(&Time, &Location, &Product, 2);
			//Load_sales(&view_cube);
			//view_cube.Make_View(&raw_cube, &Time, &Location, &Product);
		//	view_cube.Print();
		}
		else if (strcmp(command, "END") == 0) {
			_CrtDumpMemoryLeaks();
			end = false;
		}
		else if (strcmp(command, "PRINT") == 0) {
		}
	}

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

void Open_Category(tree* type_Data, const char* text_file) {
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

int count_low(tree* Tree, int number) {
	int count = 0;
	tree_node* pTemp = Tree->getRoot();
	tree_node* pParent = pTemp;
	for (int i = 1; i < number; i++) {
		pParent = pTemp;
		pTemp = pTemp->getDown();
		if (!pTemp->getDown())
			break;
	}
	
	while (pTemp) {
		count++;
		pTemp = pTemp->getNext();
		if (!pTemp) {
			pParent = pParent->getNext();
			if (!pParent)
				break;
			pTemp = pParent->getDown();
		}
	}
	return count;
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
		for (int i = 0; temp[len] != '\0'; i++, len++) {
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
	int p = 0;
	int l = 0;
	int t = 0;
	cube_1D* pTemp = Cube->getRow();
	while (pTemp) {
		if (strcmp(pTemp->getData()->getData(), time) == 0)
			break;
		t++;
		pTemp = pTemp->getNext();
	}
	pTemp = Cube->getColumn();
	while (pTemp) {
		if (strcmp(pTemp->getData()->getData(), location) == 0)
			break;
		l++;
		pTemp = pTemp->getNext();
	}
	pTemp = Cube->getHeight();
	while (pTemp) {
		if (strcmp(pTemp->getData()->getData(), product) == 0)
			break;
		p++;
		pTemp = pTemp->getNext();
	}
	
	node* pNode = Cube->getHead();
	for (int i = 0; i < p; i++) {
		pNode = pNode->getHnext();
	}
	for (int i = 0; i < l; i++) {
		pNode = pNode->getCnext();
	}
	for (int i = 0; i < t; i++) {
		pNode = pNode->getRnext();
	}
	pNode->setData(data);
}

int make_view(tree* product, tree* time, tree*, cube* raw, cube* view) {
	tree_node* pTemp = nullptr;
	while (!pTemp) {

	}
//view->Make_Cube()
	return 1;
}