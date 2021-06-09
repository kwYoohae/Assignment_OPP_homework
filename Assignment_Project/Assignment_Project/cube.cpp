#include "cube.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

cube::cube() { // 생성자(초기화)
	pHead = nullptr;
	Row = nullptr;
	Column = nullptr;
	Height = nullptr;
}

cube::~cube() {
}

cube_1D* cube::getRow() {// 값을 반환하는 매소드
	return Row;
}
cube_1D* cube::getColumn() {// 값을 반환하는 매소드
	return Column;
}
cube_1D* cube::getHeight() {// 값을 반환하는 매소드
	return Height;
}
node* cube::getHead() {// 값을 반환하는 매소드
	return pHead;
}

void cube::setRow(cube_1D* pTemp) { // 값을 변경하는 매소드
	Row = pTemp;
}
void cube::setColumn(cube_1D* pTemp) {// 값을 변경하는 매소드
	Column = pTemp;
}
void cube::setHeight(cube_1D* pTemp) {// 값을 변경하는 매소드
	Height = pTemp;
}
void cube::setHead(node* pTemp) {// 값을 변경하는 매소드
	pHead = pTemp;
}

void cube::WriteLog(char* command) {//log에 결과값을 작성하는 매소드
	ofstream log;
	cube_1D* Rev_temp = (this->*pRow)();
	log.open("log.txt", ios::app); // log.txt파일을 열고 ios::app방식으로 기존 텍스트에 이어쓴다.
	log << '[' << command << ']' << '\n';//무슨 커맨드를 작동한 결과인지 결과를 입력한다. 
	if (Rev_temp->getRev() % 2 == 0) {
		log << (this->*pRow)()->getData()->getData() << '\t'; // Row값을 먼저 출력한다.
	}
	else {
		while (Rev_temp->getNext()) { //Rev_temp를 거꾸로 출력하기 위해 제일 뒤쪽 값으로 보낸다.
			Rev_temp = Rev_temp->getNext();
		}
		log << Rev_temp->getData()->getData() << '\t'; // Row값을 먼저 출력한다.
	}
	Rev_temp = (this->*pColumn)(); // Column값을 모두 출력한다.
	if (Rev_temp->getRev() % 2 == 0) { // Rev값이 % 2를해서 0 일때는 정상적으로 출력한다.
		while (Rev_temp) { // Rev_temp를 정상적으로 출력해준다.
			log << Rev_temp->getData()->getData() << '\t';
			Rev_temp = Rev_temp->getNext();
		}
	}
	else { // 거꾸로 출력하기 위한 조건문
		while (Rev_temp->getNext()) { // 맨끝값으로 이동
			Rev_temp = Rev_temp->getNext();
		}
		while (Rev_temp) { // 이전값으로 이동하면서 거구ㅗ 출력
			log << Rev_temp->getData()->getData() << '\t';
			Rev_temp = Rev_temp->getPrev();
		}
	}
	log << '\n';
	cube_1D* pTemp = (this->*pHeight)(); //pHeight값을 출력하기 위해서 할당
	Rev_temp = (this->*pHeight)();
	while (Rev_temp->getNext()) { // 제일 뒤쪽값으로 이동
		Rev_temp = Rev_temp->getNext();
	}
	node* pWork1 = pHead;
	node* pWork2 = pWork1;
	while (pWork2) {
		if (pTemp->getRev() % 2 == 0) { // Rev값이 % 2 를 했을 때 0이면 원래 순서대로 출력
			log << pTemp->getData()->getData() << '\t'; // Height의 데이터중 하나를 출력한다/
			pTemp = pTemp->getNext();
		}
		else {
			log << Rev_temp->getData()->getData() << '\t'; // Height의 데이터중 하나를 출력한다/
			Rev_temp = Rev_temp->getPrev();
		}
		while (pWork1) {
			log << pWork1->getData() << '\t' << '\t'; // 노드의 데이터를 출력한다.
			pWork1 = (pWork1->*pRight)(); // 다음 값으로 이동
		}
		log << '\n';
		pWork2 = (pWork2->*pDown)(); // 모든 Right값을 돌았을 때 밑으로 Down으로 이동
		pWork1 = pWork2;
	}
	log << '\n' << '\n';
	log.close();
}

void cube::Make_tree(tree* Time, tree* Location, tree* Product, int product_number, int location_number, int time_number) { // 트리를 만드는 매소드
	tree_node* pTemp = Time->getRoot(); // time부터 트리생성
	tree_node* pParent = pTemp;
	for (int i = 1; i < time_number; i++) { // time의 입력한 계층만큼 밑으로 내려감
		pParent = pTemp;
		pTemp = pTemp->getDown();
		if (!pTemp->getDown()) {
			break;
		}
	}
	while (pParent) { // 부모노드가 더이상 자매노드가 없을 때까지 생성
		while (pTemp) {
			cube_1D* pNew = new cube_1D;
			if (!Row) { // Row값이 비어있을 때는
				Row = pNew;
				pNew->setData(pTemp); // Row에 데이터 저장
			}
			else {
				cube_1D* cube_temp = (this->*pRow)();
				while (cube_temp->getNext()) // Row값에서 마지막값까지이동 
					cube_temp = cube_temp->getNext();
				cube_temp->setNext(pNew); // 마지막을 새로만든 노드와 이어줌
				pNew->setPrev(cube_temp); // 마지막값의 이전값을 설정해줌
				pNew->setData(pTemp); // 데이터를 넣어줌
			}
			pTemp = pTemp->getNext(); // 다음 자매노드로
		}
		pParent = pParent->getNext(); // 다음 자매노드로
		if (!pParent) // 비었을때 반복문 종료
			break;
		pTemp = pParent->getDown();
	}

	pTemp = Location->getRoot(); //위와 똑같은 방식으로 Location의 자식의 자매노드를 계속 탐색해서 tree를 생성해준다
	pParent = pTemp;
	for (int i = 1; i < location_number; i++) {
		pParent = pTemp;
		pTemp = pTemp->getDown();
		if (!pTemp->getDown()) {
			break;
		}
	}
	while (pParent) {
		while (pTemp) {
			cube_1D* pNew = new cube_1D;
			if (!Column) {
				Column = pNew;
				pNew->setData(pTemp);
			}
			else {
				cube_1D* cube_temp = (this->*pColumn)();
				while (cube_temp->getNext())
					cube_temp = cube_temp->getNext();
				cube_temp->setNext(pNew);
				pNew->setPrev(cube_temp);
				pNew->setData(pTemp);
			}
			pTemp = pTemp->getNext();
		}
		pParent = pParent->getNext();
		if (!pParent)
			break;
		pTemp = pParent->getDown();
	}

	pTemp = Product->getRoot();//위와 똑같은 방식으로 Time의 자식의 자매노드를 계속 탐색해서 tree를 생성해준다
	pParent = pTemp;
	for (int i = 1; i < product_number; i++) {
		pParent = pTemp;
		pTemp = pTemp->getDown();
		if (!pTemp->getDown()) {
			break;
		}
	}
	while (pParent) {
		while (pTemp) {
			cube_1D* pNew = new cube_1D;
			if (!Height) {
				Height = pNew;
				pNew->setData(pTemp);
			}
			else {
				cube_1D* cube_temp = (this->*pHeight)();
				while (cube_temp->getNext())
					cube_temp = cube_temp->getNext();
				cube_temp->setNext(pNew);
				pNew->setPrev(cube_temp);
				pNew->setData(pTemp);
			}
			pTemp = pTemp->getNext();
		}
		pParent = pParent->getNext();
		if (!pParent)
			break;
		pTemp = pParent->getDown();
	}
}

