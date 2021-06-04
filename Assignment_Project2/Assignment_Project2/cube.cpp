#include "cube.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

cube::cube() {
	pHead = nullptr;
	Row = nullptr;
	Column = nullptr;
	Height = nullptr;
}

cube::~cube() {
}

cube_1D* cube::getRow() {
	return Row;
}
cube_1D* cube::getColumn() {
	return Column;
}
cube_1D* cube::getHeight() {
	return Height;
}
node* cube::getHead() {
	return pHead;
}

void cube::setRow(cube_1D* pTemp) {
	Row = pTemp;
}
void cube::setColumn(cube_1D* pTemp) {
	Column = pTemp;
}
void cube::setHeight(cube_1D* pTemp) {
	Height = pTemp;
}
void cube::setHead(node* pTemp) {
	pHead = pTemp;
}

void cube::Make_tree(tree* Time, tree* Location, tree* Product, int number) { // 트리를 만드는 매소드
	tree_node* pTemp = Time->getRoot(); // time부터 트리생성
	tree_node* pParent = pTemp;
	for (int i = 1; i < number; i++) { // time의 입력한 계층만큼 밑으로 내려감
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
	for (int i = 1; i < number; i++) {
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
	for (int i = 1; i < number; i++) {
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
				pNew->setName(pTemp->getData());
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
	int cnt = 1;
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
				pNew->setData(cnt);
				//cnt++;
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
					pWork2 = pWork2->getCnext(); // 다음 location갑승로
					pWork3 = pWork3->getCnext();
				}
				pWork2 = pWork1->getRprev()->getHnext();
				pWork3 = pWork1->getHnext();
				pWork1 = pWork1->getHnext();
			}
		}
	}
}

