#include "location_tree.h"

location_tree::location_tree() {
	pRoot = nullptr;
}
location_tree::~location_tree() {

}

tree_node* location_tree::getRoot() {
	return pRoot;
}

void location_tree::setRoot(tree_node* pTemp) {
	pRoot = pTemp;
}