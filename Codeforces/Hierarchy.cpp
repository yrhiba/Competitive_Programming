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

# define ll long long

using namespace std;


void dfs(vector< vector<ll> > &g, vector<bool> &visited, vector<ll> &res, ll node)
{
	visited[node] = true;

	for (ll i = 0; i < g[node].size(); i++)
	{
		if (visited[g[node][i]]) continue;
		dfs(g, visited, res, g[node][i]);
	}

	res.push_back(node);
}

void solve()
{
	ll n, m; cin >> n >> m;

	vector< vector<ll> > g(n+1);

	for (ll f = 1; f <= m; f++)
	{
		map<ll, bool> mp;

		ll t, a; cin >> t;

		for (ll i = 0; i < t; i++)
		{
			cin >> a;

			if (mp.find(a) != mp.end())
				continue;

			mp[a] = true;

			g[f].push_back(a);

		}
	}



	vector<ll>		initial_res;
	vector<bool>	visited(n+1, false);

	for (ll i = 1; i <= n; i++)
	{
		if (visited[i]) continue;
		dfs(g, visited, initial_res, i);
	}

	vector<ll> parents(n+1);

	for (ll i = 0; i < initial_res.size(); i++)
	{
		if (i+1 < initial_res.size())
			parents[initial_res[i]] = initial_res[i+1];
		else
			parents[initial_res[i]] = 0;
	}

	for (ll i = 1; i <= n; i++)
		cout << parents[i] << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
