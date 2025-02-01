/*
A. Escalator Conversations

link to the problem:
https://codeforces.com/contest/1851/problem/A
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
	ll n, m, k, H;
	cin >> n >> m >> k >> H;

	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	ll min_h = 0;
	ll max_h = (m - 1) * k;

	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		ll df = abs(H - a[i]);

		if (df > min_h && df <= max_h && df % k == 0)
			ans += 1;
	}

	cout << ans << endl;
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
