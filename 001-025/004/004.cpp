/*
906609
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

bool ispalindrome(int n) {
	vector<int> v;
	while (n) {
		v.push_back(n%10);
		n /= 10;
	}
	for (int i = 0; i < (int)v.size()/2; i++) {
		if (v[i] != v[int(v.size())-1-i]) return false;
	}
	return true;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int best = 0;
	for (int i = 1; i < 1000; i++) {
		for (int j = 1; j < 1000; j++) {
			if (ispalindrome(i*j)) {
				best = max(best, i*j);
			}
		}
	}
	printf("%d\n", best);

}
