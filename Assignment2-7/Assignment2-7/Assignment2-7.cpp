#include <iostream>

using namespace std;

class ���� {
private:
	char U_Name[20];
	int year;
	char U_StuID[20];
public:
	����();
	char* get_UName() { //private U_Name�� ���� get�Լ�
		return U_Name;
	}
	int get_year() { // private year�� ���� get�Լ�
		return year;
	}
	char* get_UStuID() { // private�� U_stuId�� ���� get �Լ�
		return U_StuID;
	}
	bool find_ID(char stuID[]) { // find_ID��� StudentID�� �ִ��� ������ Ȯ���ϴ� �żҵ�
		if (strcmp(stuID, U_StuID) == 0)
			return true; // ������ true�� ��ȯ
		return false; // ������ false�� ��ȯ
	}

};
����::����() { //������ �����ڿ��� cin���� private ������ ����
	cout << "�б� :";
	cin >> U_Name;
	cout << "�й� :";
	cin >> U_StuID;
	cout << "�г� :";
	cin >> year;
}
class ��ǻ���������� :public ���� { // ���п� ��ӵǾ��ִ� ��ǻ���������� Ŭ����
private:
	char Object_Oriented_Programing;
	char Digtal_Logic_Circuit;
public:
	��ǻ����������();
	char get_Object_Oriented_Programing() { // Object_Oriented_Programing�� retrun���ִ� �żҵ�
		return Object_Oriented_Programing;
	}
	char get_Digital_Logic_Circuit() { // Digital Logic Circuit�� return ���ִ� �żҵ�
		return Digtal_Logic_Circuit;
	}
};

��ǻ����������::��ǻ����������() { // ��ǻ������������ �����ڿ��� cin���� private������ ����
	cout << "��ü�������α׷��� ���� :";
	cin >> Object_Oriented_Programing;
	cout << "�����г�ȸ�� ���� :";
	cin >> Digtal_Logic_Circuit;
}

class �л����� :public ��ǻ���������� {// ��ǻ���������п� ��ӵǾ��ִ� �л�����
private:
	char Name[10];
	int age;
public:
	�л�����();
	char* get_Name() {  // Name�̶�� private ������ return 
		return Name;
	}
	int get_age() { // age��� private��� ������ return
		return age;
	}
	bool find_Name(char Name[]) { // Name�� �´��� Ȯ���ϴ� bool�� �żҵ�
		if (strcmp(Name, this->Name) == 0) // class�� Name �Ű������� Name�� �´��� Ȯ��
			return true; // ������ true�� ����
		return false; // Ʋ���� false�� ����
	}
};

�л�����::�л�����() { // �л������� private ������ cin���� �Է¹޴� ������
	cout << "�̸� :";
	cin >> Name;
	cout << "���� :";
	cin >> age;
}

int main() {
	�л�����** student = new �л����� * [100]; //�л������� 2���� �迭 �Ҵ�
	int count = 0; //���ݱ��� ����� ��û�ߴ��� Ȯ���ϴ� ����
	char Name[20]; // find�Լ����� �̸��� ã������ �̸��� �޴� ����
	char stuID[20]; // find�Լ����� �й��� ã������ StudentId�� �޴� ����
	char command[20]; // Ŀ�ǵ带 �Է¹޴� ����
	bool end = true; // �ݺ����� ���� ����
	while (end) {
		cin >> command; // Ŀ�ǵ带 �Է¹޴´�.
		if (strcmp(command, "INSERT") == 0) { //Command�� "INSERT"���� Ȯ��
			if (count < 100) { // �л��� ���� 100���� �۴ٸ� 
				student[count] = new �л�����; // �л������� �����Ҵ�
				count++; // �л����� �ö󰣰��� ��Ÿ��
			}
			else
				cout << "Limit Number is 100" << endl; //0~99�� ���� ũ�� Limit Number is 100�� ���
		}
		else if (strcmp(command, "FIND") == 0) { // Command�� "FIND"���� Ȯ��
			cin >> Name >> stuID; // ã�� ������ �Է¹���
			int index = -1; // ã�� ���� �ε��� ��ȣ�� -1�� �ʱ�ȭ
			for (int i = 0; i < count; i++) {
				if (student[i]->find_ID(stuID) == true && student[i]->find_Name(Name) == true) { //find_ID�� find_Name�żҵ带 �̿��ؼ� ����ã�´�
					index = i; // ���� �ΰ��� ���ÿ� �����ϴ� �����Ͱ� ������ �׶��� student�� ��ȣ�� index�� ����
				}
			}
			if (index != -1) { // �ΰ��� �������� ���Ѵ� �����Ͱ� ������ �ʱ� ���� -1 �̹Ƿ� -1�� �ƴѰ��̸� �л��� ������ ���
				cout << '\n' << '\n';
				cout << "�б�:" << student[index]->get_UName() << endl;
				cout << "�й�:" << student[index]->get_UStuID() << endl;
				cout << "�г�:" << student[index]->get_year() << endl;
				cout << "��ü�������α׷��� ����: " << student[index]->get_Object_Oriented_Programing() << endl;
				cout << "�����г�ȸ�� ����: " << student[index]->get_Digital_Logic_Circuit() << endl;
			}
		}
		else if (strcmp(command, "EXIT") == 0) { // Command�� "EXIT"���� Ȯ��
			end = false; // �ݺ�������
			for (int i = 0; i < count; i++) {
				delete[] student[i]; // �л�����ŭ �����Ҵ��� ����
			}
			delete[] student; //��ü�� �����Ҵ� ����
		}
	}
}
