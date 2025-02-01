/*
link to the problem:
https://cses.fi/problemset/task/1669/
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

void solve()
{
	ll n, m; cin >> n >> m;
	vector< set<ll> > g(n);
	for (ll i = 0; i < m; i++)
	{
		ll a, b; cin >> a >> b;
		a -= 1, b -= 1;
		g[a].insert(b);
		g[b].insert(a);
	}
	//
	queue<pair<ll,ll>> q;
	vector<bool> vis(n, false);
	pair<ll, ll> ans = {-1, -1};
	//
	for (ll i = 0; i < n; i++)
	{
		if (vis[i]) continue;
		vis[i] = true;
		q.push({i, -1});
		while (!q.empty())
		{
			ll curCity = q.front().first;
			ll parentCity = q.front().second;
			q.pop();
			//
			for (ll nextCity : g[curCity])
			{
				if (vis[nextCity])
				{
					if (nextCity != parentCity)
					{
						g[nextCity].erase(curCity);
						g[curCity].erase(nextCity);
						ans = {curCity, nextCity};
						break; ;
					}
					continue;
				}
				q.push({nextCity, curCity});
				vis[nextCity] = true;
			}
			//
			if (ans.first != -1) break;
		}
		//
		if (ans.first != -1) break;
	}
	//
	if (ans.first == -1)
	{
		cout << "IMPOSSIBLE\n";
		return ;
	}
	//
	ll start = ans.first;
	ll end = ans.second;
	//
	map<ll, ll> parent;
	vis = vector<bool>(n, false);
	q = queue<pair<ll,ll>>();
	q.push({start, -1});
	parent[start] = -1;
	vis[start] = true;
	//
	while (!q.empty())
	{
		ll curCity = q.front().first;
		ll parentCity = q.front().second;
		q.pop();
		//
		if (curCity == end)	break;
		//
		for (ll nextCity : g[curCity])
		{
			if (vis[nextCity]) continue;
			parent[nextCity] = curCity;
			vis[nextCity] = true;
			q.push({nextCity, curCity});
		}
	}
	//
	vector<ll> road; road.push_back(start);
	while (end != -1)
	{
		road.push_back(end);
		end = parent[end];
	}
	reverse(road.begin(), road.end());
	cout << road.size() << "\n";
	for (ll i = 0; i < road.size(); i++)
		cout << road[i] + 1 << " \n"[i+1 == road.size()];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
