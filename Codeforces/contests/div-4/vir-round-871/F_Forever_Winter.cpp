/*
link to the problem:
https://codeforces.com/contest/1829/problem/F
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

ll rec(
	vector<vector<ll>> &g,
	vector<bool> &vis,
	vector<ll> &count,
	ll i,
	ll h
)
{
	if (h >= 3) return (-1);
	//
	count[h] += 1;
	//
	vis[i] = true;
	//
	for (ll j : g[i])
	{
		if (vis[j]) continue;
		//
		if (rec(g, vis, count, j, h + 1) == -1) return (-1);
	}
	//
	return (0);
}

void solve()
{
	ll n, m; cin >> n >> m;
	vector< vector<ll> > g(n);
	for (ll i = 0; i < m; i++)
	{
		ll u, v; cin >> u >> v;
		u -= 1, v -= 1;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	//
	for (ll i = 0; i < n; i++)
	{
		vector<ll> count(3, 0);
		vector<bool> vis(n, false);
		// count in each height how many nodes
		if (rec(g, vis, count, i, 0) == -1) continue;
		//
		cout << count[1] << " " << (count[2] / count[1]) << "\n";
		return ;
	}
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
