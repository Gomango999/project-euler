/*
232792560
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
	return !b ? a : gcd(b, a%b);
}
ll lcm(ll a, ll b) {
	return (a / gcd(a,b)) * b;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll ans = 1;
	for (ll i = 1; i <= 20; i++) {
		ans = lcm(ans, i);
	}
	printf("%lld\n", ans);
}
