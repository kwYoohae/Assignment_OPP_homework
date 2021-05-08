#include <iostream>

using namespace std;

void Rightprint() { //Right print 함수
	cout << "이름 : 유해찬" << endl;
	cout << "학교 : 광운대학교" << endl;
	cout << "학과 : 컴퓨터공학과" << endl;
	cout << "학번 : 2018202028" << endl;
}

void Wrongprint() { //wrong print 함수
	cout << "Wrong Password";
}

int main() {
	void(*fp)(); //함수포인터 선언
	int pawd = 0; //password 변수선언
	cout << "Please input password :";
	cin >> pawd; //패스워드 변수값 입력받기
	if (pawd == 1234) //패스워드가 1234가 맞을때는
		fp = Rightprint; //함수 포인터가 Rightprint값을 가리킴
	else
		fp = Wrongprint; //함수 포인터가 Wrongprint값을 가리킴
	fp(); //함수 호출
}