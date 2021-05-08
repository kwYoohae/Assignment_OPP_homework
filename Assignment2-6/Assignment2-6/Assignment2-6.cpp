#include <iostream>
using namespace std;

class MyAccount
{
public:
	MyAccount(); // MyAccount�� ������
	MyAccount(char* My_Account_Number, char* My_Name);// MyAccount�� �����ε� ������
	~MyAccount();// MyAccount �Ҹ���
	void Deposit(char* My_Account_Number, unsigned int My_money); //������ ���ִ� �żҵ�
	void Withdraw(char* My_Account_Number, unsigned int My_moeny); // ����� ���ִ� �żҵ�
	void Print(); // Print�� ���ִ� �żҵ�
private:
	unsigned int Money; // �������ִ� �� 
	char* Name; // ������
	char* Account_Number; // ���¹�ȣ
};

MyAccount::MyAccount() {
	Money = 0; //���� �ʱ�ȭ
	Name = NULL; // ���� �ʱ�ȭ
	Account_Number = NULL; // ���� �ʱ�ȭ
}

MyAccount::MyAccount(char* My_Account_Number, char* My_Name) { //MyAccount �����ε� ������
	int len = strlen(My_Account_Number); // ���¹�ȣ�� ���̸� �����Ѵ�.
	Account_Number = new char[len + 1]; // Account_number������ �����Ҵ� ���ش�.
	for (int i = 0; My_Account_Number[i] != '\0'; i++) {//Account_number�� '\0'�϶����� �ݺ�������
		Account_Number[i] = My_Account_Number[i]; // Account_number�� �Ű������� My_Account_number�� ����
	}
	Account_Number[len] = '\0'; //'\0'�� �������� �־��ش�.
	len = strlen(My_Name); // �̸��� ���ؼ� �ܾ��� ���̸� ��
	Name = new char[len + 1]; // Name�� �ܾ��� ���̸�ŭ �����Ҵ��� ������
	for (int i = 0; My_Name[i] != '\0'; i++) { // My_Name�� '\0'�� ���������� Name�� ��������
		Name[i] = My_Name[i];
	}
	Name[len] = '\0'; // �������� '\0'�� �־ ������ ���� ��Ÿ��
	Money = 0; // ���� 0���� �ʱ�ȭ
}

MyAccount::~MyAccount()
{
	delete[] Name; // Name�� �޸� �����Ҵ� ����
	delete[] Account_Number; // Account_Number�� �޸� �����Ҵ� ����
}

void MyAccount::Deposit(char* MY_Account_Number, unsigned int My_money) { //���¹�ȣ�� Ȯ���ϰ� ������ ���ִ� �Լ�
	bool is_true = true;
	for (int i = 0; Account_Number[i] != '\0'; i++) { // ��ü�� ����� Account��ȣ�� ������ Ȯ��
		if (MY_Account_Number[i] != Account_Number[i]) {
			is_true = false; // Ʋ�� ���ڰ� ������ is_true�� ���� false��
		}
	}
	if (is_true) { // is_true�� true�� ����
		Money += My_money; // ���� ������
	}
}

void MyAccount::Withdraw(char* MY_Account_Number, unsigned int My_money) { //���¹�ȣ�� Ȯ���ϰ� ����� ���ִ� �Լ�
	bool is_true = true;
	for (int i = 0; Account_Number[i] != '\0'; i++) { // ��ü�� ����� Account��ȣ�� ������ Ȯ�� 
		if (MY_Account_Number[i] != Account_Number[i]) {
			is_true = false; // Ʋ�� ���ڰ� ������ is_true�� ���� false��
		}
	}
	if (is_true) {// is_true�� true�� ����
		if (Money >= My_money) // ����ݾ׺��� �۰ų� ������츸
			Money -= My_money; // ����ݾ��� ����
		else
			cout << "����ݾ׺��� ū �ݾ��� ����Ϸ� �մϴ�." << endl;
	}
}
void MyAccount::Print() {
	cout << "�̸� : " << Name << '\t' << "Account_Number : " << Account_Number << '\t' << "Money : " << Money << endl; //  Print�Լ�
}

int main() {
	unsigned int money; //money ���� �޴� �Լ�
	MyAccount* my_account[5]; //MyAccount��ü�� 5��ŭ ����
	int count = 0; // ������ ������ ������ count�ϴ� ����
	bool end = true; //�ݺ����� �������� 
	while (end) {
		char Command[100]; //Command�� �Է��� �迭
		char Name[20]; // �̸��� �Է��� �迭
		char Account[100]; //���¸� �Է��� �迭
		cin >> Command; //Command�� �Է¹���
		if (strcmp(Command, "NEW") == 0) { //command�� New���� ��
			if (count > 4) { //count�� 0~4 �ʰ��� �� ������ ���ٰ� ��� x
				cout << "Number of Account Limited" << endl;
			}
			else {
				cin >> Name >> Account; //�̸��� ���¹�ȣ�� ������
				my_account[count] = new MyAccount(Account, Name);
				//my_account[count].New(Account, Name); //����
				count++; // ���»����� �߱� ������ count +1 ������
				cout << "���»���" << endl;
			}
		}
		else if (strcmp(Command, "DEPOSIT") == 0) { //  Command�� DEPOSIT���� ��
			if (count == 0) { // ������ ���°� ������
				cout << "Number of Account is 0" << endl;
			}
			else { //������ ���°�������
				cin >> Account >> money; // ���¹�ȣ�� �Ա��� �ݾ��� �Է�
				for (int i = 0; i < count; i++) { // ������ ���¸�ŭ �ݺ����� ����
					my_account[i]->Deposit(Account, money); // Deposit �żҵ带 �Ա��� ���¹�ȣ�� �ݾ��� ���ڷ� �Ѱ���
				}
			}
		}
		else if (strcmp(Command, "WITHDRAW") == 0) { // Command�� WITHDRAW���� ��
			if (count == 0) { // ������ ���°� ���� ��
				cout << "Number of Account is 0" << endl; // Number of Account is 0�� ���
			}
			else {
				cin >> Account >> money; // Account�� Money�� �Է¹޴´�.
				for (int i = 0; i < count; i++) { // ������ ���¸�ŭ �ݺ����� ����
					my_account[i]->Withdraw(Account, money); // ��ü�� Withdraw�żҵ带 ȣ��
				}
			}
		}
		else if (strcmp(Command, "PRINT") == 0) { // Command�� PRINT���� Ȯ��
			for (int i = 0; i < count; i++) { // ������ ���¸�ŭ �ݺ����� ����
				cout << i << '\t';
				my_account[i]->Print(); // ��ü�� Print()�żҵ� ȣ��
			}
		}
		else if (strcmp(Command, "EXIT") == 0) { // Command�� Exit���� Ȯ��
			cout << "EXIT" << endl;
			for (int i = 0; i < count; i++) { // ������ ���¸�ŭ �ݺ����� ����
				cout << "���»��� :" << i << endl;
				delete my_account[i]; // ������ ��ü �޸� �Ҵ� ����
			}
			end = false; // �ݺ�������
		}
		cin.clear(); // �Է��� �ް� �Է¹��������
	}
}