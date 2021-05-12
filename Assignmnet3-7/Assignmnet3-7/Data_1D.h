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
		data = new char[100];
		for (int i = 0; i < 100; i++) {
			data[i] = temp[i];
		}
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
	void Insert_input<int>(Student_Node* node) {
		Student_Node* pTemp = getHead();
		if (!pHead) {
			pHead = node;
		}
		else {
			Student_Node* pPrev = pTemp;
			while (pTemp) {
				if (Compare(pTemp->getStudentId(), node->getStudentId()) == 1) {
					if (pTemp == pHead) {
						node->setNext_ID(pHead);
						pHead = node;
					}
					else {
						pPrev->setNext_ID(node);
						node->setNext_ID(pTemp);
					}
					break;
				}
				pPrev = pTemp;
				pTemp = pTemp->getNext_ID();
				if (!pTemp) {
					pPrev->setNext_ID(node);
				}
			}
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
						node->setNext_Name(pHead);
						pHead = node;
					}
					else {
						pPrev->setNext_Name(node);
						node->setNext_Name(pTemp);
					}
					break;
				}
				pPrev = pTemp;
				pTemp = pTemp->getNext_Name();
				if (!pTemp) {
					pPrev->setNext_Name(node);
				}
			}
		}
	}

	template<>
	void Insert_input<char*>(Student_Node* node) {
		Student_Node* pTemp = getHead();
		if (!pHead) {
			pHead = node;
		}
		else {
			Student_Node* pPrev = pTemp;
			while (pTemp) {
				if (Compare<char*>(pTemp->getStudentId(), node->getStudentId()) == 1) {
					if (pTemp == pHead) {
						node->setNext_Major(pHead);
						pHead = node;
					}
					else {
						pPrev->setNext_Major(node);
						node->setNext_Major(pTemp);
					}
					break;
				}
				pPrev = pTemp;
				pTemp = pTemp->getNext_Major();
				if (!pTemp) {
					pPrev->setNext_Major(node);
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

	template<>
	int Compare<char*>(char* temp1, char* temp2) {
		char T_temp1[100];
		char T_temp2[100];
		for (int i = 0; i <= strlen(temp1); i++) {
			if (temp1[i] >= 'A' && temp1[i] <= 'Z')
				T_temp1[i] = temp1[i] + 'a' - 'A';
			else
				T_temp1[i] = temp1[i];
		}
		for (int i = 0; i <= strlen(temp2); i++) {
			if (temp2[i] >= 'A' && temp2[i] <= 'Z')
				T_temp2[i] = temp2[i] + 'a' - 'A';
			else
				T_temp2[i] = temp2[i];
		}
		//std::cout << "temp1 : " << T_temp1 << " temp2 : " << T_temp2 << " strcmp : " << strcmp(temp1,temp2) <<'\n';
		return strcmp(temp1, temp2);
	}

	void Remove_1d() {
		Student_Node* pTemp = pHead;
		while (pTemp) {
			pHead = pHead->getNext();
			delete pTemp;
			pTemp = pHead;
		}
	}
};