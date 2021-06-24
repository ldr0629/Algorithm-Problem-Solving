#include <iostream>

using namespace std;

int main() {
	int n, k, cnt = 0;
	cin>>n>>k;
	
	// 1을 빼는 것보다 최대한 나누기를 이용해 몫을 줄이고 1에 가까워지게 만듦으로써 줄어드는 양을 증가시킴. (k>=2 가정)
	while(n!=1) {
		if(n%k==0) {
			n/=k;
			cnt++;
		}
		else {
			n-=1;
			cnt++;
		}
	}
	
	cout<<cnt<<endl;
}
