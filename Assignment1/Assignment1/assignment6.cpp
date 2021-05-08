#include <iostream>
#include <stdlib.h>

using namespace std;

bool percent[10] = { true,true,true,true,false,false,false,false,false,false }; //10���� 4���� �迭�� true�� �־� �����Լ��� 0~3������ ���� ������ true�ΰ����� 40%Ȯ���� ������


void Sender(char *Data ) {
	cout << "Data : ";
	cin >> Data;
	char CheckSum = 0;
	int count = 0;
	for (int i = 0; i < 4; i++) {
		if (Data[i] >= '0' && Data[i] <= '9')
			count++;
	}
	if (count < 4) {
		cout << "���ڸ� �߸� �Է��ϼ̽��ϴ�." << endl; //data�� 4�ڸ��� ���ڰ� �ƴҰ�� ���α׷� ����
		exit(0);
	}
	count = 0;
	for (int i = 0; i < 4; i++) {
		CheckSum += Data[i] - 48;
	}
	CheckSum = CheckSum % 10; //üũ���� �������ڸ����� ���̹Ƿ� % 10�� ����
	CheckSum += '0';
	Data[4] = CheckSum; // CheckSum_Data�� ������ �迭�� üũ������ ����
	cout << "Send Data:";
	for (int i = 0; i < 5; i++) {
		cout << Data[i];
	}
	cout << endl;
}

void Transmission_Process(const char * Data) {
	char* Data_temp = (char*)Data;
	srand((unsigned int)time(NULL)); //���� �ð��� ���� ���� �õ� ����
	int index;
	char temp = 0;
	if (percent[rand() % 10]) { // �����õ带 % 10���Ͽ� 0~9������ ���ڸ� �����ϰ� ����
		index = rand() % 5; // �ٲ� �ڸ����� �����ϰ� ����
		temp = rand() % 10; // �ٲ� ���� �����ϰ� 0~9���� ����
		while (temp + '0' == Data[index]) { //���࿡ �����ִ� ���� ���� ���� �ٽ� �����ϰ� ����
			temp = rand() % 10;
		}
		Data_temp[index] = temp + '0'; //��������� ���� ����
	}
}

void Receiver(const char Data[]) {
	char Trans_CheckSum = 0;
	cout << "Received data:";
	for (int i = 0; i < 5; i++) {
		cout << Data[i];
		if(i < 4)
			Trans_CheckSum += Data[i] - '0'; //Transmission���� �Ѿ�� ���� üũ���� ���ϱ� ���� ����
	}
	Trans_CheckSum = Trans_CheckSum % 10 + '0'; //üũ���� �������ڸ��� �����̹Ƿ� % 10�� ��
		cout << '\n';
	if (Trans_CheckSum == Data[4]) { //���� üũ�� �ѹ��� ���� ���� �ٸ���츦 ���
		cout << Data[4] << "==" << Trans_CheckSum << "     Error is not Occured!" << endl;
	}
	else
		cout << Data[4] << "!=" << Trans_CheckSum << "     Error!" << endl;
}

int main() {
	char ChckSum_Data[5];
	char CheckSum = 0;
	Sender(ChckSum_Data);
	Transmission_Process(ChckSum_Data);
	Receiver(ChckSum_Data);
	cout << endl;
}
