#include "board1D.h"

board::board() {
	pHead = nullptr; // pHead를 초기화
	pTail = nullptr; // pTail을 초기화
	pCenter = nullptr; // pCenter를 초기화
}

board::~board() { // board의 소멸자
	pTail->setNext(nullptr); // pTail의 다음값을 null로 초기화 (circle이기 때문에)
	block* pTemp = pHead; // pTemp의 값은 pHead를 가리킴
	while (pTemp) { // pTemp가 nullptr일 때 
		pHead = pHead->getNext(); //pHead의 값은 다음값으로 
		delete pTemp; // pTemp의 값 동적할당 해제
		pTemp = pHead; // pTemp의 값을 pHead로
	}
	pHead = nullptr; // pHead의 값 초기화
	pTail = nullptr; // pTail의 값 초기화
}

block* board::getHead() {
	return pHead; // pHead의 값을 반환하는 매소드
}
block* board::getTail() {
	return pTail;// pTail의 값을 반환하는 매소드
}
block* board::getCenter() {
	return pCenter;// pCenter의 값을 반환하는 매소드
}

void board::setHead(block* pTemp) {
	pHead = pTemp; // pHead의 값을 반환하는 매소드
}
void board::setTail(block* pTemp) {
	pTail = pTemp;// pHead의 값을 반환하는 매소드
}
void board::setCenter(block* pTemp) {
	pCenter = pTemp;// pHead의 값을 반환하는 매소드
}

void board::Insert() { 
	if (!pHead) { // pHead의 값이 비어있을 때
		block* pNew = new block; // pNew는 새로운 block객체 생성
		pHead = pNew;; // pHead가 비어있으므로 pNew로 설정
		pTail = pNew; // pTail도 비어있으므로 pNew로 설정
	}
	else {
		block* pNew = new block; // pNew는 새로운 block객체 생성
		pNew->setPrev(pTail); // 새로운 객체 pNew의 이전값은 pTail을 가리킴
		pTail->setNext(pNew); // pTail의 다음 값은 pNew를 가리킴
		pTail = pNew; // pTail은 pNew로 설정
	}
}

void board::Print_Check(block* pTemp) { // Block에 말이 있는지 없는지 체크하고 출력하는 매소드
	if (!pTemp->getOn()) {  // 만약 말이 없으면 ㅇ 를출력 
		std::cout << "ㅇ"; 
	}
	else {
		std::cout << pTemp->getOn()->getName(); // 말이 있으면 그 말의 이름을 출력
	}
}

int board::Check_center(block* pTemp1, block* pTemp2) { // 각 short_cut의 가운데 값은 노드가 두개이므로 판단해주기 위한 매소드
	bool temp1; // short_cut1를 판단하는 매소드
	bool temp2; // short_cut2를 판단하는 매소드
	if (!pTemp1->getOn()) { //만약 short_cut1의 가운데가 비어있을 때
		temp1 = false; // false저장
	}
	else {
		temp1 = true; // true저장
	}
	if (!pTemp2->getOn()) { // 만약 short_cut2의 가운데가 비어있을 때 
		temp2 = false; // false저장
	}
	else {
		temp2 = true; // true저장
	}
	if (temp1 == true && temp2 == true) { //temp1 , temp2모두 자리에 있을 떄는
		return 3; //  3을 반환
	}
	else if (temp1 == true) { // temp1만 true일 때
		return 1; // 1을 반환
	}
	else if (temp2 == true) { // temp2만 true일 때
		return 2; //  2을 반환
	}
	else {
		return 0; // 0을 반환
	}
}

