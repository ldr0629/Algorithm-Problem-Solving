#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	// 카드의 개수 n 입력 
	int n;
	cin>>n;
	
	// 카드의 개수만큼 레벨을 벡터에 입력 
	vector<int> v(MAX);
	for(int i = 0; i<n; i++) {
		cin>>v[i];
	}
	
	// 골드의 최댓값을 구해야하므로 내림차순 정렬 
	sort(v.begin(), v.end(), greater<int>());
	
	// 카드가 1개일 경우 최댓값은 벡터의 첫번째 원소이며,
	// 2개 이상일 경우, 각 카드들을 벡터에 있는 최대값과 합쳐나가면 골드의 최댓값을 구할 수 있다. 
	int gold_max = v[0], sum = 0;
	if(n == 1) {
		cout<<gold_max;
	} else {
		for(int i = 1; i<n; i++) {
			sum += (v[i] + gold_max);
		}
		cout<<sum;
	}
} 
