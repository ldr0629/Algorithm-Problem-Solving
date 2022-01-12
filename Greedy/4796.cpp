#include <iostream>

using namespace std;

int L, P, V;
int i = 1, vacation;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	
	while(1) {
		vacation = 0; // 케이스 별로 최대 사용 기간이 다르므로 매 번 0으로 초기화. 
		cin>>L>>P>>V; // 사용 가능 기간, 캠핑장 연속 기간, 휴가 기간 입력. 
		if(L==0 && P==0 && V==0) break; // 입력 종료 시 모두 0. 
		
		vacation = V/P*L; // 휴가 기간 중 캠핑장을 연속하는 최대 기간 내 사용할 수 있는 기간인 L을 곱한다. 
		vacation += (V%P > L ? L : V%P); // 위에서 휴가를 쓰고 남은 기간에서 사용 가능 기간과 비교했을 때 더 작은 값을 더한다. 
		cout<<"Case "<<i++<<": "<<vacation<<"\n";
	}
	return 0;
} 

