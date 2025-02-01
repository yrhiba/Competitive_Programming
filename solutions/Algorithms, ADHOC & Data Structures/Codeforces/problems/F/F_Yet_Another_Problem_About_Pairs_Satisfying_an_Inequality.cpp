/*
F. Yet Another Problem About Pairs Satisfying an Inequality

link to the problem:
https://codeforces.com/contest/1703/problem/F
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

	vector< pair<ll, ll> > a;
	a.reserve(n + 1);

	vector<ll> pr(n+2, 0);

	for (ll i = 1; i <= n; i++)
	{
		ll t; cin >> t;

		if (t < i)
			a.push_back({t , i});
	}

	for (auto &[v, i] : a)
		pr[i+1] += 1;

	for (ll i = 1; i <= (n+1); i++)
		pr[i] += pr[i - 1];

	ll ans = 0;

	for (auto &[v, i] : a)
		ans += pr[v];

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
