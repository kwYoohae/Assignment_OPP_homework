#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	string res;
	string rev;
	int count = 0;
	getline(cin, str); //string�� �Է¹���
	char temp = str[0]; //ó������ ���ϴ� ����
	for (int i = 0; i < str.size(); i++) {
		if (str[i] > 256 || str[i] < 0) {
			cout << "���ڸ� �߸� �Է��ϼ̽��ϴ�.";
			exit(0);
		}
		if (str[i] != temp) { //temp�� ���� �޶������ ���簪�� ���ο� res string�� �־�ΰ� ���ݱ��� count�� ���ڸ� ���� ���ο�temp�� ������ �ٽ� count����
			res.push_back(temp);
			if (count < 10) { // count �� 10 ���� ���� ���� 48('0')�� �����༭ res string �� �־��ش�.
				res.push_back(count + 48);
			}
			else { // ����ũ�ٸ� rev string�� ������ �� �ڸ��� ���ڸ� �־��ش�.
				for (; count > 0;) {
					rev.push_back(count % 10);
					count /= 10;
				}
				for (int i = rev.size() - 1; i >= 0; i--)
					res.push_back(rev[i] + 48); // �Ųٷ� ����� rev string�� �������� res string�� �־��ش�.
			}
			rev.clear();
			count = 0;
			temp = str[i];
		}
		count++;
	}
	res.push_back(temp); //������ ���� ���ڸ� res string�� ����
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