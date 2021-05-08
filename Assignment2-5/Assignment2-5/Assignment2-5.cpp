#include <iostream>
#include <stdlib.h>
using namespace std;

class Mystring
{
private:
	char* Mystr;
public:
	char* Mystrcpy(char* src, int len); //Mystring copy�ϴ� �Լ� ���� char *����ȯ
	int Find_char(char c);
	~Mystring();
};

Mystring::~Mystring() {
	delete[] Mystr; //�޸� ����
}

char* Mystring::Mystrcpy(char* src, int len) {
	Mystr = new char[len + 1]; // len + 1�� �ϴ� ������ \0�� �־��ֱ����ؼ�
	for (int i = 0; i < len; i++) {
		Mystr[i] = src[i]; //���ڿ��� ����
	}
	Mystr[len] = '\0'; //�������� '\0'���� ������ ���� ��Ÿ��
	return Mystr; //������ string�� ��ȯ
}

int Mystring::Find_char(char c) { //���� ã�� �żҵ�
	int count = -1; // �⺻���� -1�� �ʱ�ȭ
	for (int i = 0; Mystr[i] != '\0'; i++) { // '\0'�����϶� ���� ����ؼ� ���ڸ� ã�´�
		if (Mystr[i] == c) {
			count = i; //���ڸ� ã���� ����ó������ ��ȯ���ش�
			return count;
		}
	}
	return count; //������ �⺻���� -1�� ȣ���Ѵ�.
}

int main() {
	Mystring mysting; //Mystring ȣ��
	char str[100];
	int len = 0;
	char c;
	cin >> str;
	for (int i = 0; str[i] != '\0';i++) { //������ ���̸� ���ϱ� ���� �ݺ���
		len++;
	}
	cout << "Copy String : " << mysting.Mystrcpy(str, len) << endl; //mystring��ü�� mystrcpy�� ȣ���Ͽ� �� ������ ���� ��ȯ
	cin >> c;
	cout << mysting.Find_char(c); // ���ϴ� char���� ã�� ���� �żҵ带 ȣ�� �� ��ȯ �� ���
}