void cube::Make_Cube(int p, int l, int t) { //cube를 만드는 매소드 
	node* pWork1 = nullptr;
	node* pWork2 = nullptr;
	node* pWork3 = nullptr;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < l; k++) {
				node* pNew = new node; // cube를 생성
				if (i == 0 && j == 0 && k == 0) { // 처음값은 Head로 설정
					pHead = pNew;
					pWork1 = pHead;
					pWork2 = pHead;
					pWork3 = pHead;
				}
				else if (i != 0 && k == 0 && j == 0) { // Row값(Time값을 생성하기 위한 조건문)
					pWork1 = pHead;
					while (pWork1->getRnext()) { // Row의 끝값까지 가서 생성
						pWork1 = pWork1->getRnext();
					}
					pWork1->setRnext(pNew); // 새로운 Row(Time)을생성
					pNew->setRprev(pWork1); // 이전값 설정
					pWork2 = pNew; // 새로운 Row(Time)에서 2차원 배열을 만들어주기 위한설정
					pWork3 = pNew;// 새로운 Row(Time)에서 2차원 배열을 만들어주기 위한설정
				}
				else if (k == 0) { // 2차원배열 Height(product를 만들어주기 위한 조건문)
					pWork1 = pHead;
					while (pWork1->getRnext()) { // Row(Time)의 끝까지 이동
						pWork1 = pWork1->getRnext();
					}
					pWork2 = pWork1; // 거기서부터 지금까지 만든 product의 끝까지 이동
					while (pWork2->getHnext()) {
						pWork2 = pWork2->getHnext();
					}
					pWork2->setHnext(pNew); // 새로운 product의 이전값 다음값 설정
					pNew->setHprev(pWork2);
					pWork3 = pNew;
				}
				else { // 그냥 column(location)을 생성할 경우 location의 끝값까지 이동 후 만들어줌
					while (pWork3->getCnext()) {
						pWork3 = pWork3->getCnext();
					}
					pWork3->setCnext(pNew); // 새로생긴 location의 next,prev값 설정
					pNew->setCprev(pWork3);
				}
			}
			if (j != 0) { // j(product)가 2개이상일때 서로의 product줄을 서로 이어주는 매소드
				pWork1 = pHead;
				while (pWork1->getRnext()) { // Time이 생성된곳까지 이동
					pWork1 = pWork1->getRnext();
				}
				pWork3 = pWork1;
				while (pWork3->getHnext()) { // product가 생성된곳 까지이동
					pWork3 = pWork3->getHnext();
				}
				pWork2 = pWork3->getHprev(); // 마지막 product의 전값으로 설정
				while (pWork2) {
					pWork2->setHnext(pWork3); // 서로의 product값 설정
					pWork3->setHprev(pWork2);
					pWork2 = pWork2->getCnext(); // 그다음 location으로 이동
					pWork3 = pWork3->getCnext();
				}
			}
		}
		if (i != 0) { // Time값이 2개일 때
			pWork1 = pHead;
			while (pWork1->getRnext()) { //time의 생성된 끝값까지 이동한다
				pWork1 = pWork1->getRnext();
			}
			pWork2 = pWork1->getRprev(); // 마지막값의 전값으로 설정
			pWork3 = pWork1;
			while (pWork1) { // time을 2차원배열끼리 연결이 끝날때까지 반복
				while (pWork2) { // location을 탐색하여 time을 이어주는 반복문
					pWork2->setRnext(pWork3);
					pWork3->setRprev(pWork2);
					pWork2 = pWork2->getCnext(); // 다음 location값으로 이동
					pWork3 = pWork3->getCnext();
				}
				pWork2 = pWork1->getRprev()->getHnext();
				pWork3 = pWork1->getHnext();
				pWork1 = pWork1->getHnext();
			}
		}
	}
}

