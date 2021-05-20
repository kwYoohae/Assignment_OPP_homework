#pragma once
#include "Student_Node.h"
#include <iostream>

template<typename T>
class Data_1D {
private:
	Student_Node* pHead;
	Student_Node* pTail;
	Data_1D<T>* pNext;
	
	T data; // 템플릿변수로 2차원데이터에서 데이터를 저장
	 
public:
	Data_1D() { // 생성자
		pHead = nullptr;
		pTail = nullptr;
		pNext = nullptr;
		data = NULL;
	}

	~Data_1D() { // 소멸자

	}

	Data_1D* getNext() { // 값을 반환하는 매소드
		return pNext;
	}

	Student_Node* getHead() {// 값을 반환하는 매소드
		return pHead;
	}
	Student_Node* getTail() {// 값을 반환하는 매소드
		return pTail;
	}

	T getData() {// 값을 반환하는 매소드
		return data;
	}
	
	void setData(char temp) { // 값을 변경하는 매소드
		data = temp;
	}

	void setData(char* temp) {// 값을 변경하는 매소드
		data = new char[100]; // data가 char* 일때는 동적할당
		for (int i = 0; i < 100; i++) {
			data[i] = temp[i];
		}
	}

	void setData(int temp) {// 값을 변경하는 매소드
		data = temp;
	}
	
	void setHead(Student_Node* pTemp) {// 값을 변경하는 매소드
		pHead = pTemp;
	}

	void setTail(Student_Node* pTemp) {// 값을 변경하는 매소드
		pTail = pTemp;
	}

	void setNext(Data_1D<T> *temp) {// 값을 변경하는 매소드
		pNext = temp;
	}

	template<typename T>
	void Insert_input(Student_Node* node) { // input에 대해서 Student_node를 input해주는 매소드
		if (!pHead) { // head가 비어있을 때 haed와 tail을 설정
			pHead = node;
			pTail = node;
		}
		else {
			pTail->setNext(node); //tail의 다음값은 새로운 노드로
			pTail = node; // 새로운 노드가 뒤의값으로 tail이 된다.
		}
	}

	template<>
	void Insert_input<int>(Student_Node* node) { // 2차원 링크드리스트의 year값의 1차원 링크드리스트르 insert하는 매소드
		Student_Node* pTemp = getHead(); 
		if (!pHead) { // pHead가 비어있을 때
			pHead = node; // pHead는 노드로 설정
		}
		else {
			Student_Node* pPrev = pTemp; // pTemp의 pPrev를 가리켜줄 변수생성
			while (pTemp) {
				if (Compare(pTemp->getStudentId(), node->getStudentId()) == 1) { // 비교한값이 비교당한값보다 클때 그자리에 들어가야함
					if (pTemp == pHead) { //들어갈 자리가 pHead일때는 입력값을 pHead로 설정
						node->setNext_ID(pHead);
						pHead = node;
					}
					else { // pHead가 아니라 일반적인 상황에서는 이전값이 pTemp를 가리켜줌
						pPrev->setNext_ID(node);
						node->setNext_ID(pTemp);
					}
					break; // 설정이 끝난후 반복문종료
				}
				pPrev = pTemp; // pPrev는 pTemp로
				pTemp = pTemp->getNext_ID(); // pTemp는 그다음값으로
				if (!pTemp) { // pTmep가 nullptr일 경우는
					pPrev->setNext_ID(node); // 이전값의 넥스트를 입력값으로 입력값을 제일 끝으로
				}
			}
		}
	}

