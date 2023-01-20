#include <iostream>
#include <string>
#include <string.h>
#include <queue>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	queue<int> q;
	int n, num;
	char sen[30];
	cin>>n;
	for(int i = 0; i<n; i++) {
		cin>>sen;
		if(strcmp(sen, "push") == 0) {
			cin>>num;
			q.push(num);
		}
		else if(strcmp(sen, "pop") == 0) {
			if(!q.empty()) {
				cout<<q.front()<<"\n";
				q.pop();
			}
			else {
				cout<<-1<<"\n";
			}
		}
		else if(strcmp(sen, "size") == 0) {
			cout<<q.size()<<"\n";
		}
		else if(strcmp(sen, "empty") == 0) {
			if(q.empty()) {
				cout<<1<<"\n";
			}
			else {
				cout<<0<<"\n";
			}
		}
		else if(strcmp(sen, "front") == 0) {
			if(!q.empty()) {
				cout<<q.front()<<"\n";
			}
			else {
				cout<<-1<<"\n";
			}
		}
		else if(strcmp(sen, "back") == 0) {
			if(!q.empty()) {
				cout<<q.back()<<"\n";
			}
			else {
				cout<<-1<<"\n";
			}
		}
	}
}


