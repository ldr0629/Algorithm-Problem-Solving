#include <bits/stdc++.h>
using namespace std;

int n, result;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        v.push_back({ s, t });
    }
    
    // 강의 시작 시간을 기준으로 오름차순 정렬 후, 첫 강의의 끝나는 시간부터 해서 각 강의의 시작 시간과 비교한다.
    // 최소의 강의실 개수를 구해야하므로 우선순위 큐는 최솟값을 top으로 두어야 한다.
    sort(v.begin(), v.end());
    pq.push(v[0].second);

    for (int i = 1; i < n; i++) {
        if (pq.top() <= v[i].first) {
            pq.pop();
            pq.push(v[i].second);
        }
        else {
            pq.push(v[i].second);
        }
    }

    cout << pq.size();
    return 0;
}
