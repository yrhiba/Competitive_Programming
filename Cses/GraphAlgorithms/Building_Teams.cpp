/*
link to the problem:
https://cses.fi/problemset/task/1668/
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

ll dfs(vector< vector<ll> > &g, vector<bool> &color, vector<bool> &vis, ll pupil, bool team_color)
{
	//
	vis[pupil] = true;
	color[pupil] = team_color;
	//
	for (ll next_pupil : g[pupil])
	{
		if (vis[next_pupil])
		{
			if (color[pupil] == color[next_pupil]) return (-1);
			continue;
		}
		//
		if (dfs(g, color, vis, next_pupil, !team_color) == -1) return (-1);
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
		ll a, b; cin >> a >> b;
		a -= 1, b -= 1;
		//
		g[a].push_back(b);
		g[b].push_back(a);
	}
	//
	vector<bool> color(n);
	vector<bool> vis(n, false);
	for (ll i = 0; i < n; i++)
	{
		if (vis[i]) continue;
		if (dfs(g, color, vis, i, false) == -1)
		{
			cout << "IMPOSSIBLE\n";
			return ;
		}
	}
	//
	for (ll i = 0; i < n; i++) cout << color[i] + 1 << " \n"[i+1 == n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
