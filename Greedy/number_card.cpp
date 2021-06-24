#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	int row, col, min;
	cin>>row>>col;
	
	int card[row][col], row_num[row];
	for(int i = 0; i<row; i++) {
		min = 10001; // 숫자의 범위 1~10000 
    
		for(int j = 0; j<col; j++) {
			cin>>card[i][j];	
			if(card[i][j]<min)
				min = card[i][j];
		}
		
		row_num[i] = min;
	}
	
	sort(row_num, row_num+row, cmp);
  
	cout<<row_num[row-1]<<endl;
}
