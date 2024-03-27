/*
link to the problem:
https://cses.fi/problemset/task/1671/
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
	vector< set< pair<ll,ll> > > g(n);
	for (ll i = 0; i < m; i++)
	{
		ll a, b, c; cin >> a >> b >> c;
		a -= 1, b -= 1;
		g[a].insert({b, c});
	}
	//
	priority_queue<pair<ll, ll>,
		vector<pair<ll, ll>>,
		greater<pair<ll,ll>> > pr;
	//
	vector<ll> ans(n, 1e18);
	//
	ans[0] = 0;
	pr.push({0, 0}); // cost, city
	//
	while (!pr.empty())
	{
		ll cur_city = pr.top().second;
		ll cur_lenght = pr.top().first;
		//
		pr.pop();
		//
		if (cur_lenght > ans[cur_city]) continue;
		//
		for (auto &[city, cost] : g[cur_city])
			if (cost+cur_lenght < ans[city])
			{
				ans[city] = cost + cur_lenght;
				pr.push({ans[city], city});
			}
	}
	//
	for (ll i = 0; i < n; i++)
		cout << ans[i] << " \n"[i+1 == n];
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	solve();
}
