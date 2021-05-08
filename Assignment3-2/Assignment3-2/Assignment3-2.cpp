#include <iostream>
#include "node.h"
#include "queue.h"


using namespace std;

int is_Enqueue(char* command) { // Enqueue 라고 입력이 잘 되었는지 확인하는 함수
	int count = 0; // 공백의 개수를 확인
	int number = 0; // atoi(단어를 숫자로 변경하여 저장)

	for (int i = 7; i < strlen(command); i++) { //Enqueue 이후의 공백이 얼마나 있는지 확인
		if (command[i] == ' ')
			count++; // 공백이 있을 때 마다 갯수를 샌다
	}
	if(count == 1){ // 공백은 하나만 있어야함
		for (int i = 8; i < strlen(command); i++) { //문자를 숫자로 변환하기 위한 for문
			if (command[7] == ' ') { // Enqueue다음이 공백일 때만 반복문처리
				if (command[i] - '0' > 9 || command[i] - '0' < 0) //숫자일 때만 처리
					return -1; //숫자가 아니면 -1반환
				number += command[i] - '0'; // number에 읽어든 값에 '0'을 빼서 숫자로 변환
				number *= 10; //*10을 해줌 계속
			}
			else
				return -1;//Enqueue 다음 값이 공백이 아니면 -1반환
		}
		return number / 10; //number의 값을 변환하면 *10이 많아지기 때문에 10을 나눠서 반환
	}
	else {
		return -1; //공백이 여러개면 -1을 반환
	}
}

int is_Dequeue(char* command, int count) { // Dequeue를 제대로 입력했는지 확인하는 함수
	int number = 0; // 단어를 숫자로 변경하기 위한 변수
	int count_wspace = 0; //공백의 갯수를 세는 변수
	for (int i = 7; i < strlen(command); i++) {
		if (command[i] == ' ') //Dequeue 이후 공백이 몇개인지 확인
			count_wspace++;
	}
	if (count_wspace != 1) //공백이 한개보다 많으면
		return -1; // -1을 반환
	else {
		for (int i = 8; i < strlen(command); i++) {
			if (command[7] == ' ') { //Dequeue다음은 항상 공백일 때
				if (command[i] - '0' > 9 || command[i] - '0' < 0) 
					return -1;// 숫자가 아닐 때 -1 반환
				number += command[i] - '0'; // 숫자를 문자로 -'0'을 해주어 변환
				number *= 10; // 숫자에 10을 곱해줌
			}
			else
				return -1;//Dequeue다음에 공백이 아닐 때는 -1반환
		}
		return number / 10; //반복문을 돌고오면 10만큼이 많이 때문에 /10을 해주어 반환
	}
}

int is_Search(char* command) { // Search가 제대로 입력되었는지 확인
	int number = 0; //문자를 숫자로 변환 하는 변수
	int count_wspace = 0; // 공백의 갯수확인
	for (int i = 6; i < strlen(command); i++) {
		if (command[i] == ' ') // 공백의 갯수를 체크
			count_wspace++;
	}
	if (count_wspace != 1) //공백이 1보다 많을 때
		return -1; //-1을 반환
	else {
		for (int i = 7; i < strlen(command); i++) {
			if (command[6] == ' ') { //SEARCH 단어 뒤에 공백인지 아닌지 확인
				if (command[i] - '0' > 9 || command[i] - '0' < 0) //숫자가 아닐경우
					return -1; // -1을 반환
				number += command[i] - '0'; // - '0'을 해주어서 문자를 숫자로 바꿈
				number *= 10; //자릿수를 더해줌
			}
			else
				return -1; // SEARCH다음에 공백이 아닐경우에 -1을 반환
		}
		return number / 10; //한자릿수 많기 때문에 /10을 해준다
	}
}

