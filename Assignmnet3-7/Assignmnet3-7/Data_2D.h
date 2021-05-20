#pragma once
#include "Data_1D.h"
#include <iostream>

template<typename T>
class Data_2D {
private:
	Data_1D<T> *pHead;
public:
	Data_2D(){ //������
		pHead = nullptr;
	}
	
	~Data_2D() { // �Ҹ���

	}

	Data_1D<T>* getHead() { // ���� ��ȯ�ϴ� �żҵ�
		return pHead;
	}

	void setHead(Data_1D<T>* pTemp) { //���� �����ϴ� �żҵ�
		pHead = pTemp;
	}

	template <typename T>
	void Insert(Student_Node* node) { // typename T�� ���� 2������ũ�帮��Ʈ�� ��带 insert�ϴ� �żҵ�
		if (!pHead) { // head�� ����������
			Data_1D<T>* data_1d = new Data_1D<T>; //���ο� ��ü ����
			data_1d->setData(CovertId(node->getStudentId())); // data���� �°� convert�ϴ� �żҵ� ȣ��
			data_1d->Insert_input<T>(node); // 1�����迭�� �����ͷε� insert�ϴ� �żҵ� ȣ��
			pHead = data_1d;
		}
		else {
			Data_1D<T>* pWork = pHead;
			Data_1D<T>* pPrev = pHead;

			while (pWork) { // pWork�� nullptr�� �ɶ�����
				if (pWork->Compare<T>(pWork->getData(), CovertId(node->getStudentId())) == 0) {
					pWork->Insert_input<T>(node);
					return;
				}
				else if (pWork->Compare<T>(pWork->getData(), CovertId(node->getStudentId())) == 1) {
					if (pHead == pWork) {
						Data_1D<T>* data_1d = new Data_1D<T>;
						data_1d->setData(CovertId(node->getStudentId()));
						data_1d->Insert_input<T>(node);
						data_1d->setNext(pHead);
						pHead = data_1d;
					}
					else {
						Data_1D<T>* data_1d = new Data_1D<T>;
						data_1d->setData(CovertId(node->getStudentId()));
						data_1d->Insert_input<T>(node);
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
			pWork->setData(CovertId(node->getStudentId()));
			pWork->Insert_input<T>(node);
			pPrev->setNext(pWork);
		}
	}

	template <>
	void Insert<char>(Student_Node* node) { // 2�����迭�� ���� �����ϴ� �żҵ�
		if (!pHead) { // head�� ����� �� ���ο� ��ü ������ ���־��ֱ� , haed, tail�� ����
			Data_1D<T>* data_1d = new Data_1D<T>;
			data_1d->setData(node->getName()[0]);
			data_1d->Insert_input<char>(node);
			pHead = data_1d;
		}
		else { // haed�� ������� ���� ��
			Data_1D<T>* pWork = pHead;
			Data_1D<T>* pPrev = pHead;
			
			while (pWork) { // pWokr�� nullptr�϶�����
				if (pWork->Compare(pWork->getData(),node->getName()[0]) == 0) { //���ؼ� �������̳����� ���� 1�����迭 ��带 �������ֱ� ���ؼ� insert_input �żҵ� ȣ��
					pWork->Insert_input<char>(node);
					return;
				}
				else if (pWork->Compare(pWork->getData(), node->getName()[0]) == 1) { //���Ѱ��� ���ο���� ū���ϰ��
					if (pHead == pWork) { // pHead�� ��ġ�������� pHead�� �缳���ϰ� ����head�� �о���
						Data_1D<T>* data_1d = new Data_1D<T>;
						data_1d->setData(node->getName()[0]);
						data_1d->Insert_input<char>(node);
						data_1d->setNext(pHead);
						pHead = data_1d;
					}
					else { // pHead�� ��ġ���� ���� ���� �������� �������� next���踦 �缳��
						Data_1D<T>* data_1d = new Data_1D<T>;
						data_1d->setData(node->getName()[0]);
						data_1d->Insert_input<char>(node);
						pPrev->setNext(data_1d);
						data_1d->setNext(pWork);
					}
					return; // �ݺ�������
				}
				else { // ���� �������� ���������� �̵�
					pPrev = pWork; 
					pWork = pWork->getNext();
				}
			}
			pWork = new Data_1D<T>; // nullptr�̿��� ������ ���� �ǵ��� ���̱� ������ ���ο�� ��������
			pWork->setData(node->getName()[0]);
			pWork->Insert_input<char>(node);
			pPrev->setNext(pWork);
			
		}
	}

	int CovertId(char* temp) { // �й��� �⵵�� ���ڷ� ��ȯ�ϴ� �żҵ�
		int res = 0; // ��ȯ�ؼ� res�� ��ȯ
		for (int i = 0; i < 4; i++) {
			res += temp[i] -'0';
			res *= 10;
		}
		return res / 10;
	}

	template <>
	void Insert<int>(Student_Node* node) { // int���� ���� INSERT ���� ����� ����
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
	void Insert<char*>(Student_Node* node) { // char*�ΰ�� INSERT���ִ� �żҵ� Typename���� ������ �Ͱ� ����
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
	void print() { // typename�� T�϶� ������ ������ִ� �żҵ�
		Data_1D<T>* pTemp = pHead; //pTemp�� pHead�� 
		std::cout << "=========================================================================" << '\n';
		while (pTemp) {
			std::cout << pTemp->getData() << '\n'; // pTemp�� �����͸� ������
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
				temp = temp->getNext_Name(); //name�� ���ؼ� ������
			}
			pTemp = pTemp->getNext();
			std::cout << '\n';
		}
		std::cout << '\n';
		std::cout << "=========================================================================" << '\n';
	}

	template<>
	void print<char*>() { // char* �϶� ������ ����ϴ¸żҵ�
		Data_1D<char*>* pTemp = pHead;
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
	void print<int>() {// int�� �϶� ������ ����ϴ¸żҵ�
		Data_1D<int>* pTemp = pHead;
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
	void delete_data() { // �������� ���� �����Ҵ��ϴ� �żҵ�
		Data_1D<T>* pTemp = pHead;
		while (pTemp) {
			delete pTemp->getData();
			pTemp = pTemp->getNext();
		}
	}

	template<typename T>
	void Remove_data() { // data�� ���� �����Ҵ��ϴ� �żҵ�
		Data_1D<T>* pTemp = pHead;
		while (pTemp) {
			pHead = pHead->getNext();
			delete pTemp;
			pTemp = pHead;
		}
	}
};
