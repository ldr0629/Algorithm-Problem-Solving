#include <iostream>
#include <vector>
#include <string>
using namespace std;

string oper_str;
int n, result = -987654321;
vector<int> num;
vector<char> oper;

int operFunc(char op, int a, int b) {
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
}

// 재귀를 이용한 누적합
void go(int base, int data) {
	if (base == num.size() - 1) {
		result = max(result, data);
		return;
	}

	// 앞에서부터 계산하는 경우
	go(base + 1, operFunc(oper[base], data, num[base+1]));

	// 뒤에서부터 계산하는 경우
	if (base + 2 <= num.size() - 1) {
		int tmp = operFunc(oper[base + 1], num[base + 1], num[base + 2]);
		go(base + 2, operFunc(oper[base], data, tmp));
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> oper_str;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) num.push_back(oper_str[i]-'0');
		else oper.push_back(oper_str[i]);
	}
	go(0, num[0]);
	cout << result;
}
