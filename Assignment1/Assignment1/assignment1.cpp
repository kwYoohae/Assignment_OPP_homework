#include <iostream>

using namespace std;

int main() {
	long long first = 1; // 50��°���ʹ� ���ڰ� ���� Ŀ���Ƿ� �����÷ο찡 �Ͼ�� �ʰ� long long���� �������ش�.
	long long second = 1;
	long long Fibo,number;
	cout << "Number:";
	cin >> number;
	if (number < 1 || number > 50) { //���� �̿��� ���� �Է����� ��쿡�� ���α׷��� �����Ŵ
		cout << "���� �߸��Է��ϼ̽��ϴ�." << endl; 
		exit(0);
	}
	for (int i = 2; i < number; i++) { // �Ǻ���ġ �������� 1�̶� 2��° �϶��� 1�̹Ƿ� �����ϰ� 3��°���� �����Ѵ�
		Fibo = first + second; // Fibo() = Fibo(n-1) + Fibo(n-2)�̹Ƿ� �� ������ �ݺ��Ѵ�.
		first = second;
		second = Fibo;
	}
	if (number == 1 || number == 2)
		cout << first;
	else
		cout << Fibo;

}