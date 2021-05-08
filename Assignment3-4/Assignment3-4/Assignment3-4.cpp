#include <iostream>
#include "Node.h"
#include "Deck.h"
#include "Discard_tray.h"
#include "Player.h"
#include <crtdbg.h>
using namespace std;

void who_is_winner(int player_sum, int dealer_sum) { //���и� �����ϴ� �Լ�
	int player_res = 21 - player_sum; // ���� 21�� �� ��������� Ȯ���ϴ� ����
	int dealer_res = 21 - dealer_sum; // ���� 21�� �� ��������� Ȯ���ϴ� ����
	if (player_sum > 21) { // ���� player�� 21�� �ʰ��ؼ� ī�带 ������� Lose�� ���
		cout << "Player Lose!" << endl;
	}
	else if (dealer_sum > 21) { // ���� ������ ī�尡 21�� �Ѿ����� Win�� ���
		cout << "Player Win!" << endl;
	}
	else if (player_res == dealer_res) { // ���� ������ ���ٸ� Draw�� ���
		cout << " Draw..." << endl;
	}
	else if (player_res < dealer_res) { // Player�� 21�� �� �����ٸ� Win�� ���
		cout << "Player Win!" << endl;
	}
	else if (player_res > dealer_res) { // Player�� 21�� �� �ִٸ� Lose�� ���
		cout << "Player Lose!" << endl;
	}
}

int main() {
	deck Deck; //��ü ����
	player Player; // ��ü ����
	Dealer dealer; // ��ü ����
	discard Discard; // ��ü ����
	char command[20]; // ��ɾ� �Է�
	bool end = true; //������ ����ϴ� �ݺ����� �����Դ� bool�� ����
	bool game = false; // game�� �����ϴ��� �Ǵ��ϴ� bool�� ����
	bool bet = false; // bet�� �����ϴ��� �Ǵ��ϴ� bool�� ����
	bool stand = false; // stand�� �ϴ��� �Ǵ��ϴ� bool�� ����
	while (end) {
		if (!game) { // game�� false(���۾����� ��)
			cout << "Command list(game/shuffle/exit)" << endl;
			cout << "CMD>> ";
			cin >> command; // ��ɾ� �Է¹���
			if (strcmp(command, "game") == 0) { // �Է��� Ŀ�ǵ尡 game�� ��
				if (Deck.deck_count() == 52) // ī�� ��ü�� ���� �ִ��� Ȯ��
					game = true; // ���� ��� ī�尡 ������ ���ӽ���
				else
					cout << "Not Enough Cards" << endl; // ���� ��� ī�尡 ���� �� Not Enough Cards ���
			}
			else if (strcmp(command, "shuffle") == 0) { // �Է��� Ŀ�ǵ尡 shuffle�� ��
				int number; // ������ Ƚ���� �Ǵ� �ϴ� ����
				cin >> number; // ������ Ƚ�� �Է�
				Deck.shuffle(number, &Player, &Discard); // ������ �ϴ� �żҵ� ȣ��
			}
			else if (strcmp(command, "exit") == 0) { // ������ ����
				dealer.delete_card(); // dealer�� ������ �ִ� ��� ���(ī��) ���� 
				Player.delete_card(); // player�� ������ �ִ� ��� ���(ī��) ����
				Discard.delete_card(); // discard_tray�� �ִ� ��� ���(ī��) ����
				Deck.delete_deck(); // ���� �ִ� ��� ���(ī��) ���� 
				end = false; // �ݺ��� ����
			}
			else {
				cout << "Wrong Command!" << endl; // �ΰ��� Ŀ�ǵ尡 �ƴ� �� Ʋ�� Ŀ�ǵ��� ���
			}
		}
		else {	
			if (!bet) { // bet�� false�϶�
				cout << "Command list(bet/end)" << endl;
				cout << "CMD>> ";
				cin >> command; //��ɾ� �Է�
				if (strcmp(command, "bet") == 0) { // ��ɾ bet�� ���
					dealer.delete_card(); // ������ ��� ī�� ����
					Player.delete_card(); // �÷��̾��� ��� ī�� ����
					bet = true; // bet ����
					stand = false; // stand�� �⺻�� ����
					for (int i = 0; i < 2; i++) { // ������ �÷��̾�� ���� ������ ī�带 ��
						Deck.hit_Dealer(&Player, &dealer, &Discard);
						Deck.hit_player(&Player, &dealer, &Discard);
					}
				}
				else if (strcmp(command, "end") == 0) { // ��ɾ end���� �Ǵ�
					dealer.delete_card(); // ������ ��� ī�� ����
					Player.delete_card(); // �÷��̾��� ��� ī�� ����
					game = false; // game ����
				}
				else {
					cout << "Wrong Command!" << endl; // Ʋ����ɾ� �Է½� ���
				}
				
			}
			else {
				if (!stand) { // stand�� false�� ��(���ĵ带 ������ ��)
					dealer.print(stand); // dealer�� ī�� ���(stand�� false �� ��쿡�� ù�� ° ī�带 ���� ���
					Player.print(); // �÷��̾��� ī�� ���
				}
				else { // stand�� ������ ��
					dealer.print(stand); // ������ ī�� ��� (stand�� true �� ���� ��� ī�带 ���)
					Player.print(); // �÷��̾��� ī�� ���
					who_is_winner(Player.sum(), dealer.sum()); //���� �̰���� �Ǵ�
					if (Deck.deck_count() <= 13) { // ���� ���� ���� ī�尡 13�� ���ϸ� 
						cout << "Not Enough Card" << endl; // Not Enough Card ���
						dealer.delete_card(); // ������ ī�� ����
						Player.delete_card(); // �÷��̾��� ī�� ����
						bet = false; // ���� ����
						game = false; // ���� ����
					}
					bet = false; // �ƴҰ�� ���ø� ����
				}
				if (bet) { // ������ �� ��
					cout << "Command list(hit/stand)" << endl; 
					cout << "CMD>> ";
					cin >> command; // Ŀ�ǵ� �Է�
				}
				if (strcmp(command, "hit") == 0) { // command�� hit�� ����
					Deck.hit_player(&Player, &dealer, &Discard); // ������ �÷��̾�� ī�带 �ش�
					if (Player.sum() > 21) { // �÷��̾��� ī�尡 21���� Ŭ ��
						stand = true; // ���������� stand�� �Ѵ�.
					}
				}
				else if (strcmp(command, "stand") == 0) { // Ŀ�ǵ尡 stand���� Ȯ��
					if (dealer.sum() <= 16) { // ������ ī���� ���� 16���� �϶��� ī�带 �޴´�.
						Deck.hit_Dealer(&Player, &dealer, &Discard); // ������ �������� ī�带 �ִ� �żҵ� ȣ��
					}
					stand = true; // ������ ī�带 �ٹ޾����� �񱳸� ���� stand�� �Ѵ�.
				}
				else {
					cout << "Wrong Command!" << endl; // ��ɾ �߸��Է� ���� ��
				}
			}
		}
	}
	_CrtDumpMemoryLeaks();
}