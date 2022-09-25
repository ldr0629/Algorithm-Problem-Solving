#include <iostream>
using namespace std;

typedef long long ll;

ll a, b, c, res;
ll mul(ll a, ll b) {
	if (b == 1) return a % c;

	res = mul(a, b / 2);
	res = (res * res) % c;

	if (b % 2) res = (res * a) % c;
	return res; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> b >> c;
	cout << mul(a, b);

}
