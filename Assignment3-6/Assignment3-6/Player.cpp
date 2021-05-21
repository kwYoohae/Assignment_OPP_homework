#include "Player.h"

player::player() {
	pHead = nullptr; // pHead�� �ʱ�ȭ
	pTail = nullptr; // pTail�� �ʱ�ȭ
}
player::~player() {

}

horse* player::getHead() {
	return pHead; // pHead�� ���� ��ȯ�ϴ� �żҵ�
}
horse* player::getTail() {
	return pTail; // pTail�� ���� ��ȯ�ϴ� �żҵ�
}

void player::setHead(horse* pTemp) {
	pHead = pTemp; // pHead�� ���� ��ȯ�ϴ� �żҵ�
}
void player::setTail(horse* pTemp) {
	pTail = pTemp; // pTail�� ���� ��ȯ�ϴ� �żҵ�
}

void player::inster_name(char ch) {
	char name[5]; //name�� �����ϴ� char�� �迭 
	memset(name, NULL, 5); // name�� ���� �ʱ�ȭ
	for (int i = 0; i < 4; i++) { 
		name[0] = ch; // ������ ���� name�� ����
		name[1] = '1' + i; // ������ ������ ���ڸ� ����
		horse* pNew = new horse; // ���ο� horse��ü ����
		if (!pHead) { // pHead�� ������� ��
			pHead = pNew; // ���ο� horse���� pHead��
			pTail = pNew; // ���ο� horse���� pTail��
			pNew->setName(name); // horse�� name�� ����
		}
		else {
			pTail->setNext(pNew); // pTail�� ���� ���� ����
			pTail = pNew; // pTail�� ���� ���� ������ horse��ü
			pNew->setName(name); // ���ο� ��ü�� name�� ����
		}
	}
}

void player::print_horse() {
	int count = 1; // horse�� ���� ���ؼ� count ���� ����
	horse* pTemp = pHead; // pTemp�� pHead�� ����Ŵ
	while (pTemp) {
		if (!pTemp->getPos()) { // pTemp�� ���� ������� �� horse�� �ȿ������� �� hand�� ����ϱ� ���� if��
			if (!pTemp->getNow_carry()) { // ���� ������ Ȯ��
				std::cout << count << ". " << "Hand"; // �ƴϸ� hand���
				std::cout.width(4);
			}
		}
		else {
			if (!pTemp->getNow_carry()) { // ���� ���� �ƴϸ�
				std::cout << count << ". " << pTemp->getName(); //�׸��� �̸��� ���
				std::cout.width(4);
			}
		}
		pTemp = pTemp->getNext(); //pTemp�� ���� �״��� ������
		count++; // count�� �ø�
	}
	std::cout << '\n';
}

int player::is_exisist(block* pBoard, horse* pHorse, block* short_center1, block* short_center2) { //���� �� ���� Ȯ��
	if (short_center1 == pBoard || short_center2 == pBoard) {  // ù��° �������� �߾��̰ų� �ι�° �������� �߾��� ��
		if (!short_center1->getOn() && !short_center2->getOn()) // �̵��� ���� ������� ��
			return 0; // 0����ȯ
		else {
			if (short_center2->getOn()) { // �ι�° �������� ���� ���� ���� ��
				if (short_center2->getOn()->getName()[0] != pHorse->getName()[0])  { //����� ���̸�
					return 3; //3�� ��ȯ
				}
				else
					return 5; // ������ ���� �� 5�� ��ȯ
			}
			else {
				if (short_center1->getOn()->getName()[0] != pHorse->getName()[0]) { // ù���� �������� ���� ���� ���� ��
					return 4; // 4�� ��ȯ
				}
				else
					return 6; // ������ ���� �� 6�� ��ȯ
			}
		}
	}
	else {
		if (!pBoard->getOn()) { // �̵��� ���� ���� ���� ��
			return 0; // 0�� ��ȯ
		}
		else if (pBoard->getOn()) { // �̵��� ���� ���� ���� ��
			if (pBoard->getOn()->getName()[0] != pHorse->getName()[0]) { //������ ���� �ƴϸ�
				return 2; // 2�� ��ȯ
			}
			else
				return 1; // ������ ���̸� 1�� ��ȯ
		}
	}
}

