#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool str_cmp(string a, string b) {
	return a < b;
}

int main() {
	string s;
	cin>>s;
	
	string arr[s.length()]; // 접미사의 수만큼 배열의 길이를 정함.
	for(int i = 0; i<s.length(); i++) {
		arr[i] = s.substr(i, s.length()-i); // 부분 문자열 추출
	}
	
	sort(arr, arr+s.length(), str_cmp);
	
	for(int i = 0; i<s.length(); i++) {
		cout<<arr[i]<<endl;
	}
	
} 

