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

string oneword[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string teens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string tenword[10] = {"zeroey", "tenty", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string getword(int x) {
	if (x <= 9) return oneword[x];
	if (x <= 19) return teens[x-10];
	if (x < 100) {
		string s = tenword[(x/10)%10];
		x %= 10;
		if (!x) return s;
		s += " " + getword(x);
		return s;
	}
	if (x < 1000) {
		string s = oneword[(x / 100) % 10] + " hundred";
		x %= 100;
		if (!x) return s;
		s += " and";
		s += " " + getword(x);
		return s;
	}
	return "one thousand";
}

int countletters(int x) {
	string s = getword(x);
	int sum = 0;
	for (char c : s) sum += (c != ' ');
	return sum;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int sum = 0;
	for (int i = 1; i <= 1000; i++) {
		// cout << i << ": " << getword(i) << endl;
		sum += countletters(i);
	}
	printf("%d\n", sum);

}