void cube::Make_View(tree* Time, tree* Location, tree* Product) { //view큐브의 초기생성을 하는 매소드(row,column,height를 3계층에서 2게층으로 rollup하는 방법
	int number = 0;
	node* pWork1 = pHead;
	node* pWork2;
	node* pWork3;
	node* pWork4;
	tree_node* pTemp;
	tree_node* tree_temp = Height->getData();
	tree_node* tree_down = tree_temp->getDown();
	pTemp = tree_temp;
	if (tree_down) { // high의 자식노드가 비어있지 않을때
		while (tree_down->getNext()) { // 원하는 계층까지 이동
			tree_down = tree_down->getNext();
			number++;
		}
	}
	while (tree_temp) { // tree_temp가 마지막 자매노드까지 방문했을 때까지 반복
		for (int i = 0; i < number; i++) { // 자식노드의 개수만큼 반복 rollup을 해줌
			pWork2 = pWork1;
			while (pWork2) {
				pWork3 = pWork2;
				while (pWork3) { // height를 기준으로 서로의 다음을 이어줌
					pWork4 = pWork3->getHnext(); // height를 기준으로 삭제할 height를 가져옴
					pWork3->setData(pWork3->getData() + pWork4->getData()); // 삭제할 노드와 기존 데이터를 합침
					pWork3->setHnext(pWork4->getHnext()); // 삭제할데이터의 다음값과 합치는 값의 다음값을 결정해줌
					if (pWork4->getHnext()) { // pWork4의 다음값이 비어있지 않을때(마지막 값이 아닐때)
						pWork4->getHnext()->setHprev(pWork3); // 그다음 값의 이전값을 설정해줌
						//break;
					}
					delete pWork4; //노드삭제
					pWork3 = pWork3->getCnext(); // 그다음 노드로 이동 Column값
				}
				pWork2 = pWork2->getRnext(); // 모든 Column값을 연결해주었으면 다음 Row값으로 이동
			}
		}
		pWork1 = pWork1->getHnext(); //모든 Height에 대한값을 삭제하면 다음 Height로 이동
		tree_temp = tree_temp->getNext(); // tree_temp다음값으로 이동한다
		if (!tree_temp) // 없으면 종료
			break;
		tree_down = tree_temp->getDown(); // tree_temp의 자식노드로 이동한다.
		number = 0;
		while (tree_down->getNext()) { // 자식노드의 개수를 샌다
			tree_down = tree_down->getNext();
			number++;
		}
	}

	tree_temp = Row->getData(); // 위의 Height와 똑같은 방식으로 Row의 3계층을 2계층으로 합치는 과정임.
	pTemp = tree_temp;
	pWork1 = pHead;
	number = 0;
	tree_down = tree_temp->getDown();
	if (tree_down) {
		while (tree_down->getNext()) {
			tree_down = tree_down->getNext();
			number++;
		}
	}
	while (tree_temp) {
		for (int i = 0; i < number; i++) {
			pWork2 = pWork1;
			while (pWork2) {
				pWork3 = pWork2;
				while (pWork3) {
					pWork4 = pWork3->getRnext();
					pWork3->setData(pWork3->getData() + pWork4->getData());
					pWork3->setRnext(pWork4->getRnext());
					if (pWork4->getRnext()) {
						pWork4->getRnext()->setRprev(pWork3);
						//break;
					}
					delete pWork4;
					pWork3 = pWork3->getCnext();
				}
				pWork2 = pWork2->getHnext();
			}
		}
		pWork1 = pWork1->getRnext();
		tree_temp = tree_temp->getNext();
		if (!tree_temp)
			break;
		tree_down = tree_temp->getDown();
		number = 0;
		while (tree_down->getNext()) {
			tree_down = tree_down->getNext();
			number++;
		}
	}

	tree_temp = Column->getData();// 위의 Height와 똑같은 방식으로 Column의 3계층을 2계층으로 합치는 과정임.
	pTemp = tree_temp;
	pWork1 = pHead;
	number = 0;
	tree_down = tree_temp->getDown();
	if (tree_down) {
		while (tree_down->getNext()) {
			tree_down = tree_down->getNext();
			number++;
		}
	}
	while (tree_temp) {
		for (int i = 0; i < number; i++) {
			pWork2 = pWork1;
			while (pWork2) {
				pWork3 = pWork2;
				while (pWork3) {
					pWork4 = pWork3->getCnext();
					pWork3->setData(pWork3->getData() + pWork4->getData());
					pWork3->setCnext(pWork4->getCnext());
					if (pWork4->getCnext()) {
						pWork4->getCnext()->setCprev(pWork3);
						//break;
					}
					delete pWork4;
					pWork3 = pWork3->getHnext();
				}
				pWork2 = pWork2->getRnext();
			}
		}
		pWork1 = pWork1->getCnext();
		tree_temp = tree_temp->getNext();
		if (!tree_temp)
			break;
		tree_down = tree_temp->getDown();
		number = 0;
		while (tree_down->getNext()) {
			tree_down = tree_down->getNext();
			number++;
		}
	}
}


void cube::copyData(cube* raw) { // raw큐브의 데이터를 복사해서 가져오는 매소드
	node* pWork1 = raw->getHead();  // raw큐브의값
	node* pWork2 = pWork1;// raw큐브의값
	node* pWork3 = pWork1;// raw큐브의값
	node* pCopy1 = pHead; // view큐브의 값
	node* pCopy2 = pCopy1; // view큐브의 값
	node* pCopy3 = pCopy1; // view큐브의 값
	while (pWork1) {
		while (pWork2) {
			while (pWork3) {
				pCopy3->setData(pWork3->getData()); // 데이터를 복사해줌
				pWork3 = pWork3->getCnext(); // column(RIght)쪽으로 계속이동
				pCopy3 = pCopy3->getCnext();
			}
			pWork2 = pWork2->getHnext(); // Height(Down)쪽으로 계속이동
			pCopy2 = pCopy2->getHnext();
			pWork3 = pWork2;
			pCopy3 = pCopy2;
		}
		pWork1 = pWork1->getRnext(); // Row(Out)쪽으로 계속이동
		pCopy1 = pCopy1->getRnext();
		pWork2 = pWork1;
		pWork3 = pWork1;
		pCopy3 = pCopy1;
		pCopy2 = pCopy1;
	}
}

