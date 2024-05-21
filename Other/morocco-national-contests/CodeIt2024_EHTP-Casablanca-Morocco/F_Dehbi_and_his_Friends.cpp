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

void solve()
{
	ll n, m; cin >> n >> m;
	vector<set<pair<ll, ll>>> g(n);
	for (ll i = 0; i < m; i++)
	{
		ll u, v, w; cin >> u >> v >> w;
		u -= 1, v -= 1;
		g[u].insert({w, v});
		g[v].insert({w, u});
	}
	ll x; cin >> x;
	vector<ll> friends(x);
	for (ll i = 0; i < x; i++)
	{
		cin >> friends[i];
		friends[i] -= 1;
	}
	//
	ll dehbiPosition; cin >> dehbiPosition; dehbiPosition -= 1;
	//
	vector<ll> reached(n, 1e18);
	//
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pr;
	reached[dehbiPosition] = 0;
	pr.push({reached[dehbiPosition], dehbiPosition});
	//
	while (!pr.empty())
	{
		pair<ll, ll> cur = pr.top();
		pr.pop();

		if (reached[cur.second] < cur.first) continue;

		for (auto &[cost, node] : g[cur.second])
			if ((cost + cur.first) < reached[node])
			{
				reached[node] = (cost + cur.first);
				pr.push({reached[node], node});
			}
	}

	ll ans = -1;

	for (ll f : friends)
		if ((reached[f] != 1e18) && (ans == -1 || ans > reached[f]))
		{
			ans = reached[f];
		}

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
