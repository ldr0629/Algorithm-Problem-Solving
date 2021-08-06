#include <iostream>
#include <vector>
using namespace std;

int d(int n) {
	int iter = n;
	while(n!=0) {
		iter += n%10;
		n/=10;
	}
	return iter;
}

int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);
    
  vector<bool> self_number(10001, true);
	for(int i = 1; i<10001; i++) {
		int data = d(i);
		if(data<=10000) {
			self_number[data] = false;
		}
	}
	
	for(int i = 1; i<10001; i++) {
		if(self_number[i]) { // 생성자가 없는 숫자
			cout<<i<<"\n";
		}
	}
	return 0;
} 
