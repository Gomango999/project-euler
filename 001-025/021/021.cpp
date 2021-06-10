/* 
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

#define MAXN 10000

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll d[MAXN+5] = {0};
	for (int i = 1; i <= MAXN; i++) {
		for (int j = 1; j*j <= i; j++) {
			if (i % j == 0) d[i] += ((j*j == i) ? j : (j + i/j));
		}
		d[i] -= i;
	}
	// for (int i = 1; i <= MAXN; i++) printf("%d: %lld\n", i, d[i]);

	ll sum = 0;
	for (int i = 1; i <= MAXN; i++) {
		int j = d[i];
		// printf("%d: %d\n", i, j);
		if (j < 0 || j > MAXN) continue;
		if (i != j && d[j] == i) sum += i;
	}
	printf("%lld\n", sum);
}
