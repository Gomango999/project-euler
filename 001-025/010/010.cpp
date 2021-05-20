/*
142913828922
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

#define MAXN 2000005

bool comp[MAXN];
void seive() {
	comp[0] = comp[1] = true;
	for (ll i = 4; i < MAXN; i += 2) comp[i] = true;
	for (ll i = 3; i*i < MAXN; i += 2) {
		if (comp[i]) continue;
		for (ll j = i*i; j < MAXN; j += i*2) comp[j] = true;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	seive();

	ll sum = 0;
	for (int i = 1; i < 2000000; i++) {
		if (!comp[i]) sum += i;
	}
	printf("%lld\n", sum);
}
