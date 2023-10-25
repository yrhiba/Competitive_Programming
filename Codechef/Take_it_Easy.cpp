/*
Starters 105 Division 3 (Rated)

Take it Easy

link to the problem:
https://www.codechef.com/problems/TIES
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
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}
ll gcd(ll a, ll b)
{
	if (b == 0) return (a);
	return (gcd(b, a%b));
}
ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a, b));
}

bool good(ll x)
{
	if (x == 0)
		return (true);

	return (x%2 == 0);
}

void solve()
{
	ll n; cin >> n;

	ll sum = 0;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	if (sum%n)
	{
		cout << "NO\n";
		return ;
	}

	ll to_be = sum/n;

	for (ll i = 0; i < n; i++)
	{
		ll x = abs(a[i] - to_be);
		if (good(x)) continue;
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
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
