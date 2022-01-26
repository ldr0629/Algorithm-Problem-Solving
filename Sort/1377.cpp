#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
    
  	// 데이터와 인덱스 두 값을 한쌍에 저장하기 위해 pair 이용한다.
	vector<pair<int, int>> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}
    
  	// 일반적인 버블 소트의 코드는 시간초과가 날 것이기에 O(n*logn)의 정렬을 활용한다.
	sort(A.begin(), A.end());
    
  	// 정렬 수행 전과 수행 후의 인덱스 최대 차이 값을 저장하기 위한 변수를 선언하고,
  	// 인덱스 차이를 비교해서 최대 차이 값을 출력한다.
	int maxDiffIndex = 0;
	for (int i = 0; i < N; i++) {
		if (A[i].second - i > maxDiffIndex) {
			maxDiffIndex = A[i].second - i;
		}
	}
	cout << maxDiffIndex + 1;
}
