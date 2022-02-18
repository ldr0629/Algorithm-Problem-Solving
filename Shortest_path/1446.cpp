#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
#define INF 987654321
using namespace std;

int n, d;
vector<int> dist(MAX, INF);
vector<pair<int, int>> v[MAX];

int main(void) {
	// 지름길의 개수와 고속도로의 길이 입력 후, 시작, 도착 위치 지름길의 길이 입력
	// 단, 모든 지름길은 일방통행이므로 양방향 연결 X
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		v[e].push_back({ s, w });
	}

	// d킬로미터 까지가는데 0부터 거리가 계산되므로 0으로 초기화 후, 거리의 최솟값을 구한다.
	// 지름길이 없다면, i에서 i+1킬로미터까지 이동하는데는 1킬로미터가 계산되고, 
	// 지름길이 존재한다면 일반적으로 1킬로가 더해졌을 때의 누적값과 지름길의 거리를 비교해 최솟값을 계산한다.
	// v[i]에서 지름길의 개수가 2이상인 경우를 방지하기 위해 dist[i]와도 비교
	dist[0] = 0;
	for (int i = 1; i <= d; i++) {
		if (v[i].size() == 0) dist[i] = dist[i - 1] + 1;
		else {
			for (auto v : v[i]) {
				dist[i] = min(dist[i], min(dist[i - 1] + 1, dist[v.first] + v.second));
			}
		}
	}
	// 운전해야하는 거리의 최솟값 출력
	cout<< dist[d]; 
	return 0;
}
