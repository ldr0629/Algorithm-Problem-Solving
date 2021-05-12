#include <iostream>
#include <string>
using namespace std;

int alpha[26];

int main() {
	string sen;
	cin>>sen;
	
	for(int i = 0; i<sen.length(); i++) { 
		alpha[sen[i]-'a']++;
	}
	
	for(int i = 0; i<26; i++) {
		cout<<alpha[i]<<' ';
	}
	return 0;
}
