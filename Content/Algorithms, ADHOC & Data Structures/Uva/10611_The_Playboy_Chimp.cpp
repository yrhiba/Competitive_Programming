/*
link to the problem:
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1552
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

ll bs_less(vector<ll> &a, ll t)
{
	ll start = 0;
	ll end = a.size() - 1;
	ll x = -1;
	ll mid;

	while (start <= end)
	{
		mid = start + ((end - start) / 2);

		if (a[mid] < t)
		{
			x = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}

	return ((x != -1) ? a[x] : -1);
}

ll bs_upper(vector<ll> &a, ll t)
{
	ll start = 0;
	ll end = a.size() - 1;
	ll x = -1;
	ll mid;

	while (start <= end)
	{
		mid = start + ((end - start) / 2);

		if (a[mid] > t)
		{
			x = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}

	return ((x != -1) ? a[x] : -1);
}

void solve()
{
	ll n, t; cin >> n;

	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	ll q; cin >> q;
	for (ll i = 0; i < q; i++)
	{
		cin >> t;

		ll x = bs_less(a, t);
		ll y = bs_upper(a, t);

		if (x != -1)
			cout << x << " ";
		else
			cout << "X" << " ";
	
		if (y != -1)
			cout << y << "\n";
		else
			cout << "X" << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
