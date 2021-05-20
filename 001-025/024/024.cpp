/* 2783915460
You can just simulate permutations, O(1000000 * 10)

However, we attempt a faster solution involving working out each digit of the rotation in turn.
This is O(D^2), for the number of digits
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

int fac[15] = {1};

void getperm(int D, vector<int> &v, int i) {
	if (D == (int)v.size()) return;
	// for (int i : v) printf("%d", i); printf("\n");

	int remaining = D - (int)v.size();
	i %= fac[remaining];
	int j = i / fac[remaining-1];
	bool used[D+5] = {0};
	for (int i : v) used[i] = true;
	for (int k = 0; k < D; k++) {
		if (used[k]) continue;
		if (j == 0) {
			v.push_back(k);
			break;
		}
		j--;
	}
	getperm(D, v, i % fac[remaining-1]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 1; i < 15; i++) fac[i] = fac[i-1]*i;

	vector<int> v;
	getperm(10, v, 1000000-1);
	for (int i : v) printf("%d", i); printf("\n");
}
