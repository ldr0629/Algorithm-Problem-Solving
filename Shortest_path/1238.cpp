#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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

	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		vertex[a].push_back({ b,t });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) dist[j] = INF;
		
		dijkstra(i);
		party_t[i] = dist[x];
	}

	for (int i = 1; i <= n; i++) dist[i] = INF;
	dijkstra(x);
	for (int i = 1; i <= n; i++) party_t[i] += dist[i];
	
	sort(party_t+1, party_t + n + 1);

	cout << party_t[n];
	return 0;
}
