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

	Student_Node() { // 생성자
		memset(Student_Id, NULL, 100);
		memset(Major, NULL, 100);
		memset(Name, NULL, 100);
		pNext = nullptr;
		pNext_ID = nullptr;
		pNext_Name = nullptr;
		pNext_Major = nullptr;
	}

	~Student_Node() {

	}

	void setStudentId(char* temp) { // 값을 변경하는매소드
		strcpy_s(Student_Id, temp);
	}

	void setMajor(char* temp) {// 값을 변경하는매소드
		strcpy_s(Major, temp);
	}
	void setName(char* temp) {// 값을 변경하는매소드
		strcpy_s(Name, temp);
	}

	void setNext(Student_Node *pTemp) {// 값을 변경하는매소드
		pNext = pTemp;
	}

	void setNext_ID(Student_Node* pTemp) {// 값을 변경하는매소드
		pNext_ID = pTemp;
	}

	void setNext_Major(Student_Node* pTemp) {// 값을 변경하는매소드
		pNext_Major = pTemp;
	}

	void setNext_Name(Student_Node* pTemp) {// 값을 변경하는매소드
		pNext_Name = pTemp;
	}

	char* getStudentId() { // 값을 반환하는 매소드
		return Student_Id;
	}

	char* getMajor() {// 값을 반환하는 매소드
		return Major;
	}

	char* getName() {// 값을 반환하는 매소드
		return Name;
	}

	Student_Node* getNext() {// 값을 반환하는 매소드
		return pNext;
	}

	Student_Node* getNext_ID() {// 값을 반환하는 매소드
		return pNext_ID;
	}

	Student_Node* getNext_Name() {// 값을 반환하는 매소드
		return pNext_Name;
	}

	Student_Node* getNext_Major() {// 값을 반환하는 매소드
		return pNext_Major;
	}
	

};