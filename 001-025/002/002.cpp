/*
4613732
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
    int sum = 0;
    int a = 1, b = 1, c = 0;
    for (int i = 0; true; i++) {
        c = a+b;
        if (c % 2 == 0) sum += c;
        if (c > 4000000) break;
        a = b;
        b = c;
    }
    printf("%d\n", sum);
}
