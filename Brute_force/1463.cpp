#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, end_number = 666, cnt = 1;
	cin >> n;
  
  // n이 1인 경우에는 문자열 변환할 필요없이 무조건 666이므로 바로 출력.
	if (n == 1) {
		cout << 666;
	}
	else { // n이 1이 아닌 경우 계산하는 과정이 복잡하므로 문자열로 형변환하여 '666'과 일치하는 문자열 찾기.
		for (int i = end_number; i <= n*1000; i++) {

			string str = to_string(i);
			if (str.find("666") != string::npos) {
				if(cnt++ == n) {
					cout << str; 
					break;
				}
			}
		}
	}

	return 0;
}
