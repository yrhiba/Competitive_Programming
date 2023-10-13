/*
link to the problem:
https://codeforces.com/contest/1881/problem/A
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
	ll n, m; cin >> n >> m;
	string x, s; cin >> x >> s;

	ll i = 0, r = 0, found = 0;

	while (i < x.size())
	{
		ll j = 0, rounds = 0;
		while (s[j] && x[(i + j) % x.size()] == s[j])
		{
			j++;
			if ((i + j) && ((i + j) % x.size() == 0)
				&& (s[j] && x[(i + j) % x.size()] == s[j]))
				rounds += 1;
		}

		if (s[j] == '\0')
		{
			found = 1;
			r = rounds;
			break;
		}

		i++;
		if (i == x.size() && r == 0)
		{
			i = 0;
			r += 1;
		}
	}

	if (found)
	{
		ll ans = 0;
		while (r)
		{
			r /= 2;
			ans += 1;
		}
		cout << ans << "\n";
	}
	else
	{
		cout << -1 << "\n";
	}
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
