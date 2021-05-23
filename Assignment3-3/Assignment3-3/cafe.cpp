#include <iostream>
#include "cafe.h"
#include <crtdbg.h>

using namespace std;

cafe::cafe() {
	pHead = nullptr; //�ʱ�ȭ
	pRoot = nullptr; // �ʱ�ȭ
}

cafe::~cafe() {
	Remove_Tree(pRoot); //BST��Ʈ �����ϴ� �żҵ� ȣ��
	pRoot = nullptr; // pRoot�ʱ�ȭ
	menu_node* pTemp;
	while (pHead) { // pHead�� nullptr�� ������ �ݺ�
		pTemp = pHead; // pHead�� pTemp�� ����Ŵ
		pHead = pHead->getNext(); // pHead�� �������� ����Ŵ
		delete pTemp; // pTemp�� �����Ҵ� ����
	}
	_CrtDumpMemoryLeaks();
}

void cafe::Insert(int price, char* Name) {
	bst_node* pBst = new bst_node; // BST������
	menu_node* pMenu = new menu_node; // �޴�������
	bool is_same = false;  
	pBst->setNode(pMenu); // Bst�� �޴� ��� ����
	if (!pRoot) { // root�� ������� ��
		pRoot = pBst; // ��Ʈ�� ����
		pBst->setNode(pMenu); // pMenu�� ��� ����
		pHead = pMenu; // pHead����
		pMenu->setName(Name); // �޴��̸�����
		pMenu->setPrice(price); // �޴����ݼ���
	}
	else { // root�� ���� ��
		bst_node* pTemp_bst = pRoot;
		while (pTemp_bst) { // bst�� Ž���Ϸ��ٴϴ� ���� nullptr�� �� ����
			if (Compare(Name, pTemp_bst->getNode()->getName()) == 0) { // �����̸��� ��尡 ���� ��
				is_same = true; // ���ٴ� ���� true�� ����
				delete pBst; // pBst�����Ҵ�����
				break;
			}
			else if (Compare(Name, pTemp_bst->getNode()->getName()) == 1) { // ���ϴ³�尡 �Է¹��� ��� ���� Ŭ ��
				if (pTemp_bst->getRight() == nullptr) { // �������� ��������� �������� �������
					pTemp_bst->setRight(pBst); 
					break; // �ݺ��� ����
				}
				else { //������� ���� ���� ũ�� ������ ���������� �̵�
					pTemp_bst = pTemp_bst->getRight();
				}
			}
			else if (Compare(Name, pTemp_bst->getNode()->getName()) == -1) { // ������쿡�� �������� �̵�
				if (pTemp_bst->getLeft() == nullptr) { // �������� �̵��ϴµ� ������� ��� �װ��� �������
					pTemp_bst->setLeft(pBst);
					break;
				}
				else {
					pTemp_bst = pTemp_bst->getLeft(); // ������� ���� ��� �׳� �������� �̵�
				}
			}
		}
		if (is_same) { // �ߺ��� ������ ���
			cout << Name <<"�� �ߺ��� �����Դϴ�." << endl;
			delete pMenu; // ������ ��� ����
		} 
		else {
			menu_node* pTemp_menu = pHead; // �޴��� ���κ��� ����Ŵ
			while (pTemp_menu) { // pTemp_munu�� nullptr�� �ɶ����� 
				if (pTemp_menu->getPrice() < price) { // price�� ������
					if (pTemp_menu->getNext() == nullptr) { // pTemp_menu�� ���� ��尡 ������ ����� ���
						pMenu->setPrev(pTemp_menu); // �޴��� ����� ���� ���θ��� ���
						pMenu->getPrev()->setNext(pMenu); // �޴��� ��������� �������� ���θ�����
						pMenu->setName(Name); // �̸�����
						pMenu->setPrice(price); //���ݼ���
						break; // �ݺ��� ����
					}
					else
						pTemp_menu = pTemp_menu->getNext(); // pTemp_menu�� �������� ����Ŵ
				}
				else if (pTemp_menu->getPrice() > price) { // pTemp_menu�� ������ Ŭ���
					if (pTemp_menu == pHead) { // ���� pHead�� �� ������ ���� �ϸ�
						pMenu->setNext(pTemp_menu); // �� ���� ���� pTemp_menu����
						pMenu->getNext()->setPrev(pMenu); // ���� �ص尪�� �������� ���λ����ѳ�����
						pMenu->setName(Name); // �̸��� ����
						pMenu->setPrice(price); // ������ ����
						pHead = pMenu; // pHead�� ���λ����� ���� ����
					}
					else { // pHead�� �ƴ� �Ϲݰ��� ��
						pMenu->setNext(pTemp_menu); // ���ο� ���� pTemp_menu�� �������� ����Ŵ
						pMenu->setPrev(pTemp_menu->getPrev()); // pTemp_menu�� �������� pMenu�� ����Ŵ
						pMenu->getPrev()->setNext(pMenu); // �޴��� �������� �������� ���ο���� ����Ŵ
						pMenu->getNext()->setPrev(pMenu); // pMenu�� �������� �������� pMenu�ΰ���Ŵ
						pMenu->setName(Name); // �̸��� ����
						pMenu->setPrice(price); // ������ ����
					}
					break; // �ݺ�������
				}
				else { // ������ �������� �̸����� ���� ����
					if (Compare(Name, pTemp_menu->getName()) == -1) { // �̸��� ���ϴ� ������ �տ� ��ġ�ؾ��� ��
						if (pTemp_menu == pHead) { // ���� pHead�϶��� ���ο� ��带 pHead�� �����ϰ� next,prev���� ��������
							pMenu->setNext(pTemp_menu);
							pMenu->getNext()->setPrev(pMenu);
							pMenu->setName(Name);
							pMenu->setPrice(price);
							pHead = pMenu; // ���ο� ��带 �ص�� ����
						} 
						else { // �ص尡 �ƴ� ���� �Ϲ������� ���ο����� ���ǰ��� �տ����� next prev�� ��Ȯ�� ����
							pMenu->setNext(pTemp_menu);
							pMenu->setPrev(pTemp_menu->getPrev());
							pMenu->getPrev()->setNext(pMenu);
							pMenu->getNext()->setPrev(pMenu);
							pMenu->setName(Name);
							pMenu->setPrice(price);
						}
						break; // �ݺ��� ����
					}
					else if (Compare(Name, pTemp_menu->getName()) == 1) { // ��Ŀ��(�ڷΰ����� ��) ���������� �̵��� ��
						if (pTemp_menu->getNext() == nullptr) { // ���� ���������̾ �� �ڷ� �� �� ���� ��� Next�� Prev����
							pMenu->setPrev(pTemp_menu);
							pMenu->getPrev()->setNext(pMenu);
							pMenu->setName(Name);
							pMenu->setPrice(price);
							break; //�ݺ��� ����
						}
						else { // ���������� �� �Ѿ�� �ɰ�� ���������� �̵�
							pTemp_menu = pTemp_menu->getNext();
						}
					}
					else if (Compare(Name, pTemp_menu->getName()) == 0) { // �������� ��� �����Ѱ� ���� x
						delete pMenu; // pMenu�� ��� ����
						break; // �ݺ��� ����
					}
				}
			}

		}
	}
}

