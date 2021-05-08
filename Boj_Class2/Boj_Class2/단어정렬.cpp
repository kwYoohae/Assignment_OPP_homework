#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) {
	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i])
				return a[i] < b[i];

		}
	}
	else
		return a.size() < b.size();
}

int main() {
	vector<string> str;
	int number;
	string temp;
	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> temp;
		str.push_back(temp);
	}
	sort(str.begin(), str.end());
	str.erase(unique(str.begin(), str.end()), str.end());
	sort(str.begin(), str.end(),cmp);
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << '\n';
	}
}