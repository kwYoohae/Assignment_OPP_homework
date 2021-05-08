#include <iostream>
#include "queue.h"
#include <crtdbg.h>
using namespace std;

queue::queue() {
	data = 0; //데이터 초기화
	pHead = nullptr; //head 초기화
	pTail = nullptr; // tail 초기화
}

queue::~queue() { // queue소멸자
	node* pTemp; //pTemp라는 포인터 생성
	while (pHead) { //head가 nullptr을 만날 때 까지
		pTemp = pHead; //pTemp는 head를 가리킴
		pHead = pHead->getNext(); //head는 next값으로 이동
		delete pTemp; //동적할당 해제
	}
	_CrtDumpMemoryLeaks();
}

void queue::Enqueue(int number , int *count) {
	node* pTemp = new node; //새로운 노드 생성
	if (*count >= 5) // 큐의 값이 5보다 커질 때
		cout << "Error 300" << endl; //에러메시지 출력
	else if (*count == 0) { //처음 생성할 때
		pTemp->setData(number); // 노드에 데이터값 넣기
		pHead = pTemp; // 헤드값 넣기
		pTail = pTemp; // tail값 넣기
		pTemp->setNext(nullptr); //아무값이 없으므로 nullptr
		pTemp->setPrev(nullptr); //아무값이 없으므로 nullptr
		(*count)++; //생성한 만큼 count 추가
	}
	else {
		pTemp->setPrev(pTail); // 제일 마지막 값이 새로 생겼으므로 pTail이 이전 마지막 값이므로 이전 값으로 저장
		pTail->setNext(pTemp); // pTail이 제일 마지막이 아니므로 pTemp를 다음으로 가리킴
		pTemp->setNext(nullptr); // pTemp는 마지막 값이므로 nullptr을 사용
		pTemp->setData(number); // data값을 저장
		pTail = pTemp; // pTail의 값 변경
		(*count)++; // count증가
	}
}

void queue::Print_Queue() { //큐를 출력하는 매소드
	node* pWork = pHead; // pWork는 pHead를 가리킴
	while (pWork) { //pWork가 nullptr을 가리킬 때 까지 반복
		cout << pWork->getData(); //pWork의 데이터 출력
		cout.width(5); // 띄어쓰기
		pWork = pWork->getNext(); // pWork는 Next값으로 변경
	}
	cout << '\n';
}

void queue::Dequeue(int number, int *count, bst* Bst) { // queue를 삭제하는 매소드
	node* pTemp; //pTemp값을 선언
	for (int i = 0; i < number; i++) {
		if (*count == 1) { // 큐의 값이 하나만 남아서 queue의 헤드를 삭제 할 때
			pTemp = pHead; // pHead를 가리킴( 큐에 head밖에 남지 않아서)
			Bst->Insert(pTemp); //삭제한 값을 BST에 삽입
			pHead = nullptr; // 헤드를 삭제 할것이기 때문에 헤드 초기화
			pTail = nullptr; // 테일도 초기화
			delete pTemp; // 값 삭제
		}
		else {
			pTemp = pHead; // pHead의 값을 가져옴
			Bst->Insert(pTemp); // 삭제할 값을 BST에 저장
			pHead = pHead->getNext(); // pHead의 다음 값을 pHead로 바꿈(삭제할것이기 때문에)
			pHead->setPrev(pHead); // pHead의 이전값은 자신이 됨
			delete pTemp; // 값 삭제
		}
		(*count)--; // 하나 삭제 할 때마다 큐 값이 줄어듬 count--
	}
}

void queue::All_Dequeue(int *count, bst *Bst) { //모든 큐값 삭제하는 매소드
	node* pTemp; // pTemp포인터 선언
	for (int i = 0; *count > i; i++) {
		if (i == *count - 1) { // 큐가 하나 남았을 때
			pTemp = pHead; // pTemp는 head를 가리킴
			Bst->Insert(pTemp); // BST에 삭제할 값 넣어줌
			pHead = nullptr; // 큐에 아무것도 없기 때문에 head초기화
			pTail = nullptr; // 큐에 아무것도 없기 때문에 tail초기화
			delete pTemp; // 값 메모리 헤제
		}
		else {
			pTemp = pHead; // pTemp는 헤드를 가리킴
			Bst->Insert(pTemp); // 삭제할 값을 BST에 INSERT
			pHead = pHead->getNext(); // pHead는 다음 값을 가짐
			pHead->setPrev(pHead); // pHead의 이전값은 삭제되서 없으므로 자기 자신을 가리킴
			delete pTemp; // 값 메모리 해제
		}
	}
	*count = 0; // 모든 큐값을 삭제함으로 count = 0
}