void cafe::setHead(menu_node* pTemp) { //���� �������ִ� �żҵ�
	pHead = pTemp;
}

void cafe::setRoot(bst_node* pTemp) {//���� �������ִ� �żҵ�
	pRoot = pTemp;
}


menu_node* cafe::getHead() {//���� ��ȯ���ִ� �żҵ�
	return pHead;
}


bst_node* cafe::getRoot() { //���� ��ȯ���ִ� �żҵ�
	return pRoot;
}

int cafe::Compare(char* Insert_Name, char* Name) { // �޴��� ���ڸ� ���������� ���ؼ� ���� ��ū�� ��ȯ�ϴ� �żҵ�
	char *Insert_temp = new char[strlen(Insert_Name) + 1];
	char *Name_temp = new char[strlen(Name) + 1];
	int res = 0;
	for (int i = 0; i <= strlen(Insert_Name); i++) { // �޴��� ���� ��� �ҹ��ڷ� ����
		if (Insert_Name[i] >= 'A' && Insert_Name[i] <= 'Z') {
			Insert_temp[i] = Insert_Name[i] + ('a' - 'A');
		}
		else
			Insert_temp[i] = Insert_Name[i];
	}
	for (int i = 0; i <= strlen(Name); i++) { // �޴��� ���� ��� �ҹ��ڷ� ����
		if (Name[i] >= 'A' && Name[i] <= 'Z') {
			Name_temp[i] = Name[i] + ('a' - 'A');
		}
		else
			Name_temp[i] = Name[i];
	} 
	res = strcmp(Insert_temp, Name_temp); // strcmp�� ���� ��
	delete[] Name_temp; // �����Ҵ�����
	delete[] Insert_temp; // �����Ҵ�����
	return res; // ���� �� ��ȯ
}

