/*
CSES Problem Set

Shortest Routes II

link to the problem:
https://cses.fi/problemset/task/1672/
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
#include <cassert>
# define ll long long

using namespace std;


void solve()
{
	ll n, m, q; cin >> n >> m >> q;

	vector<vector<ll>> dis(n, vector<ll>(n, 1e18));

	for (ll i = 0; i < n; i++) dis[i][i] = 0;

	for (ll i = 0; i < m; i++)
	{
		ll a, b, c; cin >> a >> b >> c;
		a -= 1, b -= 1;
		dis[a][b] = min(dis[a][b], c);
		dis[b][a] = min(dis[b][a], c);
	}

	for (ll k = 0; k < n; k++)
		for (ll i = 0; i < n; i++)
			for (ll j = 0; j < n; j++)
				if (dis[i][k] < 1e18  && dis[k][j] < 1e18)
				{
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}

	while (q--)
	{
		ll a, b; cin >> a >> b; a -= 1, b -= 1;
		cout << ((dis[a][b] != 1e18) ? dis[a][b] : -1) << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
