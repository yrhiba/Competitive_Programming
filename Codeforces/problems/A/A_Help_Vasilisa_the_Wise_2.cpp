/*
Link to the problem:
https://codeforces.com/contest/143/problem/A
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

void solve()
{
	ll r1, r2;
	cin >> r1 >> r2;
	ll c1, c2;
	cin >> c1 >> c2;
	ll d1, d2;
	cin >> d1 >> d2;

	vector< vector<ll> > g(2, vector<ll>(2));


	for (ll i = 1; i <= 9; i++)
	{
		g[0][0] = min(r1, min(d1, c1)) - i;
		g[0][1] = r1 - g[0][0];
		g[1][0] = c1 - g[0][0];
		g[1][1] = d1 - g[0][0];

		bool f = true;

		map<ll, bool> mp;

		for (ll i = 0; i < 2; i++)
		{
			for (ll j = 0; j < 2; j++)
			{
				if (g[i][j] > 9 || g[i][j] < 1 || mp.find(g[i][j]) != mp.end())
				{
					f = false;
					break;
				}
				mp[g[i][j]] = true;
			}
			if (!f)
				break;
		}

		if (!f)
			continue;

		if (g[0][0] + g[0][1] == r1 
		&& g[1][0] + g[1][1] == r2
		&& g[0][0] + g[1][0] == c1
		&& g[0][1] + g[1][1] == c2
		&& g[0][0] + g[1][1] == d1
		&& g[0][1] + g[1][0] == d2
		)
		{
			cout << g[0][0] << ' ' << g[0][1] << "\n";	
			cout << g[1][0] << ' ' << g[1][1] << "\n";	
			return ;
		}
	}

	cout << -1 << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
