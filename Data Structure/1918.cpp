#include <iostream>
#include <stack>
#include <string>

using namespace std;

int prio(char op);
void infix_to_postfix(string sen);

int main() {
	string s;
	cin>>s;
	infix_to_postfix(s);
	return 0;
}

// 연산자의 우선순위 반환 
int prio(char op) {
	switch(op) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	} 
	return -1;
}

// 중위 표기 수식에서 후위 표기 수식으로 변환하는 알고리즘
void infix_to_postfix(string sen) {
	char ch, top_op, data;
	stack<char> s;
	
	for(int i = 0; i<sen.length(); i++) {
		ch = sen[i];
		switch(ch) {
			case '+': case '-': case '*': case '/': // 연산자 
				// 스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
				while(!s.empty() && (prio(ch) <= prio(s.top()))) {
					data = s.top();
					s.pop();
					cout<<data;
				}
				s.push(ch);
				break;
			case '(': // 왼쪽 괄호
				s.push(ch);
				break;
			case ')': // 오른쪽 괄호
				top_op = s.top();
				s.pop();
				// 왼쪽 괄호를 만날때까지 출력
				while(top_op != '(') {
					cout<<top_op;
					top_op = s.top();
					s.pop();
				}
				break;
			default: // 피연산자
				cout<<ch;
				break; 	 
		}
	} 
	while(!s.empty()) { // 스택에 저장된 나머지 연산자들 출력
		cout<<s.top();
		s.pop();
	}
} 
