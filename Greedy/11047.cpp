#include <iostream>

using namespace std;

int main() {
	int n, k, cnt = 0;
	cin>>n>>k;
	
	int coin[n];
	for(int i = 0; i<n; i++) {
		cin>>coin[i];
	}
	 
	for(int i = n-1; i>=0; i--) { // 동전 개수의 최솟값을 구하기 위하여 n-1부터 시작.
		cnt += k / coin[i]; // 일일이 빼기 연산을 하지않고, 몫을 이용해 k를 새로 갱신.
		k%=coin[i]; 
    
		/*
		while(coin[i]<=k) { // k가 1억 이하라서 시간초과는 아니지만, 시간적으로 비효율적인 코드.
	        k-=coin[i];
		cnt++;
		}
		*/
	}
	cout<<cnt;
}
