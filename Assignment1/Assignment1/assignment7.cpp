#include <iostream>
#include <string>

using namespace std;

bool valid_fomulas(string& str, int count,int index, bool cmp); //식이 정상인지 판단 후 bool변수를 반환
bool valid_input(string& str); //입력시 잘못된 문자가 있는지 확인한다. 있으면 faulty를 출력

int main() {
	string str;
	bool integrity = true; //식이 정상인지 아닌지 판별을하는 변수
	int count = 0;
	cout << "formula:";
	getline(cin, str);
	if (valid_input(str)) { // input이 정상적으로 판별가능한 문자만 받았는지 판별
		integrity = valid_fomulas(str, count, 0, true); // 식을 판별하는 함수를 출력
	}
	else //input에 +,-,/,*,(,),0~9,x 이외의 문자가 있으면 식이 정상이 아니므로 faulty를 출력하게 integrity에 false입력
		integrity = false;

	if (integrity) //integrity에 대해 true이면 integrity를 출력 아니면 faulty를 출력
		cout << "integrity" << endl;
	else
		cout << "faulty" << endl;
}

bool valid_fomulas(string& str, int count, int index , bool cmp) {
	if (index == str.size() - 1) { // index가 string의 마지막일 때 (,)에 대한 카운트를 실행 그리고 cmp를 반환
		if (str[index] == '(')
			count++;
		else if (str[index] == ')')
			count--;
		else if (str[index] == '+' || str[index] == '-' || str[index] == '/' || str[index] == '*') //+,-,/,*는 마지막에 올수 없기 때문에 있으면 판별
			cmp = false;
		if (count == 0) //(가있으면 count에 +1을 해준다. (가 있으면 count에 -1을 해줘서 판별한다.
			return cmp; // 만약 괄호의 짝이 모두 맞아서 count가 나왔을 때는 cmp를 반환해준다.
		else
			cmp = false; // 아니면 false를 cmp에 대입해주고 밑에 식에서 cmp를 리턴해준다.
	}
	if (cmp == false) {
		return cmp;
	}
	else if (count < 0) { // count가 0보다 작은경우는 '('괄호가 나오기도전에 ')'이 나왔다는 소리이기 때문에
		cmp = false; // 식이 성립할 수 없기 때문에 cmp는 false다.
	}
	else {
		if (index == 0) { // index가 0일 때는 index -1 을 접근 못함으로 따로 예외를 두어 판단
			if (str[index] == '+' || str[index] == '-' || str[index] == '/' || str[index] == '*') {
				cmp = false; //식의 제일 처음에는 =,-,/*은 올 수 없음으로 cmp = false
			}
			else if (str[index] >= '0' && str[index] <= '9') { // 숫자 바로앞에 '('은 올 수 없으므로 cmp = false
				if (str[index + 1] == '(' || str[index + 1] == ')')//또한 식의 처음 문자가 숫자인데 ')'는 '('가 없음으로 올 수 없기 때문에 예외처리를 해줌
					cmp = false;
			}
			else if (str[index] == 'x') { // x앞에 숫자가 와 괄호와 x가 동일 하게 올수 없음으로 예외처리해준다 (index가 0인 상황이기때문에)
				if ((str[index + 1] >= '0' && str[index + 1] <= '9') || str[index + 1] == '(' || str[index + 1] == ')' || str[index + 1] == 'x')
					cmp = false;
			}
			else if (str[index] == '(') { //'('앞에는 숫자나 x나 )만 올수 있음으로 예외처리해준다.
				if (str[index + 1] == '+' || str[index + 1] == '-' || str[index + 1] == '/' || str[index + 1] == '*')
					cmp = false;
				else
					count++;//'('이 나오면 괄호의 판별을 위해 count + 1을 해준다
			}
			else if (str[index] == ')')
				cmp = false; // 제일 처음에 ')'는 나올 수가 없다.
		}
		else {
			if (str[index] == '+' || str[index] == '-' || str[index] == '/') { // + - / *앞에는 +,-,/,*,)가 올수없기 때문에 예외처리 해준다.
				if (str[index + 1] == '+' || str[index + 1] == '-' || str[index + 1] == '/' || str[index + 1] == '*' || str[index + 1] == ')')
					cmp = false;
			}
			else if (str[index] == '*') { //*일때는 x가 2차식이상이 되면 안되기때문에 x가 양쪽에 있는지 판별해준다.
				if (str[index + 1] == '+' || str[index + 1] == '-' || str[index + 1] == '/' || str[index + 1] == '*' || str[index + 1] == ')')
					cmp = false;
				else if (str[index + 1] == 'x' && str[index - 1] == 'x')
					cmp = false;
			}
			else if (str[index] >= '0' && str[index] <= '9') { // 숫자는 앞에 (만 올 수 없기 때문에 예외처리한다.
				if (str[index + 1] == '(')
					cmp = false;
			}
			else if (str[index] == 'x') { // x앞에는 숫자 또는 ( 또는 자기 자신이 올 수 없기 때문에 예외처리한다.
				if ((str[index + 1] >= '0' && str[index + 1] <= '9') || str[index + 1] == '(' || str[index + 1] == 'x')
					cmp = false;

			}
			else if (str[index] == '(') { // (인경우는 앞에 + - * / 이 올 수 없기 때문에 예외처리해준다. 
				if (str[index + 1] == '+' || str[index + 1] == '-' || str[index + 1] == '/' || str[index + 1] == '*')
					cmp = false;
				else
					count++; // (인 경우는 count를 ++해주어서 괄호를 판단해준다.
			}
			else if (str[index] == ')') { // ) 인경우에는 숫자와 x와 바로 (가 올 수 없기 때문에 예외처리해준다.
				if ((str[index + 1] >= '0' && str[index + 1] <= '9') || str[index + 1] == 'x' || str[index +1] == '(')
					cmp = false;
				else
					count--; // ) 인 경우는 count를 -1 해준데 괄호를 판별하기위해서
			}
		}
	}
	valid_fomulas(str, count, index + 1, cmp); //재귀적으로 만약 판별이 끝나면 그다음 index를 판별하기위해서 index에 +1을 해준다.
}

bool valid_input(string& str) {
	bool valid = true;
	for (int i = 0; i < str.size(); i++) { // (,),+,-,*,/,x이외의 문자가 있으면 false를 반환
		if (str[i] == '(' || str[i] == ')' || str[i] == '+' || str[i] == '/' || str[i] == '-' || str[i] == '*' || str[i] == 'x' || (str[i] >= '0' && str[i] <= '9')) {
			valid = true;
		}
		else
			return false;
	}
	return valid;
}

