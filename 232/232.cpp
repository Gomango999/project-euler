/*
observation: You would never bet more than 8, since you would instantly win at this point.

For each value of T, there are 4 cases.
1. W W
2. W L
3. L W
4. L L

THIS CODE WORKS
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define x first
#define y second
#define pb push_back
#define all(x) x.begin(), x.end()

#define MAXN (105+128)

const int GOAL = 100;

bool done[MAXN][MAXN];
ld memo[MAXN][MAXN];

// dp(a, b) = prob. that p2 wins if p1 has a points, p2 has b points, and it is p2's turn.
ld dp(int a, int b) {
    if (b >= GOAL) return 1.0; // even if player 1 gets 100, player 2 got it first.
    if (a >= GOAL) return 0.0;
    if (done[a][b]) return memo[a][b];
    done[a][b] = true;

    ld best = 0.0;

    for (int T = 1; T <= 8; T++) {
        // probabilities of each player winning
        ld win1  = 0.5;
        ld win2  = 1.0/(1<<T);
        ld lose1 = 1.0 - win1;
        ld lose2 = 1.0 - win2;

        // probabilities of each case occuring
        ld prob1 = win1  * win2;
        ld prob2 = win1  * lose2;
        ld prob3 = lose1 * win2;
        ld prob4 = lose1 * lose2;

        // probabilities of each case multiplied by probability of winning if it occurs
        ld case1 = prob1 * dp(a+1, b+(1<<(T-1)));
        ld case2 = prob2 * dp(a+1, b);
        ld case3 = prob3 * dp(a  , b+(1<<(T-1)));

        // probability of winning if choosing this T.
        ld probT = (case1 + case2 + case3) / (1.0 - prob4);

        best = max(best, probT);
    }

    return memo[a][b] = best;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

    printf("%.8Lf\n", (dp(0,0) + dp(1,0))/2);
}
