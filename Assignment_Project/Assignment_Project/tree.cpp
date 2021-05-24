#include "tree.h"

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


