#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int n, m, W_power = 0, B_power = 0, strong = 1;
int move_xy[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} };
int mat[MAX][MAX] = { 0 };
bool visited[MAX][MAX] = { false };
char input[MAX][MAX];
queue<pair<int, int>> q;

void dfs(int y, int x);
void bfs(int y, int x);
void init();
void wCal();
void bCal();
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

void dfs(int y, int x) {

    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int my = y + move_xy[i][0];
        int mx = x + move_xy[i][1];

        if (mx >= 0 && my >= 0 && mx < n && my < m) {
            if (mat[my][mx] == 1 && !visited[my][mx]) {
                strong++;
                visited[my][mx] = true;
                dfs(my, mx);
            }
        }
    }
}

void bfs(int y, int x) {
    q.push({ y, x });
    visited[y][x] = true;

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int my = y + move_xy[i][0];
            int mx = x + move_xy[i][1];

            if (mx >= 0 && my >= 0 && mx < n && my < m) {
                if (mat[my][mx] == 1 && !visited[my][mx]) {
                    strong++;
                    visited[my][mx] = true;
                    q.push({ my, mx });
                }
            }
        }
    }
}

void init() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
            mat[i][j] = 0;
        }
    }
}

void wCal() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (input[i][j] == 'W') mat[i][j] = 1;
        }
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1 && !visited[i][j]) {
                dfs(i, j);
                W_power += strong * strong;
                strong = 1;
            }
        }
    }
}

void bCal() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (input[i][j] == 'B') mat[i][j] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1 && !visited[i][j]) {
                dfs(i, j);
                B_power += strong * strong;
                strong = 1;
            }
        }
    }
}

void solve() {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> input[i];
    }

    wCal();
    init();
    bCal();

    cout << W_power << ' ' << B_power;
}
