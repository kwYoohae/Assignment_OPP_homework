#include <iostream>
using namespace std;

class MyAccount
{
public:
	MyAccount(); // MyAccount의 생성자
	MyAccount(char* My_Account_Number, char* My_Name);// MyAccount의 오버로딩 생성자
	~MyAccount();// MyAccount 소멸자
	void Deposit(char* My_Account_Number, unsigned int My_money); //예금을 해주는 매소드
	void Withdraw(char* My_Account_Number, unsigned int My_moeny); // 출금을 해주는 매소드
	void Print(); // Print를 해주는 매소드
private:
	unsigned int Money; // 가지고있는 돈 
	char* Name; // 계좌주
	char* Account_Number; // 계좌번호
};

MyAccount::MyAccount() {
	Money = 0; //변수 초기화
	Name = NULL; // 변수 초기화
	Account_Number = NULL; // 변수 초기화
}

MyAccount::MyAccount(char* My_Account_Number, char* My_Name) { //MyAccount 오버로딩 생성자
	int len = strlen(My_Account_Number); // 계좌번호의 길이를 저장한다.
	Account_Number = new char[len + 1]; // Account_number변수에 동적할당 해준다.
	for (int i = 0; My_Account_Number[i] != '\0'; i++) {//Account_number가 '\0'일때까지 반복문실행
		Account_Number[i] = My_Account_Number[i]; // Account_number에 매개변수의 My_Account_number을 저장
	}
	Account_Number[len] = '\0'; //'\0'을 마지막에 넣어준다.
	len = strlen(My_Name); // 이름에 대해서 단어의 길이를 잼
	Name = new char[len + 1]; // Name에 단어의 길이만큼 동적할당을 시켜줌
	for (int i = 0; My_Name[i] != '\0'; i++) { // My_Name이 '\0'을 만날때까지 Name을 복사해줌
		Name[i] = My_Name[i];
	}
	Name[len] = '\0'; // 마지막에 '\0'을 넣어서 문장의 끝을 나타냄
	Money = 0; // 돈은 0으로 초기화
}

MyAccount::~MyAccount()
{
	delete[] Name; // Name의 메모리 동적할당 해제
	delete[] Account_Number; // Account_Number의 메모리 동적할당 해제
}

void MyAccount::Deposit(char* MY_Account_Number, unsigned int My_money) { //계좌번호를 확인하고 예금을 해주는 함수
	bool is_true = true;
	for (int i = 0; Account_Number[i] != '\0'; i++) { // 객체에 저장된 Account번호가 같은지 확인
		if (MY_Account_Number[i] != Account_Number[i]) {
			is_true = false; // 틀린 글자가 있으면 is_true의 값을 false로
		}
	}
	if (is_true) { // is_true가 true일 때만
		Money += My_money; // 돈을 더해줌
	}
}

void MyAccount::Withdraw(char* MY_Account_Number, unsigned int My_money) { //계좌번호를 확인하고 출금을 해주는 함수
	bool is_true = true;
	for (int i = 0; Account_Number[i] != '\0'; i++) { // 객체에 저장된 Account번호가 같은지 확인 
		if (MY_Account_Number[i] != Account_Number[i]) {
			is_true = false; // 틀린 글자가 있으면 is_true의 값을 false로
		}
	}
	if (is_true) {// is_true가 true일 때만
		if (Money >= My_money) // 현재금액보다 작거나 같은경우만
			Money -= My_money; // 현재금액을 빼줌
		else
			cout << "현재금액보다 큰 금액을 출금하려 합니다." << endl;
	}
}
void MyAccount::Print() {
	cout << "이름 : " << Name << '\t' << "Account_Number : " << Account_Number << '\t' << "Money : " << Money << endl; //  Print함수
}

int main() {
	unsigned int money; //money 값을 받는 함수
	MyAccount* my_account[5]; //MyAccount객체를 5만큼 생성
	int count = 0; // 생성된 계좌의 갯수를 count하는 변수
	bool end = true; //반복문의 종료조건 
	while (end) {
		char Command[100]; //Command를 입력할 배열
		char Name[20]; // 이름을 입력할 배열
		char Account[100]; //계좌를 입력할 배열
		cin >> Command; //Command를 입력받음
		if (strcmp(Command, "NEW") == 0) { //command가 New인지 비교
			if (count > 4) { //count가 0~4 초과일 때 갯수가 많다고 출력 x
				cout << "Number of Account Limited" << endl;
			}
			else {
				cin >> Name >> Account; //이름과 계좌번호를 ㅂ다음
				my_account[count] = new MyAccount(Account, Name);
				//my_account[count].New(Account, Name); //생성
				count++; // 계좌생성을 했기 때문에 count +1 을해줌
				cout << "계좌생성" << endl;
			}
		}
		else if (strcmp(Command, "DEPOSIT") == 0) { //  Command가 DEPOSIT인지 비교
			if (count == 0) { // 생성된 계좌가 없을때
				cout << "Number of Account is 0" << endl;
			}
			else { //생성된 계좌가있을떄
				cin >> Account >> money; // 계좌번호와 입금할 금액을 입력
				for (int i = 0; i < count; i++) { // 생성된 계좌만큼 반복문을 돌림
					my_account[i]->Deposit(Account, money); // Deposit 매소드를 입금할 계좌번호와 금액을 인자로 넘겨줌
				}
			}
		}
		else if (strcmp(Command, "WITHDRAW") == 0) { // Command가 WITHDRAW인지 비교
			if (count == 0) { // 생성된 계좌가 없을 때
				cout << "Number of Account is 0" << endl; // Number of Account is 0를 출력
			}
			else {
				cin >> Account >> money; // Account와 Money를 입력받는다.
				for (int i = 0; i < count; i++) { // 생성된 계좌만큼 반복문을 돌림
					my_account[i]->Withdraw(Account, money); // 객체의 Withdraw매소드를 호출
				}
			}
		}
		else if (strcmp(Command, "PRINT") == 0) { // Command가 PRINT인지 확인
			for (int i = 0; i < count; i++) { // 생성된 계좌만큼 반복문을 돌림
				cout << i << '\t';
				my_account[i]->Print(); // 객체의 Print()매소드 호출
			}
		}
		else if (strcmp(Command, "EXIT") == 0) { // Command가 Exit인지 확인
			cout << "EXIT" << endl;
			for (int i = 0; i < count; i++) { // 생성된 계좌만큼 반복문을 돌림
				cout << "계좌삭제 :" << i << endl;
				delete my_account[i]; // 생성된 객체 메모리 할당 해제
			}
			end = false; // 반복문종료
		}
		cin.clear(); // 입력을 받고 입력버퍼지우기
	}
}