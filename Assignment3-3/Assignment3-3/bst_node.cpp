#include "bst_node.h"

bst_node::bst_node() {
	pNode = nullptr;
	pRight = nullptr;
	pLeft = nullptr;
}

bst_node::~bst_node() {

}

void bst_node::setNode(menu_node* pTemp) {
	pNode = pTemp;
}

void bst_node::setLeft(bst_node* pTemp) {
	pLeft = pTemp;
}

void bst_node::setRight(bst_node* pTemp) {
	pRight = pTemp;
}

menu_node* bst_node::getNode() {
	return pNode;
}

bst_node* bst_node::getLeft() {
	return pLeft;
}

bst_node* bst_node::getRight() {
	return pRight;
}
