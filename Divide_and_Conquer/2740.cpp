#include <iostream>
using namespace std;

int mat1[101][101];
int mat2[101][101];
int res_mat[101][101];

int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin>>n>>m;
	
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			cin>>mat1[i][j];
		}
	}
	
	cin>>m>>k;
	for(int i = 0; i<m; i++) {
		for(int j = 0; j<k; j++) {
			cin>>mat2[i][j];
		}
	}
	
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<k; j++) {
			for(int l = 0; l<m; l++) {
				res_mat[i][j] += mat1[i][l]*mat2[l][j];	
			}
			cout<<res_mat[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
} 


