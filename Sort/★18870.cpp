#include <iostream> // 첫번째 풀이 (STL 활용)
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int n1, int n2) {
	return n1 < n2;
}

int main() { 
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0; i<n; i++) {
		cin>>v[i]; 
	}
	vector<int> cp_v(v);
	
	sort(cp_v.begin(), cp_v.end(), cmp); // 복사본 벡터 정렬
	cp_v.erase(unique(cp_v.begin(), cp_v.end()), cp_v.end()); // 오름차순 정렬된 복사본 벡터에서 중복 원소 제거
	for(int i = 0; i<n; i++) {
		auto v_loc = lower_bound(cp_v.begin(), cp_v.end(), v[i]); // 원본 벡터의 i번째 원소를 복사본 벡터에서 가장 처음 나오는 위치로 찾아 주소값을 반환
		cout<<v_loc-cp_v.begin()<<' '; // lower_bound 함수의 반환값에서 정렬된 복사본 벡터의 첫번째 주소값을 빼준다. (x_i > x_j을 만족)
	}
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
#include <iostream> // 두번째 풀이 (테스트 케이스는 통과했으나 시간 초과)
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n, cnt = 0;
	scanf("%d",&n);
	int arr[n], sort_arr[n];
	for(int i = 0; i<n; i++) {
		scanf("%d",&arr[i]);
		sort_arr[i] = arr[i];
	}
	sort(sort_arr, sort_arr+n, cmp); 
	
	for(int i = 0; i<n; i++) {
		cnt = 0;
		for(int j = 0; j<n; j++) {
			if(arr[i]>sort_arr[j]) {
				if(sort_arr[j] == sort_arr[j+1])
					continue;
				cnt++;
			}
		}
		printf("%d ",cnt);
	}
} 
