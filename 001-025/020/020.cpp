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

#define MAXN 1005

void print(int a[MAXN]) {
	int j = MAXN;
	while (a[j-1] == 0) j--;
	for (int i = j-1; i >= 0; i--) printf("%d", a[i]);
	printf("\n");
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N = 100;

	int a[MAXN] = {1};
	int b[MAXN] = {0};
	for (int n = 1; n <= N; n++) {
		fill(b, b+MAXN, 0);
		for (int i = 0; i < MAXN; i++) {
			int res = a[i] * n;
			for (int j = 0; res && i+j < MAXN; j++, res /= 10) {
				b[i+j] += res % 10;
				if (b[i+j] >= 10) {
					b[i+j] -= 10;
					res += 10;
				}
			}
		}
		for (int i = 0; i < MAXN; i++) a[i] = b[i];
		// print(a); //print factorials
	}
	int sum = 0;
	for (int i = 0; i < MAXN; i++) sum += a[i];
	printf("%d\n", sum);
}