bool cube::Rotate(char* command) {
	node* (node:: * pRight_temp)() = pRight; //각 temp값 생성
	node* (node:: * pLeft_temp)() = pLeft; //각 temp값 생성
	node* (node:: * pUp_temp)() = pUp; //각 temp값 생성
	node* (node:: * pDown_temp)() = pDown; //각 temp값 생성
	node* (node:: * pIn_temp)() = pIn; //각 temp값 생성
	node* (node:: * pOut_temp)() = pOut; //각 temp값 생성
	void (node:: * setRight_temp)(node * pTemp) = setRight; //각 temp값 생성
	void (node:: * setLeft_temp)(node * pTemp) = setLeft; //각 temp값 생성
	void (node:: * setUp_temp)(node * pTemp) = setUp; //각 temp값 생성
	void (node:: * setDown_temp)(node * pTemp) = setDown; //각 temp값 생성
	void (node:: * setIn_temp)(node * pTemp) = setIn; //각 temp값 생성
	void (node:: * setOut_temp)(node * pTemp) = setOut; //각 temp값 생성

	cube_1D* (cube:: * pRow_temp)() = pRow; //각 temp값 생성
	cube_1D* (cube:: * pColumn_temp)() = pColumn; //각 temp값 생성
	cube_1D* (cube:: * pHeight_temp)() = pHeight; //각 temp값 생성
	void (cube:: * pRow_set_temp)(cube_1D * pTemp) = pRow_set; //각 temp값 생성
	void (cube:: * pColumn_set_temp)(cube_1D * pTemp) = pColumn_set; //각 temp값 생성
	void (cube:: * pHeight_set_temp)(cube_1D * pTemp) = pHeight_set; //각 temp값 생성
	if (strcmp(command, "clockwise") == 0) {
		while ((pHead->*pDown)()) { //Head를 가장 밑으로
			pHead = (pHead->*pDown)();
		}
		pRight = pUp_temp; // right = up방향으로
		setRight = setUp_temp;
		pLeft = pDown_temp; // left = down방향으로
		setLeft = setDown_temp;
		pDown = pRight_temp; // down = right방향으로
		setDown = setRight_temp;
		pUp = pLeft_temp; // up = left방향으로
		setUp = setLeft_temp;
		pHeight = pColumn_temp; // Height = column방향으로
		pColumn = pHeight_temp; // Column = Height방향으로
		pHeight_set = pColumn_set_temp;
		pColumn_set = pHeight_set_temp;
		(this->*pColumn)()->setRev((this->*pColumn)()->getRev() + 1); // column은 거꾸로출력
	}
	else if (strcmp(command, "c_clockwise") == 0) {
		while ((pHead->*pRight)()) { // Head를 제일 오른쪽으로
			pHead = (pHead->*pRight)();
		}
		pRight = pDown_temp; // right = down으로
		setRight = setDown_temp;
		pLeft = pUp_temp; // left = up으로
		setLeft = setUp_temp;
		pDown = pLeft_temp; // down은 left로
		setDown = setLeft_temp;
		pUp = pRight_temp; // up은 right로
		setUp = setRight_temp;
		pHeight = pColumn_temp; // height = column으로
		pColumn = pHeight_temp; // column = height으로
		pHeight_set = pColumn_set_temp;
		pColumn_set = pHeight_set_temp;
		(this->*pHeight)()->setRev((this->*pHeight)()->getRev() + 1); // height를 거꾸로 출력
	}
	else if (strcmp(command, "left") == 0) {
		while ((pHead->*pRight)()) { // Head를 제일 right값으로
			pHead = (pHead->*pRight)();
		}
		pRight = pOut_temp; // right = out으로
		setRight = setOut_temp;
		pLeft = pIn_temp; // left= in으로
		setLeft = setIn_temp;
		pOut = pLeft_temp; // out = left로
		setOut = setLeft_temp;
		pIn = pRight_temp; // in = right로
		setIn = setRight_temp;
		pColumn = pRow_temp; // column은 row로
		pRow = pColumn_temp; // row는 column으로
		pColumn_set = pRow_set_temp;
		pRow_set = pColumn_set_temp;
		(this->*pRow)()->setRev((this->*pRow)()->getRev() + 1); // row를 거꾸로 출력
	}
	else if (strcmp(command, "right") == 0) {
		while ((pHead->*pOut)()) { // pHead를 제일 out쪽으로
			pHead = (pHead->*pOut)();
		}
		pRight = pIn_temp; //right = in으로
		setRight = setIn_temp;
		pLeft = pOut_temp; // left는 out으로
		setLeft = setOut_temp;
		pOut = pRight_temp; // out은 right로
		setOut = setRight_temp;
		pIn = pLeft_temp; // in은 left로
		setIn = setLeft_temp;
		pColumn = pRow_temp; // columb은 row로
		pRow = pColumn_temp;// row는 column으로
		(this->*pColumn)()->setRev((this->*pColumn)()->getRev() + 1); //Column은 거꾸로 출력
	}
	else if (strcmp(command, "up") == 0) {
		while ((pHead->*pDown)()) { //haed는 down의 끝쪽으로
			pHead = (pHead->*pDown)();
		}
		pDown = pOut_temp; // down = out으로
		setDown = setOut_temp;
		pUp = pIn_temp; // up 은 in으로
		setUp = setIn_temp;
		pOut = pUp_temp; // out은 up으로 
		setOut = setUp_temp;
		pIn = pDown_temp; // in은 down으로
		setIn = setDown_temp;
		pHeight = pRow_temp; // height는 row로
		pRow = pHeight_temp; // row는 height로
		pHeight_set = pRow_set_temp;
		pRow_set = pHeight_set_temp;
		(this->*pRow)()->setRev((this->*pRow)()->getRev() + 1); // row는 거꾸로 출력
	}
	else if (strcmp(command, "down") == 0) {
		while ((pHead->*pOut)()) { // head는 out의 끝으로
			pHead = (pHead->*pOut)();
		}
		pDown = pIn_temp; // down은 in으로
		setDown = setIn_temp;
		pUp = pOut_temp; // up은 out으로
		setUp = setOut_temp;
		pOut = pDown_temp; // out은 down으로
		setOut = setDown_temp;
		pIn = pUp_temp; // in은 up으로
		setIn = setUp_temp;
		pHeight = pRow_temp; // height는 row로
		pRow = pHeight_temp; // row는 height로
		pHeight_set = pRow_set_temp;
		pRow_set = pHeight_set_temp;
		(this->*pHeight)()->setRev((this->*pHeight)()->getRev() + 1); // height을 거꾸로 출력
	}
	else {
		return false;
	}
	return true;
}

