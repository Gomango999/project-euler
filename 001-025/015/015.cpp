/*
137846528820
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

#define MAXN 21
ll dp[MAXN][MAXN];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	dp[0][0] = 1;
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			if (i) dp[i][j] += dp[i-1][j];
			if (j) dp[i][j] += dp[i][j-1];
		}
	}
	printf("%lld\n", dp[20][20]);

}
