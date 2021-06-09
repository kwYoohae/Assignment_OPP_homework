#include "tree.h"
#include <iostream>
tree::tree() { // 생성자
	pRoot = nullptr;
}
tree::~tree() { // 소멸자
	delete_tree(pRoot); // tree를 삭제해주는 매소드 호출
	pRoot = nullptr;
}

tree_node* tree::getRoot() {// 값을 반환하는 매소드
	return pRoot;
}

void tree::setRoot(tree_node* pTemp) { // 값을 변경하는 매소드
	pRoot = pTemp;
}

void tree::delete_tree(tree_node* pNode) { // tree를 삭제하는 매소드
	if (!pNode) { // 재귀적으로 삭제
		delete_tree(pNode->getDown()); // 제일 밑 계층 방문 
		delete_tree(pNode->getNext()); // 자매노드 삭제
		delete pNode;
	}
}

