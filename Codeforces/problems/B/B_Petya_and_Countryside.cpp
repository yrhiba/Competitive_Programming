/*
link to the problem:
https://codeforces.com/contest/66/problem/B
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
	ll n; cin >> n;

	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	ll res = 1, cost;

	ll x, y;

	for (ll i = 0; i < n; i++)
	{
		cost = 1;

		x = i - 1;
		while (x >= 0 && a[x] <= a[x + 1])
		{
			cost += 1;
			x -= 1;
		}

		y = i + 1;
		while (y < n && a[y] <= a[y - 1])
		{
			cost += 1;
			y += 1;
		}

		res = max(res, cost);
	}
	cout << res << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
