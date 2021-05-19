#include "Yut.h"

yut::yut() {
	pHead = nullptr; //pHead�� �ʱ�ȭ
	pTail = nullptr; // pTail�� �ʱ�ȭ
}
yut::~yut() {

}

moving* yut::getHead() {
	return pHead; //pHead�� ���� ��ȯ�ϴ� �żҵ�
}
moving* yut::getTail() {
	return pTail; // pTail�� ���� ��ȯ�ϴ� �żҵ�
}

void yut::setHead(moving* pTemp) {
	pHead = pTemp; // pHead�� ���� �����ϴ� �żҵ�
}
void yut::setTail(moving* pTemp) {
	pTail = pTemp; // pTail�� ���� �����ϴ� �żҵ�
}

bool yut::Throw_yut() { //���� ������ �żҵ�
	bool yut_arr[4]; // yut�� ���� ���ϴ� ����
	srand(time(NULL)); // ���� �õ带 �����ϴ� ��
	int random_number; // 60���� Ȯ���� �޸����� �ո����� Ȯ���ϴ� ����
	int count = 0; // ���� �ո��� ���� ����
	for (int i = 0; i < 4; i++) {
		random_number = rand() % 10; // 0~3�� ���� ������ �޸� 4~9���� ���� ������ �ո�
		if (random_number < 4) {
			yut_arr[i] = false; // �޸��� ���� false
		}
		else {
			yut_arr[i] = true; // �ո��� ���� true
			count++; // �ո��� ���� ���� ������ �߰�
		}
	}
	moving* pNew = new moving; // ���ǰ��� ����
	if (!pHead) { // ���� ó���� ��
		pHead = pNew; // pHead�� ���� ���ο� move�� ����
		pTail = pNew; // pTail�� ���� ���ο� move�� ����
	}
	else {
		moving* pTemp = pHead; // pHead�� ���� pTemp�� ����Ŵ
		while (pTemp->getNext()) { //���� �� ��ġ�� �̵�
			pTemp = pTemp->getNext(); // pTemp �� ���� ���� ������ ����
		}
		pTemp->setNext(pNew); // pTemp�� �������� pNew�� ����
		pTemp = pNew; // pTemp �ǰ��� pNew�� ����
	}
	if (count == 0) { //��� �޸��� ���� �� ����
		pNew->setStep(5); // �� ����
		std::cout << "Result is mo" << '\n'; 
		return true; //�ѹ� �� ������ �Ϸ��� true�� ��ȯ
	}
	else if (count == 1) { // �Ѱ��� �ո��� �� ���� ���
		if (yut_arr[0] == true) { // yut�� �迭�� ���� ù��° ���� �ո��� �� 
			pNew->setStep(-1); // ������ ���� ����
			std::cout << "Result is back do" << '\n';
		}
		else {
			pNew->setStep(1); // 1,2,3 arr�� �� �ո��� �� ���� ����
			std::cout << "Result is do" << '\n';
		}
	}
	else if (count == 2) { // �ΰ��� �ո��� �� �� ���� ����
		pNew->setStep(2); // ���� ���� ����
		std::cout << "Result is gae" << '\n';
	}
	else if (count == 3) { // ������ �ո��� ���� ���� ����
		pNew->setStep(3); // ���� ���� ����
		std::cout << "Result is geol" << '\n';
	}
	else if (count == 4) { // 4���� �ո��� ���� ���� ����
		pNew->setStep(4); // ���� ���� ����
		std::cout << "Result is yut" << '\n';
		return true; //�ѹ��� ������ ���ؼ� true�� ��ȯ
	}
	return false; // �ѹ��� ������ �ʴ� ���� false�� ��ȯ
}

void yut::delete_yut(int num) { // ���� ���� �����ϱ� ���� �żҵ�
	moving* pTemp = pHead; // pTemp�� pHead�� ����Ŵ
	moving* pPrev = pTemp; // pPrev�� PTemp�� ����Ŵ
	for (int i = 1; i < num; i++) {
		pPrev = pTemp; // pPrev�� Ptemp�� �������� ����Ű�� ���� ���� pTemp�� ������
		pTemp = pTemp->getNext(); // pTemp�� Next�� ���� ����Ŵ
	}
	if (pTemp == pHead) { // pTemp�� pHead�� ��
		if (!pHead->getNext()) { // pHead�� �������� ��
			delete pTemp; // pTemp�� �� ����
			pHead = nullptr; // pTemp�� ���� �ʱ�ȭ
			pTail = nullptr; // pTemp�� ���� �ʱ�ȭ
		}
		else {
			pHead = pTemp->getNext(); // pHead�� ���� pTemp�� �������� ����Ŵ
			delete pTemp; // pTemp�� ����
		}
	}
	else {
		if (!pTemp->getNext()) { //pTemp�� ���������� �� 
			pPrev->setNext(nullptr); // pTemp�� ������ ������ ���̹Ƿ� nullptr�� �ʱ�ȭ
			delete pTemp; // pTemp�� �� ����
		}
		else {
			pPrev->setNext(pTemp->getNext()); // pTemp�� ������ ���� �ƴҰ�� �������� pTemp�� �������� ����Ŵ
			delete pTemp; // pTemp�� �� ����
		}
	}
}

void yut::print_yut() { // ���� ����� ���� print�� ��
	moving* pTemp = pHead; //pTemp�� pHead�� ����Ŵ
	std::cout << "Yut Results: ";
	int count = 1; // ���� ������ ī��Ʈ �ϱ����ؼ� ������ ����
	while (pTemp) { // pTemp�� ���� ���� Ȯ��
		std::cout << count << ". " << pTemp->getStep(); // pTemp�� ���� ������
		std::cout.width(5); // �ܾ��� ���⸦ ���� ��
		pTemp = pTemp->getNext(); //pTemp�� ���� ���� ����Ŵ
		count++; // count�� �����Ƿ� ���� �ϳ� �ø�
	}
	std::cout << '\n';
}

void yut::yut_delete_all() { // ��� ���� ���� ���ֱ� ���� �żҵ�
	moving* pTemp = pHead; // pTemp�� pHead�� ����Ŵ
	while (pTemp) { // pTemp�� nullptr�� ������ �ݺ�
		pHead = pHead->getNext(); // pHead�� ���� ���� ����Ŵ
		delete pTemp; //pTemp �����Ҵ� ����
		pTemp = pHead; // pTemp �� ���� pHEad
	}
	pHead = nullptr; // pHead�� �� �ʱ�ȭ
	pTail = nullptr; // pTail�� �� �ʱ�ȭ
}
