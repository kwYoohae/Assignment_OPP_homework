#include "tree.h"
#include <iostream>
tree::tree() {
	pRoot = nullptr;
}
tree::~tree() {

}

tree_node* tree::getRoot() {
	return pRoot;
}

void tree::setRoot(tree_node* pTemp) {
	pRoot = pTemp;
}

tree_node* tree::search_child(char* data) {
	tree_node* pTemp = pRoot;
	tree_node* pParent = pTemp;
	while(pParent) {
		if (strcmp(data, pTemp->getData()) == 0) {
			if (!pTemp->getDown())
				return nullptr;
			else {
				return pTemp;
			}
		}
		if (!pTemp) {
			pParent = pParent->getDown();
			pTemp = pParent;
		}
		else {
			pTemp = pTemp->getNext();
			if (!pTemp) {
				pParent = pParent->getDown();
				pTemp = pParent;
			}
		}
	}
	return nullptr;
}

int tree::cnt_chiled(char* data) {
	tree_node* pTemp = search_child(data);
	if (pTemp == nullptr)
		return 0;
	int cnt = 0;
	pTemp = pTemp->getDown();
	while (pTemp) {
		cnt++;
		pTemp = pTemp->getNext();
	}
	return cnt;
}

