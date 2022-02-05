#include <iostream> 
#include <vector> 
#include <algorithm> 
#define MAX 8
using namespace std; 

int n; 
vector<int> arr; 
vector<int> v;
int result = 0; 
bool visited[MAX]; 

int diff() { 
	int sum = 0; 
	for(int i=0; i<n-1; i++) 
		sum += abs(v[i]-v[i+1]); 
	return sum; 
} 

void dfs(int depth) { 
	if(depth == n) { 
		result = max(diff(), result); 
		return; 
	} 
	
	for(int i=0; i<n; i++) { 
		if(!visited[i]) { 
			v.push_back(arr[i]); 
			visited[i]=true; 
			dfs(depth+1); 
			v.pop_back(); 
			visited[i]=false; 
		} 
	} 
} 

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	
	cin >> n; 
	for(int i=0; i<n; i++) { 
		int data; 
		cin >> data; 
		arr.push_back(data); 
	} 
	
	dfs(0); 
	cout << result; 
	return 0; 
}
