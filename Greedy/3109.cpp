#include <iostream>
using namespace std;

int r, c;
string s;
char mat[10001][501];
int visited[10001][501] = { 0, };
int dx[3] = { -1, 0, 1 };
int dy[3] = { 1, 1, 1 };
int cnt;

bool dfs(int x, int y)
{
    if (y == c - 1) {
        cnt++;
        return true;
    }

    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < r && 0 <= ny && ny < c && !visited[nx][ny]) {
            if (mat[nx][ny] == 'x') continue;
            visited[nx][ny] = true;
            if (dfs(nx, ny)) return true;
        }
    }

    return false;
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            mat[i][j] = s[j];
        }
    }


    for (int i = 0; i < r; i++) {
        visited[i][0] = true;
        dfs(i, 0);
    }

    cout << cnt << "\n";
    return 0;
}
