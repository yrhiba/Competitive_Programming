/*
link to the problem:
https://codeforces.com/contest/1352/problem/D
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
	vector<ll> a(n);
	vector<ll> e(n, 0);
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	ll p1 = 0, p2 = n-1;
	ll r1 = 0, r2 = 0;
	ll l1 = 0, l2 = 0;

	ll moves = 0;

	while (p1 <= p2)
	{
		// alice
		l1 = 0;
		while (p1 <= p2 && e[p1] == 0 && l1 <= l2)
		{
			e[p1] = 1;
			l1 += a[p1];
			p1 += 1;
		}
		r1 += l1;

		// bob
		l2 = 0;
		while (p1 <= p2 && e[p2] == 0 && l2 <= l1)
		{
			e[p2] = 1;
			l2 += a[p2];
			p2 -= 1;
		}
		r2 += l2;

		moves += (l1 > 0) + (l2 > 0);
	}

	cout << moves << " " << r1 << " " << r2 << endl;
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
