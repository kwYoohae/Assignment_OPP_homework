#include <iostream>
#include "cafe.h"
#include <crtdbg.h>

using namespace std;

cafe::cafe() {
	pHead = nullptr; //초기화
	pRoot = nullptr; // 초기화
}

cafe::~cafe() {
	Remove_Tree(pRoot); //BST노트 삭제하는 매소드 호출
	pRoot = nullptr; // pRoot초기화
	menu_node* pTemp;
	while (pHead) { // pHead가 nullptr일 때까지 반복
		pTemp = pHead; // pHead를 pTemp가 가리킴
		pHead = pHead->getNext(); // pHead는 다음값을 가리킴
		delete pTemp; // pTemp를 동적할당 해제
	}
	_CrtDumpMemoryLeaks();
}

void cafe::Insert(int price, char* Name) {
	bst_node* pBst = new bst_node; // BST노드생성
	menu_node* pMenu = new menu_node; // 메뉴노드생성
	bool is_same = false;  
	pBst->setNode(pMenu); // Bst의 메뉴 노드 설정
	if (!pRoot) { // root가 비어있을 때
		pRoot = pBst; // 루트를 설정
		pBst->setNode(pMenu); // pMenu로 노드 설정
		pHead = pMenu; // pHead설정
		pMenu->setName(Name); // 메뉴이름설정
		pMenu->setPrice(price); // 메뉴가격설정
	}
	else { // root가 있을 때
		bst_node* pTemp_bst = pRoot;
		while (pTemp_bst) { // bst를 탐색하러다니는 값이 nullptr일 때 까지
			if (Compare(Name, pTemp_bst->getNode()->getName()) == 0) { // 같은이름의 노드가 있을 때
				is_same = true; // 같다는 변수 true로 설정
				delete pBst; // pBst동적할당해제
				break;
			}
			else if (Compare(Name, pTemp_bst->getNode()->getName()) == 1) { // 비교하는노드가 입력받은 노드 보다 클 때
				if (pTemp_bst->getRight() == nullptr) { // 오른쪽이 비어있으면 오른족에 노드저장
					pTemp_bst->setRight(pBst); 
					break; // 반복문 종료
				}
				else { //비어있지 않을 때는 크기 때문에 오른쪽으로 이동
					pTemp_bst = pTemp_bst->getRight();
				}
			}
			else if (Compare(Name, pTemp_bst->getNode()->getName()) == -1) { // 작을경우에는 왼쪽으로 이동
				if (pTemp_bst->getLeft() == nullptr) { // 왼쪽으로 이동하는데 비어있을 경우 그곳에 노드저장
					pTemp_bst->setLeft(pBst);
					break;
				}
				else {
					pTemp_bst = pTemp_bst->getLeft(); // 비어있지 않을 경우 그냥 왼쪽으로 이동
				}
			}
		}
		if (is_same) { // 중복된 문자일 경우
			cout << Name <<"은 중복된 문자입니다." << endl;
			delete pMenu; // 생성한 노드 삭제
		} 
		else {
			menu_node* pTemp_menu = pHead; // 메뉴의 헤드부분을 가리킴
			while (pTemp_menu) { // pTemp_munu가 nullptr이 될때까지 
				if (pTemp_menu->getPrice() < price) { // price가 작으면
					if (pTemp_menu->getNext() == nullptr) { // pTemp_menu의 다음 노드가 마지막 노드일 경우
						pMenu->setPrev(pTemp_menu); // 메뉴의 노드의 전이 새로만든 노드
						pMenu->getPrev()->setNext(pMenu); // 메뉴의 이전노드의 다음노드는 새로만든노드
						pMenu->setName(Name); // 이름설정
						pMenu->setPrice(price); //가격설정
						break; // 반복문 종료
					}
					else
						pTemp_menu = pTemp_menu->getNext(); // pTemp_menu는 다음값을 가리킴
				}
				else if (pTemp_menu->getPrice() > price) { // pTemp_menu의 가격이 클경우
					if (pTemp_menu == pHead) { // 만약 pHead의 값 이전에 들어가야 하면
						pMenu->setNext(pTemp_menu); // 그 다음 값을 pTemp_menu로함
						pMenu->getNext()->setPrev(pMenu); // 기존 해드값의 이전값을 새로생성한노드로함
						pMenu->setName(Name); // 이름을 설정
						pMenu->setPrice(price); // 가격을 설정
						pHead = pMenu; // pHead를 새로생성한 노드로 변경
					}
					else { // pHead가 아닌 일반값일 때
						pMenu->setNext(pTemp_menu); // 새로운 노드는 pTemp_menu를 다음으로 가리킴
						pMenu->setPrev(pTemp_menu->getPrev()); // pTemp_menu의 이전값을 pMenu가 가리킴
						pMenu->getPrev()->setNext(pMenu); // 메뉴의 이전값의 다음값을 새로운노드로 가리킴
						pMenu->getNext()->setPrev(pMenu); // pMenu의 다음값의 이전값을 pMenu로가리킴
						pMenu->setName(Name); // 이름을 설정
						pMenu->setPrice(price); // 가격을 설정
					}
					break; // 반복문종료
				}
				else { // 가격이 같을때는 이름으로 비교후 정렬
					if (Compare(Name, pTemp_menu->getName()) == -1) { // 이름이 비교하는 값보다 앞에 위치해야할 때
						if (pTemp_menu == pHead) { // 만약 pHead일때는 새로운 노드를 pHead로 설정하고 next,prev값을 설정해줌
							pMenu->setNext(pTemp_menu);
							pMenu->getNext()->setPrev(pMenu);
							pMenu->setName(Name);
							pMenu->setPrice(price);
							pHead = pMenu; // 새로운 노드를 해드로 변경
						} 
						else { // 해드가 아닐 경우는 일반적으로 새로운노드의 뒤의값과 앞에값의 next prev를 명확히 설정
							pMenu->setNext(pTemp_menu);
							pMenu->setPrev(pTemp_menu->getPrev());
							pMenu->getPrev()->setNext(pMenu);
							pMenu->getNext()->setPrev(pMenu);
							pMenu->setName(Name);
							pMenu->setPrice(price);
						}
						break; // 반복문 종료
					}
					else if (Compare(Name, pTemp_menu->getName()) == 1) { // 더커서(뒤로가야할 때) 다음값으로 이동할 때
						if (pTemp_menu->getNext() == nullptr) { // 만약 마지막값이어서 더 뒤로 갈 수 없는 경우 Next와 Prev설정
							pMenu->setPrev(pTemp_menu);
							pMenu->getPrev()->setNext(pMenu);
							pMenu->setName(Name);
							pMenu->setPrice(price);
							break; //반복문 종료
						}
						else { // 다음값으로 더 넘어가도 될경우 다음값으로 이동
							pTemp_menu = pTemp_menu->getNext();
						}
					}
					else if (Compare(Name, pTemp_menu->getName()) == 0) { // 같은값일 경우 동일한값 존재 x
						delete pMenu; // pMenu의 노드 삭제
						break; // 반복문 종료
					}
				}
			}

		}
	}
}

