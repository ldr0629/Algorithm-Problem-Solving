#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

bool cmp(int a, int b) {
	return a < b;
}

// 시간초과로 인해 cin, cout 대신 scanf, printf를 사용하였으며 메모리 공간을 낭비 하지않기 위하여 동적으로 메모리를 할당하였음.
int main() {
	int n, k;
	scanf("%d %d",&n ,&k);
	int* arr = new int[n];
	for(int i = 0; i<n; i++) {
		scanf("%d",&arr[i]);
	}
	sort(arr, arr+n, cmp);
	printf("%d",arr[k-1]);
	
	delete[] arr;
}
