#include <iostream>
#include <vector>;
#include <utility>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first > b.first) {
		return a.second > b.second;
	}
}

int main() {
	int number;
	pair<int, int> temp;
	vector<pair<int, int>> vec;
	for (int i = 0; i < number; i++) {
		cin >> temp.first >> temp.second;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end(), cmp);
	
	cout << 

}