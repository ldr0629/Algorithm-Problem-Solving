#include <iostream>
#include <string>
#define TIME 60
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int n, cnt = 0;
	string s;
	cin>>n;
	
	// 가능한 경우의 수를 모두 검사해보는 방법(완전 탐색)
	// 비효율적 시간 복잡도로써 완전 탐색은 전체 데이터의 개수가 100만 개 이하일 때 적절
	for(int i = 0; i<n+1; i++) {
		for(int j = 0; j<TIME; j++) { 	
			for(int k = 0; k<TIME; k++) {
				s = to_string(i) + to_string(j) + to_string(k);
				if(s.find("3") != string::npos) // 문자열에서 특정 문자를 찾는 경우 string 클래스 내 find 함수 이용 
					cnt++;
			}
		}
	} 
	cout<<cnt;
	return 0;
}
