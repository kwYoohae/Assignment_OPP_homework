#include <iostream>
#include "cafe.h"
#include <crtdbg.h>

using namespace std;

cafe::cafe() {
	pHead = nullptr;
	pRoot = nullptr;
}

cafe::~cafe() {
	Remove_Tree(pRoot);
	pRoot = nullptr;
	menu_node* pTemp;
	while (pHead) {
		pTemp = pHead;
		pHead = pHead->getNext();
		delete pTemp;
	}
	_CrtDumpMemoryLeaks();
}

void cafe::Insert(int price, char* Name) {
	bst_node* pBst = new bst_node;
	menu_node* pMenu = new menu_node;
	bool is_same = false;
	pBst->setNode(pMenu);
	if (!pRoot) {
		pRoot = pBst;
		pBst->setNode(pMenu);
		pHead = pMenu;
		pMenu->setName(Name);
		pMenu->setPrice(price);
	}
	else {
		bst_node* pTemp_bst = pRoot;
		while (pTemp_bst) {
			if (Compare(Name, pTemp_bst->getNode()->getName()) == 0) {
				is_same = true;
				delete pBst;
				break;
			}
			else if (Compare(Name, pTemp_bst->getNode()->getName()) == 1) {
				if (pTemp_bst->getRight() == nullptr) {
					pTemp_bst->setRight(pBst);
					break;
				}
				else {
					pTemp_bst = pTemp_bst->getRight();
				}
			}
			else if (Compare(Name, pTemp_bst->getNode()->getName()) == -1) {
				if (pTemp_bst->getLeft() == nullptr) {
					pTemp_bst->setLeft(pBst);
					break;
				}
				else {
					pTemp_bst = pTemp_bst->getLeft();
				}
			}
		}
		if (is_same) {
			cout << "중복된 문자를 입력하셨습니다" << endl;
			delete pMenu;
		}
		else {
			menu_node* pTemp_menu = pHead;
			while (pTemp_menu) {
				if (pTemp_menu->getPrice() < price) {
					if (pTemp_menu->getNext() == nullptr) {
						pMenu->setPrev(pTemp_menu);
						pMenu->getPrev()->setNext(pMenu);
						pMenu->setName(Name);
						pMenu->setPrice(price);
						break;
					}
					else
						pTemp_menu = pTemp_menu->getNext();
				}
				else if (pTemp_menu->getPrice() > price) {
					if (pTemp_menu == pHead) {
						pMenu->setNext(pTemp_menu);
						pMenu->getNext()->setPrev(pMenu);
						pMenu->setName(Name);
						pMenu->setPrice(price);
						pHead = pMenu;
					}
					else {
						pMenu->setNext(pTemp_menu);
						pMenu->setPrev(pTemp_menu->getPrev());
						pMenu->getPrev()->setNext(pMenu);
						pMenu->getNext()->setPrev(pMenu);
						pMenu->setName(Name);
						pMenu->setPrice(price);
					}
					break;
				}
				else {
					if (Compare(Name, pTemp_menu->getName()) == -1) {
						if (pTemp_menu == pHead) {
							pMenu->setNext(pTemp_menu);
							pMenu->getNext()->setPrev(pMenu);
							pMenu->setName(Name);
							pMenu->setPrice(price);
							pHead = pMenu;
						}
						else {
							pMenu->setNext(pTemp_menu);
							pMenu->setPrev(pTemp_menu->getPrev());
							pMenu->getPrev()->setNext(pMenu);
							pMenu->getNext()->setPrev(pMenu);
							pMenu->setName(Name);
							pMenu->setPrice(price);
						}
						break;
					}
					else if (Compare(Name, pTemp_menu->getName()) == 1) {
						if (pTemp_menu->getNext() == nullptr) {
							pMenu->setPrev(pTemp_menu);
							pMenu->getPrev()->setNext(pMenu);
							pMenu->setName(Name);
							pMenu->setPrice(price);
							break;
						}
						else {
							pTemp_menu = pTemp_menu->getNext();
						}
					}
					else if (Compare(Name, pTemp_menu->getName()) == 0) {
						delete pMenu;
						break;
					}
				}
			}

		}
	}
}

void cafe::setHead(menu_node* pTemp) {
	pHead = pTemp;
}

void cafe::setRoot(bst_node* pTemp) {
	pRoot = pTemp;
}


menu_node* cafe::getHead() {
	return pHead;
}


bst_node* cafe::getRoot() {
	return pRoot;
}

int cafe::Compare(char* Insert_Name, char* Name) {
	char *Insert_temp = new char[strlen(Insert_Name) + 1];
	char *Name_temp = new char[strlen(Name) + 1];
	int res = 0;
	for (int i = 0; i <= strlen(Insert_Name); i++) {
		if (Insert_Name[i] >= 'A' && Insert_Name[i] <= 'Z') {
			Insert_temp[i] = Insert_Name[i] + ('a' - 'A');
		}
		else
			Insert_temp[i] = Insert_Name[i];
	}
	for (int i = 0; i <= strlen(Name); i++) {
		if (Name[i] >= 'A' && Name[i] <= 'Z') {
			Name_temp[i] = Name[i] + ('a' - 'A');
		}
		else
			Name_temp[i] = Name[i];
	}
	res = strcmp(Insert_temp, Name_temp);
	delete[] Name_temp;
	delete[] Insert_temp;
	return res;
}

