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

	for (int a = 1; a <= 1000; a++) {
		for (int b = 1; b <= 1000-a-1; b++) {
			int c = 1000 - a - b;
			if (a*a + b*b == c*c) {
				printf("%d\n", a*b*c);
				return 0;
			}
		}
	}
}
