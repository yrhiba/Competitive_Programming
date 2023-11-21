/*

Codeforces Round 222 (Div. 1)

A. Maze

link to the problem:
https://codeforces.com/contest/377/problem/A

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
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}
ll gcd(ll a, ll b)
{
	if (b == 0) return (a);
	return (gcd(b, a%b));
}
ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a, b));
}

bool compare_connecteds_compents(const vector< pair<ll, ll> > &a, const vector< pair<ll, ll> > &b)
{
	return (a.size() < b.size());
}

void solve()
{
	ll n, m, k; cin >> n >> m >> k;

	vector< string > g(n);

	ll empty_cell_count = 0;

	for (auto &line : g)
	{
		cin >> line;

		empty_cell_count += count(line.begin(), line.end(), '.');
	}

	vector< vector<bool> > vis(n, vector<bool>(m, false));

	vector< vector< pair<ll, ll> > > connecteds_areas;

	ll di[] = {0, 0, 1, -1};
	ll dj[] = {1, -1, 0, 0};

	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
		{
			if (g[i][j] == '#')	continue;
			if (vis[i][j])		continue;

			vector< pair<ll, ll> > connected_area;

			queue<ll> qi;	qi.push(i);
			queue<ll> qj;	qj.push(j);

			vis[i][j] = true;

			while (!qi.empty() && !qj.empty())
			{
				ll &cur_i = qi.front();
				ll &cur_j = qj.front();

				connected_area.push_back({cur_i, cur_j});

				for (ll d = 0; d < 4; d++)
				{
					ll ni = cur_i + di[d];
					ll nj = cur_j + dj[d];

					if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
					if (g[ni][nj] != '.') continue;
					if (vis[ni][nj]) continue;

					qi.push(ni);
					qj.push(nj);

					vis[ni][nj] = true;
				}

				qi.pop();
				qj.pop();
			}

			connecteds_areas.push_back(connected_area);
		}

	sort(connecteds_areas.rbegin(), connecteds_areas.rend(), compare_connecteds_compents);

	vector< pair<ll, ll> > nodes;
	for (auto &cons : connecteds_areas)
		for (auto con : cons)
			nodes.push_back(con);

	ll fixed_nodes = empty_cell_count - k;

	for (ll i = fixed_nodes; i < nodes.size(); i++)
		g[nodes[i].first][nodes[i].second] = 'X';

	for (auto &line : g)
		cout << line << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
