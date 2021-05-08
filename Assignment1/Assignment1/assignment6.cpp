#include <iostream>
#include <stdlib.h>

using namespace std;

bool percent[10] = { true,true,true,true,false,false,false,false,false,false }; //10개중 4개의 배열에 true를 넣어 랜덤함수가 0~3까지의 값을 가지면 true인것으로 40%확률을 구현함


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
		cout << "숫자를 잘못 입력하셨습니다." << endl; //data가 4자리의 숫자가 아닐경우 프로그램 종료
		exit(0);
	}
	count = 0;
	for (int i = 0; i < 4; i++) {
		CheckSum += Data[i] - 48;
	}
	CheckSum = CheckSum % 10; //체크섬은 마지막자리수의 값이므로 % 10을 해줌
	CheckSum += '0';
	Data[4] = CheckSum; // CheckSum_Data의 마지막 배열에 체크섬값을 저장
	cout << "Send Data:";
	for (int i = 0; i < 5; i++) {
		cout << Data[i];
	}
	cout << endl;
}

void Transmission_Process(const char * Data) {
	char* Data_temp = (char*)Data;
	srand((unsigned int)time(NULL)); //지금 시간에 따른 랜덤 시드 생성
	int index;
	char temp = 0;
	if (percent[rand() % 10]) { // 랜덤시드를 % 10을하여 0~9까지의 숫자를 랜덤하게 생성
		index = rand() % 5; // 바꿀 자리수를 랜덤하게 생성
		temp = rand() % 10; // 바꿀 값을 랜덤하게 0~9에서 생성
		while (temp + '0' == Data[index]) { //만약에 원래있는 값과 같을 때는 다시 랜덤하게 돌림
			temp = rand() % 10;
		}
		Data_temp[index] = temp + '0'; //결과적으로 값을 변경
	}
}

void Receiver(const char Data[]) {
	char Trans_CheckSum = 0;
	cout << "Received data:";
	for (int i = 0; i < 5; i++) {
		cout << Data[i];
		if(i < 4)
			Trans_CheckSum += Data[i] - '0'; //Transmission에서 넘어온 값의 체크섬을 구하기 위해 저장
	}
	Trans_CheckSum = Trans_CheckSum % 10 + '0'; //체크섬은 마지막자리의 숫자이므로 % 10을 함
		cout << '\n';
	if (Trans_CheckSum == Data[4]) { //만약 체크섬 넘버가 같을 경우와 다를경우를 출력
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
