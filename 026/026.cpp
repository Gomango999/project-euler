/*983
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

#define MAXN 1005

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int seen[MAXN];

	int best = 0;
	int len = 0;

	for (int den = 2; den < 1000; den++) {
		fill(seen, seen+MAXN, -1);
		seen[1] = 0;

		int num = 1;
		// printf("1 / %2d: ", den);
		int i = 1;
		for (; i <= den+2; i++) {
			num *= 10;
			while (num < den) {
				// printf("%d ", 0);
				i++;
				num *= 10;
			}
			// printf("%d ", num / den);
			num = num % den;

			if (num == 0) {
				// printf("no cycle");
				break;
			} else if (seen[num] != -1) {
				int cycle_len = i - seen[num];
				// printf("cycle len: %d", cycle_len);
				if (cycle_len > len) {
					len = cycle_len;
					best = den;
				}
				break;
			}
			seen[num] = i;
		}
		// printf("\n");
	}

	printf("%d\n", best);
}
