/*

Codeforces Round 909 (Div. 3)

B. 250 Thousand Tons of TNT

link to the problem:
https://codeforces.com/contest/1899/problem/B

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
	for (ll &i : a)
		cin >> i;

	ll ans = 0;

	for (ll k = 1; k <= n; k++)
	{
		if (n % k) continue;

		ll min_s = -1, max_s = -1;

		ll p = 0;
		while (p < n)
		{
			ll cur = 0;

			for (ll j = 0; j < k; j++)
				cur	+= a[p + j];

			if (min_s == -1)
				min_s = cur;
			else
				min_s = min(min_s, cur);

			if (max_s == -1)
				max_s = cur;
			else
				max_s = max(max_s, cur);

			p += k;
		}

		ans = max(ans, abs(max_s - min_s));
	}

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
