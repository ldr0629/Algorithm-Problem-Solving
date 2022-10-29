#include <bits/stdc++.h>
using namespace std;

int num[500001];
int cnt[8001] = {0};
int n;
int avg, median, maxCnt, range;

int main(void) {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr);

	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];

		sum += num[i];
		cnt[num[i] + 4000]++;
	}

	sort(num, num+n);

	int flag, maxCntNum = 0;
	for (int i = 0; i <= 8000; i++) {
		if (maxCntNum < cnt[i]) {
			maxCntNum = cnt[i];
			flag = i;
		}
	}

	for (int i = flag + 1; i <= 8000; i++) {
		if (maxCntNum == cnt[i]) {
			flag = i;
			break;
		}
	}

	avg = round(double(sum) / n);
	median = num[(n - 1) / 2];
	maxCnt = flag - 4000;
	range = num[n - 1] - num[0];

	cout << avg << "\n" << median << "\n" << maxCnt << "\n" << range;
}
