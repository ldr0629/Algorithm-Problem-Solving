#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t, n, result;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<string> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
	
		if (n > 32) {
			cout << 0<<"\n";
		}
		else {
			result = 100001;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					for (int k = j + 1; k < n; k++) {
						int distance = 0;
						for (int l = 0; l < 4; l++) {
							distance += (v[i][l] != v[j][l]) + (v[j][l] != v[k][l]) + (v[k][l] != v[i][l]);
						}
						result = min(result, distance);
					}
				}
			}
			cout << result<<"\n";
		}
	}


}