void cafe::setHead(menu_node* pTemp) { //값을 변경해주는 매소드
	pHead = pTemp;
}

void cafe::setRoot(bst_node* pTemp) {//값을 변경해주는 매소드
	pRoot = pTemp;
}


menu_node* cafe::getHead() {//값을 반환해주는 매소드
	return pHead;
}


bst_node* cafe::getRoot() { //값을 반환해주는 매소드
	return pRoot;
}

int cafe::Compare(char* Insert_Name, char* Name) { // 메뉴의 글자를 사전식으로 비교해서 누가 더큰지 반환하는 매소드
	char *Insert_temp = new char[strlen(Insert_Name) + 1];
	char *Name_temp = new char[strlen(Name) + 1];
	int res = 0;
	for (int i = 0; i <= strlen(Insert_Name); i++) { // 메뉴의 값을 모두 소문자로 복사
		if (Insert_Name[i] >= 'A' && Insert_Name[i] <= 'Z') {
			Insert_temp[i] = Insert_Name[i] + ('a' - 'A');
		}
		else
			Insert_temp[i] = Insert_Name[i];
	}
	for (int i = 0; i <= strlen(Name); i++) { // 메뉴의 값을 모두 소문자로 복사
		if (Name[i] >= 'A' && Name[i] <= 'Z') {
			Name_temp[i] = Name[i] + ('a' - 'A');
		}
		else
			Name_temp[i] = Name[i];
	} 
	res = strcmp(Insert_temp, Name_temp); // strcmp로 값을 비교
	delete[] Name_temp; // 동적할당해제
	delete[] Insert_temp; // 동적할당해제
	return res; // 비교한 값 반환
}

