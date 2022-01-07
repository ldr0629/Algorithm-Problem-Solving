#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int cmp(string s1, string s2) {
	return s1 < s2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cout.tie(0);

	int n, max_cnt = -1, cnt;
	cin>>n;
	
	vector<string> book(n);
	string best_book;
	for(int i = 0; i<n; i++) {
		cin>>book[i];
	}
	
	sort(book.begin(), book.end(), cmp);
	for(int i = 0; i<n; i++) {
		cnt = 0;
		for(int j = 0; j<n; j++) {
			if(book[i] == book[j]) {
				cnt++;
			}
		}
		if(cnt>max_cnt) {
			best_book = book[i];
			max_cnt = cnt;
		}
	}
	cout<<best_book;
	return 0;
} 



