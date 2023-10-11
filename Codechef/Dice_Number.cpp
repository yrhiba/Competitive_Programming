/*
link to the problem:
https://www.codechef.com/problems/DICENUM
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
	vector<ll> a(3);
	vector<ll> b(3);

	for (ll i = 0; i < 3; i++)
		cin >> a[i];

	for (ll i = 0; i < 3; i++)
		cin >> b[i];

	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());

	ll x, y; x = y = 0;

	for (ll i = 0; i < 3; i++)
	{
		x = x*10 + a[i];
		y = y*10 + b[i];
	}

	if (x == y)
		cout << "Tie";
	else if (x < y)
		cout << "Bob";
	else
		cout << "Alice";

	cout << endl;
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
