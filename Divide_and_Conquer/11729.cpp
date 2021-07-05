#include <iostream>

using namespace std;

void hanoi_tower(int n, int from, int temp, int to) {
	if(n==1) {
		printf("%d %d\n",from ,to);
	}
	else {
		hanoi_tower(n-1, from, to, temp); // from으로부터 to를 이용해 temp 자리에 옮긴다.
		printf("%d %d\n",from ,to);
		hanoi_tower(n-1, temp, from, to); // temp에 있는 원판들로부터 from 자리를 이용해 to로 옮긴다.
	}
}

int pow(int x, int n) {
	if(n==0) return 1;
	else if(n%2==0) return pow(x*x, n/2);
	else return x*pow(x*x, (n-1)/2);
}

int main() { 
	int n, res;
	cin>>n;
	
	res = pow(2, n) - 1;
	cout<<res<<endl;
	
	hanoi_tower(n, 1, 2, 3);
}
