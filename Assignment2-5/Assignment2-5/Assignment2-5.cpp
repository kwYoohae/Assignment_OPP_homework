#include <iostream>
#include <stdlib.h>
using namespace std;

class Mystring
{
private:
	char* Mystr;
public:
	char* Mystrcpy(char* src, int len); //Mystring copy하는 함수 구현 char *를반환
	int Find_char(char c);
	~Mystring();
};

Mystring::~Mystring() {
	delete[] Mystr; //메모리 해제
}

char* Mystring::Mystrcpy(char* src, int len) {
	Mystr = new char[len + 1]; // len + 1을 하는 이유는 \0을 넣어주기위해서
	for (int i = 0; i < len; i++) {
		Mystr[i] = src[i]; //문자열을 복사
	}
	Mystr[len] = '\0'; //마지막에 '\0'으로 문장의 끝을 나타냄
	return Mystr; //복사한 string값 반환
}

int Mystring::Find_char(char c) { //값을 찾는 매소드
	int count = -1; // 기본값을 -1로 초기화
	for (int i = 0; Mystr[i] != '\0'; i++) { // '\0'문자일때 까지 계속해서 문자를 찾는다
		if (Mystr[i] == c) {
			count = i; //문자를 찾으면 제일처음값을 반환해준다
			return count;
		}
	}
	return count; //없으면 기본값인 -1을 호출한다.
}

int main() {
	Mystring mysting; //Mystring 호출
	char str[100];
	int len = 0;
	char c;
	cin >> str;
	for (int i = 0; str[i] != '\0';i++) { //문장의 길이를 구하기 위한 반복문
		len++;
	}
	cout << "Copy String : " << mysting.Mystrcpy(str, len) << endl; //mystring객체의 mystrcpy를 호출하여 값 복사한 값을 반환
	cin >> c;
	cout << mysting.Find_char(c); // 원하는 char값을 찾기 위한 매소드를 호출 후 반환 값 출력
}
