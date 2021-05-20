/* 4179870
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

#define MAXN 28123

int divsum(int x) {
	int sum = 0;
	for (int i = 1; i*i <= x; i++) {
		if (x % i == 0) sum += i + x/i;
		if (i == 1) sum -= x;
		if (i*i == x) sum -= i;
	}
	return sum;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	bool abundant[MAXN+5] = {0};
	for (int i = 1; i <= MAXN; i++) {
		abundant[i] = (divsum(i) > i);
	}
	// for (int i = 0; i < 100; i++) printf("%d: %d\n", i, abundant[i]);

	ll sum = 0;
	for (int i = 1; i <= MAXN; i++) {
		bool good = false;
		for (int j = 1; j < i; j++) {
			if (abundant[j] && abundant[i-j]) good = true;
		}
		if (!good) sum += i;
	}
	printf("%lld\n", sum);
}
