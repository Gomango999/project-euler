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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	const int N = 100;
	vector<int> a[N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 50; j++) {
			char c; scanf(" %c ", &c);
			a[i].push_back(c-'0');
		}
		reverse(all(a[i]));
	}
	vector<int> ans;
	int carry = 0;
	for (int i = 0; i < 50 || carry; i++) {
		int sum = 0;
		if (i < 50) for (int j = 0; j < 100; j++) sum += a[j][i];
		sum += carry % 10;
		carry /= 10;
		ans.push_back(sum % 10);
		carry += sum / 10;
	}
	reverse(all(ans));
	// for (int i : ans) printf("%d", i); printf("\n");
	for (int i = 0; i < 10; i++) printf("%d", ans[i]); printf("\n");
}
