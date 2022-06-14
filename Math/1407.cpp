#include <iostream>
using namespace std;

int main() {
	long long int A, B;
	cin >> A >> B;

	long long int sumB = 0, numB = 1;
	while (B != 0) {
		if (B % 2 != 0) sumB += ((B / 2) + 1) * numB;
		else sumB += (B / 2) * numB;
		B /= 2; numB *= 2;
	}

	long long int sumA_1 = 0, numA_1 = 1;
	long long int diffA = A - 1;
	while (diffA != 0) {
		if (diffA % 2 != 0) sumA_1 += ((diffA / 2) + 1) * numA_1;
		else sumA_1 += (diffA / 2) * numA_1;
		diffA /= 2; numA_1 *= 2;
	}

	cout << sumB - sumA_1;
}

