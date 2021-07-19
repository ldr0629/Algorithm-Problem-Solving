#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a<b;
}

int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);	 
	int n, m, result, lower, upper;
	cin>>n;
	
	int mycard[n];
	for(int i = 0; i<n; i++) {
		cin>>mycard[i];
	}
	sort(mycard, mycard+n, cmp);
	
	cin>>m;
	int check_card[m];
	for(int i = 0; i<m; i++) {
		cin>>check_card[i];
	}
	
	for(int i = 0; i<m; i++) { 
    // 키 값보다 큰 값이 처음으로 나오는 위치에서 키 값이 처음으로 나오는 위치를 빼줌으로써 
    // 해당 키 값이 배열에서 몇 개 존재하는지 확인할 수 있음.
		result = upper_bound(mycard, mycard+n, check_card[i]) - lower_bound(mycard, mycard+n, check_card[i]);
		cout<<result<<' ';
	}
	return 0;
}