void board::Print(board* short1, board* short2) { //board를 print하는 매소드
	block* pTemp = short2->getHead()->getPrev(); //첫번째 지름길로 가는 길을 가리킴
	block* pTemp1 = short1->getHead()->getPrev()->getPrev(); //처음 시작에서 윷이 나왔을 때의 길을 가리킴
	block* pShort1 = short1->getHead(); //첫번째 지름길의 haed를 가리킴 
	block* pShort2 = short2->getHead(); //두번쨰 지름길의 haed를 가리킴
	for (int i = 0; i < 6; i++) { // 맨 윗줄을 출력
		if (i == 3)
			std::cout.width(10); // 가운데의 띄어쓰기
		Print_Check(pTemp); // 말이있는지 없는지 확인후 출력
		std::cout.width(5);
		pTemp = pTemp->getPrev(); // 이전값을 출력 (Board라는 객체의 10번째 값부터 5번째 값까지출력)
	}
	std::cout << '\n' << '\n'; 
	pTemp = pShort2->getPrev()->getNext(); //pTemp의 값을 Board객체의 11번째 값으로 설정
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (j == 0) {
				Print_Check(pTemp); // block에 값이 있는지 확인 후 출력(Board객체 기준11부터 12까지)
				pTemp = pTemp->getNext(); // pTemp는 다음 값으로
				if (i == 0)
					std::cout.width(5);
				else -
					std::cout.width(10);
			}
			else if (j == 1) {
				Print_Check(pShort2); // block에 값이 있는지 확인 후 출력 (Board_shortcut2 list기준 pHead부터 그 다음값 까지)
				pShort2 = pShort2->getNext(); // pShort2는 다음 값으로 
				if (i == 0)
					std::cout.width(20);
				else
					std::cout.width(10);
			}
			else if (j == 2) {
				Print_Check(pShort1); // block에 값이 있는지 확인 후 출력(Board_shortcut1 list기준 pHead부터 그 다음값 까지)
				pShort1 = pShort1->getNext(); // pShort1의 값은 다음으로 
				if (i == 0)
					std::cout.width(5);
				else
					std::cout.width(10);
			}
			else {
				Print_Check(pTemp1); // block에 값이 있는지 확인 후 출력(Board기준 4(윷자리) , 3(걸자리)출력)
				pTemp1 = pTemp1->getPrev(); // pTemp1는 이전값으로

			}
		}
		std::cout << '\n' << '\n';
	}
	std::cout.width(15);
	int num = Check_center(pShort1, pShort2); // Check_center center의 값을 확인하는 매소드 호출
	if (num == 1) 
		Print_Check(pShort1); // pShort1의 센터에만 값이 있는 상황이므로 pShort1의 센터출력
	else if (num == 2)
		Print_Check(pShort2); // pShort2의 센터에만 값이 있는 상황이므로 pShort2의 센터출력
	else {
		Print_Check(pShort1); // pShort1, pShort2둘다 값이 없으므로 아무값이나 출력
	}
	pShort1 = pShort1->getNext(); // pShort1의 밑의값을 출력하기 위해서 다음값으로
	pShort2 = pShort2->getNext(); // pShort2의 밑의값을 출력하기 위해서 다음값으로
	std::cout << '\n' << '\n';

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (j == 0) {
				Print_Check(pTemp); // Board list 기준에서 Board(13,14)번쨰 값을 출력 
				pTemp = pTemp->getNext(); // pTemp값은 다음 값으로 
				if (i == 1)
					std::cout.width(5); 
				else
					std::cout.width(10);
			}
			else if (j == 1) {
				Print_Check(pShort1); // pShort1의 값을 Center 다음부터 pTail까지 출력
				pShort1 = pShort1->getNext(); // pShort1의 값을 다음값으로 
				if (i == 1)
					std::cout.width(20);
				else
					std::cout.width(10);
			}
			else if (j == 2) {
				Print_Check(pShort2); // pSHort2의 값을 Center의 다음부터 pTail까지 출력
				pShort2 = pShort2->getNext(); // pShort2는 pShort2의 다음값으로
				if (i == 1)
					std::cout.width(5);
				else
					std::cout.width(10);
			}
			else {
				Print_Check(pTemp1); // pTemp1은 Board 기준으로 2 , 1의 값으로
				pTemp1 = pTemp1->getPrev(); // pTemp는 pTemp의 이전값으로

			}
		}
		std::cout << '\n' << '\n';
	}

	for (int i = 0; i < 6; i++) {
		if (i == 3)
			std::cout.width(10);
		Print_Check(pTemp); // Board list기준으로 (15~부터 pHead까지 출력)
		std::cout.width(5);
		pTemp = pTemp->getNext(); //pTemp는 pTemp의 다음값으로
	}
	std::cout << '\n' << '\n';
}