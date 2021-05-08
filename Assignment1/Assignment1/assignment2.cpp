#include <iostream>

using namespace std;


void print(int number,int arr[][9]) { //array를 출력하는 함수
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	int direction;
	int arr[9][9];
	int number;
	cout << "Array Size(0<N<10):";
	cin >> number;
	if (number <= 0 || number >= 10) { // 1~9까지의 값 이외의 값을 입력하면 종료시킨다.
		cout << "숫자를 잘못 입력하셨습니다.";
		exit(0);
	}
	for (int i = 0; i < number; i++) { //값을 1로 초기화시킴
		for (int j = 0; j < number; j++) {
			arr[i][j] = 1;
		}
	}
	print(number, arr);
	cout << "Shift All Direction:";
	cin >> direction;
	if (direction < 0 || direction > 5) { //정해진 direction이외의 값이 들어가면 강제종료
		cout << "숫자를 잘못 입력하셨습니다.";
		exit(0);
	}
	if (direction == 0) { 
		for (int i = number - 1; i >= 0; i--) { //행렬의 밑부터 시작
			for (int j = 0; j < number; j++) {
				if (i > 0) {
					arr[i - 1][j] += arr[i][j]; //밑에있는 값들을 자신의 값만큼 한칸위의 값에 더해줌
					arr[i][j] -= arr[i][j]; // 자신의 값은 지움
				}
			}
		}
	}
	else if (direction == 1) {
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				if (i < number -1) {
					arr[i + 1][j] += arr[i][j]; //행렬을 아래로 밀기위해서 한칸아래의 값에 자신의 값을 더해줌
					arr[i][j] -= arr[i][j]; //자신의 값은 지움
				}
			}
		}
	}
	else if (direction == 2) {
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				if (j < number - 1) {
					arr[i][j + 1] += arr[i][j]; //오른쪽으로 몰기위해서 자신의 값을 오른쪽에 있는값에 더해줌
					arr[i][j] -= arr[i][j];//자신의 값은 지움
				}
			}
		}
	}
	else if (direction == 3) {
		for (int i = number - 1; i >= 0 ; i--) {
			for (int j = number - 1; j >= 0; j--) {
				if (j > 0) {
					arr[i][j - 1] += arr[i][j]; // 왼쪽으로 몰기위해 자신의 값을 자신 왼쪽값에 더해줌
					arr[i][j] -= arr[i][j];//자신의 값은 지움
				}
			}
		}
	}
	else if (direction == 4) {
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				if (j > 0) { //j가 0일때는 더해짐을 받는 값이기 때문에 건들지 않음
					if (i != number - 1) { //제일 밑에 있는 값은 최종적으로 값을 가지고 있어야함으로 아닐때만 코드가 실행되게함
						arr[i + 1][j - 1] += arr[i][j]; //한칸 아래 왼쪽에 자신의 값을 더해줌
						arr[i][j] -= arr[i][j];//자신의 값은 지움
					}
				}
			}
		}
	}
	else if (direction == 5) {
		for (int i = number-1 ; i >= 0; i--) {
			for (int j = 0; j < number; j++) {
				if (i > 0) { //제일 위에값은 더해짐을 받는 값이기 때문에 건들지 않음
					if (j != number - 1) {//제일 오른쪽에 있는 값은 최종적으로 값을 가지는 값이므로 건들지 않음
						arr[i - 1][j + 1] += arr[i][j]; // 한칸위 오른쪽에 값을 자신의 값을 더해줌
						arr[i][j] -= arr[i][j]; //자신의 값은 지움
					}
				}
			}
		}
	}
	print(number, arr); //값 출력
}