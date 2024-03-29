/*
link to the problem:
https://codeforces.com/contest/1829/problem/E
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

ll dr[] = {1, -1, 0, 0};
ll dc[] = {0, 0, 1, -1};

ll n, m;

ll dfs(vector<vector<ll>> &g, ll i, ll j)
{
	if (i < 0 || j < 0 || i >= n || j >= m) return (0);
	if (g[i][j] == 0) return (0);
	//
	ll cur = g[i][j];
	//
	g[i][j] = 0;
	//
	for (ll d = 0; d < 4; d++) cur += dfs(g, i+dr[d], j+dc[d]);
	//
	return (cur);
}

void solve()
{
	cin >> n >> m;
	vector<vector<ll>> g(n, vector<ll>(m));
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++) cin >> g[i][j];
	//
	ll ans = 0;
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			if (g[i][j]) ans = max(ans, dfs(g, i, j));
	//
	cout << ans << '\n';
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
