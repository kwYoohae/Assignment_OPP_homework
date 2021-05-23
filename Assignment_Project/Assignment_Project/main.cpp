#include "location_tree.h"
#include "Node.h"
#include "product_tree.h"
#include "time_tree.h"
#include <iostream>
#include <fstream>

using namespace std;

void Print_Check(tree_node* pTemp);
//void Open_Product(product_tree* Product);
//void Open_Location(location_tree* Location);
void Open_Time(time_tree* Time);
void Insert_data(time_tree* Time, tree_node* pParent, char* data);

int main() {
	product_tree Product;
	location_tree Location;
	time_tree Time;
	Open_Time(&Time);
	Print_Check(Time.getRoot());
}

void Open_Time(time_tree* Time) {
	ifstream readFile("time.txt");
	if (!readFile.is_open()) {
		cout << "Error" << endl;
		readFile.close();
	}
	tree_node* pParent = Time->getRoot();
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
					Insert_data(Time, Time->getRoot(), data);
					memset(data, NULL, 100);
					len++;
				}
				else if (temp[len] == '\0') {
					Insert_data(Time, Time->getRoot(), data);
					memset(data, NULL, 100);
				}
			}
			pParent = Time->getRoot();
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
						Insert_data(Time, pTemp, data);
						memset(data, NULL, 100);
						len++;
					}
					else if (temp[len] == '\0') {
						Insert_data(Time, pTemp, data);
						memset(data, NULL, 100);
					}
				}
			}
			len = 0;
		}
	}
	readFile.close();
}


void Print_Check(tree_node* pTemp) {
	if (pTemp) {
		Print_Check(pTemp->getNext());
		cout << pTemp->getData() << endl;
		Print_Check(pTemp->getDown());
	}
}

void Insert_data(time_tree* Time, tree_node* pParent, char* data) {
	if (!Time->getRoot()) {
		tree_node* pNew = new tree_node;
		pNew->setData(data);
		Time->setRoot(pNew);
	}
	else if (pParent == Time->getRoot()) {
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
	
	/*if (!Time->getRoot()) {
		tree_node* pNew = new tree_node;
		pNew->setData(data);
		Time->setRoot(pNew);
	}
	else if (pParent == Time->getRoot()) {
		tree_node* pNew = new tree_node;
		pNew->setNew();
		pNew->setData(data);
		pParent->setDown(pNew,pParent->getCount());
		pNew->setUp(pParent);
		pParent->setCount(pParent->getCount() + 1);
	}
	else {
		tree_node* pNew = new tree_node;
		pParent->setNew();
		pNew->setData(data);
		pParent->setDown(pNew, pParent->getCount());
		pNew->setUp(pParent);
		pParent->setCount(pParent->getCount() + 1);
	}*/
}