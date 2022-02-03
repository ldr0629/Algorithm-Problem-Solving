#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	// 테스트 케이스 t와, 케이스 별 지원자 수 n 입력 
	int t, n;
	cin>>t;
	for(int i = 0; i<t; i++) {
		cin>>n;
		
		// 각 지원자마다 서류심사 성적과 면접 성적이 하나의 데이터이므로 pair로 묶어 데이터 입력 
		vector<pair<int, int> > v;
		for(int j = 0; j < n; j++) {
			int d1, d2;
			cin>>d1>>d2;
			v.push_back({d1, d2});
		}
		
		// 시간 초과를 방지하기 위해 먼저 서류 심사 성적 기준으로 오름차순 정렬 후,
		// 높은 순위에 있는 지원자 기준으로 비교하면서 신입사원 최대 인원 수를 카운트.
		// 기준은 카운트될때마다 index로 바뀌며, 정렬을 수행하면 첫번째 원소는 무조건 선발되므로 result가 1로 시작한다. 
		int result = 1, index = 0;
		sort(v.begin(), v.end());
		for(int k = 1; k < n; k++) {
			if(v[index].second > v[k].second) {
				result++;
				index = k;
			}
		}
		cout<<result<<"\n";
	} 
} 
