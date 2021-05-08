#include <iostream>
#include "BST.h"
#include <crtdbg.h>

bst::bst() {
	count = 0; //count값 초기화
	data = 0; //data값 초기화
	root = nullptr; //root값 초기화
}

bst::~bst() {
	Remove_Tree(root); // delete하기 위한 매소드 호출
	root = nullptr; //root의 값을 nullptr로 초기화
	_CrtDumpMemoryLeaks();
}

void bst::Insert(node* pNode) { //이진트리에 값 삽입하는 매소드
	bool prev = false; //왼쪽으로 값을 저장해야하는지 오른쪽에 값을 저장해야하는지 확인하는 변수
	node* pTemp = new node; //새로운 노드 생성
	pTemp->setData(pNode->getData()); // 새로운 노드에 데이터값을 저장
	if (count == 0) { //처음 생성하는 노드일 때
		root = pTemp; //root는 처음 생성하는 노드
		pTemp->setNext(nullptr); //값이 없으므로 nullptr
		pTemp->setPrev(nullptr); //값이 없으므로 nullptr
		count++; //생성하였으므로 count++
	}
	else{
		node* pParent = root; //부모 노드 
		node* pWork = root; // 자식 노드
		while (pWork) { //자식노드가 nullptr일 때까지 반복문
			pParent = pWork; // 부모노드 = 자식노드의 변경되기 이전의 값을 가짐
			if (pWork->getData() > pTemp->getData()) { //입력한 값이 node의 값보다 작을경우
				pWork = pWork->getPrev(); //왼쪽을 찾아봄
				prev = true; // 왼쪽으로 갔기 때문에 true로 확인
			}
			else if (pWork->getData() < pTemp->getData()) { //입력한 값이 node의 값보다 클 경우
				pWork = pWork->getNext(); // 오른쪽을 확인
				prev = false; // 오른쪽으로 갔기 때문에 false
			}
			else {
				delete pTemp; //값이 중복일경우에는 무시 해야함으로 pTemp를 제거
				return; // 반환
			}
		}
		if (prev) { //왼쪽일때
			pParent->setPrev(pTemp); //부모노드의 왼쪽에 저장
		}
		else {
			pParent->setNext(pTemp); //	부모노드의 오른쪽에 저장
		}
	}
}

void bst::Print_Post(node *pNode) { //후위 순회로 출력하는 방식(재귀함수)
	if (pNode) { //pNode의 값이 nullptr이 아닐 때
		Print_Post(pNode->getPrev()); // 왼쪽으로 최대한 간 뒤
		Print_Post(pNode->getNext()); // 오른쪽으로 최대한 간 후
		std::cout << pNode->getData(); // 값을 출력
		std::cout.width(5); //간격두기
	}
}

void bst::setRoot(node* pNode) { // root의 값을 변경하는 매소드
	root = pNode;
}
void bst::setData(int number) { // data의 값을 변경하는 매소드
	data = number;
}
int bst::getData() { //data의 값을 반환하는 매소드
	return data;
}
node* bst::getRoot() { //root의 값을 반환하는 매소드
	return root;
}

bool bst::is_Empty() { // bst가 비어있는지 확인하는 매소드
	if (getRoot() == NULL) // root의 값이 null일때 
		return true; //true를 반환
	else
		return false; //root의 값이 있을 때 false를 반환
}

int bst::Search(int number) { // bst의 값을 찾는 매소드
	node* pNode = root; // pNode라는 포인터가 root를 가리킴
	while (pNode) { //pNode가 nullptr을 만날 때 까지 반복
		if (pNode->getData() == number) // 같은 data 값이 있는지 확인
			return pNode->getData(); // data값을 반환
		else if (pNode->getData() > number) { // 입력한 데이터 값이 비교하는 값보다 작을 경우 왼쪽 트리 탐색
			pNode = pNode->getPrev();
		}
 		else if (pNode->getData() < number) { // 입력한 데이터 값이 비교하는 값보다 클 경우 오른쪽 트리 탐색
			pNode = pNode->getNext();
		}
	}
	return -1; // 트리를 조건대로 찾아보고 없는 경우 -1 반환
}

void bst::Print_Pre(node* pNode) { //전위 순회로 값을 출력
	if (pNode) { //pNode가 nullptr이 아아닐 경우에만
		std::cout << pNode->getData(); //root부터 계속 출력
		std::cout.width(5); // 띄어쓰기
		Print_Pre(pNode->getPrev()); //왼쪽 탐색
		Print_Pre(pNode->getNext()); //오른쪽 탐색
	}
}

void bst::Print_in(node* pNode) { // 중위 순회로 값을 출력
	if (pNode) { //pNode가 nullptr이 아닐 경우에만
		Print_in(pNode->getPrev()); // 최대한 왼쪽으로 출발
		std::cout << pNode->getData(); //값을 출력
		std::cout.width(5); // 띄어쓰기
		Print_in(pNode->getNext()); // 오른쪽 값 탐색
	}
}

void bst::Remove_Tree(node* pTemp) { // tree를 제거하는 매소드
	if (pTemp) { // pTemp의 값이 존재 할때
		Remove_Tree(pTemp->getPrev()); // 가장 왼쪽으로 탐색
		Remove_Tree(pTemp->getNext()); // 오른쪽 탐색
		delete pTemp; //값 할당 해제
	}
}