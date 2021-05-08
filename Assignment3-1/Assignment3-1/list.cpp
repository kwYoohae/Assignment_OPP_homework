#include "list.h"
#include "node.h"
#include <iostream>

using namespace std;

list::list() {
	pHead = nullptr; //pHead값 초기화
	pTail = nullptr; //pTail값 초기화
}
list::~list() {
	node* pTemp; // node의 pTemp포인터 생성
	while (pHead) { // pHead가 null값일 때 까지 반복
		pTemp = pHead; //pTemp가 pHead를 가리킴
		pHead = pHead->getNext(); // pHead는 다음 node값으로 변경
		delete pTemp; // pTemp는 pHead 를 가리킨 값을 삭제
	}
	_CrtDumpMemoryLeaks();
}

void list::Insert(char* str, int count) { //단어를 삽입하는 매소드
	node* pNew = new node; // 새로운 노드 생성
	if (count == 0) { // 처음 생성할 때
		pNew->setData(str); // pNew노드의 데이터 저장
		pHead = pNew; // pHead설정
		pTail = pNew; // pTail설정
		pNew->setPrev(pHead); //pHead의 이전값 설정
		pNew->setNext(nullptr); // 다음 값은 처음이라 없기 때문에 nullptr설정
	}
	else { //처음 노드가 아닐 때
		pNew->setPrev(pTail); //새로운 노드의 이전 값은 마지막값(pTail) 
		pTail->setNext(pNew); //pTail은 뒤에 다른 노드가 생성 되었으므로 Next값을 새로 생성된 pNew의 값으로 가리킴
		pNew->setNext(nullptr); // pNew의 뒷값은 없기 때문에 Next값은 nullptr이다
		pNew->setData(str); // pNew노드에 데이터 추가
		pTail = pNew; // pTail의 값은 pNew가 마지막이 되었기 때문에 pNew로 변경
	}
	
}

void list::Print() {
	node* pWork = pHead; //pWork는 pHead를 가리킴
	while (pWork) { // pWork가 마지막 단어의 Next를 가리킬 때 까지 반복문
		cout << pWork->getData() << "->"; //node의 단어를 입력
		pWork = pWork->getNext(); // pWork는 다음 노드로 변경
	}
	cout << '\n';
}

bool list::Search_equal(char* str) { //같은 값이 있는지 확인하는 매소드
	node* pWork = pHead; //pHead부터 검사하기 위해서 pWork라는 노드를 생성해서 pHead를 가리킴
	char temp_node[20]; // node의 data값을 소문자로 변경하기 위한 변수
	char temp_insert[20];  // 방금 입력한 data값을 소문자로 변경하기 위한 변수
	memset(temp_node, NULL, 20); //NULL로 초기화
	memset(temp_insert, NULL, 20); // NULL로 초기화
	for (int i = 0; i <= strlen(str); i++) { //str의 값을 복사하는 for문
		if (str[i] >= 'A' && str[i] <= 'Z') { //만약 대문자면 +32로해서 소문자로 바꾸어서 temp_insert에 값을 저장
			temp_insert[i] = str[i] + 32;
		 }
		else {
			temp_insert[i] = str[i]; //특수문자거나 소문자인 값들은 그냥 저장
		}
	}
	while (pWork) { // pWork가 마지막 노드로가서 null이 될때 까지 반복
		for (int i = 0; i <= strlen(pWork->getData()); i++) { // 현재 pWork가 가리키고 있는 데이터 값을 소문자로 다시 복사하기 위한 for문
			if (pWork->getData()[i] >= 'A' && pWork->getData()[i] <= 'Z') { // 대문자일 경우 +32를해서 temp_node에 저장
				temp_node[i] = pWork->getData()[i] + 32;
			}
			else {
				temp_node[i] = pWork->getData()[i]; //아닐경우 그냥저장
			}
		}
		if (strcmp(temp_node, temp_insert) == 0) //strcmp를 사용해서 값이 같은지 비교
			return false; // 같은값이 있으면 false를 반환
		pWork = pWork->getNext(); // pWork는 다음 Next값으로 이동
		memset(temp_node, NULL, 20); // temp_node를 null로 다시 초기화
	}
	return true; // 만약 걸리는게 없어서 false를 반환하지 않았다면 true 를 반환
}

bool list::backward_word(char * str) { //뒤에 단어의 끝에 글자가 입력한 글자와 이어지는지 확인
	int len = strlen(pTail->getData()); // linked list의 끝부분(tail)의 단어를 불러옴
	bool upper = false; //pTail기준 대문자인 경우
	bool lower = false; //pTail기준 소문자인경우
	if ((pTail->getData()[len - 1] >= 'a' && pTail->getData()[len - 1] <= 'z') || (pTail->getData()[len - 1] >= 'A' && pTail->getData()[len - 1] <= 'Z')) { //끝나는 글자가 영문자일 때만
		if (str[0] >= 'a' && str[0] <= 'z') { //입력단어가 소문자일 경우
			if (pTail->getData()[len - 1] == str[0]) { // 끝 단어의 마지막 단어와 같은지 확인
				lower = true; //pTail이 소문자일 때 같으면 true
			}
			else if(pTail->getData()[len - 1] == str[0] - 32){
				upper = true; //pTail이 대문자 일때 같으면 true
			}
		}
		else if (str[0] >= 'A' && str[0] <= 'Z') { // 입력단어가 대문자일 때
			if (pTail->getData()[len - 1] == str[0] + 32) { // pTail이 소문자라 가정하고 +32를 해주어 같으면
				upper = true; //pTail이 대문자 일때 같으면 true
			}
			else if (pTail->getData()[len - 1] == str[0]) { // pTail이 대문자라 가정하고 같으면 
				lower = true;//pTail이 소문자 일 때 같으면 true
			}
		}
		else {
			return false; // (소문소문/대문소문/소문대문/대문대문)의 경우를 만족시키지 못할 때 false를 return
		}
	}
	else {
		if (pTail->getData()[len - 1] == str[0]) { // 끝나는 문자가 특수문자일 경우 같은 때 true 아니면 false를 리턴
			return true;
		}
		return false;
	}
	if (upper == true || lower == true)//대소문자중 하나라도 같은게 있었다면 true를 반환 아니면 false를 반환
		return true;
	else
		return false;
}