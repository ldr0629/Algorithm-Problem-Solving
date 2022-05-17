#include <iostream>
#define MAX 1001
using namespace std;

int board[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	int n, pos_d, x = 0, y = 0, dir = 0;
	cin>>n>>pos_d;
	for(int i = n*n; i>=1; i--) {
		board[x][y] = i;
		int mx = x + dx[dir];
		int my = y + dy[dir];
		if(mx < 0 || mx >= n || my < 0 || my >= n || board[mx][my]) {
			mx = x - dx[dir]; my = y - dy[dir];
			dir = (dir+1)%4;	
			mx = x + dx[dir]; my = y + dy[dir];
		}
		x = mx; 
		y = my;
	}
	
	int res_x, res_y;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			cout<<board[i][j]<<" ";
			if(board[i][j] == pos_d) {
				res_x = i + 1;
				res_y = j + 1;
			}
		}
		cout<<"\n";
	}
	cout<<res_x<<" "<<res_y;
}
