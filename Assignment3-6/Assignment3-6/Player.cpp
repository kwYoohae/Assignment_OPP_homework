#include "Player.h"

player::player() {
	pHead = nullptr; // pHead의 초기화
	pTail = nullptr; // pTail의 초기화
}
player::~player() {

}

horse* player::getHead() {
	return pHead; // pHead의 값을 반환하는 매소드
}
horse* player::getTail() {
	return pTail; // pTail의 값을 반환하는 매소드
}

void player::setHead(horse* pTemp) {
	pHead = pTemp; // pHead의 값을 반환하는 매소드
}
void player::setTail(horse* pTemp) {
	pTail = pTemp; // pTail의 값을 반환하는 매소드
}

void player::inster_name(char ch) {
	char name[5]; //name을 결정하는 char형 배열 
	memset(name, NULL, 5); // name의 값을 초기화
	for (int i = 0; i < 4; i++) { 
		name[0] = ch; // 인자의 값을 name에 저장
		name[1] = '1' + i; // 인자의 값옆에 숫자를 저장
		horse* pNew = new horse; // 새로운 horse객체 생성
		if (!pHead) { // pHead가 비어있을 때
			pHead = pNew; // 새로운 horse값을 pHead로
			pTail = pNew; // 새로운 horse값을 pTail로
			pNew->setName(name); // horse에 name을 저장
		}
		else {
			pTail->setNext(pNew); // pTail의 다음 값을 설정
			pTail = pNew; // pTail의 값은 새로 생성한 horse객체
			pNew->setName(name); // 새로운 객체에 name값 저장
		}
	}
}

void player::print_horse() {
	int count = 1; // horse를 세기 위해서 count 변수 생성
	horse* pTemp = pHead; // pTemp는 pHead를 가리킴
	while (pTemp) {
		if (!pTemp->getPos()) { // pTemp의 값이 비어있을 때 horse가 안움직였을 때 hand를 출력하기 위한 if문
			if (!pTemp->getNow_carry()) { // 업힌 말인지 확인
				std::cout << count << ". " << "Hand"; // 아니면 hand출력
				std::cout.width(4);
			}
		}
		else {
			if (!pTemp->getNow_carry()) { // 업힌 말이 아니면
				std::cout << count << ". " << pTemp->getName(); //그말의 이름을 출력
				std::cout.width(4);
			}
		}
		pTemp = pTemp->getNext(); //pTemp의 값은 그다음 값으로
		count++; // count를 올림
	}
	std::cout << '\n';
}

int player::is_exisist(block* pBoard, horse* pHorse, block* short_center1, block* short_center2) { //말이 들어갈 값을 확인
	if (short_center1 == pBoard || short_center2 == pBoard) {  // 첫번째 지름길의 중앙이거나 두번째 지름길의 중앙일 때
		if (!short_center1->getOn() && !short_center2->getOn()) // 이동할 값이 비어있을 때
			return 0; // 0을반환
		else {
			if (short_center2->getOn()) { // 두번째 지름길의 값에 말이 있을 때
				if (short_center2->getOn()->getName()[0] != pHorse->getName()[0])  { //상대의 말이면
					return 3; //3을 반환
				}
				else
					return 5; // 같은편 말일 때 5를 반환
			}
			else {
				if (short_center1->getOn()->getName()[0] != pHorse->getName()[0]) { // 첫번쨰 지름길의 값에 말이 있을 때
					return 4; // 4를 반환
				}
				else
					return 6; // 같은편 말일 때 6을 반환
			}
		}
	}
	else {
		if (!pBoard->getOn()) { // 이동할 곳에 말이 없을 때
			return 0; // 0을 반환
		}
		else if (pBoard->getOn()) { // 이동할 곳에 말이 있을 떄
			if (pBoard->getOn()->getName()[0] != pHorse->getName()[0]) { //같은편 말이 아니면
				return 2; // 2를 반환
			}
			else
				return 1; // 같은편 말이면 1을 반환
		}
	}
}

