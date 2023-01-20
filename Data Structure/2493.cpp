#include <iostream>
#include <stack>
using namespace std;

stack<pair<int, int>> stk;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, h;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> h;

      // 스택이 비어있지 않은 경우 수신 가능한 탑을 찾아 출력
      while (!stk.empty()) {
        if (stk.top().second > h) {
          cout << stk.top().first << " ";
          break;
        }
        stk.pop();
      }

      // 스택이 비어있는 경우 수신받을 수 없는 상태
      if (stk.empty()) {
        cout << 0 << " ";
      }

      stk.push({ i, h });
    }

}
