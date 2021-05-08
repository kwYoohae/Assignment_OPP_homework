#include <iostream>
#include <stdlib.h>

using namespace std;


void print(int number,int arr[][10]) { //배열을 출력하는 함수
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			cout << arr[i][j] << "   ";
		}
		cout << '\n';
	}
}

void swap(int& a, int& b) { //두수의 값을 변경하는 함수
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main() {
	int number,temp_number;
	int arr[10][10];
	bool visited[100];
	int temp;
	srand((unsigned int)time(NULL)); // 현재시간을 시드값으로 준다 
	cout << "Array Size(0<N<11) : "; 
	cin >> number;
	if (number < 1 || number > 10) {
		cout << "문자입력을 잘못하셨습니다.";
		return 0;
	}
	for (int i = 0; i < 100; i++) {
		visited[i] = false; //vistied의 모든 값을 false로 초기화
	}

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			temp = rand() % 100; // 0~ 99까지의 숫자를 랜덤으로 생성
			if (visited[temp] == true) { // 만약에 이미 생성했던 값이면 다른 값이 나올 때까지 랜덤난수 생성
				while (visited[temp]) {
					temp = rand() % 100;
				}
			}
			arr[i][j] = temp; // 0 ~ 99까지의 숫자를 랜덤하게 배열에 저장
			visited[temp] = true; // 이 숫자가 생성됬다는 것을 알림
		}
	}
	print(number,arr);

	for (int i = 0; i < number * number; i++) { //2차원 배열을 1차원을 생각하여 i/number 과 i%number로 나누어서 선택정렬을 진행함
		for (int j = i + 1; j < number * number; j++) {
			if (arr[i / number][i % number] > arr[j / number][j % number])
				swap(arr[i / number][i % number], arr[j / number][j % number]);
		}
	}
	cout << '\n';
	print(number,arr);
}

