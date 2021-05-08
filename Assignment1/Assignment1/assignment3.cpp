#include <iostream>
#include <stdlib.h>

using namespace std;


void print(int number,int arr[][10]) { //�迭�� ����ϴ� �Լ�
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			cout << arr[i][j] << "   ";
		}
		cout << '\n';
	}
}

void swap(int& a, int& b) { //�μ��� ���� �����ϴ� �Լ�
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
	srand((unsigned int)time(NULL)); // ����ð��� �õ尪���� �ش� 
	cout << "Array Size(0<N<11) : "; 
	cin >> number;
	if (number < 1 || number > 10) {
		cout << "�����Է��� �߸��ϼ̽��ϴ�.";
		return 0;
	}
	for (int i = 0; i < 100; i++) {
		visited[i] = false; //vistied�� ��� ���� false�� �ʱ�ȭ
	}

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			temp = rand() % 100; // 0~ 99������ ���ڸ� �������� ����
			if (visited[temp] == true) { // ���࿡ �̹� �����ߴ� ���̸� �ٸ� ���� ���� ������ �������� ����
				while (visited[temp]) {
					temp = rand() % 100;
				}
			}
			arr[i][j] = temp; // 0 ~ 99������ ���ڸ� �����ϰ� �迭�� ����
			visited[temp] = true; // �� ���ڰ� ������ٴ� ���� �˸�
		}
	}
	print(number,arr);

	for (int i = 0; i < number * number; i++) { //2���� �迭�� 1������ �����Ͽ� i/number �� i%number�� ����� ���������� ������
		for (int j = i + 1; j < number * number; j++) {
			if (arr[i / number][i % number] > arr[j / number][j % number])
				swap(arr[i / number][i % number], arr[j / number][j % number]);
		}
	}
	cout << '\n';
	print(number,arr);
}