bool cube::Roll_up(char* command) { // ROLLUP을 하는 매소드
	bool find = false;
	int h = 0;
	int r = 0;
	int c = 0;
	int cnt = 0;
	int end = 0;
	int start = 0;
	int low_number = 0;
	cube_1D* pTemp = (this->*pRow)(); // Row의 값을 가져온다.
	while (!find) { //find를 찾지못해 false이면 반복문을 돌게한다.
		while (pTemp) {
			if (strcmp(pTemp->getData()->getData(), command) == 0) { // row값이 같은지 확인
				cnt++;
				r = cnt;
				find = true;
				break; // 같으면 반복문종료
			}
			pTemp = pTemp->getNext(); // 다음값으로
			cnt++;
		}
		if (find)
			break; // find를 했으면 break으로 반복문을 빼져나감
		pTemp = (this->*pColumn)(); // Column값을 비교하기 위해 할당
		cnt = 0;
		while (pTemp) {
			if (strcmp(pTemp->getData()->getData(), command) == 0) { //같은값인지 확인
				cnt++;
				c = cnt;
				find = true;
				break; //반복문종료
			}
			pTemp = pTemp->getNext(); //다음값으로
			cnt++;
		}
		if (find)
			break; //반복문종료
		pTemp = (this->*pHeight)(); // Height값을 비교하기 위해 할당
		cnt = 0;
		while (pTemp) {
			if (strcmp(pTemp->getData()->getData(), command) == 0) { // 같은 값인지 확인
				cnt++;
				h = cnt;
				find = true;
				break; // 반복문종료
			}
			pTemp = pTemp->getNext(); // 다음값으로
			cnt++;
		}
		break; // 반복문 종료
	}
	if (find == true) {//만약 값을 찾았을 때
		if (!pTemp->getData()->getUp()) { // up이 없으면 1계층이므로 ROLLUP할게 없으므로 false를 return
			return false;
		}
		else {
			low_number = pTemp->getData()->getLow() - 1; // 계층 데이터를 저장
			tree_node* pCount = pTemp->getData()->getNext(); // end와 start를 세어주기 위한 변수
			node* pWork1 = pHead;
			while (pCount) { // next를 돌면서 end의 까지의 개수를 샌다.
				end++;
				pCount = pCount->getNext(); // Next로 값을 이동
			}
			pCount = pTemp->getData()->getPrev(); //prev값으로 start까지의 거리를 재기 위해서 할당
			while (pCount) {
				start++;
				pCount = pCount->getPrev(); // 이전값으로 계속이동
			}
			if (!pTemp->getData()->getUp()->getDown()->getNext()) { //자식노드가 하나인지 확인하는 매소드
				pTemp->setData(pTemp->getData()->getUp()); // 위의 계층 값으로 cube_1d의 데이터 저장
				return true; //true반환 후 매소드 종료
			}
			else if (!pTemp->getNext() && !pTemp->getPrev()) { // 만약 node가 next prev가 둘다 비어 혼자만 있는 상황일 때
				pTemp->setData(pTemp->getData()->getUp()); // 위의 계층 값으로 cube_1D의 데이터 저장
				return true; // true반환 후 매소드 종료
			}
			for (int i = 0; i < start; i++) { // ROLLUP하려는 계층의 시작값으로 이동한다.
				r--; // 변수를 나중에 쓸거기 때문에 이동하는 만큼 감소시킨다.
				h--;
				c--;
				if (!pTemp->getPrev()) // 만약 이전값이 비어있을 때는 반복문 종료 (혼자만 있는 큐브 일 때)
					break;
				pTemp = pTemp->getPrev();
			}
			if (h > 0) { //h >0 이어서 Height값에 ROLLUP을 수행할 값이 있는 경우
				for (int i = 0; i < h - 1; i++) { // Head부터 ROLLUP을 해줄 값까지 노드를 이동
					pWork1 = (pWork1->*pDown)(); // Height이므로 down방향으로 이동
				}
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < start + end; i++) { // 계층의 자매노드의 개수만큼 반복문 실행
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pDown)(); //pWork4는 그다음 Height의 값 (삭제할값)
							pWork3->setData(pWork3->getData() + pWork4->getData()); // 데이터를 덧셈한다.
							(pWork3->*setDown)((pWork4->*pDown)()); // Down값을 pWork4의 다음값으로 이동
							if ((pWork4->*pDown)()) {  //더이상 ROLLUP할 노드가 없어(Cube의 맨 끝 값 반복문을 수행하지 못할 때)
								((pWork4->*pDown)()->*setUp)(pWork3); // pDown에 대한 Height값 설정
							}
							delete pWork4; // 큐브삭제
							pWork3 = (pWork3->*pRight)(); // 다음 column값으로 이동
						}
						pWork2 = (pWork2->*pOut)(); // column값을 다 돌았으면 다음 Out값으로 이동
					}
				}
			}
			else if (c > 0) {//c >0일 떄는 Column값에 ROLLUP을 수행할 값이 있는 경우
				for (int i = 0; i < c - 1; i++) { // Column이므로 right로 이동
					pWork1 = (pWork1->*pRight)();
				}
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < start + end; i++) { // 계층의 자매노드 개수만큼 반복문 실행
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pRight)(); // pWork는 다음 Column의 값
							pWork3->setData(pWork3->getData() + pWork4->getData()); // 삭제할 데이터와 기준데이터를 합친다.
							(pWork3->*setRight)((pWork4->*pRight)()); //기준값의 다음 Right값의 삭제할 값의 다음 right값으로 설정
							if ((pWork4->*pRight)()) { // 더 이상 Rollup할 노드가 없을 때 (Cube의 맨 끝 Column값이 기준값이라 반복문을 수행하지 못할 때)
								((pWork4->*pRight)()->*setLeft)(pWork3);
							}
							delete pWork4;//큐브를 삭제
							pWork3 = (pWork3->*pDown)(); // 다음 Down값으로 이동
						}
						pWork2 = (pWork2->*pOut)(); // 다음 Out값으로 이동
					}
				}
			}
			else if (r > 0) { //r > 0일 때는 Row값에 ROLLUP을 수행할 값이 있는 경우
				for (int i = 0; i < r - 1; i++) { // Row값이므로 Out쪽으로 이동
					pWork1 = (pWork1->*pOut)();
				}
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < start + end; i++) { // 계층의 자매 노드의 개수만큼 반복문 실행
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pOut)(); // pWork는 다음 Row 값
							pWork3->setData(pWork3->getData() + pWork4->getData()); // 삭제할 데이터와 기준데이터를 합침
							(pWork3->*setOut)((pWork4->*pOut)()); // 기준값의 다음 out값의 삭제할 값을 삭제할 값의 out값으로 변경
							if ((pWork4->*pOut)()) { // 더 이상 ROLLUP할 노드가 없을 떄 (Cube의 맨 끝값이 기준값일경우)
								((pWork4->*pOut)()->*setIn)(pWork3);
							}
							delete pWork4; // 큐브를 삭제
							pWork3 = (pWork3->*pRight)(); // 다음 Right값으로 이동
						}
						pWork2 = (pWork2->*pDown)(); // 다음 Down값으로 이동
					}
				}
			}
			pTemp->setData(pTemp->getData()->getUp()); // 데이터를 윗 계층의 값으로 변경시킨다.
			cube_1D* pTemp_next = pTemp->getNext();
			for (int i = 0; i < start + end; i++) { // Cube_1D의 데이터도 삭제하기 위해서 반복문을 돌림
				pTemp->setNext(pTemp_next->getNext()); // next포인터를 삭제할 값의 다음 값으로 설정
				delete pTemp_next; // cube_1D의 데이터를 삭제
				pTemp_next = pTemp->getNext(); // 다음값으로 이동
				if (pTemp_next == nullptr) { // 다음값이 더이상없을 때
					pTemp->setNext(nullptr); // null포인터로 초기화
					break; // 반복문 종료
				}
				pTemp_next->setPrev(pTemp); //이전값도 설정
			}
		}
	}
	else { // 값을 찾지 못했을 때 false를 반환
		return false;
	}
	if (low_number == 1) { // 계층이 1계층일 때 3계층의 값들이 있으면 합치기 위해서 조건문설정
		node* pWork1 = pHead;
		node* pWork2 = pWork1;
		node* pWork3 = pWork1;
		node* pWork4 = pWork1;
		while (pTemp->getPrev()) { // 제일 앞의 값으로 이동
			pTemp = pTemp->getPrev();
		}
		cnt = 0;
		while (pTemp->getNext()) {
			cnt++; // 총 몇개의 노드가 있는지 count
			pTemp = pTemp->getNext();
		}
		while (pTemp->getPrev()) { // 다시 처음 값으로 이동
			pTemp = pTemp->getPrev();
		}
		if (h > 0) { // h >0 일 때 기준값이 Height에 있으므로 Height기준으로 값 삭제와 덧셈을 실행
			for (int i = 0; i < cnt; i++) { // 처음부터 끝까지 실행
				pWork2 = pWork1;
				while (pWork2) {
					pWork3 = pWork2;
					while (pWork3) {
						pWork4 = (pWork3->*pDown)(); // Height이므로 Down으로 이동
						pWork3->setData(pWork3->getData() + pWork4->getData()); // Data값을 덧셈
						(pWork3->*setDown)((pWork4->*pDown)()); // 기준값의 Down을 새로 삭제할 값의 Down으로 설정
						if ((pWork4->*pDown)()) { // 만약 더 이상 값이 없는경우
							((pWork4->*pDown)()->*setUp)(pWork3);
						}
						delete pWork4; // 값을 삭제해준다
						pWork3 = (pWork3->*pRight)(); // 다음 right값으로 이동
					}
					pWork2 = (pWork2->*pOut)(); // 다음 out값으로 이동
				}
			}
		}
		else if (c > 0) { //  c> 0 일 때 기준값이 Column에 있으므로 Column기준으로 값 삭제 와 덧셈을 실행
			for (int i = 0; i < cnt; i++) { // 처음부터 끝까지 실행
				pWork2 = pWork1;
				while (pWork2) {
					pWork3 = pWork2;
					while (pWork3) {
						pWork4 = (pWork3->*pRight)(); // Column이므로 Right로이동
						pWork3->setData(pWork3->getData() + pWork4->getData()); // Data값을 덧셈
						(pWork3->*setRight)((pWork4->*pRight)()); // 기존값의 Right를 삭제할 값의 right로 설정
						if ((pWork4->*pRight)()) { // 더이상 다음 값이 없는 경우
							((pWork4->*pRight)()->*setLeft)(pWork3);
						}
						delete pWork4; // 큐브 삭제
						pWork3 = (pWork3->*pDown)(); // 다음 down값으로 이동
					}
					pWork2 = (pWork2->*pOut)(); // 다음 out값으로 이동
				}
			}
		}
		else if (r > 0) { //r>0일 때 기준값이 row에 있으므로  row기준으로 값 삭제와 덧셈을 실행
			for (int i = 0; i < cnt;i++) { // 처음부터 끝까지 실행
				pWork2 = pWork1;
				while (pWork2) {
					pWork3 = pWork2;
					while (pWork3) {
						pWork4 = (pWork3->*pOut)(); // Row이므로 Out으로 이동
						pWork3->setData(pWork3->getData() + pWork4->getData()); // Data값을 덧셈
						(pWork3->*setOut)((pWork4->*pOut)()); // 기존값이 Out을 삭제할 값의 Out으로 설정
						if ((pWork4->*pOut)()) { // 더 이상 다음 값이 없는 경우
							((pWork4->*pOut)()->*setIn)(pWork3);
						}
						delete pWork4; // 큐브 값을 삭제
						pWork3 = (pWork3->*pRight)(); // 다음 Right값으로 이동
					}
					pWork2 = (pWork2->*pDown)(); // 다음 Down값으로 이동
				}
			}
		}
		cube_1D* pTemp_next = pTemp->getNext();
		for (int i = 0; i < cnt; i++) { // Cube_1D의 값을 삭제
			pTemp->setNext(pTemp_next->getNext()); // 삭제할 값의 다음 값을 기준값의 다음 값으로 설정
			delete pTemp_next; // Cube_1D값 삭제
			pTemp_next = pTemp->getNext(); // 다음값으로 이동
			if (pTemp_next == nullptr) { // 끝값으로 와서 nullptr일 때 다음 값을 nullptr로 설정 후 반복문 종료
				pTemp->setNext(nullptr);
				break;
			}
			pTemp_next->setPrev(pTemp); // 다음값의 이전값을 설정
		}
		tree_node* temp_tree = pTemp->getData();
		while (temp_tree->getUp()) { // root노드를 방문하기 위해 계속 up방향으로 이동
			temp_tree = temp_tree->getUp();
		}
		pTemp->setData(temp_tree); // 1계층 이므로 값을 root노드의 값으로 설정
	}
	return true; // true 반환
}

