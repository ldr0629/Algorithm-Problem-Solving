#include <bits/stdc++.h>
using namespace std;

int n, ny, nx, min_cost = INT_MAX;
int mat[11][11];
bool visited[11][11];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void init(int y, int x) {
    visited[y][x] = false;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        visited[ny][nx] = false;
    }
}

int costSum(int y, int x) {
    // 주변에 꽃이 있는 경우
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (visited[ny][nx]) return -1;
    }

    // 꽃이 없는 경우 합을 구함
    int sum = mat[y][x];
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        visited[ny][nx] = true;
        sum += mat[ny][nx];
    }
    return sum;
}


void dfs(int y, int x, int cnt, int s) {
    if (cnt == 3) {
        min_cost = min(min_cost, s);
        return;
    }
    for (int i = y; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (visited[i][j]) continue;
            int sum = costSum(i, j);
            if (sum != -1) {
                dfs(i, j, cnt + 1, s + sum);
                init(i, j);
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < n-1; j++) {
            int sum = costSum(i, j);
            dfs(i, j, 1, sum); 
            init(i, j);
        }
    }
    cout << min_cost << "\n";
    return 0;
}