void cube::Print() {
	cout.setf(ios::left);
	int R = 0;
	int C = 0;
	int H = 0;
	cube_1D* pTemp = (this->*pRow)();
	while (pTemp) {
		R++;
		pTemp = pTemp->getNext();
	}
	pTemp = (this->*pColumn)();
	while (pTemp) {
		C++;
		pTemp = pTemp->getNext();
	}
	pTemp = (this->*pHeight)();
	while (pTemp) {
		H++;
		pTemp = pTemp->getNext();
	}
	node* pWork1 = pHead;
	node* pWork2 = pHead;
	node* pWork3 = pHead;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < C;k++) {
				cout << pWork3->getData() << '\t';
				pWork3 = (pWork3->*pRight)();
			}
			cout << '\n';
			pWork2 = (pWork2->*pDown)();
			pWork3 = pWork2;
		}
		cout << '\n' << '\n';
		pWork1 = (pWork1->*pOut)();
		pWork2 = pWork1;
		pWork3 = pWork1;
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
	while (tree_down->getNext()) { // hight의 계층을 찾고 원하는 트리노드가 있는 곳까지 이동
		tree_down = tree_down->getNext();
		number++;
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
	while (tree_down->getNext()) {
		tree_down = tree_down->getNext();
		number++;
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
	while (tree_down->getNext()) {
		tree_down = tree_down->getNext();
		number++;
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

void cube::WriteLog(char* command) {//log에 결과값을 작성하는 매소드
	ofstream log;
	log.open("log.txt", ios::app); // log.txt파일을 열고 ios::app방식으로 기존 텍스트에 이어쓴다.
	log << '[' << command << ']' <<'\n';//무슨 커맨드를 작동한 결과인지 결과를 입력한다. 
	log << (this->*pRow)()->getData()->getData() << '\t'; // Row값을 먼저 출력한다.
	cube_1D* pTemp = (this->*pColumn)(); // Column값을 모두 출력한다.
	while (pTemp) {
		log << pTemp->getData()->getData() << '\t';
		pTemp = pTemp->getNext();
	}
	log << '\n';
	pTemp = (this->*pHeight)(); 
	node* pWork1 = pHead;
	node* pWork2 = pWork1;
	while (pWork2) {
		log << pTemp->getData()->getData() << '\t'; // Height의 데이터중 하나를 출력한다/
		pTemp = pTemp->getNext();
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
			pWork3 =pWork2;
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

void cube::Rotate(char* command) {
	node* (node:: * pRight_temp)() = pRight;
	node* (node:: * pLeft_temp)() = pLeft;
	node* (node:: * pUp_temp)() = pUp;
	node* (node:: * pDown_temp)() = pDown;
	node* (node:: * pIn_temp)() = pIn;
	node* (node:: * pOut_temp)() = pOut;
	void (node:: * setRight_temp)(node * pTemp) = setRight;
	void (node:: * setLeft_temp)(node * pTemp) = setLeft;
	void (node:: * setUp_temp)(node * pTemp) = setUp;
	void (node:: * setDown_temp)(node * pTemp) = setDown;
	void (node:: * setIn_temp)(node * pTemp) = setIn;
	void (node:: * setOut_temp)(node * pTemp) = setOut;

	cube_1D* (cube:: * pRow_temp)() = pRow;
	cube_1D* (cube:: * pColumn_temp)() = pColumn;
	cube_1D* (cube:: * pHeight_temp)() = pHeight;
	void (cube:: * pRow_set_temp)(cube_1D * pTemp) = pRow_set;
	void (cube:: * pColumn_set_temp)(cube_1D * pTemp) = pColumn_set;
	void (cube:: * pHeight_set_temp)(cube_1D * pTemp) = pHeight_set;
	if (strcmp(command, "clockwise") == 0) {
		while ((pHead->*pDown)()) {
			pHead = (pHead->*pDown)();
		}
		pRight = pUp_temp;
		setRight = setUp_temp;
		pLeft = pDown_temp;
		setLeft = setDown_temp;
		pDown = pRight_temp;
		setDown = setRight_temp;
		pUp = pLeft_temp;
		setUp = setLeft_temp;
		pHeight = pColumn_temp;
		pColumn = pHeight_temp;
		pHeight_set = pColumn_set_temp;
		pColumn_set = pHeight_set_temp;
		Reverse((this->*pColumn)());
	}
	else if (strcmp(command, "c_clockwise") == 0) {
		while ((pHead->*pRight)()) {
			pHead = (pHead->*pRight)();
		}
		pRight = pDown_temp;
		setRight = setDown_temp;
		pLeft = pUp_temp;
		setLeft = setUp_temp;
		pDown = pLeft_temp;
		setDown = setLeft_temp;
		pUp = pRight_temp;
		setUp = setRight_temp;
		pHeight = pColumn_temp;
		pColumn = pHeight_temp;
		pHeight_set = pColumn_set_temp;
		pColumn_set = pHeight_set_temp;
		Reverse((this->*pHeight)());
	}
	else if (strcmp(command, "left") == 0) {
		while ((pHead->*pRight)()) {
			pHead = (pHead->*pRight)();
		}
		pRight = pOut_temp;
		setRight = setOut_temp;
		pLeft = pIn_temp;
		setLeft = setIn_temp;
		pOut = pLeft_temp;
		setOut = setLeft_temp;
		pIn = pRight_temp;
		setIn = setRight_temp;
		pColumn = pRow_temp;
		pRow = pColumn_temp;
		pColumn_set = pRow_set_temp;
		pRow_set = pColumn_set_temp;
		//Reverse((this->*pColumn)());
	}
	else if (strcmp(command, "right") == 0) {
		while ((pHead->*pOut)()) {
			pHead = (pHead->*pOut)();
		}
		pRight = pIn_temp;
		setRight = setIn_temp;
		pLeft = pOut_temp;
		setLeft = setOut_temp;
		pOut = pRight_temp;
		setOut = setRight_temp;
		pIn = pLeft_temp;
		setIn = setLeft_temp;
		pColumn = pRow_temp;
		pRow = pColumn_temp;
		//Reverse((this->*pColumn)());
	}
	else if (strcmp(command, "up") == 0) {
		while ((pHead->*pDown)()) {
			pHead = (pHead->*pDown)();
		}
		pDown = pOut_temp;
		setDown = setOut_temp;
		pUp = pIn_temp;
		setUp = setIn_temp;
		pOut = pUp_temp;
		setOut = setUp_temp;
		pIn = pDown_temp;
		setIn = setDown_temp;
		pHeight = pRow_temp;
		pRow = pHeight_temp;
		pHeight_set = pRow_set_temp;
		pRow_set = pHeight_set_temp;
		Reverse((this->*pHeight)());
		Reverse((this->*pRow)());
	}
	else if (strcmp(command, "down") == 0) {
		while ((pHead->*pOut)()) {
			pHead = (pHead->*pOut)();
		}
		pDown = pIn_temp;
		setDown = setIn_temp;
		pUp = pOut_temp;
		setUp = setOut_temp;
		pOut = pDown_temp;
		setOut = setDown_temp;
		pIn = pUp_temp;
		setIn = setUp_temp;
		pHeight = pRow_temp;
		pRow = pHeight_temp;
		pHeight_set = pRow_set_temp;
		pRow_set = pHeight_set_temp;
		Reverse((this->*pHeight)());
		Reverse((this->*pRow)());
	}
}

void cube::check() {
	cube_1D* pTemp = (this->*pRow)();
	cout << "Row :";
	while (pTemp) {
		cout << pTemp->getData()->getData() << '\t';
		pTemp = pTemp->getNext();
	}
	cout << '\n';
	pTemp = (this->*pColumn)();
	cout << "pColumn :";
	while (pTemp) {
		cout << pTemp->getData()->getData() << '\t';
		pTemp = pTemp->getNext();
	}
	cout << '\n';
	pTemp = (this->*pHeight)();
	cout << "pHeight :";
	while (pTemp) {
		cout << pTemp->getData()->getData() << '\t';
		pTemp = pTemp->getNext();
	}
	cout << '\n';
}

void cube::Reverse(cube_1D* pCube) {
	cube_1D* pHead = pCube;
	cube_1D* pTemp1 = pHead;
	cube_1D* pPrev = nullptr;
	cube_1D* pNode = pHead;
	int cnt = 0;
	if (!pHead->getNext())
		return;
	while (pNode->getNext()) {
		pNode = pNode->getNext();
		cnt++;
	}
	pTemp1 = pNode;
	while (cnt != 0) {
		pNode = pHead;
		for (int i = 0; i < cnt; i++) {
			pPrev = pNode;
			pNode = pNode->getNext();
		}
		pNode->setNext(pPrev);
		cnt--;
	}
	pPrev->setNext(nullptr);
	pHead->setPrev(nullptr);
	pPrev = pHead->getNext();
	while (pPrev) {
		pPrev->setPrev(pHead);
		pHead = pHead->getNext();
		pPrev = pPrev->getNext();
	}
	if (pCube == Row)
		Row = pTemp1;
	else if (pCube == Column)
		Column = pTemp1;
	else if (pCube == Height)
		Height = pTemp1;
	while (pTemp1) {
		cout << pTemp1->getData()->getData() << '\t';
		pTemp1 = pTemp1->getNext();
	}
}

bool cube::Roll_up(char* command) {
	bool find = false;
	int h = 0;
	int r = 0;
	int c = 0;
	int cnt = 0;
	int end = 0;
	int start = 0;
	int low_number = 0;
	cube_1D* pTemp = (this->*pRow)();
	while (!find) {
		while (pTemp) {
			if (strcmp(pTemp->getData()->getData(), command) == 0) {
				cnt++;
				r = cnt;
				find = true;
				break;
			}
			pTemp = pTemp->getNext();
			cnt++;
		}
		if (find)
			break;
		pTemp = (this->*pColumn)();
		cnt = 0;
		while (pTemp) {
			if (strcmp(pTemp->getData()->getData(), command) == 0) {
				cnt++;
				c = cnt;
				find = true;
				break;
			}
			pTemp = pTemp->getNext();
			cnt++;
		}
		if (find)
			break;
		pTemp = (this->*pHeight)();
		cnt = 0;
		while (pTemp) {
			if (strcmp(pTemp->getData()->getData(), command) == 0) {
				cnt++;
				h = cnt;
				find = true;
				break;
			}
			pTemp = pTemp->getNext();
			cnt++;
		}
		break;
	}
	if (find == true) {
		if (!pTemp->getData()->getUp()) {
			return false;
		}
		else {
			low_number = pTemp->getData()->getLow() - 1;
			tree_node* pCount =pTemp->getData()->getNext();
			node* pWork1 = pHead;
			while (pCount) {
				end++;
				pCount = pCount->getNext();
			}
			pCount = pTemp->getData()->getPrev();
			while (pCount) {
				start++;
				pCount = pCount->getPrev();
			}
			if (!pTemp->getData()->getUp()->getDown()->getNext()) {
				pTemp->setData(pTemp->getData()->getUp());
				return true;
			}
			else if (!pTemp->getNext() && !pTemp->getPrev()) {
				pTemp->setData(pTemp->getData()->getUp());
				return true;
			}
			for (int i = 0; i < start; i++) {
				r--;
				h--;
				c--;
				if (!pTemp->getPrev())
					break;
				pTemp = pTemp->getPrev();
			}
			if (h > 0) {
				for (int i = 0; i < h-1; i++) {
					pWork1 = (pWork1->*pDown)();
				}
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < start+end; i++) {
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pDown)();
							pWork3->setData(pWork3->getData() + pWork4->getData());
							(pWork3->*setDown)((pWork4->*pDown)());
							if ((pWork4->*pDown)()) {
								((pWork4->*pDown)()->*setUp)(pWork3);
							}
							delete pWork4;
							pWork3 = (pWork3->*pRight)();
						}
						pWork2 = (pWork2->*pOut)();
					}
				}
			}
			else if (c > 0) {
				for (int i = 0; i < c-1; i++) {
					pWork1 = (pWork1->*pRight)();
				}
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < start + end; i++) {
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pRight)();
							pWork3->setData(pWork3->getData() + pWork4->getData());
							(pWork3->*setRight)((pWork4->*pRight)());
							if ((pWork4->*pRight)()) {
								((pWork4->*pRight)()->*setLeft)(pWork3);
							}
							delete pWork4;
							pWork3 = (pWork3->*pDown)();
						}
						pWork2 = (pWork2->*pOut)();
					}
				}
			}
			else if (r > 0) {
				for (int i = 0; i < r-1; i++) {
					pWork1 = (pWork1->*pOut)();
				}
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < start + end; i++) {
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pOut)();
							pWork3->setData(pWork3->getData() + pWork4->getData());
							(pWork3->*setOut)((pWork4->*pOut)());
							if ((pWork4->*pOut)()) {
								((pWork4->*pOut)()->*setIn)(pWork3);
							}
							delete pWork4;
							pWork3 = (pWork3->*pRight)();
						}
						pWork2 = (pWork2->*pDown)();
					}
				}
			}
			pTemp->setData(pTemp->getData()->getUp());
			cube_1D* pTemp_next = pTemp->getNext();
			for (int i = 0; i < start + end; i++) {
				pTemp->setNext(pTemp_next->getNext());
				delete pTemp_next;
				pTemp_next = pTemp->getNext();
				if (pTemp_next == nullptr) {
					pTemp->setNext(nullptr);
					break;
				}
				pTemp_next->setPrev(pTemp);
			}
		}
	}
	else {
		return false;
	}
	if (low_number == 1) {
		node* pWork1 = pHead;
		node* pWork2 = pWork1;
		node* pWork3 = pWork1;
		node* pWork4 = pWork1;
		while (pTemp->getPrev()) {
			pTemp = pTemp->getPrev();
		}
		cnt = 0;
		while (pTemp->getNext()) {
			cnt++;
			pTemp = pTemp->getNext();
		}
		while (pTemp->getPrev()) {
			pTemp = pTemp->getPrev();
		}
		if (h > 0) {
			for (int i = 0; i < cnt; i++) {
				pWork2 = pWork1;
				while (pWork2) {
					pWork3 = pWork2;
					while (pWork3) {
						pWork4 = (pWork3->*pDown)();
						pWork3->setData(pWork3->getData() + pWork4->getData());
						(pWork3->*setDown)((pWork4->*pDown)());
						if ((pWork4->*pDown)()) {
							((pWork4->*pDown)()->*setUp)(pWork3);
						}
						delete pWork4;
						pWork3 = (pWork3->*pRight)();
					}
					pWork2 = (pWork2->*pOut)();
				}
			}
		}
		else if (c > 0) {
			for (int i = 0; i < cnt; i++) {
				pWork2 = pWork1;
				while (pWork2) {
					pWork3 = pWork2;
					while (pWork3) {
						pWork4 = (pWork3->*pRight)();
						pWork3->setData(pWork3->getData() + pWork4->getData());
						(pWork3->*setRight)((pWork4->*pRight)());
						if ((pWork4->*pRight)()) {
							((pWork4->*pRight)()->*setLeft)(pWork3);
						}
						delete pWork4;
						pWork3 = (pWork3->*pDown)();
					}
					pWork2 = (pWork2->*pOut)();
				}
			}
		}
		else if (r > 0) {
			for (int i = 0; i < cnt;i++) {
				pWork2 = pWork1;
				while (pWork2) {
					pWork3 = pWork2;
					while (pWork3) {
						pWork4 = (pWork3->*pOut)();
						pWork3->setData(pWork3->getData() + pWork4->getData());
						(pWork3->*setOut)((pWork4->*pOut)());
						if ((pWork4->*pOut)()) {
							((pWork4->*pOut)()->*setIn)(pWork3);
						}
						delete pWork4;
						pWork3 = (pWork3->*pRight)();
					}
					pWork2 = (pWork2->*pDown)();
				}
			}
		}
		cube_1D* pTemp_next = pTemp->getNext();
		for (int i = 0; i < cnt; i++) {
			pTemp->setNext(pTemp_next->getNext());
			delete pTemp_next;
			pTemp_next = pTemp->getNext();
			if (pTemp_next == nullptr) {
				pTemp->setNext(nullptr);
				break;
			}
			pTemp_next->setPrev(pTemp);
		}
		tree_node* temp_tree = pTemp->getData();
		while (temp_tree->getUp()) {
			temp_tree = temp_tree->getUp();
		}
		pTemp->setData(temp_tree);
	}
	return true;
}

