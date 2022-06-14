#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	vector<long long int> v;
	long long int k, tmp;
	int cnt = 0; 
	cin >> k;
	
	tmp = k;
	for (long long int i = 2; i * i <= k; i++) {
		while (tmp % i == 0) {
			v.push_back(i);
			cnt++;
			tmp /= i;
		}
	}
	if (tmp != 1) {
		v.push_back(tmp);
		cnt++;
	}
	
	cout << cnt << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}

