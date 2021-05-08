#pragma once
#include "Student_Node.h"
#include <iostream>

class Data_1D {
private:
	Student_Node* pHead;
	Student_Node* pTail;

	char name[100];
	char major[100];
	char student_id[100];
	char first_name[1];
	char year[5];

public:
	Data_1D() {
		pHead = nullptr;
		pTail = nullptr;
		memset(name, NULL, 100);
		memset(major, NULL, 100);
		memset(student_id, NULL, 100);
		memset(first_name, NULL, 1);
		memset(year, NULL, 5);
	}

	~Data_1D() {

	}

	char* getName() {
		return name;
	}

	char* getMajor() {
		return major;
	}

	char* getId() {
		return student_id;
	}

	char* getFirst_name() {
		return first_name;
	}

	char* getyear() {
		return year;
	}

	void setName(char *temp) {
		strcpy_s(name, temp);
		if (temp[0] >= 'a' && temp[0] <= 'z')
			first_name[0] = temp[0] - 32;
		else
			first_name[0] = temp[0];
	}

	void setMajor(char* temp) {
		strcpy_s(major, temp);
	}

	void setId(char* temp) {
		strcpy_s(student_id, temp);
		for (int i = 0; i < 4;i++) {
			student_id[i] = temp[i];
		}
	}

	Student_Node* getHead() {
		return pHead;
	}
	Student_Node* getTail() {
		return pTail;
	}

	void setHead(Student_Node* pTemp) {
		pHead = pTemp;
	}

	void setTail(Student_Node* pTemp) {
		pTail = pTemp;
	}

	void Insert_input(char* ID, char* major, char* name) {
		Student_Node* pNew = new Student_Node;
		pNew->setStudentId(ID);
		pNew->setMajor(major);
		pNew->setName(name);
		if (!pHead) {
			pHead = pNew;
			pTail = pNew;
		}
		else {
			pTail->setNext(pNew);
			pTail = pNew;
		}
	}

	void print() {
		Student_Node* pTemp = pHead;
		std::cout << "Print File" << '\n';
		std::cout << "=========================================================================" << '\n';
		while (pTemp) {
			std::cout << pTemp->getStudentId();
			std::cout.width(30);
			std::cout << pTemp->getMajor() << '\t' << '\t';
			std::cout.width(10);
			std::cout << pTemp->getName() << '\n';
			pTemp = pTemp->getNext();
		}
		std::cout << "=========================================================================" << '\n';
	}
};