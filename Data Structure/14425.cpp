#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, cnt = 0;
	cin>>n>>m;
	
	string s;
	map<string, bool> str_m;
	for(int i = 0; i<n; i++) {
		cin>>s;
		str_m[s] = true;
	}
	
	for(int i = 0; i<m; i++) {
		cin>>s;
		if(str_m[s]) cnt++;
	}
	cout << cnt;
}
