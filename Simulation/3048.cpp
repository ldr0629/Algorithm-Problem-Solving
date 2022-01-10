#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 첫 번째 그룹과 두 번째 그룹의 개미의 수를 나타내는 변수 n1, n2와 초 변수 T.
int n1, n2, T;   

// 그룹1과 그룹2의 순서에 대한 문자열 변수와 최종 순서인 result.
string ants_one, ants_two, result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	
	// n1, n2 입력 후 수에 맞게 문자열 입력. 
	cin>>n1>>n2;
	cin>>ants_one>>ants_two>>T;
	
	// 첫번째 그룹에서 오른쪽으로 가는 방향일 때 원 문자열의 역순이므로 reverse 
	reverse(ants_one.begin(), ants_one.end());
	// 처음에 만났을 때에 순서 초기화 
	result = ants_one + ants_two;
	
	while(T!=0) {
		// 두 그룹의 개미 수 끝까지 인접하는지 확인하며 이동.
		// 인접해서 반대 방향으로 움직이는 경우 swap하고, 
		// 이동한 후 바로 다음엔 이동시킬 필요가 없으므로 한번 더 i를 증가시킨다. 
		for(int i = 0; i<n1+n2; i++) {
			if(ants_one.find(result[i]) != string::npos
			&& ants_two.find(result[i+1]) != string::npos) {
				swap(result[i], result[i+1]);
				i++;
			}
		}
		T--;
		
	}
	// T초가 지난 후 최종 개미들의 순서 출력. 
	cout<<result;
	return 0;
} 



