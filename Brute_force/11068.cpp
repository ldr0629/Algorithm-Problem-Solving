#include <iostream>
#include <vector>
using namespace std;

int t, n;
bool check = false;

vector<int> getNumbers(int n, int b) {
	vector<int> numbers;
	while (n != 0) {
		numbers.push_back(n % b);
		n /= b;
	}
	return numbers;
}

bool isPalindrome(vector<int> numbers) {
	for (int i = 0; i < numbers.size() / 2; i++) {
		if (numbers[i] != numbers[numbers.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}


int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		check = false;
		for (int i = 2; i <= 64; i++) {
			vector<int> numbers = getNumbers(n, i);
			if (isPalindrome(numbers)) {
				check = true; 
				break;
			}
		}
		if (check) cout << 1<<"\n";
		else cout << 0<<"\n";
	}
}
