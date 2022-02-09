#include <iostream>
#include <cmath>
#include <vector>
#define MAX 4000001
using namespace std;

int n, prime_cnt = 0, sum = 0;
bool check[MAX];
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
    
  	// 단순 이중 for문으로 소수 판별시 시간초과이므로 에라토스테네스의 체 알고리즘 활용 
	for(int i = 2; i<sqrt(MAX); i++) {
		if(!check[i]) {
            // 소수가 아닌 경우 true 처리
			for(int j = 2*i; j<=MAX; j+=i) {
				check[j] = true;
			}
		}
	}

  	// 소수들을 오름차순 형태로 벡터에 푸쉬
	for(int i = 2; i<=n; i++) {
		if(!check[i]) {
			v.push_back(i);
		}
	}
    
  	// O(N^2) 시간초과를 방지하기 위해 O(N) 시간복잡도를 갖는 투 포인터 이용
	int left = 0, right = 0;
	while(1) {
		if(sum >= n) {
			if(sum == n) prime_cnt++;
			sum -= v[left++];
		} 
		else if(right == v.size()) {
			break;
		}
		else {
			sum += v[right++];
		}
	}
	cout<<prime_cnt;

} 
