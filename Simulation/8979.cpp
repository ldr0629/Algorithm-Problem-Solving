#include <iostream>
#define MAX 1001
using namespace std;

// 국가의 수 n, 등수를 알고싶은 국가 k, 국가에 대한 넘버 num, 등수에 대한 정보인 rank
int n, k, res = 0;
// 각 국가에 대한 금, 은, 동 정보를 나타내기 위한 배열
int gold[MAX], silver[MAX], bronze[MAX]; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	

    // 국가의 수 n과 등수를 알고싶은 국가인 k 입력
	cin>>n>>k;
 	
 	// 국가를 나타내는 번호와 금, 은, 동 개수 입력 
	for(int i = 0; i<n; i++) {
		int num;
		cin>>num>>gold[num]>>silver[num]>>bronze[num];
	} 
	
    // 금, 은, 동 순으로 정렬되므로 i번째에 해당하는 국가보다 메달 수가 적을 때마다 rank가 1씩 증가
    // 등수가 동일하면 증가하지 않는다.
    for(int i = 1; i<=n; i++) {
		if(gold[i] > gold[k]) {
			res++;
		} else if(gold[i] == gold[k]) {
			if(silver[i] > silver[k]) res++;
		} else if(silver[i] == silver[k]) {
			if(bronze[i] > bronze[k]) res++;
		}
	}
    
    // 국가 k의 등수 출력
	cout<<res;
	return 0;
} 