void cube::delete_cube() { // cube를 삭제하는 매소드
	node* pWork1 = pHead;
	node* pWork2 = pHead;
	node* pWork3 = pHead;
	node* pWork4 = pHead;
	while (pWork1) { // Row값을 이동
		pWork2 = pWork1;
		pWork1 = (pWork1->*pOut)(); // 다음값으로
		while (pWork2) { // Height값으로 이동
			pWork3 = pWork2;
			pWork2 = (pWork2->*pDown)(); // 다음값으로 이동
			while (pWork3) { // Column값으로 이동 후 삭제
				pWork4 = pWork3;
				pWork3 = (pWork3->*pRight)();
				delete pWork4;
			}
		}
	}
	cube_1D* pTemp = Row;
	while (pTemp) { // cube_1D의 Row값을 삭제
		Row = Row->getNext();
		delete pTemp;
		pTemp = Row;
	}
	pTemp = Column;
	while (pTemp) { // cube_1D의 Column값을 살제
		Column = Column->getNext();
		delete pTemp;
		pTemp = Column;
	}
	pTemp = Height;
	while (pTemp) { // cube_1D의 Height값을 삭제
		Height = Height->getNext();
		delete pTemp;
		pTemp = Height;
	}
	Row = nullptr;
	Column = nullptr;
	Height = nullptr;
	pHead = nullptr;
	pRight = &node::getCnext; // 함수포인터 값 초기화
	pLeft = &node::getCprev;// 함수포인터 값 초기화 
	pUp = &node::getHprev;// 함수포인터 값 초기화 
	pDown = &node::getHnext;// 함수포인터 값 초기화 
	pIn = &node::getRprev;// 함수포인터 값 초기화 
	pOut = &node::getRnext;// 함수포인터 값 초기화 
	setRight = &node::setCnext;// 함수포인터 값 초기화 
	setLeft = &node::setCprev;// 함수포인터 값 초기화 
	setUp = &node::setHprev;// 함수포인터 값 초기화 
	setDown = &node::setHnext;// 함수포인터 값 초기화 
	setIn = &node::setRprev;// 함수포인터 값 초기화 
	setOut = &node::setRnext;// 함수포인터 값 초기화

	pRow = &cube::getRow;// 함수포인터 값 초기화 
	pColumn = &cube::getColumn;// 함수포인터 값 초기화 
	pHeight = &cube::getHeight;// 함수포인터 값 초기화 
	pRow_set = &cube::setRow;// 함수포인터 값 초기화 
	pColumn_set = &cube::setColumn;// 함수포인터 값 초기화 
	pHeight_set = &cube::setHeight;// 함수포인터 값 초기화 
}

