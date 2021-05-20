#include <iostream>
#include <fstream>
#include "Data_1D.h"
#include "Data_1D.h"
#include "Data_2D.h"
#include "Student_Node.h"
#include <crtdbg.h>

using namespace std;

int main() {
	Data_1D<char> data_1d; //1�����迭�� �����ϴ� ����
	Data_2D<int> year_2d; //year�� ���� 2�����迭�� �����ϴ� ����
	Data_2D<char> name_2d; //name�� ���� 2�����迭�� �����ϴ� ����
	Data_2D<char*> major_2d;//major�� ���� 2�����迭�� �����ϴ� ����
	bool end = true; 
	int command;
	char str[100];
	char Id[100];
	char major[100];
	char name[100];
	ifstream readFile("student.txt"); // student������ �о��
	if (!readFile.is_open()) { // ������ �������������
		readFile.close();
		ofstream writeFile; // outputstream���� ���ο���
		writeFile.open("student.txt"); //student.txt������ ��������λ���
		writeFile.close(); // ������ ����
		ifstream readFile("student.txt"); // student.txt�� ����.
	}
	while (readFile) { // readFile�� ������ ������ �ݺ�
		int len = 0; // �ܾ��� ���̸� count�ϴ� ����
		memset(str, NULL, 100);  // �����ʱ�ȭ
		memset(Id, NULL, 100);// �����ʱ�ȭ
		memset(major, NULL, 100);// �����ʱ�ȭ
		memset(name, NULL, 100);// �����ʱ�ȭ
		readFile.getline(str, 100, '\n'); // �ܾ �о��
		if (str[0] == NULL) // �ܾ �д°��� ���� �о�� �ܾ ���� ��
			break;
		for (; str[len] != ','; len++) { // ,���� �о�� id�� ����
			Id[len] = str[len];
		}
		len++;
		for (int i = 0; str[len] != ','; i++, len++) { // ���� ,���� �о�� major�� ����
			major[i] = str[len];
		}
		for (int i = 0; i <= strlen(str); i++ , len++) { // ������ �о�ͼ� name�� ����
			name[i]= str[len+1];
		}
		Student_Node* pNew = new Student_Node; //��� ����
		pNew->setMajor(major); // ���λ����� student_node�� ��������
		pNew->setStudentId(Id);// ���λ����� student_node�� �й�����
		pNew->setName(name);// ���λ����� student_node�� �̸�����
		data_1d.Insert_input<Student_Node>(pNew); // Input������ 1�����迭�� ����
		name_2d.Insert<char>(pNew); // 2�����迭�� ����
		major_2d.Insert<char*>(pNew); // 2�����迭�� ����
		year_2d.Insert<int>(pNew); // 2�����迭�� ����
	}
	readFile.close(); // �����б�����
	//name_2d.Insert(&data_1d);
	//major_2d.Insert<char*>(&data_1d);
	while (end) {
		cout << "1. Print File" << endl;
		cout << "2. Print by ID" << endl;
		cout << "3. Print by Major" << endl;
		cout << "4. Print by Name" << endl;
		cout << "5. Program End" << endl;
		cout << "CMD>> ";
		cin >> command; // command�� ����
		if (command == 1) { // input������ ���
			data_1d.print(); //1�����迭�� ��¸żҵ� ȣ��
		}
		else if (command == 2) { // year������ ���
			cout << "Print by ID" << '\n';
			year_2d.print<int>(); // year������ ����ϴ� �żҵ� ȣ��
		}
		else if (command == 3) { // major������ ���
			cout << "Print by Major" << '\n';
			major_2d.print<char*>(); // major������ ����ϴ� �żҵ� ȣ��
		}
		else if (command == 4) { // ID������ ���
			cout << "Print by Name" << '\n';
			name_2d.print<char>(); // ID������ ����ϴ� �żҵ� ȣ��
		} 
		else if(command == 5){
			end = false; // �ݺ�������
			major_2d.delete_data<char*>(); // major_2d�� ������ ���� �����Ҵ�����
			major_2d.Remove_data<char*>(); // major�� �ִ� 1D��� �����Ҵ�����
			year_2d.Remove_data<int>(); // year�� �ִ� 1d��� �����Ҵ�����
			name_2d.Remove_data<char>(); // name�� �ִ� 1d��� �����Ҵ�����
			data_1d.Remove_1d(); // Student_node�����Ҵ� ����
		}
		else { // command�� �ƴ� �׸��Է½�
			cout << "wrong input" << endl; 
		}
	}
	return 0;
}