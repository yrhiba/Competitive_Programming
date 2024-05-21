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

bool dfs(vector<set<ll>>&g, vector<bool> &vis, const ll &target, ll cur)
{
	if (cur == target) return (true);
	if (vis[cur]) return (false);

	vis[cur] = true;

	for (ll nxt : g[cur])
		if (dfs(g, vis, target, nxt)) return (true);

	return false;
}

void solve()
{
	ll n, m, q; cin >> n >> m >> q;
	vector<set<ll>> g(n);
	for (ll i = 0; i < m; i++)
	{
		ll a, b; cin >> a >> b;
		a -= 1, b -= 1;
		g[a].insert(b);
	}
	for (ll i = 0; i < q; i++)
	{
		ll u, v; cin >> u >> v;
		u -= 1, v -= 1;
		vector<bool> vis(n, false);
		vis[u] = true;
		bool reached = false;
		for (ll starting : g[u]) reached |= dfs(g, vis, v, starting);
		if (reached) cout << "YES\n";
		else cout << "NO\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
