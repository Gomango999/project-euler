/*
25164150
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

	ll sum1 = 0;
	ll sum2 = 0;
	for (ll i = 1; i <= 100; i++) {
		sum1 += i*i;
		sum2 += i;
	}
	sum2 = sum2 * sum2;
	printf("%lld\n", sum2 - sum1);
}