void cafe::Print_price() { // ���ݼ����� ����ϴ� �żҵ�
	menu_node* pTemp = pHead;
	while (pTemp) { // pTemp�� nullptr�� �� ����
		cout << pTemp->getName();
		cout.width(10);
		cout << pTemp->getPrice() << endl;
		pTemp = pTemp->getNext();
	}
}

void cafe::Print_menu(bst_node* pTemp) { // menu������ ����ϴ� �żҵ�
	if (pTemp) { // Bst�� �̿��ؼ� ���
		Print_menu(pTemp->getLeft()); // ���� �������� �̵�(����Լ����)
		cout << pTemp->getNode()->getName(); // �̸� ��� ���
		cout.width(10);
		cout << pTemp->getNode()->getPrice() << endl; 
		Print_menu(pTemp->getRight()); // �������� �ִ°�� ���ϱ� ��ο��� ���Ͽ��������� �̵�(����Լ�)
	}
}
 
int cafe::SEARCH(char* Name) { //���� ã�� �żҵ�
	menu_node* pTemp = pHead;
	int price = -1;
	while (pTemp) { // pTemp�� nullptr�� ������
		if (strcmp(Name, pTemp->getName()) == 0) { // �޴��� �̸��� ���ϴ°��� �������
			price = pTemp->getPrice(); // �׸޴��� price�� ��ȯ
			break;
		}
		else
			pTemp = pTemp->getNext(); // ���� �ƴѰ�� ����������
	}
	return price; // ������ ��ȯ
}

