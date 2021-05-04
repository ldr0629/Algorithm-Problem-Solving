#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef struct {
	int score;
	string name;
}STUDENT;

bool cmp(STUDENT s1, STUDENT s2) {
	return s1.score < s2.score;
}

int main() {
	int n;
	cin>>n;
	STUDENT s[n];
	for(int i = 0; i<n; i++) {
		cin>>s[i].name>>s[i].score;
	}
	
	sort(s, s+n, cmp);
	for(int i = 0; i<n; i++) {
		cout<<s[i].name<<' ';
	}
}
