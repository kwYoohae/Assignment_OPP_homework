#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	getline(cin, str); //string�� �Է¹���
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') { //���� �빮���� ��쿡 +32�� ���ؼ� �ҹ��ڷ� ��������
			str[i] += 32;
		}
		else if (str[i] < 'a' || str[i] >'z') {
			str.erase(str.begin() + i); //�ҹ��ڰ� �ƴѰ����� erase�Լ��� �̿��� ������
			i--; // str.size()�� 1�� ������� ������ �ε����� �ٿ���
		}
	}
	cout << str;
}
