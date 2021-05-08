#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	getline(cin, str); //string을 입력받음
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') { //만약 대문자일 경우에 +32를 더해서 소문자로 변경해줌
			str[i] += 32;
		}
		else if (str[i] < 'a' || str[i] >'z') {
			str.erase(str.begin() + i); //소문자가 아닌값들은 erase함수를 이용해 제거함
			i--; // str.size()가 1이 사라졌기 때문에 인덱스도 줄여줌
		}
	}
	cout << str;
}
