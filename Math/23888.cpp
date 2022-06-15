#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long int

ll Gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return Gcd(b, a % b);
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll A, D, Q;
	cin >> A >> D;
	cin >> Q;
	FOR(q, 1, Q) {
		ll kind, l, r;
		cin >> kind >> l >> r;
		if (kind == 1) {
			ll tmp1 = r * (2 * A + (r - 1) * D) / 2;
			ll tmp2 = (l - 1) * (2 * A + (l - 2) * D) / 2;
			cout << tmp1 - tmp2 << "\n";
		}
		else if (kind == 2) {
			if (l == r) {
				cout << A + (l - 1) * D << "\n";
			}
			else {
				cout << Gcd(A, D) << "\n";
			}
		}
	}


	return 0;
}
