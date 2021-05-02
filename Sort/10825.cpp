#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct {
	int kor, eng, mat;
	string name;
}STU;

bool compare(STU& p1, STU& p2) {
	if(p1.kor == p2.kor && p1.eng == p2.eng && p1.mat == p2.mat) 
		return p1.name < p2.name;
	else if(p1.kor == p2.kor && p1.eng == p2.eng)
		return p1.mat > p2.mat;
	else if(p1.kor == p2.kor)
		return p1.eng < p2.eng;
	else
		return p1.kor > p2.kor;
}

int main() {
	int n;
	cin>>n;
	STU s[n];
	for(int i = 0; i<n; i++) {
		cin>>s[i].name>>s[i].kor>>s[i].eng>>s[i].mat;
	}
	sort(s, s+n, compare);
	
	for(int i = 0; i<n; i++) {
		cout<<s[i].name<<"\n";
	}
}
