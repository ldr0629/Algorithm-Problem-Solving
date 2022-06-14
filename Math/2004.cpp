#include <iostream>
#include <vector>
using namespace std;

pair<long long int, long long int> zeroCount(long long int num) {
	long long int two_cnt = 0, five_cnt = 0;
	for (long long int i = 2; i <= num; i *= 2) {
		two_cnt += num / i;
	}
	for (long long int i = 5; i <= num; i *= 5) {
		five_cnt += num / i;
	}
	return { two_cnt, five_cnt };
}


int main() {
	long long int n, m;
	cin >> n >> m;

	vector<pair<long long int, long long int>> v;
	v.push_back(zeroCount(n));
	v.push_back(zeroCount(m));
	v.push_back(zeroCount(n - m));
	cout << min(v[0].first - v[1].first - v[2].first, v[0].second - v[1].second - v[2].second);
}
