#include <bits/stdc++.h>
using namespace std;

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};
string mat[50];

int cntWB(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (mat[x + i][y + j] != WB[i][j]) cnt++;
        }
    }
    return cnt;
}

int cntBW(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (mat[x + i][y + j] != BW[i][j]) cnt++;
        }
    }
    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, minVal = INT_MAX;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }

    for (int i = 0; i + 8 <= n; i++) {
        for (int j = 0; j + 8 <= m; j++) {
            int tmp;
            tmp = min(cntWB(i, j), cntBW(i, j));
            if (tmp < minVal) minVal = tmp;
        }
    }
    cout << minVal;
}
