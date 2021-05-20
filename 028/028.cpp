/*
669171001
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

	const int N = 1001;

	ll sum = 1;
	ll num = 1;
	for (ll i = 1; i <= N / 2; i++) {
		for (ll j = 0; j < 4; j++) {
			num += i*2;
			sum += num;
		}
	}
	printf("%lld\n", sum);
}
