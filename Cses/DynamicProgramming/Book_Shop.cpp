/*
CSES Problem Set

Book Shop

link to the problem:
https://cses.fi/problemset/task/1158/
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

void solve()
{
	int n, x; cin >> n >> x;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first;
	for (int i = 0; i < n; i++) cin >> a[i].second;
	//
	vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
	//
	for (int i = n-1; i >= 0; i--)
		for (int j = 0; j <= x; j++)
		{
			dp[i][j] = dp[i+1][j];

			if (a[i].first <= j)
				dp[i][j] = max(dp[i][j], a[i].second + dp[i+1][j - a[i].first]);
		}
	//
	cout << dp[0][x] << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
