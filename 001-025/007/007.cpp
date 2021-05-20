/*
104743
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

#define MAXN 1000005

bool prime[MAXN];
void seive() {
	fill(prime, prime+MAXN, true);
	prime[1] = false;
	for (int i = 0; i < MAXN; i+=2) prime[i] = false;
	prime[2] = true;
	for (ll i = 3; i < MAXN; i+=2) {
		if (!prime[i]) continue;
		for (ll j = i*i; j < MAXN; j += i*2) {
			prime[j] = false;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	seive();
	int p = 0;
	for (int i = 2; i < MAXN; i++) {
		if (prime[i]) p++;
		if (p == 10001) {
			printf("%d\n", i);
			break;
		}
	}
}