int main() {
	queue Queue; //큐를 선언
	bst Bst; //이진트리를 선언
	char command[20]; //명령어를 입력받는 변수
	int data; // 데이터 값을 받는 변수
	int count = 0; //지금까지 Queue의 값이 얼마나 있는지 확인하는 변수
	int count_bst = 0; //bst의 문자가 얼마나 저장되었는지 확인하는 변수
	bool end = true; //반복문을 돌리기 위한 함수
	while (end) {
		cin.getline(command , 20); //명령어 입력
		//cout << is_Enqueue(command) << endl;
		if (strncmp(command, "Enqueue" , 7) == 0) { //Enqueue가 맞을 때
			if (is_Enqueue(command) == -1) {//명령어가 진짜 Enqueue인지 함수를 통해 형식 확인 후 아닐 때
				cout << "Error 200" << endl; //Error메시지 출력
			}
			else {
				Queue.Enqueue(is_Enqueue(command) , &count); // 맞을 때는 Enqueue에 입력한 값을 Queue의 Enqueue매소드를 호출
			}
			
		}
		else if (strncmp(command, "Dequeue", 7) == 0) { // Dequeue가 맞는지 확인
			if (is_Dequeue(command, count) == -1) { //명령어가 Dequeue의 입력 형식이 안맞을 경우
				cout << "Error 200" << endl; //에러메시지 출력
			}
			else if (count == 0) { // 입력한 Queue가 없을 경우
				cout << "Error 400" << endl; //에러메시지 출력
			}
			else if (is_Dequeue(command, count) >= count) { //Dequeue의 개수가 현재 존재하는 Queue의 개수보다 많을 경우
				Queue.All_Dequeue(&count, &Bst); //모든 queue를 삭제하는 매소드 호출
			}
			else {
				Queue.Dequeue(is_Dequeue(command,count),&count, &Bst); //입력한 개수만큼 queue를 삭제하는 매소드 호출
			}
		}
		else if (strcmp(command, "Print_Queue") == 0) { //Print_Queue가 맞는지 확인
			if (count == 0) { // 출력할 Queue가 하나도 없는 경우
				cout << "Error 500" << endl; //에러메시지 호출
			}
			else {
				Queue.Print_Queue(); //Queue가 1개이상 존재하는 경우 출력하는 매소드 호출
			}
		}
		else if (strcmp(command, "PRINT POST") == 0) { //PRINT POST가 맞는지 확인
			if (Bst.is_Empty()) { // BST가 비어있는지 확인
				cout << "Error 700" << endl; //비어있을 때 에러메시지 호출
			}
			else {
				Bst.Print_Post(Bst.getRoot()); //아닐 때 전위 순회로 값들을 출력
				std::cout << '\n';
			}
		}
		else if (strcmp(command, "PRINT IN") == 0) { //PRINT IN이 맞는지 확인
			if (Bst.is_Empty()) { // BST가 비어있는지 확인
				cout << "Error 700" << endl;//비어있을 때 에러메시지 호출
			}
			else {
				Bst.Print_in(Bst.getRoot()); //아닐 때 중위 순회로 값들을 출력
				std::cout << '\n';
			}
		}
		else if (strcmp(command, "PRINT PRE") == 0) { // PRINT PRE가 맞는지 확인
			if (Bst.is_Empty()) { //BST가 비어있는지 확인
				cout << "Error 700" << endl; //비어있을 때 에러메시지 호출
			}
			else {
				Bst.Print_Pre(Bst.getRoot()); //BST를 후위 순회로 값을 출력
				std::cout << '\n';
			}
		}
		else if (strncmp(command, "SEARCH", 6) == 0) { //SEARCH가 맞는지 확인
			int search_number = is_Search(command); //SEARCH하는 data가 얼마인지 값을 확인
			if (search_number == -1) { // -1일경우 SEARCH의 입력형식이 잘못된것
				cout << "Error 200" << endl; // 에러메시지 호출
			}
			else {
				if (Bst.Search(search_number) == -1) { // SEARCH메소드에서 값이 없을 때
					cout << "Error 600" << endl; //에러메시지 호출
				}
				else {
					cout << Bst.Search(is_Search(command)) << "is exists" << endl; // SEARCH값이 있을 때 SEARCH하는 값을 출력
				}
			}
		}
		else if (strcmp(command, "EXIT") == 0) { //반복문 종료
			end = false; //end의 값을 false로 설정
		}
		else {
			cout << "Error 100" << endl; //명령어를 잘못 입력 했을 경우 에러메시지 출력
		}
	}
	return 0;
}