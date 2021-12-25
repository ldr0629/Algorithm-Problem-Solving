#include <iostream>
#include <vector>
#define MAX 50
using namespace std;

int n;
vector<pair<pair<int,int>, int> > v[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	
	int n;
	cin>>n;
	
	for(int i = 0; i<n; i++) {
		int x, y;
		cin>>x>>y;
		v[i].push_back(make_pair(make_pair(x, y), 1));
	}
	
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			if(i==j) continue;

			if(v[i].front().first.first < v[j].front().first.first &&
			v[i].front().first.second < v[j].front().first.second) {
				v[i].front().second++;
			} 
		}
	}	
	
	for(int i = 0; i<n; i++) {
		cout<<v[i].front().second<<" ";
	}
} 

