/*
link to the problem:
https://codeforces.com/contest/433/problem/B
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

	vector<ll> v(n+1);
	vector<ll> u(n+1);

	for (ll i = 1; i <= n; i++)
	{
		cin >> v[i];
		u[i] = v[i];
	}

	sort(u.begin(), u.end());

	for (ll i = 1; i <= n; i++)
	{
		v[i] += v[i-1];
		u[i] += u[i-1];
	}

	ll m; cin >> m;

	for (ll i = 0; i < m; i++)
	{
		ll t, l, r;
		cin >> t >> l >> r;

		if (t == 1)
		{
			cout << v[r] - v[l-1] << "\n";
		}
		if (t == 2)
		{
			cout << u[r] - u[l-1] << "\n";
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
