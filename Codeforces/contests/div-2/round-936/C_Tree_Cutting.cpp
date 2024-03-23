/*
link to the problem:
https://codeforces.com/contest/1946/problem/C
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
#include <numeric>
# define ull unsigned long long
# define ll long long
const ll mod = 1e9 + 7;
using namespace std;

ll dfs(vector<vector<ll>> &g, vector<bool> &vis, ll &x, ll &k, ll i)
{
	if (k == 0) return (0);
	vis[i] = true;
	ll cur = 1;
	for (ll j : g[i])
	{
		if (vis[j]) continue;
		cur += dfs(g, vis, x, k, j);
	}
	vis[i] = false;
	if (k && cur >= x)
	{
		k -= 1;
		return (0);
	}
	return cur;
}

bool good(vector<vector<ll>> &g, vector<bool> &vis, ll x, ll k)
{
	k++;
	dfs(g, vis, x, k, 0);
	if (k) return false;
	return true;
}

void solve()
{
	ll n, k; cin >> n >> k;
	vector< vector<ll> > g(n);
	for (ll i = 0; i+1 < n; i++)
	{
		ll u, v; cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	//
	vector<bool> vis(n, false);
	//
	ll left = 1, right = n, mid, ans = 1;
	//
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		//
		if (good(g, vis, mid, k))
		{
			ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	//
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--)
		solve();
}
