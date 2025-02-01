/*
CSES Problem Set

Edit Distance

link to the problem:
https://cses.fi/problemset/task/1639/
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
# define ull unsigned long long
# define ll long long
ll mod = 1e9 + 7;
using namespace std;

int rec(vector<vector<int>> &dp, string &s, string &t, int i, int j)
{
	if (i == -1 || j == -1) return (max(i, j) + 1);

	if (dp[i][j] != -1) return dp[i][j];

	dp[i][j] = min(
		{
			1 + rec(dp, s, t, i - 1, j),
			1 + rec(dp, s, t, i, j - 1),
			(s[i] != t[j]) + rec(dp, s, t, i - 1, j - 1)
		}
	);

	return (dp[i][j]);
}

void solve()
{
	vector<vector<int>> dp(5e3+1, vector<int>(5e3+1, -1));
	//
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();
	//
	cout << rec(dp, s, t, n-1, m-1) << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
