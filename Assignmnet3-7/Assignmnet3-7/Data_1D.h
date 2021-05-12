#pragma once
#include "Student_Node.h"
#include <iostream>

template<typename T>
class Data_1D {
private:
	Student_Node* pHead;
	Student_Node* pTail;
	Data_1D* pNext;
	
	T data;

public:
	Data_1D() {
		pHead = nullptr;
		pTail = nullptr;
		pNext = nullptr;
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

	T getData() {
		return data;
	}
	
	void setData(char temp) {
		data = temp;
	}

	void setData(char* temp) {
		strcpy_s(data,temp);
	}

	void setData(int temp) {
		data = temp;
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