/*
link to the problem:
https://www.codechef.com/INOIPRAC/problems/INOI1402
status: time limit - solved but still need optimization.
maybe some DP technique!
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
ll powermod(ll x, ll p, ll m)
{
	if (p == 0) return (1);
	ll res = powermod(x, p/2, m) % m;
	if (p%2)
		return ((((res * res) % m) * (x % m)) % m);
	return ((res * res) % m);
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
	return ((a*b)/gcd(a,b));
}
ll inverse(ll x, ll m)
{
	return (powermod(x, m-2, m));
}

ll cost = 0;

void dfs(vector< vector<ll> > &g, vector<bool> &visited, ll i, ll j, ll from)
{
	if (i == j)
	{
		g[from][j] = (g[from][j] != -1) ? min(cost, g[from][j]) : cost;
		g[j][from] = (g[j][from] != -1) ? min(cost, g[j][from]) : cost;
		return ;
	}

	visited[i] = true;

	for (ll x = 1; x < g.size(); x++)
	{
		if (visited[x]) continue;
		if (g[i][x] == -1) continue;

		cost += g[i][x];
		dfs(g, visited, x, j, from);
		cost -= g[i][x];
	}

	visited[i] = false;
}

void solve()
{
	ll n, e; cin >> n >> e;

	vector< vector<ll> > g(n+1, vector<ll>(n+1, -1));

	for (ll i = 0; i < e; i++)
	{
		ll a, b, c; cin >> a >> b >> c;

		if (g[a][b] == -1)
			g[a][b] = c;
		else
			g[a][b] = min(g[a][b], c);

		if (g[b][a] == -1)
			g[b][a] = c;
		else
			g[b][a] = min(g[b][a], c);
	}

	vector<bool> visited(n+1, false);

	for (ll i = 1; i <= n; i++)
	{
		for (ll j = i + 1; j <= n; j++)
		{
			dfs(g, visited, i, j, i);
		}
	}

	ll ans = -1;

	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= n; j++)
		{
			ans = max(ans, g[i][j]);
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
