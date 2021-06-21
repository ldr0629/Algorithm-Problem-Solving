#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	int n, m, k, max = 0, sum = 0, cnt_two = 0; // M, 10,000 이하인 경우
	cin>>n>>m>>k;
	
	int arr[n], cnt[n];
	for(int i = 0; i<n; i++) {
		cin>>arr[i];
		cnt[i] = 0;
		if(max < arr[i])
			max = arr[i];
	}
  
	sort(arr, arr+n, cmp);
  
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			if(max == arr[i]) {
				cnt[i]++;
				cnt_two++;	
			}
			else
				break;
			
			if(cnt[i]<=k)
				sum+=arr[i];
			else {
				cnt[i] = 0;
				sum+=arr[n-2];
			}
		}
    
		if(cnt_two > 0)
			break;
	}
	cout<<sum<<endl;
	return 0;
	
}
