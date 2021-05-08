#pragma once
#include "Data_1D.h"

template<typename T>
class Data_2D {
private:
	Student_Node* pHead_year;
	Student_Node* pHead_alphabet;
	Student_Node* pHead_major;

public:
	Data_2D() {
		pHead_year = nullptr;
		pHead_alphabet = nullptr;
		pHead_major = nullptr;
	}
	~Data_2D() {
		
	}

	Student_Node* getHead_year() {
		return pHead_year;
	}
	Student_Node* getHead_alphabet() {
		return pHead_alphabet;
	}

	Student_Node* getHead_major() {
		return pHead_major;
	}

	void setHead_year(Student_Node* pTemp) {
		pHead_year = pTemp;
	}

	void setHead_alphabet(Student_Node* pTemp) {
		pHead_alphabet = pTemp;
	}

	void setHead_name(Student_Node* pTemp) {
		pHead_major = pTemp;
	}

	int Compare(char* temp1, char* temp2) {
		char T_temp1[100];
		char T_temp2[100];
		for (int i = 0; i <= strlen(temp1); i++) {
			if (temp1[i] >= 'A' && temp1[i] <= 'Z')
				T_temp1[i] = temp1[i] + 'a' - 'A';
			else
				T_temp[i] = temp1[i];
		}
		for (int i = 0; i < strlen(temp2); i++) {
			if (temp2[i] >= 'A' && temp2[i] <= 'Z')
				T_temp1[i] = temp2[i] + 'a' - 'A';
			else
				T_temp2[i] = temp2[i];
		}
		return strcmp(temp1, temp2);
	}

	void Insert_alphabet(Data_1D *data) {
		Student_Node* pTemp = data->getHead();
		while (pTemp) {
			if (pHead_alphabet == nullptr) {
				pHead_alphabet = pTemp;
				 
			}
			else {

			}
		}
	}

};