#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> q;
	int n;
	cin>>n;
	for(int i = 1; i<=n; i++) {
		q.push(i);
	}
	
	for(int i = 1; i<n; i++) {
		q.pop();
		if(i==n-1)
			break;
		q.push(q.front());
		q.pop();
	}
	cout<<q.front();
}