	template<>
	void Insert_input<char>(Student_Node* node) {// 2차원 링크드리스트의 name값의 1차원 링크드리스트르 insert하는 매소드
		Student_Node* pTemp = getHead();
		if (!pHead) { // pHead가 없을때 head를 설정해주는 조건문
			pHead = node;
		}
		else { // pHead가 있을 때
			Student_Node* pPrev = pTemp;
			while (pTemp) { // pTem가 마지막 일때까지 
				if (Compare(pTemp->getName(), node->getName()) == 1) { // 비교노드가 입력한 노드보다 클때
					if (pTemp == pHead) { // pHead랑 비교해서 클때는 pHead보다 전으로 들어가야 함으로 새로운 입력을 haed로 설정
						node->setNext_Name(pHead); 
						pHead = node;
					}
					else { // pHead가 아닌 일반적인 상황일시 이전값의 넥스트와 생성한값의 넥스트를 결정해줌
						pPrev->setNext_Name(node); 
						node->setNext_Name(pTemp);
					}
					break; // 반복문종료
				}
				pPrev = pTemp; // pTemp의 이전값은 pTemp로
				pTemp = pTemp->getNext_Name(); // pTemp는 다음값으로
				if (!pTemp) { // pTemp가 nullptr일 떄 마지막에 새로운값을 저장
					pPrev->setNext_Name(node);
				}
			}
		}
	}

	template<>
	void Insert_input<char*>(Student_Node* node) { // 2차원 링크드리스트의 major값의 1차원 링크드리스트르 insert하는 매소드
		Student_Node* pTemp = getHead();
		if (!pHead) { // head가 비어있을 때 haed를 생성
			pHead = node;
		}
		else { // pHead가 있을 때
			Student_Node* pPrev = pTemp;
			while (pTemp) {
				if (Compare<char*>(pTemp->getStudentId(), node->getStudentId()) == 1) {// 비교노드가 입력한 노드보다 클때
					if (pTemp == pHead) {// pHead랑 비교해서 클때는 pHead보다 전으로 들어가야 함으로 새로운 입력을 haed로 설정
						node->setNext_Major(pHead);
						pHead = node;
					}
					else {// pHead가 아닌 일반적인 상황일시 이전값의 넥스트와 생성한값의 넥스트를 결정해줌
						pPrev->setNext_Major(node);
						node->setNext_Major(pTemp);
					}
					break;// 반복문종료
				}
				pPrev = pTemp; //pTemp의 이전값은 pTemp로
				pTemp = pTemp->getNext_Major(); // pTemp는 다음값으로
				if (!pTemp) { // pTemp가 nullptr일때는 마지막값이므로 마지막값에 새로운 노드를 저장
					pPrev->setNext_Major(node);
				}
			}
		}
	}

	void print() { // 1차원배열의 값을 print하는 매소드
		Student_Node* pTemp = pHead; //pTemp를 pHead로
		std::cout << "Print File" << '\n';
		std::cout << "=========================================================================" << '\n';
		while (pTemp) { // pTemp가 null일때까지
			std::cout << pTemp->getStudentId();
			std::cout.width(30);
			std::cout << pTemp->getMajor() << '\t' << '\t';
			std::cout.width(10);
			std::cout << pTemp->getName() << '\n';
			pTemp = pTemp->getNext(); // pTemp는 다음값으로
		}
		std::cout << "=========================================================================" << '\n';
	}

	template<typename T>
	int Compare(T temp1, T temp2) { // 두 값을 비교하는 매소드
		if (temp1 > temp2) // temp1이 temp2보다 클때 1반환
			return 1;
		else if (temp1 == temp2) // 같을때는 0반환
			return 0;
		return -1; // temp1이 temp2 보다 작을때는 -1반환
	}

	template<>
	int Compare<char*>(char* temp1, char* temp2) { // 두 값을 비교하는 매소드
		char T_temp1[100];
		char T_temp2[100];
		for (int i = 0; i <= strlen(temp1); i++) { // 값을 동일하게 비교하기 위해 소문자로 고침
			if (temp1[i] >= 'A' && temp1[i] <= 'Z')
				T_temp1[i] = temp1[i] + 'a' - 'A';
			else
				T_temp1[i] = temp1[i];
		}
		for (int i = 0; i <= strlen(temp2); i++) { // 값을 동일하게 비교하기 위해 소문자로 고침
			if (temp2[i] >= 'A' && temp2[i] <= 'Z')
				T_temp2[i] = temp2[i] + 'a' - 'A';
			else
				T_temp2[i] = temp2[i];
		}
		//std::cout << "temp1 : " << T_temp1 << " temp2 : " << T_temp2 << " strcmp : " << strcmp(temp1,temp2) <<'\n';
		return strcmp(temp1, temp2); // strcmp한값을 return
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