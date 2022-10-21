#include <bits/stdc++.h>
using namespace std;

int n, m, res, cnt, ny, nx;
int arr[10][10];
int visited[10][10];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;

void dfs(int y, int x) {
    if (arr[y][x] == 1 || visited[y][x]) return;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
            dfs(ny, nx);
        }
    }
}

int solve() {
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 2) dfs(i, j);
        }
    }

    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && arr[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (!arr[i][j]) v.push_back({ i, j });
        }
    }

    assert(v.size() >= 3);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                arr[v[i].first][v[i].second] = arr[v[j].first][v[j].second] = arr[v[k].first][v[k].second] = 1;
                res = max(res, solve());
                arr[v[i].first][v[i].second] = arr[v[j].first][v[j].second] = arr[v[k].first][v[k].second] = 0;
            }
        }
    }
    cout << res << "\n";
    return 0;
}
