/*

CSES Problem Set

Minimizing Coins

link to the problem:
https://cses.fi/problemset/task/1634/

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

ll n, x;

ll calc(ll x, vector<ll> &c, vector<ll> &dp)
{
	if (x == 0) return (0);

	if (dp[x] != -2)
		return (dp[x]);

	dp[x] = -1;

	for (ll i = 0; i < n; i++)
	{
		if (x - c[i] < 0) continue;

		if (calc(x - c[i], c, dp) == -1) continue;

		if (dp[x] != -1)
		{
			dp[x] = min(dp[x], 1 + calc(x - c[i], c, dp));
		}
		else
		{
			dp[x] = 1 + calc(x - c[i], c, dp);
		}
	}
	return (dp[x]);
}

void solve()
{
	cin >> n >> x;

	vector<ll> dp(x+1, -2);

	vector<ll> c(n);
	for (auto &i : c)
			cin >> i;

	cout << calc(x, c, dp) << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