void player::caught_horse(block* pTemp, horse* pHorse) { //���� �̵������� ����� �������� ��� ��� �żҵ�
	horse* temp_horse = pTemp->getOn(); // temp_horse�� ���������� �ִ� ��
	horse* carry = temp_horse->getCarry(); // carry�� temp_horse�� �����ִ� ��
	while (temp_horse) { //�������� ���� �� ����
		temp_horse->setStart(false); // ���� start�� false�� �ʱ�ȭ
		temp_horse->setShrotCut1(false); // ���� �����氪 false�� �ʱ�ȭ
		temp_horse->setShrotCut2(false); // ���� �����氪 false�� �ʱ�ȭ
		temp_horse->setPos(nullptr); // ���� Pos���� �ʱ�ȭ
		temp_horse->setNow_carry(false); // ���� now_carry���� �ʱ�ȭ
		temp_horse->setCarry(nullptr); // ���� carry���� �ʱ�ȭ
		temp_horse = carry; // ���� ��������
		if (!carry)
			break; // carry�� ������� �� �ݺ��� ����
		carry = carry->getCarry(); // carry�� ���� carry������
	}
	if (pHorse->getPos()) {// ���� ���� ��ġ�� �ڽ��� ���� ��(���� �ǿ� �־��� ��)
		pHorse->getPos()->setOn(nullptr); // �ڽ��� ���� �ʱ�ȭ
	}
	pHorse->setPos(pTemp); // pTemp�� ���� �ű�
	pTemp->setOn(pHorse); // pTemp�� ���� �ִٰ� �˸�
}

void player::run_horse(block* pBlock, horse* pHorse) { // ���� �̵���ų ��
	if (!pHorse->getPos()) { // ���� ó�� ���� ��
		pHorse->setPos(pBlock); // pHorse�� ��ġ���� ����
		pBlock->setOn(pHorse); // pBlock�� ���� ����
	}
	else {
		pHorse->getPos()->setOn(nullptr); // ���� �ִ� �ڸ��� ���� ����
		pHorse->setPos(pBlock); // ���� �� ���� ��ġ�� ����
		pBlock->setOn(pHorse); // ���� ���� ��ġ�� ����
	}
	pHorse->setStart(true); // ��� �ߴٰ� start���� true��
}

void player::finished_horse(block* pBlock, horse* pHorse) { // ���� �������� ��
	horse* carry = pHorse->getCarry(); // ���� carry���� carry������ ����
	std::cout << "Finishted the horse"; 
	while (pHorse) { // ���� ����� ������ �ݺ�������
		pHorse->getPos()->setOn(nullptr); //���� ����block������ ���� ������ ����
		pHorse->setPos(nullptr); // ���� ����� ���� ����
		std::cout << " " << pHorse->getName(); // ���� �̸��� ���
		horse_delete(pHorse); // ���� �����ϴ� �żҵ� ȣ��
		pHorse = carry; // ���� carry���� �־���
		if (!carry) // carry�� ���� ���� �ݺ�������
			break;
		carry = carry->getCarry(); // carry�� ���������� �̵�
	}
	std::cout << "!" << '\n';

}

