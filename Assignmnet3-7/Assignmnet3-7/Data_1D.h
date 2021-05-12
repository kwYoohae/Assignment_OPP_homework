#pragma once
#include "Student_Node.h"
#include <iostream>

template<typename T>
class Data_1D {
private:
	Student_Node* pHead;
	Student_Node* pTail;
	Data_1D<T>* pNext;
	
	T data;
	 
public:
	Data_1D() {
		pHead = nullptr;
		pTail = nullptr;
		pNext = nullptr;
		data = NULL;
	}

	~Data_1D() {

	}

	Data_1D<T>* getNext() {
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

	void setNext(Data_1D<T> *temp) {
		pNext = temp;
	}

	template<typename T>
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

	template<>
	void Insert_input<char>(Student_Node* node) {
		Student_Node* pTemp = getHead();
		if (!pHead) {
			pHead = node;
		}
		else {
			Student_Node* pPrev = pTemp;
			while (pTemp) {
				if (Compare(pTemp->getName(), node->getName()) == 1) {
					if (pTemp == pHead) {
						node->setNext_Name(pTemp);
						pHead = node;
					}
					else {
						pPrev->setNext_Name(node);
						node->setNext_Name(pTemp);
					}
				}
				pPrev = pTemp;
				pTemp = pTemp->getNext_Name();
				if (!pTemp) {
					pPrev->setNext_Name(node);
				}
			}

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

	template<typename T>
	int Compare(T temp1, T temp2) {
		if (temp1 > temp2)
			return 1;
		else if (temp1 == temp2)
			return 0;
		return -1;
	}
};