void cafe::Print_price() { // 가격순으로 출력하는 매소드
	menu_node* pTemp = pHead;
	while (pTemp) { // pTemp가 nullptr일 때 까지
		cout << pTemp->getName();
		cout.width(10);
		cout << pTemp->getPrice() << endl;
		pTemp = pTemp->getNext();
	}
}

void cafe::Print_menu(bst_node* pTemp) { // menu순으로 출력하는 매소드
	if (pTemp) { // Bst를 이용해서 출력
		Print_menu(pTemp->getLeft()); // 제일 왼쪽으로 이동(재귀함수사용)
		cout << pTemp->getNode()->getName(); // 이름 모두 출력
		cout.width(10);
		cout << pTemp->getNode()->getPrice() << endl; 
		Print_menu(pTemp->getRight()); // 오른쪽이 있는경우 제일그 노두에서 제일오른쪽으로 이동(재귀함수)
	}
}
 
int cafe::SEARCH(char* Name) { //값을 찾는 매소드
	menu_node* pTemp = pHead;
	int price = -1;
	while (pTemp) { // pTemp가 nullptr일 때까지
		if (strcmp(Name, pTemp->getName()) == 0) { // 메뉴의 이름과 비교하는값이 같은경우
			price = pTemp->getPrice(); // 그메뉴의 price를 반환
			break;
		}
		else
			pTemp = pTemp->getNext(); // 값이 아닌경우 다음값으로
	}
	return price; // 가격을 반환
}

