#pragma once
#include "Student_Node.h"
#include <iostream>

template<typename T>
class Data_1D {
private:
	Student_Node* pHead;
	Student_Node* pTail;
	Data_1D<T>* pNext;
	
	T data; // ���ø������� 2���������Ϳ��� �����͸� ����
	 
public:
	Data_1D() { // ������
		pHead = nullptr;
		pTail = nullptr;
		pNext = nullptr;
		data = NULL;
	}

	~Data_1D() { // �Ҹ���

	}

	Data_1D* getNext() { // ���� ��ȯ�ϴ� �żҵ�
		return pNext;
	}

	Student_Node* getHead() {// ���� ��ȯ�ϴ� �żҵ�
		return pHead;
	}
	Student_Node* getTail() {// ���� ��ȯ�ϴ� �żҵ�
		return pTail;
	}

	T getData() {// ���� ��ȯ�ϴ� �żҵ�
		return data;
	}
	
	void setData(char temp) { // ���� �����ϴ� �żҵ�
		data = temp;
	}

	void setData(char* temp) {// ���� �����ϴ� �żҵ�
		data = new char[100]; // data�� char* �϶��� �����Ҵ�
		for (int i = 0; i < 100; i++) {
			data[i] = temp[i];
		}
	}

	void setData(int temp) {// ���� �����ϴ� �żҵ�
		data = temp;
	}
	
	void setHead(Student_Node* pTemp) {// ���� �����ϴ� �żҵ�
		pHead = pTemp;
	}

	void setTail(Student_Node* pTemp) {// ���� �����ϴ� �żҵ�
		pTail = pTemp;
	}

	void setNext(Data_1D<T> *temp) {// ���� �����ϴ� �żҵ�
		pNext = temp;
	}

	template<typename T>
	void Insert_input(Student_Node* node) { // input�� ���ؼ� Student_node�� input���ִ� �żҵ�
		if (!pHead) { // head�� ������� �� haed�� tail�� ����
			pHead = node;
			pTail = node;
		}
		else {
			pTail->setNext(node); //tail�� �������� ���ο� ����
			pTail = node; // ���ο� ��尡 ���ǰ����� tail�� �ȴ�.
		}
	}

	template<>
	void Insert_input<int>(Student_Node* node) { // 2���� ��ũ�帮��Ʈ�� year���� 1���� ��ũ�帮��Ʈ�� insert�ϴ� �żҵ�
		Student_Node* pTemp = getHead(); 
		if (!pHead) { // pHead�� ������� ��
			pHead = node; // pHead�� ���� ����
		}
		else {
			Student_Node* pPrev = pTemp; // pTemp�� pPrev�� �������� ��������
			while (pTemp) {
				if (Compare(pTemp->getStudentId(), node->getStudentId()) == 1) { // ���Ѱ��� �񱳴��Ѱ����� Ŭ�� ���ڸ��� ������
					if (pTemp == pHead) { //�� �ڸ��� pHead�϶��� �Է°��� pHead�� ����
						node->setNext_ID(pHead);
						pHead = node;
					}
					else { // pHead�� �ƴ϶� �Ϲ����� ��Ȳ������ �������� pTemp�� ��������
						pPrev->setNext_ID(node);
						node->setNext_ID(pTemp);
					}
					break; // ������ ������ �ݺ�������
				}
				pPrev = pTemp; // pPrev�� pTemp��
				pTemp = pTemp->getNext_ID(); // pTemp�� �״���������
				if (!pTemp) { // pTmep�� nullptr�� ����
					pPrev->setNext_ID(node); // �������� �ؽ�Ʈ�� �Է°����� �Է°��� ���� ������
				}
			}
		}
	}

	template<>
	void Insert_input<char>(Student_Node* node) {// 2���� ��ũ�帮��Ʈ�� name���� 1���� ��ũ�帮��Ʈ�� insert�ϴ� �żҵ�
		Student_Node* pTemp = getHead();
		if (!pHead) { // pHead�� ������ head�� �������ִ� ���ǹ�
			pHead = node;
		}
		else { // pHead�� ���� ��
			Student_Node* pPrev = pTemp;
			while (pTemp) { // pTem�� ������ �϶����� 
				if (Compare(pTemp->getName(), node->getName()) == 1) { // �񱳳�尡 �Է��� ��庸�� Ŭ��
					if (pTemp == pHead) { // pHead�� ���ؼ� Ŭ���� pHead���� ������ ���� ������ ���ο� �Է��� haed�� ����
						node->setNext_Name(pHead); 
						pHead = node;
					}
					else { // pHead�� �ƴ� �Ϲ����� ��Ȳ�Ͻ� �������� �ؽ�Ʈ�� �����Ѱ��� �ؽ�Ʈ�� ��������
						pPrev->setNext_Name(node); 
						node->setNext_Name(pTemp);
					}
					break; // �ݺ�������
				}
				pPrev = pTemp; // pTemp�� �������� pTemp��
				pTemp = pTemp->getNext_Name(); // pTemp�� ����������
				if (!pTemp) { // pTemp�� nullptr�� �� �������� ���ο�� ����
					pPrev->setNext_Name(node);
				}
			}
		}
	}

