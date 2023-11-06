/*
link to the problem:
https://codeforces.com/contest/1883/problem/D
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
ll powermod(ll x, ll p, ll m)
{
	if (p == 0) return (1);
	ll res = powermod(x, p/2, m) % m;
	if (p%2)
		return ((((res * res) % m) * (x % m)) % m);
	return ((res * res) % m);
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
	return ((a*b)/gcd(a,b));
}
ll inverse(ll x, ll m)
{
	return (powermod(x, m-2, m));
}


void solve()
{
	ll q; cin >> q;

	multiset< ll, greater<ll>  > lefts;
	multiset< ll > rights;

	while (q--)
	{
		char c; cin >> c;

		ll l, r; cin >> l >> r;

		if (c == '+')
		{
			lefts.insert(l);
			rights.insert(r);
		}
		else
		{
			lefts.erase(lefts.find(l));
			rights.erase(rights.find(r));
		}


		if (lefts.size() >= 2)
		{
			ll max_l, min_r;

			max_l = *lefts.begin();
			min_r = *rights.begin();

			if (max_l <= min_r)
			{
				cout << "NO\n";
			}
			else
			{
				cout << "YES\n";
			}
		}
		else
		{
			cout << "NO\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
