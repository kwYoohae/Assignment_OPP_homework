#include <iostream>
#include <Windows.h>

using namespace std;
#define MAX 5



void print(char arr[][MAX]) { //arr를 그리는 함수이다.
	system("cls"); //콘솔창을 지운다.
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

bool move_valid(char temp, int row, int column , char arr[][MAX]) {
	bool possible = true;
	if (temp == 'a') { // 왼쪽으로 갈 수 있는지 판단한다. 왼쪽 끝에 있는경우도 판별한다.
		if (column == 0 || arr[row][column - 1] == 'a')
			possible = false;
	}
	else if (temp == 's') { // 밑으로 갈 수 있는지 판단한다. 제일 밑에 있는 경우도 판별한다.
		if (row == MAX - 1 || arr[row + 1][column] == 'a')
			possible = false;
	}
	else if (temp == 'd') { // 오른쪽으로 갈 수 있는지 판단한다. 제일 오른 쪽에 있는 경우도 판별한다.
		if (column == MAX - 1 || arr[row][column + 1] == 'a')
			possible = false;
	}
	else if (temp == 'w') { // 위쪽으로 갈 수 있는지 판단한다 제일 위쪽에 있는 경우도 판별한다.
		if (row == 0 || arr[row - 1][column] == 'a')
			possible = false;
	}
	return possible;
}

bool valid(int row, int column , int visited[][MAX]) {
	bool row_possible = true; //상,하로 갈 수 있는지 판단하는 bool변수
	bool column_possible = true; //좌,우로 갈 수 있는지 판단하는 bool변수
	if (row == 0 && visited[row + 1][column] == 1) //상하로 갈 수 있는 지 판단한다. (제일위에있는 경우와 제일 밑에 있는 경우도 생각해준다.)
		row_possible = false; 
	else if (row == MAX - 1 && visited[row - 1][column] == 1)
		row_possible = false;
	else if (visited[row - 1][column] == 1 && visited[row + 1][column] == 1)
		row_possible = false;

	if (column == 0 && visited[row][column + 1] == 1) //좌우로 갈 수 있는지 판단한다.(왼쪽끝 오른쪽 끝에 있는 경우도 판단해준다.)
		column_possible = false;
	else if (column == MAX - 1 && visited[row][column - 1] == 1)
		column_possible = false;
	else if (visited[row][column - 1] == 1 && visited[row][column + 1] == 1)
		column_possible = false;
	if (row_possible == false && column_possible == false) //상하와 좌우가 모두 갈 수 없다면 false를 반환 한곳이라도 갈 수 있으면 true를 반환
		return false;
	else
		return true;
}

int main() {
	bool End = true; //arr가 이동이 가능한지 판별하는 bool변수
	char arr[MAX][MAX]; //5x5의 배열
	int visited[MAX][MAX]; //arr가 방문했는지를 알려주는 변수
	for (int i = 0; i < MAX; i++) { // 변수를 arr == '0'으로 visited는 모두 false로 초기화
		for (int j = 0; j < MAX; j++) {
			arr[i][j] = '0';
			visited[i][j] = 0;
		}
	}
	arr[0][0] = 'a'; //arr첫 시작은 a이므로 대입
	visited[0][0] = 1; // 0,0은 a이므로 방문했다고 체크
	char Command; // command를 받는 변수
	int a_row = 0, a_column = 0; //지금 위치를 알려주는 변수
	while (End) { // End라는 bool 변수가 true 일때만 계속해서 반복
		print(arr); //arr를 출력
		cout << "Command : "; 
		cin >> Command; 
		if (Command == 'a') { //커맨드가 a일 때 확인
			if (move_valid(Command, a_row, a_column,arr)) { //갈수있는 장소있지 판별하는 move_valid함수를 불러옴
				a_column--; // a로 갈때는 column이 -1이기때문에 위치를 바꾸어줌
				arr[a_row][a_column] = 'a'; //바꾼위치에 도착했기 때문에 'a'를입력
				visited[a_row][a_column] = 1; //visited = ture
			}
		}
		else if (Command == 's') {
			if (move_valid(Command, a_row, a_column, arr)) {//갈수있는 장소있지 판별하는 move_valid함수를 불러옴
				a_row++; // s는 밑으로 한칸이기 때문에 a_row를 ++
				arr[a_row][a_column] = 'a';
				visited[a_row][a_column] = 1;
			}
		}
		else if (Command == 'w') {
			if (move_valid(Command, a_row, a_column, arr)) {//갈수있는 장소있지 판별하는 move_valid함수를 불러옴
				a_row--; // w를 위로 한칸이기때문에 a_row를 --해준다
				arr[a_row][a_column] = 'a';
				visited[a_row][a_column] = 1;
			}
		}
		else if (Command == 'd') {
			if (move_valid(Command, a_row, a_column, arr)) {//갈수있는 장소있지 판별하는 move_valid함수를 불러옴
				a_column++; // d는 오른쪽으로 한칸이므로 a_column을 -- 해준다.
				arr[a_row][a_column] = 'a';
				visited[a_row][a_column] = 1;
			}
		}
		else {
			cout << "잘못된 입력입니다."; //Command이외의 변수가 입력되면 다시 입력하게한다.
			Sleep(1000); // 잘못된 입력입니다를 1초동안 보여주고 밑에서 다시 redraw한다.
		}
		End = valid(a_row, a_column, visited); // 현재 위치에서 위 아래 오른쪽 왼쪽으로 갈 수 있는지 판단한다. 아니면 End = false 가되고 반복문이 종료됨
	}
	print(arr);
	cout << "Command : END";
}