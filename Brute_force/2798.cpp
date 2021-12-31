#include <iostream>
#define MAX 100
using namespace std;

int main(void) {
	int n, m, min = 9999999, sum = 0, result;
	cin>>n>>m;
	
	int card[MAX] = {0};
	for(int i = 0; i<n; i++) {
		cin>>card[i];
	}
	
	for(int i = 0; i<n-2; i++) {
		for(int j = i+1; j<n-1; j++) {
			for(int k = j+1; k<n; k++) {
				sum = card[i] + card[j] + card[k];
				if(m-sum<min && m-sum >= 0) {
					min = m-sum;
					result = sum;
				}
			}
		}
	}
	cout<<result<<"\n";
    return 0;
}
