#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<short> vec;
	short temp;
	int number;
	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < number; i++) {
		cout << vec[i] << '\n';
	}
}