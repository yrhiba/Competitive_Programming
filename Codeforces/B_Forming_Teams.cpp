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
# define ull unsigned long long
# define ll long long
ll mod = 1000000007;
using namespace std;
ll powermod(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = powermod(x, p/2) % mod;
	if (p%2)
		return ((((res * res) % mod) * (x % mod)) % mod);
	return ((res * res) % mod);
}
ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}

ll res;

# define T1 1
# define T2 2
# define NT 3

void bfs(vector< vector<ll> > &g, vector<ll> &color, ll f)
{
	color[f] = T1;

	deque<ll> qp;

	qp.push_back(f);

	while (qp.size() > 0)
	{
		ll to_color;

		if (color[qp.front()] == NT)
		{
			qp.pop_front();
			continue;
		}

		if (color[qp.front()] == T1)
			to_color = T2;
		else
			to_color = T1;

		for (ll i = 0; i < g[qp.front()].size(); i++)
		{
			if (color[g[qp.front()][i]] == to_color || color[g[qp.front()][i]] == NT)
				continue;

			if (color[g[qp.front()][i]] == 0)
			{
				color[g[qp.front()][i]] = to_color;
				qp.push_back(g[qp.front()][i]);
			}
			else if (color[g[qp.front()][i]] == color[qp.front()])
			{
				color[g[qp.front()][i]] = NT;
				res += 1;
			}
		}
		qp.pop_front();

	}
}

void solve()
{
	ll n, m; cin >> n >> m;

	vector< vector<ll> > g(n);
	vector<ll> color(n, 0);

	for (ll i = 0; i < m; i++)
	{
		ll a, b; cin >> a >> b;
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);
	}

	res = 0;

	for (ll i = 0; i < n; i++)
	{
		if (color[i] != 0) continue;
		bfs(g, color, i);
	}

	cout << res + ((n - res) % 2) << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