	template<>
	void Insert_input<char*>(Student_Node* node) { // 2���� ��ũ�帮��Ʈ�� major���� 1���� ��ũ�帮��Ʈ�� insert�ϴ� �żҵ�
		Student_Node* pTemp = getHead();
		if (!pHead) { // head�� ������� �� haed�� ����
			pHead = node;
		}
		else { // pHead�� ���� ��
			Student_Node* pPrev = pTemp;
			while (pTemp) {
				if (Compare<char*>(pTemp->getStudentId(), node->getStudentId()) == 1) {// �񱳳�尡 �Է��� ��庸�� Ŭ��
					if (pTemp == pHead) {// pHead�� ���ؼ� Ŭ���� pHead���� ������ ���� ������ ���ο� �Է��� haed�� ����
						node->setNext_Major(pHead);
						pHead = node;
					}
					else {// pHead�� �ƴ� �Ϲ����� ��Ȳ�Ͻ� �������� �ؽ�Ʈ�� �����Ѱ��� �ؽ�Ʈ�� ��������
						pPrev->setNext_Major(node);
						node->setNext_Major(pTemp);
					}
					break;// �ݺ�������
				}
				pPrev = pTemp; //pTemp�� �������� pTemp��
				pTemp = pTemp->getNext_Major(); // pTemp�� ����������
				if (!pTemp) { // pTemp�� nullptr�϶��� ���������̹Ƿ� ���������� ���ο� ��带 ����
					pPrev->setNext_Major(node);
				}
			}
		}
	}

	void print() { // 1�����迭�� ���� print�ϴ� �żҵ�
		Student_Node* pTemp = pHead; //pTemp�� pHead��
		std::cout << "Print File" << '\n';
		std::cout << "=========================================================================" << '\n';
		while (pTemp) { // pTemp�� null�϶�����
			std::cout << pTemp->getStudentId();
			std::cout.width(30);
			std::cout << pTemp->getMajor() << '\t' << '\t';
			std::cout.width(10);
			std::cout << pTemp->getName() << '\n';
			pTemp = pTemp->getNext(); // pTemp�� ����������
		}
		std::cout << "=========================================================================" << '\n';
	}

	template<typename T>
	int Compare(T temp1, T temp2) { // �� ���� ���ϴ� �żҵ�
		if (temp1 > temp2) // temp1�� temp2���� Ŭ�� 1��ȯ
			return 1;
		else if (temp1 == temp2) // �������� 0��ȯ
			return 0;
		return -1; // temp1�� temp2 ���� �������� -1��ȯ
	}

	template<>
	int Compare<char*>(char* temp1, char* temp2) { // �� ���� ���ϴ� �żҵ�
		char T_temp1[100];
		char T_temp2[100];
		for (int i = 0; i <= strlen(temp1); i++) { // ���� �����ϰ� ���ϱ� ���� �ҹ��ڷ� ��ħ
			if (temp1[i] >= 'A' && temp1[i] <= 'Z')
				T_temp1[i] = temp1[i] + 'a' - 'A';
			else
				T_temp1[i] = temp1[i];
		}
		for (int i = 0; i <= strlen(temp2); i++) { // ���� �����ϰ� ���ϱ� ���� �ҹ��ڷ� ��ħ
			if (temp2[i] >= 'A' && temp2[i] <= 'Z')
				T_temp2[i] = temp2[i] + 'a' - 'A';
			else
				T_temp2[i] = temp2[i];
		}
		//std::cout << "temp1 : " << T_temp1 << " temp2 : " << T_temp2 << " strcmp : " << strcmp(temp1,temp2) <<'\n';
		return strcmp(temp1, temp2); // strcmp�Ѱ��� return
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