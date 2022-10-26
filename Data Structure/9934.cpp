#include <iostream>
#include <vector>
using namespace std;

int k, node, node_num;
vector<int> h[11];
int arr[1024];

void dfs(int s, int e, int level) {
	int m = (s + e) / 2;
	h[level].push_back(arr[m]);
	if (s == e) {
		return;
	} 
	
	dfs(s, m - 1, level + 1);
	dfs(m + 1, e, level + 1);
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k;
	node_num = 1;
	for (int i = 0; i < k; i++) {
		node_num *= 2;
	}
	node_num--;
	for (int i = 0; i < node_num; i++) {
		cin >> node;
		arr[i] = node;
	}

	dfs(0, node_num - 1, 1);

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < h[i].size(); j++) {
			cout << h[i][j] << " ";
		}
		cout << "\n";
	}
}
