#include "Yut.h"

yut::yut() {
	pHead = nullptr; //pHead를 초기화
	pTail = nullptr; // pTail을 초기화
}
yut::~yut() {

}

moving* yut::getHead() {
	return pHead; //pHead의 값을 반환하는 매소드
}
moving* yut::getTail() {
	return pTail; // pTail의 값을 반환하는 매소드
}

void yut::setHead(moving* pTemp) {
	pHead = pTemp; // pHead의 값을 변경하는 매소드
}
void yut::setTail(moving* pTemp) {
	pTail = pTemp; // pTail의 값을 변경하는 매소드
}

bool yut::Throw_yut() { //윷을 던지는 매소드
	bool yut_arr[4]; // yut의 값을 정하는 변수
	srand(time(NULL)); // 랜덤 시드를 생성하는 것
	int random_number; // 60프로 확율로 뒷면인지 앞면인지 확인하는 변수
	int count = 0; // 윷의 앞면을 세는 변수
	for (int i = 0; i < 4; i++) {
		random_number = rand() % 10; // 0~3의 값이 나오면 뒷면 4~9까지 값이 나오면 앞면
		if (random_number < 4) {
			yut_arr[i] = false; // 뒷면일 때는 false
		}
		else {
			yut_arr[i] = true; // 앞면일 떄는 true
			count++; // 앞면일 떄의 값의 갯수를 추가
		}
	}
	moving* pNew = new moving; // 윷의값을 생성
	if (!pHead) { // 윷이 처음일 때
		pHead = pNew; // pHead의 값을 새로운 move로 생성
		pTail = pNew; // pTail의 값을 새로운 move로 생성
	}
	else {
		moving* pTemp = pHead; // pHead의 값을 pTemp는 가리킴
		while (pTemp->getNext()) { //제일 끝 위치로 이동
			pTemp = pTemp->getNext(); // pTemp 의 값은 다음 값으로 설정
		}
		pTemp->setNext(pNew); // pTemp의 다음값은 pNew로 설정
		pTemp = pNew; // pTemp 의값을 pNew로 설정
	}
	if (count == 0) { //모두 뒷면일 떄는 모를 저장
		pNew->setStep(5); // 모를 저장
		std::cout << "Result is mo" << '\n'; 
		return true; //한번 더 던지게 하려고 true를 반환
	}
	else if (count == 1) { // 한개만 앞면일 때 도를 출력
		if (yut_arr[0] == true) { // yut의 배열의 제일 첫번째 윷만 앞면일 때 
			pNew->setStep(-1); // 뺵도의 값을 저장
			std::cout << "Result is back do" << '\n';
		}
		else {
			pNew->setStep(1); // 1,2,3 arr일 때 앞면일 때 도를 저장
			std::cout << "Result is do" << '\n';
		}
	}
	else if (count == 2) { // 두개가 앞면일 떄 는 개를 저장
		pNew->setStep(2); // 개의 값을 저장
		std::cout << "Result is gae" << '\n';
	}
	else if (count == 3) { // 세개가 앞면일 때는 걸을 저장
		pNew->setStep(3); // 걸의 값을 저장
		std::cout << "Result is geol" << '\n';
	}
	else if (count == 4) { // 4개가 앞면일 떄는 윷을 저장
		pNew->setStep(4); // 윷의 값을 저장
		std::cout << "Result is yut" << '\n';
		return true; //한번더 던지기 위해서 true값 반환
	}
	return false; // 한번더 던지지 않는 경우는 false를 반환
}

void yut::delete_yut(int num) { // 던진 윷을 삭제하기 위한 매소드
	moving* pTemp = pHead; // pTemp는 pHead를 가리킴
	moving* pPrev = pTemp; // pPrev는 PTemp를 가리킴
	for (int i = 1; i < num; i++) {
		pPrev = pTemp; // pPrev는 Ptemp의 이전값을 가리키기 위해 먼저 pTemp의 값저장
		pTemp = pTemp->getNext(); // pTemp는 Next의 값을 가리킴
	}
	if (pTemp == pHead) { // pTemp가 pHead일 때
		if (!pHead->getNext()) { // pHead만 남아있을 떄
			delete pTemp; // pTemp의 값 삭제
			pHead = nullptr; // pTemp의 값을 초기화
			pTail = nullptr; // pTemp의 값을 초기화
		}
		else {
			pHead = pTemp->getNext(); // pHead의 값은 pTemp의 다음값을 가리킴
			delete pTemp; // pTemp를 삭제
		}
	}
	else {
		if (!pTemp->getNext()) { //pTemp가 마지막값일 때 
			pPrev->setNext(nullptr); // pTemp의 전값은 삭제할 값이므로 nullptr로 초기화
			delete pTemp; // pTemp의 값 삭제
		}
		else {
			pPrev->setNext(pTemp->getNext()); // pTemp가 마지막 값이 아닐경우 이전값음 pTemp의 다음값을 가리킴
			delete pTemp; // pTemp의 값 삭제
		}
	}
}

void yut::print_yut() { // 윷에 저장된 값을 print를 함
	moving* pTemp = pHead; //pTemp는 pHead를 가리킴
	std::cout << "Yut Results: ";
	int count = 1; // 윷의 개수를 카운트 하기위해서 생성한 변수
	while (pTemp) { // pTemp가 빌때 까지 확인
		std::cout << count << ". " << pTemp->getStep(); // pTemp의 값을 가졍ㅁ
		std::cout.width(5); // 단어의 띄어쓰기를 위한 것
		pTemp = pTemp->getNext(); //pTemp는 다음 값을 가리킴
		count++; // count를 했으므로 값을 하나 올림
	}
	std::cout << '\n';
}

void yut::yut_delete_all() { // 모든 윷의 값을 없애기 위한 매소드
	moving* pTemp = pHead; // pTemp는 pHead를 가리킴
	while (pTemp) { // pTemp가 nullptr일 떄까지 반복
		pHead = pHead->getNext(); // pHead는 다음 값을 가리킴
		delete pTemp; //pTemp 동적할당 해제
		pTemp = pHead; // pTemp 의 값은 pHEad
	}
	pHead = nullptr; // pHead의 값 초기화
	pTail = nullptr; // pTail의 값 초기화
}