bool cube::slice(char* command) { //slice하는 매소드
	bool find = false;
	int h = 0;
	int r = 0;
	int c = 0;
	int cnt = 0;
	int end = 0;
	int start = 0;
	cube_1D* pTemp = (this->*pRow)();
	while (!find) { // slice하고 싶은 값을 찾기 위한 과정
		while (pTemp) { // Row를 순회하면서 같은 값이 있는지 확인
			if (strcmp(pTemp->getData()->getData(), command) == 0) {
				cnt++;
				r = cnt;
				find = true;
				break; // 같은값 찾으면 반복문 종료
			}
			pTemp = pTemp->getNext(); // 다음값으로 이동
			cnt++;
		}
		if (find) // 값을 찾았을 때 반복문 종료
			break;
		pTemp = (this->*pColumn)();
		cnt = 0;
		while (pTemp) { // Column에서 값을 찾는 반복문
			if (strcmp(pTemp->getData()->getData(), command) == 0) {
				cnt++;
				c = cnt;
				find = true;
				break; // 값을 찾았을 때 반복문종료
			}
			pTemp = pTemp->getNext(); // 다음 값으로 이동
			cnt++;
		}
		if (find)// 값을 찾았을 때 반복문 종료
			break;
		pTemp = (this->*pHeight)();
		cnt = 0;
		while (pTemp) { // Height에서 값을 찾는 반복문
			if (strcmp(pTemp->getData()->getData(), command) == 0) {
				cnt++;
				h = cnt;
				find = true;
				break; //찾았으면 반복문 종료
			}
			pTemp = pTemp->getNext(); // 다음값으로 이동
			cnt++;
		}
		break; //반복문 종료
	}
	if (find == true) { // 값을 찾았을 때
		if (!pTemp->getData()->getUp()) { // 1계층일때는 slice를 굳이 할 필요가 없으므로 true반환
			return true;
		}
		else {
			cube_1D* pCount = pTemp->getNext(); // Count를 하기 위한 값 할당
			node* pWork1 = pHead;
			while (pCount) { // end까지의 값을 count
				end++;
				pCount = pCount->getNext();
			}
			pCount = pTemp->getPrev(); // start까지의 값을 count하기 위해 할당
			while (pCount) { // start까지의 값을 count
				start++;
				pCount = pCount->getPrev(); // 이전값으로 계속 이동
			}
			pWork1 = pHead;
			if (h > 0) { // 값이 Height에 있을 때
				node* Copy_Work1 = pWork1; // 값을 한번더 쓰기 위해서 복사 해놓음
				for (int i = 0; i < h - 1; i++) { // Head를 Height이기 때문에 Down으로 이동
					Copy_Work1 = (Copy_Work1->*pDown)();
				}
				pHead = Copy_Work1;
				pWork1 = Copy_Work1;
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < end; i++) { // 기준값에서 끝값까지 삭제
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pDown)(); // 기준값의 Down값으로 이동
							(pWork3->*setDown)((pWork4->*pDown)()); //삭제할 값의 다음 값으로 기준 값의 다음값을 설정
							if ((pWork4->*pDown)()) { // 더이상 Down값이 없을 경우
								((pWork4->*pDown)()->*setUp)(pWork3);
							}
							delete pWork4; // 큐브 삭제
							pWork3 = (pWork3->*pRight)(); // 다음 right로 이동
						}
						pWork2 = (pWork2->*pOut)(); // 다음 Out으로 이동
					}
				}
				pWork1 = Copy_Work1;
				pWork2 = pWork1;
				pWork3 = pWork1;
				pWork4 = pWork1;
				for (int i = 0; i < start; i++) { // 기준 값에서 start값까지 삭제 
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pUp)(); // 다음 up값으로 이동
							(pWork3->*setUp)((pWork4->*pUp)()); // 삭제할 값의 이전 값으로 이전ㄱ밧을 설정
							if ((pWork4->*pUp)()) { // 더이상 up값이 없을 경우
								((pWork4->*pUp)()->*setDown)(pWork3);
							}
							delete pWork4; // 큐브 삭제
							pWork3 = (pWork3->*pRight)(); // 다음 right값으로 이동
						}
						pWork2 = (pWork2->*pOut)(); // 다음 out값으로 이동
					}
				}
			}
			else if (c > 0) { // 값이 column에 있을 때 Height와 같이 실행
				node* Copy_Work1 = pHead;
				for (int i = 0; i < c - 1; i++) { // head이동
					Copy_Work1 = (Copy_Work1->*pRight)();
				}
				pHead = Copy_Work1;
				pWork1 = Copy_Work1;
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < end; i++) { //end값 까지 이동
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pRight)(); // 다음 right 값을 설정
							(pWork3->*setRight)((pWork4->*pRight)()); // 삭제할 값의 다음 값으로 다음 값을 설정
							if ((pWork4->*pRight)()) { // 더이상 right값이 없을 경우
								((pWork4->*pRight)()->*setLeft)(pWork3);
							}
							delete pWork4; // 큐브 삭제
							pWork3 = (pWork3->*pDown)(); // Down으로 이동
						}
						pWork2 = (pWork2->*pOut)(); // 다음 Out으로 이동
					}
				}
				pWork1 = Copy_Work1;
				pWork2 = pWork1;
				pWork3 = pWork1;
				pWork4 = pWork1;
				for (int i = 0; i < start; i++) { // start값까지 이동 이동
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pLeft)(); // 다음 left 값을 설정
							(pWork3->*setLeft)((pWork4->*pLeft)()); // 삭제 할 값의 다음 값을 기존값의 다음값으로 설정
							if ((pWork4->*pLeft)()) { // left값이 없을 경우
								((pWork4->*pLeft)()->*setRight)(pWork3);
							}
							delete pWork4; // 큐브를 삭제
							pWork3 = (pWork3->*pDown)(); // 다음 down으로 이동
						}
						pWork2 = (pWork2->*pOut)(); // 다음 out으로 이동
					}
				}
			}
			else if (r > 0) { // 값이 column에 있을 때
				node* Copy_Work1 = pHead;
				for (int i = 0; i < r - 1; i++) { // head으로 이동
					Copy_Work1 = (Copy_Work1->*pOut)();
				}
				pHead = Copy_Work1;
				pWork1 = Copy_Work1;
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < end; i++) { // end값 까지 삭제
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pOut)(); // 다음 out 값을 설정
							(pWork3->*setOut)((pWork4->*pOut)()); // 삭제할 값의 다음 값을 기존 값의 다음 값으로 설정
							if ((pWork4->*pOut)()) { // out값이 없을 경우
								((pWork4->*pOut)()->*setIn)(pWork3);
							}
							delete pWork4; //큐브를 삭제
							pWork3 = (pWork3->*pRight)(); // 다음 right값으로 이동
						}
						pWork2 = (pWork2->*pDown)(); // 다음 Down값으로 이동
					}
				}
				pWork1 = Copy_Work1;
				pWork2 = pWork1;
				pWork3 = pWork1;
				pWork4 = pWork1;
				for (int i = 0; i < start; i++) { // start값 까지 삭제
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pIn)(); // 다음 In값을 설정
							(pWork3->*setIn)((pWork4->*pIn)()); // 삭제할 값의 이전 값을 기존 값의 이전 값으로 설정
							if ((pWork4->*pIn)()) { // in값이 없을 경우
								((pWork4->*pIn)()->*setOut)(pWork3);
							}
							delete pWork4; // 큐브를 삭제
							pWork3 = (pWork3->*pRight)(); // 다음 Right값으로 이동
						}
						pWork2 = (pWork2->*pDown)(); // 다음 down값으로 이동
					}
				}

			}
			cube_1D* pTemp_next = pTemp->getNext();
			cube_1D* pTemp_prev = pTemp->getPrev();
			for (int i = 0; i < end; i++) { // end까지의 cube_1D의 값을 삭제
				pTemp->setNext(pTemp_next->getNext()); // 삭제할 값의 다음 값을 기존 값의 다음 값으로 설정
				delete pTemp_next; // cube_1D값을 삭제
				pTemp_next = pTemp->getNext(); // 다음 값으로 이동
				if (pTemp_next == nullptr) { // 다음값이 없을 경우
					pTemp->setNext(nullptr); // nullptr로 설정
					break; // 반복문 종료
				}
				pTemp_next->setPrev(pTemp); // 이전값설정
			}
			for (int i = 0; i < start; i++) { // start값 까지 이동
				pTemp->setPrev(pTemp_prev->getPrev()); // 삭제할 값의 이전 값을 기존 값의 이전 값으로 설정
				delete pTemp_prev; // cube_1D값을 삭제
				pTemp_prev = pTemp->getPrev(); // 이전값으로 이동
				if (pTemp_prev == nullptr) { // 이전값이 없는 경우
					pTemp->setPrev(nullptr); // nullptr로 설정
					break; // 반복문설정
				}
			}
			if (h > 0) { // head값을 다시 설정해주는 조건문
				(this->*pHeight_set)(pTemp);
			}
			else if (c > 0) {
				(this->*pColumn_set)(pTemp);
			}
			else if (r > 0) {
				(this->*pRow_set)(pTemp);
			}
		}
	}
	else { //값이 없을 경우 false를 return
		return false;
	}

}

/*(bool cube::DrillDown(char* command ) {
	//조교님 사랑합니다...
}*/

void cube::WriteError(char* command) { // 에러 log를 남기는 매소드
	ofstream log;
	log.open("log.txt", ios::app); // log.txt파일을 연다
	log << "[" << command << "]" << endl; // 값저장
	log << "ERROR" << '\n' << '\n';
	log.close(); // 파일닫기
}