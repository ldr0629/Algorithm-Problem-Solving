#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, meet_cnt = 0;
	cin>>n;
	
	// 각 회의 I에 대해 시작 시간과 끝나는 시간이 주어지므로 pair로 벡터를 선언
	vector<pair<int, int> > v(n);
	for(int i = 0; i<n; i++) {
		cin>>v[i].second>>v[i].first;
	}
	
	// 시작 시간 기준으로 오름차순 정렬
	sort(v.begin(), v.end());
	
	// 각 회의가 겹치지 않게 하면서 회의실을 사용할수 있는 회의의 최대 개수를 구한다.
	int s = 0;
	for(int i = 0; i<v.size(); i++) {
		if(s <= v[i].second) {
			s = v[i].first;
			meet_cnt++;
		}
	}
	
	cout<<meet_cnt;
	
    return 0;
}
