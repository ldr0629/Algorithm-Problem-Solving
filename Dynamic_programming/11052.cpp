#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 1001
using namespace std;

// card는 개수에 따른 카드팩의 가격 배열이며, DP는 카드 n개 구매시 최대 비용을 나타냄.
int n, cnt;
int card[MAX];
int DP[MAX];

int main(void) {
	cin >> n;

	// 각 카드팩에 대한 비용 입력
	for (int i = 1; i <= n; i++) {
		cin >> card[i];
	}
	
	// index 0에 해당하는 값은 0으로 초기화
	DP[0] = card[0] = 0;
	for (int i = 1; i<=n; i++) {
		for (int j = 1; j <= i; j++) {
			// 각 카드팩에 들어간 개수를 파악하여 card의 카드팩 값을 더해주고,
			// 기존 i번째 DP에 해당하는 값과 비교하여 금액의 최댓값을 구해준다.
			DP[i] = max(DP[i - j] + card[j], DP[i]);
		}
	}
	// 카드 n개를 갖기 위해 지불해야 하는 금액의 최댓값 출력
	cout << DP[n]; 
	return 0;
}
