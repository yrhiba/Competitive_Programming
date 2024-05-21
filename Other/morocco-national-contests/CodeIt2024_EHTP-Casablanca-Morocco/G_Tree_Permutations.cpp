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

ll fact[100001];

ll powermod(ll x, ll p, ll m = mod)
{
	if (p == 0) return (1);
	ll res = powermod(x, p/2, m) % m;
	if (p%2)
		return ((((res * res) % m) * (x % m)) % m);
	return ((res * res) % m);
}

ll inverse(ll x, ll m = mod)
{
	return (powermod(x, m-2, m));
}

void setup()
{
	/*factorial precalculation*/
	fact[0] = 1;
	fact[1] = 1;
	for (ll i = 2; i <= 1e5; i++)
	{
		fact[i] = (i * fact[i-1]);
		fact[i] %= mod;
	}
}

ll calcDelta(vector<vector<ll>> &g, vector<ll> &delta, vector<ll> &childCount, ll root)
{
	delta[root] = 1;

	for (ll child : g[root])
		if (delta[child] == -1)
		{
			childCount[root] += 1;
			delta[root] *= calcDelta(g, delta, childCount, child);
			delta[root] %= mod;
		}

	delta[root] *= fact[childCount[root]];
	delta[root] %= mod;

	return delta[root];
}

void calcGlobalDelta
	(
		vector<vector<ll>> &g,
		vector<ll> &delta,
		vector<ll> &globalDelta,
		vector<ll> &childCount,
		ll root,
		ll parent)
{
	ll prvTreeValue = globalDelta[parent]
		* inverse((g[parent].size() * delta[root]) % mod);

	globalDelta[root] = prvTreeValue % mod;

	for (ll child : g[root])
		if (globalDelta[child] == -1)
		{
			globalDelta[root] *= delta[child];
			globalDelta[root] %= mod;
		}

	globalDelta[root] *= fact[g[root].size()];
	globalDelta[root] %= mod;

	// calc nexts
	for (ll child : g[root])
		if (globalDelta[child] == -1)
		{
			calcGlobalDelta(g, delta, globalDelta, childCount, child, root);
		}
}

void solve()
{
	ll n; cin >> n;
	vector<vector<ll>> g(n);
	for (ll i = 1; i < n; i++)
	{
		ll u, v; cin >> u >> v;
		u -= 1, v -= 1;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	//
	vector<ll> delta(n, -1);
	vector<ll> childCount(n, 0);
	calcDelta(g, delta, childCount, 0);
	//
	vector<ll> globalDelta(n, -1);
	globalDelta[0] = delta[0];
	for (ll child : g[0])
		calcGlobalDelta(g, delta, globalDelta, childCount, child, 0);
	//
	ll ans = 0;
	for (ll d : globalDelta)
	{
		ans += d;
		ans %= mod;
	}
	ans *= inverse(n);
	cout << (ans % mod) << "\n";
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	setup();
	solve();
}
