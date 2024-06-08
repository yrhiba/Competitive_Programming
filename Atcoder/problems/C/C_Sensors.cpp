/*
KEYENCE Programming Contest 2023 Autumn（AtCoder Beginner Contest 325）

link to the problem:
https://atcoder.jp/contests/abc325/tasks/abc325_c
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

ll dr[] = {1, -1, 0, 0, 1, -1, 1, -1};
ll dc[] = {0, 0, -1, 1, -1, 1, 1, -1};
ll n, m;


void dfs(vector<string> &g, vector< vector<bool> > &visited, ll i, ll j)
{
	if (i < 0 || i >= n || j < 0 || j >= m) return ;
	if (g[i][j] != '#' || visited[i][j]) return ;

	visited[i][j] = true;

	for (ll k = 0; k < 8; k++)
		dfs(g, visited, i+dr[k], j+dc[k]);
}

void solve()
{
	cin >> n >> m;

	vector<string> g(n);
	for (ll i = 0; i < n; i++)
		cin >> g[i];

	vector< vector<bool> > visited(n, vector<bool>(m, false));

	ll ans = 0;

	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++)
		{
			if (g[i][j] != '#' || visited[i][j]) continue;
			ans += 1;
			dfs(g, visited, i, j);
		}
	}

	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
