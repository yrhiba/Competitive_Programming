/*

2023-2024 ICPC, NERC, Northern Eurasia Onsite 
(Unrated, Online Mirror, ICPC Rules, Teams Preferred)

A. Accumulator Apex

link to the problem:
https://codeforces.com/contest/1912/problem/A

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

void solve()
{
	ll x, k; cin >> x >> k;
	vector< vector< pair<ll, ll> > > g;

	for (ll i = 0; i < k; i++)
	{
		vector< pair<ll, ll> > a;
		ll n; cin >> n;
		ll cur = 0;
		ll cost = 0;
		for (ll i = 0; i < n; i++)
		{
			ll t; cin >> t;

			if (t >= 0)
			{
				if (cur >= 0)
				{
					cur += t;
				}
				else
				{
					cost = cur;
					cur = t;
				}
			}
			else
			if (t < 0)
			{
				if (cur < 0)
				{
					cur += t;
				}
				else
				{
					a.push_back({abs(cost), cur + cost});
					cur = t;
				}
			}
		}

		if (cur >= 0)
			a.push_back({abs(cost), cur + cost});

		g.push_back(a);
	}

	vector< deque< pair<ll, ll> > > res(k);

	for (ll i = 0; i < k; i++)
	{
		deque< pair<ll, ll> > &r = res[i];

		for (ll j = 0; j < g[i].size(); )
		{
			ll cost = g[i][j].first;
			ll gain = g[i][j].second;

			ll x = j + 1;
			while (x < g[i].size() && gain < 0)
			{
				cost = max(cost, g[i][x].first + abs(gain));
				gain += g[i][x].second;
				x += 1;
			}

			if (gain >= 0)
				r.push_back({cost, gain});
			else
				break;

			j = x;
		}
	}

	ll ans = x;

	while (true)
	{
		bool f = false;

		for (auto &v : res)
		{
			if (!v.empty())
			{
				if (v.front().first <= ans)
				{
					ans += v.front().second;
					v.pop_front();
					f = true;
				}
			}
		}

		if (!f)	break;
	}

	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
