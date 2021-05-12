#pragma once
#include "Student_Node.h"
#include <iostream>

class Data_1D {
private:
	Student_Node* pHead;
	Student_Node* pTail;
	Data_1D* pNext;
	
	char First_Alphabet;
	int Convert_Id;
	char major[100];
public:
	Data_1D() {
		pHead = nullptr;
		pTail = nullptr;
		pNext = nullptr;
		First_Alphabet = 0;
		Convert_Id = 0;
		memset(major, NULL, 100);
	}

	~Data_1D() {

	}

	Data_1D* getNext() {
		return pNext;
	}

	Student_Node* getHead() {
		return pHead;
	}
	Student_Node* getTail() {
		return pTail;
	}

	char getName() {
		return First_Alphabet;
	}

	char* getMajor() {
		return major;
	}

	int getStudentId() {
		return Convert_Id;
	}

	void setName(char temp) {
		First_Alphabet = temp;
	}

	void setMajor(char* temp) {
		strcpy_s(major, temp);
	}

	void setHead(Student_Node* pTemp) {
		pHead = pTemp;
	}

	void setTail(Student_Node* pTemp) {
		pTail = pTemp;
	}

	void setNext(Data_1D *temp) {
		pNext = temp;
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

	void Insert_input(Student_Node* node) {
		if (!pHead) {
			pHead = node;
			pTail = node;
		}
		else {
			pTail->setNext(node);
			pTail = node;
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