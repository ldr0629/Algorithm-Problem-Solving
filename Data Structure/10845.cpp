#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int main() { 
	queue<int> q;
	char sen[10];
	int n, num, pop_num;
	cin>>n;
	for(int i = 0; i<n; i++) {
		cin>>sen;
		if(strcmp(sen, "push") == 0) {
			cin>>num;
			q.push(num);
		}
		else if(strcmp(sen, "front") == 0) {
			if(!q.empty()) {
				cout<<q.front()<<endl;
			}
			else {
				cout<<-1<<endl;
			}
		}
		else if(strcmp(sen, "back") == 0) {
			if(!q.empty()) {
				cout<<q.back()<<endl;
			}
			else {
				cout<<-1<<endl;
			}
		}
		else if(strcmp(sen, "size") == 0) {
			cout<<q.size()<<endl;
		}
		else if(strcmp(sen, "empty") == 0) {
			if(q.empty()) {
				cout<<1<<endl;
			}
			else {
				cout<<0<<endl;
			}	
		}
		else if(strcmp(sen, "pop") == 0) {
			if(!q.empty()) {
				cout<<q.front()<<endl;
				q.pop();
			}
			else {
				cout<<-1<<endl;
			}
		}
	}
}
