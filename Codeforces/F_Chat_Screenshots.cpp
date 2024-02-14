/*
F. Chat Screenshots

link to the problem:
https://codeforces.com/contest/1931/problem/F
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

void dfs(vector<ll> &topoSort, vector< set<ll> > &g, vector<bool> &vis, ll i)
{
	if (vis[i]) return ;
	vis[i] = true;
	for (ll x : g[i]) dfs(topoSort, g, vis, x);
	topoSort.push_back(i);
}

void solve()
{
	ll n, k; cin >> n >> k;
	vector< vector<ll> > a(k, vector<ll>(n));
	for (ll i = 0; i < k; i++)
		for (ll j = 0; j < n; j++) cin >> a[i][j];
	if (n <= 2 || k <= 1)
	{
		cout << "YES\n";
		return ;
	}
	vector< set<ll> > g(n+1);
	for (ll i = 0; i < k; i++)
		for (ll j = 1; j+1 < n; j++)
			g[a[i][j]].insert(a[i][j+1]);
	vector<ll> topoSort;
	vector<bool> vis(n+1, false);
	for (int i = 1; i <= n; i++) dfs(topoSort, g, vis, i);
	reverse(topoSort.begin(), topoSort.end());
	for (ll i = 0; i < k; i++)
		for (ll j = 1, x = 0; j < n; j++, x++)
		{
			if (topoSort[x] == a[i][0]) x++;
			if (topoSort[x] != a[i][j])
			{
				cout << "NO\n";
				return ;
			}
		}
	cout << "YES\n";
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--)	solve();
}
