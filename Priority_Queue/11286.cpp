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

