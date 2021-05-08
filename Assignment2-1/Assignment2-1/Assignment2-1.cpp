#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	int* row[4];
	int* array_2D = new int[20]; //1차원 배열에 4*5 20개 배열을 할당
	srand(time(0));//랜덤시드값 설정
	for (int i = 0; i < 20; i++) {
		array_2D[i] = rand() % 20;
		if (i % 5 == 0) {
			row[i / 5] = &array_2D[i]; //나누어 떨어질때마다 첫번째 값 저장
		}
	}

	for (int i = 0; i < 4; i++) { // 출력
		for (int j = 0; j < 5; j++) {
			cout << row[i][j];
			cout.width(5);
		}
		cout << '\n';
	}
	cout << '\n' << '\n';

	for (int i = 0; i < 4; i++) { // 선택정렬을 사용해 값을 정렬해준다.
		for (int j = 0; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				if (row[i][j] > row[i][k]) {
					int temp = 0;
					temp = row[i][j];
					row[i][j] = row[i][k];
					row[i][k] = temp;
				}
			}
		}
	}

	for (int i = 0; i < 4; i++) { // 출력
		for (int j = 0; j < 5; j++) {
			cout << row[i][j];
			cout.width(5);
		}
		cout << '\n';
	}

	delete[] array_2D; //array_2D에 할당한 메모리 해제
}