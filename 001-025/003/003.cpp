/*
6857
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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll N = 600851475143;
	ll best = 1;
	for (ll i = 2; i * i <= N; i++) { // sqrt(N)
		while (N % i == 0) { // log(N)
			N /= i;
			best = max(best, i);
		}
	}
	if (N > 1) best = max(best, N);
	printf("%lld\n", best);
}
