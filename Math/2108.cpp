#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a < b;
}

int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	
	int arr[n], mode[8001] = {0}, sum = 0;
	for(int i = 0; i<n; i++) {
		cin>>arr[i];
		sum+=arr[i]; 
		mode[arr[i] + 4000]++; // -4000~4000 범위에서 음수 인덱스를 고려하여, 0~8000까지에 접근하게 함. 
	}
	sort(arr, arr+n, cmp); 
	
	int mode_max = 0, index = 0, mode_value;
	for(int i = 0; i<8001; i++) {
		if(mode[i] > mode_max) { // 최빈값이 나온 경우, 이때의 인덱스와 최빈값을 얻는다. 
			mode_max = mode[i];
			index = i;
			mode_value = i - 4000;  
		}
	}
	
	for(int i = 0; i<8001; i++) { 
		if((mode[i] == mode_max) && (index<i)) { // 최빈값이 여러 개인 경우, 두번째로 작은 값 설정. 
			mode_value = i - 4000;
			break;
		}
	} 
	
	cout<<round((double)sum/n)<<"\n"<<arr[n/2]<<"\n"<<mode_value<<"\n"<<arr[n-1] - arr[0];
  
	return 0;
} 
