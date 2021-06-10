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


int monthdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int getNumDays(int m, int y) {
	bool leap = ((y % 4 == 0) && !(y % 100 == 0)) || (y % 400 == 0);
	if (leap && m == 1) return monthdays[m]+1;
	else return monthdays[m];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int cnt = 0;
	int d = 0; // monday = 0
	for (int y = 1900; y <= 2000; y++) {
		for (int m = 0; m < 12; m++) {
			if (y >= 1901 && d == 6) cnt++;
			d = (d + getNumDays(m, y)) % 7;
		}
	}
	printf("%d\n", cnt);
}
