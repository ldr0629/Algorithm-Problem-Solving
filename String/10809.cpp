#include <iostream>
#include <string.h>

using namespace std;

int alpha_cnt[26];

int main() {
	char s[99];
	cin>>s; 
	
	for(int i = 'a'; i<='z'; i++) { 
		for(int j = 0; s[j]!='\0'; j++) {
			if(s[j] == i) {
				alpha_cnt[i-'a'] = j+1;
				break; 
			}
		}
	}
	
	for(int i = 0; i<26; i++) {
		cout<<alpha_cnt[i]-1<<' '; 
	}
	return 0;
}
