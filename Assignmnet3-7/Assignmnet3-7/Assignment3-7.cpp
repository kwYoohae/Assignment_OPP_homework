#include <iostream>
#include <fstream>
#include "Data_1D.h"
#include "Data_1D.h"
#include "Data_2D.h"
#include "Student_Node.h"

using namespace std;

int main() {
	Data_1D<char> data_1d;
	Data_2D<int> year_2d;
	Data_2D<char> name_2d;
	Data_2D<char*> ID_2d;
	bool end = true;
	int command;
	char str[100];
	char Id[100];
	char major[100];
	char name[100];
	ifstream readFile("student.txt");
	if (!readFile.is_open()) {
		readFile.close();
		ofstream writeFile;
		writeFile.open("menu.txt");
		writeFile.close();
		ifstream readFile("student.txt");
	}
	while (readFile) {
		int len = 0;
		memset(str, NULL, 100);
		memset(Id, NULL, 100);
		memset(major, NULL, 100);
		memset(name, NULL, 100);
		readFile.getline(str, 100, '\n');
		if (str[0] == NULL)
			break;
		for (; str[len] != ','; len++) {
			Id[len] = str[len];
		}
		len++;
		for (int i = 0; str[len] != ','; i++, len++) {
			major[i] = str[len];
		}
		for (int i = 0; i <= strlen(str); i++ , len++) {
			name[i]= str[len+1];
		}
		data_1d.Insert_input(Id, major, name);
	}
	name_2d.Insert(&data_1d);
	while (end) {
		cout << "1. Print File" << endl;
		cout << "2. Print by ID" << endl;
		cout << "3. Print by Major" << endl;
		cout << "4. Print by Name" << endl;
		cout << "5. Program End" << endl;
		cout << "CMD>> ";
		cin >> command;
		if (command == 1) {
			data_1d.print();
		}
		else if (command == 2) {
			name_2d.print_char();
		}
	}

}