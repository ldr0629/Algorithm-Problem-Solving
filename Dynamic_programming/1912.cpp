#include <iostream>
#include <limits.h>

using namespace std;

// 양수일 때 연속합의 최대를 구하는 함수로, temp가 0보다 작아질 때 0으로 초기화해준다.
int getMaxSubsequence(int arr[], int n)   
{						
	int temp = 0, max = 0;
	for(int i=0; i<n; i++)
	{
		temp += arr[i];
		if(temp > max)
			max=temp;
		else if(temp<0)
			temp=0;
	}
	return max;
}

// main에서 result가 0일 때 배열에서의 연속합 최대값이 음수인 경우를 고려한 함수
int getMaxElement(int arr[], int n) {
	int max2 = -1000;
	for(int i=0; i<n; i++)
	{
		if(max2<arr[i])
			max2=arr[i];
	}
	return max2;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
  
	for(int i = 0; i<n; i++) {
		cin>>arr[i];
	}
   
	int result = getMaxSubsequence(arr, n);
  // result가 0이 아닌 경우 연속합 출력
	if(result != 0)
		cout<<result;
	else
        cout<<getMaxElement(arr, n);
	return 0;
	
} 
