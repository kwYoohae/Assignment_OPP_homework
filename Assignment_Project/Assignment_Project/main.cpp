#include "location_tree.h"
#include "Node.h"
#include "product_tree.h"
#include "time_tree.h"
#include <iostream>
#include <fstream>

using namespace std;

void Open_Product(product_tree* Product);
//void Open_Location(location_tree* Location);
void Open_Time(time_tree* Time);

int main() {
	product_tree Product;
	location_tree Location;
	time_tree Time;
	Open_Time(&Time);
}

void Open_Time(time_tree* Time) {
	ifstream readFile("time.txt");
	if (!readFile.is_open()) {
		cout << "Error" << endl;
		readFile.close();
	}
	char temp[100];
	char data[100];
	int len = 0;
	int count = 0;
	while (true) {
		int i = 0;
		memset(temp, NULL, 100);
		memset(data, NULL, 100);
		readFile.getline(temp, 100, '\n');
		if (temp[0] == NULL)
			break;
		while (temp[len] != '\0') {
			data[i] = temp[len];
			len++;
			i++;
			if (temp[len] == ' ') {
				if (!Time->getRoot()) {
					time_node* pNew = new time_node();
					pNew->setData(data);
					
				}
				else {
					time_node* pNew = new time_node();
					pNew->setData(data);
					pNew->setUp(Time->getRoot());
				}
				memset(data, NULL, 100);
				i = 0;
				len++;
			}
			else if (temp[len] == '\0') {
				cout << data << endl;
			}
		}
		len = 0;
	}
	readFile.close();
}

void Open_Product(product_tree* Product) {
	ifstream readFile("product.txt");
	if (!readFile.is_open()) {
		cout << "Error" << endl;
	}
	char temp[100];
	char data[100];
	int count = 0;
	while (temp) {
		int len = 0;
		memset(temp,NULL, 100);
		readFile.getline(temp, 100, '\n');
		if (count == 0) {
			for (; temp[len] != ' '; len++)
				data[len] = temp[len];
		}
	}
}