bool cafe::Delete_node(char* name) { // 노드를 삭제해주는 매소드
	bst_node* pBst = pRoot; // pRoot를 가리키는 노드
	bst_node* pParent = pRoot; // bst를 탐새하는 포인터의 parent 노드
	menu_node* pMenu = pHead; //pHead를 가리키는 노드 
	bool is_search = false;
	while (pBst) { // pBst가 nullptr일 떄 까지 반복
		if (Compare(name, pBst->getNode()->getName()) == 0) { // 입력한이름과 노드가 가지고 있는 이름이 같을 때
			is_search = true; // 같은경우라고 bool문 설정
			if (pParent->getLeft() == pBst) { // 부모노드에서 왼쪽이 내가 찾는 노드있지 확인
				if (pBst->getLeft() == nullptr && pBst->getRight() == nullptr) { // 찾는 노드가 자식노드를 가지지 않을 경우
					pParent->setLeft(nullptr); // 왼쪽에 저저아
				}
				else if (pBst->getLeft() == nullptr) { // 왼쪽만 비어있을 경우
					pParent->setLeft(pBst->getRight()); // 부모노드의 왼쪽에 자식노드의 오른쪽을 붙임
				}
				else if (pBst->getRight() == nullptr) { // pBst의 오른쪽이 비어있을 경우
					pParent->setLeft(pBst->getLeft()); //부모노드의 왼쪽에 자식노드의 왼쪽을 붙임
					
				}
				else { // 삭제할 노드의 자식노드가 둘다 있을 때
					bst_node* pTemp = pBst->getRight(); // pTemp는 pBst의 오른쪽을 가리킴
					bst_node* pTemp_Parent = pBst; // pTemp의 부모노트는 pBst를 가리킴
					while (pTemp->getRight()) {
						pTemp_Parent = pTemp;  // pTemp의 부모는 pTemp를 가리킴
						pTemp = pTemp->getRight(); // pTemp의 계속 오른쪽으로
					}
					pParent->setLeft(pTemp); // 부모노드는 pTemp를 왼쪽으로 가리킴
					pTemp_Parent->setRight(pTemp->getLeft()); //pTemp의 부모노드의 오른쪽은 pTemp의 왼쪽을 붙임
					pTemp->setLeft(pBst->getLeft()); // pTemp의 왼쪽은 원래 pBst의 왼쪽을 설정
					pTemp->setRight(pBst->getRight()); // pTemp의 오른쪽은 원래 pBst의 오른쪽을 설정
				}
				delete pBst; // pBst노드 삭제
			}
			else if (pParent->getRight() == pBst) { // 부모노드의 오른쪽이 삭제할 노드일 경우
				if (pBst->getLeft() == nullptr && pBst->getRight() == nullptr) { // 삭제할노드가 자식노드를 가지지 않는경우
					pParent->setRight(nullptr); // 부모노드의 오른쪽을 땜
				}
				else if (pBst->getLeft() == nullptr) { //삭제할 노드의 왼쪽만 비었을 때
					pParent->setRight(pBst->getRight()); // 부모노드의 오른쪽은 삭제할 노드의 오른쪽을 붙임
				}
				else if (pBst->getRight() == nullptr) { // 삭제할 노드의 오른쪽만 비었을 때
					pParent->setRight(pBst->getLeft()); // 부모노드의 오른쪽을 삭제할 노드의 왼쪽을 붙임

				}
				else { // 자식노드가 둘다 있을 때
					bst_node* pTemp = pBst->getRight(); // pTemp는 삭제할 노드의 오른쪽을 가리킴
					bst_node* pTemp_Parent = pBst; // pTemp의부모는 삭제할 노드름 가리킴
					while (pTemp->getRight()) { // pTemp의 오른쪽이 비어있을 때까지 반복
						pTemp_Parent = pTemp; // pTemp의 부모노드는 pTmep로
						pTemp = pTemp->getRight(); // pTemp는 계속 오른쪽으로
					}
					pParent->setRight(pTemp); // 삭제할 노드의 부모노드는 pTemp를 오른쪽에 붙임
					pTemp_Parent->setRight(pTemp->getLeft()); // pTemp의 부모노드의 오른쪽은 pTemp의 왼쪽을 붙임
					pTemp->setLeft(pBst->getLeft()); // pTemp의 왼쪽은 삭제할 노드의 오른쪽을 붙임
					pTemp->setRight(pBst->getRight()); // pTemp의 오른쪽은 삭제할 노드의 오른쪽을 붙임
				}
				delete pBst; // pBst노드 삭제
			}
			else { //부모노드의 왼쪽 오른쪽이 아닐경우(즉 pRoot일 경우)
				if (pBst->getLeft() == nullptr && pBst->getRight() == nullptr) { // pRoot가 자식노드가 없을경우
					pRoot = nullptr; // root를 초기화한다.
				}
				else if (pBst->getLeft() == nullptr) { // root가 왼쪽노드만 비어있을 경우
					pRoot = pBst->getRight(); // 오른쪽 노드로 root를 이동한다.
				}
				else if (pBst->getRight() == nullptr) { // root가 오른쪽노드만 비어있을 경우
					pRoot = pBst->getLeft(); // 왼쪽노드로 root를 이동한다.
				}
				else { // root가 둘다 있을 경우
					bst_node* pTemp = pBst->getLeft(); // root의 왼쪽노드의 제일 큰값을 설정해주기 위해서 왼쪽을 설정
					bst_node* pTemp_Parent = pBst; //root의 왼쪽 노드중 가장큰값의 부모노드
					while (pTemp->getRight()) { // pTemp를 root에서 제일 큰값을 찾기위해서 오른쪽으로 보냄
						pTemp_Parent = pTemp; // 부모설정
						pTemp = pTemp->getRight(); // 오른쪽으로
					}
					if (pTemp == pBst->getLeft()) { // pTemp가 삭제할 노드의 왼쪽일경우(root의 자식노드가 왼쪽에 하나일경우)
						pTemp->setRight(pBst->getRight()); // 삭제할 노드의 왼쪽을 pRoot로 바꿈
						pRoot = pTemp;
					}
					else { // pTemp가 삭제할 노드의 가장 큰값으로 간경우(오른쪽으로 한번이라도 간경우)
						pTemp_Parent->setRight(pTemp->getLeft()); // pTemp의 부모의 오른쪽은 pTemp의 왼쪽값을 가짐
						pTemp->setLeft(pBst->getLeft()); // pTemp의 왼쪽은 Root의 왼쪽을가짐
						pTemp->setRight(pBst->getRight()); // pTemp의 오른쪽은 Root의 오른쪽을 가짐
						pRoot = pTemp; // pRoot로 변경
					}
				}
				delete pBst; // pBst노드 삭제
			}
			break; // 반복문 종료
		}
		else if (Compare(name, pBst->getNode()->getName()) == 1) { // 삭제할 노드의 이름과 현재노드의 이름을 비교해서 삭제할 노드의 이름이클때는 오른쪽으로 이동
			pParent = pBst;
			pBst = pBst->getRight();
		}
		else if (Compare(name, pBst->getNode()->getName()) == -1) { // 삭제할 노드의 이름과 현재노드의 이름을 비교해서 작을 경우는 왼쪽으로
			pParent = pBst;
			pBst = pBst->getLeft();
		}
	}
	while (pMenu) { // pMenu에서 노드를 찾고 삭제하기 위한 반복문
		if (strcmp(name, pMenu->getName()) == 0) { // 이름이 같은 노드를 찾았을 때
			if (pMenu == pHead) { // 삭제할 노드가 pHead인 경우
				if (pMenu->getNext() != nullptr) { // 삭제할 노드의 다음노드가 있는 경우
					pMenu->getNext()->setPrev(nullptr); // 삭제할노드의 다음값의 이전값을 삭제
				}
				pHead = pMenu->getNext(); //삭제할값의 다음값을 pHead로 바꿈
			}
			else { // 삭제할 노드가 Head가 아닌경우
				pMenu->getPrev()->setNext(pMenu->getNext()); //메뉴의 이전값은 삭제할노드가 가리키는 다음값을 다음값으로 설정
				if (pMenu->getNext() != nullptr) { // 삭제할값이 Tail이 아닐경우
					pMenu->getNext()->setPrev(pMenu->getPrev()); // 삭제할노드의 다음값의 이전값은 삭제할노드의 이전값으로 설정
				} 
			}
			delete pMenu; //메뉴 노드삭제 
			 break; // 반복문종료
		}
		else {
			pMenu = pMenu->getNext(); // pMenu는 다음 값으로
		}
	}
	return is_search; // 동일한값이여서 수행이 안됬는지 됬는지를 반환
}

void cafe::Remove_Tree(bst_node* pTemp) { // bst를 삭제하는 매소드
	if (pTemp) { 
		Remove_Tree(pTemp->getLeft()); // bst에서 제일 왼쪽으로이동 (재귀함수)
		Remove_Tree(pTemp->getRight()); // bst에서 그중 제일 오른쪽으로이동 (재귀함수)
		delete pTemp; // 동적할당해제
	}
}