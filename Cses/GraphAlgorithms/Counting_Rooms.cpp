/*
link to the problem:
https://cses.fi/problemset/task/1192/
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

ll n, m;

ll dr[] = {1, -1, 0, 0};
ll dc[] = {0, 0, -1, 1};

void dfs(vector<string> &g, ll i, ll j)
{
	if (i < 0 || j < 0 || i >= n || j >= m) return ;
	if (g[i][j] == '#') return ;

	g[i][j] = '#';

	for (ll d = 0; d < 4; d++) dfs(g, i + dr[d], j + dc[d]);
}

void solve()
{
	cin >> n >> m;
	vector<string> g(n);
	for (string &l : g) cin >> l;
	//
	ll ans = 0;
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			if (g[i][j] != '#') dfs(g, i, j), ans += 1;
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
