#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	vector<int> vec;
	vector<int> res;
	cin >> n >> k;
	vec.push_back(0);
	for (int i = 0; i < n; i++) {
		vec.push_back(i + 1);
	}
	
	for (int i = k; n != 0; i+= k-1) {
		if (i > n) {
			while (n < i) {
				i -= n;
			}
		}
		res.push_back(vec[i]);
		vec.erase(vec.begin() + i);
		n--;
	}
	cout << "<";
	for (int i = 0; i < res.size(); i++) {
		if (i == res.size() - 1)
			cout << res[i] << ">";
		else {
			cout << res[i] << ", ";
		}
	}
}