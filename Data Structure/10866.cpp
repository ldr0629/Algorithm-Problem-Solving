#include <iostream>
#include <deque>
#include <string.h>
using namespace std;

int main() {
	deque<int> dq;
	int n, num;
	char sen[30];
	cin>>n;
	for(int i = 0; i<n; i++) {
		cin>>sen;
		if(strcmp(sen, "push_front") == 0) {
			cin>>num;
			dq.push_front(num);
		}
		else if(strcmp(sen, "push_back") == 0) {
			cin>>num;
			dq.push_back(num);
		}
		else if(strcmp(sen, "pop_front") == 0) {
			if(!dq.empty()) {
				cout<<dq.front()<<endl;
				dq.pop_front();
			}
			else {
				cout<<-1<<endl;
			}
		}
		else if(strcmp(sen, "pop_back") == 0) {
			if(!dq.empty()) {
				cout<<dq.back()<<endl;
				dq.pop_back();
			}
			else {
				cout<<-1<<endl;
			}
		}
		else if(strcmp(sen, "size") == 0) {
			cout<<dq.size()<<endl;
		}
		else if(strcmp(sen, "empty") == 0) {
			if(dq.empty()) {
				cout<<1<<endl;
			}
			else {
				cout<<0<<endl;
			}
		}
		else if(strcmp(sen, "front") == 0) {
			if(!dq.empty()) {
				cout<<dq.front()<<endl;
			}
			else {
				cout<<-1<<endl;
			}
		}
		else if(strcmp(sen, "back") == 0) {
			if(!dq.empty()) {
				cout<<dq.back()<<endl;
			}
			else {
				cout<<-1<<endl;
			}
		}
	}
}

