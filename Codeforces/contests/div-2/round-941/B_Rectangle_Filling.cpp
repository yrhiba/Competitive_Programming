/*
B. Rectangle Filling

link to the problem:
https://codeforces.com/contest/1966/problem/B
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

bool ok(vector<vector<pair<bool, bool>>> &a, pair<ll, ll> x, pair<ll, ll> y)
{
	if (a[x.first][x.second].first && a[x.first][x.second].first == a[y.first][y.second].first)
		return true;

	if (a[x.first][x.second].second && a[x.first][x.second].second == a[y.first][y.second].second)
		return true;

	return false;
}

void solve()
{
	ll n, m; cin >> n >> m;
	//
	vector<vector<pair<bool, bool>>> a(n, vector<pair<bool, bool>>(m, {false, false}));
	vector<string> g(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> g[i];
		for (ll j = 0; j < m; j++)
		{
			if (g[i][j] == 'W') a[i][j].first = true;
			else a[i][j].second = true;
		}
	}
	//
	vector<pair<ll, ll>> d = {{0, 0}, {0, m-1}, {n-1, m-1}, {n-1, 0}};
	//
	for (auto [i, j] : d)
	{
		if (g[i][j] == 'W')
		{
			bool fr = false, fc = false;
			for (ll r = 0; r < n; r++) fr |= g[r][j] == 'B';
			for (ll c = 0; c < m; c++) fc |= g[i][c] == 'B';
			if (fr && fc) a[i][j].second = true;
		}
		else
		{
			bool fr = false, fc = false;
			for (ll r = 0; r < n; r++) fr |= g[r][j] == 'W';
			for (ll c = 0; c < m; c++) fc |= g[i][c] == 'W';
			if (fr && fc) a[i][j].first = true;
		}
	}

	if (ok(a, d[0], d[2]) || ok(a, d[1], d[3]))
		cout << "YES\n";
	else
		cout << "NO\n";
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
