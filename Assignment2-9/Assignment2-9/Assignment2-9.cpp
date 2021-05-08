#include <iostream>

using namespace std;

class Mystring // Mystring class생성
{
public:
	Mystring(const char* str); //Mystring에 매개변수를 받는 생성자
	Mystring(); // Mystring의 기본생성자
	~Mystring(); // Mystring의 소멸자
	Mystring operator +(Mystring ch) { // + 연산자를 만났을 때의 매소드 구현
		int index_ch1 = 0; // 
		int index_ch2 = 0;
		Mystring my;
		if (this->my_str[0] != '\0') {
			for (int i = 0; this->my_str[i] != '\0'; i++) {
				index_ch1 = i;
				my.my_str[i] = this->my_str[i];
			}
			index_ch1++;
		}
		for (int i = 0; ch.my_str[i] != '\0'; i++) {
			my.my_str[i + index_ch1] = ch.my_str[i];
			index_ch2 = i;
		}
		my.my_str[index_ch1 + index_ch2 + 1] = '\0';
		return my;
	}
	friend ostream& operator<< (ostream& os, const Mystring& ms); //접근권한을 풀어주는 public함수로 쓰기위해서 friend함수로 선언

private:
	char my_str[100]; // 길이가 100인 문자열 변수
};

ostream& operator<<(ostream& os, const Mystring& ms) { // outputstream을 사용하여 ms.my_str에 <<가 들어간다면 출력하도록 함수구현
	os << ms.my_str << endl;
	return os;
}

Mystring::Mystring(const char* str) //매개변수의 값을 받으면
{
	int index = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		index++; // str의 legth를 str[i] == '\0'일때까지 카운트
	}
	for (int i = 0; i < index; i++) {
		my_str[i] = str[i]; // 매개변수의 값을 private변수에 하나씩 넣어줌
	}
	my_str[index] = '\0'; // my_str의 끝에 '\0'문자를 넣어줌
}

Mystring::Mystring() { //my_str이라는 private 변수를 초기화
	my_str[0] = NULL;
}

Mystring::~Mystring() {

}


int main() {
	Mystring my_str;
	Mystring my_str2("문의는 ");
	my_str = my_str2 + "pwh7514@gmail.com로 주세요"; // my_str2 와 문자열의 합
	cout << my_str; // my_str출력
}