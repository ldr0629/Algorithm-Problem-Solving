#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits.h>
using namespace std;

struct food {
	int mp, mf, ms, mv, cost;
}F[16];
int b, c, d, e, result = INT_MAX, sum;
map<int, vector<vector<int>>> ret_m;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, mp, mf, ms, mv;
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; i++) {
		cin>>F[i].mp >> F[i].mf >> F[i].ms >> F[i].mv >> F[i].cost;
	}

	// 모든 경우의 수에 대해서 체크
	for (int i = 0; i < (1 << n); i++) {
		b = c = d = e = sum = 0;
		vector<int> vec;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				vec.push_back(j + 1);
				b += F[j].mp;
				c += F[j].mf;
				d += F[j].ms;
				e += F[j].mv;
				sum += F[j].cost;
			}
		}
		// 최소 영양분을 넘었을 때 비용 체크
		if (b >= mp && c >= mf && d >= ms && e >= mv) {
			if (result >= sum) {
				result = sum;
				ret_m[result].push_back(vec);
			}
		}
	}

	// 영양분을 넘는 조합이 없는 경우 
	if (result == INT_MAX) cout << -1 << "\n";
	else { // 비용에 해당하는 영양분 조합 정렬 
		sort(ret_m[result].begin(), ret_m[result].end());
		cout << result << "\n";
		// 같은 비용의 잡합이 하나 이상이면 가장 빠른 것 출력
		for (int a : ret_m[result][0]) {
			cout << a << " ";
		}
	}
}
