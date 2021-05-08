#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	string res;
	string rev;
	int count = 0;
	getline(cin, str); //string을 입력받음
	char temp = str[0]; //처음으로 비교하는 숫자
	for (int i = 0; i < str.size(); i++) {
		if (str[i] > 256 || str[i] < 0) {
			cout << "문자를 잘못 입력하셨습니다.";
			exit(0);
		}
		if (str[i] != temp) { //temp의 값이 달라질경우 현재값을 새로운 res string에 넣어두고 지금까지 count한 숫자를 적고 새로운temp를 저장후 다시 count를함
			res.push_back(temp);
			if (count < 10) { // count 가 10 보다 작을 경우는 48('0')을 더해줘서 res string 에 넣어준다.
				res.push_back(count + 48);
			}
			else { // 만약크다면 rev string에 저장후 각 자리의 숫자를 넣어준다.
				for (; count > 0;) {
					rev.push_back(count % 10);
					count /= 10;
				}
				for (int i = rev.size() - 1; i >= 0; i--)
					res.push_back(rev[i] + 48); // 거꾸로 저장된 rev string을 뒤집에서 res string에 넣어준다.
			}
			rev.clear();
			count = 0;
			temp = str[i];
		}
		count++;
	}
	res.push_back(temp); //마지막 남은 문자를 res string에 저장
	if (count < 10) {
		res.push_back(count + 48);
	}
	else {
		for (; count > 0;) {
			rev.push_back(count % 10);
			count /= 10;
		}
		for (int i = rev.size() - 1; i >= 0; i--)
			res.push_back(rev[i] + 48);
	}
	cout << res;

}