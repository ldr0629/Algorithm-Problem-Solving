#include <bits/stdc++.h>
#define INF 987654321
#define MAX 1001
using namespace std;

int n, m, city_s, city_e;
int dist[MAX];
vector<pair<int, int> > graph[MAX];


void dijkstra() {
	priority_queue<pair<int, int> > pq;
	dist[city_s] = 0;
	pq.push(make_pair(dist[city_s], city_s));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
  
    		// 시간초과 방지를 위해서 최소 가중치 합이 이미 구해진 경우는 아래의 과정을 생략한다.
		if (dist[cur] < cost) continue;

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
	// 도시와 버스의 개수 입력
	cin >> n >> m;

	// u번째 도시에서 v번째 도시까지 각 정점을 연결해주고, 간선의 가중치 입력
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	// 처음에는 한 정점에서 모든 정점으로 가는 비용을 무한대로 초기화
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	// 출발, 도착점의 도시번호가 주어진 후 다익스트라 수행
	cin >> city_s >> city_e;
	dijkstra();

	// 출발 도시에서 도착 도시까지 가는데 드는 최소 비용 출력
	cout << dist[city_e];
	return 0;
}
