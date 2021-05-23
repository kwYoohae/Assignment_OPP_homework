#include "time_tree.h"

time_tree::time_tree() {
	pRoot = nullptr;
}
time_tree::~time_tree() {

}

time_node* time_tree::getRoot() {
	return pRoot;
}


void time_tree::setRoot(time_node* pTemp) {
	pRoot = pTemp;
}
