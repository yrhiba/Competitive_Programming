/*
link to the problem:
https://codeforces.com/contest/16/problem/B
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
	ll n, m; cin >> n >> m;

	vector< pair<ll, ll> > a(m);
	for (ll i = 0; i < m; i++)
		cin >> a[i].second >> a[i].first;

	sort(a.begin(), a.end(), greater< pair<ll, ll> >());

	ll res = 0;

	for (ll i = 0; i < m; i++)
	{
		if (n == 0)
			break;

		if (n >= a[i].second)
		{
			res += (a[i].first * a[i].second);
			n -= a[i].second;
		}
		else
		{
			res += (n * a[i].first);
			n -= n;
		}
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
