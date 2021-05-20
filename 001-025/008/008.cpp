/*
23514624000
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

ll best = 1;
vector<int> v;

void solve() {
	if ((int)v.size() < 13) return;
	ll prod = 1;
	for (int i = 0; i < (int)v.size(); i++) {
		prod *= v[i];
		if (i >= 13) prod /= v[i-13];
		if (i >= 12) best = max(best, prod);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 0; i < 1000; i++) {
		char c;
		scanf(" %c ", &c);
		int a = c - '0';
		if (a != 0) v.push_back(a);
		else {
			// find the best 13 digit number in the current sequence.
			solve();
			v.clear();
		}
	}

	printf("%lld\n", best);
}
