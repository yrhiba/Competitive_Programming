/*
KEYENCE Programming Contest 2023 Autumn（AtCoder Beginner Contest 325）

link to the problem:
https://atcoder.jp/contests/abc325/tasks/abc325_b
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


	vector< pair<ll, ll> > a(n);

	for (ll i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}

	ll ans = 0;

	for (ll i = 0; i < 24; i++)
	{
		ll t = 0;

		for (ll x = 0; x < n; x++)
		{
			if (9 <= (a[x].second + i)%24 && (a[x].second + i)%24 < 18)
				t += a[x].first;
		}

		ans = max(ans, t);
	}

	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
