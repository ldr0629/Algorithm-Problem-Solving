#include <iostream>
using namespace std;

int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);	 
	int e, s, m, year = 1;
	cin>>e>>s>>m;
	while(1) {
		if((year-e)%15==0 && (year-s)%28==0 && (year-m)%19==0) { // 각각의 배수에 모두 만족할 때 연도를 구할 수 있음.
			break;
		}
		year++;
	}
	cout<<year;
	return 0;
} 
