#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int getGcd(int a, int b) {
	while (a % b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return b;
}

int main() {
	int t, gcd;
	cin >> t; 
	for (int i = 0; i < t; i++) {
		int data;
		cin >> data;
		v.push_back(data);
	}

	sort(v.begin(), v.end());
	gcd = v[1] - v[0];
	for (int i = 2; i < t; i++) {
		gcd = getGcd(v[i] - v[i - 1], gcd);
	}

	vector<int> res;
	for (int i = 2; i*i <= gcd; i++) {
		if (gcd % i == 0) {
			res.push_back(i);
			res.push_back(gcd / i);
		}
	}
	
	res.push_back(gcd);
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end()); 

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
}

