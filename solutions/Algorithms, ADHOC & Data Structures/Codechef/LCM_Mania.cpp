/*

Starters 111 (Rated till 6 Stars)

LCM Mania

link to the problem:
https://www.codechef.com/problems/LCMMANIA

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

void solve()
{
	ll n; cin >> n;

	if (n < 3)
	{
		cout << -1 << '\n';
		return ;
	}

	if (n%3 == 0)
	{
		cout << n/3 << ' ' << n/3 << ' ' << n/3 << '\n';
		return ;
	}

	if (n%2)
	{
		cout << 1 << ' ' << 1 << ' ' << n/2 << '\n';
		return ;
	}

	for (ll i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			ll a = i;
			ll b = n/i;

			if (a%2 && b%2 == 0)
			{
				ll x, y, z;

				x  = 1; y  = 1; z  = a/2;
				x *= b; y *= b; z *= b;

				cout << x << ' ' << y << ' ' << z << '\n';
				return ;
			}
			else
			if (b%2 && a%2 == 0)
			{
				swap(a, b);

				ll x, y, z;

				x  = 1; y  = 1; z  = a/2;
				x *= b; y *= b; z *= b;

				cout << x << ' ' << y << ' ' << z << '\n';
				return ;
			}
		}
	}

	cout << -1 << "\n";
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
