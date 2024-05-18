/*
CSES Problem Set

Rectangle Cutting

link to the problem:
https://cses.fi/problemset/task/1744/
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


int rec(vector<vector<int>> &dp, int a, int b)
{
	if (a == b) return (0);
	//
	if (dp[a][b] != -1) return dp[a][b];
	if (dp[b][a] != -1) return dp[b][a];
	//
	dp[a][b] = 1e18;

	for (int i = 1; i < b; i++) dp[a][b] = min(dp[a][b], 1 + rec(dp, a, i) + rec(dp, a, b - i));

	for (int i = 1; i < a; i++) dp[a][b] = min(dp[a][b], 1 + rec(dp, i, b) + rec(dp, a - i, b));

	return dp[a][b];
}

void solve()
{
	vector<vector<int>> dp(501, vector<int>(501, -1));
	//
	int a, b; cin >> a >> b;
	//
	cout << rec(dp, a, b) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
