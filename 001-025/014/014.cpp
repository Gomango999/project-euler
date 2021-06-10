/*

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
#define x first
#define y second
#define pb push_back
#define all(x) x.begin(), x.end()

#define MAXN 1000005

bool done[MAXN];
ll memo[MAXN];

ll next(ll x) {
	if (x & 1) return 3*x+1;
	else return x/2;
}

// calculates how many iterations it takes to reach 1
ll dp(ll x) {
	if (x == 1) return 0;
	if (x < MAXN && done[x]) return memo[x];
	ll ans = dp(next(x)) + 1;
	if (x < MAXN) {
		done[x] = true;
		memo[x] = ans;
	}
	return ans;
}

void printChain(ll x) {
	while (x != 1) {
		printf("%lld -> ", x);
		x = next(x);
	}
	printf("1\n");
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	pii best = {0,0};
	for (int i = 1; i < 1000000; i++) {
		best = max(best, {dp(i), i});
	}
	// printChain(best.y);
	printf("%lld\n", best.y);
}
