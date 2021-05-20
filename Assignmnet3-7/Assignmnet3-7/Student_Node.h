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

	Student_Node() { // ������
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

	void setStudentId(char* temp) { // ���� �����ϴ¸żҵ�
		strcpy_s(Student_Id, temp);
	}

	void setMajor(char* temp) {// ���� �����ϴ¸żҵ�
		strcpy_s(Major, temp);
	}
	void setName(char* temp) {// ���� �����ϴ¸żҵ�
		strcpy_s(Name, temp);
	}

	void setNext(Student_Node *pTemp) {// ���� �����ϴ¸żҵ�
		pNext = pTemp;
	}

	void setNext_ID(Student_Node* pTemp) {// ���� �����ϴ¸żҵ�
		pNext_ID = pTemp;
	}

	void setNext_Major(Student_Node* pTemp) {// ���� �����ϴ¸żҵ�
		pNext_Major = pTemp;
	}

	void setNext_Name(Student_Node* pTemp) {// ���� �����ϴ¸żҵ�
		pNext_Name = pTemp;
	}

	char* getStudentId() { // ���� ��ȯ�ϴ� �żҵ�
		return Student_Id;
	}

	char* getMajor() {// ���� ��ȯ�ϴ� �żҵ�
		return Major;
	}

	char* getName() {// ���� ��ȯ�ϴ� �żҵ�
		return Name;
	}

	Student_Node* getNext() {// ���� ��ȯ�ϴ� �żҵ�
		return pNext;
	}

	Student_Node* getNext_ID() {// ���� ��ȯ�ϴ� �żҵ�
		return pNext_ID;
	}

	Student_Node* getNext_Name() {// ���� ��ȯ�ϴ� �żҵ�
		return pNext_Name;
	}

	Student_Node* getNext_Major() {// ���� ��ȯ�ϴ� �żҵ�
		return pNext_Major;
	}
	

};