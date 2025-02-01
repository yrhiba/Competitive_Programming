/*
CSES Problem Set

Coin Combinations II

link to the problem:
https://cses.fi/problemset/task/1636
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <fstream>
using namespace std;
# define MOD 1000000007
 
int main()
{
	int n, x; cin >> n >> x;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<vector<int>> dp(n+1, vector<int>(x+1));

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}

	for (int i = n-1; i >= 0; i--) {
		for (int j = 1; j <= x; j++) {
			int skipping = dp[i+1][j];
			int picking = 0;
			if (a[i] <= j) {
				picking = dp[i][j - a[i]];
			}
			dp[i][j] = (picking + skipping) % MOD;
		}
	}

	cout << dp[0][x] << '\n';
}
