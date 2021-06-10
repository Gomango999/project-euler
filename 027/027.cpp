/* 
Is there an upper limit on how many primes can be produced?
Yes: b. Therefore, at most 1000 primes.

Max number will be 1000^2 + 1000^2 + 1000 < 3,000,000

Test 1000 * 1000 * 1000?
In practice, most will fail instantly.
For example, if b is even, then all n will be less than 1.
b must also be positive.

Ran in 0.29
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

#define MAXN 300006

bool prime[MAXN];
void sieve() {
	fill(prime, prime+MAXN, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= MAXN; i++) {
		if (!prime[i]) continue;
		for (int j = i * i; j < MAXN; j += (i == 2) ? i : i*2) {
			prime[j] = false;
		}
	}
}

int check(int a, int b) {
	for (int n = 0; n <= b; n++) {
		int res = n*n + a*n + b;
		if (res <= 1 || !prime[res]) return n-1;
	}
	return b;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	sieve();

	pii best = {-1, -1};
	for (int a = -1000; a <= 1000; a++) {
		for (int b = 3; b <= 999; b+=2) { // b must be odd, > 1
			best = max(best, {check(a,b), a*b});
		}
	}
	printf("%d\n", best.y);
}
