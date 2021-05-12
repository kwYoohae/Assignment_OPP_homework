#pragma once
#include <iostream>

class Student_Node {
private:
	char Student_Id[100];
	char Major[100];
	char Name[100];

	Student_Node* pNext;
	Student_Node* pNext_ID;
	Student_Node* pNext_Name;
	Student_Node* pNext_Major;

public:

	Student_Node() {
		memset(Student_Id, NULL, 100);
		memset(Major, NULL, 100);
		memset(Name, NULL, 100);
		pNext = nullptr;
		pNext_ID = nullptr;
		pNext_Name = nullptr;
		pNext_Major = nullptr;
	}

	void setStudentId(char* temp) {
		strcpy_s(Student_Id, temp);
	}

	void setMajor(char* temp) {
		strcpy_s(Major, temp);
	}
	void setName(char* temp) {
		strcpy_s(Name, temp);
	}

	void setNext(Student_Node *pTemp) {
		pNext = pTemp;
	}

	void setNext_ID(Student_Node* pTemp) {
		pNext_ID = pTemp;
	}

	void setNext_Major(Student_Node* pTemp) {
		pNext_Major = pTemp;
	}

	void setNext_Name(Student_Node* pTemp) {
		pNext_Name = pTemp;
	}

	char* getStudentId() {
		return Student_Id;
	}

	char* getMajor() {
		return Major;
	}

	char* getName() {
		return Name;
	}

	Student_Node* getNext() {
		return pNext;
	}

	Student_Node* getNext_ID() {
		return pNext_ID;
	}

	Student_Node* getNext_Name() {
		return pNext_Name;
	}

	Student_Node* getNext_Major() {
		return pNext_Major;
	}
	

};