#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	
	priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

	int n, x;
	cin>>n;
	
	for(int i = 0; i<n; i++) {
		cin>>x;
		// x가 0이 아니라면 우선순위 큐에 x라는 값을 넣는 연산이고, 0이라면 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거
		// 큐가 비어있다면 0을 출력
		if(x==0) {
			if(!pq.empty()) {
				cout<<pq.top().second<<"\n";
				pq.pop();
			} else {
				cout<<0<<"\n";
			}
		} else {
			pq.push({abs(x), x});
		}
	}
} 

