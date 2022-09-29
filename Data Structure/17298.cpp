#include <iostream>
#include <stack>
#define MAX 1000001
using namespace std;

int n;
stack<int> s;
int answer[MAX];
int seq[MAX];

int main() {


	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= seq[i])
			s.pop();

		if (s.empty()) answer[i] = -1;
		else answer[i] = s.top();

		s.push(seq[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}
}