void cube::delete_cube() {
	node* pWork1 = pHead;
	node* pWork2 = pHead;
	node* pWork3 = pHead;
	node* pWork4 = pHead;
	while (pWork1) {
		pWork2 = pWork1;
		pWork1 = (pWork1->*pOut)();
		while (pWork2) {
			pWork3 = pWork2;
			pWork2 = (pWork2->*pDown)();
			while (pWork3) {
				pWork4 = pWork3;
				pWork3 = (pWork3->*pRight)();
				delete pWork4;
			}
		}
	}
	cube_1D* pTemp = Row;
	while (pTemp) {
		Row = Row->getNext();
		delete pTemp;
		pTemp = Row;
	}
	pTemp = Column;
	while (pTemp) {
		Column = Column->getNext();
		delete pTemp;
		pTemp = Column;
	}
	pTemp = Height;
	while (pTemp) {
		Height = Height->getNext();
		delete pTemp;
		pTemp = Height;
	}
}

bool cube::slice(char* command) {
	bool find = false;
	int h = 0;
	int r = 0;
	int c = 0;
	int cnt = 0;
	int end = 0;
	int start = 0;
	cube_1D* pTemp = (this->*pRow)();
	while (!find) {
		while (pTemp) {
			if (strcmp(pTemp->getData()->getData(), command) == 0) {
				cnt++;
				r = cnt;
				find = true;
				break;
			}
			pTemp = pTemp->getNext();
			cnt++;
		}
		if (find)
			break;
		pTemp = (this->*pColumn)();
		cnt = 0;
		while (pTemp) {
			if (strcmp(pTemp->getData()->getData(), command) == 0) {
				cnt++;
				c = cnt;
				find = true;
				break;
			}
			pTemp = pTemp->getNext();
			cnt++;
		}
		if (find)
			break;
		pTemp = (this->*pHeight)();
		cnt = 0;
		while (pTemp) {
			if (strcmp(pTemp->getData()->getData(), command) == 0) {
				cnt++;
				h = cnt;
				find = true;
				break;
			}
			pTemp = pTemp->getNext();
			cnt++;
		}
		break;
	}
	if (find == true) {
		if (!pTemp->getData()->getUp()) {
			return false;
		}
		else {
			cube_1D* pCount = pTemp->getNext();
			node* pWork1 = pHead;
			while (pCount) {
				end++;
				pCount = pCount->getNext();
			}
			pCount = pTemp->getPrev();
			while (pCount) {
				start++;
				pCount = pCount->getPrev();
			}
			pWork1 = pHead;
			if (h > 0) {
				node* Copy_Work1 = pWork1;
				for (int i = 0; i < h - 1; i++) {
					Copy_Work1 = (Copy_Work1->*pDown)();
				}
				pHead = Copy_Work1;
				pWork1 = Copy_Work1;
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < end; i++) {
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pDown)();
							(pWork3->*setDown)((pWork4->*pDown)());
							if ((pWork4->*pDown)()) {
								((pWork4->*pDown)()->*setUp)(pWork3);
							}
							delete pWork4;
							pWork3 = (pWork3->*pRight)();
						}
						pWork2 = (pWork2->*pOut)();
					}
				}
				pWork1 = Copy_Work1;
				pWork2 = pWork1;
				pWork3 = pWork1;
				pWork4 = pWork1;
				for (int i = 0; i < start; i++) {
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pUp)();
							(pWork3->*setUp)((pWork4->*pUp)());
							if ((pWork4->*pUp)()) {
								((pWork4->*pUp)()->*setDown)(pWork3);
							}
							delete pWork4;
							pWork3 = (pWork3->*pRight)();
						}
						pWork2 = (pWork2->*pOut)();
					}
				}
			}
			else if (c > 0) {
				node* Copy_Work1 = pHead;
				for (int i = 0; i < c - 1; i++) {
					Copy_Work1 = (Copy_Work1->*pRight)();
				}
				pHead = Copy_Work1;
				pWork1 = Copy_Work1;
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < end; i++) {
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pRight)();
							(pWork3->*setRight)((pWork4->*pRight)());
							if ((pWork4->*pRight)()) {
								((pWork4->*pRight)()->*setLeft)(pWork3);
							}
							delete pWork4;
							pWork3 = (pWork3->*pDown)();
						}
						pWork2 = (pWork2->*pOut)();
					}
				}
				pWork1 = Copy_Work1;
				pWork2 = pWork1;
				pWork3 = pWork1;
				pWork4 = pWork1;
				for (int i = 0; i < start; i++) {
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pLeft)();
							(pWork3->*setLeft)((pWork4->*pLeft)());
							if ((pWork4->*pLeft)()) {
								((pWork4->*pLeft)()->*setRight)(pWork3);
							}
							delete pWork4;
							pWork3 = (pWork3->*pDown)();
						}
						pWork2 = (pWork2->*pOut)();
					}
				}
			}
			else if (r > 0) {
				node* Copy_Work1 = pHead;
				for (int i = 0; i < r - 1; i++) {
					Copy_Work1 = (Copy_Work1->*pOut)();
				}
				pHead = Copy_Work1;
				pWork1 = Copy_Work1;
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < end; i++) {
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pOut)();
							(pWork3->*setOut)((pWork4->*pOut)());
							if ((pWork4->*pOut)()) {
								((pWork4->*pOut)()->*setIn)(pWork3);
							}
							delete pWork4;
							pWork3 = (pWork3->*pRight)();
						}
						pWork2 = (pWork2->*pDown)();
					}
				}
				pWork1 = Copy_Work1;
				pWork2 = pWork1;
				pWork3 = pWork1;
				pWork4 = pWork1;
				for (int i = 0; i < start; i++) {
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pIn)();
							(pWork3->*setIn)((pWork4->*pIn)());
							if ((pWork4->*pIn)()) {
								((pWork4->*pIn)()->*setOut)(pWork3);
							}
							delete pWork4;
							pWork3 = (pWork3->*pRight)();
						}
						pWork2 = (pWork2->*pDown)();
					}
				}

			}
			cube_1D* pTemp_next = pTemp->getNext();
			cube_1D* pTemp_prev = pTemp->getPrev();
			for (int i = 0; i < end; i++) {
				pTemp->setNext(pTemp_next->getNext());
				delete pTemp_next;
				pTemp_next = pTemp->getNext();
				if (pTemp_next == nullptr) {
					pTemp->setNext(nullptr);
					break;
				}
				pTemp_next->setPrev(pTemp);
			}
			for (int i = 0; i < start; i++) {
				pTemp->setPrev(pTemp_prev->getPrev());
				delete pTemp_prev;
				pTemp_prev = pTemp->getPrev();
				if (pTemp_prev == nullptr) {
					pTemp->setPrev(nullptr);
					break;
				}
			}
			if (h > 0) {
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
	else {
		return false;
	}

}

