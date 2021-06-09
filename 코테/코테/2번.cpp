#include <iostream>

using namespace std;

class phone {
public:
	char name[100];
	int number_first;
	int a = 1;
	int b = 2;
	friend ostream &operator<< (ostream & output, phone & Phone);
	friend istream& operator>>(istream& input, phone& Phone);
	phone operator+(phone &Phone);
};

phone phone::operator+(phone &Phone) {

}

ostream& operator<<(ostream& output, phone& Phone) {
	output << Phone.name<< Phone.number_first;
	return output;
}

istream &operator>>(istream& input, phone& Phone) {
	input >> Phone.name;
	cout << "number :";
	cin >> Phone.number_first;
	return input;
}

int main() {
	phone Phone;
	cin >> Phone;
	cout << Phone;
}