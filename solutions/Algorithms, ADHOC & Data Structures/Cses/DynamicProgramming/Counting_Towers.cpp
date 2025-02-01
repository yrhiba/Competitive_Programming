/*
CSES Problem Set

Counting Towers

link to the problem:
https://cses.fi/problemset/task/2413/
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

int mod = int(1e9 + 7);

void solve()
{
	int n = int(1e6 + 1);

	vector<vector<int>> g = {
		{0, 2, 7},
		{1, 3, 4, 5, 6},
		{0, 2, 7},
		{1, 3, 4, 5, 6},
		{1, 3, 4, 5, 6},
		{1, 3, 4, 5, 6},
		{0, 2, 7},
		{1, 3, 4, 5, 6},
	};

	vector<vector<int>> dp(n, vector<int>(8));

	vector<int> ans(n);

	dp[0] = vector<int>(8, 1);
	ans[0] = 8;

	for (int i = 1; i < n; i++)
	{
		ans[i] = 0;
		for (int state = 0; state < 8; state++)
		{
			dp[i][state] = 0;
			//
			for (int validPreviousState : g[state])
			{
				dp[i][state] += dp[i-1][validPreviousState];
				dp[i][state] %= mod;
			}

			ans[i] += dp[i][state];
			ans[i] %= mod;
		}
	}

	int q; cin >> q;

	while (q--)
	{
		int i; cin >> i;
		//
		if (i == 1)
		{
			cout << 2 << "\n";
		}
		else
		{
			cout << ans[i-2] << "\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

/*

Recursion function dp;

	int rec(
	vector<vector<int>> &g,
	vector<vector<int>> &dp, 
	int i,
	int state
	)
	{
		if (i == 0) return (1);

		if (dp[i][state] != -1) return dp[i][state];

		dp[i][state] = 0;

		for (int nextState : g[state])
		{
			dp[i][state] += rec(g, dp, i-1, nextState);
			dp[i][state] %= mod;
		}

		return dp[i][state];
	}

*/