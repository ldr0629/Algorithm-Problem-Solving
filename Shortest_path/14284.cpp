#include <bits/stdc++.h>
#define INF 999999999
#define MAX 5001
using namespace std;

int n, m, s, t;
int dist[MAX];
vector<pair<int, int> > graph[MAX];


void dijkstra() {
	// 우선순위 큐를 선언 후 현재 비용과 시작 정점을 쌍으로 넣고, 자신의 정점은 0으로 초기화
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, s));
	dist[s] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int weight = graph[cur][i].second;
			
			// 현재 정점의 비용, 연결된 정점의 가중치를 더한 값이 다음 정점의 비용보다 작은 경우 최소 비용을
			// 업데이트 해주고, 이때의 비용과 정점을 우선순위 큐에 삽입한다.
			if (dist[next] > cost + weight) {
				dist[next] = cost + weight;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
}

int main() {
	// 정점의 개수와 간선리스트의 간선 수 입력
	cin >> n >> m;

	// 무방향 그래프이므로 양방향으로 정점과 가중치를 입력
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}

	// 처음에는 한 정점에서 모든 정점으로 가는 비용을 무한대로 초기화
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	// s에서 시작하여 t로 연결되는 시점에서 가중치의 합의 최솟값을 구한다.
	cin >> s >> t;
	dijkstra();

	// s에서 t로 가는데에 최소 비용 출력
	cout << dist[t];
	return 0;
}