void player::caught_horse(block* pTemp, horse* pHorse) { //말의 이동지점에 상대편 말이있을 경우 잡는 매소드
	horse* temp_horse = pTemp->getOn(); // temp_horse는 도착지점에 있는 말
	horse* carry = temp_horse->getCarry(); // carry는 temp_horse에 업혀있는 말
	while (temp_horse) { //업힌말이 없을 때 까지
		temp_horse->setStart(false); // 말의 start값 false로 초기화
		temp_horse->setShrotCut1(false); // 말의 지름길값 false로 초기화
		temp_horse->setShrotCut2(false); // 말의 지름길값 false로 초기화
		temp_horse->setPos(nullptr); // 말이 Pos값을 초기화
		temp_horse->setNow_carry(false); // 말의 now_carry값을 초기화
		temp_horse->setCarry(nullptr); // 말의 carry값을 초기화
		temp_horse = carry; // 말은 업힌말로
		if (!carry)
			break; // carry가 비어있을 때 반복문 종료
		carry = carry->getCarry(); // carry는 다음 carry값으로
	}
	if (pHorse->getPos()) {// 현재 말의 위치에 자신이 있을 때(말이 판에 있었을 때)
		pHorse->getPos()->setOn(nullptr); // 자신의 값을 초기화
	}
	pHorse->setPos(pTemp); // pTemp로 말을 옮김
	pTemp->setOn(pHorse); // pTemp에 말이 있다고 알림
}

void player::run_horse(block* pBlock, horse* pHorse) { // 말을 이동시킬 때
	if (!pHorse->getPos()) { // 말이 처음 나갈 때
		pHorse->setPos(pBlock); // pHorse의 위치값을 설정
		pBlock->setOn(pHorse); // pBlock에 말의 설정
	}
	else {
		pHorse->getPos()->setOn(nullptr); // 원래 있던 자리의 값을 삭제
		pHorse->setPos(pBlock); // 말이 갈 블럭의 위치를 저장
		pBlock->setOn(pHorse); // 블럭에 말의 위치를 저장
	}
	pHorse->setStart(true); // 출발 했다고 start값을 true로
}

void player::finished_horse(block* pBlock, horse* pHorse) { // 말이 완주했을 때
	horse* carry = pHorse->getCarry(); // 말의 carry값을 carry변수에 저장
	std::cout << "Finishted the horse"; 
	while (pHorse) { // 말이 비었을 때까지 반복문돌림
		pHorse->getPos()->setOn(nullptr); //말의 현재block에서의 말의 저장을 삭제
		pHorse->setPos(nullptr); // 말이 저장된 값을 삭제
		std::cout << " " << pHorse->getName(); // 말의 이름을 출력
		horse_delete(pHorse); // 말을 삭제하는 매소드 호출
		pHorse = carry; // 말에 carry값을 넣어줌
		if (!carry) // carry가 없을 때는 반복문종료
			break;
		carry = carry->getCarry(); // carry는 다음값으로 이동
	}
	std::cout << "!" << '\n';

}

