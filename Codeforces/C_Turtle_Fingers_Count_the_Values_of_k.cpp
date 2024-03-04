/*
B. Turtle Math: Fast Three Task

link to the problem:
https://codeforces.com/contest/1933/problem/C
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

ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}

bool check(ll k, ll a, ll b)
{
	for (ll x = 0; ; x++)
	{
		ll t = power(a, x);
		for (ll y = 0; ; y++)
		{
			ll tt = t * power(b, y);
			if (tt == k) return true;
			if (tt > k) break;
		}
		if (t > k) break;
	}
	return (false);
}

void solve()
{
	ll a, b, l; cin >> a >> b >> l;
	ll ans = 0;
	ans += check(1, a, b);
	if (1 != l)	ans += check(l, a, b);
	for (ll i = 2; i*i <= l; i++)
	{
		if (l%i) continue;
		//
		ans += check(i, a, b);
		if (i != (l/i)) ans += check(l/i, a, b);
	}
	cout << ans << "\n";
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
