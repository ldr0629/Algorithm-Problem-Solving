#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, data, alpha[26] = {0};
	cin>>n;
	
	string s;
	cin>>s;
	
	for(int i = 0; i<n; i++) {
		cin>>alpha[i];
	}
	
	stack<double> post_s;
	double a, b, result;
	for(int i = 0; i<s.length(); i++) {
		if(s[i]>=65 && s[i]<=90) {
			post_s.push(alpha[s[i]-'A']);
		} else {
			a = post_s.top();
			post_s.pop();
			b = post_s.top();
			post_s.pop();
			if(s[i] == '+') {
				post_s.push(a + b);
			} else if(s[i] == '-') {
				post_s.push(b - a);
			} else if(s[i] == '*') {
				post_s.push(a * b);
			} else if(s[i] == '/') {
				post_s.push(b / a);
			}
		}
	}
	
	result = post_s.top();
	cout<<fixed;
	cout.precision(2);
	cout<<result;
	return 0;
} 
