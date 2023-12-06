/*

CSES Problem Set

Coin Combinations I

link to the problem:
https://cses.fi/problemset/task/1635/

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
	int mod = 1000000007;

	int n, x; cin >> n >> x;

	int c[1000001];
	for (int i = 0; i < n; i++)
		cin >> c[i];

	sort(c, c + n);

	int dp[1000001];

	dp[0] = 1;

	for (int i = 1; i <= x; i++)
	{
		dp[i] = 0;
		for (int j = 0; j < n; j++)
		{
			if (i < c[j]) break;
			dp[i] = (dp[i] + dp[i - c[j]])%mod;
		}
	}

	cout << dp[x] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	solve();
}
