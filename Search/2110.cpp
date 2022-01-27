#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, c, max_dist = 0;
	cin>>n>>c;
	
	vector<int> v(n);
	for(int i = 0; i<n; i++) {
		cin>>v[i];
	}
	
	// 이분 탐색을 위해 입력한 좌표들을 오름차순으로 정렬 
	sort(v.begin(), v.end());
	
	// 이분 탐색의 범위는 처음 좌표인 0부터 입력 좌표의 마지막 값까지이다. 
	int start = 0, end = v[n-1];
	
	// 집 사이의 거리를 mid와 비교해 설치할 수 있는 공유기를 카운트하고, 
	// 가장 인접한 두 공유기 사이의 최대 거리를 구한다. 
	while(start<=end) {
		int mid = (start + end) / 2, ip_cnt = 1;
		int prev = v[0]; // 항상 처음에는 첫 집을 기준으로한다. 
		for(int i = 1; i<n; i++) { 
			if(v[i] - prev >= mid) { // mid보다 크거나 같아지면 기준을 변경한다. 
				prev = v[i];
				ip_cnt++;
			} 
		}
		if(ip_cnt >= c) {
			start = mid + 1;
			max_dist = max(max_dist, mid);
		} else {
			end = mid - 1;
		}
	}
	cout<<max_dist;
}
