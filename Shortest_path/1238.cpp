#include<bits/stdc++.h>
#define MAX 1001
#define INF 9999999999

using namespace std;

int n, m, x;
int dist[MAX], party_t[MAX];
vector<pair<int, int>> vertex[MAX];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push({dist[start], start});
	
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < vertex[cur].size(); i++) {
			int next = vertex[cur][i].first;
			int weight = vertex[cur][i].second + cost;

			if (dist[next] > weight) {
				dist[next] = weight;
				pq.push({-dist[next], next});
			}
		}
	}
}


int main(void) {
	// 마을, 단방향 도로의 수, 파티를 벌일 마을의 번호 입력
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		vertex[a].push_back({ b,t });
	}

	// 파티하는 곳에 가기까지 각 학생들이 걸리는 각각의 최단 시간을 구하기위해 n번 다익스트라를 수행하고, x까지 가는데 최단 시간을 저장한다.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) dist[j] = INF;
		dijkstra(i);
		party_t[i] = dist[x];
	}

	// 파티가 벌여진 곳에서 다시 자신의 마을로 돌아오는 최단 시간을 구해야하므로 
	// x에서 모든 정점으로 도착하기까지의 최단 시간을 구하고, 그 값들을 이전에 각 정점에서 구한 최단시간에 더해준다.
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dijkstra(x);
	for (int i = 1; i <= n; i++) party_t[i] += dist[i];
	
	// 정렬 후, 오고 가는데 가장 오래 걸리는 학생의 소요시간을 출력한다.
	sort(party_t+1, party_t + n + 1);
	cout << party_t[n];
	return 0;
}