int player::move_horse(int move_number, int select_number, yut* Yut, board* Board, board* Board_short1, board* Board_short2) {
	if (!pHead) { //���� ��縻�� ���� Player�� ���� ������� ��
		Yut->yut_delete_all(); //��� �� ����
		return 0; // 0�� ��ȯ
	} 
	int return_number = 0; // ���� �����ϴ��� ���ϴ��� Ȯ�� �żҵ��� Ȯ���� ������ Ŀ�ǵ带 �޴� ����
	moving* yut_temp = Yut->getHead(); // ���� ���� ���� haed���� �ҷ���
	horse* horse_temp = pHead; // ���� haed���� �ҷ���
	for (int i = 1; i < move_number; i++) {
		yut_temp = yut_temp->getNext(); // ���� ������ ���� ���� ������ ��
	}
	for (int i = 1; i < select_number; i++) {
		horse_temp = horse_temp->getNext(); // ���� ������ ���� ������ ��
	}
	if (!yut_temp || !horse_temp) {
		return -1; // �żҵ� ��ȯ�Ͽ� ����
	}
	else {
		int run = yut_temp->getStep(); // yut�� �����ϰ� �ִ� step���� �ҷ��´�.
		if (run == -1 && is_hand() == true && Yut->getHead()->getNext() == nullptr) { //���� �����ε� ������ ���� ���� ����
			Yut->delete_yut(move_number); // ���� ������
			return -2; // -2�� ��ȯ
		}
		if (run == -1 &&possible_backdo()) { //�������� ������ Hand�� �ִ� ���� �������Ȯ��
			if (!horse_temp->getPos()) { //horse_temp�� ����ߴ��� ���ߴ��� Ȯ��
				std::cout << "you must choose start horse" << '\n';
				return -3; // -3�� ��ȯ
			}
		}
		if (!horse_temp->getPos()) { // ���� ���� �������� �ʾƼ� ������� ����
			block* pTemp = Board->getHead(); //Board�� head���� ����Ŵ
			for (int i = 0; i < run; i++) {
				pTemp = pTemp->getNext(); //�̵��� ��ŭ �̵�
			}
			return_number = is_exisist(pTemp, horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); //������ ��ġ�� ���� ���� �Ͼ�� Ȯ�� �� Ŀ�ǵ� �� ��ȯ
			if (return_number == 2 || return_number == 3 || return_number == 4) { // ��ȯ���� 2,3,4�϶��� ������� �ִ°��
				if (return_number == 3)
					pTemp = Board_short2->getCenter(); // short2�� ������� �ֱ� ������ �װ����� �̵�
				else if (return_number == 4)
					pTemp = Board_short1->getCenter(); // short1�� ������� �ֱ� ������ �װ����� �̵�
				caught_horse(pTemp, horse_temp); // ���� ��� �żҵ带 ȣ��
				if (run == 4 || run == 5) { // ���� ���̰ų� ��� ��Ƶ� �ѹ��� ���� �ʱ� ���� ���ǹ�
					Yut->delete_yut(move_number); // ���� ����
					return 7; // 7�� ��ȯ
				}
			}
			else if (return_number == 1 || return_number == 5 || return_number == 6) { // ��ȯ���� 1,5,6�� ���� ������ ���� �ִ°��
				if (return_number == 5) // ���� ��ȯ���� 5�� ���� short2�� �츮���� �����Ƿ�
					pTemp = Board_short2->getCenter(); // pTemp�� short2�� ���ͷ�
				else if (return_number == 6) // ���� ��ȯ���� 6�� ���� short1�� �츮���� �����Ƿ�
					pTemp = Board_short1->getCenter(); // pTemp�� short1�� ���ͷ�
				horse_temp->insert_carry(pTemp->getOn()); // horse_temp�� ���� ������
				run_horse(pTemp, horse_temp); //  ���� �޸��� �ϴ� �żҵ� ȣ��
			}
			else {
				horse_temp->setPos(pTemp); // ���� �̵���ġ�� �̵��Ѵ�.
				horse_temp->getPos()->setOn(horse_temp); // ���� �̵��� block�� ���� ����
				horse_temp->setStart(true); // ���� ����� �����ߴٰ� start��
			}
			Yut->delete_yut(move_number);
		}
		else if (run == -1) { // ������ ����
			block* pTemp = horse_temp->getPos()->getPrev(); // pTemp�� �⺻������ �ڱ��� ����block�� ����Ų��.
			if (horse_temp->getPos() != Board->getHead()) { // ���� �������� �������� �ʾ��� ��
				if (Board_short1->getTail()->getNext() == horse_temp->getPos()) { // Board����  15���� ��ġ�� ���� ��
					if (horse_temp->getShortCut1() || horse_temp->getShortCut2()) { // �������� �ѹ��̶� ������ ���� ���
						return_number = is_exisist(Board_short1->getTail(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); // return_number�� ���¸� Ȯ���Ѵ�.
						pTemp = Board_short1->getTail(); // pTemp�� �������� Tail������ �����Ѵ�.
					}
					else {
						return_number = is_exisist(horse_temp->getPos()->getPrev(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); // ������� �ȿ��� ��쿡�� return_number�� ���¸� Ȯ���Ѵ�.
						pTemp = horse_temp->getPos()->getPrev(); // pTemp�� ������ġ�� ���������� �����Ѵ�.
					}
				}
				else if (Board_short2->getCenter() == horse_temp->getPos() || Board_short1->getCenter() == horse_temp->getPos()) { //���� 2���� �������� 4��° �ڸ��� ���� ��
					if (horse_temp->getShortCut1()) { // ���� shortcut1�� ������ ������� shortcut1������ �ڷΰ�
						return_number = is_exisist(Board_short1->getCenter()->getPrev(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter());  // return_number�� ���¸� Ȯ���Ѵ�/
						pTemp = Board_short1->getCenter()->getPrev();
					}
					else { // �ƴѰ��� shortcut2������ ����
						return_number = is_exisist(horse_temp->getPos()->getPrev(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); // return_number�� ���¸� Ȯ���Ѵ�.
						pTemp = horse_temp->getPos()->getPrev(); // ���������� �̵�
					}
				}
				else
					return_number = is_exisist(horse_temp->getPos()->getPrev(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); //retrun_number�� ���¸� Ȯ���Ѵ�.
			}
			else {
				if (Board->getHead() == horse_temp->getPos()) { // ���� ������ ��ġ�϶�
					if (horse_temp->getShortCut1() || horse_temp->getShortCut2()) { //������� ������ �ִ°���
						return_number = is_exisist(Board_short2->getTail(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); //return_number�� ���¸� Ȯ����
						pTemp = Board_short2->getTail(); // �������� tail�κ����� ��ġ��Ŵ
					}
					else {
						return_number = is_exisist(Board->getTail(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); // �ƴѰ��� return_number�� ���¸� Ȯ�� ��
						pTemp = Board->getTail(); // pTemp�� �ٷ� �ڿ� ���� ����Ŵ
					}
				}
			}
			if (return_number == 2 || return_number == 3 || return_number == 4) { //return_number�� 2,3,4���� ���� ����� ���� ����� ��쿡
				if (return_number == 3) //board_short2�� ���� ��忡�� ������ ���
					pTemp = Board_short2->getCenter(); // pTemp�� board_short2�� ���ͷ� ����Ŵ
				else if (return_number == 4) // board_short1�� ���� ��忡�� ������ ���
					pTemp = Board_short1->getCenter(); //pTemp�� board_short1�� ���ͷ� ����Ŵ
				caught_horse(pTemp, horse_temp); // ��븻�� ��� �żҵ� ȣ��
				if (run == 5 || run == 4) { // ���̰ų� ���ΰ��״� �ѹ��� ���� �ʱ����ؼ� ȣ��
					Yut->delete_yut(move_number); // �� �� ����
					return 7; // 7����ȯ
				}
			}
			else if (return_number == 1 || return_number == 5 || return_number == 6) { //return_number�� 1,5,6�̿��� ���� �츮�� ���� ������
				if (return_number == 5) // 5�ϰ�� Board_short2�� ���Ϳ��� ���� ����
					pTemp = Board_short2->getCenter(); // pTemp�� BOard_short2�� ���͸� ����Ŵ
				else if (return_number == 6) // 6�ϰ�� Board_short1�� ���Ϳ��� ���� ����
					pTemp = Board_short1->getCenter(); // pTemp�� Board_short1�� ���͸� ����Ŵ
				horse_temp->insert_carry(pTemp->getOn()); // ���� ���� �żҵ带 ȣ��
				run_horse(pTemp, horse_temp); // ���� �̵���Ű�� �żҵ带 ȣ��

			}
			else {
				run_horse(pTemp, horse_temp); // ���� �̵���Ű�� �żҵ带 ȣ��
			}
			Yut->delete_yut(move_number); // �̵�Ƚ���� ��� ������ ����
			return return_number; // return_number�� ��ȯ
		}
		else {
			block* pRun_horse = horse_temp->getPos(); // pRun_horse�� ���� ���� ��ġ�� ����Ŵ 
			if (!pRun_horse->getShortcut()) { // ���� short_cut�� �ִ� ��쿡
				for (int i = 0; i < run; i++) { 
					if (pRun_horse == Board->getHead() && horse_temp->getStart() == true) { //���� �������� �����
						finished_horse(pRun_horse, horse_temp); // ������ó���� ���ִ� �żҵ带 ȣ��
						if (!pHead) // ��� ���� �� pHead�� null�� ���
							Yut->yut_delete_all(); // ��� �� ����
						else
							Yut->delete_yut(move_number); //�ƴϸ���� �������� ����
						return 0; // 0����ȯ
					}
					pRun_horse = pRun_horse->getNext(); //pRun_horse�� �������� ����Ŵ
				}
				return_number = is_exisist(pRun_horse, horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); // return_number�� ����
			}
			else {
				if (pRun_horse == Board_short1->getHead()->getPrev()) { // pRun_horse�� shortCut1���� ���� ������ ���
					horse_temp->setShrotCut1(true); // short_cut1���� ���ٰ� true�� ����
				}
				else if (pRun_horse == Board_short2->getHead()->getPrev()) { // pRun_horse�� shortCut2�� ���� ���
					horse_temp->setShrotCut2(true); // short_cut2�� ���ٰ� true�� ����
				}
				for (int i = 0; i < run; i++) {
					if (pRun_horse == Board->getHead() && horse_temp->getStart() == true) { // �������� ������ ���
						finished_horse(pRun_horse, horse_temp); // �����ϴ� �żҵ� ȣ��
						if (!pHead) // ��� ���� ������ ��
							Yut->yut_delete_all(); // ��� �� ����
						else
							Yut->delete_yut(move_number); // �ƴҰ�� ���� ���� ����
						return 0; // 0��ȯ
					}
					if (i == 0)
						pRun_horse = pRun_horse->getShortcut(); // ó���� shortcut���� �̵�
					else
						pRun_horse = pRun_horse->getNext(); // ���Ĵ� ���������� �̵�
				}
				return_number = is_exisist(pRun_horse, horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); //return_number�� ����
			}
			if (return_number == 0) { // ���������� �ƹ����� ���°��
				run_horse(pRun_horse, horse_temp); // �����̵���Ŵ
			}
			else if (return_number == 2 || return_number == 3 || return_number == 4) { // ��븻�� ��������
				if (return_number == 3) // Board_short2���� ����� ���
					pRun_horse = Board_short2->getCenter();  //pRun_horse�� Short2�� ���ͷ� ����
				else if (return_number == 4) // Board_short1���� ����� ���
					pRun_horse = Board_short1->getCenter(); //pRun_horse�� short1�� ���ͷ� ����
				caught_horse(pRun_horse, horse_temp);  // ���� ��� �żҵ带 ȣ��
				if (run == 5 || run == 4) { //  ���̳� ��� ����� ��
					Yut->delete_yut(move_number); //  ���� �׳� ���� �ѹ��� �������� ��
					return 7;
				}
			}
			else {
				if (return_number == 5) { // return_number�� 5�ϰ�� pRun_horse���� Short2�� ������ ���� �����Ƿ� ����
					pRun_horse = Board_short2->getCenter();
				}
				else if (return_number == 6) // rerturn_number�� 6�ϰ�� pRun_horse���� Short1�� ������ ���� �����Ƿ� ����
					pRun_horse = Board_short1->getCenter(); 
				horse_temp->insert_carry(pRun_horse->getOn()); //horse_temp�� ���� ���� �żҵ带 ȣ��
				run_horse(pRun_horse, horse_temp); // ���� �̵���Ŵ
			}
			Yut->delete_yut(move_number); // ����� ���� ����
		}
	}
	return return_number; // return_number�� ��ȯ
}

void player::horse_delete(horse* pHorse) { // ���� ����� �żҵ�
	horse* pTemp = pHead;
	horse* pPrev = pTemp;
	horse* pCarry = pHorse->getCarry();
	while (pTemp) { // pTemp�� null�϶����� �ݺ�
		if (pTemp == pHorse) // pTemprk ������ ���϶����� �ݺ�
			break;
		pPrev = pTemp; // pTemp�� ������ ����
		pTemp = pTemp->getNext(); // pTemp �� ����������
	}
	if (pTemp == pHead) { // pTemp�� pHead�ϰ�� head�� �ٽü������ִ� ����ó��
		if (pHead->getNext() == nullptr) { //pHead�� ȥ�ڳ����� �� pHead�� pTail�� �ʱ�ȭ���ֱ����� �żҵ�
			delete pTemp; //�����Ҵ�����
			pHead = nullptr;
			pTail = nullptr;
		}
		else { // pHead �������� ���� �� pHead�� �Ű��ش�.
			pHead = pHead->getNext();
			delete pTemp; // �����Ҵ� ����
		}
	}
	else if (pTemp == pTail) { // pTemp�� pTail�� ���
		pPrev->setNext(nullptr); // �������� �����Ƿ� ������
		delete pTemp; // �����Ҵ�����
	}
	else { //������ horse�� Head�� Tail�� �ƴҰ��
		pPrev->setNext(pTemp->getNext());  // �������� �����ҳ���� �������� next�ΰ���Ŵ
		delete pTemp;//�����Ҵ�����
	}
}

bool player::is_hand() { // ��縻�� hand�� �ִ��� Ȯ���ϴ� �żҵ�
	horse* pTemp = pHead;
	while (pTemp) { 
		if (pTemp->getPos()) // ���� �ϳ��� ���� ������ return false���
			return false;
		pTemp = pTemp->getNext(); //pTemp�� �״�������
	}
	return true; //��ΰ� hand�� ���� �� true��ȯ
}

void player::delete_player() { // player�� �ִ� horse�� ��� �����ϴ� �żҵ�
	horse* pTemp = pHead;
	while (pTemp) { // pTemp�� nullptr�ϋ�����
		pHead = pHead->getNext();
		delete pTemp; // �����Ҵ����������ش�.
		pTemp = pHead;
	}
}

bool player::possible_backdo() { // back�� �� �� �ִ� ������ Ȯ���ϴ� �żҵ�
	horse* pTemp = pHead;
	while (pTemp) {
		if (pTemp->getPos()) // ���� hand���ִ� ���� �ƴ� ���̸� �Ҽ��ֵ��� true�� ��ȯ�Ѵ�.
			return true;
		pTemp = pTemp->getNext();
	}
	return false; //��� hand�� ���� �� false�� ��ȯ
}