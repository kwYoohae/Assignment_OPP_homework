#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	int* row[4];
	int* array_2D = new int[20]; //1���� �迭�� 4*5 20�� �迭�� �Ҵ�
	srand(time(0));//�����õ尪 ����
	for (int i = 0; i < 20; i++) {
		array_2D[i] = rand() % 20;
		if (i % 5 == 0) {
			row[i / 5] = &array_2D[i]; //������ ������������ ù��° �� ����
		}
	}

	for (int i = 0; i < 4; i++) { // ���
		for (int j = 0; j < 5; j++) {
			cout << row[i][j];
			cout.width(5);
		}
		cout << '\n';
	}
	cout << '\n' << '\n';

	for (int i = 0; i < 4; i++) { // ���������� ����� ���� �������ش�.
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

	for (int i = 0; i < 4; i++) { // ���
		for (int j = 0; j < 5; j++) {
			cout << row[i][j];
			cout.width(5);
		}
		cout << '\n';
	}

	delete[] array_2D; //array_2D�� �Ҵ��� �޸� ����
}