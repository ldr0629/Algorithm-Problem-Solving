#include <stdio.h>  # 에라토스테네스의 체 알고리즘
#include <math.h>

int main() {
	bool prime[1000000];
	int n, m, i, j;
	scanf("%d %d",&m ,&n);
	
	prime[1] = false;
	for(i=2; i<1000000; i++) {
		prime[i] = true;
	}
	
	for(i=2; i<=sqrt(1000000); i++) {
		if(prime[i] == true) {
			for(j=i*2; j<=1000000; j = j + i) { 
				prime[j] = false; 
			}
		}
	}
	
	for(i=m; i<=n; i++) {
		if(prime[i])
			printf("%d\n",i);
	}
}


