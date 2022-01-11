#include <iostream>
#include <vector>
#include <limits.h>
#define MAX 50
using namespace std;

int n;
vector<int> d(MAX);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	
	// n의 약수의 개수 입력. 
	cin>>n;
	
	// n의 약수 입력. 
	for(int i = 0; i<n; i++) {
		cin>>d[i];
	}
	
	// 약수의 최소값, 최대값을 구한다. 
	int min = INT_MAX, max = INT_MIN;
	for(int i = 0; i<n; i++) {
		if(min>d[i]) {
			min = d[i];
		}
		if(max<d[i]) {
			max = d[i];
		}
	}
	
	// 위에서 구한 최소, 최대값을 곱해주어 N을 출력한다. 
	cout<<min*max;
	return 0;
} 

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <algorithm> 
#define MAX 50
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	
	// n의 약수의 개수 입력. 
	cin>>n;
	int* d = new int[n];
	
	// n의 약수 입력. 
	for(int i = 0; i<n; i++) {
		cin>>d[i];
	}
	
    // 정렬을 함으로써 약수의 최소값과 최대값에 쉽게 접근할 수 있다.
	sort(d, d+n);

    // 약수 배열에 속한 최소값과 최대값을 곱하여 n을 구한다.
	cout<<d[0]*d[n-1];
	return 0;
} 

