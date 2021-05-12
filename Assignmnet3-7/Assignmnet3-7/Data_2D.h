#pragma once
#include "Data_1D.h"
#include <iostream>

template<typename T>
class Data_2D {
private:
	Data_1D<T> *pHead;
public:
	Data_2D(){
		pHead = nullptr;
	}
	
	~Data_2D() {

	}

	Data_1D<T>* getHead() {
		return pHead;
	}

	void setHead(Data_1D<T>* pTemp) {
		pHead = pTemp;
	}

	template <typename T>
	void Insert(Student_Node* node) {
		if (!pHead) {
			Data_1D<T>* data_1d = new Data_1D<T>;
			data_1d->setData(node->getName()[0]);
			data_1d->Insert_input<char>(node);
			pHead = data_1d;
		}
		else {
			Data_1D<T>* pWork = pHead;
			Data_1D<T>* pPrev = pHead;
			
			while (pWork) {
				if (pWork->Compare(pWork->getData(),node->getName()[0]) == 0) {
					pWork->Insert_input<char>(node);
					return;
				}
				else if (pWork->Compare(pWork->getData(), node->getName()[0]) == 1) {
					if (pHead == pWork) {
						Data_1D<T>* data_1d = new Data_1D<T>;
						data_1d->setData(node->getName()[0]);
						data_1d->Insert_input<char>(node);
						data_1d->setNext(pHead);
						pHead = data_1d;
					}
					else {
						Data_1D<T>* data_1d = new Data_1D<T>;
						data_1d->setData(node->getName()[0]);
						data_1d->Insert_input<char>(node);
						pPrev->setNext(data_1d);
						data_1d->setNext(pWork);
					}
					return;
				}
				else {
					pPrev = pWork;
					pWork = pWork->getNext();
				}
			}
			pWork = new Data_1D<T>;
			pWork->setData(node->getName()[0]);
			pWork->Insert_input<char>(node);
			pPrev->setNext(pWork);
			
		}
	}

	int CovertId(char* temp) {
		int res = 0;
		for (int i = 0; i < 4; i++) {
			res += temp[i] -'0';
			res *= 10;
		}
		return res / 10;
	}

	template <>
	void Insert<int>(Student_Node* node) {
		if (!pHead) {
			Data_1D<int>* data_1d = new Data_1D<int>;
			data_1d->setData(CovertId(node->getStudentId()));
			data_1d->Insert_input<int>(node);
			pHead = data_1d;
		}
		else {
			Data_1D<int>* pWork = pHead;
			Data_1D<int>* pPrev = pHead;

			while (pWork) {
				if (pWork->Compare<int>(pWork->getData(), CovertId(node->getStudentId())) == 0) {
					pWork->Insert_input<int>(node);
					return;
				}
				else if (pWork->Compare<int>(pWork->getData(), CovertId(node->getStudentId())) == 1) {
					if (pHead == pWork) {
						Data_1D<int>* data_1d = new Data_1D<int>;
						data_1d->setData(CovertId(node->getStudentId()));
						data_1d->Insert_input<int>(node);
						data_1d->setNext(pHead);
						pHead = data_1d;
					}
					else {
						Data_1D<int>* data_1d = new Data_1D<int>;
						data_1d->setData(CovertId(node->getStudentId()));
						data_1d->Insert_input<int>(node);
						pPrev->setNext(data_1d);
						data_1d->setNext(pWork);
					}
					return;
				}
				else {
					pPrev = pWork;
					pWork = pWork->getNext();
				}
			}
			pWork = new Data_1D<int>;
			pWork->setData(CovertId(node->getStudentId()));
			pWork->Insert_input<int>(node);
			pPrev->setNext(pWork);
		}
	}

	template <>
	void Insert<char*>(Student_Node* node) {
		if (!pHead) {
			Data_1D<char*>* data_1d = new Data_1D<char*>;
			data_1d->setData(node->getMajor());
			data_1d->Insert_input<char*>(node);
			pHead = data_1d;
		}
		else {
			Data_1D<char*>* pWork = pHead;
			Data_1D<char*>* pPrev = pHead;

			while (pWork) {
				if (pWork->Compare<char*>(pWork->getData(), node->getMajor()) == 0) {
					pWork->Insert_input<char*>(node);
					return;
				}
				else if (pWork->Compare<char*>(pWork->getData(), node->getMajor()) == 1) {
					if (pHead == pWork) {
						Data_1D<char*>* data_1d = new Data_1D<char*>;
						data_1d->setData(node->getMajor());
						data_1d->Insert_input<char*>(node);
						data_1d->setNext(pHead);
						pHead = data_1d;
					}
					else {
						Data_1D<char*>* data_1d = new Data_1D<char*>;
						data_1d->setData(node->getMajor());
						data_1d->Insert_input<char*>(node);
						pPrev->setNext(data_1d);
						data_1d->setNext(pWork);
					}
					return;
				}
				else {
					pPrev = pWork;
					pWork = pWork->getNext();
				}
			}
			pWork = new Data_1D<char*>;
			pWork->setData(node->getMajor());
			pWork->Insert_input<char*>(node);
			pPrev->setNext(pWork);
		}
	}

	template<typename T>
	void print() {
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
			std::cout << '\n';
		}
		std::cout << '\n';
		std::cout << "=========================================================================" << '\n';
	}

	template<>
	void print<char*>() {
		Data_1D<char*>* pTemp = pHead;
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
				temp = temp->getNext_Major();
			}
			pTemp = pTemp->getNext();
			std::cout << '\n';
		}
		std::cout << '\n';
		std::cout << "=========================================================================" << '\n';
	}

	template<>
	void print<int>() {
		Data_1D<int>* pTemp = pHead;
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
				temp = temp->getNext_ID();
			}
			pTemp = pTemp->getNext();
			std::cout << '\n';
		}
		std::cout << '\n';
		std::cout << "=========================================================================" << '\n';
	}

	template<typename T>
	void delete_data() {
		Data_1D<T>* pTemp = pHead;
		while (pTemp) {
			delete pTemp->getData();
			pTemp = pTemp->getNext();
		}
	}

	template<typename T>
	void Remove_data() {
		Data_1D<T>* pTemp = pHead;
		while (pTemp) {
			pHead = pHead->getNext();
			delete pTemp;
			pTemp = pHead;
		}
	}
};
