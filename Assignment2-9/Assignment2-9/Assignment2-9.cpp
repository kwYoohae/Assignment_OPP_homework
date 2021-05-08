#include <iostream>

using namespace std;

class Mystring // Mystring class����
{
public:
	Mystring(const char* str); //Mystring�� �Ű������� �޴� ������
	Mystring(); // Mystring�� �⺻������
	~Mystring(); // Mystring�� �Ҹ���
	Mystring operator +(Mystring ch) { // + �����ڸ� ������ ���� �żҵ� ����
		int index_ch1 = 0; // 
		int index_ch2 = 0;
		Mystring my;
		if (this->my_str[0] != '\0') {
			for (int i = 0; this->my_str[i] != '\0'; i++) {
				index_ch1 = i;
				my.my_str[i] = this->my_str[i];
			}
			index_ch1++;
		}
		for (int i = 0; ch.my_str[i] != '\0'; i++) {
			my.my_str[i + index_ch1] = ch.my_str[i];
			index_ch2 = i;
		}
		my.my_str[index_ch1 + index_ch2 + 1] = '\0';
		return my;
	}
	friend ostream& operator<< (ostream& os, const Mystring& ms); //���ٱ����� Ǯ���ִ� public�Լ��� �������ؼ� friend�Լ��� ����

private:
	char my_str[100]; // ���̰� 100�� ���ڿ� ����
};

ostream& operator<<(ostream& os, const Mystring& ms) { // outputstream�� ����Ͽ� ms.my_str�� <<�� ���ٸ� ����ϵ��� �Լ�����
	os << ms.my_str << endl;
	return os;
}

Mystring::Mystring(const char* str) //�Ű������� ���� ������
{
	int index = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		index++; // str�� legth�� str[i] == '\0'�϶����� ī��Ʈ
	}
	for (int i = 0; i < index; i++) {
		my_str[i] = str[i]; // �Ű������� ���� private������ �ϳ��� �־���
	}
	my_str[index] = '\0'; // my_str�� ���� '\0'���ڸ� �־���
}

Mystring::Mystring() { //my_str�̶�� private ������ �ʱ�ȭ
	my_str[0] = NULL;
}

Mystring::~Mystring() {

}


int main() {
	Mystring my_str;
	Mystring my_str2("���Ǵ� ");
	my_str = my_str2 + "pwh7514@gmail.com�� �ּ���"; // my_str2 �� ���ڿ��� ��
	cout << my_str; // my_str���
}