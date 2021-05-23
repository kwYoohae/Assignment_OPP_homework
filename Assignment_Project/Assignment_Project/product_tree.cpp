#include "product_tree.h"

product_tree::product_tree() {
	pRoot = nullptr;
}
product_tree::~product_tree() {

}

product_node* product_tree::getRoot() {
	return pRoot;
}

void product_tree::setRoot(product_node* pTemp) {
	pRoot = pTemp;
}