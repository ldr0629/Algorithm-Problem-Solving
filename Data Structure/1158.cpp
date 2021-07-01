#include <iostream> // 11866번 문제와 동일
#include <queue>
using namespace std;

int main() {
	queue<int> q;
	int n, k, data, cnt = 0;
	cin>>n>>k; 
	cout<<'<'; 
  
	for(int i = 1; i<=n; i++) {
		q.push(i); 
	}
	
	for(int i = 0; i<n*k; i++) {
		cnt++;
		if(cnt%k==0) {  // 순서대로 k번째 사람을 제거
			data = q.front();  
			q.pop();
      
			if(cnt == n*k)
				cout<<data;
			else
				cout<<data<<", ";
				
		} else { // k번째 사람이 아닌 경우 제거하고 뒤에 다시 삽입
			data = q.front();
			q.pop();
			q.push(data);
		}  
			
	}
	cout<<'>';
} 

