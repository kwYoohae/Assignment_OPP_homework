#include <iostream>
#include <vector>
using namespace std;
int main() {
	int R, C;
	vector<vector<char>> vec;
	vector<char> vec_temp;
	char temp;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> temp;
			vec_temp.push_back(temp);
		}
		vec.push_back(vec_temp);
		vec_temp.clear();
	}
	return 0;
}