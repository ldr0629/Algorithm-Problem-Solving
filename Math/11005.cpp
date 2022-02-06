#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {

	int N, B;
	string result = "";
	cin >> N >> B;
	while (N != 0) {
		int mod = N % B;
		if (mod < 10) {
			result += (mod + '0');
		}
		else {
			result += (mod - 10 + 'A');
		}
		N /= B;
	} 
	reverse(result.begin(), result.end());

	cout << result; 
	return 0;
}
