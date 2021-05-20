#pragma once
#include "Data_1D.h"
#include <iostream>

template<typename T>
class Data_2D {
private:
	Data_1D<T> *pHead;
public:
	Data_2D(){ //생성자
		pHead = nullptr;
	}
	
	~Data_2D() { // 소멸자

	}

	Data_1D<T>* getHead() { // 값을 반환하는 매소드
		return pHead;
	}

	void setHead(Data_1D<T>* pTemp) { //값을 변경하는 매소드
		pHead = pTemp;
	}

	template <typename T>
	void Insert(Student_Node* node) { // typename T에 대해 2차원링크드리스트의 노드를 insert하는 매소드
		if (!pHead) { // head가 비어있을경우
			Data_1D<T>* data_1d = new Data_1D<T>; //새로운 객체 생성
			data_1d->setData(CovertId(node->getStudentId())); // data형에 맞게 convert하는 매소드 호출
			data_1d->Insert_input<T>(node); // 1차원배열의 데이터로도 insert하는 매소드 호출
			pHead = data_1d;
		}
		else {
			Data_1D<T>* pWork = pHead;
			Data_1D<T>* pPrev = pHead;

			while (pWork) { // pWork가 nullptr이 될때까지
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
	void Insert<char>(Student_Node* node) { // 2차원배열의 값을 저장하는 매소드
		if (!pHead) { // head가 비었을 때 새로운 객체 생성후 값넣어주기 , haed, tail도 생성
			Data_1D<T>* data_1d = new Data_1D<T>;
			data_1d->setData(node->getName()[0]);
			data_1d->Insert_input<char>(node);
			pHead = data_1d;
		}
		else { // haed가 비어있지 않을 때
			Data_1D<T>* pWork = pHead;
			Data_1D<T>* pPrev = pHead;
			
			while (pWork) { // pWokr가 nullptr일때까지
				if (pWork->Compare(pWork->getData(),node->getName()[0]) == 0) { //비교해서 같은값이나오면 안의 1차원배열 노드를 설정해주기 위해서 insert_input 매소드 호출
					pWork->Insert_input<char>(node);
					return;
				}
				else if (pWork->Compare(pWork->getData(), node->getName()[0]) == 1) { //비교한값이 새로운값보다 큰값일경우
					if (pHead == pWork) { // pHead에 위치해있으면 pHead를 재설정하고 기존head를 밀어줌
						Data_1D<T>* data_1d = new Data_1D<T>;
						data_1d->setData(node->getName()[0]);
						data_1d->Insert_input<char>(node);
						data_1d->setNext(pHead);
						pHead = data_1d;
					}
					else { // pHead에 위치하지 않을 때는 이전값과 다음값의 next관계를 재설정
						Data_1D<T>* data_1d = new Data_1D<T>;
						data_1d->setData(node->getName()[0]);
						data_1d->Insert_input<char>(node);
						pPrev->setNext(data_1d);
						data_1d->setNext(pWork);
					}
					return; // 반복문종료
				}
				else { // 값이 작을때는 다음값으로 이동
					pPrev = pWork; 
					pWork = pWork->getNext();
				}
			}
			pWork = new Data_1D<T>; // nullptr이여서 끝났을 때는 맨뒤의 값이기 때문에 새로운값을 생성해줌
			pWork->setData(node->getName()[0]);
			pWork->Insert_input<char>(node);
			pPrev->setNext(pWork);
			
		}
	}

	int CovertId(char* temp) { // 학번의 년도를 숫자로 변환하는 매소드
		int res = 0; // 변환해서 res를 반환
		for (int i = 0; i < 4; i++) {
			res += temp[i] -'0';
			res *= 10;
		}
		return res / 10;
	}

	template <>
	void Insert<int>(Student_Node* node) { // int형에 관한 INSERT 위의 내용과 같음
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
	void Insert<char*>(Student_Node* node) { // char*인경우 INSERT해주는 매소드 Typename으로 정의한 것과 같음
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
	void print() { // typename이 T일때 값들을 출력해주는 매소드
		Data_1D<T>* pTemp = pHead; //pTemp는 pHead로 
		std::cout << "=========================================================================" << '\n';
		while (pTemp) {
			std::cout << pTemp->getData() << '\n'; // pTemp의 데이터를 가져옴
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
				temp = temp->getNext_Name(); //name에 대해서 다음값
			}
			pTemp = pTemp->getNext();
			std::cout << '\n';
		}
		std::cout << '\n';
		std::cout << "=========================================================================" << '\n';
	}

	template<>
	void print<char*>() { // char* 일때 값들을 출력하는매소드
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
	void print<int>() {// int형 일때 값들을 출력하는매소드
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
	void delete_data() { // 데이터의 값을 동적할당하는 매소드
		Data_1D<T>* pTemp = pHead;
		while (pTemp) {
			delete pTemp->getData();
			pTemp = pTemp->getNext();
		}
	}

	template<typename T>
	void Remove_data() { // data의 값을 동적할당하는 매소드
		Data_1D<T>* pTemp = pHead;
		while (pTemp) {
			pHead = pHead->getNext();
			delete pTemp;
			pTemp = pHead;
		}
	}
};
