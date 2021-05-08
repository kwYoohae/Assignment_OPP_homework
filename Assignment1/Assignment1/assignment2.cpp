#include <iostream>

using namespace std;


void print(int number,int arr[][9]) { //array�� ����ϴ� �Լ�
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
	if (number <= 0 || number >= 10) { // 1~9������ �� �̿��� ���� �Է��ϸ� �����Ų��.
		cout << "���ڸ� �߸� �Է��ϼ̽��ϴ�.";
		exit(0);
	}
	for (int i = 0; i < number; i++) { //���� 1�� �ʱ�ȭ��Ŵ
		for (int j = 0; j < number; j++) {
			arr[i][j] = 1;
		}
	}
	print(number, arr);
	cout << "Shift All Direction:";
	cin >> direction;
	if (direction < 0 || direction > 5) { //������ direction�̿��� ���� ���� ��������
		cout << "���ڸ� �߸� �Է��ϼ̽��ϴ�.";
		exit(0);
	}
	if (direction == 0) { 
		for (int i = number - 1; i >= 0; i--) { //����� �غ��� ����
			for (int j = 0; j < number; j++) {
				if (i > 0) {
					arr[i - 1][j] += arr[i][j]; //�ؿ��ִ� ������ �ڽ��� ����ŭ ��ĭ���� ���� ������
					arr[i][j] -= arr[i][j]; // �ڽ��� ���� ����
				}
			}
		}
	}
	else if (direction == 1) {
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				if (i < number -1) {
					arr[i + 1][j] += arr[i][j]; //����� �Ʒ��� �б����ؼ� ��ĭ�Ʒ��� ���� �ڽ��� ���� ������
					arr[i][j] -= arr[i][j]; //�ڽ��� ���� ����
				}
			}
		}
	}
	else if (direction == 2) {
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				if (j < number - 1) {
					arr[i][j + 1] += arr[i][j]; //���������� �������ؼ� �ڽ��� ���� �����ʿ� �ִ°��� ������
					arr[i][j] -= arr[i][j];//�ڽ��� ���� ����
				}
			}
		}
	}
	else if (direction == 3) {
		for (int i = number - 1; i >= 0 ; i--) {
			for (int j = number - 1; j >= 0; j--) {
				if (j > 0) {
					arr[i][j - 1] += arr[i][j]; // �������� �������� �ڽ��� ���� �ڽ� ���ʰ��� ������
					arr[i][j] -= arr[i][j];//�ڽ��� ���� ����
				}
			}
		}
	}
	else if (direction == 4) {
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				if (j > 0) { //j�� 0�϶��� �������� �޴� ���̱� ������ �ǵ��� ����
					if (i != number - 1) { //���� �ؿ� �ִ� ���� ���������� ���� ������ �־�������� �ƴҶ��� �ڵ尡 ����ǰ���
						arr[i + 1][j - 1] += arr[i][j]; //��ĭ �Ʒ� ���ʿ� �ڽ��� ���� ������
						arr[i][j] -= arr[i][j];//�ڽ��� ���� ����
					}
				}
			}
		}
	}
	else if (direction == 5) {
		for (int i = number-1 ; i >= 0; i--) {
			for (int j = 0; j < number; j++) {
				if (i > 0) { //���� �������� �������� �޴� ���̱� ������ �ǵ��� ����
					if (j != number - 1) {//���� �����ʿ� �ִ� ���� ���������� ���� ������ ���̹Ƿ� �ǵ��� ����
						arr[i - 1][j + 1] += arr[i][j]; // ��ĭ�� �����ʿ� ���� �ڽ��� ���� ������
						arr[i][j] -= arr[i][j]; //�ڽ��� ���� ����
					}
				}
			}
		}
	}
	print(number, arr); //�� ���
}