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

int N = 15;

bool valid(int y, int x) {
	if (y < 0 || y >= N) return false;
	if (x < 0 || x >= N) return false;
	if (x > y) return false;
	return true;
}

int dy[2] = {-1, -1};
int dx[2] = {0, -1};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int dp[20][20];
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < y+1; x++) {
			cin >> dp[y][x];
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < y+1; x++) {
			int best = 0;
			for (int i = 0; i < 2; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (!valid(ny, nx)) continue;
				best = max(best, dp[ny][nx]);
			}
			dp[y][x] += best;
		}
	}

	int best = 0;
	for (int x = 0; x < N; x++) {
		best = max(best, dp[N-1][x]);
	}
	printf("%d\n", best);
}
