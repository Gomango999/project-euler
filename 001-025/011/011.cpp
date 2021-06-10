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

const int N = 20;

int dy[8] = {1,1,1,0,-1,-1,-1,0};
int dx[8] = {-1,0,1,1,1,0,-1,-1};

bool inside(int y, int x) {
	if (y < 0 || y >= N) return false;
	if (x < 0 || x >= N) return false;
	return true;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);


	int a[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}

	int best = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			for (int i = 0; i < 8; i++){
				int ny = y;
				int nx = x;
				int prod = 1;
				bool good = true;
				for (int j = 0; j < 4; j++) {
					if (!inside(ny, nx)) good = false;
					prod *= a[ny][nx];
					ny += dy[i];
					nx += dx[i];
				}
				if (good) best = max(best, prod);
				// if (prod == 96059601) printf("%d %d %d\n", y, x, i);
			}
		}
	}
	printf("%d\n", best);
}
