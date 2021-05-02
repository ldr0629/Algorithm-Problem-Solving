#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int age;
	string name;
	int join;
}PERSON;

bool cmp(PERSON p1, PERSON p2) {
	if(p1.age == p2.age)
		return p1.join < p2.join;
	else
		return p1.age < p2.age;
}

int main() {
	int t;
	cin>>t;
	vector<PERSON> p(t);
	for(int i = 0; i<t; i++) {
		cin>>p[i].age>>p[i].name;
		p[i].join = i;
	}
	sort(p.begin(), p.end(), cmp);
	for(int i = 0; i<t; i++) {
		cout<<p[i].age<<' '<<p[i].name<<"\n";
	}
}
