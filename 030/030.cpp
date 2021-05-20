/*
- Max sum you can get for a digit is 59049
- Hence, number of digits * 59049 > N

- We have 6 * 59049 = 354294 which is larger than some 6 digit numbers
- We have 7 * 59049 = 413343 which is smaller than all 7 digit numbers
- In general, for any number of digits >= 7, it's impossible for it to be written as the sum of 5th powers of digits
- Hence, we can just test all numbers less than 354294
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

int power[11];

void print(vector<int> &v) {
	for (int i : v) printf("%d ", i); printf("\n");
}

bool ok(int N) {
	vector<int> v;
	int M = N;
	while (M) v.pb(M % 10), M /= 10;
	int sum = 0;
	for (int i : v) sum += power[i];
	return N == sum;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for (int i = 0; i <= 10; i++) power[i] = i*i*i*i*i;

	int sum = 0;
	for (int i = 2; i < 354294; i++) {
		if (ok(i)) {
			sum += i;
			printf("%d\n", i);
		}
	}
	printf("%d\n", sum);
}
