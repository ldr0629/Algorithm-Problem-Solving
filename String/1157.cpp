#include <iostream>
#include <string>
#include <ctype.h>
#define NUM 26
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cout.tie(0);
	
	string s;
	cin>>s;
	
	int size = s.size(), max_cnt = -1, check = 0;
	int arr[NUM] = {0}, count_arr[NUM] = {0};
	for(int i = 0; i<size; i++) {
		s[i] = tolower(s[i]);
		arr[s[i]-'a']++;
	}
	
	char data;
	for(int i = 0; i<NUM; i++) {
		if(arr[i]>=max_cnt) {
			count_arr[i] = arr[i];
			max_cnt = arr[i];
			data = i + 'a' - 32;
		} 
	}
	
	for(int i = 0; i<NUM; i++) {
		if(count_arr[i] == max_cnt) check++;
	}
	
	// 가장 많이 사용된 알파벳이 여러개 존재하는 경우 "?" 출력 
	if(check > 1) cout<<"?";
	else cout<<data;
	
	return 0;
} 



