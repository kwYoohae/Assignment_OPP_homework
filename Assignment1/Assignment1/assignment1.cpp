#include <iostream>

using namespace std;

int main() {
	long long first = 1; // 50번째부터는 숫자가 많이 커지므로 오버플로우가 일어나지 않게 long long으로 선언해준다.
	long long second = 1;
	long long Fibo,number;
	cout << "Number:";
	cin >> number;
	if (number < 1 || number > 50) { //범위 이외의 값을 입력했을 경우에는 프로그램을 종료시킴
		cout << "값을 잘못입력하셨습니다." << endl; 
		exit(0);
	}
	for (int i = 2; i < number; i++) { // 피보나치 수열에서 1이랑 2번째 일때는 1이므로 제외하고 3번째부터 시작한다
		Fibo = first + second; // Fibo() = Fibo(n-1) + Fibo(n-2)이므로 이 행위를 반복한다.
		first = second;
		second = Fibo;
	}
	if (number == 1 || number == 2)
		cout << first;
	else
		cout << Fibo;

}