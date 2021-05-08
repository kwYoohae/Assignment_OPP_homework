#include <iostream>
#include <string>

using namespace std;

bool valid_fomulas(string& str, int count,int index, bool cmp); //���� �������� �Ǵ� �� bool������ ��ȯ
bool valid_input(string& str); //�Է½� �߸��� ���ڰ� �ִ��� Ȯ���Ѵ�. ������ faulty�� ���

int main() {
	string str;
	bool integrity = true; //���� �������� �ƴ��� �Ǻ����ϴ� ����
	int count = 0;
	cout << "formula:";
	getline(cin, str);
	if (valid_input(str)) { // input�� ���������� �Ǻ������� ���ڸ� �޾Ҵ��� �Ǻ�
		integrity = valid_fomulas(str, count, 0, true); // ���� �Ǻ��ϴ� �Լ��� ���
	}
	else //input�� +,-,/,*,(,),0~9,x �̿��� ���ڰ� ������ ���� ������ �ƴϹǷ� faulty�� ����ϰ� integrity�� false�Է�
		integrity = false;

	if (integrity) //integrity�� ���� true�̸� integrity�� ��� �ƴϸ� faulty�� ���
		cout << "integrity" << endl;
	else
		cout << "faulty" << endl;
}

bool valid_fomulas(string& str, int count, int index , bool cmp) {
	if (index == str.size() - 1) { // index�� string�� �������� �� (,)�� ���� ī��Ʈ�� ���� �׸��� cmp�� ��ȯ
		if (str[index] == '(')
			count++;
		else if (str[index] == ')')
			count--;
		else if (str[index] == '+' || str[index] == '-' || str[index] == '/' || str[index] == '*') //+,-,/,*�� �������� �ü� ���� ������ ������ �Ǻ�
			cmp = false;
		if (count == 0) //(�������� count�� +1�� ���ش�. (�� ������ count�� -1�� ���༭ �Ǻ��Ѵ�.
			return cmp; // ���� ��ȣ�� ¦�� ��� �¾Ƽ� count�� ������ ���� cmp�� ��ȯ���ش�.
		else
			cmp = false; // �ƴϸ� false�� cmp�� �������ְ� �ؿ� �Ŀ��� cmp�� �������ش�.
	}
	if (cmp == false) {
		return cmp;
	}
	else if (count < 0) { // count�� 0���� �������� '('��ȣ�� �����⵵���� ')'�� ���Դٴ� �Ҹ��̱� ������
		cmp = false; // ���� ������ �� ���� ������ cmp�� false��.
	}
	else {
		if (index == 0) { // index�� 0�� ���� index -1 �� ���� �������� ���� ���ܸ� �ξ� �Ǵ�
			if (str[index] == '+' || str[index] == '-' || str[index] == '/' || str[index] == '*') {
				cmp = false; //���� ���� ó������ =,-,/*�� �� �� �������� cmp = false
			}
			else if (str[index] >= '0' && str[index] <= '9') { // ���� �ٷξտ� '('�� �� �� �����Ƿ� cmp = false
				if (str[index + 1] == '(' || str[index + 1] == ')')//���� ���� ó�� ���ڰ� �����ε� ')'�� '('�� �������� �� �� ���� ������ ����ó���� ����
					cmp = false;
			}
			else if (str[index] == 'x') { // x�տ� ���ڰ� �� ��ȣ�� x�� ���� �ϰ� �ü� �������� ����ó�����ش� (index�� 0�� ��Ȳ�̱⶧����)
				if ((str[index + 1] >= '0' && str[index + 1] <= '9') || str[index + 1] == '(' || str[index + 1] == ')' || str[index + 1] == 'x')
					cmp = false;
			}
			else if (str[index] == '(') { //'('�տ��� ���ڳ� x�� )�� �ü� �������� ����ó�����ش�.
				if (str[index + 1] == '+' || str[index + 1] == '-' || str[index + 1] == '/' || str[index + 1] == '*')
					cmp = false;
				else
					count++;//'('�� ������ ��ȣ�� �Ǻ��� ���� count + 1�� ���ش�
			}
			else if (str[index] == ')')
				cmp = false; // ���� ó���� ')'�� ���� ���� ����.
		}
		else {
			if (str[index] == '+' || str[index] == '-' || str[index] == '/') { // + - / *�տ��� +,-,/,*,)�� �ü����� ������ ����ó�� ���ش�.
				if (str[index + 1] == '+' || str[index + 1] == '-' || str[index + 1] == '/' || str[index + 1] == '*' || str[index + 1] == ')')
					cmp = false;
			}
			else if (str[index] == '*') { //*�϶��� x�� 2�����̻��� �Ǹ� �ȵǱ⶧���� x�� ���ʿ� �ִ��� �Ǻ����ش�.
				if (str[index + 1] == '+' || str[index + 1] == '-' || str[index + 1] == '/' || str[index + 1] == '*' || str[index + 1] == ')')
					cmp = false;
				else if (str[index + 1] == 'x' && str[index - 1] == 'x')
					cmp = false;
			}
			else if (str[index] >= '0' && str[index] <= '9') { // ���ڴ� �տ� (�� �� �� ���� ������ ����ó���Ѵ�.
				if (str[index + 1] == '(')
					cmp = false;
			}
			else if (str[index] == 'x') { // x�տ��� ���� �Ǵ� ( �Ǵ� �ڱ� �ڽ��� �� �� ���� ������ ����ó���Ѵ�.
				if ((str[index + 1] >= '0' && str[index + 1] <= '9') || str[index + 1] == '(' || str[index + 1] == 'x')
					cmp = false;

			}
			else if (str[index] == '(') { // (�ΰ��� �տ� + - * / �� �� �� ���� ������ ����ó�����ش�. 
				if (str[index + 1] == '+' || str[index + 1] == '-' || str[index + 1] == '/' || str[index + 1] == '*')
					cmp = false;
				else
					count++; // (�� ���� count�� ++���־ ��ȣ�� �Ǵ����ش�.
			}
			else if (str[index] == ')') { // ) �ΰ�쿡�� ���ڿ� x�� �ٷ� (�� �� �� ���� ������ ����ó�����ش�.
				if ((str[index + 1] >= '0' && str[index + 1] <= '9') || str[index + 1] == 'x' || str[index +1] == '(')
					cmp = false;
				else
					count--; // ) �� ���� count�� -1 ���ص� ��ȣ�� �Ǻ��ϱ����ؼ�
			}
		}
	}
	valid_fomulas(str, count, index + 1, cmp); //��������� ���� �Ǻ��� ������ �״��� index�� �Ǻ��ϱ����ؼ� index�� +1�� ���ش�.
}

bool valid_input(string& str) {
	bool valid = true;
	for (int i = 0; i < str.size(); i++) { // (,),+,-,*,/,x�̿��� ���ڰ� ������ false�� ��ȯ
		if (str[i] == '(' || str[i] == ')' || str[i] == '+' || str[i] == '/' || str[i] == '-' || str[i] == '*' || str[i] == 'x' || (str[i] >= '0' && str[i] <= '9')) {
			valid = true;
		}
		else
			return false;
	}
	return valid;
}

