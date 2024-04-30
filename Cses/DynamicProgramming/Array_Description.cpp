/*
CSES Problem Set

Array Description

link to the problem:
https://cses.fi/problemset/task/1746/
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

void solve()
{
	ll n, m; cin >> n >> m;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	//
	vector<vector<ll>> dp(n+1, vector<ll>(m+2, 0));
	//
	for (ll i = 0; i < n; i++)
		for (ll j = 1; j <= m; j++)
		{
			if (!i) dp[i][j] = ((a[i] && a[i] == j) || !a[i]);
			//
			if ((a[i] && a[i] == j) || !a[i])
			{
				dp[i+1][j-1] += dp[i][j];
				dp[i+1][j-1] %= mod;
				//
				dp[i+1][j] += dp[i][j];
				dp[i+1][j] %= mod;
				//
				dp[i+1][j+1] += dp[i][j];
				dp[i+1][j+1] %= mod;
			}
		}
	//
	ll ans = 0;
	for (ll i = 1; i <= m; i++)
		if ((a.back() && a.back() == i) || !a.back())
		{
			ans += dp[n-1][i];
			ans %= mod;
		}
	//
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

/*
Recursion solution:

	ll dfs(vector<vector<ll>> &dp, vector<ll> &a, const ll &m, ll i, ll j)
	{
		if (i >= a.size()) return (1);
		if (dp[i][j] != -1) return dp[i][j];
		//
		if (a[i] != 0)
		{
			if (i && abs(a[i] - a[i-1]) > 1) return dp[i][j] = 0;
			dp[i][j] = dfs(dp, a, m, i+1, a[i]);
		}
		else
		{
			dp[i][j] = 0;
			if (!i)
			{
				for (ll ai = 1; ai <= m; ai++)
				{
					a[i] = ai;
					if (i && (abs(a[i] - a[i-1]) > 1)) continue;
					dp[i][j] += dfs(dp, a, m, i+1, ai);
					dp[i][j] %= mod;
				}
			}
			else
			{
				for (ll ai = max(1ll, a[i-1]-1); ai <= min(m, a[i-1]+1); ai++)
				{
					a[i] = ai;
					dp[i][j] += dfs(dp, a, m, i+1, ai);
					dp[i][j] %= mod;
				}
			}
			a[i] = 0;
		}
		//
		return dp[i][j];
	}
*/
