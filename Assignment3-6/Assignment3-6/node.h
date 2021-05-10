#pragma once
#include <iostream>

class Node {
private:
	char name[5];
	Node* pNext;
	Node* pPrev;

public:
	char* getName() {
		return name;
	}

	Node* getNext() {
		return pNext;
	}
	
	Node* getPrev() {
		return pPrev;
	}

	void setName(char* temp) {
		strcpy_s(name, temp);
	}

	void setNext(Node* pTemp) {
		pNext = pTemp;
	}

	void setPrev(Node* pTemp) {
		pPrev = pTemp;
	}
};