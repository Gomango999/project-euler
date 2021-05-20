/*
76576500
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define x first
#define y second
#define pb push_back
#define all(x) x.begin(), x.end()

ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll num_iter = 1000000;
	for (ll i = 1; i <= num_iter; i++) {
		ll tri = i*(i+1)/2;

		ll factors = 0;
		ll j = 1;
		for (; j*j < tri; j++) {
			if (tri % j == 0) factors += 2;
		}
		if (j*j == tri) factors++;

		// printf("%lld: tri:%lld factors:%lld\n", i, tri, factors);

		if (factors > 500) {
			printf("%lld\n", tri);
			break;
		}
	}
}
