#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_VERTICES 10001

using namespace std;

int parent[MAX_VERTICES]; 

typedef struct Edge {
	int u, v, weight;
};

bool cmp(const Edge e1, const Edge e2) {
	return e1.weight < e2.weight;
}

void set_init(int v) {
	for(int i = 0; i<v; i++) {
		parent[i] = -1;
	}
} 

int set_find(int curr) {
	if(parent[curr] == -1) {
		return curr;
	}	
	
	while(parent[curr] != -1) {
		curr = parent[curr];
	}
	
	return curr;
} 

void set_union(int a, int b) {
	int root1 = set_find(a); 
	int root2 = set_find(b); 
	if(root1 != root2) { 
		parent[root1] = root2;
	}
} 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<Edge> edge;
	int v, e, result = 0;
	cin>>v>>e;
	
	int vt_a, vt_b, weight;
	for(int i = 0; i<e; i++) {
		cin>>vt_a>>vt_b>>weight;
		edge.push_back({vt_a, vt_b, weight});
	}
	
	sort(edge.begin(), edge.end(), cmp);
	set_init(v);
	
	for(int i = 0; i<edge.size(); i++) {
		Edge e = edge[i];
		if(set_find(e.u) != set_find(e.v)) {
			result += e.weight;
			set_union(e.u, e.v);
		}
	}
	
	cout<<result;
}
