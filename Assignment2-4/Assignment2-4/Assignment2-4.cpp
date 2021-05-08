#include <iostream>
#include <stdlib.h>

using namespace std;

void print(int arr[][9], int number) { //�迭 ����ϴ� �Լ�,number�� ���° ����� ������ ���
	cout << "N =" << number << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

void copy_temp(int arr[][3], int res[][9], int number) { //���Ѱ��� ����
	int j_temp = 0;
	int k_temp = 0;
	if (number / 3 == 0) { //����� Ƚ���� ���� ���°�� ���־���ϴ��� if������ �б⸦ ����
		for (int j = 0; j < 3; j++, j_temp++) { //1,2,3��° ����϶� �� ����
			k_temp = 0;
			for (int k = number * 3; k < (number + 1) * 3; k++, k_temp++) {
				res[j][k] += arr[j_temp][k_temp];
			}
		}
	}
	else if (number / 3 == 1) {
		for (int j = 3; j < 6; j++, j_temp++) { // 4,5,6��° ����� �� �� ����
			k_temp = 0;
			for (int k = (number - (number / 3) * 3) * 3; k < ((number + 1) - (number / 3) * 3) * 3; k++, k_temp++) {
				res[j][k] += arr[j_temp][k_temp];
			}
		}
	}
	else if (number / 3 == 2) {
		for (int j = 6; j < 9; j++, j_temp++) { // 7,8,9��° ����� �� �� ����
			k_temp = 0;
			for (int k = (number - (number / 3) * 3) * 3; k < ((number + 1) - (number / 3) * 3) * 3; k++, k_temp++) {
				res[j][k] += arr[j_temp][k_temp];
			}
		}
	}

}

void multiply(int A[][3], int B[][3], int temp[][3]) { // ����� �� ���
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				temp[i][j] += A[i][k] * B[k][j]; // ���ʴ�� �̾ƿ� A�� B����� �� ����ؼ� �� �־��ֱ�
			}
		}
	}
}

int main() {
	int arr[9][3][3];
	int res[9][9] = { {0} };
	int arr_temp[9][9] = { {0} };
	int number = 0;
	for (int i = 0; i < 9; i++) { //arr_temp(9x9)��Ŀ� 0~80���� �� ����
		for (int j = 0; j < 9; j++) {
			arr_temp[i][j] = i * 9 + j;
		}
	}

	for (int i = 0; i < 9; i++) { //(0~80)������� 9x9����� arr 9���� 3x3����� ���� 3�����迭�� ������ ��� ����
		int j_temp = 0; //������ 3*3����� row��
		int k_temp = 0; //������ 3*3����� column��
		if (i / 3 == 0) { // 0~2�� ���� row�� 0~2�� ����Ǿ�߱� ������ if������ �б⸦ ����
			for (int j = 0; j < 3; j++, j_temp++) { //1,2,3��° ��� ����
				k_temp = 0;
				for (int k = i * 3; k < (i + 1) * 3; k++, k_temp++) {
					arr[i][j_temp][k_temp] = arr_temp[j][k];
				}
			}
		}
		else if (i / 3 == 1) { // 3~5������ ���� row�� ��� 3~5�̹Ƿ� if������ �б⸦ ����
			for (int j = 3; j < 6; j++, j_temp++) { // 4,5,6��° ��� ����
				k_temp = 0;
				for (int k = (i - (i / 3) * 3) * 3; k < ((i + 1) - (i / 3) * 3) * 3; k++, k_temp++) {
					arr[i][j_temp][k_temp] = arr_temp[j][k];
				}
			}
		}
		else if (i / 3 == 2) {// 6~8������ ���� row�� ��� 6~8�̹Ƿ� if������ �б⸦ ����
			for (int j = 6; j < 9; j++, j_temp++) { // 7,8,9��° ��� ����
				k_temp = 0;
				for (int k = (i - (i / 3) * 3) * 3; k < ((i + 1) - (i / 3) * 3) * 3; k++, k_temp++) {
					arr[i][j_temp][k_temp] = arr_temp[j][k];
				}
			}
		}
	}

	number = 1; //number������ n�� ���° ����ΰ��� ������ 1�� �ʱ�ȭ
	for (int i = 0; i < 3; i++) { //3���� ����� ���� ����
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++, number++) {
				int temp[3][3] = { {0} };
				multiply(arr[k + (i * 3)], arr[j + (k * 3)], temp); //���ϴ� �Լ� ����
				copy_temp(temp, res, j + (i * 3)); //0���� �ʱ�ȭ�� 9*9��Ŀ� ���� ��� �־ �����ֱ�
				print(res, number); //0���� �ʱ�ȭ�� ��� ���
			}
		}
	}
}