#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int GCD(int a, int b) {
	return !b ? a : GCD(b, a % b);
}

int main() {
	int t, max;
	cin >> t;
	cin.ignore();
	while(t--) {
		vector<int> v;

		string data, num;
		getline(cin, data);
		stringstream sstream(data);
		while (getline(sstream, num, ' '))
			v.push_back(stoi(num));

		int max = 0;
		for (int j = 0; j < v.size(); j++) {
			for (int k = j + 1; k < v.size(); k++) {
				int gcd_value = GCD(v[j], v[k]);
				if (max < gcd_value) {
					max = gcd_value;
				}
			}
		}
		cout << max << "\n";
	}
}