void cafe::Print_price() {
	menu_node* pTemp = pHead;
	while (pTemp) {
		cout << pTemp->getName();
		cout.width(10);
		cout << pTemp->getPrice() << endl;
		pTemp = pTemp->getNext();
	}
}

void cafe::Print_menu(bst_node* pTemp) {
	if (pTemp) {
		Print_menu(pTemp->getLeft());
		cout << pTemp->getNode()->getName();
		cout.width(10);
		cout << pTemp->getNode()->getPrice() << endl;
		Print_menu(pTemp->getRight());
	}
}

int cafe::SEARCH(char* Name) {
	menu_node* pTemp = pHead;
	int price = -1;
	while (pTemp) {
		if (strcmp(Name, pTemp->getName()) == 0) {
			price = pTemp->getPrice();
			break;
		}
		else
			pTemp = pTemp->getNext();
	}
	return price;
}

bool cafe::Delete_node(char* name) {
	bst_node* pBst = pRoot;
	bst_node* pParent = pRoot;
	menu_node* pMenu = pHead;
	bool is_search = false;
	while (pBst) {
		if (strcmp(name, pBst->getNode()->getName()) == 0) {
			is_search = true;
			if (pParent->getLeft() == pBst) {
				if (pBst->getLeft() == nullptr && pBst->getRight() == nullptr) {
					pParent->setLeft(nullptr);
				}
				else if (pBst->getLeft() == nullptr) {
					pParent->setLeft(pBst->getRight());
				}
				else if (pBst->getRight() == nullptr) {
					pParent->setLeft(pBst->getLeft());
					
				}
				else {
					bst_node* pTemp = pBst->getRight();
					bst_node* pTemp_Parent = pBst;
					while (pTemp->getRight()) {
						pTemp_Parent = pTemp;
						pTemp = pTemp->getRight();
					}
					pParent->setLeft(pTemp);
					pTemp_Parent->setRight(pTemp->getLeft());
					pTemp->setLeft(pBst->getLeft());
					pTemp->setRight(pBst->getRight());
				}
				delete pBst;
			}
			else if (pParent->getRight() == pBst) {
				if (pBst->getLeft() == nullptr && pBst->getRight() == nullptr) {
					pParent->setRight(nullptr);
				}
				else if (pBst->getLeft() == nullptr) {
					pParent->setRight(pBst->getRight());
				}
				else if (pBst->getRight() == nullptr) {
					pParent->setRight(pBst->getLeft());

				}
				else {
					bst_node* pTemp = pBst->getRight();
					bst_node* pTemp_Parent = pBst;
					while (pTemp->getRight()) {
						pTemp_Parent = pTemp;
						pTemp = pTemp->getRight();
					}
					pParent->setRight(pTemp);
					pTemp_Parent->setRight(pTemp->getLeft());
					pTemp->setLeft(pBst->getLeft());
					pTemp->setRight(pBst->getRight());
				}
				delete pBst;
			}
			else {
				if (pBst->getLeft() == nullptr && pBst->getRight() == nullptr) {
					pRoot = nullptr;
				}
				else if (pBst->getLeft() == nullptr) {
					pRoot = pBst->getRight();
				}
				else if (pBst->getRight() == nullptr) {
					pRoot = pBst->getLeft();
				}
				else {
					bst_node* pTemp = pBst->getLeft();
					bst_node* pTemp_Parent = pBst;
					while (pTemp->getRight()) {
						pTemp_Parent = pTemp;
						pTemp = pTemp->getRight();
					}
					if (pTemp == pBst->getLeft()) {
						pTemp->setRight(pBst->getRight());
						pRoot = pTemp;
					}
					else {
						pTemp_Parent->setRight(pTemp->getLeft());
						pTemp->setLeft(pBst->getLeft());
						pTemp->setRight(pBst->getRight());
						pRoot = pTemp;
					}
				}
				delete pBst;
			}
			break;
		}
		else if (strcmp(name, pBst->getNode()->getName()) == 1) {
			pParent = pBst;
			pBst = pBst->getRight();
		}
		else if (strcmp(name, pBst->getNode()->getName()) == -1) {
			pParent = pBst;
			pBst = pBst->getLeft();
		}
	}
	while (pMenu) {
		if (strcmp(name, pMenu->getName()) == 0) {
			if (pMenu == pHead) {
				if (pMenu->getNext() != nullptr) {
					pMenu->getNext()->setPrev(nullptr);
				}
				pHead = pMenu->getNext();
			}
			else {
				pMenu->getPrev()->setNext(pMenu->getNext());
				if (pMenu->getNext() != nullptr) {
					pMenu->getNext()->setPrev(pMenu->getPrev());
				}
			}
			delete pMenu;
			break;
		}
		else {
			pMenu = pMenu->getNext();
		}
	}
	return is_search;
}

void cafe::Remove_Tree(bst_node* pTemp) {
	if (pTemp) {
		Remove_Tree(pTemp->getLeft());
		Remove_Tree(pTemp->getRight());
		delete pTemp;
	}
}