/*bool cube::DrillDown(char* command,cube* raw) {
	bool find = false;
	int h = 0;
	int r = 0;
	int c = 0;
	int cnt = 0;
	int raw_cnt = 0;
	int tree_end = 0;
	int low_number = 0;
	cube_1D* pTemp = (this->*pRow)();
	while (!find) {
		while (pTemp) {
			if (strcmp(pTemp->getData()->getData(), command) == 0) {
				cnt++;
				r = cnt;
				find = true;
				break;
			}
			pTemp = pTemp->getNext();
			cnt++;
		}
		if (find)
			break;
		pTemp = (this->*pColumn)();
		cnt = 0;
		while (pTemp) {
			if (strcmp(pTemp->getData()->getData(), command) == 0) {
				cnt++;
				c = cnt;
				find = true;
				break;
			}
			pTemp = pTemp->getNext();
			cnt++;
		}
		if (find)
			break;
		pTemp = (this->*pHeight)();
		cnt = 0;
		while (pTemp) {
			if (strcmp(pTemp->getData()->getData(), command) == 0) {
				cnt++;
				h = cnt;
				find = true;
				break;
			}
			pTemp = pTemp->getNext();
			cnt++;
		}
		break;
	}
	if (find == true) {
		if (!pTemp->getData()->getDown()) {
			return false;
		}
		else {
			low_number = pTemp->getData()->getLow();
			node* pWork1 = pHead;
			if (low_number == 2) {
				tree_node* pCount = pTemp->getData()->getDown();
				while (pCount->getNext()) {
					tree_end++;
					pCount = pCount->getNext();
				}
				pCount = pTemp->getData()->getDown();
				node* pWork_Copy = raw->getHead();
				node* pWork1 = pHead;
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				if (h > 0) {
					cube_1D* raw_tree = (raw->*pHeight)();
					while (pWork_Copy) {
						if (strcmp(raw_tree->getData()->getData(), pCount->getData()) == 0)
							break;
						pWork_Copy = (pWork_Copy->*pDown)();
					}
					for (int i = 0; i < h - 1; i++) {
						pWork1 = (pWork1->*pDown)();
					}
					for (int i = 0; i < tree_end; i++) {
						
					}
				}
				else if (c > 0) {

				}
				else if (r > 0) {

				}
			}
			while (pCount) {
				end++;
				pCount = pCount->getNext();
			}
			pCount = pTemp->getData()->getPrev();
			while (pCount) {
				start++;
				pCount = pCount->getPrev();
			}
			if (!pTemp->getData()->getUp()->getDown()->getNext()) {
				pTemp->setData(pTemp->getData()->getUp());
				return true;
			}
			for (int i = 0; i < start; i++) {
				pTemp = pTemp->getPrev();
				r--;
				h--;
				c--;
			}
			if (h > 0) {
				for (int i = 0; i < h - 1; i++) {
					pWork1 = (pWork1->*pDown)();
				}
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < start + end; i++) {
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pDown)();
							pWork3->setData(pWork3->getData() + pWork4->getData());
							(pWork3->*setDown)((pWork4->*pDown)());
							if ((pWork4->*pDown)()) {
								((pWork4->*pDown)()->*setUp)(pWork3);
							}
							delete pWork4;
							pWork3 = (pWork3->*pRight)();
						}
						pWork2 = (pWork2->*pOut)();
					}
				}
			}
			else if (c > 0) {
				for (int i = 0; i < c - 1; i++) {
					pWork1 = (pWork1->*pRight)();
				}
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < start + end; i++) {
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pRight)();
							pWork3->setData(pWork3->getData() + pWork4->getData());
							(pWork3->*setRight)((pWork4->*pRight)());
							if ((pWork4->*pRight)()) {
								((pWork4->*pRight)()->*setLeft)(pWork3);
							}
							delete pWork4;
							pWork3 = (pWork3->*pDown)();
						}
						pWork2 = (pWork2->*pOut)();
					}
				}
			}
			else if (r > 0) {
				for (int i = 0; i < r - 1; i++) {
					pWork1 = (pWork1->*pOut)();
				}
				node* pWork2 = pWork1;
				node* pWork3 = pWork1;
				node* pWork4 = pWork1;
				for (int i = 0; i < start + end; i++) {
					pWork2 = pWork1;
					while (pWork2) {
						pWork3 = pWork2;
						while (pWork3) {
							pWork4 = (pWork3->*pOut)();
							pWork3->setData(pWork3->getData() + pWork4->getData());
							(pWork3->*setOut)((pWork4->*pOut)());
							if ((pWork4->*pOut)()) {
								((pWork4->*pOut)()->*setIn)(pWork3);
							}
							delete pWork4;
							pWork3 = (pWork3->*pRight)();
						}
						pWork2 = (pWork2->*pDown)();
					}
				}
			}
			pTemp->setData(pTemp->getData()->getUp());
			cube_1D* pTemp_next = pTemp->getNext();
			for (int i = 0; i < start + end; i++) {
				pTemp->setNext(pTemp_next->getNext());
				delete pTemp_next;
				pTemp_next = pTemp->getNext();
				if (pTemp_next == nullptr) {
					pTemp->setNext(nullptr);
					break;
				}
				pTemp_next->setPrev(pTemp);
			}
		}
	}
	else {
		return false;
	}
	return true;
}*/

void cube::WriteError(char* command) {
	ofstream log;
	log.open("log.txt", ios::app);
	log << "[" << command << "]" << endl;
	log << "ERROR" << '\n' << '\n';
	log.close();
}