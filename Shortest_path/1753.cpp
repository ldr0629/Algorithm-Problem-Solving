#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
#define MAX 20001
using namespace std;

int v, e, start;
int dist[MAX];
vector<pair<int, int>> vertex[MAX];

void dijkstra() {
	// 비용과 현재위치를 한 쌍으로 넣어주고, 처음 자기 자신에 대한 거리 비용은 0으로 초기화.
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	// 큐가 빌때까지 각 큐에 대한 비용과 현재 위치를 얻은 뒤 현재 정점과 연결된 크기만큼
	// 다음 연결된 정점의 비용과 다른 정점을 거쳤을 때의 비용, 가중치를 더한 값을 비교해 각 거리를 계산해준 후 각 정점으로의 최단 경로를 구해준다.
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < vertex[cur].size(); i++) {
			int next = vertex[cur][i].first;
			int weight = vertex[cur][i].second;
			
			if (dist[next] > cost + weight) {
				dist[next] = cost + weight;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}

int main(void) {
	// 정점, 간선의 개수와 시작 정점의 번호 입력.
	cin >> v >> e >> start;

	// 간선과 가중치를 입력받고, 정점에 연결된 정점과 가중치를 벡터에 넣어준다.
	int u1, u2, w;
	for (int i = 0; i < e; i++) {
		cin >> u1 >> u2 >> w;
		vertex[u1].push_back(make_pair(u2, w));
	}
	
	// 처음에 한 정점에서 다른 모든 정점으로의 최소 비용 배열은 무한대로 초기화.
	for(int i = 1; i<=v; i++) {
		dist[i] = INF;
	}

	dijkstra();
	return 0;
}
