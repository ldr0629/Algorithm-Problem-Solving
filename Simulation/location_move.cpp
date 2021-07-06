#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int n;
	cin>>n;
	
	int x = 1, y = 1;
	char move;
	
	while(move!='n') { // n을 입력할 때까지 이동 계획서 작성 
		cin>>move;
		
		if(move == 'R' && n+1 != y+1) {
			y++;
		} else if(move == 'L' && 0 != y-1) {
			y--;
		} else if(move == 'U' && 0 != x-1) {
			x--;
		} else if(move == 'D' && n+1 != x+1) {
			x++;
		}
	} 
	
	cout<<x<<' '<<y;
	return 0;
}
