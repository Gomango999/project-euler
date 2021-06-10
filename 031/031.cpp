/*
dp[i][j] = ways of making j pence using first i coins.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define rep(i, n) for (int i = 0; i < (n); i++)

#define MAXP 205

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	const int N = 8;
	int v[N] = {1,2,5,10,20,50,100,200};

	ll dp[N+5][MAXP] = {{0}};
	dp[0][0] = 1;
	for (int i = 1; i <= 8; i++) {
		for (int j = 0; j <= 200; j++) {
			dp[i][j] = dp[i-1][j];
			for (int k = j-v[i-1]; k >= 0; k -= v[i-1]) {
				dp[i][j] += dp[i-1][k];
			}
		}
	}
	printf("%lld\n", dp[8][200]);
}
