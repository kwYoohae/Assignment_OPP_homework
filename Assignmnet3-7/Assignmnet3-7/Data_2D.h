#pragma once
#include "Data_1D.h"
#include <iostream>

template <typename T>
class Data_2D {
private:
	Data_1D<T> *pHead;

public:
	Data_2D() {
		pHead = nullptr;
	}
	~Data_2D() {
		
	}

	Data_1D<T> *getHead() {
		return pHead;
	}

	void setHead(Data_1D<T> *pTemp) {
		pHead = pTemp;
	}

	int Compare(int temp1, int temp2) {
		if (temp1 > temp2)
			return 1;
		else if (temp1 == temp2)
			return 0;
		else
			return -1;
	}

	int Compare(char temp1, char temp2) {
		if (temp1 >= 'A' && temp1 <= 'Z')
			temp1 += 'a' - 'A';
		if (temp2 >= 'A' && temp2 <= 'Z')
			temp2 += 'a' - 'A';
		if (temp1 > temp2)
			return 1;
		else if (temp1 == temp2)
			return 0;
		return -1;
	}
	
	int Compare(char* temp1, char* temp2) {
		char T_temp1[100];
		char T_temp2[100];
		for (int i = 0; i <= strlen(temp1); i++) {
			if (temp1[i] >= 'A' && temp1[i] <= 'Z')
				T_temp1[i] = temp1[i] + 'a' - 'A';
			else
				T_temp1[i] = temp1[i];
		}
		for (int i = 0; i < strlen(temp2); i++) {
			if (temp2[i] >= 'A' && temp2[i] <= 'Z')
				T_temp2[i] = temp2[i] + 'a' - 'A';
			else
				T_temp2[i] = temp2[i];
		}
		return strcmp(temp1, temp2);
	}

	void Insert(Data_1D<T>* data) {
		Student_Node* head_1d = data->getHead();
		while (head_1d) {
			if (!pHead) {
				Data_1D<T>* pNew_1d = new Data_1D<T>;
				pNew_1d->setData(head_1d->getName()[0]);
				pHead = pNew_1d;
			}
			else {
				Data_1D<T>* temp_1d = pHead;
				Data_1D<T>* pPrev = temp_1d;
				while (temp_1d) {
					if (Compare(temp_1d->getData(), head_1d->getName()[0]) == 1) {
						if (temp_1d == pHead) {
							Data_1D<T>* pNew_1d = new Data_1D<T>;
							pNew_1d->setData(head_1d->getName()[0]);
							pNew_1d->setNext(pHead);
							pHead = pNew_1d;
						}
						else {
							Data_1D<T>* pNew_1d = new Data_1D<T>;
							pNew_1d->setData(head_1d->getName()[0]);
							pPrev->setNext(pNew_1d);
							pNew_1d->setNext(temp_1d);
						}
						break;
					}
					else if (Compare(temp_1d->getData(), head_1d->getName()[0]) == 0)
						break;
					pPrev = temp_1d;
					temp_1d = temp_1d->getNext();
					if (!temp_1d) {
						Data_1D<T>* pNew_1d = new Data_1D<T>;
						pNew_1d->setData(head_1d->getName()[0]);
						pPrev->setNext(pNew_1d);
						break;
					}
				}
			}
			head_1d = head_1d->getNext();
		}
		head_1d = data->getHead();
		while (head_1d) {
			Data_1D<T>* temp_1d = pHead;
			while (temp_1d) {
				if (Compare(temp_1d->getData(), head_1d->getName()[0]) == 0) {
					if (!temp_1d->getHead()) {
						temp_1d->setHead(head_1d);
						break;
					}
					else {
						Student_Node* temp = temp_1d->getHead();
						Student_Node* pPrev = temp;
						while (temp) {
							if (Compare(temp->getName(), head_1d->getName()) == 1) {
								if (temp == temp_1d->getHead()) {
									head_1d->setNext_Name(temp_1d->getHead());
									temp_1d->setHead(head_1d);
								}
								else {
									pPrev->setNext_Name(head_1d);
									head_1d->setNext_Name(temp);
								}
								break;
							}
							pPrev = temp;
							temp = temp->getNext_Name();
							if (!temp) {
								pPrev->setNext_Name(head_1d);
								break;
							}
						}
					}
				}
				//print_char();
				temp_1d = temp_1d->getNext();
			}
			head_1d = head_1d->getNext();
		}
	}

	void print_char() {
		Data_1D<T>* pTemp = pHead;
		std::cout << "Print File" << '\n';
		std::cout << "=========================================================================" << '\n';
		while (pTemp) {
			std::cout << pTemp->getData() << '\n';
			Student_Node* temp = pTemp->getHead();
			std::cout << "StudentID";
			std::cout.width(30);
			std::cout << "Major" << '\t' << '\t';
			std::cout.width(10);
			std::cout << "Name" << '\n';
			while (temp) {
				std::cout << temp->getStudentId();
				std::cout.width(30);
				std::cout << temp->getMajor() << '\t';
				std::cout.width(10);
				std::cout << temp->getName() << '\n';
				temp = temp->getNext_Name();
			}
			pTemp = pTemp->getNext();
		}
		std::cout << '\n';
		std::cout << "=========================================================================" << '\n';
	}
};