int player::move_horse(int move_number, int select_number, yut* Yut, board* Board, board* Board_short1, board* Board_short2) {
	if (!pHead) { //만약 모든말이 가서 Player의 말이 비어있을 때
		Yut->yut_delete_all(); //모든 윷 삭제
		return 0; // 0값 반환
	} 
	int return_number = 0; // 말이 존재하는지 안하는지 확인 매소드의 확인후 실행할 커맨드를 받는 변수
	moving* yut_temp = Yut->getHead(); // 윳을 던진 값의 haed값을 불러옴
	horse* horse_temp = pHead; // 말의 haed값을 불러옴
	for (int i = 1; i < move_number; i++) {
		yut_temp = yut_temp->getNext(); // 내가 선택한 윷을 던진 값까지 감
	}
	for (int i = 1; i < select_number; i++) {
		horse_temp = horse_temp->getNext(); // 내가 선택한 말의 값까지 감
	}
	if (!yut_temp || !horse_temp) {
		return -1; // 매소드 반환하여 종료
	}
	else {
		int run = yut_temp->getStep(); // yut이 저장하고 있던 step값을 불러온다.
		if (run == -1 && is_hand() == true && Yut->getHead()->getNext() == nullptr) { //윷이 빽도인데 진출한 말이 없을 때는
			Yut->delete_yut(move_number); // 윷을 삭제후
			return -2; // -2를 반환
		}
		if (run == -1 &&possible_backdo()) { //빽도에서 나가지 Hand에 있는 말을 골랐는지확인
			if (!horse_temp->getPos()) { //horse_temp가 출발했는지 안했는지 확인
				std::cout << "you must choose start horse" << '\n';
				return -3; // -3값 반환
			}
		}
		if (!horse_temp->getPos()) { // 만약 말이 진출하지 않아서 비어있을 때는
			block* pTemp = Board->getHead(); //Board의 head값을 가리킴
			for (int i = 0; i < run; i++) {
				pTemp = pTemp->getNext(); //이동할 만큼 이동
			}
			return_number = is_exisist(pTemp, horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); //도착할 위치에 무슨 일이 일어날지 확인 후 커맨드 값 반환
			if (return_number == 2 || return_number == 3 || return_number == 4) { // 반환값이 2,3,4일때는 상대편말이 있는경우
				if (return_number == 3)
					pTemp = Board_short2->getCenter(); // short2에 상대편말이 있기 때문에 그곳으로 이동
				else if (return_number == 4)
					pTemp = Board_short1->getCenter(); // short1에 상대편말이 있기 때문에 그곳으로 이동
				caught_horse(pTemp, horse_temp); // 말을 잡는 매소드를 호출
				if (run == 4 || run == 5) { // 만약 윷이거나 모면 잡아도 한번더 하지 않기 위한 조건문
					Yut->delete_yut(move_number); // 윷을 삭제
					return 7; // 7을 반환
				}
			}
			else if (return_number == 1 || return_number == 5 || return_number == 6) { // 반환값이 1,5,6일 때는 같은편 말이 있는경우
				if (return_number == 5) // 만약 반환값이 5일 때는 short2에 우리편말이 있으므로
					pTemp = Board_short2->getCenter(); // pTemp는 short2의 센터로
				else if (return_number == 6) // 만약 반환값이 6일 때는 short1에 우리편말이 있으므로
					pTemp = Board_short1->getCenter(); // pTemp는 short1의 센터로
				horse_temp->insert_carry(pTemp->getOn()); // horse_temp는 말을 업게함
				run_horse(pTemp, horse_temp); //  말을 달리게 하는 매소드 호출
			}
			else {
				horse_temp->setPos(pTemp); // 말을 이동위치로 이동한다.
				horse_temp->getPos()->setOn(horse_temp); // 말이 이동할 block에 말을 설정
				horse_temp->setStart(true); // 말이 출발을 시작했다고 start를
			}
			Yut->delete_yut(move_number);
		}
		else if (run == -1) { // 빽도일 때는
			block* pTemp = horse_temp->getPos()->getPrev(); // pTemp는 기본적으로 자기의 이전block을 가리킨다.
			if (horse_temp->getPos() != Board->getHead()) { // 말이 도착점에 도착하지 않았을 때
				if (Board_short1->getTail()->getNext() == horse_temp->getPos()) { // Board에서  15번의 위치해 있을 때
					if (horse_temp->getShortCut1() || horse_temp->getShortCut2()) { // 지름길을 한번이라도 지나서 왔을 경우
						return_number = is_exisist(Board_short1->getTail(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); // return_number로 상태를 확인한다.
						pTemp = Board_short1->getTail(); // pTemp는 지름길의 Tail값으로 설정한다.
					}
					else {
						return_number = is_exisist(horse_temp->getPos()->getPrev(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); // 지름길로 안왔을 경우에는 return_number로 상태를 확인한다.
						pTemp = horse_temp->getPos()->getPrev(); // pTemp는 현재위치의 이전값으로 설정한다.
					}
				}
				else if (Board_short2->getCenter() == horse_temp->getPos() || Board_short1->getCenter() == horse_temp->getPos()) { //만약 2번쨰 지름길의 4번째 자리에 있을 때
					if (horse_temp->getShortCut1()) { // 만약 shortcut1을 지나서 왔을경우 shortcut1쪽으로 뒤로감
						return_number = is_exisist(Board_short1->getCenter()->getPrev(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter());  // return_number로 상태를 확인한다/
						pTemp = Board_short1->getCenter()->getPrev();
					}
					else { // 아닌경우는 shortcut2쪽으로 왔음
						return_number = is_exisist(horse_temp->getPos()->getPrev(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); // return_number로 상태를 확인한다.
						pTemp = horse_temp->getPos()->getPrev(); // 이전값으로 이동
					}
				}
				else
					return_number = is_exisist(horse_temp->getPos()->getPrev(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); //retrun_number로 상태를 확인한다.
			}
			else {
				if (Board->getHead() == horse_temp->getPos()) { // 만약 도착점 위치일때
					if (horse_temp->getShortCut1() || horse_temp->getShortCut2()) { //지름길론 온적이 있는경우는
						return_number = is_exisist(Board_short2->getTail(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); //return_number로 상태를 확인후
						pTemp = Board_short2->getTail(); // 지름길의 tail부분으로 위치시킴
					}
					else {
						return_number = is_exisist(Board->getTail(), horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); // 아닌경우는 return_number로 상태를 확인 후
						pTemp = Board->getTail(); // pTemp는 바로 뒤에 값을 가리킴
					}
				}
			}
			if (return_number == 2 || return_number == 3 || return_number == 4) { //return_number가 2,3,4여서 각각 상대팀 마을 잡았을 경우에
				if (return_number == 3) //board_short2의 센터 노드에서 잡혔을 경우
					pTemp = Board_short2->getCenter(); // pTemp를 board_short2의 센터로 가리킴
				else if (return_number == 4) // board_short1의 센터 노드에서 잡혔을 경우
					pTemp = Board_short1->getCenter(); //pTemp를 board_short1의 센터로 가리킴
				caught_horse(pTemp, horse_temp); // 상대말을 잡는 매소드 호출
				if (run == 5 || run == 4) { // 윷이거나 모인경우네는 한번더 하지 않기위해서 호출
					Yut->delete_yut(move_number); // 쓴 윷 삭제
					return 7; // 7을반환
				}
			}
			else if (return_number == 1 || return_number == 5 || return_number == 6) { //return_number가 1,5,6이여서 각각 우리팀 말에 업힐때
				if (return_number == 5) // 5일경우 Board_short2의 센터에서 말을 업음
					pTemp = Board_short2->getCenter(); // pTemp는 BOard_short2의 센터를 가리킴
				else if (return_number == 6) // 6일경우 Board_short1의 센터에서 말을 업음
					pTemp = Board_short1->getCenter(); // pTemp는 Board_short1의 센터를 가리킴
				horse_temp->insert_carry(pTemp->getOn()); // 말을 업는 매소드를 호출
				run_horse(pTemp, horse_temp); // 말을 이동시키는 매소드를 호출

			}
			else {
				run_horse(pTemp, horse_temp); // 말을 이동시키는 매소드를 호출
			}
			Yut->delete_yut(move_number); // 이동횟수를 썼기 때문에 삭제
			return return_number; // return_number를 반환
		}
		else {
			block* pRun_horse = horse_temp->getPos(); // pRun_horse는 말의 현재 위치를 가리킴 
			if (!pRun_horse->getShortcut()) { // 만약 short_cut이 있는 경우에
				for (int i = 0; i < run; i++) { 
					if (pRun_horse == Board->getHead() && horse_temp->getStart() == true) { //만약 도착점에 들어갈경우
						finished_horse(pRun_horse, horse_temp); // 도착점처리를 해주는 매소드를 호출
						if (!pHead) // 모든 말이 들어가 pHead가 null일 경우
							Yut->yut_delete_all(); // 모든 윺 삭제
						else
							Yut->delete_yut(move_number); //아니리경우 현재윷만 삭제
						return 0; // 0을반환
					}
					pRun_horse = pRun_horse->getNext(); //pRun_horse는 다음값을 가리킴
				}
				return_number = is_exisist(pRun_horse, horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); // return_number을 결정
			}
			else {
				if (pRun_horse == Board_short1->getHead()->getPrev()) { // pRun_horse가 shortCut1으로 들어가는 지점일 경우
					horse_temp->setShrotCut1(true); // short_cut1으로 들어갔다고 true로 설정
				}
				else if (pRun_horse == Board_short2->getHead()->getPrev()) { // pRun_horse가 shortCut2로 들어가는 경우
					horse_temp->setShrotCut2(true); // short_cut2로 들어갔다고 true로 설정
				}
				for (int i = 0; i < run; i++) {
					if (pRun_horse == Board->getHead() && horse_temp->getStart() == true) { // 도착점을 지나는 경우
						finished_horse(pRun_horse, horse_temp); // 완주하는 매소드 호출
						if (!pHead) // 모든 말이 완주할 때
							Yut->yut_delete_all(); // 모든 윷 삭제
						else
							Yut->delete_yut(move_number); // 아닐경우 현재 윷만 삭제
						return 0; // 0반환
					}
					if (i == 0)
						pRun_horse = pRun_horse->getShortcut(); // 처음에 shortcut으로 이동
					else
						pRun_horse = pRun_horse->getNext(); // 그후는 다음값으로 이동
				}
				return_number = is_exisist(pRun_horse, horse_temp, Board_short1->getCenter(), Board_short2->getCenter()); //return_number값 결정
			}
			if (return_number == 0) { // 도착지점에 아무말도 없는경우
				run_horse(pRun_horse, horse_temp); // 말을이동시킴
			}
			else if (return_number == 2 || return_number == 3 || return_number == 4) { // 상대말을 잡았을경우
				if (return_number == 3) // Board_short2에서 잡았을 경우
					pRun_horse = Board_short2->getCenter();  //pRun_horse를 Short2의 센터로 설정
				else if (return_number == 4) // Board_short1에서 잡았을 경우
					pRun_horse = Board_short1->getCenter(); //pRun_horse를 short1의 센터로 설정
				caught_horse(pRun_horse, horse_temp);  // 말을 잡는 매소드를 호출
				if (run == 5 || run == 4) { //  윷이나 모로 잡았을 때
					Yut->delete_yut(move_number); //  윷을 그냥 삭제 한번더 못던지게 함
					return 7;
				}
			}
			else {
				if (return_number == 5) { // return_number가 5일경우 pRun_horse에서 Short2에 같은편 말이 있으므로 업음
					pRun_horse = Board_short2->getCenter();
				}
				else if (return_number == 6) // rerturn_number가 6일경우 pRun_horse에서 Short1에 같은편 말이 있으므로 업음
					pRun_horse = Board_short1->getCenter(); 
				horse_temp->insert_carry(pRun_horse->getOn()); //horse_temp는 말을 업는 매소드를 호출
				run_horse(pRun_horse, horse_temp); // 말을 이동시킴
			}
			Yut->delete_yut(move_number); // 사용한 윷을 지움
		}
	}
	return return_number; // return_number를 반환
}

void player::horse_delete(horse* pHorse) { // 말을 지우는 매소드
	horse* pTemp = pHead;
	horse* pPrev = pTemp;
	horse* pCarry = pHorse->getCarry();
	while (pTemp) { // pTemp가 null일때까지 반복
		if (pTemp == pHorse) // pTemprk 선택한 말일때까지 반복
			break;
		pPrev = pTemp; // pTemp의 전값을 저장
		pTemp = pTemp->getNext(); // pTemp 는 다음값으로
	}
	if (pTemp == pHead) { // pTemp가 pHead일경우 head를 다시설정해주는 예외처리
		if (pHead->getNext() == nullptr) { //pHead가 혼자남았을 때 pHead와 pTail를 초기화해주기위한 매소드
			delete pTemp; //동적할당해제
			pHead = nullptr;
			pTail = nullptr;
		}
		else { // pHead 다음값이 있을 때 pHead만 옮겨준다.
			pHead = pHead->getNext();
			delete pTemp; // 동적할당 해제
		}
	}
	else if (pTemp == pTail) { // pTemp가 pTail일 경우
		pPrev->setNext(nullptr); // 다음값은 없으므로 설ㅈ어
		delete pTemp; // 동적할당해제
	}
	else { //삭제할 horse가 Head나 Tail이 아닐경우
		pPrev->setNext(pTemp->getNext());  // 이전값이 삭제할노드의 다음값을 next로가리킴
		delete pTemp;//동적할당해제
	}
}

bool player::is_hand() { // 모든말이 hand에 있는지 확인하는 매소드
	horse* pTemp = pHead;
	while (pTemp) { 
		if (pTemp->getPos()) // 만약 하나라도 말이 있으면 return false출력
			return false;
		pTemp = pTemp->getNext(); //pTemp는 그다음으로
	}
	return true; //모두가 hand에 있을 때 true반환
}

void player::delete_player() { // player에 있는 horse를 모두 삭제하는 매소드
	horse* pTemp = pHead;
	while (pTemp) { // pTemp가 nullptr일떄까지
		pHead = pHead->getNext();
		delete pTemp; // 동적할당해제를해준다.
		pTemp = pHead;
	}
}

bool player::possible_backdo() { // back를 할 수 있는 말인지 확인하는 매소드
	horse* pTemp = pHead;
	while (pTemp) {
		if (pTemp->getPos()) // 만약 hand에있는 것이 아닌 말이면 할수있도록 true를 반환한다.
			return true;
		pTemp = pTemp->getNext();
	}
	return false; //모두 hand에 있을 시 false를 반환
}