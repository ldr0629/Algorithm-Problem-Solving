#include <bits/stdc++.h>
using namespace std;

int n, m, sum, index;
vector<int> v;
priority_queue<int, vector<int>, greater<int> > q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	// 전자기기와 콘센트의 개수 n, m 입력 
	cin>>n>>m;
	for(int i = 0; i<n; i++) {
		int data;
		cin>>data;
		sum+=data;
		v.push_back(data);
	}
	
	// 충전 시간이 긴 것부터 해야 최소 시간이 나올 수 있으므로 내림차순 정렬 
	sort(v.begin(), v.end(), greater<int>());
	
	// 충전기가 한 개인 경우 충전하는데 걸리는 시간은 각 기기가 걸리는 시간을 합친 것 
	if(m==1) cout<<sum;
	// 콘센트의 개수가 기기의 개수보다 클 때는 충전에 필요한 시간이 가장 큰 기기의 시간이 최소 
	else if(m>n) cout<<v[0];
	else {
		// 충전이 가능한 것부터 큐에 push 
		for(int i = 0; i<m; i++) q.push(v[i]);
		// 충전기 개수만큼 index가 바뀌고, 시간을 카운트하면서 가장 오래 걸리는 기기의 충전 시간보다 커질때
		// 큐에 들어가고 모든 기기가 충전을 다 할때까지 push 해주고 다 된 경우 충전에 필요한 최소 시간을 출력한다. 
		index+=m;
		while(index<n) {
			int sec = q.top();
			q.pop();
			while(sec <= q.top() && index<n) {
				sec += v[index++];
			}
			q.push(sec);
    }
    
		for(int i = 0; i<m-1; i++) q.pop();
		cout<<q.top();
	}	
} 
