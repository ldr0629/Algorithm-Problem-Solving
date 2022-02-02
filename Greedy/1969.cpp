#include <iostream>
#define MAX 1001
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	// DNA 수 N과 문자열 길이 M, distance의 합을 나타내는 변수 선언 
	int n, m, dist_sum = 0;
	cin>>n>>m;
	
	// N만큼 DNA를 입력받으며, distance의 합이 가장 작은 DNA의 변수 선언 
	string DNA[MAX], DNA_result = "";
	for(int i = 0; i<n; i++) {
		cin>>DNA[i];
	}
	
	for(int i = 0; i<m; i++) {
		// A, C, G, T를 각각 카운트하기 위한 배열 선언 후 카운트 
		int alpha[26] = {0};
		for(int j = 0; j<n; j++) {
			alpha[DNA[j][i] - 'A']++;
		}
		
		// DNA에서 가장 많이 나온 문자의 카운트값과 index를 정한다. 
		int max = 0, index = 0;
		for(int k = 0; k<26; k++) {
			if(max < alpha[k]) {
				max = alpha[k];
				index = k;
			}
		}
		// 최종적으로 Hamming Distance 합이 가장 작은 DNA에 문자를 하나씩 채우고,
		// Hamming Distance도 DNA의 수인 N에서 각 DNA마다 max를 빼준 값을 더해주면 합을 구할 수 있다. 
		DNA_result += 'A' + index;
		dist_sum += n - max;
	}
	
	cout<<DNA_result<<"\n"<<dist_sum;
} 
