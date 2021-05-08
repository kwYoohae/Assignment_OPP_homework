#include <iostream>
#include "Node.h"
#include "Deck.h"
#include "Discard_tray.h"
#include "Player.h"
#include <crtdbg.h>
using namespace std;

void who_is_winner(int player_sum, int dealer_sum) { //승패를 결정하는 함수
	int player_res = 21 - player_sum; // 값이 21에 더 가까운지를 확인하는 변수
	int dealer_res = 21 - dealer_sum; // 값이 21에 더 가까운지를 확인하는 변수
	if (player_sum > 21) { // 만약 player가 21을 초과해서 카드를 받을경우 Lose를 출력
		cout << "Player Lose!" << endl;
	}
	else if (dealer_sum > 21) { // 만약 딜러의 카드가 21을 넘었으면 Win을 출력
		cout << "Player Win!" << endl;
	}
	else if (player_res == dealer_res) { // 서로 점수가 같다면 Draw를 출력
		cout << " Draw..." << endl;
	}
	else if (player_res < dealer_res) { // Player가 21에 더 가깝다면 Win을 출력
		cout << "Player Win!" << endl;
	}
	else if (player_res > dealer_res) { // Player가 21에 더 멀다면 Lose를 출력
		cout << "Player Lose!" << endl;
	}
}

int main() {
	deck Deck; //객체 생성
	player Player; // 객체 생성
	Dealer dealer; // 객체 생성
	discard Discard; // 객체 생성
	char command[20]; // 명령어 입력
	bool end = true; //블랙잭을 계속하는 반복문을 결정함는 bool형 변수
	bool game = false; // game을 시작하는지 판단하는 bool형 변수
	bool bet = false; // bet을 시작하는지 판단하는 bool형 변수
	bool stand = false; // stand를 하는지 판단하는 bool형 변수
	while (end) {
		if (!game) { // game이 false(시작안했을 때)
			cout << "Command list(game/shuffle/exit)" << endl;
			cout << "CMD>> ";
			cin >> command; // 명령어 입력받음
			if (strcmp(command, "game") == 0) { // 입력한 커맨드가 game일 때
				if (Deck.deck_count() == 52) // 카드 전체가 덱에 있는지 확인
					game = true; // 덱에 모든 카드가 있으면 게임시작
				else
					cout << "Not Enough Cards" << endl; // 덱에 모든 카드가 없을 때 Not Enough Cards 출력
			}
			else if (strcmp(command, "shuffle") == 0) { // 입력한 커맨드가 shuffle일 때
				int number; // 셔플할 횟수를 판단 하는 변수
				cin >> number; // 셔플할 횟수 입력
				Deck.shuffle(number, &Player, &Discard); // 셔플을 하는 매소드 호출
			}
			else if (strcmp(command, "exit") == 0) { // 게임을 종료
				dealer.delete_card(); // dealer가 가지고 있는 모든 노드(카드) 삭제 
				Player.delete_card(); // player가 가지고 있는 모든 노드(카드) 삭제
				Discard.delete_card(); // discard_tray에 있는 모든 노드(카드) 삭제
				Deck.delete_deck(); // 덱에 있는 모든 노드(카드) 삭제 
				end = false; // 반복문 종료
			}
			else {
				cout << "Wrong Command!" << endl; // 두개의 커맨드가 아닐 시 틀린 커맨드라고 출력
			}
		}
		else {	
			if (!bet) { // bet이 false일때
				cout << "Command list(bet/end)" << endl;
				cout << "CMD>> ";
				cin >> command; //명령어 입력
				if (strcmp(command, "bet") == 0) { // 명령어가 bet일 경우
					dealer.delete_card(); // 딜러의 모든 카드 삭제
					Player.delete_card(); // 플레이어의 모든 카드 삭제
					bet = true; // bet 시작
					stand = false; // stand의 기본값 설정
					for (int i = 0; i < 2; i++) { // 딜러와 플레이어에게 각각 두장의 카드를 줌
						Deck.hit_Dealer(&Player, &dealer, &Discard);
						Deck.hit_player(&Player, &dealer, &Discard);
					}
				}
				else if (strcmp(command, "end") == 0) { // 명령어가 end인지 판단
					dealer.delete_card(); // 딜러의 모든 카드 삭제
					Player.delete_card(); // 플레이어의 모든 카드 삭제
					game = false; // game 종료
				}
				else {
					cout << "Wrong Command!" << endl; // 틀린명령어 입력시 출력
				}
				
			}
			else {
				if (!stand) { // stand가 false일 때(스탠드를 안했을 때)
					dealer.print(stand); // dealer의 카드 출력(stand가 false 일 경우에는 첫번 째 카드를 빼고 출력
					Player.print(); // 플레이어의 카드 출력
				}
				else { // stand를 외쳤을 때
					dealer.print(stand); // 딜러의 카드 출력 (stand가 true 일 때는 모든 카드를 출력)
					Player.print(); // 플레이어의 카드 출력
					who_is_winner(Player.sum(), dealer.sum()); //누가 이겼는지 판단
					if (Deck.deck_count() <= 13) { // 만약 덱에 남은 카드가 13개 이하면 
						cout << "Not Enough Card" << endl; // Not Enough Card 출력
						dealer.delete_card(); // 딜러의 카드 삭제
						Player.delete_card(); // 플레이어의 카드 삭제
						bet = false; // 베팅 종료
						game = false; // 게임 종료
					}
					bet = false; // 아닐경우 배팅만 종료
				}
				if (bet) { // 배팅을 할 때
					cout << "Command list(hit/stand)" << endl; 
					cout << "CMD>> ";
					cin >> command; // 커맨드 입력
				}
				if (strcmp(command, "hit") == 0) { // command가 hit일 때는
					Deck.hit_player(&Player, &dealer, &Discard); // 덱에서 플레이어에게 카드를 준다
					if (Player.sum() > 21) { // 플레이어의 카드가 21보다 클 때
						stand = true; // 강제적으로 stand를 한다.
					}
				}
				else if (strcmp(command, "stand") == 0) { // 커맨드가 stand인지 확인
					if (dealer.sum() <= 16) { // 딜러의 카드의 합이 16이하 일때는 카드를 받는다.
						Deck.hit_Dealer(&Player, &dealer, &Discard); // 덱에서 딜러에게 카드를 주는 매소드 호출
					}
					stand = true; // 딜러가 카드를 다받았으면 비교를 위해 stand를 한다.
				}
				else {
					cout << "Wrong Command!" << endl; // 명령어를 잘못입력 했을 시
				}
			}
		}
	}
	_CrtDumpMemoryLeaks();
}