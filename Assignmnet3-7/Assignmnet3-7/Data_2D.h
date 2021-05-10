#pragma once
#include "Data_1D.h"

class Data_2D {
private:
	Data_1D<int>* pHead_year;
	Data_1D<char>* pHead_alphabet;
	Data_1D<char*>* pHead_major;

public:
	Data_2D() {
		pHead_year = nullptr;
		pHead_alphabet = nullptr;
		pHead_major = nullptr;
	}
	~Data_2D() {
		
	}

	Data_1D<int> *getHead_year() {
		return pHead_year;
	}
	Data_1D<char> *getHead_alphabet() {
		return pHead_alphabet;
	}

	Data_1D<char*> *getHead_major() {
		return pHead_major;
	}

	void setHead_year(Data_1D<int> *pTemp) {
		pHead_year = pTemp;
	}

	void setHead_alphabet(Data_1D<char> *pTemp) {
		pHead_alphabet = pTemp;
	}

	void setHead_name(Data_1D<char*> *pTemp) {
		pHead_major = pTemp;
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

	bool find_same(char data) {
		Data_1D<char> *pTemp = pHead_alphabet;
		while (pTemp) {
			if (pTemp->getData() == data)
				return false;
			pTemp = pTemp->getNext();
		}
		return true;
	}

	void Insert_alphabet(Data_1D<char> *data) {
		Student_Node* pTemp = data->getHead();
		Data_1D<char>* pTail = pHead_alphabet;
		while (pTemp) {
			if (pHead_alphabet == nullptr) {
				Data_1D<char> *pNew = new Data_1D<char>;
				pNew->setData(pTemp->getAlphabet());
				pHead_alphabet = pNew;
				pTail = pNew;
			}
			else {
				if (find_same(pTemp->getAlphabet())) {
					Data_1D<char>* pNew = new Data_1D<char>;
					pNew->setData(pTemp->getAlphabet());
					pTail->setNext(pNew);
					pTail = pNew;
				}
			}
			pTemp = pTemp->getNext();
		}
		pTemp = data->getHead();
		while (pTemp) {
			Data_1D<char>* pTemp_1d = pHead_alphabet;
			while (pTemp_1d->getData() != pTemp->getAlphabet())
				pTemp_1d = pTemp_1d->getNext();
			if (pTemp_1d->getHead() == nullptr) {
				pTemp_1d->setHead(pTemp);
				pTemp_1d->setTail(pTemp);
			}
			else {

			}
		}
	}

};