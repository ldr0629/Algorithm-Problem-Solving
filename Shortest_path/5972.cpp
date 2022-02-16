#include <bits/stdc++.h>
#define INF 999999999
#define MAX 50001
using namespace std;

int n, m;
int dist[MAX];
vector<pair<int, int>> graph[MAX];

void dijkstra() {
	// 헛간 1부터 시작하므로 비용은 0, 시작 정점은 1로 큐에 삽입한다.
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 1));
	dist[1] = 0;

	// 연결된 길마다 최소한의 여물을 구하는 과정을 반복한다. 
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int weight = graph[cur][i].second;

			if (dist[next] > cost + weight) {
				dist[next] = cost + weight;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
}

int main() {
	// 헛간과 양방향 길의 개수 입력 
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		// 각 헛간과 소의 수 입력 
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	dijkstra();

	// 헛간 N까지 가는데 현서가 가져가야 할 최소 여물 출력
	cout << dist[n];
	return 0;
}
