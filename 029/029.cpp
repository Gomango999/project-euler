/* Distinct Powers
- Store all prime factorisations
- For each number, check if its prime factorisation has been stored before
- N^4 log(N)
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
#define sz(x) int(x.size())

#define MOD 1000000007

const int MINA = 2;
const int MAXA = 100;
const int MINB = 2;
const int MAXB = 100;

int gcd(int a, int b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

int prime[200];
vector<int> primes;
void sieve(int N) {
	fill(prime, prime+N, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= N; i++) {
		if (prime[i]) {
			primes.pb(i);
			for (int j = i*i; j <= N; j+=i) {
				prime[j] = false;
			}
		}
	}
}

vector<pii> primefactorise(int N) {
	vector<pii> pfs;
	for (int p : primes) {
		int k = 0;
		while (N % p == 0) k++, N /= p;
		if (k) pfs.push_back({p, k});
	}
	if (N > 1) pfs.push_back({N, 1});
	return pfs;
}

void pfspower(vector<pii> &pfs, int e) {
	for (pii &p : pfs) p.y *= e;
}

bool comp(vector<pii> &pfs1, vector<pii> &pfs2) {
	if (pfs1.size() != pfs2.size()) return false;
	for (int i = 0; i < sz(pfs1); i++) {
		if (pfs1[i] != pfs2[i]) return false;
	}
	return true;
}

void print(vector<pii> &pfs) {
	for(int i = 0; i < sz(pfs); i++) {
		printf("%d^%d ", pfs[i].x, pfs[i].y);
		if (i < sz(pfs)-1) printf("* ");
	}
	printf("\n");
}

vector<pii> pfs[MAXA+5][MAXB+5];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	sieve(MAXA);
	for (int a = MINA; a <= MAXA; a++) {
		for (int b = MINB; b <= MAXB; b++) {
			pfs[a][b] = primefactorise(a);
			pfspower(pfs[a][b], b);
			// printf("a:%2d b:%2d ", a, b); print(pfs[a][b]);
		}
	}

	int sum = 0;
	for (int a = MINA; a <= MAXA; a++) {
		for (int b = MINB; b <= MAXB; b++) {
			// printf("a:%d b:%d\n", a, b);
			int unique = true;
			for (int i = MINA; i <= a && unique; i++) {
				for (int j = MINB; j <= (i==a?b:MAXB) && unique; j++) {
					if (i == a && j == b) continue;
					if (comp(pfs[a][b], pfs[i][j])) {
						// printf("  same as i:%d j:%d\n", i, j);
						unique = false;
					}
				}
			}
			sum += unique;
		}
	}
	printf("%d\n", sum);
}
