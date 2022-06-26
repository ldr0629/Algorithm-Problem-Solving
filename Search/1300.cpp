#include <iostream>
using namespace std;

int n, k, cnt;
int result;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    
    int s = 1, e = k, mid;
    while (s <= e) {
        cnt = 0;
        mid = (s + e) / 2;
        for (int i = 1; i <= n; i++) {
            cnt += min(mid / i, n);
        }

        if (cnt < k) {
            s = mid + 1;
        }
        else {
            result = mid;
            e = mid - 1;
        }
    }
    cout << result;
    return 0;
}
