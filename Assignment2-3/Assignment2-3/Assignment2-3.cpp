#include <iostream>

using namespace std;

void Rightprint() { //Right print �Լ�
	cout << "�̸� : ������" << endl;
	cout << "�б� : ������б�" << endl;
	cout << "�а� : ��ǻ�Ͱ��а�" << endl;
	cout << "�й� : 2018202028" << endl;
}

void Wrongprint() { //wrong print �Լ�
	cout << "Wrong Password";
}

int main() {
	void(*fp)(); //�Լ������� ����
	int pawd = 0; //password ��������
	cout << "Please input password :";
	cin >> pawd; //�н����� ������ �Է¹ޱ�
	if (pawd == 1234) //�н����尡 1234�� ��������
		fp = Rightprint; //�Լ� �����Ͱ� Rightprint���� ����Ŵ
	else
		fp = Wrongprint; //�Լ� �����Ͱ� Wrongprint���� ����Ŵ
	fp(); //�Լ� ȣ��
}