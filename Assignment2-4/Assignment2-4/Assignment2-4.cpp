#include <iostream>
#include <stdlib.h>

using namespace std;

void print(int arr[][9], int number) { //배열 출력하는 함수,number는 몇번째 실행된 값인지 출력
	cout << "N =" << number << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

void copy_temp(int arr[][3], int res[][9], int number) { //곱한값을 저장
	int j_temp = 0;
	int k_temp = 0;
	if (number / 3 == 0) { //시행된 횟수에 따라서 몇번째를 해주어야하는지 if문으로 분기를 나눔
		for (int j = 0; j < 3; j++, j_temp++) { //1,2,3번째 행렬일때 값 저장
			k_temp = 0;
			for (int k = number * 3; k < (number + 1) * 3; k++, k_temp++) {
				res[j][k] += arr[j_temp][k_temp];
			}
		}
	}
	else if (number / 3 == 1) {
		for (int j = 3; j < 6; j++, j_temp++) { // 4,5,6번째 행렬일 때 값 저장
			k_temp = 0;
			for (int k = (number - (number / 3) * 3) * 3; k < ((number + 1) - (number / 3) * 3) * 3; k++, k_temp++) {
				res[j][k] += arr[j_temp][k_temp];
			}
		}
	}
	else if (number / 3 == 2) {
		for (int j = 6; j < 9; j++, j_temp++) { // 7,8,9번째 행렬일 때 값 저장
			k_temp = 0;
			for (int k = (number - (number / 3) * 3) * 3; k < ((number + 1) - (number / 3) * 3) * 3; k++, k_temp++) {
				res[j][k] += arr[j_temp][k_temp];
			}
		}
	}

}

void multiply(int A[][3], int B[][3], int temp[][3]) { // 행렬의 곱 계산
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				temp[i][j] += A[i][k] * B[k][j]; // 차례대로 뽑아온 A와 B행렬의 곱 계산해서 값 넣어주기
			}
		}
	}
}

int main() {
	int arr[9][3][3];
	int res[9][9] = { {0} };
	int arr_temp[9][9] = { {0} };
	int number = 0;
	for (int i = 0; i < 9; i++) { //arr_temp(9x9)행렬에 0~80까지 값 저장
		for (int j = 0; j < 9; j++) {
			arr_temp[i][j] = i * 9 + j;
		}
	}

	for (int i = 0; i < 9; i++) { //(0~80)이저장된 9x9행렬을 arr 9개로 3x3행렬을 나눈 3차원배열에 값들을 모두 저장
		int j_temp = 0; //저장할 3*3행렬의 row값
		int k_temp = 0; //저장할 3*3행렬의 column값
		if (i / 3 == 0) { // 0~2의 값은 row가 0~2가 저장되어야기 때문에 if문으로 분기를 나눔
			for (int j = 0; j < 3; j++, j_temp++) { //1,2,3번째 행렬 보관
				k_temp = 0;
				for (int k = i * 3; k < (i + 1) * 3; k++, k_temp++) {
					arr[i][j_temp][k_temp] = arr_temp[j][k];
				}
			}
		}
		else if (i / 3 == 1) { // 3~5까지의 값은 row가 모두 3~5이므로 if문으로 분기를 나눔
			for (int j = 3; j < 6; j++, j_temp++) { // 4,5,6번째 행렬 보관
				k_temp = 0;
				for (int k = (i - (i / 3) * 3) * 3; k < ((i + 1) - (i / 3) * 3) * 3; k++, k_temp++) {
					arr[i][j_temp][k_temp] = arr_temp[j][k];
				}
			}
		}
		else if (i / 3 == 2) {// 6~8까지의 값은 row가 모두 6~8이므로 if문으로 분기를 나눔
			for (int j = 6; j < 9; j++, j_temp++) { // 7,8,9번째 행렬 보관
				k_temp = 0;
				for (int k = (i - (i / 3) * 3) * 3; k < ((i + 1) - (i / 3) * 3) * 3; k++, k_temp++) {
					arr[i][j_temp][k_temp] = arr_temp[j][k];
				}
			}
		}
	}

	number = 1; //number변수를 n이 몇번째 계산인가에 쓰려고 1로 초기화
	for (int i = 0; i < 3; i++) { //3차원 행렬의 곱을 구현
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++, number++) {
				int temp[3][3] = { {0} };
				multiply(arr[k + (i * 3)], arr[j + (k * 3)], temp); //곱하는 함수 구현
				copy_temp(temp, res, j + (i * 3)); //0으로 초기화된 9*9행렬에 곱한 행렬 넣어서 더해주기
				print(res, number); //0으로 초기화된 행렬 출력
			}
		}
	}
}