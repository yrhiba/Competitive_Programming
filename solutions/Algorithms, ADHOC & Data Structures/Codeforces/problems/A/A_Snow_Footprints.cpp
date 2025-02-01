/*
link to the probem:
https://codeforces.com/contest/298/problem/A
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
	string s; cin >> s;

	ll c = 0, t = 0;
	for (ll i = 0; i < s.size(); i++)
	{
		if (s[i] == 'R' && !c)
			c = i + 1;
		if (s[i] == 'R')
			t = i + 2;
	}

	ll x = 0, y = 0;
	for (ll i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == 'L' && !x)
			x = i + 1;
		if (s[i] == 'L')
			y = i;
	}

	if (c != 0 && x != 0)
	{
		cout << x << " " << y << endl;
	}
	else if (c != 0)
	{
		cout << c << " " << t << endl;
	}
	else if (x != 0)
	{
		cout << x << " " << y << endl;
	}
	else
		cout << 1 << " " << 1 << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
