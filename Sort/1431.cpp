#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s[1000];

int numSum(string s) {
	int sum = 0;
	for(int i = 0; i<s.length(); i++) {
		if(s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			sum += s[i] - '0';
		}
	}
	return sum;
}

bool cmp(string a, string b) {
	if(a.length() < b.length()) {
		return 1;
	} else if(a.length() > b.length()) {
		return 0;
	} else {
		int n1 = numSum(a);
		int n2 = numSum(b);
		if(n1 != n2) {
			return n1 < n2;
		} else{
			return a < b;
		}
	}

}

int main() {
	int n;
	cin>>n;
	for(int i = 0; i<n; i++) {
		cin>>s[i];
	}
	sort(s, s+n, cmp);
	for(int i = 0; i<n; i++) {
		cout<<s[i]<<'\n';
	}
}