bool cafe::Delete_node(char* name) { // ��带 �������ִ� �żҵ�
	bst_node* pBst = pRoot; // pRoot�� ����Ű�� ���
	bst_node* pParent = pRoot; // bst�� Ž���ϴ� �������� parent ���
	menu_node* pMenu = pHead; //pHead�� ����Ű�� ��� 
	bool is_search = false;
	while (pBst) { // pBst�� nullptr�� �� ���� �ݺ�
		if (Compare(name, pBst->getNode()->getName()) == 0) { // �Է����̸��� ��尡 ������ �ִ� �̸��� ���� ��
			is_search = true; // ��������� bool�� ����
			if (pParent->getLeft() == pBst) { // �θ��忡�� ������ ���� ã�� ������� Ȯ��
				if (pBst->getLeft() == nullptr && pBst->getRight() == nullptr) { // ã�� ��尡 �ڽĳ�带 ������ ���� ���
					pParent->setLeft(nullptr); // ���ʿ� ������
				}
				else if (pBst->getLeft() == nullptr) { // ���ʸ� ������� ���
					pParent->setLeft(pBst->getRight()); // �θ����� ���ʿ� �ڽĳ���� �������� ����
				}
				else if (pBst->getRight() == nullptr) { // pBst�� �������� ������� ���
					pParent->setLeft(pBst->getLeft()); //�θ����� ���ʿ� �ڽĳ���� ������ ����
					
				}
				else { // ������ ����� �ڽĳ�尡 �Ѵ� ���� ��
					bst_node* pTemp = pBst->getRight(); // pTemp�� pBst�� �������� ����Ŵ
					bst_node* pTemp_Parent = pBst; // pTemp�� �θ��Ʈ�� pBst�� ����Ŵ
					while (pTemp->getRight()) {
						pTemp_Parent = pTemp;  // pTemp�� �θ�� pTemp�� ����Ŵ
						pTemp = pTemp->getRight(); // pTemp�� ��� ����������
					}
					pParent->setLeft(pTemp); // �θ���� pTemp�� �������� ����Ŵ
					pTemp_Parent->setRight(pTemp->getLeft()); //pTemp�� �θ����� �������� pTemp�� ������ ����
					pTemp->setLeft(pBst->getLeft()); // pTemp�� ������ ���� pBst�� ������ ����
					pTemp->setRight(pBst->getRight()); // pTemp�� �������� ���� pBst�� �������� ����
				}
				delete pBst; // pBst��� ����
			}
			else if (pParent->getRight() == pBst) { // �θ����� �������� ������ ����� ���
				if (pBst->getLeft() == nullptr && pBst->getRight() == nullptr) { // �����ҳ�尡 �ڽĳ�带 ������ �ʴ°��
					pParent->setRight(nullptr); // �θ����� �������� ��
				}
				else if (pBst->getLeft() == nullptr) { //������ ����� ���ʸ� ����� ��
					pParent->setRight(pBst->getRight()); // �θ����� �������� ������ ����� �������� ����
				}
				else if (pBst->getRight() == nullptr) { // ������ ����� �����ʸ� ����� ��
					pParent->setRight(pBst->getLeft()); // �θ����� �������� ������ ����� ������ ����

				}
				else { // �ڽĳ�尡 �Ѵ� ���� ��
					bst_node* pTemp = pBst->getRight(); // pTemp�� ������ ����� �������� ����Ŵ
					bst_node* pTemp_Parent = pBst; // pTemp�Ǻθ�� ������ ��帧 ����Ŵ
					while (pTemp->getRight()) { // pTemp�� �������� ������� ������ �ݺ�
						pTemp_Parent = pTemp; // pTemp�� �θ���� pTmep��
						pTemp = pTemp->getRight(); // pTemp�� ��� ����������
					}
					pParent->setRight(pTemp); // ������ ����� �θ���� pTemp�� �����ʿ� ����
					pTemp_Parent->setRight(pTemp->getLeft()); // pTemp�� �θ����� �������� pTemp�� ������ ����
					pTemp->setLeft(pBst->getLeft()); // pTemp�� ������ ������ ����� �������� ����
					pTemp->setRight(pBst->getRight()); // pTemp�� �������� ������ ����� �������� ����
				}
				delete pBst; // pBst��� ����
			}
			else { //�θ����� ���� �������� �ƴҰ��(�� pRoot�� ���)
				if (pBst->getLeft() == nullptr && pBst->getRight() == nullptr) { // pRoot�� �ڽĳ�尡 �������
					pRoot = nullptr; // root�� �ʱ�ȭ�Ѵ�.
				}
				else if (pBst->getLeft() == nullptr) { // root�� ���ʳ�常 ������� ���
					pRoot = pBst->getRight(); // ������ ���� root�� �̵��Ѵ�.
				}
				else if (pBst->getRight() == nullptr) { // root�� �����ʳ�常 ������� ���
					pRoot = pBst->getLeft(); // ���ʳ��� root�� �̵��Ѵ�.
				}
				else { // root�� �Ѵ� ���� ���
					bst_node* pTemp = pBst->getLeft(); // root�� ���ʳ���� ���� ū���� �������ֱ� ���ؼ� ������ ����
					bst_node* pTemp_Parent = pBst; //root�� ���� ����� ����ū���� �θ���
					while (pTemp->getRight()) { // pTemp�� root���� ���� ū���� ã�����ؼ� ���������� ����
						pTemp_Parent = pTemp; // �θ���
						pTemp = pTemp->getRight(); // ����������
					}
					if (pTemp == pBst->getLeft()) { // pTemp�� ������ ����� �����ϰ��(root�� �ڽĳ�尡 ���ʿ� �ϳ��ϰ��)
						pTemp->setRight(pBst->getRight()); // ������ ����� ������ pRoot�� �ٲ�
						pRoot = pTemp;
					}
					else { // pTemp�� ������ ����� ���� ū������ �����(���������� �ѹ��̶� �����)
						pTemp_Parent->setRight(pTemp->getLeft()); // pTemp�� �θ��� �������� pTemp�� ���ʰ��� ����
						pTemp->setLeft(pBst->getLeft()); // pTemp�� ������ Root�� ����������
						pTemp->setRight(pBst->getRight()); // pTemp�� �������� Root�� �������� ����
						pRoot = pTemp; // pRoot�� ����
					}
				}
				delete pBst; // pBst��� ����
			}
			break; // �ݺ��� ����
		}
		else if (Compare(name, pBst->getNode()->getName()) == 1) { // ������ ����� �̸��� �������� �̸��� ���ؼ� ������ ����� �̸���Ŭ���� ���������� �̵�
			pParent = pBst;
			pBst = pBst->getRight();
		}
		else if (Compare(name, pBst->getNode()->getName()) == -1) { // ������ ����� �̸��� �������� �̸��� ���ؼ� ���� ���� ��������
			pParent = pBst;
			pBst = pBst->getLeft();
		}
	}
	while (pMenu) { // pMenu���� ��带 ã�� �����ϱ� ���� �ݺ���
		if (strcmp(name, pMenu->getName()) == 0) { // �̸��� ���� ��带 ã���� ��
			if (pMenu == pHead) { // ������ ��尡 pHead�� ���
				if (pMenu->getNext() != nullptr) { // ������ ����� ������尡 �ִ� ���
					pMenu->getNext()->setPrev(nullptr); // �����ҳ���� �������� �������� ����
				}
				pHead = pMenu->getNext(); //�����Ұ��� �������� pHead�� �ٲ�
			}
			else { // ������ ��尡 Head�� �ƴѰ��
				pMenu->getPrev()->setNext(pMenu->getNext()); //�޴��� �������� �����ҳ�尡 ����Ű�� �������� ���������� ����
				if (pMenu->getNext() != nullptr) { // �����Ұ��� Tail�� �ƴҰ��
					pMenu->getNext()->setPrev(pMenu->getPrev()); // �����ҳ���� �������� �������� �����ҳ���� ���������� ����
				} 
			}
			delete pMenu; //�޴� ������ 
			 break; // �ݺ�������
		}
		else {
			pMenu = pMenu->getNext(); // pMenu�� ���� ������
		}
	}
	return is_search; // �����Ѱ��̿��� ������ �ȉ���� ������� ��ȯ
}

void cafe::Remove_Tree(bst_node* pTemp) { // bst�� �����ϴ� �żҵ�
	if (pTemp) { 
		Remove_Tree(pTemp->getLeft()); // bst���� ���� ���������̵� (����Լ�)
		Remove_Tree(pTemp->getRight()); // bst���� ���� ���� �����������̵� (����Լ�)
		delete pTemp; // �����Ҵ�����
	}
}